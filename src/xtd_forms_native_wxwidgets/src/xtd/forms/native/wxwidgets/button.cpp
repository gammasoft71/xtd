#include <xtd/forms/native/button.hpp>
#include "wx_button.hpp"

using namespace xtd;
using namespace xtd::forms::native;

void button::default_button(intptr_t control, bool default_button) {
  if (control == 0) return;
  
  wxWindow* top_level_control = static_cast<wxWindow*>(reinterpret_cast<control_handler*>(control)->control());
  while (top_level_control && dynamic_cast<wxTopLevelWindow*>(top_level_control) == nullptr && top_level_control->GetParent() != nullptr)
    top_level_control = top_level_control->GetParent();
  if (top_level_control && dynamic_cast<wxTopLevelWindow*>(top_level_control) != nullptr)
    static_cast<wxTopLevelWindow*>(top_level_control)->SetDefaultItem(default_button ? static_cast<wxWindow*>(reinterpret_cast<control_handler*>(control)->control()) : nullptr);
}
