#include <xtd/basic_string>
#include <xtd/char16>
#include <xtd/char32>
#include <xtd/char8>
#include <xtd/size_object>
#include <xtd/wchar>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  template <typename value_t>
  class basic_string_tests;

  test_class_attribute<basic_string_tests<char>> basic_string_tests_class_char_attr {"basic_string_tests<char>"};
  test_class_attribute<basic_string_tests<char16>> basic_string_tests_class_char16_attr {"basic_string_tests<char16>"};
  test_class_attribute<basic_string_tests<char32>> basic_string_tests_class_char32_attr {"basic_string_tests<char32>"};
#if defined(__xtd__cpp_lib_char8_t)
  test_class_attribute<basic_string_tests<char8>> basic_string_tests_class_char8_attr {"basic_string_tests<char8>"};
#endif
  test_class_attribute<basic_string_tests<wchar>> basic_string_tests_class_wchar_attr {"basic_string_tests<wchar>"};

  template <typename char_t>
  class basic_string_tests : public test_class {
  public:
    void test_method_(base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_<typename basic_string<char_t>::base_type>(), csf_);
    }
    
    void test_method_(traits_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::traits_type>(), typeof_<typename basic_string<char_t>::traits_type>(), csf_);
    }
    
    void test_method_(value_type) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<char_t>(), typeof_<typename basic_string<char_t>::value_type>(), csf_);
    }
    
    void test_method_(allocator_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::allocator_type>(), typeof_<typename basic_string<char_t>::allocator_type>(), csf_);
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::size_type>(), typeof_<typename basic_string<char_t>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::difference_type>(), typeof_<typename basic_string<char_t>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<char_t&>(), typeof_<typename basic_string<char_t>::reference>(), csf_);
    }
    
    void test_method_(const_reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<const char_t&>(), typeof_<typename basic_string<char_t>::const_reference>(), csf_);
    }
    
    void test_method_(pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<char_t*>(), typeof_<typename basic_string<char_t>::pointer>(), csf_);
    }
    
    void test_method_(const_pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<const char_t*>(), typeof_<typename basic_string<char_t>::const_pointer>(), csf_);
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::iterator>(), typeof_<typename basic_string<char_t>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_iterator>(), typeof_<typename basic_string<char_t>::const_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::reverse_iterator>(), typeof_<typename basic_string<char_t>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_reverse_iterator>(), typeof_<typename basic_string<char_t>::const_reverse_iterator>(), csf_);
    }

    void test_method_(empty_string) {
      assert::is_zero(basic_string<char_t>::empty_string.length(), csf_);
      assert::is_true(basic_string<char_t>::is_empty(basic_string<char_t>::empty_string), csf_);
    }

    void test_method_(npos) {
      assert::are_equal(size_object::max_value, basic_string<char_t>::npos, csf_);
    }

    void test_method_(default_constructor) {
      auto s = basic_string<char_t> {};
      assert::is_zero(s.length(), csf_);
      assert::is_true(basic_string<char_t>::is_empty(s), csf_);
    }

    void test_method_(constructor_with_count_and_character) {
      auto s = basic_string<char_t>(10, '*');
      assert::are_equal(10_z, s.length(), csf_);
      assert::is_false(basic_string<char_t>::is_empty(s), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal('*', s[index], csf_);
    }

    void test_method_(constructor_with_count_and_char_character) {
      auto s = basic_string<char_t>(10, char {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      assert::is_false(basic_string<char_t>::is_empty(s), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal('*', s[index], csf_);
    }

    void test_method_(constructor_with_count_and_char16_character) {
      auto s = basic_string<char_t>(10, char16 {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      assert::is_false(basic_string<char_t>::is_empty(s), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal('*', s[index], csf_);
    }

    void test_method_(constructor_with_count_and_char32_character) {
      auto s = basic_string<char_t>(10, char32 {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      assert::is_false(basic_string<char_t>::is_empty(s), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal('*', s[index], csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_count_and_char8_character) {
      auto s = basic_string<char_t>(10, char8 {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      assert::is_false(basic_string<char_t>::is_empty(s), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal('*', s[index], csf_);
    }
#endif

    void test_method_(constructor_with_count_and_wchar_character) {
      auto s = basic_string<char_t>(10, wchar {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      assert::is_false(basic_string<char_t>::is_empty(s), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal('*', s[index], csf_);
    }

    void test_method_(constructor_with_basic_string_and_index) {
      auto s = basic_string<char_t>(basic_string<char_t>("Hello, World"), 7);
      collection_assert::are_equal({'W', 'o', 'r', 'l', 'd'},  s, csf_);
    }
  };
}
