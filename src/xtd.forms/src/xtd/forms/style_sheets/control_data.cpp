#include <xtd/argument_exception.h>
#include "../../../../include/xtd/forms/style_sheets/control_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control_data::control_data(const box_data& box, const shared_ptr<brush>& color) : box_(box), color_(color) {
  if (!color) throw argument_exception(csf_);
}

const box_data& control_data::box() const noexcept {
  return box_;
}

const shared_ptr<brush>& control_data::color() const noexcept {
  return color_;
}
