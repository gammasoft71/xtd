#include <stdexcept>
#include <xtd/forms/native/group_box.hpp>
#include "control_handler.hpp"
#include <wx/statbox.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_group_box : public control_handler {
  public:
    wx_group_box(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int32_t style = 0) {
      this->control_handler::create<wxStaticBox>(parent, id, title, pos, size, style);
    }
  };
}

intptr_t group_box::create(intptr_t parent, const size& size) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return (intptr_t) new wx_group_box(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}
