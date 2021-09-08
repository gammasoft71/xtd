#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

class size_sof {
public:
  int w = 0;
  int h = 0;
};

template<typename char_t>
std::basic_ostream<char_t>& operator<<(std::basic_ostream<char_t>& os, const ::size_sof& p) {
  return os << "(" << p.w << ", " << p.h << ")";
}

namespace unit_tests {
  class test_class_(test_string_object_format_without_xtd_to_string) {
  public:
    void test_method_(format_location_with_default_argument) {
      assert::are_equal("(42, 24)", xtd::ustring::format("{0}", ::size_sof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_left_alignment) {
      assert::are_equal("  (42, 24)", ustring::format("{0,10}", ::size_sof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_right_alignment) {
      assert::are_equal("(42, 24)  ", ustring::format("{0, -10}", ::size_sof {42, 24}), csf_);
    }
    
    void test_method_(format_location_with_zero_alignment) {
      assert::are_equal("(42, 24)", ustring::format("{0,0}", ::size_sof {42, 24}), csf_);
    }

    void test_method_(format_location_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format("{0:G}", ::size_sof {42, 24});}, csf_);
    }
  };
}
