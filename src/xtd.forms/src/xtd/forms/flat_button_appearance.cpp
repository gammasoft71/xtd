#include "../../../include/xtd/forms/flat_button_appearance.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

flat_button_appearance::flat_button_appearance(const flat_button_appearance& other) {
  *data_ = *other.data_;
}

flat_button_appearance& flat_button_appearance::operator =(const flat_button_appearance& other) {
  *data_ = *other.data_;
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::border_color() const noexcept {
  return data_->border_color;
}

flat_button_appearance& flat_button_appearance::border_color(const xtd::drawing::color& color) {
  data_->border_color = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::border_color(std::nullptr_t) {
  data_->border_color.reset();
  return *this;
}

std::optional<int32_t> flat_button_appearance::border_radius() const noexcept {
  return data_->border_radius;
}

flat_button_appearance& flat_button_appearance::border_radius(int32_t radius) {
  data_->border_radius = radius;
  return *this;
}

flat_button_appearance& flat_button_appearance::border_radius(std::nullptr_t) {
  data_->border_radius.reset();
  return *this;
}

std::optional<int32_t> flat_button_appearance::border_size() const noexcept {
  return data_->border_size;
}

flat_button_appearance& flat_button_appearance::border_size(int32_t size) {
  data_->border_size = size;
  return *this;
}

flat_button_appearance& flat_button_appearance::border_size(std::nullptr_t) {
  data_->border_size.reset();
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::checked_back_color() const noexcept {
  return data_->checked_back_color;
}

flat_button_appearance& flat_button_appearance::checked_back_color(const xtd::drawing::color& color) {
  data_->checked_back_color = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::checked_back_color(std::nullptr_t) {
  data_->checked_back_color.reset();
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::mouse_down_back_color() const noexcept {
  return data_->mouse_down_back_color;
}

flat_button_appearance& flat_button_appearance::mouse_down_back_color(const xtd::drawing::color& color) {
  data_->mouse_down_back_color = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::mouse_down_back_color(std::nullptr_t) {
  data_->mouse_down_back_color.reset();
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::mouse_over_back_color() const noexcept {
  return data_->mouse_over_back_color;
}

flat_button_appearance& flat_button_appearance::mouse_over_back_color(const xtd::drawing::color& color) {
  data_->mouse_over_back_color = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::mouse_over_back_color(std::nullptr_t) {
  data_->mouse_over_back_color.reset();
  return *this;
}

bool flat_button_appearance::equals(const flat_button_appearance& other) const noexcept {
  return data_->border_color == other.data_->border_color && data_->border_size == other.data_->border_size && data_->checked_back_color == other.data_->checked_back_color && data_->mouse_down_back_color == other.data_->mouse_down_back_color && data_->mouse_over_back_color == other.data_->mouse_over_back_color;
}
