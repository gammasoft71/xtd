#include <xtd/string_comparison.h>
#include <xtd/tunit/assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_comparison_tests) {
  public:
    void test_method_(ordinal) {
      assert::are_equal(0, enum_object<>::to_int32(string_comparison::ordinal), csf_);
      assert::are_equal("ordinal", enum_object<>::to_string(string_comparison::ordinal), csf_);
      assert::are_equal(string_comparison::ordinal, enum_object<>::parse<string_comparison>("ordinal"), csf_);
    }
    
    void test_method_(ordinal_ignore_case) {
      assert::are_equal(1, enum_object<>::to_int32(string_comparison::ordinal_ignore_case), csf_);
      assert::are_equal("ordinal_ignore_case", enum_object<>::to_string(string_comparison::ordinal_ignore_case), csf_);
      assert::are_equal(string_comparison::ordinal_ignore_case, enum_object<>::parse<string_comparison>("ordinal_ignore_case"), csf_);
    }
  };
}

