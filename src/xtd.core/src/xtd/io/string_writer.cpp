#include "../../../include/xtd/io/string_writer.hpp"

using namespace xtd;
using namespace xtd::io;

string_writer::string_writer(const string& str) {
  write(str);
}

const std::ostream& string_writer::base_stream() const noexcept {
  return stream_;
}

std::ostream& string_writer::base_stream() noexcept {
  return stream_;
}

void string_writer::flush() {
  stream_.flush();
}

string string_writer::to_string() const noexcept {
  return stream_.str();
}

void string_writer::write(const string& value) {
  stream_.write(value.chars().c_str(), value.length());
}
