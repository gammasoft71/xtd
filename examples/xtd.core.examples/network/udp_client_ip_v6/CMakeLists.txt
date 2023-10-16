cmake_minimum_required(VERSION 3.20)

project(udp_client_ip_v6)
find_package(xtd REQUIRED)
add_sources(README.md src/udp_client_ip_v6.cpp)
target_type(CONSOLE_APPLICATION)
