//
// Created by ggam-nyang on 2/13/24.
//

#ifndef BOOSTASIO_LOBBY_H
#define BOOSTASIO_LOBBY_H

#include <memory>
#include <set>
#include "User.h"

class Lobby {
public:
    using pointer = std::shared_ptr<Lobby>;

    static void enter(User::pointer user);
    void leave(User::pointer user);
    void writeMessage(User::pointer sender, const std::string &message);

    std::set<User::pointer> users_;

private:
    static const std::string kWelcomeString;
};



#endif //BOOSTASIO_LOBBY_H
