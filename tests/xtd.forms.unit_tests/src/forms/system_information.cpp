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
      assert::are_equal_(static_cast<xtd::forms::boot_mode>(GetSystemMetrics(SM_CLEANBOOT), system_information::boot_mode());
#else
      assert::are_equal_(xtd::forms::boot_mode::normal, system_information::boot_mode());
#endif
    }

    void test_method_(border_3d_size) {
#if defined(_WIN32)
      assert::are_equal_(size(0, 0), system_information::border_3d_size());
#else
      assert::are_equal_(size(0, 0), system_information::border_3d_size());
#endif
    }
  };
}
