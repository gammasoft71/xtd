#include <xtd/io/stream_reader>
#include <xtd/net/sockets/udp_client>
#include <xtd/net/ip_end_point>
#include <xtd/console>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto main()->int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto udp = udp_client {ip_end_point {ip_address::any, 9400}};
    while (!terminate_app) {
      ip_end_point incoming_end_point;
      auto buffer = udp.receive(incoming_end_point);
      if (buffer.size() && buffer[0] != 0xFF)
        console::write_line(ustring(buffer.begin(), buffer.end()));
    }
  }};
  
  auto client = thread {[&] {
    auto udp = udp_client {};
    auto counter = 0;
    while (!terminate_app) {
      auto str = ustring::format("counter={}", ++counter);
      udp.send(vector<unsigned char>(str.begin(), str.end()), str.size(), ip_end_point(ip_address::loopback, 9400));
      sleep_for(50_ms);
    }
    udp.send(vector<unsigned char> {0xFF}, 1, ip_end_point(ip_address::loopback, 9400));
  }};
  
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
