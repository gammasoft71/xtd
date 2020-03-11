#include <wx/settings.h>
#include <wx/frame.h>
#if defined(__WXMSW__)
#include <Windows.h>
#endif
#include <xtd/forms/native/arranged_direction_window.h>
#include <xtd/forms/native/system_information.h>

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

xtd::drawing::size system_information::border_3d_size() {
#if defined(__WXMSW__)
  return {wxSystemSettings::GetMetric(wxSystemMetric::wxSYS_EDGE_X), wxSystemSettings::GetMetric(wxSystemMetric::wxSYS_EDGE_Y)};
#else
  return {0, 0};
#endif
}

int32_t system_information::border_multiplier_factor() {
#if defined(__WXMSW__)
  int32_t value;
  SystemParametersInfo(SPI_GETBORDER, 0, &value, 0);
  return value;
#else
  return 1;
#endif
}

xtd::drawing::size system_information::border_size() {
#if defined(__WXMSW__)
  return {wxSystemSettings::GetMetric(wxSystemMetric::wxSYS_BORDER_X), wxSystemSettings::GetMetric(wxSystemMetric::wxSYS_BORDER_Y)};
#else
  return {0, 0};
#endif
}

xtd::drawing::size system_information::caption_button_size() {
#if defined(__WXMSW__)
  return {GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE)};
#else
  return {16, 16};
#endif
}

int32_t system_information::caption_height() {
#if defined(__WXMSW__)
  return wxSystemSettings::GetMetric(wxSystemMetric::wxSYS_CAPTION_Y);
#elif defined(__WXOSX__)
  // return 22;
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, wxEmptyString);
  int height = frame->GetSize().GetHeight() - frame->GetClientSize().GetHeight();
  frame->Destroy();
  return height;
#else
  return 1;
#endif
}

int32_t system_information::caret_blink_time() {
#if defined(__WXMSW__)
  return GetCaretBlinkTime();
#else
  return 530;
#endif
}

int32_t system_information::caret_width() {
#if defined(__WXMSW__)
  int32_t value;
  SystemParametersInfo(SPI_GETCARETWIDTH, 0, &value, 0);
  return value;
#else
  return 1;
#endif
}

std::string system_information::computer_name() {
  return xtd::environment::machine_name();;
}

xtd::drawing::size system_information::cursor_size() {
#if defined(__WXMSW__)
  return {wxSystemSettings::GetMetric(wxSYS_CURSOR_X), wxSystemSettings::GetMetric(wxSYS_CURSOR_Y)};
#else
  return {32, 32};
#endif
}

bool system_information::dbcs_enabled() {
#if defined(__WXMSW__)
  return GetSystemMetrics(SM_DBCSENABLED);
#else
  return false;
#endif
}

bool system_information::debug_os() {
#if defined(__WXMSW__)
  return GetSystemMetrics(SM_DEBUG);
#else
  return false;
#endif
}

xtd::drawing::size system_information::double_click_size() {
#if defined(__WXMSW__)
  return {wxSystemSettings::GetMetric(wxSYS_DCLICK_X), wxSystemSettings::GetMetric(wxSYS_DCLICK_Y)};
#else
  return {4, 4};
#endif
}

int32_t system_information::double_click_time() {
  return wxSystemSettings::GetMetric(wxSYS_DCLICK_MSEC);
}

bool system_information::drag_full_windows() {
#if defined(__WXMSW__)
  int32_t drag_full_windows;
  SystemParametersInfo(SPI_GETDRAGFULLWINDOWS, 0, &drag_full_windows, 0);
  return drag_full_windows;
#else
  return true;
#endif
}

xtd::drawing::size system_information::drag_size() {
#if defined(__WXMSW__)
  return {wxSystemSettings::GetMetric(wxSYS_DRAG_X), wxSystemSettings::GetMetric(wxSYS_DRAG_Y)};
#else
  return {4, 4};
#endif
}

xtd::drawing::size system_information::fixed_frame_border_size() {
#if defined(__WXMSW__)
  return {wxSystemSettings::GetMetric(wxSYS_FRAMESIZE_X), wxSystemSettings::GetMetric(wxSYS_FRAMESIZE_Y)};
#else
  return {0, 0};
#endif
}

int32_t system_information::font_smoothing_contrast() {
#if defined(__WXMSW__)
  int32_t font_smoothing_contrast;
  SystemParametersInfo(SPI_GETFONTSMOOTHINGCONTRAST, 0, &font_smoothing_contrast, 0);
  return font_smoothing_contrast;
#else
  return 1200;
#endif
}

int32_t system_information::font_smoothing_type() {
#if defined(__WXMSW__)
  int32_t font_smoothing_type;
  SystemParametersInfo(SPI_GETFONTSMOOTHINGTYPE, 0, &font_smoothing_type, 0);
  return font_smoothing_type;
#else
  return 2;
#endif
}
