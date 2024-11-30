#include "../../../include/xtd/io/string_reader.hpp"

using namespace xtd::io;

string_reader::string_reader(const string& input) : stream_(input) {
}

xtd::int32 string_reader::peek() const {
  return stream_.peek();
}

xtd::int32 string_reader::read() {
  return stream_.get();
}
