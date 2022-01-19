#include <xtd/argument_exception.h>
#include "../../../../include/xtd/forms/style_sheets/color_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

color_data::color_data(color_style style) : style_(style) {
}

color_style color_data::style() const noexcept {
  return style_;
}
