#include "../form_api.hpp"
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/settings.h>

class Form : public control_handler {
public:
  Form(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE) {
    this->control_handler::create<wxFrame>(parent, id, title, pos, size, style);
    this->control()->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
    this->panel = new wxPanel(this->control());
    this->panel->Hide();
  }
  
private:
  wxPanel* panel;
};

intptr_t native::form_api::create(const xtd::drawing::size& size) {
  return (intptr_t) new Form(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}

void native::form_api::initialize_application() {
  if (wxTheApp) return;  
  wxInitialize();
  wxApp::SetInstance(new wxApp());
  wxTheApp->CallOnInit();
}

