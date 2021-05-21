#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/track_bar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_track_bar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void track_bar::large_change(intptr_t control, int32_t large_change) {
  if (control == 0) return;
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetPageSize(large_change);
}

void track_bar::maximum(intptr_t control, int32_t maximum) {
  if (control == 0) return;
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetMax(maximum);
}

void track_bar::minimum(intptr_t control, int32_t minimum) {
  if (control == 0) return;
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetMin(minimum);
}

void track_bar::small_change(intptr_t control, int32_t small_change) {
  if (control == 0) return;
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetLineSize(small_change);
}

void track_bar::tick_frequency(intptr_t control, int32_t tick_frequency) {
  if (control == 0) return;
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetTickFreq(tick_frequency);
}

int32_t track_bar::value(intptr_t control) {
  if (control == 0) return 0;
  return static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void track_bar::value(intptr_t control, int32_t value) {
  if (control == 0) return;
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
}
