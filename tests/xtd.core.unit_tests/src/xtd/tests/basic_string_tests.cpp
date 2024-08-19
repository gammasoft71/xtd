#include <xtd/basic_string>
#include <xtd/char16>
#include <xtd/char32>
#include <xtd/char8>
#include <xtd/index_out_of_range_exception.h>
#include <xtd/size_object>
#include <xtd/wchar>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
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
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Aliases
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
      assert::are_equal(typeof_<typename ienumerable<char_t>::iterator>(), typeof_<typename basic_string<char_t>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<typename ienumerable<char_t>::const_iterator>(), typeof_<typename basic_string<char_t>::const_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::reverse_iterator>(), typeof_<typename basic_string<char_t>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_reverse_iterator>(), typeof_<typename basic_string<char_t>::const_reverse_iterator>(), csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                         Fields
    void test_method_(empty_string) {
      assert::is_zero(basic_string<char_t>::empty_string.length(), csf_);
      assert::is_true(basic_string<char_t>::is_empty(basic_string<char_t>::empty_string), csf_);
    }

    void test_method_(npos) {
      assert::are_equal(size_object::max_value, basic_string<char_t>::npos, csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                   Constructors
    void test_method_(default_constructor) {
      auto s = basic_string<char_t> {};
      assert::is_zero(s.length(), csf_);
      assert::is_true(basic_string<char_t>::is_empty(s), csf_);
    }

    void test_method_(constructor_with_basic_string_char) {
      auto s = basic_string<char>("A test string");
      assert::are_equal("A test string", basic_string<char_t>(s), csf_);
      assert::are_equal("A test string", s, csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")), csf_);
    }
    
    void test_method_(constructor_with_basic_string_char16) {
      auto s = basic_string<xtd::char16>(u"A test string");
      assert::are_equal(u"A test string", basic_string<char_t>(s), csf_);
      assert::are_equal(u"A test string", s, csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")), csf_);
    }
    
    void test_method_(constructor_with_basic_string_char32) {
      auto s = basic_string<xtd::char32>(U"A test string");
      assert::are_equal(U"A test string", basic_string<char_t>(s), csf_);
      assert::are_equal(U"A test string", s, csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")), csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_basic_string_char8) {
      auto s = basic_string<xtd::char8>(u8"A test string");
      assert::are_equal(u8"A test string", basic_string<char_t>(s), csf_);
      assert::are_equal(u8"A test string", s, csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")), csf_);
    }
#endif
    
    void test_method_(constructor_with_basic_string_wchar) {
      auto s = basic_string<xtd::wchar>(L"A test string");
      assert::are_equal(L"A test string", basic_string<char_t>(s), csf_);
      assert::are_equal(L"A test string", s, csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")), csf_);
    }

    void test_method_(constructor_with_basic_string_char_and_index) {
      assert::are_equal("string", basic_string<char_t>(basic_string<char>("A test string"), 7), csf_);
      assert::are_equal("g", basic_string<char_t>(basic_string<char>("A test string"), 12), csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char>("A test string"), 13), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char>("A test string"), 14);}, csf_);
    }

    void test_method_(constructor_with_basic_string_char16_and_index) {
      assert::are_equal(u"string", basic_string<char_t>(basic_string<char16>(u"A test string"), 7), csf_);
      assert::are_equal(u"g", basic_string<char_t>(basic_string<char16>(u"A test string"), 12), csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char16>(u"A test string"), 13), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char16>("A test string"), 14);}, csf_);
    }

    void test_method_(constructor_with_basic_string_char32_and_index) {
      assert::are_equal(U"string", basic_string<char_t>(basic_string<char32>(U"A test string"), 7), csf_);
      assert::are_equal(U"g", basic_string<char_t>(basic_string<char32>(U"A test string"), 12), csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char32>(U"A test string"), 13), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char32>(U"A test string"), 14);}, csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_basic_string_char8_and_index) {
      assert::are_equal(u8"string", basic_string<char_t>(basic_string<char8>(u8"A test string"), 7), csf_);
      assert::are_equal(u8"g", basic_string<char_t>(basic_string<char8>(u8"A test string"), 12), csf_);
      assert::is_empty(basic_string<char_t>(basic_string<char8>(u8"A test string"), 13), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char8>(u8"A test string"), 14);}, csf_);
    }
