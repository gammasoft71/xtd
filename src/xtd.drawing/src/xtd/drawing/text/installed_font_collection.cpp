#include "../../../../include/xtd/drawing/text/installed_font_collection.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::text;

installed_font_collection::installed_font_collection() {
  auto iffs = native::font_family::installed_font_families();
  for_each(iffs.begin(), iffs.end(), [&](const xtd::ustring & family) {families_.emplace_back(family);});
}
