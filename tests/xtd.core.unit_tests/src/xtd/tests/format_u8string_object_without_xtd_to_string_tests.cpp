#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

struct size_sof {
  int w = 0;
  int h = 0;
  
  friend std::ostream& operator << (std::ostream& os, const size_sof& value) {return os << string::format("({}, {})", value.w, value.h);}
};

namespace xtd::tests {
  class test_class_(format_u8string_object_without_xtd_to_string_tests) {
    auto test_method_(format_location_with_default_argument) {
      assert::are_equal("(42, 24)", format(u8"{0}", ::size_sof {42, 24}));
    }
    
    auto test_method_(format_location_with_left_alignment) {
      assert::are_equal("  (42, 24)", format(u8"{0,10}", ::size_sof {42, 24}));
    }
    
    auto test_method_(format_location_with_right_alignment) {
      assert::are_equal("(42, 24)  ", format(u8"{0,-10}", ::size_sof {42, 24}));
    }
    
    auto test_method_(format_location_with_zero_alignment) {
      assert::are_equal("(42, 24)", format(u8"{0,0}", ::size_sof {42, 24}));
    }
    
    auto test_method_(format_location_with_invalid_argument) {
      assert::are_equal("(42, 24)", format(u8"{0:G}", ::size_sof {42, 24}));
    }
  };
}
