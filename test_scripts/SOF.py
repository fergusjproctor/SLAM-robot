import serial
import time
from collections import Counter

# Configuration
serial_port = '/dev/tty.usbmodem11101'  # Update this to your Arduino's serial port
baud_rate = 115200
duration = 10  # Duration to record data in seconds

# Function to perform analysis for a given packet length
def analyze_packet_length(packet_length):
    # Open serial port
    ser = serial.Serial(serial_port, baud_rate, timeout=1)
    time.sleep(2)  # Wait for the connection to establish

    # Initialize a Counter to store byte frequencies and packet buffers
    byte_counter = Counter()
    total_bytes = 0  # Variable to keep track of total bytes transmitted
    packet_counter = Counter()  # To count occurrences of each potential SOF

    print(f"Recording data for packet length {packet_length}...")

    start_time = time.time()
    packet_buffer = []

    try:
        while time.time() - start_time < duration:
            if ser.in_waiting > 0:
                byte = ser.read(1)  # Read one byte
                if byte:
                    byte_value = ord(byte)  # Convert byte to integer
                    byte_counter[byte_value] += 1  # Update the byte frequency count
                    total_bytes += 1  # Increment total byte count
                    
                    # Add the byte to the packet buffer
                    packet_buffer.append(byte_value)
                    
                    # Keep only the last 'packet_length' bytes
                    if len(packet_buffer) > packet_length:
                        packet_buffer.pop(0)
                    
                    # Check if buffer length is equal to packet_length
                    if len(packet_buffer) == packet_length:
                        # Check if the current buffer is a potential SOF
                        for i in range(packet_length):
                            packet_counter[(i + 1, packet_buffer[i])] += 1

    finally:
        ser.close()  # Close the serial port when done

    print(f"Recording stopped for packet length {packet_length}.")

    # Write results to file
    with open(f'byte_frequencies_{packet_length}.txt', 'w') as f:
        # Byte frequencies
        f.write("Total bytes transmitted: {}\n".format(total_bytes))
        f.write("Top 10 Byte Frequencies (Hex) : Frequency\n")
        for byte_value, count in byte_counter.most_common(10):
            f.write(f"0x{byte_value:02X} : {count}\n")

        # SOF analysis
        f.write("\nTop 10 Possible Start of Frame (SOF) Bytes Analysis:\n")
        f.write("Position : Byte (Hex) : Frequency\n")
        # Extract the top 10 positions with highest frequencies
        top_sof = Counter({key: val for key, val in packet_counter.items()}).most_common(20)
        for (position, byte_value), count in top_sof:
            f.write(f"Position {position} : 0x{byte_value:02X} : {count}\n")

    print(f"Data has been recorded to 'byte_frequencies_{packet_length}.txt'. Total bytes transmitted: {total_bytes}")

# Main loop to test packet lengths from 2 to 15
for packet_length in range(15, 30):
    analyze_packet_length(packet_length)
