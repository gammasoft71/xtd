#include <stdexcept>
#include <xtd/forms/native/label.hpp>
#include "control_handler.hpp"
#include <wx/stattext.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_label : public control_handler {
  public:
    wx_label(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size , int32_t style) {
      this->control_handler::create<wxStaticText>(parent, wxID_ANY, title, pos, size, style);
    }
  };
}

intptr_t label::create(const forms::create_params& create_params) {
  return (intptr_t) new wx_label(reinterpret_cast<control_handler*>(create_params.parent())->control(), create_params.caption(), wxPoint(create_params.x(), create_params.y()), (create_params.style() & SS_AUTOSIZE) == SS_AUTOSIZE ? wxDefaultSize : wxSize(create_params.width(), create_params.height()), control_handler::to_wx_style(create_params.style(), create_params.ex_style()));
}
