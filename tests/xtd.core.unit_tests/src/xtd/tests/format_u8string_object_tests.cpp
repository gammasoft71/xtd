#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace {
  class point {
  public:
    int x = 0;
    int y = 0;
  };
  
  template<class char_t>
  std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const ::point& p) {
    return os << xtd::to_string(p, string::empty_string);
  }
}

namespace xtd {
  template<>
  std::string to_string(const point& p, const std::string& fmt, const std::locale& loc) {
    if (fmt.empty()) return format("({}, {})", p.x, p.y);
    if (fmt.size() > 1) throw xtd::format_exception("Format can contains only one character.");
    
    switch (fmt[0]) {
      case 'l': return format("(x={}, y={})", p.x, p.y);
      case 'L': return format("(X={}, Y={})", p.x, p.y);
      case 'g':
      case 'G': return format("({}, {})", p.x, p.y);
      default: throw xtd::format_exception("Format invalid argument.");
    }
  }
}

namespace xtd::tests {
#if defined(__xtd__cpp_lib_char8_t)
  class test_class_(format_u8string_object_tests) {
    void test_method_(format_point_with_default_argument) {
      assert::are_equal(u8"(42, 24)", format(u8"{0}", point {42, 24}));
    }
    
    void test_method_(format_point_with_left_alignment) {
      assert::are_equal(u8"  (42, 24)", format(u8"{0,10}", point {42, 24}));
    }
    
    void test_method_(format_point_with_right_alignment) {
      assert::are_equal(u8"(42, 24)  ", format(u8"{0, -10}", point {42, 24}));
    }
    
    void test_method_(format_point_with_zero_alignment) {
      assert::are_equal(u8"(42, 24)", format(u8"{0,0}", point {42, 24}));
    }
    
    void test_method_(format_point_with_general_argument) {
      assert::are_equal(u8"(42, 24)", format(u8"{0:G}", point {42, 24}));
    }
    
    void test_method_(format_point_with_label_argument) {
      assert::are_equal(u8"(x=42, y=24)", format(u8"{0:l}", point {42, 24}));
    }
    
    void test_method_(format_point_with_label_uppercase_argument) {
      assert::are_equal(u8"(X=42, Y=24)", format(u8"{0:L}", point {42, 24}));
    }
    
    void test_method_(format_point_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:, }", point {42, 24});});
    }
  };
#endif
}
