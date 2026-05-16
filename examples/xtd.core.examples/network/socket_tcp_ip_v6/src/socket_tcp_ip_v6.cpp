#include <xtd/xtd>

auto main() -> int {
  auto server = jthread::start_new([] {
    auto server_socket = net::sockets::socket {net::sockets::address_family::inter_network_v6, net::sockets::socket_type::stream, net::sockets::protocol_type::tcp};
    server_socket.bind(net::ip_end_point {net::ip_address::ip_v6_any, 9400});
    server_socket.listen();
    auto new_socket = server_socket.accept();
    auto buffer = array<byte>(4_z);
    for (auto counter = 0; counter != -1;) {
      new_socket.receive(buffer);
      counter = bit_converter::to_int32(buffer, 0);
      if (counter != -1) console::write_line("recv => {}", counter);
    }
  });
  thread::sleep(100_ms); // wait server ready before connect client

  auto client = jthread::start_new([] {
    auto client_socket = net::sockets::socket {net::sockets::address_family::inter_network_v6, net::sockets::socket_type::stream, net::sockets::protocol_type::tcp};
    client_socket.connect(net::ip_address::ip_v6_loopback, 9400);
    for (auto counter = 1; counter <= 100; ++counter) {
      client_socket.send(bit_converter::get_bytes(counter));
      thread::sleep(50_ms);
    }
    client_socket.send(bit_converter::get_bytes(-1));
  });
}

// This code produces the following output :
//
// recv => 1
// recv => 2
// recv => 3
// ...
// recv => 98
// recv => 99
// recv => 100
