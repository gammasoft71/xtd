#include <stdexcept>
#include <xtd/forms/native/panel.hpp>
#include "control_handler.hpp"
#include <wx/panel.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_panel : public control_handler {
  public:
    wx_panel(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxPanel>(parent, id, pos, size, style);
    }
  };
}

intptr_t panel::create(intptr_t parent, const size& size, size_t styles, size_t ex_styles) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return (intptr_t) new wx_panel(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height()), control_handler::to_wx_style(styles, ex_styles));
}
