#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <future>
#include <mutex>
#include <condition_variable>

class SerialCommunicator {
public:
    SerialCommunicator(const std::string& port, unsigned int baud_rate)
        : io_service_(), serial_port_(io_service_), keep_running_(true) {
        // Open the serial port
        serial_port_.open(port);

        // Set the baud rate and other options
        serial_port_.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
        serial_port_.set_option(boost::asio::serial_port_base::character_size(8));
        serial_port_.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial_port_.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial_port_.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));

        // Start the io_service in a separate thread
        io_thread_ = std::thread([this]() { io_service_.run(); });
    }

    ~SerialCommunicator() {
        // Stop the io_service and join the thread
        keep_running_ = false; // Signal that we should stop
        io_service_.stop();
        if (io_thread_.joinable()) {
            io_thread_.join();
        }

        // Close the serial port
        serial_port_.close();
    }

    void send_data(const std::string& data, std::promise<void>&& promise) {
        boost::asio::async_write(
            serial_port_,
            boost::asio::buffer(data),
            [this, data, p = std::move(promise)](const boost::system::error_code& error, std::size_t length) mutable {
                if (!error) {
                    std::cout << "Sent \"" << data << "\" (" << length << " bytes) to the Arduino." << std::endl;
                } else {
                    std::cerr << "Error sending data: " << error.message() << std::endl;
                }
                p.set_value(); // Notify that the operation is complete
            }
        );
    }

private:
    boost::asio::io_service io_service_;
    boost::asio::serial_port serial_port_;
    std::thread io_thread_;
    std::atomic<bool> keep_running_;
};

int main() {
    try {
        // Replace with your serial port name and baud rate
        SerialCommunicator communicator("/dev/tty.usbmodem11101", 38400);

        // Example data to send
        std::string data_to_send = "TOGGLE";

        // Vector of futures to wait for all asynchronous operations to complete
        std::vector<std::future<void>> futures;

        // Mutex and condition variable for waiting
        std::mutex mtx;
        std::condition_variable cv;
        size_t pending_operations = 0;

        // Send data to the Arduino in a loop
        for (int i = 0; i < 10; ++i) { // Limiting the number of iterations for demonstration
            std::cout << "Sending data" << std::endl;
            std::promise<void> promise;
            futures.push_back(promise.get_future());

            {
                std::lock_guard<std::mutex> lock(mtx);
                ++pending_operations;
            }
            communicator.send_data(data_to_send, std::move(promise));

            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        // Wait for all asynchronous operations to complete
        for (auto& future : futures) {
            future.get(); // Blocks until the promise is set
        }

        // Allow some time for the asynchronous operation to complete
        std::this_thread::sleep_for(std::chrono::seconds(1));

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
