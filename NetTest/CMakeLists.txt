project(TCPCommunication)
cmake_minimum_required(VERSION 3.5)

find_package(Boost 1.42.0 REQUIRED COMPONENTS system thread regex)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)

if (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
else()
    message("Boost not found.")
endif()

add_executable(TCPClient TCPClient.cpp)
target_link_libraries(TCPClient ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

add_executable(TCPServer TCPServer.cpp)
target_link_libraries(TCPServer ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
