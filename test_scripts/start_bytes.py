import serial
import time
import numpy as np
from collections import defaultdict

# Configuration
serial_port = '/dev/tty.usbmodem11101'  # Update this to your Arduino's serial port
baud_rate = 115200
duration = 10  # Duration to record data in seconds
buffer_size = 1024  # Size of buffer to hold byte stream

# Open serial port
ser = serial.Serial(serial_port, baud_rate, timeout=1)
time.sleep(2)  # Wait for the connection to establish

byte_buffer = []
packet_lengths = defaultdict(list)

print("Recording data...")

start_time = time.time()

try:
    while time.time() - start_time < duration:
        if ser.in_waiting > 0:
            byte = ser.read(1)  # Read one byte
            if byte:
                byte_value = ord(byte)  # Convert byte to integer
                byte_buffer.append(byte_value)
                
                # Maintain buffer size
                if len(byte_buffer) > buffer_size:
                    byte_buffer.pop(0)

finally:
    ser.close()  # Close the serial port when done

print("Recording stopped.")

# Convert buffer to numpy array for processing
byte_stream = np.array(byte_buffer)

# Iterate over all possible byte values from 0x00 to 0xFF
for start_byte in range(256):
    indices = np.where(byte_stream == start_byte)[0]  # Find all indices of start_byte in the stream
    if len(indices) < 2:
        # Not enough start bytes to form packets
        continue
    
    lengths = []
    for i in range(len(indices) - 1):
        packet_length = indices[i + 1] - indices[i]
        lengths.append(packet_length)
    
    # Calculate average packet length
    if lengths:
        average_length = np.mean(lengths)
        packet_lengths[start_byte] = average_length

# Output results
for start_byte, average_length in packet_lengths.items():
    print(f"Start byte 0x{start_byte:02X}: Average packet length = {average_length:.2f} bytes")
