#include "../../../include/xtd/io/text_writer.h"

using namespace xtd::io;

null_text_writer& text_writer::null() {
  static null_text_writer null_text_writer;
  return null_text_writer;
}

synchronized_text_writer text_writer::synchronised(text_writer& writer) {
  return synchronized_text_writer(writer);
}
