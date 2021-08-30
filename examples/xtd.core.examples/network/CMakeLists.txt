cmake_minimum_required(VERSION 3.3)

project(network)
find_package(xtd REQUIRED)

add_projects(
  dns_get_host_addresses
  dns_get_host_entry
  network_stream
  socket_tcp_ip_v4
  socket_tcp_ip_v4_without_thread
  socket_tcp_ip_v6
  socket_udp_ip_v4
  socket_udp_ip_v6
  tcp_client
)
