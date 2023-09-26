#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_checked_list_box"
#include <xtd/forms/native/application>
#include <xtd/forms/native/checked_list_box>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <xtd/drawing/system_colors>
#include <limits>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void checked_list_box::begin_update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void checked_list_box::check_state(intptr control, size_t index, int32 check_state) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32>(index), check_state != 0);
}

int32 checked_list_box::check_state(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  return static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->IsChecked(static_cast<int32>(index));
}

void checked_list_box::delete_item(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32>(index));
}

void checked_list_box::end_update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void checked_list_box::insert_item(intptr control, size_t index, const ustring& value, int32 check_state) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(xtd::convert_string::to_wstring(value), static_cast<int32>(index));
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32>(index), check_state != 0);
  #if defined(__WXMSW__)
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetItem(index)->SetTextColour(static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetForegroundColour());
  #endif
}

size_t checked_list_box::selected_index(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  if (static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->HasMultipleSelection()) {
    vector<size_t> indices = selected_indices(control);
    if (indices.empty()) return std::numeric_limits<size_t>::max();
    return indices[0];
  }
  return static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void checked_list_box::selected_index(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  return static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32>(index));
}

vector<size_t> checked_list_box::selected_indices(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  vector<size_t> indices;
  wxArrayInt wx_indices;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelections(wx_indices);
  for_each(wx_indices.begin(), wx_indices.end(), [&](int32 index) {indices.push_back(index);});
  return indices;
  
}

void checked_list_box::update_item(intptr control, size_t index, const xtd::ustring& value, int32 check_state) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32>(index), xtd::convert_string::to_wstring(value));
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32>(index), check_state != 0);
}
