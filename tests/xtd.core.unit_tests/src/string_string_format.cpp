#include <xtd/ustring.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_string_string_format) {
  public:
    void test_method_(format_string_with_default_argument) {
      assert::are_equal("string", ustring::format("{0}", "string"));
    }
    
    void test_method_(format_string_with_left_alignment) {
      assert::are_equal("    string", ustring::format("{0,10}", "string"));
    }
    
    void test_method_(format_string_with_right_alignment) {
      assert::are_equal("string    ", ustring::format("{0, -10}", "string"));
    }
    
    void test_method_(format_string_with_left_alignment_to_zero) {
      assert::are_equal("string", ustring::format("{0,0}", "string"));
    }
    
    void test_method_(format_string_with_invalid_format) {
      assert::are_equal("string", ustring::format("{0:invalid}", "string"));
    }
    
    void test_method_(format_string_with_decimal_format) {
      assert::are_equal("string", ustring::format("{0:D}", "string"));
    }
  };
}
