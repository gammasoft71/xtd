#include <stdexcept>
#include <xtd/forms/native/panel.hpp>
#include "control_handler.hpp"
#include <wx/panel.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

#if defined(__APPLE__)
constexpr int64_t border_fixed_single = wxBORDER_SUNKEN;
constexpr int64_t border_fixed_3d = wxBORDER_SIMPLE;
#else
constexpr int64_t border_fixed_single = wxBORDER_SIMPLE;
constexpr int64_t border_fixed_3d = wxBORDER_SUNKEN;
#endif

namespace {
  class wx_panel : public control_handler {
  public:
    wx_panel(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int32_t style = 0) {
      this->control_handler::create<wxPanel>(parent, id, pos, size, style);
    }
  };
}

intptr_t panel::create(intptr_t parent, const size& size, styles styles) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  int64_t wx_style = 0;
  if ((styles & panel::styles::border_fixed_single) == panel::styles::border_fixed_single) wx_style |= border_fixed_single;
  if ((styles & panel::styles::border_fixed_3d) == panel::styles::border_fixed_3d) wx_style |= border_fixed_3d;
  return (intptr_t) new wx_panel(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height()), wx_style);
}
