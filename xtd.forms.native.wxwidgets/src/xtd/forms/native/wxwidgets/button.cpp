#include <xtd/forms/native/button.hpp>
#include "control_handler.hpp"
#include <wx/button.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_button : public control_handler {
  public:
    wx_button(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxButton>(parent, wxID_ANY, title, pos, size, 0);
    }
  };
}

intptr_t button::create(const forms::create_params& create_params) {
  return (intptr_t) new wx_button(reinterpret_cast<control_handler*>(create_params.parent())->control(), create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::button_to_wx_style(create_params.style(), create_params.ex_style()));
}
