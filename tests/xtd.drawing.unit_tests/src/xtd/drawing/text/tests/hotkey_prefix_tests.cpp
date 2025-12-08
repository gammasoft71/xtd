#include <xtd/drawing/text/hotkey_prefix>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::text;
using namespace xtd::tunit;

namespace xtd::drawing::text::tests {
  class test_class_(hotkey_prefix_tests) {
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(hotkey_prefix::none));
      assert::are_equal("none", enum_object<>::to_string(hotkey_prefix::none));
      assert::are_equal(hotkey_prefix::none, enum_object<>::parse<hotkey_prefix>("none"));
    }
    
    auto test_method_(show) {
      assert::are_equal(1, enum_object<>::to_int32(hotkey_prefix::show));
      assert::are_equal("show", enum_object<>::to_string(hotkey_prefix::show));
      assert::are_equal(hotkey_prefix::show, enum_object<>::parse<hotkey_prefix>("show"));
    }
    
    auto test_method_(hide) {
      assert::are_equal(2, enum_object<>::to_int32(hotkey_prefix::hide));
      assert::are_equal("hide", enum_object<>::to_string(hotkey_prefix::hide));
      assert::are_equal(hotkey_prefix::hide, enum_object<>::parse<hotkey_prefix>("hide"));
    }
  };
}
