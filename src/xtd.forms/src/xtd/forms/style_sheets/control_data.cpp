#include "../../../../include/xtd/forms/style_sheets/control_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control_data::control_data(const box_data& box) : box_(box) {
}

const box_data& control_data::box() const noexcept {
  return box_;
}

const color_data& control_data::color() const noexcept {
  return color_;
}
