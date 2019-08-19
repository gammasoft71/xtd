#include <xtd/forms/native/radio_button.hpp>
#include "control_handler.hpp"
#include <wx/radiobut.h>
#include <wx/tglbtn.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_radio_button : public control_handler {
  public:
    wx_radio_button(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style, bool push_like) {
      if (!push_like)
        this->control_handler::create<wxRadioButton>(parent, wxID_ANY, title, pos, size, style | wxRB_GROUP);
      else
        this->control_handler::create<wxToggleButton>(parent, wxID_ANY, title, pos, size, 0);
      this->hiden_radio_button = new wxRadioButton(parent, wxID_ANY, title, pos, size, 0);
      this->hiden_radio_button->Show(false);
    }
    wxRadioButton* hiden_radio_button = nullptr;
  };
}

intptr_t radio_button::create(const create_params& create_params) {
  return (intptr_t) new wx_radio_button(reinterpret_cast<control_handler*>(create_params.parent())->control(), create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::to_wx_style(create_params.style(), create_params.ex_style()), (create_params.style() & BS_PUSHLIKE) == BS_PUSHLIKE);
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
