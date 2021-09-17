cmake_minimum_required(VERSION 3.3)

project(socket_tcp_ip_v4)
find_package(xtd REQUIRED)
add_sources(src/socket_tcp_ip_v4.cpp)
target_type(CONSOLE_APPLICATION)
