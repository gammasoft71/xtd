#include <xtd/forms/progress_bar_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(progress_bar_style_tests) {
  public:
    auto test_method_(blocks) {
      assert::are_equal(0, enum_object<>::to_int32(progress_bar_style::blocks));
      assert::are_equal("blocks", enum_object<>::to_string(progress_bar_style::blocks));
      assert::are_equal(progress_bar_style::blocks, enum_object<>::parse<progress_bar_style>("blocks"));
    }
    
    auto test_method_(continuous) {
      assert::are_equal(1, enum_object<>::to_int32(progress_bar_style::continuous));
      assert::are_equal("continuous", enum_object<>::to_string(progress_bar_style::continuous));
      assert::are_equal(progress_bar_style::continuous, enum_object<>::parse<progress_bar_style>("continuous"));
    }
    
    auto test_method_(marquee) {
      assert::are_equal(2, enum_object<>::to_int32(progress_bar_style::marquee));
      assert::are_equal("marquee", enum_object<>::to_string(progress_bar_style::marquee));
      assert::are_equal(progress_bar_style::marquee, enum_object<>::parse<progress_bar_style>("marquee"));
    }
  };
}
