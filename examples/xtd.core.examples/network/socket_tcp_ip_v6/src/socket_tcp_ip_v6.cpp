#include <xtd/xtd>

auto main() -> int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto server_socket = net::sockets::socket {net::sockets::address_family::inter_network_v6, net::sockets::socket_type::stream, net::sockets::protocol_type::tcp};
    server_socket.bind(net::ip_end_point {net::ip_address::ip_v6_any, 9400});
    server_socket.listen();
    auto new_socket = server_socket.accept();
    
    while (!terminate_app) {
      auto buffer = array<byte>(256);
      auto number_of_byte_received = new_socket.receive(buffer);
      if (number_of_byte_received) console::write_line(string(buffer.begin(), buffer.begin() + number_of_byte_received));
    }
  }};
  
  auto client = thread {[&] {
    auto client_socket = net::sockets::socket {net::sockets::address_family::inter_network_v6, net::sockets::socket_type::stream, net::sockets::protocol_type::tcp};
    client_socket.connect(net::ip_address::ip_v6_loopback, 9400);
    
    auto counter = 0;
    while (!terminate_app) {
      auto str = string::format("counter={}", ++counter);
      client_socket.send(array<byte> {str.begin(), str.end()});
      thread::sleep(50_ms);
    }
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
