#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

bool terminate_app = false;

void on_server_accept(shared_ptr<iasync_result> ar) {
  xtd::net::sockets::socket socket = as<xtd::net::sockets::socket>(ar->async_state()).end_accept(ar);

  while (!terminate_app) {
    vector<byte_t> buffer(256);
    size_t number_of_byte_received = socket.receive(buffer);
    if (number_of_byte_received) console::write_line(ustring(buffer.begin(), buffer.begin() + number_of_byte_received));
  }
}

void on_client_connect(shared_ptr<iasync_result> ar) {
  xtd::net::sockets::socket socket = as<xtd::net::sockets::socket>(ar->async_state());
  socket.end_connect(ar);
  
  int counter = 1;
  while (!terminate_app) {
    ustring str = ustring::format("socket={}, counter={}", socket.handle(), counter++);
    socket.send(vector<byte_t>(str.begin(), str.end()));
    this_thread::sleep_for(50ms);
  }
}

int main() {
  const size_t client_count = 10;
  
  socket server_socket(address_family::inter_network, socket_type::stream, protocol_type::tcp);
  server_socket.bind(ip_end_point(ip_address::any, 9400));
  server_socket.listen();
  for (auto index = 0U; index < client_count; ++index)
    server_socket.begin_accept(async_callback(on_server_accept), server_socket);

  for (auto index = 0U; index < client_count; ++index) {
    xtd::net::sockets::socket socket(address_family::inter_network, socket_type::stream, protocol_type::tcp);
    socket.begin_connect(ip_address::loopback, 9400, async_callback(on_client_connect), socket);
  }
  
  console::read_key();
  terminate_app = true;
}

// This code can produce the following output:
//
// socket=4, counter=1
// socket=5, counter=1
// socket=6, counter=1
// socket=9, counter=1
// socket=10, counter=1
// socket=12, counter=1
// socket=15, counter=1
// socket=17, counter=1
// socket=18, counter=1
// socket=20, counter=1
// socket=5, counter=2
// socket=4, counter=2
// socket=6, counter=2
// socket=9, counter=2
// socket=10, counter=2
// socket=12, counter=2
// socket=17, counter=2
// socket=18, counter=2
// socket=15, counter=2
// socket=20, counter=2
// socket=10, counter=3
// socket=12, counter=3
// socket=15, counter=3
// socket=17, counter=3
// socket=4, counter=3
// socket=6, counter=3
// socket=9, counter=3
// socket=5, counter=3
// socket=20, counter=3
// socket=18, counter=3
// socket=17, counter=4
// socket=9, counter=4
// socket=15, counter=4
// socket=4, counter=4
// socket=12, counter=4
// socket=6, counter=4
// socket=5, counter=4
// socket=18, counter=4
// socket=10, counter=4
// socket=20, counter=4
// socket=6, counter=5
// socket=18, counter=5
// socket=4, counter=5
// socket=12, counter=5
// socket=9, counter=5
// socket=15, counter=5
// socket=17, counter=5
// socket=5, counter=5
// socket=10, counter=5
// socket=20, counter=5
// ...
