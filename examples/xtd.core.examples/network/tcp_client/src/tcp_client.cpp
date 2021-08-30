#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;
using namespace xtd::net::sockets;

int main() {
  bool terminate_app = false;
  
  thread server([&] {
    socket server_socket(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
    server_socket.bind(ip_end_point(ip_address::ip_v6_any, 9400));
    server_socket.listen();
    network_stream stream(server_socket.accept());
    stream_reader reader(stream);
    
    while (!terminate_app)
      if (stream.data_availlable()) console::write_line(reader.read_line());
  });
  
  thread client([&] {
    tcp_client client(address_family::inter_network_v6);
    client.connect(ip_address::ip_v6_loopback, 9400);
    network_stream stream = client.get_stream();
    stream_writer writer(stream);
    
    int counter = 1;
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
