#include <xtd/net/sockets/socket>
#include <xtd/net/ip_end_point>
#include <xtd/threading/thread>
#include <xtd/as>
#include <xtd/console>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::threading;

auto main()->int {
  auto terminate_app = false;
  
  auto on_server_accept = [&](async_result ar) {
    auto socket = as<xtd::net::sockets::socket>(ar->async_state()).end_accept(ar);
    
    while (!terminate_app) {
      auto buffer = std::vector<unsigned char>(256);
      auto number_of_byte_received = socket.receive(buffer);
      if (number_of_byte_received) console::write_line(ustring {buffer.begin(), buffer.begin() + number_of_byte_received});
    }
  };
  
  auto on_client_connect = [&](async_result ar) {
    auto socket = as<xtd::net::sockets::socket>(ar->async_state());
    socket.end_connect(ar);
    
    auto counter = 0;
    while (!terminate_app) {
      auto str = ustring::format("socket={}, counter={}", socket.handle(), ++counter);
      socket.send(std::vector<unsigned char> {str.begin(), str.end()});
      thread::sleep(50_ms);
    }
  };
  
  const size_t client_count = 10;
  
  auto server_socket = socket {address_family::inter_network, socket_type::stream, protocol_type::tcp};
  server_socket.bind(ip_end_point {ip_address::any, 9400});
  server_socket.listen();
  for (auto index = 0_sz; index < client_count; ++index)
    server_socket.begin_accept(async_callback(on_server_accept), server_socket);
    
  for (auto index = 0_sz; index < client_count; ++index) {
    auto socket = xtd::net::sockets::socket(address_family::inter_network, socket_type::stream, protocol_type::tcp);
    socket.begin_connect(ip_address::loopback, 9400, async_callback(on_client_connect), socket);
  }
  
  console::read_key();
  terminate_app = true;
}

// This code can produce the following output:
//
// socket=4, counter=1
// socket=5, counter=1
// socket=6, counter=1
// socket=9, counter=1
// socket=10, counter=1
// socket=12, counter=1
// socket=15, counter=1
// socket=17, counter=1
// socket=18, counter=1
// socket=20, counter=1
// socket=5, counter=2
// socket=4, counter=2
// socket=6, counter=2
// socket=9, counter=2
// socket=10, counter=2
// socket=12, counter=2
// socket=17, counter=2
// socket=18, counter=2
// socket=15, counter=2
// socket=20, counter=2
// socket=10, counter=3
// socket=12, counter=3
// socket=15, counter=3
// socket=17, counter=3
// socket=4, counter=3
// socket=6, counter=3
// socket=9, counter=3
// socket=5, counter=3
// socket=20, counter=3
// socket=18, counter=3
// socket=17, counter=4
// socket=9, counter=4
// socket=15, counter=4
// socket=4, counter=4
// socket=12, counter=4
// socket=6, counter=4
// socket=5, counter=4
// socket=18, counter=4
// socket=10, counter=4
// socket=20, counter=4
// socket=6, counter=5
// socket=18, counter=5
// socket=4, counter=5
// socket=12, counter=5
// socket=9, counter=5
// socket=15, counter=5
// socket=17, counter=5
// socket=5, counter=5
// socket=10, counter=5
// socket=20, counter=5
// ...
