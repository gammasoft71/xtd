#include <xtd/drawing/color.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/form.hpp>
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/settings.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_form : public control_handler {
  public:
    wx_form(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxFrame>(parent, wxID_ANY, title, pos, size, style);
      this->panel = new wxPanel(this->control());
      this->control()->SetBackgroundColour(this->panel->GetBackgroundColour());
      this->panel->Hide();
      this->control()->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {event.Veto();});
    }
    
  private:
    wxPanel* panel;
  };
}

intptr_t form::create(const forms::create_params& create_params) {
  application::initialize_application(); // Must be first
  return (intptr_t) new wx_form(create_params.parent() ? ((control_handler*)create_params.parent())->control() : wxTheApp->GetTopWindow(), create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::form_to_wx_style(create_params.style(), create_params.ex_style()));
}

void form::close(intptr_t form) {
  reinterpret_cast<wx_form*>(form)->control()->Close();
}
