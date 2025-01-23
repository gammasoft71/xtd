#include "../../../include/xtd/io/end_of_stream_exception.hpp"
#include "../../../include/xtd/io/stream.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/math.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/not_supported_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"

using namespace xtd;
using namespace xtd::io;

stream::streambuf::streambuf(stream& owner) : owner_{owner} {
}

stream::streambuf::int_type stream::streambuf::underflow() {
  auto int_read = owner_.read_byte();
  if(int_read == stream::eof) return stream::eof;
  value_ = as<byte>(int_read);
  setg(value_ptr_, value_ptr_, value_ptr_ + 1);
  return int_read;
}

stream::streambuf::int_type stream::streambuf::overflow(int_type value) {
  value_ = as<byte>(value);
  owner_.write_byte(value_);
  setp(value_ptr_, value_ptr_);
  return 1;
}

bool stream::can_timeout() const noexcept {
  return false;
}

bool stream::is_closed() const noexcept {
  return closed_;
}

int32 stream::read_timeout() const {
  throw invalid_operation_exception {};
}

void stream::read_timeout(int32 value) {
  throw invalid_operation_exception {};
}

int32 stream::write_timeout() const {
  throw invalid_operation_exception {};
}

void stream::write_timeout(int32 value) {
  throw invalid_operation_exception {};
}

void stream::copy_to(std::ostream& destination) {
  copy_to(destination, length());
}

void stream::copy_to(std::ostream& destination, xtd::size buffer_size) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};
  if (buffer_size == 0_z) throw argument_out_of_range_exception {};

  auto copy_count = math::min(buffer_size, length() - position());
  if (copy_count == 0) return;
  for (auto index = 0_z; index < copy_count; ++index) {
    auto b = read_byte();
    destination.write(reinterpret_cast<const char_type*>(&b), 1);
  }
}

xtd::size stream::read(xtd::array<xtd::byte>& buffer) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};
  
  return read(buffer, 0_z, buffer.length());
}

xtd::size stream::read_at_least(xtd::array<xtd::byte>& buffer, xtd::size minimum_bytes, bool throw_on_end_of_stream) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};
  
  if (minimum_bytes == 0_z) return 0_z;
  if (buffer.length() < minimum_bytes) throw argument_out_of_range_exception {};
  
  auto read_count = read(buffer, 0_z, minimum_bytes);
  if (throw_on_end_of_stream && read_count < minimum_bytes) throw end_of_stream_exception {};
  return read_count;
}

int32 stream::read_byte() {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};
  
  static array<byte> b(1_z);
  if (read(b) == 1_z)
    return as<int32>(b[0]);
  return stream::eof;
}

void stream::read_exactly(xtd::array<xtd::byte>& buffer) {
  read_exactly(buffer, 0_z, buffer.length());
}

void stream::read_exactly(xtd::array<xtd::byte>& buffer, xtd::size offset, xtd::size count) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};

  if (count == 0_z) return;
  if (offset >= buffer.size() || offset + count > buffer.size()) throw argument_out_of_range_exception {};

  auto total_read_count = 0_z;
  
  while (total_read_count < count) {
    auto read_count = read(buffer, offset + total_read_count, count - total_read_count);
    if (read_count == 0_z) throw end_of_stream_exception {};
    total_read_count += read_count;
  }
}

void stream::write(const xtd::array<xtd::byte>& buffer) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_write()) throw not_supported_exception {};
  
  write(buffer, 0_z, buffer.length());
}

void stream::write_byte(xtd::byte value) {
  if (is_closed()) throw object_closed_exception {};
  if (!can_write()) throw not_supported_exception {};
  
  array<byte> b = {value};
  write(b);
}

stream::stream() : std::iostream {&streambuf_} {
}
