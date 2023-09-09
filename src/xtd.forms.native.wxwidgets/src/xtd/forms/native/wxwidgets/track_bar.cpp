#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/track_bar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_track_bar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void track_bar::large_change(intptr control, int32 large_change) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetPageSize(large_change);
}

void track_bar::maximum(intptr control, int32 maximum) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetMax(maximum);
}

void track_bar::minimum(intptr control, int32 minimum) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetMin(minimum);
}

void track_bar::small_change(intptr control, int32 small_change) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetLineSize(small_change);
}

void track_bar::tick_frequency(intptr control, int32 tick_frequency) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  if ((static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->GetWindowStyle() & wxSL_AUTOTICKS) != wxSL_AUTOTICKS) return;
  
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetTickFreq(tick_frequency);
}

int32 track_bar::value(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  return static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void track_bar::value(intptr control, int32 value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSlider*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
}
