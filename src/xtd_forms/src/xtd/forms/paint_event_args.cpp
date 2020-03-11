#include <xtd/forms/native/control.h>
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/paint_event_args.h"

using namespace xtd;
using namespace xtd::forms;

drawing::graphics paint_event_args::graphics() const {
  if (double_buffered_) return drawing::graphics(native::control::create_double_buffered_paint_graphics(this->control_->handle()));
  return drawing::graphics(native::control::create_paint_graphics(this->control_->handle()));
}
