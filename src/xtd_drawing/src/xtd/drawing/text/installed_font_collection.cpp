#include "../../../../include/xtd/drawing/text/installed_font_collection.hpp"
#include <xtd/drawing/native/font_family.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::text;

installed_font_collection::installed_font_collection() {  
  for(const std::string& family : native::font_family::installed_font_families())
    this->families_.push_back(font_family(family));
}
