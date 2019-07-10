#include "../button_api.hpp"
#include "control_handler.hpp"
#include <wx/button.h>

namespace {
  class button : public control_handler {
  public:
    button(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
      this->control_handler::create<wxButton>(parent, id, title, pos, size);
    }
  };
}

intptr_t native::button_api::create(intptr_t parent, const xtd::drawing::size& size) {
  return (intptr_t) new button(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}
