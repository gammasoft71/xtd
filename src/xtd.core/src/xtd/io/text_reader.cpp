#include "../../../include/xtd/io/text_reader.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include <mutex>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

std::recursive_mutex __synchronized_text_reader_mutex__;

auto text_reader::null() noexcept -> null_text_reader& {
  static auto null_text_reader = io::null_text_reader {};
  return null_text_reader;
}

auto text_reader::close() -> void {
}

auto text_reader::peek() const -> int32 {
  return EOF;
}

auto text_reader::read() -> int32 {
  return EOF;
}

auto text_reader::read(span<char>& buffer) -> size {
  for (auto i = 0_z; i < buffer.length(); i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[i] = static_cast<char>(current);
  }
  return buffer.length();
}

auto text_reader::read(array<char>& buffer, size index, size count) -> size {
  if (index + count > buffer.length()) throw_helper::throws(exception_case::argument);
  for (auto i = 0_z; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<char>(current);
  }
  return count;
}

auto text_reader::read_block(span<char>& buffer) -> size {
  return read(buffer);
}

auto text_reader::read_block(array<char>& buffer, size index, size count) -> size {
  return read(buffer, index, count);
}

auto text_reader::read_line() -> string {
  auto line = string::empty_string;
  for (auto current = read(); current != EOF && current != '\n'; current = read()) {
    if (current == '\r') continue;
    line += static_cast<char>(current);
  }
  return line;
}

auto text_reader::read_to_end() -> string {
  auto text = string::empty_string;
  for (int32 current = read(); current != EOF; current = read()) {
    if (current == '\r') continue;
    text += static_cast<char>(current);
  }
  return text;
}

auto text_reader::synchronised(text_reader& reader) noexcept -> synchronized_text_reader {
  return synchronized_text_reader(reader);
}

auto null_text_reader::read() -> int32 {
  return EOF;
}

auto synchronized_text_reader::read() -> int32 {
  auto lock = std::lock_guard<std::recursive_mutex> {__synchronized_text_reader_mutex__};
  return reader_.read();
}

synchronized_text_reader::synchronized_text_reader(xtd::io::text_reader& reader) : reader_(reader) {
}
