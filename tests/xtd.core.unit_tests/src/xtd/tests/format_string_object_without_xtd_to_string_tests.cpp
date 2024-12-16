#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

class size_sof {
public:
  int w = 0;
  int h = 0;
};

template<typename char_t>
std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const ::size_sof& p) {
  return os << "(" << p.w << ", " << p.h << ")";
}

namespace xtd::tests {
  class test_class_(format_string_object_without_xtd_to_string_tests) {
    void test_method_(format_location_with_default_argument) {
      assert::throws<xtd::format_exception>([] {format("{0}", ::size_sof {42, 24});});
    }
    
    void test_method_(format_location_with_left_alignment) {
      assert::throws<xtd::format_exception>([] {string::format("{0,10}", ::size_sof {42, 24});});
    }
    
    void test_method_(format_location_with_right_alignment) {
      assert::throws<xtd::format_exception>([] {string::format("{0, -10}", ::size_sof {42, 24});});
    }
    
    void test_method_(format_location_with_zero_alignment) {
      assert::throws<xtd::format_exception>([] {string::format("{0,0}", ::size_sof {42, 24});});
    }
    
    void test_method_(format_location_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format("{0:G}", ::size_sof {42, 24});});
    }
  };
}
