#if defined(_WIN32)
#include <Windows.h>
#endif
#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_system_information) {
  public:
    void test_method_(active_window_tracking_delay) {
      assert::are_equal_(0, system_information::active_window_tracking_delay());
    }

    void test_method_(arrange_direction) {
#if defined(_WIN32)
      assert::are_equal_(static_cast<xtd::forms::arrange_direction>(GetSystemMetrics(SM_ARRANGE) & (ARW_DOWN | ARW_LEFT | ARW_RIGHT | ARW_UP)), system_information::arrange_direction());
#else
      assert::are_equal_(xtd::forms::arrange_direction::left, system_information::arrange_direction());
#endif
    }

    void test_method_(arrange_starting_position) {
#if defined(_WIN32)
      assert::are_equal_(static_cast<xtd::forms::arrange_starting_position>(GetSystemMetrics(SM_ARRANGE) & (ARW_BOTTOMLEFT | ARW_BOTTOMRIGHT | ARW_HIDE |ARW_TOPLEFT | ARW_TOPRIGHT)), system_information::arrange_starting_position());
#else
      assert::are_equal_(xtd::forms::arrange_starting_position::hide, system_information::arrange_starting_position());
#endif
    }

    void test_method_(boot_mode) {
#if defined(_WIN32)
      assert::are_equal_(static_cast<xtd::forms::boot_mode>(GetSystemMetrics(SM_CLEANBOOT)), system_information::boot_mode());
#else
      assert::are_equal_(xtd::forms::boot_mode::normal, system_information::boot_mode());
#endif
    }

    void test_method_(border_3d_size) {
#if defined(_WIN32)
      assert::are_equal_(size(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE)), system_information::border_3d_size());
#else
      assert::are_equal_(size(0, 0), system_information::border_3d_size());
#endif
    }

    void test_method_(border_multiplier_factor) {
#if defined(_WIN32)
      int32_t border_multiplier_factor = 0;
      SystemParametersInfo(SPI_GETBORDER, 0, &border_multiplier_factor, 0);
      assert::are_equal_(border_multiplier_factor, system_information::border_multiplier_factor());
#else
      assert::are_equal_(1, system_information::border_multiplier_factor());
#endif
    }

    void test_method_(border_size) {
#if defined(_WIN32)
      assert::are_equal_(size(GetSystemMetrics(SM_CXBORDER), GetSystemMetrics(SM_CYBORDER)), system_information::border_size());
#else
      assert::are_equal_(size(0, 0), system_information::border_size());
#endif
    }

    void test_method_(caption_button_size) {
#if defined(_WIN32)
      assert::are_equal_(size(GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE)), system_information::caption_button_size());
#else
      assert::are_equal_(size(16, 16), system_information::caption_button_size());
#endif
    }

    void test_method_(caption_height) {
#if defined(_WIN32)
      assert::are_equal_(GetSystemMetrics(SM_CYCAPTION), system_information::caption_height());
#elif defined (__APPLE__)
      form form;
      assert::are_equal_(form.size().height() - form.client_size().height(), system_information::caption_height());
#else
      assert::are_equal_(1, system_information::caption_height());
#endif
    }

    void test_method_(caret_blink_time) {
#if defined(_WIN32)
      assert::are_equal_(GetCaretBlinkTime(), system_information::caret_blink_time());
#else
      assert::are_equal_(530, system_information::caret_blink_time());
#endif
    }

    void test_method_(caret_width) {
#if defined(_WIN32)
      int32_t caret_width = 0;
      SystemParametersInfo(SPI_GETCARETWIDTH, 0, &caret_width, 0);
      assert::are_equal_(caret_width, system_information::caret_width());
#else
      assert::are_equal_(1, system_information::caret_width());
#endif
    }

    void test_method_(computer_name) {
      assert::are_equal_(xtd::environment::machine_name(), system_information::computer_name());
    }
  };
}
