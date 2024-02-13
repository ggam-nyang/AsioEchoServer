#include <boost/asio.hpp>
#include <iostream>

std::string getData(boost::asio::ip::tcp::socket &socket) {
    boost::asio::streambuf buffer;
    boost::system::error_code error;

    boost::asio::read_until(socket, buffer, '\n', error);
    if (error) return error.message();

    std::string data = boost::asio::buffer_cast<const char *>(buffer.data());
    return data;
}

// Driver program to send data
void sendData(boost::asio::ip::tcp::socket &socket, const std::string &message) {
    write(socket,
          boost::asio::buffer(message + "\n"));
}

int main() {
    boost::asio::io_context io_context_object;
    boost::asio::ip::tcp::socket socket_object(io_context_object);
    socket_object.connect(
            boost::asio::ip::tcp::endpoint(
                    boost::asio::ip::address::from_string("127.0.0.1"),
                    8888
            )
    );

    while (true) {
        std::string message;
        std::cout << "Enter Message: ";
        std::cin >> message;
        sendData(socket_object, message);
        std::cout << "Server replied: " << getData(socket_object) << std::endl;
    }

    return 0;
}