#include "../../../include/xtd/io/text_reader.h"

using namespace xtd::io;

null_text_reader& text_reader::null() {
  static null_text_reader null_text_reader;
  return null_text_reader;
}


synchronized_text_reader text_reader::synchronised(text_reader& reader) {
  return synchronized_text_reader(reader);
}
