import serial
import matplotlib.pyplot as plt
import numpy as np

# Configure serial port and baud rate
ser = serial.Serial('/dev/tty.usbmodem11101', 115200)  # Replace 'COM3' with your Arduino port

# Initialize the plot
plt.ion()
fig, ax = plt.subplots()
x_data, y_data = [], []
line, = ax.plot([], [], 'o')

angle = None
distance = None

def update_plot(x, y):
    x_data.append(x)
    y_data.append(y)
    line.set_data(x_data, y_data)
    ax.relim()
    ax.autoscale_view()
    plt.draw()
    plt.pause(0.01)

while True:
    if ser.in_waiting > 0:
        try:
            # Read available data
            data = ser.read_until(b'\n').decode('utf-8').strip()
            
            # Check for angle or distance and parse accordingly
            if data.startswith("Angle:"):
                angle = float(data.split(":")[1].strip())
            elif data.startswith("Distance:"):
                distance = float(data.split(":")[1].strip())
                
                # Convert angle from degrees to radians
                angle_rad = np.deg2rad(angle)
                
                # Convert polar coordinates to Cartesian coordinates
                x = distance * np.cos(angle_rad)
                y = distance * np.sin(angle_rad)
                
                # Update plot with Cartesian coordinates
                update_plot(x, y)
                    
        except ValueError as ve:
            print(f"ValueError: {ve}")
        except Exception as e:
            print(f"Error: {e}")