#include <exception>
#include "../../../../include/xtd/drawing/text/private_font_collection.hpp"
#include <xtd/not_implemented_exception>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing::text;
using namespace xtd::helpers;

private_font_collection::private_font_collection() {
}

void private_font_collection::add_font_file(const string& filename) {
  throw_helper::throws(exception_case::not_implemented);
}

void private_font_collection::add_memory_font(intptr memory, size length) {
  throw_helper::throws(exception_case::not_implemented);
}
