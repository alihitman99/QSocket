cmake_minimum_required(VERSION 3.16)
project(QSocket LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_executable(server mainServer.cpp
    chatserver.h chatserver.cpp)
target_link_libraries(server PRIVATE Qt6::Core Qt6::Network)

add_executable(client mainClient.cpp
    chatclient.h chatclient.cpp)
target_link_libraries(client PRIVATE Qt6::Core Qt6::Network)
