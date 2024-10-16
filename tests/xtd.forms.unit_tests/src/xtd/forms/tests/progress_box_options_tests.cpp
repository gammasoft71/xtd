#include <xtd/forms/progress_box_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(progress_box_options_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(progress_box_options::none));
      assert::are_equal("none", enum_object<>::to_string(progress_box_options::none));
      assert::are_equal(progress_box_options::none, enum_object<>::parse<progress_box_options>("none"));
    }
    
    void test_method_(show_cancel_button) {
      assert::are_equal(1, enum_object<>::to_int32(progress_box_options::show_cancel_button));
      assert::are_equal("show_cancel_button", enum_object<>::to_string(progress_box_options::show_cancel_button));
      assert::are_equal(progress_box_options::show_cancel_button, enum_object<>::parse<progress_box_options>("show_cancel_button"));
    }
    
    void test_method_(show_skip_button) {
      assert::are_equal(2, enum_object<>::to_int32(progress_box_options::show_skip_button));
      assert::are_equal("show_skip_button", enum_object<>::to_string(progress_box_options::show_skip_button));
      assert::are_equal(progress_box_options::show_skip_button, enum_object<>::parse<progress_box_options>("show_skip_button"));
    }
    
    void test_method_(show_elapsed_time) {
      assert::are_equal(4, enum_object<>::to_int32(progress_box_options::show_elapsed_time));
      assert::are_equal("show_elapsed_time", enum_object<>::to_string(progress_box_options::show_elapsed_time));
      assert::are_equal(progress_box_options::show_elapsed_time, enum_object<>::parse<progress_box_options>("show_elapsed_time"));
    }
    
    void test_method_(show_estimated_time) {
      assert::are_equal(8, enum_object<>::to_int32(progress_box_options::show_estimated_time));
      assert::are_equal("show_estimated_time", enum_object<>::to_string(progress_box_options::show_estimated_time));
      assert::are_equal(progress_box_options::show_estimated_time, enum_object<>::parse<progress_box_options>("show_estimated_time"));
    }
    
    void test_method_(show_remaining_time) {
      assert::are_equal(16, enum_object<>::to_int32(progress_box_options::show_remaining_time));
      assert::are_equal("show_remaining_time", enum_object<>::to_string(progress_box_options::show_remaining_time));
      assert::are_equal(progress_box_options::show_remaining_time, enum_object<>::parse<progress_box_options>("show_remaining_time"));
    }
    
    void test_method_(all) {
      assert::are_equal(31, enum_object<>::to_int32(progress_box_options::all));
      assert::are_equal("all", enum_object<>::to_string(progress_box_options::all));
      assert::are_equal(progress_box_options::all, enum_object<>::parse<progress_box_options>("all"));
    }
  };
}
