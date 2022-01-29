#include "../../../../include/xtd/forms/style_sheets/box_data.h"
#include <xtd/as.h>
#include <xtd/is.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const forms::padding& padding, const color& background_color) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const forms::padding& padding, const style_sheets::background_image& background_image) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_image_(background_image) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const forms::padding& padding, const color& background_color, const style_sheets::background_image& background_image) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), background_image_(background_image) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const forms::padding& padding, const color& background_color, optional<int32_t> width, optional<int32_t> height) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), width_(width), height_(height) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const forms::padding& padding, const style_sheets::background_image& background_image, optional<int32_t> width, optional<int32_t> height) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_image_(background_image), width_(width), height_(height) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const forms::padding& padding, const color& background_color, const style_sheets::background_image& background_image, optional<int32_t> width, optional<int32_t> height) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), background_image_(background_image), width_(width), height_(height) {
}

const color& box_data::background_color() const noexcept {
  return background_color_;
}

void box_data::background_color(const color& value) noexcept {
  background_color_ = value;
}

const style_sheets::background_image& box_data::background_image() const noexcept {
  return background_image_;
}

void box_data::background_image(const style_sheets::background_image& value) noexcept {
  background_image_ = value;
}

const xtd::forms::style_sheets::border_color& box_data::border_color() const noexcept {
  return border_color_;
}

void box_data::border_color(const xtd::forms::style_sheets::border_color& value) noexcept {
  border_color_ = value;
}

xtd::forms::style_sheets::border_radius box_data::border_radius() const noexcept {
  return border_radius_;
}

void box_data::border_radius(xtd::forms::style_sheets::border_radius value) noexcept {
  border_radius_ = value;
}

xtd::forms::style_sheets::border_style box_data::border_style() const noexcept {
  return border_style_;
}

void box_data::border_style(xtd::forms::style_sheets::border_style value) noexcept {
  border_style_ = value;
}

xtd::forms::style_sheets::border_width box_data::border_width() const noexcept {
  return border_width_;
}

void box_data::border_width(xtd::forms::style_sheets::border_width value) noexcept {
  border_width_ = value;
}

optional<int32_t> box_data::height() const noexcept {
  return height_;
}

const xtd::forms::padding& box_data::margin() const noexcept {
  return margin_;
}

const xtd::forms::padding& box_data::padding() const noexcept {
  return padding_;
}

optional<int32_t> box_data::width() const noexcept {
  return width_;
}

bool box_data::equals(const object& other) const noexcept {
  return is<box_data>(other) ? equals(static_cast<const box_data&>(other)) : false;
}

bool box_data::equals(const box_data& other) const noexcept {
  return margin_ == other.margin_ && border_style_ == other.border_style_ && border_color_ == other.border_color_ && border_width_ == other.border_width_ && border_radius_ == other.border_radius_ && padding_ == other.padding_ && background_color_ == other.background_color_ && background_image_ == other.background_image_ && width_ == other.width_ && height_ == other.height_;
}

rectangle box_data::get_border_rectangle(const rectangle& bounds) const noexcept {
  auto bounds_rect = bounds;
  if (width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), margin().left() + border_width().left() + padding().left() + width().value() + padding().right() + border_width().right() + margin().right(), bounds_rect.height());
  if (height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), margin().top() + border_width().top() + padding().top() + height().value() + padding().bottom() + border_width().bottom() + margin().bottom());
  
  auto border_rect = rectangle::offset(bounds_rect, margin().left(), margin().top());
  border_rect = rectangle::inflate(border_rect, -margin().right() - margin().left(), -margin().bottom() - margin().top());
  return border_rect;
}

rectangle box_data::get_fill_rectangle(const rectangle& bounds) const noexcept {
  auto fill_rect = rectangle::offset(get_border_rectangle(bounds), border_width().left(), border_width().top());
  fill_rect = rectangle::inflate(fill_rect, -border_width().left() - border_width().right(), -border_width().top() - border_width().bottom());
  return fill_rect;
}

rectangle box_data::get_content_rectangle(const rectangle& bounds) const noexcept {
  auto content_rect = rectangle::offset(get_fill_rectangle(bounds), padding().left(), padding().top());
  content_rect = rectangle::inflate(content_rect, -padding().left() - padding().right(), -padding().top() - padding().bottom());
  return content_rect;
}
