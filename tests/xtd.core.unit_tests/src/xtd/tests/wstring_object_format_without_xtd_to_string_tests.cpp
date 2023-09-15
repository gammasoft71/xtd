#include <xtd/ustring>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

class size_wsof {
public:
  int w = 0;
  int h = 0;
};

template<typename char_t>
std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const ::size_wsof& p) {
  return os << "(" << p.w << ", " << p.h << ")";
}

namespace xtd::tests {
  class test_class_(wstring_object_format_without_xtd_to_string_tests) {
  public:
    void test_method_(format_location_with_default_argument) {
      assert::are_equal(L"(42, 24)", xtd::ustring::format(L"{0}", ::size_wsof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_left_alignment) {
      assert::are_equal(L"  (42, 24)", ustring::format(L"{0,10}", ::size_wsof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_right_alignment) {
      assert::are_equal(L"(42, 24)  ", ustring::format(L"{0, -10}", ::size_wsof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_zero_alignment) {
      assert::are_equal(L"(42, 24)", ustring::format(L"{0,0}", ::size_wsof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::ustring::format(L"{0:G}", ::size_wsof {42, 24});}, csf_);
    }
  };
}
