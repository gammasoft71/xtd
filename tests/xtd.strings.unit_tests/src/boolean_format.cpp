#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_boolean_format) {
  public:
    void test_method_(string_format_boolean_false_with_default_argument) {
      assert::are_equal("false", strings::format("{0}", false));
    }
    
    void test_method_(string_format_boolean_true_with_default_argument) {
      assert::are_equal("true", strings::format("{0}", true));
    }
    
    void test_method_(string_format_boolean_false_with_left_alignment) {
      assert::are_equal("     false", strings::format("{0,10}", false));
    }
    
    void test_method_(string_format_boolean_true_with_left_alignment) {
      assert::are_equal("      true", strings::format("{0,10}", true));
    }
    
    void test_method_(string_format_boolean_false_with_right_alignment) {
      assert::are_equal("false     ", strings::format("{0, -10}", false));
    }
    
    void test_method_(string_format_boolean_true_with_right_alignment) {
      assert::are_equal("true      ", strings::format("{0, -10}", true));
    }
    
    void test_method_(string_format_boolean_false_with_left_alignment_to_zero) {
      assert::are_equal("false", strings::format("{0,0}", false));
    }
    
    void test_method_(string_format_boolean_true_with_left_alignment_zero) {
      assert::are_equal("true", strings::format("{0,0}", true));
    }
  };
}
