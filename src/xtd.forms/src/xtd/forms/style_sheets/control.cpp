#include "../../../../include/xtd/forms/style_sheets/control.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control::control(const style_sheets::margin& margin, const style_sheets::border_style& border_style, const style_sheets::border_color& border_color, const style_sheets::border_width& border_width, const style_sheets::border_radius& border_radius, const style_sheets::padding& padding, const drawing::color& background_color, const style_sheets::background_image& background_image, std::optional<style_sheets::length> width, std::optional<style_sheets::length> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), background_image_(background_image), width_(width), height_(height), color_(color), alignment_(alignment), font_(font) {
}

const drawing::color& control::background_color() const noexcept {
  return background_color_;
}

void control::background_color(const drawing::color& value) noexcept {
  background_color_ = value;
}

const style_sheets::background_image& control::background_image() const noexcept {
  return background_image_;
}

void control::background_image(const style_sheets::background_image& value) noexcept {
  background_image_ = value;
}

const xtd::forms::style_sheets::border_color& control::border_color() const noexcept {
  return border_color_;
}

void control::border_color(const xtd::forms::style_sheets::border_color& value) noexcept {
  border_color_ = value;
}

xtd::forms::style_sheets::border_radius control::border_radius() const noexcept {
  return border_radius_;
}

void control::border_radius(xtd::forms::style_sheets::border_radius value) noexcept {
  border_radius_ = value;
}

xtd::forms::style_sheets::border_style control::border_style() const noexcept {
  return border_style_;
}

void control::border_style(xtd::forms::style_sheets::border_style value) noexcept {
  border_style_ = value;
}

xtd::forms::style_sheets::border_width control::border_width() const noexcept {
  return border_width_;
}

void control::border_width(xtd::forms::style_sheets::border_width value) noexcept {
  border_width_ = value;
}

optional<length> control::height() const noexcept {
  return height_;
}

void control::height(const std::optional<length>& value) noexcept {
  height_ = value;
}

const style_sheets::margin& control::margin() const noexcept {
  return margin_;
}

void control::margin(const style_sheets::margin& value) noexcept {
  margin_ = value;
}

const style_sheets::padding& control::padding() const noexcept {
  return padding_;
}

void control::padding(const style_sheets::padding& value) noexcept {
  padding_ = value;
}

optional<length> control::width() const noexcept {
  return width_;
}

void control::width(optional<length> value) noexcept {
  width_ = value;
}

content_alignment control::alignment() const noexcept {
  return alignment_;
}

void control::alignment(content_alignment value) noexcept {
  alignment_ = value;
}

const drawing::color& control::color() const noexcept {
  return color_;
}

void control::color(const drawing::color& value) noexcept {
  color_ = value;
}

text_decoration control::decoration() const noexcept {
  return decoration_;
}

void control::decoration(text_decoration value) noexcept {
  decoration_ = value;
}

text_transformation control::transformation() const noexcept {
  return transformation_;
}

void control::transformation(text_transformation value) noexcept {
  transformation_ = value;
}

const font& control::font() const noexcept {
  return font_;
}

void control::font(const drawing::font& value) noexcept {
  font_ = value;
}

bool control::equals(const object& other) const noexcept {
  return is<control>(other) ? equals(static_cast<const control&>(other)) : false;
}

bool control::equals(const control& other) const noexcept {
  return margin_ == other.margin_ && border_style_ == other.border_style_ && border_color_ == other.border_color_ && border_width_ == other.border_width_ && border_radius_ == other.border_radius_ && padding_ == other.padding_ && background_color_ == other.background_color_ && background_image_ == other.background_image_ && width_ == other.width_ && height_ == other.height_ && color_ == other.color_ && alignment_ == other.alignment_ && font_ == other.font_ && decoration_ == other.decoration_ && transformation_ == other.transformation_;
}

rectangle control::get_border_rectangle(const rectangle& bounds) const noexcept {
  auto bounds_rect = bounds;
  if (width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), margin().left().get_pixels(bounds) + border_width().left().get_pixels(bounds) + padding().left().get_pixels(bounds) + width().value().get_pixels(bounds) + padding().right().get_pixels(bounds) + border_width().right().get_pixels(bounds) + margin().right().get_pixels(bounds), bounds_rect.height());
  if (height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), margin().top().get_pixels(bounds) + border_width().top().get_pixels(bounds) + padding().top().get_pixels(bounds) + height().value().get_pixels(bounds) + padding().bottom().get_pixels(bounds) + border_width().bottom().get_pixels(bounds) + margin().bottom().get_pixels(bounds));
  
  auto border_rect = rectangle::offset(bounds_rect, margin().left().get_pixels(bounds), margin().top().get_pixels(bounds));
  border_rect = rectangle::inflate(border_rect, -margin().right().get_pixels(bounds) - margin().left().get_pixels(bounds), -margin().bottom().get_pixels(bounds) - margin().top().get_pixels(bounds));
  return border_rect;
}

rectangle control::get_fill_rectangle(const rectangle& bounds) const noexcept {
  auto fill_rect = rectangle::offset(get_border_rectangle(bounds), border_width().left().get_pixels(bounds), border_width().top().get_pixels(bounds));
  fill_rect = rectangle::inflate(fill_rect, -border_width().left().get_pixels(bounds) - border_width().right().get_pixels(bounds), -border_width().top().get_pixels(bounds) - border_width().bottom().get_pixels(bounds));
  return fill_rect;
}

rectangle control::get_content_rectangle(const rectangle& bounds) const noexcept {
  auto content_rect = rectangle::offset(get_fill_rectangle(bounds), padding().left().get_pixels(bounds), padding().top().get_pixels(bounds));
  content_rect = rectangle::inflate(content_rect, -padding().left().get_pixels(bounds) - padding().right().get_pixels(bounds), -padding().top().get_pixels(bounds) - padding().bottom().get_pixels(bounds));
  return content_rect;
}

string_format control::control::make_string_format() const noexcept {
  string_format format;
  format.line_alignment(xtd::drawing::string_alignment::center);
  format.alignment(xtd::drawing::string_alignment::center);
  
  if (alignment() == content_alignment::top_left) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (alignment() == content_alignment::top_center) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (alignment() == content_alignment::top_right) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (alignment() == content_alignment::middle_left) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (alignment() == content_alignment::middle_center) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (alignment() == content_alignment::middle_right) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (alignment() == content_alignment::bottom_left) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (alignment() == content_alignment::bottom_center) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (alignment() == content_alignment::bottom_right) {
    format.alignment(xtd::drawing::string_alignment::far);
    format.line_alignment(xtd::drawing::string_alignment::far);
  }
  
  return format;
}
