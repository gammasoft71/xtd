#include <xtd/argument_exception.h>
#include "../../../../include/xtd/forms/style_sheets/button_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

button_data::button_data(const box_data& box, const shared_ptr<brush>& color) : box_(box), color_(color) {
  if (!color) throw argument_exception(csf_);
}

const box_data& button_data::box() const noexcept {
  return box_;
}

const shared_ptr<brush>& button_data::color() const noexcept {
  return color_;
}
