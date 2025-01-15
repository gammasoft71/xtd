#include <xtd/string_comparer>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_comparer_tests) {
    void test_method_(string_comparer_ordinal_compare_with_strings) {
      assert::is_zero(string_comparer::ordinal().compare(string {""}, string {""}));
      assert::is_zero(string_comparer::ordinal().compare(string {"abc"}, string {"abc"}));
      assert::is_positive(string_comparer::ordinal().compare(string {"abc"}, string {"ABC"}));
      assert::is_negative(string_comparer::ordinal().compare(string {"ABC"}, string {"abc"}));
      assert::is_positive(string_comparer::ordinal().compare(string {"bca"}, string {"abc"}));
      assert::is_negative(string_comparer::ordinal().compare(string {"abc"}, string {"bca"}));
    }

    void test_method_(string_comparer_ordinal_ignore_case_compare_with_strings) {
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {""}, string {""}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"abc"}, string {"abc"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"abc"}, string {"ABC"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"ABC"}, string {"abc"}));
      assert::is_positive(string_comparer::ordinal_ignore_case().compare(string {"bca"}, string {"abc"}));
      assert::is_negative(string_comparer::ordinal_ignore_case().compare(string {"abc"}, string {"bca"}));
    }
  };
}
