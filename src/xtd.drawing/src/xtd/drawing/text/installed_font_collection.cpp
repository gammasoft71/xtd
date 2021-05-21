#include "../../../../include/xtd/drawing/text/installed_font_collection.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::text;

installed_font_collection::installed_font_collection() {  
  for(const std::string& family : native::font_family::installed_font_families())
    families_.push_back(font_family(family));
}
