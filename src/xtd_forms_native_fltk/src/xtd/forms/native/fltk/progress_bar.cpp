#include <xtd/forms/native/progress_bar.hpp>
#include "fl_progress_bar.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void progress_bar::value(intptr_t control, int32_t value) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->value(value);
}

void progress_bar::maximum(intptr_t control, int32_t maximum) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->maximum(maximum);
}

void progress_bar::minimum(intptr_t control, int32_t minimum) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->minimum(minimum);
}

void progress_bar::marquee(intptr_t control, bool marquee, size_t animation_speed) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->marquee(marquee);
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->animation_speed(animation_speed);
}
