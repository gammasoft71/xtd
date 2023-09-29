#include "../../../include/xtd/io/string_reader.h"

using namespace std;
using namespace xtd::io;

string_reader::string_reader(const ustring& input) : stream_(input) {
}

xtd::int32 string_reader::peek() const {
  return stream_.peek();
}

xtd::int32 string_reader::read() {
  return stream_.get();
}
