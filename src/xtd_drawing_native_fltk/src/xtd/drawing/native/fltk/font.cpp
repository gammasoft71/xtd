#include <map>
#include <xtd/drawing/native/font.hpp>
#include <xtd/xtd.strings>
#include "../../../../../include/xtd/drawing/native/fl_font.hpp"
#include <FL/Fl.H>

using namespace xtd::drawing::native;

namespace {
#if defined(__WXOSX__)
  Fl_Fontsize points_to_native_font_graphics_untit(float size) {
    return static_cast<Fl_Fontsize>(size / font::dpi() * 96.0f);  // font is in pixels and not in points
  }

  Fl_Fontsize native_font_graphics_untit_to_points(float size) {
    return static_cast<Fl_Fontsize>(size / 96.0f * font::dpi());  // font is in pixels and not in points
  }
#else
  Fl_Fontsize points_to_native_font_graphics_untit(float size) {
    return static_cast<Fl_Fontsize>(size);  // font is in points
  }

  Fl_Fontsize native_font_graphics_untit_to_points(float size) {
    return static_cast<Fl_Fontsize>(size);  // font is in points
  }
#endif

  std::map<std::string, Fl_Font>& fonts() {
    static std::map<std::string, Fl_Font> fonts;
    if (fonts.empty()) {
      Fl_Font count = Fl::set_fonts();
      for(Fl_Font index = 0; index < count; ++index) {
        int attribute = 0;
        std::string name = Fl::get_font_name(index, &attribute);
        fonts[name] = index;
      }
    }
    return fonts;
  }
}

intptr_t font::create(const std::string& name, float em_size, bool bold, bool italic, bool underline, bool strikeout, uint8_t gdi_char_set, bool gdi_vertical_font) {
  return reinterpret_cast<intptr_t>(new xtd::drawing::native::fl_font(fonts()[name], points_to_native_font_graphics_untit(em_size)));
}

intptr_t font::create_from_hdc(intptr_t hdc) {
  return reinterpret_cast<intptr_t>(new xtd::drawing::native::fl_font(::fl_font(), fl_size()));
}

intptr_t font::create_from_hfont(intptr_t hfont) {
  return reinterpret_cast<intptr_t>(new xtd::drawing::native::fl_font(*reinterpret_cast<xtd::drawing::native::fl_font*>(hfont)));
}

void font::destroy(intptr_t font) {
  delete reinterpret_cast<xtd::drawing::native::fl_font*>(font);
}

int32_t font::dpi() {
  float h = 0, v = 0;
  Fl::screen_dpi(h, v);
  return static_cast<int32_t>(v);
}

void font::get_information(intptr_t font, std::string& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, uint8_t& gdi_char_set, bool& gdi_vertical_font) {
  xtd::drawing::native::fl_font* fl_font = reinterpret_cast<xtd::drawing::native::fl_font*>(font);
  std::string font_name = Fl::get_font_name(fl_font->font());
  name = xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(font_name, " Italic", ""), " italic", ""), " Bold", ""), " bold", "");
  em_size = native_font_graphics_untit_to_points(static_cast<float>(fl_font->size()));
  bold = xtd::strings::index_of(font_name, " Bold") != -1 || xtd::strings::index_of(font_name, " bold") != -1;
  italic = xtd::strings::index_of(font_name, " Italic") != -1 || xtd::strings::index_of(font_name, " italic") != -1;
  underline = false;
  strikeout = false;
  gdi_char_set = 0;
  gdi_vertical_font = false;
}

float font::height(intptr_t font) {
  xtd::drawing::native::fl_font* fl_font = reinterpret_cast<xtd::drawing::native::fl_font*>(font);
  return fl_height(fl_font->font(), fl_font->size());
}

float font::height(intptr_t font, intptr_t hdc) {
  xtd::drawing::native::fl_font* fl_font = reinterpret_cast<xtd::drawing::native::fl_font*>(font);
  return fl_height(fl_font->font(), fl_font->size());
}
