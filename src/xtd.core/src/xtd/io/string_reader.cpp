#include "../../../include/xtd/io/string_reader.h"

using namespace std;
using namespace xtd::io;

string_reader::string_reader(const ustring& input) : stream_(input) {
}

int32_t string_reader::peek() const {
  return stream_.peek();
}

int32_t string_reader::read() {
  return stream_.get();
}
