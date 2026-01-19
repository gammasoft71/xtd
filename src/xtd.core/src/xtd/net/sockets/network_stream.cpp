#include "../../../../include/xtd/net/sockets/network_stream.hpp"

using namespace xtd;
using namespace xtd::helpers;
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

auto network_stream::can_read() const noexcept -> bool {
  return (data_->access & file_access::read) == file_access::read;
}

auto network_stream::can_seek() const noexcept -> bool {
  return false;
}


auto network_stream::can_timeout() const noexcept -> bool {
  return true;
}

auto network_stream::can_write() const noexcept -> bool {
  return (data_->access & file_access::write) == file_access::write;
}

auto network_stream::data_available() const -> bool {
  return data_->socket.available() != 0;
}

auto network_stream::length() const -> size {
  return 1;
}

auto network_stream::position() const -> size {
  return 0;
}

auto network_stream::position(size value) -> void {
  throw_helper::throws(exception_case::not_supported);
}

auto network_stream::read_timeout() const -> int32 {
  return data_->socket.receive_timeout();
}

auto network_stream::read_timeout(int32 value) -> void {
  data_->socket.receive_timeout(value);
}

auto network_stream::write_timeout() const -> int32 {
  return data_->socket.send_timeout();
}

auto network_stream::write_timeout(int32 value) -> void {
  data_->socket.send_timeout(value);
}

auto network_stream::socket() const -> xtd::net::sockets::socket {
  return data_->socket;
}

auto network_stream::flush() -> void {
}

auto network_stream::read(array<byte>& buffer, size offset, size count) -> size {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  return data_->socket.receive(buffer, offset, count, socket_flags::none);
}

auto network_stream::set_length(size value) -> void {
  throw_helper::throws(exception_case::not_supported);
}

auto network_stream::write(const array<byte>& buffer, size offset, size count) -> void {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_write()) throw_helper::throws(exception_case::not_supported);
  
  data_->socket.send(buffer, offset, count, socket_flags::none);
}
