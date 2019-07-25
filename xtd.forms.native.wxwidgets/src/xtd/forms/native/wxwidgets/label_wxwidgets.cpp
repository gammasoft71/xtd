#include <stdexcept>
#include <xtd/forms/native/label.hpp>
#include "control_handler.hpp"
#include <wx/stattext.h>

namespace {
  class wx_label : public control_handler {
  public:
    wx_label(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
      this->control_handler::create<wxStaticText>(parent, id, title, pos, size);
    }
  };
}

intptr_t xtd::forms::native::label::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return (intptr_t) new wx_label(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}
