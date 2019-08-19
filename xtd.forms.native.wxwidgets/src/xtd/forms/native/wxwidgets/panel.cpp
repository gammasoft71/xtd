#include <stdexcept>
#include <xtd/forms/native/panel.hpp>
#include "control_handler.hpp"
#include <wx/panel.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_panel : public control_handler {
  public:
    wx_panel(wxWindow *parent, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxPanel>(parent, wxID_ANY, pos, size, style);
    }
  };
}

intptr_t panel::create(const forms::create_params& create_params) {
  return (intptr_t) new wx_panel(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::to_wx_style(create_params.style(), create_params.ex_style()));
}
