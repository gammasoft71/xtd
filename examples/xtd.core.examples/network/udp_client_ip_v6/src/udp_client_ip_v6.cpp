#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

int main() {
  auto terminate_app = false;
  
  thread server([&] {
    udp_client udp(ip_end_point(ip_address::ip_v6_any, 9400));
    
    while (!terminate_app) {
      ip_end_point incoming_end_point;
      auto buffer = udp.receive(incoming_end_point);
      if (buffer.size() && buffer[0] != 0xFF)
        console::write_line(ustring(buffer.begin(), buffer.end()));
    }
  });
  
  thread client([&] {
    udp_client udp(address_family::inter_network_v6);
    
    auto counter = 1;
    while (!terminate_app) {
      auto str = ustring::format("counter={}", counter++);
      udp.send(vector<byte_t>(str.begin(), str.end()), str.size(), ip_end_point(ip_address::ip_v6_loopback, 9400));
      this_thread::sleep_for(50ms);
    }
    
    udp.send(vector<byte_t> {0xFF}, 1, ip_end_point(ip_address::ip_v6_loopback, 9400));
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
