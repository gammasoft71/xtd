#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

int main() {
  bool terminate_app = false;
  
  thread server([&] {
    socket server_socket(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
    server_socket.bind(ip_end_point(ip_address::ip_v6_any, 9400));
    server_socket.listen();
    socket new_socket = server_socket.accept();

    while (!terminate_app) {
      vector<byte_t> buffer(256);
      size_t number_of_byte_received = new_socket.receive(buffer);
      if (number_of_byte_received) console::write_line(ustring(buffer.begin(), buffer.begin() + number_of_byte_received));
    }
  });
  
  thread client([&] {
    socket client_socket(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
    client_socket.connect(ip_address::ip_v6_loopback, 9400);
    
    int counter = 1;
    while (!terminate_app) {
      ustring str = ustring::format("counter={}", counter++);
      client_socket.send(vector<byte_t>(str.begin(), str.end()));
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
