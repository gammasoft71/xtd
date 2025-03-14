#include "../../../../include/xtd/net/sockets/socket_async_event_args.hpp"
#include "../../../../include/xtd/argument_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

xtd::net::sockets::socket socket_async_event_args::accept_socket() const noexcept {
  return accept_socket_;
}

socket_async_event_args& socket_async_event_args::accept_socket(const xtd::net::sockets::socket& value) noexcept {
  accept_socket_ = value;
  return *this;
}

const xtd::array<xtd::byte>& socket_async_event_args::buffer() const noexcept {
  return buffer_;
}

xtd::array<xtd::byte>& socket_async_event_args::buffer() noexcept {
  return buffer_;
}

void socket_async_event_args::set_buffer(const xtd::array<xtd::byte>& memory_buffer) {
  memory_buffer_ = memory_buffer;
}

void socket_async_event_args::set_buffer(size_t offset, size_t count) {
  set_buffer(buffer_, offset, count);
}

void socket_async_event_args::set_buffer(const xtd::array<xtd::byte>& buffer, size_t offset, size_t count) {
  if (offset + count > buffer_.size()) throw_helper::throws(exception_case::argument_out_of_range);
  buffer_ = buffer;
  offset_ = offset;
  count_ = count;
}

void socket_async_event_args::on_complete(const socket_async_event_args& e) {
  completed(e);
}
