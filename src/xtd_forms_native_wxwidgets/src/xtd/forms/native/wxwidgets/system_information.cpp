#include <wx/settings.h>
#include <wx/frame.h>
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

ustring system_information::computer_name() {
  return xtd::environment::machine_name();;
}
