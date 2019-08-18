#include <xtd/drawing/color.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/form.hpp>
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/settings.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_form : public control_handler {
  public:
    wx_form(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxFrame>(parent, id, title, pos, size, style);
       this->panel = new wxPanel(this->control());
      this->panel->Hide();
      this->control()->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        event.Veto();
      });
    }
    
  private:
    wxPanel* panel;
  };
}

intptr_t form::create(const size& size, size_t styles, size_t ex_styles) {
  application::initialize_application(); // Must be first
  return (intptr_t) new wx_form(wxTheApp->GetTopWindow(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()}, (control_handler::to_wx_style(styles, ex_styles) | wxDEFAULT_FRAME_STYLE) & ~wxBORDER_NONE);
}

void form::close(intptr_t form) {
  reinterpret_cast<wx_form*>(form)->control()->Close();
}
