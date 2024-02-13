//
// Created by ggam-nyang on 2/12/24.
//

#ifndef BOOSTASIO_SERVER_H
#define BOOSTASIO_SERVER_H

#include <string>
#include <boost/asio.hpp>
#include "Connection.h"
#include "Lobby.h"

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context &io_context, const tcp::endpoint &endpoint);

private:
    boost::asio::io_context &io_context_;
    tcp::acceptor acceptor_;
    Lobby::pointer lobbyPtr_ = std::make_shared<Lobby>();

    void start_accept();
    void handle_accept(User::pointer newUser, const boost::system::error_code &error);
};

#endif //BOOSTASIO_SERVER_H
