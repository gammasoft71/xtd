#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_scroll_bar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void scroll_bar::large_change(intptr_t control, int32_t large_change) {
  if (control == 0) return;
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->large_change_ = large_change;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

void scroll_bar::maximum(intptr_t control, int32_t maximum) {
  if (control == 0) return;
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->maximum_ = maximum;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

void scroll_bar::minimum(intptr_t control, int32_t minimum) {
  if (control == 0) return;
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->minimum_ = minimum;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

void scroll_bar::small_change(intptr_t control, int32_t small_change) {
  if (control == 0) return;
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->small_change_ = small_change;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

int32_t scroll_bar::value(intptr_t control) {
  if (control == 0) return 0;
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->value_ = static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->GetThumbPosition();
  return wxsb->value_;
}

void scroll_bar::value(intptr_t control, int32_t value) {
  if (control == 0) return;
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->value_ = value;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}
