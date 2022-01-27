#include "../../../../include/xtd/forms/style_sheets/control_selector.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control_selector::control_selector(const box_data& box) : box_(box) {
}

control_selector::control_selector(const box_data& box, const text_data& text) : box_(box), text_(text) {
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
