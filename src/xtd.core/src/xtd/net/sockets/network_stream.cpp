#include "../../../../include/xtd/net/sockets/network_stream.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

network_stream::socket_streambuf::socket_streambuf(const xtd::net::sockets::socket& socket, bool owns_socket) : socket_(socket), owns_socket_(owns_socket) {
}

network_stream::socket_streambuf::~socket_streambuf() {
  if (owns_socket_) socket_.close();
}

int network_stream::socket_streambuf::underflow() {
  std::vector<byte_t> buffer(1);
  if (socket_.receive(buffer) == 1) {
    value_ = static_cast<char>(buffer[0]);
    setg(&value_, &value_, &value_+1);
    return value_;
  }
  return std::streambuf::underflow(); // EOF
}

int network_stream::socket_streambuf::overflow(int value) {
  value_ = static_cast<char>(value);
  std::vector<byte_t> buffer {static_cast<byte_t>(value_)};
  if (socket_.send(buffer) == 1) {
    setp(&value_, &value_);
    return 0;
  }
  return std::streambuf::overflow(value); // EOF
}

network_stream::network_stream(const xtd::net::sockets::socket& socket) : std::iostream(&stream_buf_), stream_buf_(socket, false) {
}

network_stream::network_stream(const xtd::net::sockets::socket& socket, bool owns_socket) : std::iostream(&stream_buf_), stream_buf_(socket, owns_socket) {
}

bool network_stream::data_available() const {
  return stream_buf_.socket_.available() != 0;
}

xtd::net::sockets::socket network_stream::socket() const {
  return stream_buf_.socket_;
}
