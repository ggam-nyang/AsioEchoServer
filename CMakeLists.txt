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
    #    message(STATUS "Boost found")
endif ()

add_executable(boostAsio server.cpp)
add_executable(client client.cpp)
add_executable(syncClient1 daytime1/syncTCPClient.cpp)
add_executable(syncServer1 daytime1/syncTCPServer.cpp)
