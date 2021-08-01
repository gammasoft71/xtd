#include "../../../include/xtd/io/string_writer.h"

using namespace std;
using namespace xtd::io;

string_writer::string_writer(const ustring& str) {
  write(str);
}

const ostream& string_writer::base_stream() const noexcept {
  return stream_;
}

ostream& string_writer::base_stream() noexcept {
  return stream_;
}

void string_writer::flush() {
  stream_.flush();
}

string string_writer::to_string() const noexcept {
  return stream_.str();
}

void string_writer::write(const ustring& value) {
  stream_.write(value.c_str(), value.length());
}
