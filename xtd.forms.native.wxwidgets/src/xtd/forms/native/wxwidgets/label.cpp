#include <stdexcept>
#include <xtd/forms/native/label.hpp>
#include "control_handler.hpp"
#include <wx/stattext.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_label : public control_handler {
  public:
    wx_label(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int32_t style = 0) {
      this->control_handler::create<wxStaticText>(parent, id, title, pos, size, style);
    }
  };
}

intptr_t label::create(intptr_t parent, const size& size, styles styles) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  int64_t wx_style = wxST_NO_AUTORESIZE;
  if ((styles & label::styles::auto_size) == label::styles::auto_size) wx_style &= ~wxST_NO_AUTORESIZE;
  if ((styles & label::styles::border_fixed_single) == label::styles::border_fixed_single) wx_style |= wxBORDER_SIMPLE;
  if ((styles & label::styles::border_fixed_3d) == label::styles::border_fixed_3d) wx_style |= wxBORDER_SUNKEN;
  return (intptr_t) new wx_label(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, (styles & label::styles::auto_size) == label::styles::auto_size ? wxDefaultSize : wxSize(size.width(), size.height()), wx_style);
}
