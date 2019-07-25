#include <stdexcept>
#include <xtd/forms/native/text_box.hpp>
#include "control_handler.hpp"
#include <wx/textctrl.h>

using namespace std;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_text_box : public control_handler {
  public:
    wx_text_box(wxWindow *parent, wxWindowID id, const wxString& value, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
      this->control_handler::create<wxTextCtrl>(parent, id, value, pos, size);
    }
  };
}

intptr_t text_box::create(intptr_t parent, const drawing::size& size) {
  if (parent == 0) throw invalid_argument("parent can't be null");
  return (intptr_t) new wx_text_box(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()});
}

string text_box::text(intptr_t control) {
  if (control == 0) return {};
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue().ToStdString();
}

void text_box::text(intptr_t control, const string& text) {
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(text);
  //send_message(control, control, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString().c_str()));
}
