cmake_minimum_required(VERSION 3.20)
project(Central_station)

set(CMAKE_CXX_STANDARD 20)
find_package(Threads)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(Central_station src/msg_outline/T2msg.cpp
        src/msg_outline/T2msg.h
        src/msg_outline/Generalmsg.cpp
        src/msg_outline/Generalmsg.h
        src/msg_outline/Logmsg.cpp
        src/msg_outline/Logmsg.h
        src/msg_outline/T3msg.cpp
        src/msg_outline/T3msg.h
        src/msg_outline/MsgHistory.cpp
        src/msg_outline/MsgHistory.h
        src/msg_outline/Cmdmsg.h
        src/msg_outline/Cmdmsg.cpp
        src/msg_outline/augermsg.h
        src/CentralProccess.cpp
        src/CentralProccess.h
        src/t2li.h
        src/client.cpp
        src/server.cpp
        src/networkcom.cpp
        src/networkcom.h
        )
