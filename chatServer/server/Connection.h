//
// Created by ggam-nyang on 2/12/24.
//

#ifndef BOOSTASIO_CONNECTION_H
#define BOOSTASIO_CONNECTION_H

#include <memory>
#include "boost/asio.hpp"

class Connection : public std::enable_shared_from_this<Connection> {
public:
    using pointer = std::shared_ptr<Connection>;

    static pointer create(boost::asio::io_context &io_context);

    boost::asio::ip::tcp::socket &socket();

    void start();

    void writeMessage(const std::string &message);

    std::string readMessage();


private:
    explicit Connection(boost::asio::io_context &io_context);

    void handle_write(const boost::system::error_code & /*error*/, size_t /*bytes_transferred*/);

    boost::asio::ip::tcp::socket socket_;
    std::string buffer_;

    static const std::string kInputUserNameStr;
    static const std::string kGreetingStr;
};

#endif //BOOSTASIO_CONNECTION_H
