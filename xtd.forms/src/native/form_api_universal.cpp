#include "form_api.hpp"
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Form : public wxFrame {
public:
  Form(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE,  const wxString& name = wxFrameNameStr) : wxFrame(parent, id, title, pos, size, style, name) {
    this->SetBackgroundColour(this->panel->GetBackgroundColour());
    this->panel->Hide();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
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

