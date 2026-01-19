#include "../../../../include/xtd/net/sockets/socket_async_event_args.hpp"
#include "../../../../include/xtd/argument_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto socket_async_event_args::accept_socket() const noexcept -> socket {
  return accept_socket_;
}

auto socket_async_event_args::accept_socket(const socket& value) noexcept -> socket_async_event_args& {
  accept_socket_ = value;
  return *this;
}

auto socket_async_event_args::buffer() const noexcept -> const array<xtd::byte>& {
  return buffer_;
}

auto socket_async_event_args::buffer() noexcept -> array<xtd::byte>& {
  return buffer_;
}

auto socket_async_event_args::set_buffer(const array<xtd::byte>& memory_buffer) -> void {
  memory_buffer_ = memory_buffer;
}

auto socket_async_event_args::set_buffer(size offset, size count) -> void {
  set_buffer(buffer_, offset, count);
}

auto socket_async_event_args::set_buffer(const array<xtd::byte>& buffer, size offset, size count) -> void {
  if (offset + count > buffer_.length()) throw_helper::throws(exception_case::argument_out_of_range);
  buffer_ = buffer;
  offset_ = offset;
  count_ = count;
}

auto socket_async_event_args::on_complete(const socket_async_event_args& e) -> void {
  auto safe_completed = completed;
  if (safe_completed.is_empty()) return;
  safe_completed(e);
}
