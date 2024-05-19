#include <xtd/io/stream_reader>
#include <xtd/io/stream_writer>
#include <xtd/net/sockets/socket>
#include <xtd/net/sockets/network_stream>
#include <xtd/net/ip_end_point>
#include <xtd/threading/thread>
#include <xtd/console>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::threading;

auto main() -> int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto server_socket = socket {address_family::inter_network, socket_type::stream, protocol_type::tcp};
    server_socket.bind(ip_end_point {ip_address::any, 9400});
    server_socket.listen();
    auto stream = network_stream {server_socket.accept()};
    auto reader = stream_reader {stream};
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  }};
  server.start();
  
  auto client = thread {[&] {
    auto stream = network_stream {socket {address_family::inter_network, socket_type::stream, protocol_type::tcp}};
    stream.socket().connect(ip_address::loopback, 9400);
    auto writer = stream_writer {stream};
    
    auto counter = 0;
    while (!terminate_app) {
      writer.write_line(ustring::format("counter={}", ++counter));
      thread::sleep(50_ms);
    }
  }};
  client.start();
  
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
