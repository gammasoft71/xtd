#include <xtd/forms/native/progress_bar.hpp>
#include "wx_progress_bar.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void progress_bar::value(intptr_t control, int32_t value) {
  static_cast<wxGauge*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
}

void progress_bar::maximum(intptr_t control, int32_t maximum) {
  reinterpret_cast<wx_progress_bar*>(control)->maximum_ = maximum;
  static_cast<wxGauge*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(reinterpret_cast<wx_progress_bar*>(control)->maximum_ - reinterpret_cast<wx_progress_bar*>(control)->minimum_);
}

void progress_bar::minimum(intptr_t control, int32_t minimum) {
  reinterpret_cast<wx_progress_bar*>(control)->minimum_ = minimum;
  static_cast<wxGauge*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(reinterpret_cast<wx_progress_bar*>(control)->maximum_ - reinterpret_cast<wx_progress_bar*>(control)->minimum_);
}

void progress_bar::marquee(intptr_t control, bool marquee, size_t animation_speed) {
  reinterpret_cast<wx_progress_bar*>(control)->marquee(marquee, animation_speed);
}
