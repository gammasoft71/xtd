#include <xtd/strings.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

class size {
public:
  int w = 0;
  int h = 0;
};

template<typename Char>
std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, const ::size& p) {
  return os << "(" << p.w << ", " << p.h << ")";
}

namespace unit_tests {
  class test_class_(test_string_object_format_without_xtd_to_string) {
  public:
    void test_method_(format_location_with_default_argument) {
      assert::are_equal("(42, 24)", xtd::strings::format("{0}", ::size {42, 24}));
    }
    
    void test_method_(format_location_with_left_alignment) {
      assert::are_equal("  (42, 24)", strings::format("{0,10}", ::size {42, 24}));
    }
    
    void test_method_(format_location_with_right_alignment) {
      assert::are_equal("(42, 24)  ", strings::format("{0, -10}", ::size {42, 24}));
    }
    
    void test_method_(format_location_with_zero_alignment) {
      assert::are_equal("(42, 24)", strings::format("{0,0}", ::size {42, 24}));
    }

    void test_method_(format_location_with_invalid_argument) {
      assert::throws<std::invalid_argument>([]{xtd::strings::format("{0:G}", ::size {42, 24});});
    }
  };
}
