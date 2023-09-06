#include <xtd/io/stream_reader>
#include <xtd/net/sockets/tcp_client>
#include <xtd/net/sockets/tcp_listener>
#include <xtd/threading/thread>
#include <xtd/console>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::threading;

auto main()->int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto listener = tcp_listener::create(9400);
    listener.start();
    auto stream = listener.accept_tcp_client().get_stream();
    auto reader = stream_reader {stream};
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  }};
  
  auto client = thread {[&] {
    auto client = tcp_client {};
    client.connect(ip_address::loopback, 9400);
    auto stream = client.get_stream();
    auto writer = stream_writer {stream};
    
    auto counter = 0;
    while (!terminate_app) {
      writer.write_line(ustring::format("counter={}", ++counter));
      thread::sleep(50_ms);
    }
  }};

  server.start();
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
