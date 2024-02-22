#include "Connection.h"
using boost::asio::ip::tcp;

const std::string Connection::kInputUserNameStr = "이름을 입력해주세요. \n";
const std::string Connection::kGreetingStr = "서버에 연결됐습니다. \n";

Connection::pointer Connection::create(boost::asio::io_context &io_context) {
    return pointer(new Connection(io_context));
}

tcp::socket& Connection::socket() {
    return socket_;
}

Connection::Connection(boost::asio::io_context &io_context): socket_(io_context) {}

void Connection::start() {
    boost::asio::async_write(socket_, boost::asio::buffer(kGreetingStr),
                             std::bind(&Connection::handle_write, shared_from_this(),
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred));
}

void Connection::writeMessage(const std::string &message) {
    boost::asio::async_write(socket_, boost::asio::buffer(message),
                             std::bind(&Connection::handle_write, shared_from_this(),
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred));
}

std::string Connection::readMessage() {
    boost::asio::async_read(socket_, boost::asio::buffer(buffer_),
                            std::bind(&Connection::handle_write, shared_from_this(),
                                      boost::asio::placeholders::error,
                                      boost::asio::placeholders::bytes_transferred));

    return buffer_;
}

void Connection::handle_write(const boost::system::error_code&, size_t) {}



