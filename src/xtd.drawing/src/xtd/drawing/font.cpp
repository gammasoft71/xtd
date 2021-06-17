#include <cmath>
#include <limits>
#include "../../../include/xtd/drawing/font.h"
#include "../../../include/xtd/drawing/graphics.h"
#include <xtd/argument_exception.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

font::font(const font& prototype, float em_size) {
  *data_ = *prototype.data_;
  data_->size_ = em_size;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(const font& prototype, float em_size, font_style style) {
  *data_ = *prototype.data_;
  data_->size_ = em_size;
  data_->style_ = style;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(const font& prototype, font_style style) {
  *data_ = *prototype.data_;
  data_->style_ = style;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(std::string family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font) {
  if (em_size <= 0 || em_size == std::numeric_limits<float>::infinity() || std::isnan(em_size)) throw xtd::argument_exception("em_size is less than or equal to 0, evaluates to infinity, or is not a valid number."_t, current_stack_frame_);
  if (unit == graphics_unit::display) throw xtd::argument_exception("unit can't be equal to graphics_unit::display."_t, current_stack_frame_);
  try {
    data_->font_family_ = drawing::font_family(family_name);
  } catch (...) {
    data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  data_->original_font_name_ = data_->font_family_.name();
  data_->size_ = em_size;
  data_->style_ = style;
  data_->unit_ = unit;
  data_->gdi_char_set_ = gdi_char_set;
  data_->gdi_vertical_font_ = gdi_vertical_font;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(intptr_t handle) {
  data_->handle_ = handle;
  std::string family_name;
  bool bold = false, italic = false, underline = false, strikeout = false;
  native::font::get_information(data_->handle_, family_name, data_->size_, bold, italic, underline, strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
  try {
    data_->font_family_ = drawing::font_family(family_name);
  }
  catch (...) {
    data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  if (bold) data_->style_ |= font_style::bold;
  if (italic) data_->style_ |= font_style::italic;
  if (underline) data_->style_ |= font_style::underline;
  if (strikeout) data_->style_ |= font_style::strikeout;
  data_->original_font_name_ = family_name;
  data_->system_font_name_ = family_name;
  data_->is_system_font_ = true;
  data_->unit_ = graphics_unit::point;
}

font::font(const font& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font::destroy(data_->handle_);
  data_ = value.data_;
}

font& font::operator=(const font& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

font::~font() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font::destroy(data_->handle_);
}

float font::size_in_points() const {
  switch (data_->unit_) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return data_->size_ / 96.0f * native::font::dpi();
    case graphics_unit::point: return data_->size_;
    case graphics_unit::inch: return data_->size_ * native::font::dpi();
    case graphics_unit::document: return data_->size_ / 300.0f * native::font::dpi();
    case graphics_unit::millimeter: return data_->size_ / 25.4f * native::font::dpi();
    default: return data_->size_;
  }
}

int32_t font::height() const {
  return static_cast<int32_t>(std::ceil(get_height()));
}

font font::from_hdc(const intptr_t hdc) {
  font font;
  font.data_->handle_ = native::font::create_from_hdc(hdc);
  std::string family_name;
  bool bold = false, italic = false, underline = false, strikeout = false;
  native::font::get_information(font.data_->handle_, family_name, font.data_->size_, bold, italic, underline, strikeout, font.data_->gdi_char_set_, font.data_->gdi_vertical_font_);
  try {
    font.data_->font_family_ = drawing::font_family(family_name);
  } catch (...) {
    font.data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  if (bold) font.data_->style_ |= font_style::bold;
  if (italic) font.data_->style_ |= font_style::italic;
  if (underline) font.data_->style_ |= font_style::underline;
  if (strikeout) font.data_->style_ |= font_style::strikeout;
  font.data_->original_font_name_ = family_name;
  font.data_->is_system_font_ = true;
  font.data_->unit_ = graphics_unit::point;
  return font;
}

font font::from_hfont(const intptr_t hfont) {
  return font(native::font::create_from_hfont(hfont));
}

float font::get_height() const {
  return native::font::height(data_->handle_);
}

float font::get_height(const graphics& graphics) const {
  return native::font::height(data_->handle_, graphics.data_->handle_);
}

float font::get_height(float dpi) const {
  //return native::font::height(data_->handle_,dpi);
  if (data_->unit_ == graphics_unit::pixel) return get_height();
  return get_height() / native::font::dpi() * dpi;
}

intptr_t font::to_hfont() const {
  return native::font::create_from_hfont(data_->handle_);
}

