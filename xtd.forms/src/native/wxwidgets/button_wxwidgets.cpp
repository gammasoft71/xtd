#include "../button_api.hpp"
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/settings.h>

class Button : public control_handler {
public:
  Button(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
    this->control_handler::create<wxButton>(parent, id, title, pos, size);
  }
};

intptr_t native::button_api::create(intptr_t parent, const xtd::drawing::size& size) {
  return (intptr_t) new Button(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}
