#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_scroll_bar.hpp"
#include <xtd/forms/native/scroll_bar>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void scroll_bar::large_change(intptr control, int32 large_change) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->large_change_ = large_change;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

void scroll_bar::maximum(intptr control, int32 maximum) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->maximum_ = maximum;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

void scroll_bar::minimum(intptr control, int32 minimum) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->minimum_ = minimum;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

void scroll_bar::small_change(intptr control, int32 small_change) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->small_change_ = small_change;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}

int32 scroll_bar::value(intptr control) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return 0;
  }
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->value_ = static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->GetThumbPosition();
  return wxsb->value_;
}

void scroll_bar::value(intptr control, int32 value) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  auto wxsb = reinterpret_cast<wx_scroll_bar*>(control);
  wxsb->value_ = value;
  static_cast<wxScrollBar*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollbar(wxsb->minimum_ + wxsb->value_, wxsb->small_change_, wxsb->maximum_ - wxsb->minimum_, wxsb->large_change_);
}
