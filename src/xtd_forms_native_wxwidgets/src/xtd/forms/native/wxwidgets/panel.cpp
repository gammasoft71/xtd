#include <stdexcept>
#include <xtd/forms/native/panel.hpp>
#include "wx_panel.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void panel::virtual_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;

#if defined(__WXOSX__)
  int32_t offset_x = -9;
#else
  int32_t offset_x = -9;
#endif
  int32_t offset_y = -10;

  
  static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetVirtualSize(wxSize(size.width() + offset_x, size.height() + offset_y));
  static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollRate(10, 10);
}
