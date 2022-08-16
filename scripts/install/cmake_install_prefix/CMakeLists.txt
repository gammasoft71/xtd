cmake_minimum_required(VERSION 3.3)
project(cmake_install_prefix)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/cmake_install_prefix.txt 
"${CMAKE_INSTALL_PREFIX}")
