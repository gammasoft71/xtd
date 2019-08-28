#include <cmath>
#include <limits>
#include "../../../include/xtd/drawing/font.hpp"
#include "../../../include/xtd/drawing/graphics.hpp"
#include <xtd/drawing/native/font.hpp>

using namespace xtd;
using namespace xtd::drawing;

font::font (const font& prototype, font_style style) {
  *this->data_ = *prototype.data_;
  this->data_->style_ = style;
  this->data_->handle_ = native::font::create(this->data_->original_font_name_, this->size_in_points(), (this->data_->style_ & font_style::bold) == font_style::bold, (this->data_->style_ & font_style::italic) == font_style::italic, (this->data_->style_ & font_style::underline) == font_style::underline, (this->data_->style_ & font_style::strikeout) == font_style::strikeout, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
}

font::font(std::string family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font) {
  if (em_size <= 0 || em_size == std::numeric_limits<float>::infinity() || std::isnan(em_size)) throw std::invalid_argument("em_size is less than or equal to 0, evaluates to infinity, or is not a valid number.");
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
  this->data_->height_ = static_cast<int32_t>(std::ceil(this->get_height()));
}

font::~font() {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::font::destroy(this->data_->handle_);
}

float font::size_in_points() const {
  switch (this->data_->unit_) {
    case graphics_unit::world: return this->data_->size_ * 0.75f;
    case graphics_unit::display: return this->data_->size_ / 75.0f * native::font::dpi();
    case graphics_unit::pixel: return this->data_->size_ * 0.75f;
    case graphics_unit::point: return this->data_->size_;
    case graphics_unit::inch: return this->data_->size_ * native::font::dpi();
    case graphics_unit::document: return this->data_->size_ / 300.0f * native::font::dpi();
    case graphics_unit::millimeter: return this->data_->size_ / 25.4f * native::font::dpi();
    default: return this->data_->size_;
  }
}

float font::get_height() const {
  return native::font::height(this->data_->handle_);
}

float font::get_height(const graphics& graphics) const {
  return native::font::height(this->data_->handle_, graphics.data_->handle_);
}

float font::get_height(float dpi) const {
  return native::font::height(this->data_->handle_,dpi);
}

intptr_t font::to_hfont() const {
  return native::font::create_from_hfont(this->data_->handle_);
}

