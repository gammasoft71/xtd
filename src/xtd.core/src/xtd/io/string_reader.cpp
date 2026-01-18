#include "../../../include/xtd/io/string_reader.hpp"

using namespace xtd;
using namespace xtd::io;

string_reader::string_reader(const string& input) : stream_(input) {
}

auto string_reader::peek() const -> int32 {
  return stream_.peek();
}

auto string_reader::read() -> int32 {
  return stream_.get();
}
