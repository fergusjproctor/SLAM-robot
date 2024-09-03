import serial
import time
from collections import Counter

# Configuration
serial_port = '/dev/tty.usbmodem11101'  # Update this to your Arduino's serial port
baud_rate = 115200
duration =  15  # Duration to record data in seconds
packet_length = 21  # Length of each packet (can be adjusted as needed)

# Open serial port
ser = serial.Serial(serial_port, baud_rate, timeout=1)
time.sleep(2)  # Wait for the connection to establish

# Initialize counters
position_counters = [Counter() for _ in range(packet_length)]  # One Counter for each position in the packet
total_packets = 0  # Variable to keep track of total packets

# Temporary list to accumulate bytes
packet = []

print("Recording data...")

start_time = time.time()

try:
    while time.time() - start_time < duration:
        if ser.in_waiting > 0:
            byte = ser.read(1)  # Read one byte
            if byte:
                byte_value = ord(byte)  # Convert byte to integer
                packet.append(byte_value)  # Add byte to the packet

                # Check if the packet is full
                if len(packet) == packet_length:
                    # Count occurrences of 0x65 in each position of the packet
                    for i, value in enumerate(packet):
                        if value == 0x20:
                            position_counters[i][0x65] += 1
                    total_packets += 1  # Increment total packet count
                    packet = []  # Clear packet for the next one

finally:
    ser.close()  # Close the serial port when done

print("Recording stopped.")

# Write results to file
with open('packet_frequencies.txt', 'w') as f:
    f.write("Total packets recorded: {}\n".format(total_packets))
    f.write("Position : Frequency of 0x20\n")
    for i, counter in enumerate(position_counters, start=1):
        f.write(f"Position {i} : {counter.get(0x20, 0)}\n")

print(f"Data has been recorded to 'packet_frequencies.txt'. Total packets recorded: {total_packets}")
