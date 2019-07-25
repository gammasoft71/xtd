#include <xtd/forms/native/button.hpp>
#include "control_handler.hpp"
#include <wx/button.h>

using namespace xtd::forms::native;

namespace {
  class wx_button : public control_handler {
  public:
    wx_button(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
      this->control_handler::create<wxButton>(parent, id, title, pos, size);
    }
  };
}

intptr_t button::create(intptr_t parent, const xtd::drawing::size& size) {
  return (intptr_t) new wx_button(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()});
}