#endif

    void test_method_(constructor_with_basic_string_wchar_and_index) {
      assert::are_equal(L"string", basic_string<char_t>(basic_string<wchar>(L"A test string"), 7), csf_);
      assert::are_equal(L"g", basic_string<char_t>(basic_string<wchar>(L"A test string"), 12), csf_);
      assert::is_empty(basic_string<char_t>(basic_string<wchar>(L"A test string"), 13), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<wchar>(L"A test string"), 14);}, csf_);
    }

    void test_method_(constructor_with_basic_string_char_and_index_and_count) {
      assert::are_equal("str", basic_string<char_t>(basic_string<char>("A test string"), 7, 3), csf_);
      assert::are_equal("string", basic_string<char_t>(basic_string<char>("A test string"), 7, 6), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char>("A test string"), 7, 7);}, csf_);
    }

    void test_method_(constructor_with_basic_string_char16_and_index_and_count) {
      assert::are_equal(u"str", basic_string<char_t>(basic_string<char16>(u"A test string"), 7, 3), csf_);
      assert::are_equal(u"string", basic_string<char_t>(basic_string<char16>(u"A test string"), 7, 6), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char16>(u"A test string"), 7, 7);}, csf_);
    }

    void test_method_(constructor_with_basic_string_char32_and_index_and_count) {
      assert::are_equal(U"str", basic_string<char_t>(basic_string<char32>(U"A test string"), 7, 3), csf_);
      assert::are_equal(U"string", basic_string<char_t>(basic_string<char32>(U"A test string"), 7, 6), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char32>(U"A test string"), 7, 7);}, csf_);
    }

    void test_method_(constructor_with_basic_string_char8_and_index_and_count) {
      assert::are_equal(u8"str", basic_string<char_t>(basic_string<char8>(u8"A test string"), 7, 3), csf_);
      assert::are_equal(u8"string", basic_string<char_t>(basic_string<char8>(u8"A test string"), 7, 6), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<char8>(u8"A test string"), 7, 7);}, csf_);
    }

    void test_method_(constructor_with_basic_string_wchar_and_index_and_count) {
      assert::are_equal(L"str", basic_string<char_t>(basic_string<wchar>(L"A test string"), 7, 3), csf_);
      assert::are_equal(L"string", basic_string<char_t>(basic_string<wchar>(L"A test string"), 7, 6), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string<char_t>(basic_string<wchar>(L"A test string"), 7, 7);}, csf_);
    }

    void test_method_(move_constructor_with_basic_string) {
      auto s = basic_string<char_t>("A test string");
      assert::are_equal("A test string", basic_string<char_t>(std::move(s)), csf_);
      assert::is_empty(s, csf_);
    }

    void test_method_(constructor_with_count_and_char_character) {
      auto s = basic_string<char_t>(10, char {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }

    void test_method_(constructor_with_count_and_char16_character) {
      auto s = basic_string<char_t>(10, char16 {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }

    void test_method_(constructor_with_count_and_char32_character) {
      auto s = basic_string<char_t>(10, char32 {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_count_and_char8_character) {
      auto s = basic_string<char_t>(10, char8 {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }
#endif

    void test_method_(constructor_with_count_and_wchar_character) {
      auto s = basic_string<char_t>(10, wchar {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }

    void test_method_(constructor_with_count_and_char_pointer) {
      auto p = "A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal("A test string\U0001F603", s, csf_);
    }

    void test_method_(constructor_with_count_and_char16_pointer) {
      auto p = u"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(u"A test string\U0001F603", s, csf_);
    }

    void test_method_(constructor_with_count_and_char32_pointer) {
      auto p = U"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(U"A test string\U0001F603", s, csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_count_and_char8_pointer) {
      auto p = u8"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(u8"A test string\U0001F603", s, csf_);
    }
#endif

    void test_method_(constructor_with_count_and_wchar_pointer) {
      auto p = L"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(L"A test string\U0001F603", s, csf_);
    }

    void test_method_(constructor_with_count_and_char_pointer_and_count) {
      auto p = "A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal("A test", s, csf_);
    }

    void test_method_(constructor_with_count_and_char16_pointer_and_count) {
      auto p = u"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(u"A test", s, csf_);
    }
    
    void test_method_(constructor_with_count_and_char32_pointer_and_count) {
      auto p = U"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(U"A test", s, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_count_and_char8_pointer_and_count) {
      auto p = u8"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(u8"A test", s, csf_);
    }
#endif
    
    void test_method_(constructor_with_count_and_wchar_pointer_and_count) {
      auto p = L"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(L"A test", s, csf_);
    }

    void test_method_(constructor_with_std_basic_string_char) {
      assert::are_equal("A test string", basic_string<char_t>(std::basic_string<char>("A test string")), csf_);
    }

    void test_method_(constructor_with_std_basic_string_char16) {
      assert::are_equal(u"A test string", basic_string<char_t>(std::basic_string<char16>(u"A test string")), csf_);
    }

    void test_method_(constructor_with_std_basic_string_char32) {
      assert::are_equal(U"A test string", basic_string<char_t>(std::basic_string<char32>(U"A test string")), csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_std_basic_string_char8) {
      assert::are_equal(u8"A test string", basic_string<char_t>(std::basic_string<char8>(u8"A test string")), csf_);
    }
#endif

    void test_method_(constructor_with_std_basic_string_wchar) {
      assert::are_equal(L"A test string", basic_string<char_t>(std::basic_string<wchar>(L"A test string")), csf_);
    }

    void test_method_(constructor_with_first_and_last) {
      auto s = std::string("A test string");
      assert::are_equal("test string", basic_string<char_t>(s.begin() + 2, s.end()), csf_);
    }

    void test_method_(constructor_with_initializer_list_char) {
      assert::are_equal("A test string", basic_string<char_t>(std::initializer_list<char> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}), csf_);
    }

    void test_method_(constructor_with_initializer_list_char16) {
      assert::are_equal(u"A test string", basic_string<char_t>(std::initializer_list<char16> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}), csf_);
    }

    void test_method_(constructor_with_initializer_list_char32) {
      assert::are_equal(U"A test string", basic_string<char_t>(std::initializer_list<char32> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}), csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_initializer_list_char8) {
      assert::are_equal(u8"A test string", basic_string<char_t>(std::initializer_list<char8> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}), csf_);
    }
#endif

    void test_method_(constructor_with_initializer_list_wchar) {
      assert::are_equal(L"A test string", basic_string<char_t>(std::initializer_list<wchar> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}), csf_);
    }
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                     Properties

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Methods

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                 Static Methods

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                      Operators
    void test_method_(indexer_operator) {
      auto s = basic_string<char_t>("A test string");
      assert::are_equal(char_t {'A'}, s[0], csf_);
      assert::are_equal(char_t {' '}, s[1], csf_);
      assert::are_equal(char_t {'t'}, s[2], csf_);
      assert::are_equal(char_t {'e'}, s[3], csf_);
      assert::are_equal(char_t {'s'}, s[4], csf_);
      assert::are_equal(char_t {'t'}, s[5], csf_);
      assert::are_equal(char_t {' '}, s[6], csf_);
      assert::are_equal(char_t {'s'}, s[7], csf_);
      assert::are_equal(char_t {'t'}, s[8], csf_);
      assert::are_equal(char_t {'r'}, s[9], csf_);
      assert::are_equal(char_t {'i'}, s[10], csf_);
      assert::are_equal(char_t {'n'}, s[11], csf_);
      assert::are_equal(char_t {'g'}, s[12], csf_);
      assert::throws<index_out_of_range_exception>([&]{s[13];}, csf_);
    }

    void test_method_(cast_operator_base_type) {
      auto s = std::basic_string<char_t> {};
      s = basic_string<char_t>("A test string");
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, s, csf_);
    }

    void test_method_(equal_operator_basic_string_char) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char>("A test string");
      s1 = s2;
      assert::are_equal("A test string", s1, csf_);
      assert::are_equal("A test string", s2, csf_);
    }

    void test_method_(equal_operator_basic_string_char16) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char16>(u"A test string");
      s1 = s2;
      assert::are_equal(u"A test string", s1, csf_);
      assert::are_equal(u"A test string", s2, csf_);
    }

    void test_method_(equal_operator_basic_string_char32) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char32>(U"A test string");
      s1 = s2;
      assert::are_equal(U"A test string", s1, csf_);
      assert::are_equal(U"A test string", s2, csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(equal_operator_basic_string_char8) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char8>(u8"A test string");
      s1 = s2;
      assert::are_equal(u8"A test string", s1, csf_);
      assert::are_equal(u8"A test string", s2, csf_);
    }
#endif

    void test_method_(equal_operator_basic_string_wchar) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<wchar>(L"A test string");
      s1 = s2;
      assert::are_equal(L"A test string", s1, csf_);
      assert::are_equal(L"A test string", s2, csf_);
    }

    void test_method_(equal_operator_move_basic_string_char) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char>("A test string");
      s1 = std::move(s2);
      assert::are_equal("A test string", s1, csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(equal_operator_move_basic_string_char16) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char16>(u"A test string");
      s1 = std::move(s2);
      assert::are_equal(u"A test string", s1, csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(equal_operator_move_basic_string_char32) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char32>(U"A test string");
      s1 = std::move(s2);
      assert::are_equal(U"A test string", s1, csf_);
      assert::is_empty(s2, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(equal_operator_move_basic_string_char8) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char8>(u8"A test string");
      s1 = std::move(s2);
      assert::are_equal(u8"A test string", s1, csf_);
      assert::is_empty(s2, csf_);
    }
#endif
    
    void test_method_(equal_operator_move_basic_string_wchar) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<wchar>(L"A test string");
      s1 = std::move(s2);
      assert::are_equal(L"A test string", s1, csf_);
      assert::is_empty(s2, csf_);
    }
  };
}
