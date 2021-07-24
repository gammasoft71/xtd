#include "../../../include/xtd/io/string_writer.h"

using namespace std;
using namespace xtd::io;

string_writer::string_writer(const string& str) {
  write(str);
}

const ostream& string_writer::base_stream() const {
  return stream_;
}

ostream& string_writer::base_stream() {
  return stream_;
}

void string_writer::flush() {
  stream_.flush();
}

string string_writer::to_string() const noexcept {
  return stream_.str();
}

void string_writer::write(const string& value) {
  stream_.write(value.c_str(), value.length());
}
