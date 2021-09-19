#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <xtd/drawing/native/font.hpp>
#include <xtd/drawing/native/font_family.hpp>
#include <FL/Fl.H>
#include "../../../../../include/xtd/drawing/native/fl_dc.hpp"
#include "../../../../../include/xtd/drawing/native/fl_font.hpp"

using namespace xtd::drawing::native;

namespace {
#if defined(__WXOSX__)
  float pixel_to_native_font_graphics_untit(float size) {
    return size;  // font is in points
  }
#else
  float pixel_to_native_font_graphics_untit(float size) {
    return size / 96.0f * font::dpi();  // font is in pixels and not in points
  }
#endif
  const std::set<std::string>& families() {
    static std::set<std::string> families;
    if (families.size() == 0) {
      Fl_Font count = Fl::set_fonts();
      for(Fl_Font index = 0; index < count; ++index) {
        int attribute = 0;
        std::string name = Fl::get_font_name(index, &attribute);
        if (attribute == 0) families.insert(name);
      }
    }
    return families;
  }
}

intptr_t font_family::create(const std::string& name) {
  if (name == ".AppleSystemUIFont") return reinterpret_cast<intptr_t>(new std::string(name));
  return  families().find(name) != families().end() ? reinterpret_cast<intptr_t>(new std::string(name)) : 0;
}

void font_family::destroy(intptr_t font_family) {
  delete reinterpret_cast<std::string*>(font_family);
}

std::string font_family::generic_serif_name() {
  return Fl::get_font_name(FL_TIMES);
}

std::string font_family::generic_sans_serif_name() {
  return Fl::get_font_name(FL_HELVETICA);
}

std::string font_family::generic_monospace_name() {
  return Fl::get_font_name(FL_COURIER);
}

std::vector<std::string> font_family::installed_font_families() {
  return std::vector<std::string>(families().begin(), families().end());
}

int32_t font_family::get_cell_ascent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
  fl_screen_dc screen_dc;
  fl_font font(font_family, em_height);
  return screen_dc.ascent(font.font(), pixel_to_native_font_graphics_untit(font.size()));
}

int32_t font_family::get_cell_descent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
  fl_screen_dc screen_dc;
  fl_font font(font_family, em_height);
  return screen_dc.descent(font.font(), pixel_to_native_font_graphics_untit(font.size()));
}

int32_t font_family::get_line_spacing(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
  return 0;
}

std::string font_family::get_name(intptr_t font_family, int32_t language) {
  return *reinterpret_cast<std::string*>(font_family);
}

bool font_family::is_style_available(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout) {
  return true;
}
