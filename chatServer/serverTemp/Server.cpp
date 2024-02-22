//
// Created by ggam-nyang on 2/12/24.
//

#include "Server.h"
class Connection;

Server::Server(boost::asio::io_context &io_context, const tcp::endpoint &endpoint)
        : io_context_(io_context),
          acceptor_(io_context, endpoint) {
    start_accept();
}

void Server::start_accept() {
    Connection::pointer new_connection = Connection::create(io_context_);
    User::pointer newUser = User::create(new_connection);
    lobbyPtr_->enter(newUser);

    acceptor_.async_accept(new_connection->socket(),
                           std::bind(&Server::handle_accept, this, newUser,
                                     boost::asio::placeholders::error));
}

void Server::handle_accept(User::pointer newUser,
                           const boost::system::error_code &error) {
    if (!error) {
        newUser->start(); // FIXME:
    }

    start_accept();
}