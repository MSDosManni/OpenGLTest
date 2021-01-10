project(TCPCommunication)
cmake_minimum_required(VERSION 3.5)

set(BOOST_ROOT "C:/Program Files/boost_1_75_0")

SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREAD ON)

find_package(Boost 1.42.0 COMPONENTS system thread regex REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})


add_executable(TCPClient TCPClient.cpp)
target_link_libraries(TCPClient ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

add_executable(TCPServer TCPServer.cpp)
target_link_libraries(TCPServer ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
