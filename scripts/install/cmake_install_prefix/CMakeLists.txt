cmake_minimum_required(VERSION 3.20)
project(cmake_install_prefix)

set(XTD_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
if (MSVC)
  string(REPLACE "/" "\\" XTD_INSTALL_PREFIX ${XTD_INSTALL_PREFIX})
  string(REPLACE "\\cmake_install_prefix" "" XTD_INSTALL_PREFIX ${XTD_INSTALL_PREFIX})
endif ()
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/cmake_install_prefix.txt 
"${XTD_INSTALL_PREFIX}")
