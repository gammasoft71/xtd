#include <exception>
#include "../../../../include/xtd/drawing/text/private_font_collection.h"
#include <xtd/drawing/native/font_family.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::text;

private_font_collection::private_font_collection() {
}

void private_font_collection::add_font_file(const std::string& filename) {
  throw std::runtime_error("not implemented");
}

void private_font_collection::add_memory_font(intptr_t memory, size_t length) {
  throw std::runtime_error("not implemented");
}
