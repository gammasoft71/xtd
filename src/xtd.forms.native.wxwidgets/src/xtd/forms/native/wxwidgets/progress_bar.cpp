#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_progress_bar"
#include <xtd/forms/native/progress_bar>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void progress_bar::value(intptr control, int32 value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxGauge*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
}

void progress_bar::maximum(intptr control, int32 maximum) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<wx_progress_bar*>(control)->maximum_ = maximum;
  static_cast<wxGauge*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(reinterpret_cast<wx_progress_bar*>(control)->maximum_ - reinterpret_cast<wx_progress_bar*>(control)->minimum_);
}

void progress_bar::minimum(intptr control, int32 minimum) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<wx_progress_bar*>(control)->minimum_ = minimum;
  static_cast<wxGauge*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(reinterpret_cast<wx_progress_bar*>(control)->maximum_ - reinterpret_cast<wx_progress_bar*>(control)->minimum_);
}

void progress_bar::marquee(intptr control, bool marquee, size_t animation_speed) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<wx_progress_bar*>(control)->marquee(marquee, animation_speed);
}
