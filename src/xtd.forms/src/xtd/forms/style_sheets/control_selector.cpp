#include "../../../../include/xtd/forms/style_sheets/control_selector.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control_selector::control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) :
box_(margin, border_style, border_color, border_width, border_radius, padding, background_color, width, height), text_(color, alignment, font) {
}

control_selector::control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::background_image& background_image, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) :
box_(margin, border_style, border_color, border_width, border_radius, padding, background_image, width, height), text_(color, alignment, font) {
}

const box_data& control_selector::box() const noexcept {
  return box_;
}

box_data& control_selector::box() noexcept {
  return box_;
}

const text_data& control_selector::text() const noexcept {
  return text_;
}

text_data& control_selector::text() noexcept {
  return text_;
}
