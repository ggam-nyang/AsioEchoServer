//
// Created by ggam-nyang on 2/13/24.
//

#include "User.h"
#include "Lobby.h"

User::User(Connection::pointer connectionPtr) : connectionPtr_(std::move(connectionPtr)) {}

User::pointer User::create(const Connection::pointer &connectionPtr) {
    return make_shared<User>(connectionPtr);
}

void User::start() {
    connectionPtr_->start();
}

void User::readMessage() {
    std::string message = connectionPtr_->readMessage();
    lobbyPtr_->writeMessage(message);
}

void User::writeMessage(const std::string &message) {
    connectionPtr_->writeMessage(message);
}
