#include <rclcpp/rclcpp.hpp>
#include <boost/asio.hpp>

class SerialSenderNode : public rclcpp::Node
{
public:
    SerialSenderNode() : Node("serial_sender_node"), io(), serial(io)
    {
        // Open the serial port (adjust the device path as necessary)
        serial.open("/dev/tty.usbmodem11101");  // Update with your specific serial port

        // Set serial port parameters
        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));

        // Create a timer to send data periodically
        timer_ = this->create_wall_timer(
            std::chrono::seconds(3),
            std::bind(&SerialSenderNode::send_data, this));
    }

private:
    void send_data()
    {
        std::string message = "Hello, Arduino!";
        boost::asio::write(serial, boost::asio::buffer(message));
        RCLCPP_INFO(this->get_logger(), "Sent: %s", message.c_str());
    }

    boost::asio::io_service io;
    boost::asio::serial_port serial;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SerialSenderNode>());
    rclcpp::shutdown();
    return 0;
}
