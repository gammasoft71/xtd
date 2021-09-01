cmake_minimum_required(VERSION 3.3)

project(udp_client_ip_v4)
find_package(xtd REQUIRED)
add_sources(src/udp_client_ip_v4.cpp)
target_type(CONSOLE_APPLICATION)
