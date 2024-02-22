cmake_minimum_required(VERSION 3.26)
project(boostAsio)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost
        COMPONENTS
        thread
        chrono
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

#add_executable(boostAsio server.cpp)
#add_executable(client client.cpp)
#add_executable(syncClient1 daytime1/syncTCPClient.cpp)
#add_executable(syncServer1 daytime1/syncTCPServer.cpp)
#add_executable(asyncServer1 daytime1/asyncTCPServer.cpp)
add_executable(chatServer chatServer/server/serverMain.cpp)
add_executable(chatClient chatServer/client/clientMain.cpp
        chatServer/client/Client.cpp
        chatServer/client/Client.h)

target_link_libraries(chatServer ${Boost_LIBRARIES})
target_link_libraries(chatClient ${Boost_LIBRARIES})
#target_link_libraries(chatServer Boost::thread Boost::chrono)
#target_link_libraries(chatClient Boost::thread Boost::chrono)