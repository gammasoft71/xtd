#include "../../../include/xtd/io/memory_stream.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::io;

bool memory_stream::can_read() const noexcept {
  return true;
}

bool memory_stream::can_seek() const noexcept {
  return true;
}

bool memory_stream::can_write() const noexcept {
  return true;
}

xtd::size memory_stream::capacity() const noexcept {
  std::streamsize current_pos = rdbuf()->pubseekoff(0, std::ios::cur, std::ios::out);
  std::streamsize result = rdbuf()->pubseekoff(0, std::ios::end, std::ios::out);
  rdbuf()->pubseekpos(current_pos, std::ios::out);
  return result;
}

memory_stream& memory_stream::capacity(xtd::size value) {
  return *this;
}

xtd::size memory_stream::length() const noexcept {
  auto current_pos = const_cast<memory_stream*>(this)->tellg();
  const_cast<memory_stream*>(this)->seekg(0, std::ios_base::end);
  auto result = const_cast<memory_stream*>(this)->tellg();
  const_cast<memory_stream*>(this)->seekg(current_pos, std::ios_base::beg);
  return result;
}

xtd::size memory_stream::position() const noexcept {
  return const_cast<memory_stream*>(this)->tellg();
}

memory_stream& memory_stream::position(xtd::size value) {
  if (value > length()) seekg(0, std::ios_base::end);
  else seekg(value, std::ios_base::beg);
  return *this;
}

void memory_stream::read(xtd::array<xtd::byte>& bytes) {
  write(bytes, xtd::size {}, bytes.size());
}

void memory_stream::read(xtd::array<xtd::byte>& bytes, size offset, size count) {
  if (offset >= bytes.size() || offset + count > bytes.size()) throw argument_out_of_range_exception {};
  for (auto index = offset; index < count; ++index) {
    auto value = read_byte();
    if (value == -1) return;
    bytes[index] = static_cast<byte>(value);
  }
}

xtd::int32 memory_stream::read_byte() {
  auto value = byte {};
  if (readsome(reinterpret_cast<char*>(&value), 1) != 1) return -1;
  if (position()) position(position() - 1);
  return static_cast<int32>(value);
}

void memory_stream::write(const xtd::array<xtd::byte>& bytes) {
  write(bytes, 0_z, bytes.size());
}

void memory_stream::write(const xtd::array<xtd::byte>& bytes, size offset, size count) {
  if (offset >= bytes.size() || offset + count > bytes.size()) throw argument_out_of_range_exception {};
  for (auto index = offset; index < count; ++index)
    write_byte(bytes[index]);
}

void memory_stream::write_byte(xtd::byte value) {
  write(reinterpret_cast<const char*>(&value), 1);
  position(position() + 1);
}
