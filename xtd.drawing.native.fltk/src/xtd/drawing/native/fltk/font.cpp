#include <map>
#include <xtd/drawing/native/font.hpp>
#include <xtd/xtd.strings>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

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

  struct fl_font_tuple {
    Fl_Font font_ = 0;
    Fl_Fontsize size_ = 0;
  };
}

intptr_t font::create(const std::string& name, float em_size, bool bold, bool italic, bool underline, bool strikeout, uint8_t gdi_char_set, bool gdi_vertical_font) {
  return reinterpret_cast<intptr_t>(new fl_font_tuple {fonts()[name], points_to_native_font_graphics_untit(em_size)});
}

intptr_t font::create_from_hdc(intptr_t hdc) {
  return reinterpret_cast<intptr_t>(new fl_font_tuple {fl_font(), fl_size()});
}

intptr_t font::create_from_hfont(intptr_t hfont) {
  return reinterpret_cast<intptr_t>(new fl_font_tuple {*reinterpret_cast<fl_font_tuple*>(hfont)});
}

void font::destroy(intptr_t font) {
  delete reinterpret_cast<fl_font_tuple*>(font);
}

int32_t font::dpi() {
  float h = 0, v = 0;
  Fl::screen_dpi(h, v);
  return static_cast<int32_t>(v);
}

void font::get_information(intptr_t font, std::string& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, uint8_t& gdi_char_set, bool& gdi_vertical_font) {
  fl_font_tuple* fl_font = reinterpret_cast<fl_font_tuple*>(font);
  std::string font_name = Fl::get_font_name(fl_font->font_);
  name = xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(font_name, " Italic", ""), " italic", ""), " Bold", ""), " bold", "");
  em_size = native_font_graphics_untit_to_points(static_cast<float>(fl_font->size_));
  bold = xtd::strings::index_of(font_name, " Bold") != -1 || xtd::strings::index_of(font_name, " bold") != -1;
  italic = xtd::strings::index_of(font_name, " Italic") != -1 || xtd::strings::index_of(font_name, " italic") != -1;
  underline = false;
  strikeout = false;
  gdi_char_set = 0;
  gdi_vertical_font = false;
}

float font::height(intptr_t font) {
  fl_font_tuple* fl_font = reinterpret_cast<fl_font_tuple*>(font);
  return fl_height(fl_font->font_, fl_font->size_);
}

float font::height(intptr_t font, intptr_t hdc) {
  fl_font_tuple* fl_font = reinterpret_cast<fl_font_tuple*>(font);
  return fl_height(fl_font->font_, fl_font->size_);
}
