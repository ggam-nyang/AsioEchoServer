//
// Created by ggam-nyang on 2/13/24.
//

#include "Lobby.h"

const std::string Lobby::kWelcomeString = "Welcome to the chat server!\n";

void Lobby::enter(User::pointer user) {
    user->writeMessage(kWelcomeString);
}

void Lobby::writeMessage(const std::string &message) {
    for (const auto &user : users_) {
        user->writeMessage(message);
    }
}

