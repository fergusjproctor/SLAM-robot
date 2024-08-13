import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial

class SerialNode(Node):
    def __init__(self):
        super().__init__('serial_node')

        # Initialize the serial port
        self.serial_port = serial.Serial('/dev/tty.usbmodem11101', baudrate=38400, timeout=1)

        # Create a publisher
        self.publisher_ = self.create_publisher(String, 'serial_output', 10)

        # Create a subscriber
        self.subscription_ = self.create_subscription(
            String,
            'serial_input',
            self.handle_message,
            10
        )

        # Create a timer to periodically send data
        self.timer_ = self.create_timer(2.0, self.send_data)

        # Create a timer to periodically read from serial port
        self.read_timer_ = self.create_timer(0.1, self.read_from_serial)

        # Start reading from the serial port
        self.read_from_serial()

    def handle_message(self, msg):
        data = msg.data
        self.serial_port.write(data.encode())
        self.get_logger().info(f'Sent: {data}')

    def send_data(self):
        message = "Hello Arduino!"
        self.serial_port.write(message.encode())
        self.get_logger().info(f'Sent: {message}')

    def read_from_serial(self):
        
        if self.serial_port.in_waiting > 0:
            data = self.serial_port.readline().decode('utf-8').strip()
            if data:
                self.get_logger().info(f'Received: {data}')
                msg = String()
                msg.data = data
                self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    serial_node = SerialNode()

    try:
        rclpy.spin(serial_node)
    except KeyboardInterrupt:
        pass

    serial_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
