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

int32 stream::read_byte() {
  if (is_closed()) throw object_closed_exception {};
  if (!can_read()) throw not_supported_exception {};
  
  static array<byte> b(1_z);
  if (read(b) == 1_z)
    return as<int32>(b[0]);
  return stream::eof;
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
