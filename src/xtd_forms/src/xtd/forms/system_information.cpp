#include <xtd/forms/native/system_information.hpp>
#include "../../../include/xtd/forms/system_information.hpp"

using namespace xtd;
using namespace xtd::forms;

int32_t system_information::active_window_tracking_delay() {
  return native::system_information::active_window_tracking_delay();
}

xtd::forms::arrange_direction system_information::arrange_direction() {
  return static_cast<xtd::forms::arrange_direction>(native::system_information::arrange_direction());
}

xtd::forms::arrange_starting_position system_information::arrange_starting_position() {
  return static_cast<xtd::forms::arrange_starting_position>(native::system_information::arrange_starting_position());
}

xtd::forms::boot_mode system_information::boot_mode() {
  return static_cast<xtd::forms::boot_mode>(native::system_information::boot_mode());
}

xtd::drawing::size system_information::border_3d_size() {
  return native::system_information::border_3d_size();
}

int32_t system_information::border_multiplier_factor() {
  return native::system_information::border_multiplier_factor();
}

xtd::drawing::size system_information::border_size() {
  return native::system_information::border_size();
}

xtd::drawing::size system_information::caption_button_size() {
  return native::system_information::caption_button_size();
}
