#include <xtd/forms/native/radio_button.hpp>
#include "control_handler.hpp"
#include <wx/radiobut.h>
#include <wx/tglbtn.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_radio_button : public control_handler {
  public:
    wx_radio_button(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, bool push_like) {
      if (!push_like)
        this->control_handler::create<wxRadioButton>(parent, id, title, pos, size, style | wxRB_GROUP);
      else
        this->control_handler::create<wxToggleButton>(parent, id, title, pos, size, 0);
      this->hiden_radio_button = new wxRadioButton(parent, id, title, pos, size, 0);
      this->hiden_radio_button->Show(false);
    }
    wxRadioButton* hiden_radio_button = nullptr;
  };
}

intptr_t radio_button::create(intptr_t parent, const size& size, size_t styles, size_t ex_styles) {
  return (intptr_t) new wx_radio_button(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()}, control_handler::to_wx_style(styles, ex_styles), (styles & BS_PUSHLIKE) == BS_PUSHLIKE);
}

bool radio_button::checked(intptr_t control) {
  if (control == 0) return false;
  if (dynamic_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    return static_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  return static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void radio_button::checked(intptr_t control, bool checked) {
  if (control == 0) return;
  if (dynamic_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr) {
    reinterpret_cast<wx_radio_button*>(control)->hiden_radio_button->SetValue(!checked);
    static_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(checked);
  }
  else {
    reinterpret_cast<wx_radio_button*>(control)->hiden_radio_button->SetValue(checked);
    static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(checked);
  }
}
