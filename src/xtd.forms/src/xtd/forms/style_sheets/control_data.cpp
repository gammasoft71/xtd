#include "../../../../include/xtd/forms/style_sheets/control_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control_data::control_data(const box_data& box) : box_(box) {
}

control_data::control_data(const box_data& box, const text_data& text) : box_(box), text_(text) {
}

const box_data& control_data::box() const noexcept {
  return box_;
}

box_data& control_data::box() noexcept {
  return box_;
}

const text_data& control_data::text() const noexcept {
  return text_;
}

text_data& control_data::text() noexcept {
  return text_;
}
