#include <xtd/forms/native/track_bar.hpp>
#include "fl_track_bar.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void track_bar::large_change(intptr_t control, int32_t large_change) {
}

void track_bar::maximum(intptr_t control, int32_t maximum) {
  if (control == 0) return;
  static_cast<Fl_Slider*>(reinterpret_cast<control_handler*>(control)->control())->maximum(maximum);
}

void track_bar::minimum(intptr_t control, int32_t minimum) {
  if (control == 0) return;
  static_cast<Fl_Slider*>(reinterpret_cast<control_handler*>(control)->control())->minimum(minimum);
}

void track_bar::small_change(intptr_t control, int32_t small_change) {
}

void track_bar::tick_frequency(intptr_t control, int32_t tick_frequency) {
}

int32_t track_bar::value(intptr_t control) {
  if (control == 0) return 0;
  return static_cast<Fl_Slider*>(reinterpret_cast<control_handler*>(control)->control())->value();
}

void track_bar::value(intptr_t control, int32_t value) {
  if (control == 0) return;
  static_cast<Fl_Slider*>(reinterpret_cast<control_handler*>(control)->control())->value(value);
}
