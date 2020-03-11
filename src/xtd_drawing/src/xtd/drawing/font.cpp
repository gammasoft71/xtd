#include <cmath>
#include <limits>
#include "../../../include/xtd/drawing/font.hpp"
#include "../../../include/xtd/drawing/graphics.hpp"
#include <xtd/drawing/native/font.h>

using namespace xtd;
using namespace xtd::drawing;

font::font(const font& prototype, float em_size) {
  *this->data_ = *prototype.data_;
  this->data_->size_ = em_size;
  this->data_->handle_ = native::font::create(this->data_->original_font_name_, this->size_in_points(), (this->data_->style_ & font_style::bold) == font_style::bold, (this->data_->style_ & font_style::italic) == font_style::italic, (this->data_->style_ & font_style::underline) == font_style::underline, (this->data_->style_ & font_style::strikeout) == font_style::strikeout, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
}

font::font(const font& prototype, float em_size, font_style style) {
  *this->data_ = *prototype.data_;
  this->data_->size_ = em_size;
  this->data_->style_ = style;
  this->data_->handle_ = native::font::create(this->data_->original_font_name_, this->size_in_points(), (this->data_->style_ & font_style::bold) == font_style::bold, (this->data_->style_ & font_style::italic) == font_style::italic, (this->data_->style_ & font_style::underline) == font_style::underline, (this->data_->style_ & font_style::strikeout) == font_style::strikeout, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
}

font::font(const font& prototype, font_style style) {
  *this->data_ = *prototype.data_;
  this->data_->style_ = style;
  this->data_->handle_ = native::font::create(this->data_->original_font_name_, this->size_in_points(), (this->data_->style_ & font_style::bold) == font_style::bold, (this->data_->style_ & font_style::italic) == font_style::italic, (this->data_->style_ & font_style::underline) == font_style::underline, (this->data_->style_ & font_style::strikeout) == font_style::strikeout, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
}

font::font(std::string family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font) {
  if (em_size <= 0 || em_size == std::numeric_limits<float>::infinity() || std::isnan(em_size)) throw std::invalid_argument("em_size is less than or equal to 0, evaluates to infinity, or is not a valid number.");
  if (unit == graphics_unit::display) throw std::invalid_argument("unit can't be equal to graphics_unit::display.");
  try {
    this->data_->font_family_ = drawing::font_family(family_name);
  } catch (...) {
    this->data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  this->data_->original_font_name_ = this->data_->font_family_.name();
  this->data_->size_ = em_size;
  this->data_->style_ = style;
  this->data_->unit_ = unit;
  this->data_->gdi_char_set_ = gdi_char_set;
  this->data_->gdi_vertical_font_ = gdi_vertical_font;
  this->data_->handle_ = native::font::create(this->data_->original_font_name_, this->size_in_points(), (this->data_->style_ & font_style::bold) == font_style::bold, (this->data_->style_ & font_style::italic) == font_style::italic, (this->data_->style_ & font_style::underline) == font_style::underline, (this->data_->style_ & font_style::strikeout) == font_style::strikeout, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
}

font::font(intptr_t handle) {
  this->data_->handle_ = handle;
  std::string family_name;
  bool bold = false, italic = false, underline = false, strikeout = false;
  native::font::get_information(this->data_->handle_, family_name, this->data_->size_, bold, italic, underline, strikeout, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
  try {
    this->data_->font_family_ = drawing::font_family(family_name);
  }
  catch (...) {
    this->data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  if (bold) this->data_->style_ |= font_style::bold;
  if (italic) this->data_->style_ |= font_style::italic;
  if (underline) this->data_->style_ |= font_style::underline;
  if (strikeout) this->data_->style_ |= font_style::strikeout;
  this->data_->original_font_name_ = family_name;
  this->data_->system_font_name_ = family_name;
  this->data_->is_system_font_ = true;
  this->data_->unit_ = graphics_unit::point;
}

font::font(const font& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::font::destroy(this->data_->handle_);
  this->data_ = value.data_;
}

font& font::operator=(const font& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::font::destroy(this->data_->handle_);
  this->data_ = value.data_;
  return *this;
}

font::~font() {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::font::destroy(this->data_->handle_);
}

float font::size_in_points() const {
  switch (this->data_->unit_) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return this->data_->size_ / 96.0f * native::font::dpi();
    case graphics_unit::point: return this->data_->size_;
    case graphics_unit::inch: return this->data_->size_ * native::font::dpi();
    case graphics_unit::document: return this->data_->size_ / 300.0f * native::font::dpi();
    case graphics_unit::millimeter: return this->data_->size_ / 25.4f * native::font::dpi();
    default: return this->data_->size_;
  }
}

int32_t font::height() const {
  return static_cast<int32_t>(std::ceil(this->get_height()));
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
  return native::font::height(this->data_->handle_);
}

float font::get_height(const graphics& graphics) const {
  return native::font::height(this->data_->handle_, graphics.data_->handle_);
}

float font::get_height(float dpi) const {
  //return native::font::height(this->data_->handle_,dpi);
  if (this->data_->unit_ == graphics_unit::pixel) return this->get_height();
  return this->get_height() / native::font::dpi() * dpi;
}

intptr_t font::to_hfont() const {
  return native::font::create_from_hfont(this->data_->handle_);
}

