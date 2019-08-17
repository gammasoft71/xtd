#include <stdexcept>
#include <xtd/forms/native/label.hpp>
#include "control_handler.hpp"
#include <wx/stattext.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_label : public control_handler {
  public:
    wx_label(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size , int32_t style) {
      this->control_handler::create<wxStaticText>(parent, id, title, pos, size, style);
    }
  };
}

intptr_t label::create(intptr_t parent, const size& size, size_t styles, size_t ex_styles) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return (intptr_t) new wx_label(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, (styles & SS_AUTOSIZE) == SS_AUTOSIZE ? wxDefaultSize : wxSize(size.width(), size.height()), control_handler::to_wx_style(styles, ex_styles));
}
