cmake_minimum_required(VERSION 3.26)
project(boostAsio)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost
        REQUIRED
)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    #    link_directories(${Boost_LIBRARY_DIRS})
    #    add_definitions( "-DHAS_BOOST" )
    #    Message(STATUS "Boost found")
endif ()

find_package(Protobuf REQUIRED)
if (Protobuf_FOUND)
    include_directories(${Protobuf_INCLUDE_DIRS})
endif ()

add_executable(boostAsio server.cpp)
add_executable(client client.cpp)
add_executable(syncClient1 daytime1/syncTCPClient.cpp)
add_executable(syncServer1 daytime1/syncTCPServer.cpp)
add_executable(asyncServer1 daytime1/asyncTCPServer.cpp)
add_executable(chatServer1 chatServer/server/serverMain.cpp
        chatServer/server/Server.cpp
        chatServer/server/Connection.cpp
        chatServer/server/Connection.h
        chatServer/server/Lobby.cpp
        chatServer/server/Lobby.h
        chatServer/server/User.cpp
        chatServer/server/User.h
)
