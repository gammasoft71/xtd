#include "../../../../include/xtd/forms/style_sheets/control.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

const drawing::color& control::background_color() const noexcept {
  return background_color_;
}

control& control::background_color(const drawing::color& value) noexcept {
  background_color_ = value;
  return *this;
}

const style_sheets::background_image& control::background_image() const noexcept {
  return background_image_;
}

control& control::background_image(const style_sheets::background_image& value) noexcept {
  background_image_ = value;
  return *this;
}

const xtd::forms::style_sheets::border_color& control::border_color() const noexcept {
  return border_color_;
}

control& control::border_color(const xtd::forms::style_sheets::border_color& value) noexcept {
  border_color_ = value;
  return *this;
}

xtd::forms::style_sheets::border_radius control::border_radius() const noexcept {
  return border_radius_;
}

control& control::border_radius(xtd::forms::style_sheets::border_radius value) noexcept {
  border_radius_ = value;
  return *this;
}

xtd::forms::style_sheets::border_style control::border_style() const noexcept {
  return border_style_;
}

control& control::border_style(xtd::forms::style_sheets::border_style value) noexcept {
  border_style_ = value;
  return *this;
}

xtd::forms::style_sheets::border_width control::border_width() const noexcept {
  return border_width_;
}

control& control::border_width(xtd::forms::style_sheets::border_width value) noexcept {
  border_width_ = value;
  return *this;
}

optional<length> control::height() const noexcept {
  return height_;
}

control& control::height(const std::optional<length>& value) noexcept {
  height_ = value;
  return *this;
}

xtd::forms::content_alignment control::image_alignment() const noexcept {
  return image_alignment_;
}

control& control::image_alignment(xtd::forms::content_alignment value) noexcept {
  image_alignment_ = value;
  return *this;
}

const style_sheets::margin& control::margin() const noexcept {
  return margin_;
}

control& control::margin(const style_sheets::margin& value) noexcept {
  margin_ = value;
  return *this;
}

const style_sheets::padding& control::padding() const noexcept {
  return padding_;
}

control& control::padding(const style_sheets::padding& value) noexcept {
  padding_ = value;
  return *this;
}

optional<length> control::width() const noexcept {
  return width_;
}

control& control::width(optional<length> value) noexcept {
  width_ = value;
  return *this;
}

content_alignment control::text_alignment() const noexcept {
  return text_alignment_;
}

control& control::text_alignment(content_alignment value) noexcept {
  text_alignment_ = value;
  return *this;
}

const drawing::color& control::color() const noexcept {
  return color_;
}

control& control::color(const drawing::color& value) noexcept {
  color_ = value;
  return *this;
}

text_decoration control::decoration() const noexcept {
  return decoration_;
}

control& control::decoration(text_decoration value) noexcept {
  decoration_ = value;
  return *this;
}

text_transformation control::transformation() const noexcept {
  return transformation_;
}

control& control::transformation(text_transformation value) noexcept {
  transformation_ = value;
  return *this;
}

const font& control::font() const noexcept {
  return font_;
}

control& control::font(const drawing::font& value) noexcept {
  font_ = value;
  return *this;
}

bool control::equals(const object& other) const noexcept {
  return is<control>(other) ? equals(static_cast<const control&>(other)) : false;
}

bool control::equals(const control& other) const noexcept {
  return margin_ == other.margin_ && border_style_ == other.border_style_ && border_color_ == other.border_color_ && border_width_ == other.border_width_ && border_radius_ == other.border_radius_ && padding_ == other.padding_ && background_color_ == other.background_color_ && background_image_ == other.background_image_ && width_ == other.width_ && height_ == other.height_ && color_ == other.color_ && text_alignment_ == other.text_alignment_ && font_ == other.font_ && decoration_ == other.decoration_ && transformation_ == other.transformation_;
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
  
  if (text_alignment() == content_alignment::top_left) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (text_alignment() == content_alignment::top_center) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (text_alignment() == content_alignment::top_right) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (text_alignment() == content_alignment::middle_left) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (text_alignment() == content_alignment::middle_center) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (text_alignment() == content_alignment::middle_right) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (text_alignment() == content_alignment::bottom_left) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (text_alignment() == content_alignment::bottom_center) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (text_alignment() == content_alignment::bottom_right) {
    format.alignment(xtd::drawing::string_alignment::far);
    format.line_alignment(xtd::drawing::string_alignment::far);
  }
  
  return format;
}
