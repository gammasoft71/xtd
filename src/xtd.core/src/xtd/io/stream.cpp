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
  if(int_read == EOF) return EOF;
  value_ = as<char_type>(int_read);
  setg(&value_, &value_, &value_ + 1);
  return int_read;
}

stream::streambuf::int_type stream::streambuf::overflow(int_type value) {
  value_ = as<char>(value);
  owner_.write_byte(as<byte>(value_));
  setp(&value_, &value_);
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

xtd::size stream::read(xtd::array<xtd::byte>& buffer) {
  return read(buffer, 0_z, buffer.length());
}

int32 stream::read_byte() {
  if (is_closed()) throw object_closed_exception {};
  static array<byte> b(1_z);
  if (read(b) == 1_z)
    return as<int32>(b[0]);
  return EOF;
}

void stream::write(const xtd::array<xtd::byte>& buffer) {
  write(buffer, 0_z, buffer.length());
}

void stream::write_byte(xtd::byte value) {
  if (is_closed()) throw object_closed_exception {};
  array<byte> b = {value};
  write(b);
}

stream::stream() : std::iostream {&streambuf_} {
}
