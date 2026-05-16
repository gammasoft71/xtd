#include <xtd/xtd>

auto main() -> int {
  auto server = jthread::start_new([] {
    auto listener = net::sockets::tcp_listener::create(9400);
    listener.start();
    auto stream = listener.accept_tcp_client().get_stream();
    auto reader = binary_reader {stream};
    for (auto counter = reader.read_int32(); counter != -1; counter = reader.read_int32())
      console::write_line("recv => {}", counter);
  });
  thread::sleep(100_ms); // wait server ready before connect client

  auto client = jthread::start_new([] {
    auto client = net::sockets::tcp_client {};
    client.connect(net::ip_address::loopback, 9400);
    auto stream = client.get_stream();
    auto writer = binary_writer {stream};
    for (auto counter = 1; counter <= 100; ++counter) {
      writer.write(counter);
      thread::sleep(50_ms);
    }
    writer.write(-1);
  });
}

// This code produces the following output :
//
// recv => 1
// recv => 2
// recv => 3
// ...
// recv => 98
// recv => 99
// recv => 100
