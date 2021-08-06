#include <exception>
#include "../../../../include/xtd/drawing/text/private_font_collection.h"
#include <xtd/not_implemented_exception.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::text;

private_font_collection::private_font_collection() {
}

void private_font_collection::add_font_file(const xtd::ustring& filename) {
  throw xtd::not_implemented_exception(current_stack_frame_);
}

void private_font_collection::add_memory_font(intptr_t memory, size_t length) {
  throw xtd::not_implemented_exception(current_stack_frame_);
}
