#include <stdexcept>
#include <xtd/forms/native/panel.hpp>
#include "wx_panel.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void panel::virtual_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  
  static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetVirtualSize(wxSize(size.width() - 10, size.height() - 10));
  static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollRate(10, 10);
}
