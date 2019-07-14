#include <stdexcept>
#include "../label_api.hpp"
#include "control_handler.hpp"
#include <wx/stattext.h>

namespace {
  class label : public control_handler {
  public:
    label(wxWindow *parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
      this->control_handler::create<wxStaticText>(parent, id, title, pos, size);
    }
  };
}

intptr_t native::label_api::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return (intptr_t) new label(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}
