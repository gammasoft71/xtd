#include <xtd/xtd>

auto main() -> int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto server_socket = net::sockets::socket {net::sockets::address_family::inter_network, net::sockets::socket_type::stream, net::sockets::protocol_type::tcp};
    server_socket.bind(net::ip_end_point {net::ip_address::any, 9400});
    server_socket.listen();
    auto stream = net::sockets::network_stream {server_socket.accept(), file_access::read};
    auto reader = stream_reader {stream};
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  }};
  server.start();
  
  auto client = thread {[&] {
    auto stream = net::sockets::network_stream {net::sockets::socket {net::sockets::address_family::inter_network, net::sockets::socket_type::stream, net::sockets::protocol_type::tcp}, file_access::write};
    stream.socket().connect(net::ip_address::loopback, 9400);
    auto writer = stream_writer {stream};
    
    auto counter = 0;
    while (!terminate_app) {
      writer.write_line("counter={}", ++counter);
      thread::sleep(50_ms);
    }
  }};
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
