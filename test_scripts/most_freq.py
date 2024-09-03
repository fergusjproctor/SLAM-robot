import serial
import time
from collections import Counter

# Configuration
serial_port = '/dev/tty.usbmodem11101'  # Update this to your Arduino's serial port



baud_rate = 115200
duration = 5  # Duration to record data in seconds

# Open serial port
ser = serial.Serial(serial_port, baud_rate, timeout=1)
time.sleep(2)  # Wait for the connection to establish

# Initialize a Counter to store byte frequencies
byte_counter = Counter()
total_bytes = 0  # Variable to keep track of total bytes transmitted

print("Recording data...")

start_time = time.time()

try:
    while time.time() - start_time < duration:
        if ser.in_waiting > 0:
            byte = ser.read(1)  # Read one byte
            if byte:
                byte_value = ord(byte)  # Convert byte to integer
                byte_counter[byte_value] += 1  # Update the count
                total_bytes += 1  # Increment total byte count

finally:
    ser.close()  # Close the serial port when done

print("Recording stopped.")

# Write results to file
with open('byte_frequencies.txt', 'w') as f:
    f.write("Total bytes transmitted: {}\n".format(total_bytes))
    f.write("Byte (Hex) : Frequency\n")
    for byte_value, count in byte_counter.most_common():
        f.write(f"0x{byte_value:02X} : {count}\n")

print(f"Data has been recorded to 'byte_frequencies.txt'. Total bytes transmitted: {total_bytes}")

