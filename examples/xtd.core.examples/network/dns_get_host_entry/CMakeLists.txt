cmake_minimum_required(VERSION 3.20)

project(dns_get_host_entry)
find_package(xtd REQUIRED)
add_sources(src/dns_get_host_entry.cpp)
target_type(CONSOLE_APPLICATION)
