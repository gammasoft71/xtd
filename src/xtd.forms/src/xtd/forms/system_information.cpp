#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/system_information.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/system_information.h"

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

int32_t system_information::caption_height() {
  return native::system_information::caption_height();
}

int32_t system_information::caret_blink_time() {
  return native::system_information::caret_blink_time();
}

int32_t system_information::caret_width() {
  return native::system_information::caret_width();
}

xtd::ustring system_information::computer_name() {
  return native::system_information::computer_name();
}

xtd::drawing::size system_information::cursor_size() {
  return native::system_information::cursor_size();
}

bool system_information::dbcs_enabled() {
  return native::system_information::dbcs_enabled();
}

bool system_information::debug_os() {
  return native::system_information::dbcs_enabled();
}

xtd::drawing::size system_information::double_click_size() {
  return native::system_information::double_click_size();
}

int32_t system_information::double_click_time() {
  return native::system_information::double_click_time();
}

bool system_information::drag_full_windows() {
  return native::system_information::drag_full_windows();
}

xtd::drawing::size system_information::drag_size() {
  return native::system_information::drag_size();
}

xtd::drawing::size system_information::fixed_frame_border_size() {
  return native::system_information::fixed_frame_border_size();
}

int32_t system_information::font_smoothing_contrast() {
  return native::system_information::font_smoothing_contrast();
}

int32_t system_information::font_smoothing_type() {
  return native::system_information::font_smoothing_type();
}

int32_t system_information::horizontal_scroll_bar_height() {
  return 15;
}

int32_t system_information::vertical_scroll_bar_width() {
  return 15;
}
