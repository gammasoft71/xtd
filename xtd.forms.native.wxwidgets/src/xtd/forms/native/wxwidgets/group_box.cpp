#include <stdexcept>
#include <xtd/forms/native/group_box.hpp>
#include "control_handler.hpp"
#include <wx/statbox.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_group_box : public control_handler {
  public:
    wx_group_box(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxStaticBox>(parent, wxID_ANY, title, pos, size, style);
    }
  };
}

intptr_t group_box::create(const forms::create_params& create_params) {
  return (intptr_t) new wx_group_box(reinterpret_cast<control_handler*>(create_params.parent())->control(), create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::to_wx_style(create_params.style(), create_params.ex_style()));
}
