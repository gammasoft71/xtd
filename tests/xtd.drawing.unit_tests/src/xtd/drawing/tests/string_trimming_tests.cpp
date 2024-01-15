#include <xtd/drawing/string_trimming>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(string_trimming_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(string_trimming::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(string_trimming::none), csf_);
      assert::are_equal(string_trimming::none, enum_object<>::parse<string_trimming>("none"), csf_);
    }
    
    void test_method_(character) {
      assert::are_equal(1, enum_object<>::to_int32(string_trimming::character), csf_);
      assert::are_equal("character", enum_object<>::to_string(string_trimming::character), csf_);
      assert::are_equal(string_trimming::character, enum_object<>::parse<string_trimming>("character"), csf_);
    }
    
    void test_method_(word) {
      assert::are_equal(2, enum_object<>::to_int32(string_trimming::word), csf_);
      assert::are_equal("word", enum_object<>::to_string(string_trimming::word), csf_);
      assert::are_equal(string_trimming::word, enum_object<>::parse<string_trimming>("word"), csf_);
    }
    
    void test_method_(ellipsis_character) {
      assert::are_equal(3, enum_object<>::to_int32(string_trimming::ellipsis_character), csf_);
      assert::are_equal("ellipsis_character", enum_object<>::to_string(string_trimming::ellipsis_character), csf_);
      assert::are_equal(string_trimming::ellipsis_character, enum_object<>::parse<string_trimming>("ellipsis_character"), csf_);
    }
    
    void test_method_(ellipsis_word) {
      assert::are_equal(4, enum_object<>::to_int32(string_trimming::ellipsis_word), csf_);
      assert::are_equal("ellipsis_word", enum_object<>::to_string(string_trimming::ellipsis_word), csf_);
      assert::are_equal(string_trimming::ellipsis_word, enum_object<>::parse<string_trimming>("ellipsis_word"), csf_);
    }
    
    void test_method_(ellipsis_path) {
      assert::are_equal(5, enum_object<>::to_int32(string_trimming::ellipsis_path), csf_);
      assert::are_equal("ellipsis_path", enum_object<>::to_string(string_trimming::ellipsis_path), csf_);
      assert::are_equal(string_trimming::ellipsis_path, enum_object<>::parse<string_trimming>("ellipsis_path"), csf_);
    }
  };
}
