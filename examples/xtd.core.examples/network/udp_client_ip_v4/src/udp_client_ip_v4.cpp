#include <xtd/xtd>

auto main() -> int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto udp = net::sockets::udp_client {net::ip_end_point {net::ip_address::any, 9400}};
    while (!terminate_app) {
      auto incoming_end_point = net::ip_end_point {};
      auto buffer = udp.receive(incoming_end_point);
      if (buffer.length() && buffer[0] != 0xFF)
        console::write_line(string(buffer.begin(), buffer.end()));
    }
  }};
  
  auto client = thread {[&] {
    auto udp = net::sockets::udp_client {};
    auto counter = 0;
    while (!terminate_app) {
      auto str = string::format("counter={}", ++counter);
      udp.send(array<byte>(str.begin(), str.end()), str.length(), net::ip_end_point(net::ip_address::loopback, 9400));
      thread::sleep(50_ms);
    }
    udp.send(array<byte> {0xFF}, 1, net::ip_end_point(net::ip_address::loopback, 9400));
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
