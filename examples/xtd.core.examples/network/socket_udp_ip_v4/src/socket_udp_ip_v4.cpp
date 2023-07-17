#include <xtd/net/sockets/socket>
#include <xtd/net/ip_end_point>
#include <xtd/console>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto main()->int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto server_socket = socket {address_family::inter_network, socket_type::dgram, protocol_type::udp};
    server_socket.bind(ip_end_point {ip_address::any, 9400});
    
    while (!terminate_app) {
      auto buffer = vector<unsigned char>(256);
      auto incoming_end_point = ip_end_point {};
      auto number_of_byte_received = server_socket.receive_from(buffer, incoming_end_point);
      if (!(number_of_byte_received == 1 && buffer[0] == 0xFF))
        console::write_line(ustring(buffer.begin(), buffer.begin() + number_of_byte_received));
    }
  }};
  
  auto client = thread{[&] {
    auto client_socket = socket {address_family::inter_network, socket_type::dgram, protocol_type::udp};
    
    auto counter = 1;
    while (!terminate_app) {
      auto str = ustring::format("counter={}", counter++);
      client_socket.send_to(vector<unsigned char> {str.begin(), str.end()}, ip_end_point {ip_address::loopback, 9400});
      sleep_for(50_ms);
    }
    
    client_socket.send_to(vector<unsigned char> {0xFF}, ip_end_point {ip_address::loopback, 9400});
  }};
  
  console::read_key();
  terminate_app = true;
  server.join();
  client.join();
}

// This code produces the following output:
//
// counter=1
// counter=2
// counter=3
// counter=4
// counter=5
// ...
