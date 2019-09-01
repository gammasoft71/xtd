#include <xtd/forms/native/control.hpp>
#include "../../../include/xtd/forms/control.hpp"
#include "../../../include/xtd/forms/paint_event_args.hpp"

using namespace xtd;
using namespace xtd::forms;

drawing::graphics paint_event_args::graphics() const {
  return drawing::graphics(native::control::create_paint_graphics(this->control_->handle()));
}
