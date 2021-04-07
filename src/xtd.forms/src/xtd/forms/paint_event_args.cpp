#include <xtd/forms/native/control.h>
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/paint_event_args.h"

using namespace xtd;
using namespace xtd::forms;

drawing::graphics paint_event_args::graphics() const {
  if (control_->get_state(control::state::double_buffered)) return drawing::graphics(native::control::create_double_buffered_paint_graphics(control_->handle()));
  return drawing::graphics(native::control::create_paint_graphics(control_->handle()));
}
