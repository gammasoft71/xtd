cmake_minimum_required(VERSION 3.3)

project(tcp_client)
find_package(xtd REQUIRED)
add_sources(src/tcp_client.cpp)
target_type(CONSOLE_APPLICATION)
