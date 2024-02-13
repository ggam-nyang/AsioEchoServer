//
// Created by ggam-nyang on 2/13/24.
//

#ifndef BOOSTASIO_USER_H
#define BOOSTASIO_USER_H

#include "Connection.h"

class Lobby;

class User : public std::enable_shared_from_this<User> {
public:
    using pointer = std::shared_ptr<User>;

    static pointer create(const Connection::pointer &connectionPtr);

    explicit User(Connection::pointer connectionPtr);

    void start();
//    void enterLobby();
//    void leaveLobby();
    void writeMessage(const std::string &message);
    void readMessage();

    std::string name;
private:
    Connection::pointer connectionPtr_;
    Lobby *lobbyPtr_;
};


#endif //BOOSTASIO_USER_H
