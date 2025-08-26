#include <xtd/xtd>

auto main() -> int {
  auto terminate_app = false;
  
  auto server = thread {[&] {
    auto listener = net::sockets::tcp_listener::create(9400);
    listener.start();
    auto stream = listener.accept_tcp_client().get_stream();
    auto reader = stream_reader {stream};
    
    while (!terminate_app)
      if (stream.data_available()) console::write_line(reader.read_line());
  }};
  
  auto client = thread {[&] {
    auto client = net::sockets::tcp_client {};
    client.connect(net::ip_address::loopback, 9400);
    auto stream = client.get_stream();
    auto writer = stream_writer {stream};
    
    auto counter = 0;
    while (!terminate_app) {
      writer.write_line("counter={}", ++counter);
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

// This code produces the following output :
//
// counter=1
// counter=2
// counter=3
// counter=4
// counter=5
// ...
