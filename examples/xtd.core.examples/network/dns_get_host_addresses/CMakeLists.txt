cmake_minimum_required(VERSION 3.20)

project(dns_get_host_addresses)
find_package(xtd REQUIRED)
add_sources(README.md src/dns_get_host_addresses.cpp)
target_type(CONSOLE_APPLICATION)
