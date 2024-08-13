#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <memory>
#include <geometry_msgs/msg/twist.hpp>
#include <string>




using namespace std::chrono_literals;
using boost::asio::serial_port;
using boost::asio::io_service;
using boost::asio::buffer;
using boost::asio::write;
using boost::asio::read;
using std::placeholders::_1;
using std::placeholders::_2;

class SerialNode : public rclcpp::Node {
public:
    SerialNode() : Node("serial_node") {
        // Initialize serial port
        io_ = std::make_shared<io_service>();


        serial_port_ = std::make_shared<serial_port>(*io_, "/dev/tty.HC05Ferg1"); // Adjust port name as needed

        // serial_port_ is shared pointer, "->" dereferences it to all its method set option
        serial_port_->set_option(serial_port::baud_rate(38400));
        serial_port_->set_option(serial_port::character_size(8));
        serial_port_->set_option(serial_port::parity(serial_port::parity::none));
        serial_port_->set_option(serial_port::stop_bits(serial_port::stop_bits::one));
        serial_port_->set_option(serial_port::flow_control(serial_port::flow_control::none));
        

        // Create publisher
        publisher_ = this->create_publisher<std_msgs::msg::String>("serial_output", 2);

        // Create subscriber
        //subscription_ = this->create_subscription<std_msgs::msg::String>(
        //    "serial_input", 2, std::bind(&SerialNode::handle_message, this, _1)
        //);

        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/turtle1/cmd_vel", 2, std::bind(&SerialNode::handle_message, this, _1)
        );

        // Start serial read
        start_read();

        // Create timer to periodically send data
        timer_ = this->create_wall_timer(
            2000ms, [this]() { send_data(""); }
        );
    }

private:
    // handler for string message
    // void handle_message(const std_msgs::msg::String::SharedPtr msg) {
    //     std::string data = msg->data;
    //     RCLCPP_INFO(rclcpp::get_logger("SerialNode"), "Message received on serial_input topic");
        
    //     boost::asio::async_write(
    //         *serial_port_,
    //         boost::asio::buffer(data),
    //         [this](const boost::system::error_code& error, std::size_t length) {
    //             if (error) {
    //                 RCLCPP_ERROR(rclcpp::get_logger("SerialNode"), "Error writing to serial port: %s", error.message().c_str());
    //             }
    //         }
    //     );
    // }

    void handle_message(const geometry_msgs::msg::Twist::ConstSharedPtr vel) {
        float lin_vel_x_ = vel->linear.x;
        float ang_vel_ = vel->angular.z;
        std::string data = "";
        RCLCPP_INFO(rclcpp::get_logger("SerialNode"), "Message received on serial_input topic");
        
        if (lin_vel_x_ == 2.0){

        data = "F";
        }else {
            data = "C";
             
        }
        boost::asio::async_write(
            *serial_port_,
            boost::asio::buffer(data),
            [this](const boost::system::error_code& error, std::size_t length) {
                if (error) {
                    RCLCPP_ERROR(rclcpp::get_logger("SerialNode"), "Error writing to serial port: %s", error.message().c_str());
                }
            }
        );
    }



    char twistToChar(const geometry_msgs::msg::Twist& twist) {
    // Check if the Twist message matches the specific condition
    if (twist.linear.x == 2.0 &&
        twist.linear.y == 0.0 &&
        twist.linear.z == 0.0 &&
        twist.angular.x == 0.0 &&
        twist.angular.y == 0.0 &&
        twist.angular.z == 0.0) {
        return 'F';  // Return 'F' if the condition is met
    } else {
        return 'U';  // Return 'U' for "Unknown" if the condition is not met
    }
}

void send_data(const std::string& data) {
        RCLCPP_INFO(rclcpp::get_logger("SerialNode"), "Send data called");
        boost::asio::async_write(
            *serial_port_,
            boost::asio::buffer(data),
            [](const boost::system::error_code& error, std::size_t length) {
                if (!error) {
                    RCLCPP_INFO(rclcpp::get_logger("SerialNode"), "Sent %zu bytes", length);
                    
                } else {
                    RCLCPP_ERROR(rclcpp::get_logger("SerialNode"), "Error sending data: %s", error.message().c_str());
                }
            }
        );
    }


    void start_read() {
        
        auto buffer = std::make_shared<std::array<char, 256>>();
        serial_port_->async_read_some(
            boost::asio::buffer(*buffer),
            [this, buffer](const boost::system::error_code& error, std::size_t length) {
                if (!error) {
                    std::string data(buffer->data(), length);
                    auto msg = std::make_shared<std_msgs::msg::String>();
                    msg->data = data;
                    publisher_->publish(*msg);
                } else {
                    RCLCPP_ERROR(rclcpp::get_logger("SerialNode"), "Error reading from serial port: %s", error.message().c_str());
                }
                start_read(); // Continue reading
            }
        );
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    //rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;

    rclcpp::TimerBase::SharedPtr timer_;

    std::shared_ptr<io_service> io_;
    std::shared_ptr<serial_port> serial_port_;
};

int main(int argc, char * argv[]) {
    
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SerialNode>());
    rclcpp::shutdown();
    return 0;
}
