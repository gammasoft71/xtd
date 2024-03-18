#include "../../../include/xtd/io/text_reader.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include <mutex>

using namespace xtd;
using namespace xtd::io;

std::recursive_mutex __synchronized_text_reader_mutex__;

null_text_reader& text_reader::null() noexcept {
  static auto null_text_reader = io::null_text_reader {};
  return null_text_reader;
}

void text_reader::close() {
}

int32 text_reader::peek() const {
  return EOF;
}

int32 text_reader::read() {
  return EOF;
}

size_t text_reader::read(std::vector<char>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw argument_exception {csf_};
  for (auto i = 0_z; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<char>(current);
  }
  return count;
}

size_t text_reader::read_block(std::vector<char>& buffer, size_t index, size_t count) {
  return read(buffer, index, count);
}

ustring text_reader::read_line() {
  auto line = ustring::empty_string;
  for (auto current = read(); current != EOF && current != '\n'; current = read()) {
    if (current == '\r') continue;
    line += static_cast<char>(current);
  }
  return line;
}

ustring text_reader::read_to_end() {
  auto text = ustring::empty_string;
  for (int32 current = read(); current != EOF; current = read()) {
    if (current == '\r') continue;
    text += static_cast<char>(current);
  }
  return text;
}

synchronized_text_reader text_reader::synchronised(text_reader& reader) noexcept {
  return synchronized_text_reader(reader);
}

int32 null_text_reader::read() {
  return EOF;
}

int32 synchronized_text_reader::read() {
  auto lock = std::lock_guard<std::recursive_mutex> {__synchronized_text_reader_mutex__};
  return reader_.read();
}

synchronized_text_reader::synchronized_text_reader(xtd::io::text_reader& reader) : reader_(reader) {
}
