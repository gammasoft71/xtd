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
    tcp_listener listener(ip_end_point(ip_address::ip_v6_any, 9400));
    listener.start();
    auto stream = listener.accept_tcp_client().get_stream();
    stream_reader reader(stream);
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  });
  
  thread client([&] {
    tcp_client client(address_family::inter_network_v6);
    client.connect(ip_address::ip_v6_loopback, 9400);
    auto stream = client.get_stream();
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
