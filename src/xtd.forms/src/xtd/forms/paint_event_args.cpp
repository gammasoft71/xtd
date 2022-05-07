#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/control.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/paint_event_args.h"

using namespace xtd;
using namespace xtd::forms;

paint_event_args::~paint_event_args() {
  if (control_ && graphics_) delete graphics_;
}

drawing::graphics& paint_event_args::graphics() {
  auto using_double_buffered_graphics = control_->get_state(control::state::double_buffered) && !native::toolkit::is_operating_system_double_buffered();
  if (control_ && !graphics_) graphics_ = new drawing::graphics(using_double_buffered_graphics ? native::control::create_double_buffered_paint_graphics(control_->handle()) : native::control::create_paint_graphics(control_->handle()), control_->region());
  return *graphics_;
}
