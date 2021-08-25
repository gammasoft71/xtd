cmake_minimum_required(VERSION 3.3)

project(network)
find_package(xtd REQUIRED)

add_projects(
  socket_tcp_ip_v4
  socket_tcp_ip_v6
  socket_udp_ip_v4
  socket_udp_ip_v6
)
