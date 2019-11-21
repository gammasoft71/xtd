#if defined(__WXMSW__)
#include <Windows.h>
#endif
#include <xtd/forms/native/arranged_direction_window.hpp>
#include <xtd/forms/native/system_information.hpp>

using namespace xtd;
using namespace xtd::forms::native;

int32_t system_information::active_window_tracking_delay() {
  return 0;
}

int32_t system_information::arrange_direction() {
#if defined(__WXMSW__)
  return GetSystemMetrics(SM_ARRANGE) & (ARW_DOWN | ARW_LEFT | ARW_RIGHT | ARW_UP);
#else
  return ARW_LEFT;
#endif
}

int32_t system_information::arrange_starting_position() {
  #if defined(__WXMSW__)
    return GetSystemMetrics(SM_ARRANGE) & (ARW_BOTTOMLEFT | ARW_BOTTOMRIGHT | ARW_HIDE |ARW_TOPLEFT | ARW_TOPRIGHT);
  #else
    return ARW_HIDE;
  #endif
}

int32_t system_information::boot_mode() {
  #if defined(__WXMSW__)
    return GetSystemMetrics(SM_CLEANBOOT);
  #else
    return 0; // mode : 0 = Normal, 1 = Fail Safeand 2 = Fail safe with network.
  #endif
}
