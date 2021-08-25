#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

int main() {
  bool terminate = false;
  
  thread server([&] {
    socket server_socket(address_family::inter_network_v6, socket_type::dgram, protocol_type::udp);
    server_socket.bind(ip_end_point(ip_address::ip_v6_any, 9400));
    
    while (!terminate) {
      vector<byte_t> buffer(256);
      ip_end_point incoming_end_point;
      size_t number_of_byte_received = server_socket.receive_from(buffer, incoming_end_point);
      if (!(number_of_byte_received == 1 && buffer[0] == 0xFF))
        console::write_line(ustring(buffer.begin(), buffer.begin() + number_of_byte_received));
    }
  });
  
  thread client([&] {
    socket client_socket(address_family::inter_network_v6, socket_type::dgram, protocol_type::udp);
    
    int counter = 1;
    while (!terminate) {
      ustring str = ustring::format("counter={}", counter++);
      client_socket.send_to(vector<byte_t>(str.begin(), str.end()), ip_end_point(ip_address::ip_v6_loopback, 9400));
      this_thread::sleep_for(50ms);
    }
    
    client_socket.send_to(vector<byte_t> {0xFF}, ip_end_point(ip_address::ip_v6_loopback, 9400));
  });

  console::read_key();
  terminate = true;
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
