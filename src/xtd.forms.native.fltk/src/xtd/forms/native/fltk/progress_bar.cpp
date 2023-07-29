#include <xtd/forms/native/progress_bar.hpp>
#include "fl_progress_bar.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void progress_bar::value(intmax_t control, int_least32_t value) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->value(value);
}

void progress_bar::maximum(intmax_t control, int_least32_t maximum) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->maximum(maximum);
}

void progress_bar::minimum(intmax_t control, int_least32_t minimum) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->minimum(minimum);
}

void progress_bar::marquee(intmax_t control, bool marquee, size_t animation_speed) {
  if (control == 0) return;
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->marquee(marquee);
  static_cast<Fl_Progress_Bar*>(reinterpret_cast<control_handler*>(control)->control())->animation_speed(animation_speed);
}
