#include "../../../include/xtd/forms/flat_button_appearance.hpp"

using namespace xtd;
using namespace xtd::forms;

struct flat_button_appearance::data {
  std::optional<xtd::drawing::color> border_color;
  std::optional<int32> border_radius;
  std::optional<int32> border_size;
  std::optional<xtd::drawing::color> checked_back_color;
  std::optional<xtd::drawing::color> mouse_down_back_color;
  std::optional<xtd::drawing::color> mouse_over_back_color;
};

flat_button_appearance::flat_button_appearance() : data_(xtd::new_sptr<data>()) {
}

flat_button_appearance::flat_button_appearance(const flat_button_appearance& other) : data_(xtd::new_sptr<data>()) {
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

std::optional<int32> flat_button_appearance::border_radius() const noexcept {
  return data_->border_radius;
}

flat_button_appearance& flat_button_appearance::border_radius(int32 radius) {
  data_->border_radius = radius;
  return *this;
}

flat_button_appearance& flat_button_appearance::border_radius(std::nullptr_t) {
  data_->border_radius.reset();
  return *this;
}

std::optional<int32> flat_button_appearance::border_size() const noexcept {
  return data_->border_size;
}

flat_button_appearance& flat_button_appearance::border_size(int32 size) {
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

bool flat_button_appearance::equals(const object& obj) const noexcept {
  return is<flat_button_appearance>(obj) && equals(static_cast<const flat_button_appearance&>(obj));
}

bool flat_button_appearance::equals(const flat_button_appearance& other) const noexcept {
  return data_->border_color == other.data_->border_color && data_->border_radius == other.data_->border_radius && data_->border_size == other.data_->border_size && data_->checked_back_color == other.data_->checked_back_color && data_->mouse_down_back_color == other.data_->mouse_down_back_color && data_->mouse_over_back_color == other.data_->mouse_over_back_color;
}

xtd::size flat_button_appearance::get_hash_code() const noexcept {
  return hash_code::combine(data_->border_color.value_or(drawing::color::empty), data_->border_radius.value_or(0), data_->border_size.value_or(0), data_->checked_back_color.value_or(drawing::color::empty), data_->mouse_down_back_color.value_or(drawing::color::empty), data_->mouse_over_back_color.value_or(drawing::color::empty));
}
