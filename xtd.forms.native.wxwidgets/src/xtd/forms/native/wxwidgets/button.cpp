#include <xtd/forms/native/button.hpp>
#include "control_handler.hpp"
#include <wx/button.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_button : public control_handler {
  public:
    wx_button(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxButton>(parent, id, title, pos, size, 0);
    }
  };
}

intptr_t button::create(intptr_t parent, const size& size, size_t styles, size_t ex_styles) {
  return (intptr_t) new wx_button(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()}, control_handler::to_wx_style(styles, ex_styles));
}
