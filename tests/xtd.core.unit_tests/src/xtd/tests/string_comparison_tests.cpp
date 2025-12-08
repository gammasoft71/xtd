#include <xtd/string_comparison>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_comparison_tests) {
    auto test_method_(current_culture) {
      assert::are_equal(0, enum_object<>::to_int32(string_comparison::current_culture));
      assert::are_equal("current_culture", enum_object<>::to_string(string_comparison::current_culture));
      assert::are_equal(string_comparison::current_culture, enum_object<>::parse<string_comparison>("current_culture"));
    }
    
    auto test_method_(current_culture_ignore_case) {
      assert::are_equal(1, enum_object<>::to_int32(string_comparison::current_culture_ignore_case));
      assert::are_equal("current_culture_ignore_case", enum_object<>::to_string(string_comparison::current_culture_ignore_case));
      assert::are_equal(string_comparison::current_culture_ignore_case, enum_object<>::parse<string_comparison>("current_culture_ignore_case"));
    }
    
    auto test_method_(invariant_culture) {
      assert::are_equal(2, enum_object<>::to_int32(string_comparison::invariant_culture));
      assert::are_equal("invariant_culture", enum_object<>::to_string(string_comparison::invariant_culture));
      assert::are_equal(string_comparison::invariant_culture, enum_object<>::parse<string_comparison>("invariant_culture"));
    }
    
    auto test_method_(invariant_culture_ignore_case) {
      assert::are_equal(3, enum_object<>::to_int32(string_comparison::invariant_culture_ignore_case));
      assert::are_equal("invariant_culture_ignore_case", enum_object<>::to_string(string_comparison::invariant_culture_ignore_case));
      assert::are_equal(string_comparison::invariant_culture_ignore_case, enum_object<>::parse<string_comparison>("invariant_culture_ignore_case"));
    }
    
    auto test_method_(ordinal) {
      assert::are_equal(4, enum_object<>::to_int32(string_comparison::ordinal));
      assert::are_equal("ordinal", enum_object<>::to_string(string_comparison::ordinal));
      assert::are_equal(string_comparison::ordinal, enum_object<>::parse<string_comparison>("ordinal"));
    }
    
    auto test_method_(ordinal_ignore_case) {
      assert::are_equal(5, enum_object<>::to_int32(string_comparison::ordinal_ignore_case));
      assert::are_equal("ordinal_ignore_case", enum_object<>::to_string(string_comparison::ordinal_ignore_case));
      assert::are_equal(string_comparison::ordinal_ignore_case, enum_object<>::parse<string_comparison>("ordinal_ignore_case"));
    }
  };
}

