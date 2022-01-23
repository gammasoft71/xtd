#include "../../../../include/xtd/forms/style_sheets/box_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

box_data::box_data(const forms::padding& margin, const array<border_data, 4>& borders, const forms::padding& padding, const color_data& background_color) : margin_(margin), borders_(borders), padding_(padding), background_color_(background_color) {
}

box_data::box_data(const forms::padding& margin, const array<border_data, 4>& borders, const forms::padding& padding, const color_data& background_color, optional<int32_t> width, optional<int32_t> height) : margin_(margin), borders_(borders), padding_(padding), background_color_(background_color), width_(width), height_(height) {
}

box_data::box_data(const forms::padding& margin, const border_data& border, const forms::padding& padding, const color_data& background_color) : margin_(margin), borders_({border, border, border, border}), padding_(padding), background_color_(background_color) {
}

box_data::box_data(const forms::padding& margin, const border_data& border, const forms::padding& padding, const color_data& background_color, optional<int32_t> width, optional<int32_t> height) : margin_(margin), borders_({border, border, border, border}), padding_(padding), background_color_(background_color), width_(width), height_(height) {
}

const color_data& box_data::background_color() const noexcept {
  return background_color_;
}

void box_data::background_color(const color_data& color) noexcept {
  background_color_ = color;
}

const array<border_data, 4>& box_data::borders() const noexcept {
  return borders_;
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

rectangle box_data::get_border_rectangle(const rectangle& bounds) const noexcept {
  auto bounds_rect = bounds;
  if (width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), margin().left() + borders()[3].width() + padding().left() + width().value() + padding().right() + borders()[1].width() + margin().right(), bounds_rect.height());
  if (height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), margin().top() + borders()[0].width() + padding().top() + height().value() + padding().bottom() + borders()[2].width() + margin().bottom());
  
  auto border_rect = rectangle::offset(bounds_rect, margin().left(), margin().top());
  border_rect = rectangle::inflate(border_rect, -margin().right() - margin().left(), -margin().bottom() - margin().top());
  return border_rect;
}

rectangle box_data::get_fill_rectangle(const rectangle& bounds) const noexcept {
  auto fill_rect = rectangle::offset(get_border_rectangle(bounds), borders()[3].width(), borders()[0].width());
  fill_rect = rectangle::inflate(fill_rect, -borders()[3].width() - borders()[1].width(), -borders()[0].width() - borders()[2].width());
  return fill_rect;
}

rectangle box_data::get_content_rectangle(const rectangle& bounds) const noexcept {
  auto content_rect = rectangle::offset(get_fill_rectangle(bounds), padding().left(), padding().top());
  content_rect = rectangle::inflate(content_rect, -padding().left() - padding().right(), -padding().top() - padding().bottom());
  return content_rect;
}
