#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;
using namespace xtd::net::sockets;

int main() {
  auto terminate_app = false;
  
  thread server([&] {
    socket server_socket(address_family::inter_network, socket_type::stream, protocol_type::tcp);
    server_socket.bind(ip_end_point(ip_address::any, 9400));
    server_socket.listen();
    network_stream stream(server_socket.accept());
    stream_reader reader(stream);
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  });
  
  thread client([&] {
    network_stream stream(socket(address_family::inter_network, socket_type::stream, protocol_type::tcp));
    stream.socket().connect(ip_address::loopback, 9400);
    stream_writer writer(stream);
    
    auto counter = 1;
    while (!terminate_app) {
      writer.write_line(ustring::format("counter={}", counter++));
      this_thread::sleep_for(50ms);
    }
  });
  
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
