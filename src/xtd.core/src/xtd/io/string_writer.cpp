#include "../../../include/xtd/io/string_writer.hpp"

using namespace xtd;
using namespace xtd::io;

string_writer::string_writer(const string& str) {
  write(str);
}

auto string_writer::base_stream() const noexcept -> const std::ostream& {
  return stream_;
}

auto string_writer::base_stream() noexcept -> std::ostream& {
  return stream_;
}

auto string_writer::flush() -> void {
  stream_.flush();
}

auto string_writer::to_string() const noexcept -> string {
  return stream_.str();
}

auto string_writer::write(const string& value) -> void {
  stream_.write(value.chars().c_str(), value.length());
}
