#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/paint_event_args.h"
#include "../../../include/xtd/forms/system_information.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

paint_event_args::paint_event_args(xtd::forms::control& control, const drawing::rectangle& clip_rectangle) : control_(&control), clip_rectangle_(clip_rectangle) {
}

paint_event_args::paint_event_args(xtd::drawing::graphics& graphics, const drawing::rectangle& clip_rectangle) : graphics_(&graphics), clip_rectangle_(clip_rectangle) {
}

const drawing::rectangle& paint_event_args::clip_rectangle() const noexcept {
  return clip_rectangle_;
}

drawing::graphics& paint_event_args::graphics() {
  if (!control_) throw xtd::argument_exception("The control is null"_t, csf_);
  auto using_double_buffered_graphics = control_->get_state(control::state::double_buffered) && !system_information::is_operating_system_double_buffered();
  if (!graphics_) graphics_.reset(new drawing::graphics(using_double_buffered_graphics ? native::control::create_double_buffered_paint_graphics(control_->handle()) : native::control::create_paint_graphics(control_->handle()), control_->region()));
  return *graphics_;
}
