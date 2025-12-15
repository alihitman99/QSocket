cmake_minimum_required(VERSION 3.16)
project(chatClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Network Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appclient
    main.cpp
)

qt_add_qml_module(appclient
    URI chatClient
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES chatclient.h chatclient.cpp
        SOURCES chatClientModel.h chatClientModel.cpp
)

target_link_libraries(appclient PRIVATE Qt6::Core Qt6::Network Qt6::Quick)

# add_executable(client mainClient.cpp
#     chatclient.h chatclient.cpp)
# target_link_libraries(client PRIVATE Qt6::Core Qt6::Network Qt6::Quick)
