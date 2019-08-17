#include <xtd/forms/native/check_box.hpp>
#include "control_handler.hpp"
#include <wx/checkbox.h>
#include <wx/tglbtn.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_check_box : public control_handler {
  public:
    wx_check_box(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, int style, bool push_like) {
      if (!push_like)
        this->control_handler::create<wxCheckBox>(parent, id, title, pos, size, style);
      else
        this->control_handler::create<wxToggleButton>(parent, id, title, pos, size, 0);
    }
  };
  
  wxCheckBoxState to_check_box_state(int value) {
    switch (value) {
      case BST_UNCHECKED: return wxCheckBoxState::wxCHK_UNCHECKED;
      case BST_CHECKED: return wxCheckBoxState::wxCHK_CHECKED;
      case BST_INDETERMINATE: return wxCheckBoxState::wxCHK_UNDETERMINED;
      default: return wxCheckBoxState::wxCHK_UNCHECKED;
    }
  }
  
  int from_check_box_state(wxCheckBoxState value) {
    switch (value) {
      case wxCheckBoxState::wxCHK_UNCHECKED: return BST_UNCHECKED;
      case wxCheckBoxState::wxCHK_CHECKED: return BST_CHECKED;
      case wxCheckBoxState::wxCHK_UNDETERMINED: return BST_INDETERMINATE;
      default: return BST_UNCHECKED;
    }
  }
}

intptr_t check_box::create(intptr_t parent, const size& size, size_t styles, size_t ex_styles) {
  return (intptr_t) new wx_check_box(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()}, wxCHK_3STATE | control_handler::to_wx_style(styles, ex_styles), (styles & BS_PUSHLIKE) == BS_PUSHLIKE);
}

int check_box::check_state(intptr_t control) {
  if (control == 0) return false;
  if (dynamic_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    return from_check_box_state(static_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control())->Get3StateValue());
  else
    return static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void check_box::check_state(intptr_t control, int state) {
  if (control == 0) return;
  if (dynamic_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    static_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control())->Set3StateValue(to_check_box_state(state));
  else
    static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(state);
}
