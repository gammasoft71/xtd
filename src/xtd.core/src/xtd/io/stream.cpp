#include "../../../include/xtd/io/end_of_stream_exception.hpp"
#include "../../../include/xtd/io/stream.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/math.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/not_supported_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

stream::streambuf::streambuf(stream& owner) : owner_{owner} {
}

stream::streambuf::int_type stream::streambuf::underflow() {
  auto int_read = owner_.read_byte();
  if (int_read == stream::eof) return stream::eof;
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

auto stream::can_timeout() const noexcept -> bool {
  return false;
}

auto stream::is_closed() const noexcept -> bool {
  return closed_;
}

auto stream::read_timeout() const -> int32 {
  throw_helper::throws(exception_case::invalid_operation);
}

auto stream::read_timeout(int32 value) -> void {
  throw_helper::throws(exception_case::invalid_operation);
}

auto stream::write_timeout() const -> int32 {
  throw_helper::throws(exception_case::invalid_operation);
}

auto stream::write_timeout(int32 value) -> void {
  throw_helper::throws(exception_case::invalid_operation);
}

auto stream::copy_to(std::ostream& destination) -> void {
  copy_to(destination, length());
}

auto stream::copy_to(std::ostream& destination, xtd::size buffer_size) -> void {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  if (buffer_size == 0_z) throw_helper::throws(exception_case::argument_out_of_range);
  
  auto copy_count = math::min(buffer_size, length() - position());
  if (copy_count == 0) return;
  for (auto index = 0_z; index < copy_count; ++index) {
    auto b = read_byte();
    destination.write(reinterpret_cast<const char_type*>(&b), 1);
  }
}

auto stream::read(span<byte>& buffer) -> size {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  for (auto index = 0_z; index < buffer.length(); ++index) {
    auto value = read_byte();
    if (value == eof) return index;
    buffer[index] = as<byte>(value);
  }
  
  return buffer.length();
}

auto stream::read_at_least(array<byte>& buffer, size minimum_bytes, bool throw_on_end_of_stream) -> size {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  if (minimum_bytes == 0_z) return 0_z;
  if (buffer.length() < minimum_bytes) throw_helper::throws(exception_case::argument_out_of_range);
  
  auto read_count = read(buffer, 0_z, minimum_bytes);
  if (throw_on_end_of_stream && read_count < minimum_bytes) throw_helper::throws(exception_case::end_of_stream);
  return read_count;
}

auto stream::read_byte() -> int32 {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  static array<byte> b(1_z);
  if (read(b, 0, 1_z) == 1_z)
    return as<int32>(b[0]);
  return stream::eof;
}

auto stream::read_exactly(array<byte>& buffer) -> void {
  read_exactly(buffer, 0_z, buffer.length());
}

auto stream::read_exactly(array<byte>& buffer, size offset, size count) -> void {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  if (count == 0_z) return;
  if (offset >= buffer.length() || offset + count > buffer.length()) throw_helper::throws(exception_case::argument_out_of_range);
  
  auto total_read_count = 0_z;
  
  while (total_read_count < count) {
    auto read_count = read(buffer, offset + total_read_count, count - total_read_count);
    if (read_count == 0_z) throw_helper::throws(exception_case::end_of_stream);
    total_read_count += read_count;
  }
}

auto stream::write(xtd::span<const xtd::byte> buffer) -> void {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_write()) throw_helper::throws(exception_case::not_supported);
  
  for (auto item : buffer)
    write_byte(item);
}

auto stream::write_byte(byte value) -> void {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_write()) throw_helper::throws(exception_case::not_supported);
  
  array<byte> b = {value};
  write(b, 0, 1_z);
}

stream::stream() : std::iostream {&streambuf_} {
}
