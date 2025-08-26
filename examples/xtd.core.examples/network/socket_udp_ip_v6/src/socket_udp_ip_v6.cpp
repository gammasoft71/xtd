#include <xtd/xtd>

auto main() -> int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto server_socket = net::sockets::socket {net::sockets::address_family::inter_network_v6, net::sockets::socket_type::dgram, net::sockets::protocol_type::udp};
    server_socket.bind(net::ip_end_point {net::ip_address::ip_v6_any, 9400});
    
    while (!terminate_app) {
      auto buffer = array<byte>(256);
      auto incoming_end_point = net::ip_end_point {};
      auto number_of_byte_received = server_socket.receive_from(buffer, incoming_end_point);
      if (!(number_of_byte_received == 1 && buffer[0] == 0xFF))
        console::write_line(string(buffer.begin(), buffer.begin() + number_of_byte_received));
    }
  }};
  
  auto client = thread{[&] {
    auto client_socket = net::sockets::socket {net::sockets::address_family::inter_network_v6, net::sockets::socket_type::dgram, net::sockets::protocol_type::udp};
    
    auto counter = 0;
    while (!terminate_app) {
      auto str = string::format("counter={}", ++counter);
      client_socket.send_to(array<byte>(str.begin(), str.end()), net::ip_end_point {net::ip_address::ip_v6_loopback, 9400});
      thread::sleep(50_ms);
    }
    
    client_socket.send_to(array<byte> {0xFF}, net::ip_end_point {net::ip_address::ip_v6_loopback, 9400});
  }};
  
  server.start();
  client.start();

  console::read_key();
  terminate_app = true;
  server.join();
  client.join();
}

// This code produces the following output :
//
// counter=1
// counter=2
// counter=3
// counter=4
// counter=5
// ...
