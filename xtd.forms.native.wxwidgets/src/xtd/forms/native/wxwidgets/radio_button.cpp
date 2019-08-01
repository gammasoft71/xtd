#include <xtd/forms/native/radio_button.hpp>
#include "control_handler.hpp"
#include <wx/radiobut.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_radio_button : public control_handler {
  public:
    wx_radio_button(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int style = 0) {
      this->control_handler::create<wxRadioButton>(parent, id, title, pos, size, style);
    }
  };
}

intptr_t radio_button::create(intptr_t parent, const size& size) {
  return (intptr_t) new wx_radio_button(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()});
}

bool radio_button::checked(intptr_t control) {
  return static_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void radio_button::checked(intptr_t control, bool checked) {
  static_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(checked);
}
