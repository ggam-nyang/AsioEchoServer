#include <iostream>
#include <boost/asio.hpp>
#include "Server.h"

int main() {
    try {
        boost::asio::io_context io_context;
        Server server(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8000));
        io_context.run();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
