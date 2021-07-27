#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace {
  class point {
  public:
    int x = 0;
    int y = 0;
  };
  
  template<typename Char>
  std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, const ::point& p) {
    return os << xtd::to_string(p, ustring::empty());
  }
}

namespace xtd {
  template<>
  std::string to_string(const point& p, const std::string& fmt, const std::locale& loc) {
    if (fmt.empty()) return xtd::ustring::format(L"({}, {})", p.x, p.y);
    if (fmt.size() > 1) throw xtd::format_exception("Format can contains only one character.");
    
    switch (fmt[0]) {
      case 'l': return xtd::ustring::format(L"(x={}, y={})", p.x, p.y);
      case 'L': return xtd::ustring::format(L"(X={}, Y={})", p.x, p.y);
      case 'g':
      case 'G': return xtd::ustring::format(L"({}, {})", p.x, p.y);
      default: throw xtd::format_exception("Format invalid argument.");
    }
  }
}

namespace unit_tests {
  class test_class_(test_wstring_object_format) {
  public:
    void test_method_(format_point_with_default_argument) {
      assert::are_equal(L"(42, 24)", xtd::ustring::format(L"{0}", point {42, 24}));
    }
    
    void test_method_(format_point_with_left_alignment) {
      assert::are_equal(L"  (42, 24)", ustring::format(L"{0,10}", point {42, 24}));
    }
    
    void test_method_(format_point_with_right_alignment) {
      assert::are_equal(L"(42, 24)  ", ustring::format(L"{0, -10}", point {42, 24}));
    }
    
    void test_method_(format_point_with_zero_alignment) {
      assert::are_equal(L"(42, 24)", ustring::format(L"{0,0}", point {42, 24}));
    }
    
    void test_method_(format_point_with_general_argument) {
      assert::are_equal(L"(42, 24)", xtd::ustring::format(L"{0:G}", point {42, 24}));
    }
    
    void test_method_(format_point_with_label_argument) {
      assert::are_equal(L"(x=42, y=24)", xtd::ustring::format(L"{0:l}", point {42, 24}));
    }
    
    void test_method_(format_point_with_label_uppercase_argument) {
      assert::are_equal(L"(X=42, Y=24)", xtd::ustring::format(L"{0:L}", point {42, 24}));
    }
    
    void test_method_(format_point_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format(L"{0:, }", point {42, 24});});
    }
  };
}
