#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.h"
#include <xtd/forms/native/application>
#include <xtd/forms/native/text_box>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/argument_exception>
#include <xtd/convert_string>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

size_t text_box::selection_length(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  long from = 0, to = 0;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection(&from, &to);
  return static_cast<size_t>(to - from);
}

size_t text_box::selection_start(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  long from = 0, to = 0;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection(&from, &to);
  return static_cast<size_t>(from);
}

void text_box::append(intptr control, const ustring& text) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->AppendText(convert_string::to_wstring(text));
}

void text_box::select(intptr control, size_t start, size_t length) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(start, start + length);
}
ustring text_box::text(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return "";
  }
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue().c_str().AsWChar();
}

void text_box::text(intptr control, const ustring& text) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  switch (reinterpret_cast<wx_text_box*>(control)->character_casing_) {
    case wx_text_box::character_casing::normal: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wxString(convert_string::to_wstring(text))); break;
    case wx_text_box::character_casing::upper: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(convert_string::to_wstring(text.to_upper())); break;
    case wx_text_box::character_casing::lower: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(convert_string::to_wstring(text.to_lower())); break;
  }
}

void text_box::placeholder_text(intptr control, const ustring& text) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  switch (reinterpret_cast<wx_text_box*>(control)->character_casing_) {
    case wx_text_box::character_casing::normal: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetHint(wxString(convert_string::to_wstring(text))); break;
    case wx_text_box::character_casing::upper: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetHint(convert_string::to_wstring(text.to_upper())); break;
    case wx_text_box::character_casing::lower: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetHint(convert_string::to_wstring(text.to_lower())); break;
  }
}
