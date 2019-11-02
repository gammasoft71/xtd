#include <stdexcept>
#include <xtd/forms/native/user_control.hpp>
#include "wx_user_control.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void user_control::virtual_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  
  static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetVirtualSize(wxSize(size.width(), size.height()));
  static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollRate(10, 10);
}
