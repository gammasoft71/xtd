#include "../form_api.hpp"
#include "ControlEvent.hpp"
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Form : public control_handler {
public:
  Form(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE) {
    this->control_handler::create<wxFrame>(parent, id, title, pos, size, style);
    this->panel = new wxPanel(this->control());
    this->control()->SetBackgroundColour(this->panel->GetBackgroundColour());
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

