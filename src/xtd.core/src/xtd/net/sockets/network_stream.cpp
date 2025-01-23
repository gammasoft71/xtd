#include "../../../../include/xtd/net/sockets/network_stream.hpp"

using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;
using namespace xtd::net::sockets;

network_stream::network_stream(const sockets::socket& socket) : network_stream {socket, file_access::read_write, false} {
}

network_stream::network_stream(const sockets::socket& socket, bool owns_socket) : network_stream {socket, file_access::read_write, owns_socket}  {
}

network_stream::network_stream(const sockets::socket& socket, file_access access) : network_stream {socket, access, false} {
}

network_stream::network_stream(const sockets::socket& socket, file_access access, bool owns_socket) {
  data_->socket = socket;
  data_->access = access;
  data_->owns_socket = owns_socket;
}

network_stream::~network_stream() {
  if (data_->owns_socket) data_->socket.close();
}

bool network_stream::can_read() const noexcept {
  return (data_->access & file_access::read) == file_access::read;
}

bool network_stream::can_seek() const noexcept {
  return false;
}


bool network_stream::can_timeout() const noexcept {
  return true;
}

bool network_stream::can_write() const noexcept {
  return (data_->access & file_access::write) == file_access::write;
}

bool network_stream::data_available() const {
  return data_->socket.available() != 0;
}

size network_stream::length() const {
  return 1;
}

size network_stream::position() const {
  return 0;
}

void network_stream::position(size value) {
  throw not_supported_exception {};
}

int32 network_stream::read_timeout() const {
  return data_->socket.receive_timeout();
}

void network_stream::read_timeout(int32 value) {
  data_->socket.receive_timeout(value);
}

int32 network_stream::write_timeout() const {
  return data_->socket.send_timeout();
}

void network_stream::write_timeout(int32 value) {
  data_->socket.send_timeout(value);
}

xtd::net::sockets::socket network_stream::socket() const {
  return data_->socket;
}

void network_stream::flush() {
}

size network_stream::read(array<byte>& buffer, size offset, size count) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};
  
  return data_->socket.receive(buffer, offset, count, socket_flags::none);
}

void network_stream::set_length(size value) {
  throw not_supported_exception {};
}

void network_stream::write(const array<byte>& buffer, size offset, size count) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_write()) throw not_supported_exception {};
  
  data_->socket.send(buffer, offset, count, socket_flags::none);
}
