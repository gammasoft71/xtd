#include "../../../include/xtd/forms/flat_button_appearance.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

std::optional<xtd::drawing::color> flat_button_appearance::border_color() const {
  return border_color_;
}

flat_button_appearance& flat_button_appearance::border_color(const xtd::drawing::color& color) {
  border_color_ = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::border_color(nullptr_t) {
  border_color_.reset();
  return *this;
}

int32_t flat_button_appearance::border_size() const {
  return border_size_;
}

flat_button_appearance& flat_button_appearance::border_size(int32_t size) {
  border_size_ = size;
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::checked_back_color() const {
  return checked_back_color_;
}

flat_button_appearance& flat_button_appearance::checked_back_color(const xtd::drawing::color& color) {
  checked_back_color_ = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::checked_back_color(nullptr_t) {
  checked_back_color_.reset();
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::mouse_down_back_color() const {
  return mouse_down_back_color_;
}

flat_button_appearance& flat_button_appearance::mouse_down_back_color(const xtd::drawing::color& color) {
  mouse_down_back_color_ = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::mouse_down_back_color(nullptr_t) {
  mouse_down_back_color_.reset();
  return *this;
}

std::optional<xtd::drawing::color> flat_button_appearance::mouse_over_back_color() const {
  return mouse_over_back_color_;
}

flat_button_appearance& flat_button_appearance::mouse_over_back_color(const xtd::drawing::color& color) {
  mouse_over_back_color_ = color;
  return *this;
}

flat_button_appearance& flat_button_appearance::mouse_over_back_color(nullptr_t) {
  mouse_over_back_color_.reset();
  return *this;
}
