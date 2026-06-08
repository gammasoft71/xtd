#include "../../../include/xtd/forms/control.hpp"
#include "../../../include/xtd/forms/paint_event_args.hpp"
#include "../../../include/xtd/forms/system_information.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;

paint_event_args::paint_event_args(xtd::forms::control& control, const xtd::drawing::rectangle& clip_rectangle, xtd::forms::message& message)  : control_(&control), clip_rectangle_(clip_rectangle), message_(&message) {
  auto using_double_buffered_graphics = control_->get_state(control::state::double_buffered) && !system_information::is_operating_system_double_buffered();
  graphics_.reset(new xtd::drawing::graphics {using_double_buffered_graphics ? native::control::create_double_buffered_paint_graphics(control_->handle()) : native::control::create_paint_graphics(control_->handle()), control_->region()});
}

const rectangle& paint_event_args::clip_rectangle() const noexcept {
  return clip_rectangle_;
}

xtd::drawing::graphics& paint_event_args::graphics() {
  return *graphics_;
}

xtd::forms::message& paint_event_args::message() noexcept {
  return *message_;
}
