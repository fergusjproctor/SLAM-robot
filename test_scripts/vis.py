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

def update_plot(angle, distance):
    x_data.append(angle)
    y_data.append(distance)
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
                
                # Ensure both angle and distance have been received before updating the plot
                if angle is not None and distance is not None:
                    update_plot(angle, distance)
                    # Reset angle and distance after updating plot
                    angle = None
                    distance = None
                    
        except ValueError as ve:
            print(f"ValueError: {ve}")
        except Exception as e:
            print(f"Error: {e}")