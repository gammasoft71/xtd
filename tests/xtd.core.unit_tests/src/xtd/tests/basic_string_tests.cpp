#include <xtd/basic_string>
#include <xtd/argument_exception>
#include <xtd/char16>
#include <xtd/char32>
#include <xtd/char8>
#include <xtd/argument_out_of_range_exception>
#include <xtd/environment>
#include <xtd/index_out_of_range_exception>
#include <xtd/size_object>
#include <xtd/wchar>
#include <xtd/collections/generic/list>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <sstream>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  template<class value_t>
  class basic_string_tests;

  test_class_attribute<basic_string_tests<char>> basic_string_tests_class_char_attr {"basic_string_tests<char>"};
  test_class_attribute<basic_string_tests<char16>> basic_string_tests_class_char16_attr {"basic_string_tests<char16>"};
  test_class_attribute<basic_string_tests<char32>> basic_string_tests_class_char32_attr {"basic_string_tests<char32>"};
#if defined(__xtd__cpp_lib_char8_t)
  test_class_attribute<basic_string_tests<char8>> basic_string_tests_class_char8_attr {"basic_string_tests<char8>"};
#endif
  test_class_attribute<basic_string_tests<wchar>> basic_string_tests_class_wchar_attr {"basic_string_tests<wchar>"};

  template<class char_t>
  class basic_string_tests : public test_class {
  public:
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Aliases
    void test_method_(base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_<typename basic_string<char_t>::base_type>());
    }
    
    void test_method_(traits_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::traits_type>(), typeof_<typename basic_string<char_t>::traits_type>());
    }
    
    void test_method_(value_type) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else assert::are_equal(typeof_<char_t>(), typeof_<typename basic_string<char_t>::value_type>());
    }
    
    void test_method_(allocator_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::allocator_type>(), typeof_<typename basic_string<char_t>::allocator_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::size_type>(), typeof_<typename basic_string<char_t>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::difference_type>(), typeof_<typename basic_string<char_t>::difference_type>());
    }
    
    void test_method_(reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else assert::are_equal(typeof_<char_t&>(), typeof_<typename basic_string<char_t>::reference>());
    }
    
    void test_method_(const_reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else assert::are_equal(typeof_<const char_t&>(), typeof_<typename basic_string<char_t>::const_reference>());
    }
    
    void test_method_(pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else assert::are_equal(typeof_<char_t*>(), typeof_<typename basic_string<char_t>::pointer>());
    }
    
    void test_method_(const_pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else assert::are_equal(typeof_<const char_t*>(), typeof_<typename basic_string<char_t>::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<typename ienumerable<char_t>::iterator>(), typeof_<typename basic_string<char_t>::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<typename ienumerable<char_t>::const_iterator>(), typeof_<typename basic_string<char_t>::const_iterator>());
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::reverse_iterator>(), typeof_<typename basic_string<char_t>::reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_reverse_iterator>(), typeof_<typename basic_string<char_t>::const_reverse_iterator>());
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                         Fields
    void test_method_(empty_string) {
      assert::is_zero(basic_string<char_t>::empty_string.length());
      assert::is_true(basic_string<char_t>::is_empty(basic_string<char_t>::empty_string));
      assert::are_equal("", basic_string<char_t>::empty_string);
    }

    void test_method_(npos) {
      assert::are_equal(size_object::max_value, basic_string<char_t>::npos);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                   Constructors
    void test_method_(default_constructor) {
      auto s = basic_string<char_t> {};
      assert::is_zero(s.length());
      assert::is_true(basic_string<char_t>::is_empty(s));
    }

    void test_method_(constructor_with_basic_string_char) {
      auto s = basic_string<char>("A test string");
      assert::are_equal("A test string", basic_string<char_t>(s));
      assert::are_equal("A test string", s);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")));
    }
    
    void test_method_(constructor_with_basic_string_char16) {
      auto s = basic_string<xtd::char16>(u"A test string");
      assert::are_equal(u"A test string", basic_string<char_t>(s));
      assert::are_equal(u"A test string", s);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")));
    }
    
    void test_method_(constructor_with_basic_string_char32) {
      auto s = basic_string<xtd::char32>(U"A test string");
      assert::are_equal(U"A test string", basic_string<char_t>(s));
      assert::are_equal(U"A test string", s);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")));
    }
    
    void test_method_(constructor_with_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<xtd::char8>(u8"A test string");
      assert::are_equal(u8"A test string", basic_string<char_t>(s));
      assert::are_equal(u8"A test string", s);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")));
#endif
    }
    
    void test_method_(constructor_with_basic_string_wchar) {
      auto s = basic_string<xtd::wchar>(L"A test string");
      assert::are_equal(L"A test string", basic_string<char_t>(s));
      assert::are_equal(L"A test string", s);
      assert::is_empty(basic_string<char_t>(basic_string<char_t>("")));
    }

    void test_method_(constructor_with_basic_string_char_and_index) {
      assert::are_equal("string", basic_string<char_t>(basic_string<char>("A test string"), 7));
      assert::are_equal("g", basic_string<char_t>(basic_string<char>("A test string"), 12));
      assert::is_empty(basic_string<char_t>(basic_string<char>("A test string"), 13));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char>("A test string"), 14);});
    }

    void test_method_(constructor_with_basic_string_char16_and_index) {
      assert::are_equal(u"string", basic_string<char_t>(basic_string<char16>(u"A test string"), 7));
      assert::are_equal(u"g", basic_string<char_t>(basic_string<char16>(u"A test string"), 12));
      assert::is_empty(basic_string<char_t>(basic_string<char16>(u"A test string"), 13));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char16>("A test string"), 14);});
    }

    void test_method_(constructor_with_basic_string_char32_and_index) {
      assert::are_equal(U"string", basic_string<char_t>(basic_string<char32>(U"A test string"), 7));
      assert::are_equal(U"g", basic_string<char_t>(basic_string<char32>(U"A test string"), 12));
      assert::is_empty(basic_string<char_t>(basic_string<char32>(U"A test string"), 13));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char32>(U"A test string"), 14);});
    }

    void test_method_(constructor_with_basic_string_char8_and_index) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal(u8"string", basic_string<char_t>(basic_string<char8>(u8"A test string"), 7));
      assert::are_equal(u8"g", basic_string<char_t>(basic_string<char8>(u8"A test string"), 12));
      assert::is_empty(basic_string<char_t>(basic_string<char8>(u8"A test string"), 13));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char8>(u8"A test string"), 14);});
#endif
    }

    void test_method_(constructor_with_basic_string_wchar_and_index) {
      assert::are_equal(L"string", basic_string<char_t>(basic_string<wchar>(L"A test string"), 7));
      assert::are_equal(L"g", basic_string<char_t>(basic_string<wchar>(L"A test string"), 12));
      assert::is_empty(basic_string<char_t>(basic_string<wchar>(L"A test string"), 13));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<wchar>(L"A test string"), 14);});
    }

    void test_method_(constructor_with_basic_string_char_and_index_and_count) {
      assert::are_equal("str", basic_string<char_t>(basic_string<char>("A test string"), 7, 3));
      assert::are_equal("string", basic_string<char_t>(basic_string<char>("A test string"), 7, 6));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char>("A test string"), 7, 7);});
    }

    void test_method_(constructor_with_basic_string_char16_and_index_and_count) {
      assert::are_equal(u"str", basic_string<char_t>(basic_string<char16>(u"A test string"), 7, 3));
      assert::are_equal(u"string", basic_string<char_t>(basic_string<char16>(u"A test string"), 7, 6));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char16>(u"A test string"), 7, 7);});
    }

    void test_method_(constructor_with_basic_string_char32_and_index_and_count) {
      assert::are_equal(U"str", basic_string<char_t>(basic_string<char32>(U"A test string"), 7, 3));
      assert::are_equal(U"string", basic_string<char_t>(basic_string<char32>(U"A test string"), 7, 6));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char32>(U"A test string"), 7, 7);});
    }

    void test_method_(constructor_with_basic_string_char8_and_index_and_count) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal(u8"str", basic_string<char_t>(basic_string<char8>(u8"A test string"), 7, 3));
      assert::are_equal(u8"string", basic_string<char_t>(basic_string<char8>(u8"A test string"), 7, 6));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<char8>(u8"A test string"), 7, 7);});
#endif
    }

    void test_method_(constructor_with_basic_string_wchar_and_index_and_count) {
      assert::are_equal(L"str", basic_string<char_t>(basic_string<wchar>(L"A test string"), 7, 3));
      assert::are_equal(L"string", basic_string<char_t>(basic_string<wchar>(L"A test string"), 7, 6));
      assert::throws<argument_out_of_range_exception>([]{basic_string<char_t>(basic_string<wchar>(L"A test string"), 7, 7);});
    }

    void test_method_(move_constructor_with_basic_string) {
      auto s = basic_string<char_t>("A test string");
      assert::are_equal("A test string", basic_string<char_t>(std::move(s)));
      assert::is_empty(s);
    }

    void test_method_(constructor_with_count_and_char_character) {
      auto s = basic_string<char_t>(10, char {'*'});
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }

    void test_method_(constructor_with_count_and_char16_character) {
      auto s = basic_string<char_t>(10, char16 {'*'});
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }

    void test_method_(constructor_with_count_and_char32_character) {
      auto s = basic_string<char_t>(10, char32 {'*'});
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }

    void test_method_(constructor_with_count_and_char8_character) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t>(10, char8 {'*'});
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
#endif
    }

    void test_method_(constructor_with_count_and_wchar_character) {
      auto s = basic_string<char_t>(10, wchar {'*'});
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }

    void test_method_(constructor_with_char_character_and_count) {
      auto s = basic_string<char_t>(char {'*'}, 10);
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }
    
    void test_method_(constructor_with_char16_character_and_count) {
      auto s = basic_string<char_t>(char16 {'*'}, 10);
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }
    
    void test_method_(constructor_with_char32_character_and_count) {
      auto s = basic_string<char_t>(char32 {'*'}, 10);
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }
    
    void test_method_(constructor_with_char8_character_and_count) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t>(char8 {'*'}, 10);
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
#endif
    }
    
    void test_method_(constructor_with_wchar_character_and_count) {
      auto s = basic_string<char_t>(wchar {'*'}, 10);
      assert::are_equal(10_z, s.length());
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index]);
    }

    void test_method_(constructor_with_count_and_char_pointer) {
      auto p = "A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal("A test string\U0001F603", s);
    }

    void test_method_(constructor_with_count_and_char16_pointer) {
      auto p = u"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(u"A test string\U0001F603", s);
    }

    void test_method_(constructor_with_count_and_char32_pointer) {
      auto p = U"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(U"A test string\U0001F603", s);
    }

    void test_method_(constructor_with_count_and_char8_pointer) {
#if defined(__xtd__cpp_lib_char8_t)
      auto p = u8"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(u8"A test string\U0001F603", s);
#endif
    }

    void test_method_(constructor_with_count_and_wchar_pointer) {
      auto p = L"A test string\U0001F603";
      auto s = basic_string<char_t>(p);
      assert::are_equal(L"A test string\U0001F603", s);
    }

    void test_method_(constructor_with_count_and_char_pointer_and_count) {
      auto p = "A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal("A test", s);
    }

    void test_method_(constructor_with_count_and_char16_pointer_and_count) {
      auto p = u"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(u"A test", s);
    }
    
    void test_method_(constructor_with_count_and_char32_pointer_and_count) {
      auto p = U"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(U"A test", s);
    }
    
    void test_method_(constructor_with_count_and_char8_pointer_and_count) {
#if defined(__xtd__cpp_lib_char8_t)
      auto p = u8"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(u8"A test", s);
#endif
    }
    
    void test_method_(constructor_with_count_and_wchar_pointer_and_count) {
      auto p = L"A test string";
      auto s = basic_string<char_t>(p, 6);
      assert::are_equal(L"A test", s);
    }
    
    void test_method_(constructor_with_std_basic_string_char) {
      assert::are_equal("A test string", basic_string<char_t>(std::basic_string<char>("A test string")));
    }

    void test_method_(constructor_with_std_basic_string_char16) {
      assert::are_equal(u"A test string", basic_string<char_t>(std::basic_string<char16>(u"A test string")));
    }

    void test_method_(constructor_with_std_basic_string_char32) {
      assert::are_equal(U"A test string", basic_string<char_t>(std::basic_string<char32>(U"A test string")));
    }

    void test_method_(constructor_with_std_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal(u8"A test string", basic_string<char_t>(std::basic_string<char8>(u8"A test string")));
#endif
    }

    void test_method_(constructor_with_std_basic_string_wchar) {
      assert::are_equal(L"A test string", basic_string<char_t>(std::basic_string<wchar>(L"A test string")));
    }

    void test_method_(constructor_with_first_and_last) {
      auto s = std::string("A test string");
      assert::are_equal("test string", basic_string<char_t>(s.begin() + 2, s.end()));
    }

    void test_method_(constructor_with_initializer_list_char) {
      assert::are_equal("A test string", basic_string<char_t>(std::initializer_list<char> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}));
    }

    void test_method_(constructor_with_initializer_list_char16) {
      assert::are_equal(u"A test string", basic_string<char_t>(std::initializer_list<char16> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}));
    }

    void test_method_(constructor_with_initializer_list_char32) {
      assert::are_equal(U"A test string", basic_string<char_t>(std::initializer_list<char32> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}));
    }

    void test_method_(constructor_with_initializer_list_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal(u8"A test string", basic_string<char_t>(std::initializer_list<char8> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}));
#endif
    }

    void test_method_(constructor_with_initializer_list_wchar) {
      assert::are_equal(L"A test string", basic_string<char_t>(std::initializer_list<wchar> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}));
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                     Properties
    void test_method_(back) {
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {}.back();});
      assert::are_equal(char_t {'g'}, basic_string<char_t> {"A test string"}.back());
    }
    
    void test_method_(begin) {
      auto s = basic_string<char_t> {"A test string"};
      auto iterator = s.begin();
      assert::are_equal(char_t {'A'}, *iterator++);
      assert::are_equal(char_t {' '}, *iterator++);
      assert::are_equal(char_t {'e'}, *++iterator);
      assert::are_equal(char_t {'e'}, *iterator++);
      assert::are_equal(char_t {'s'}, *iterator);
      assert::are_equal(char_t {'i'}, *(iterator + 6));
    }
    
    void test_method_(c_str) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      assert::is_empty(basic_string<char_t> {}.c_str());
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.c_str());
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else {
        assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string<char_t> {}.c_str()));
        assert::is_empty(basic_string<char_t> {}.c_str());
        assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.c_str());
      }
    }
    
    void test_method_(capacity) {
      assert::is_not_zero(basic_string<char_t> {}.capacity());
    }
    
    void test_method_(cbegin) {
      auto s = basic_string<char_t> {"A test string"};
      auto iterator = s.cbegin();
      assert::are_equal(char_t {'A'}, *iterator++);
      assert::are_equal(char_t {' '}, *iterator++);
      assert::are_equal(char_t {'e'}, *++iterator);
      assert::are_equal(char_t {'e'}, *iterator++);
      assert::are_equal(char_t {'s'}, *iterator);
      assert::are_equal(char_t {'i'}, *(iterator + 6));
    }

    void test_method_(chars) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_(basic_string<char_t> {}.chars()));
      assert::is_empty(basic_string<char_t> {}.chars());
      collection_assert::are_equal(std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.chars());
    }
    
    void test_method_(cend) {
      auto s = basic_string<char_t> {"A test string"};
      auto iterator = s.cend();
      // Attempting to access cend results in undefined behaviour in Windows.
      if (!environment::os_version().is_windows()) assert::throws<index_out_of_range_exception>([&]{ [[maybe_unused]] auto v = *iterator;});
    }
    
    void test_method_(data) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      assert::is_empty(basic_string<char_t> {}.data());
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.data());
      if constexpr(std::is_same<char_t, char8>::value) return;
      else {
        assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string<char_t> {}.data()));
        assert::is_empty(basic_string<char_t> {}.data());
        assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.data());
      }
#else
      assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string<char_t> {}.data()));
      assert::is_empty(basic_string<char_t> {}.data());
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.data());
#endif
    }
    
    void test_method_(empty) {
      assert::is_true(basic_string<char_t> {}.empty());
      assert::is_true(basic_string<char_t>::empty_string.empty());
      assert::is_false(basic_string<char_t> {"A test string"}.empty());
    }
    
    void test_method_(end) {
      auto s = basic_string<char_t> {"A test string"};
      auto iterator = s.end();
      // Attempting to access end results in undefined behaviour in Windows.
      if (!environment::os_version().is_windows()) assert::throws<index_out_of_range_exception>([&]{ [[maybe_unused]] auto v = *iterator;});
    }

    void test_method_(front) {
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {}.front();});
      assert::are_equal(char_t {'A'}, basic_string<char_t> {"A test string"}.front());
    }
    
    void test_method_(length) {
      assert::is_zero(basic_string<char_t> {}.length());
      assert::is_zero(basic_string<char_t>::empty_string.length());
      assert::are_equal(13_z, basic_string<char_t> {"A test string"}.length());
    }
    
    void test_method_(max_size) {
      assert::is_not_zero(basic_string<char_t> {}.max_size());
    }
    
    void test_method_(size) {
      assert::is_zero(basic_string<char_t> {}.size());
      assert::is_zero(basic_string<char_t>::empty_string.size());
      assert::are_equal(13_z, basic_string<char_t> {"A test string"}.size());
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Methods

    void test_method_(at) {
      auto s = basic_string<char_t>("A test string");
      assert::are_equal(char_t {'A'}, s.at(0));
      assert::are_equal(char_t {' '}, s.at(1));
      assert::are_equal(char_t {'t'}, s.at(2));
      assert::are_equal(char_t {'e'}, s.at(3));
      assert::are_equal(char_t {'s'}, s.at(4));
      assert::are_equal(char_t {'t'}, s.at(5));
      assert::are_equal(char_t {' '}, s.at(6));
      assert::are_equal(char_t {'s'}, s.at(7));
      assert::are_equal(char_t {'t'}, s.at(8));
      assert::are_equal(char_t {'r'}, s.at(9));
      assert::are_equal(char_t {'i'}, s.at(10));
      assert::are_equal(char_t {'n'}, s.at(11));
      assert::are_equal(char_t {'g'}, s.at(12));
      assert::throws<index_out_of_range_exception>([&]{s.at(13);});
      assert::throws<index_out_of_range_exception>([&]{basic_string<char_t> {}.at(0);});
    }
    
    void test_method_(compare) {
      assert::is_zero(basic_string<char_t> {""}.compare(""));
      assert::is_zero(basic_string<char_t> {"A test string"}.compare("A test string"));
      assert::is_zero(basic_string<char_t> {"A test string"}.compare(1, 9, "B test strong", 1, 9));
      assert::is_negative(basic_string<char_t> {"A test string"}.compare("B test strong"));
      assert::is_positive(basic_string<char_t> {"B test strong"}.compare("A test string"));
    }
    
    void test_method_(compare_to_object) {
      auto s1 = basic_string<char_t> {"A test string"};
      auto s2 = basic_string<char_t> {"A test string"};
      auto& o1 = static_cast<object&>(s2);
      auto o2 = object {};
      assert::is_zero(s1.compare_to(o1));
      assert::throws<argument_exception>([&] {s1.compare_to(o2);});
    }
    
    void test_method_(compare_to) {
      assert::is_zero(basic_string<char_t> {"A test string"}.compare_to("A test string"));
      assert::is_negative(basic_string<char_t> {"A test string"}.compare_to("B test strong"));
      assert::is_positive(basic_string<char_t> {"B test strong"}.compare_to("A test string"));
    }
    
    void test_method_(contains_value_type) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.contains(char_t {'s'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.contains(char_t {'z'}));
    }
    
    void test_method_(contains_basic_string) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.contains("test"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.contains("tist"));
    }

    void test_method_(ends_with_value_type) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with(char_t {'g'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'G'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'n'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'N'}));
    }

    void test_method_(ends_with_value_type_ingore_case_false) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with(char_t {'g'}, false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'G'}, false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'n'}, false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'N'}, false));
    }

    void test_method_(ends_with_value_type_ingore_case_true) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with(char_t {'g'}, true));
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with(char_t {'G'}, true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'n'}, true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with(char_t {'N'}, true));
    }

    void test_method_(ends_with_basic_string) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("string"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("StRiNg"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("test"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("TeSt"));
    }
    
    void test_method_(ends_with_basic_string_and_ignore_case_false) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("string", false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("StRiNg", false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("test", false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("TeSt", false));
    }
    
    void test_method_(ends_with_basic_string_and_ignore_case_true) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("string", true));
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("StRiNg", true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("test", true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("TeSt", true));
    }
    
    void test_method_(ends_with_basic_string_and_string_comparison_ordinale) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("string", string_comparison::ordinal));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("StRiNg", string_comparison::ordinal));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("test", string_comparison::ordinal));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("TeSt", string_comparison::ordinal));
    }
    
    void test_method_(ends_with_basic_string_and_string_comparison_ordinal_ignore_case) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("string", string_comparison::ordinal_ignore_case));
      assert::are_equal(true, basic_string<char_t> {"A test string"}.ends_with("StRiNg", string_comparison::ordinal_ignore_case));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("test", string_comparison::ordinal_ignore_case));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.ends_with("TeSt", string_comparison::ordinal_ignore_case));
    }

    void test_method_(equals_object) {
      auto s1 = basic_string<char_t> {"A test string"};
      auto s2 = basic_string<char_t> {"A test string"};
      auto& o1 = static_cast<object&>(s2);
      auto o2 = object {};
      assert::is_true(s1.equals(o1));
      assert::is_false(s1.equals(o2));
    }

    void test_method_(equals) {
      assert::is_true(basic_string<char_t> {"A test string"}.equals("A test string"));
      assert::is_false(basic_string<char_t> {"A test string"}.equals("A tEsT sTrInG"));
      assert::is_false(basic_string<char_t> {"A tEsT sTrInG"}.equals("A test string"));
      assert::is_false(basic_string<char_t> {"A test string"}.equals("B test strong"));
      assert::is_false(basic_string<char_t> {"B test strong"}.equals("A test string"));
    }

    void test_method_(equals_with_ignore_case_to_false) {
      assert::is_true(basic_string<char_t> {"A test string"}.equals("A test string", false));
      assert::is_false(basic_string<char_t> {"A test string"}.equals("A tEsT sTrInG", false));
      assert::is_false(basic_string<char_t> {"A tEsT sTrInG"}.equals("A test string", false));
      assert::is_false(basic_string<char_t> {"A test string"}.equals("B test strong", false));
      assert::is_false(basic_string<char_t> {"B test strong"}.equals("A test string", false));
    }

    void test_method_(equals_with_ignore_case_to_true) {
      assert::is_true(basic_string<char_t> {"A test string"}.equals("A test string", true));
      assert::is_true(basic_string<char_t> {"A test string"}.equals("A tEsT sTrInG", true));
      assert::is_true(basic_string<char_t> {"A tEsT sTrInG"}.equals("A test string", true));
      assert::is_false(basic_string<char_t> {"A test string"}.equals("B test strong", true));
      assert::is_false(basic_string<char_t> {"B test strong"}.equals("A test string", true));
    }

    void test_method_(find) {
      assert::are_equal(2_z, basic_string<char_t> {"A test string"}.find("test"));
      assert::are_equal(4_z, basic_string<char_t> {"A test string"}.find(char_t {'s'}));
    }
    
    void test_method_(find_first_of) {
      assert::are_equal(2_z, basic_string<char_t> {"A test string to test"}.find_first_of("tuvw"));
      assert::are_equal(4_z, basic_string<char_t> {"A test string to test"}.find_first_of(char_t {'s'}));
    }
    
    void test_method_(find_first_not_of) {
      assert::are_equal(15_z, basic_string<char_t> {"A test string to test"}.find_first_not_of("Aeginrst "));
      assert::are_equal(1_z, basic_string<char_t> {"A test string to test"}.find_first_not_of(char_t {'A'}));
    }

    void test_method_(find_last_of) {
      assert::are_equal(15_z, basic_string<char_t> {"A test string to test"}.find_last_of("Baco"));
      assert::are_equal(16_z, basic_string<char_t> {"A test string to test"}.find_last_of(char_t {' '}));
    }

    void test_method_(find_last_not_of) {
      assert::are_equal(12_z, basic_string<char_t> {"A test string to test"}.find_last_not_of("eost "));
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.find_last_not_of(char_t {'t'}));
    }

    void test_method_(get_allocator) {
      assert::are_equal(typeof_<typename std::allocator<char_t>>(), typeof_(basic_string<char_t> {"A test string"}.get_allocator()));
    }

    void test_method_(get_base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_(basic_string<char_t> {}.get_base_type()));
      assert::is_empty(basic_string<char_t> {}.get_base_type());
      collection_assert::are_equal(std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string<char_t> {"A test string"}.get_base_type());
    }
    
    void test_method_(get_hash_code) {
      assert::are_equal(basic_string<char_t> {"01234"}.get_hash_code(), basic_string<char_t> {"01234"}.get_hash_code());
      assert::are_not_equal(basic_string<char_t> {"01235"}.get_hash_code(), basic_string<char_t> {"01234"}.get_hash_code());
    }
    
    void test_method_(get_enumerator) {
      auto s = basic_string<char_t> {"A test string"};
      auto r = s;
      
      r = basic_string<char_t>::empty_string;
      auto e = s.get_enumerator();
      while (e.move_next())
        r += e.current() + basic_string<char_t> {", "};
      assert::are_equal("A,  , t, e, s, t,  , s, t, r, i, n, g, ", r);
      
      r = basic_string<char_t>::empty_string;
      for (auto c : s)
        r += c + basic_string<char_t> {", "};
      assert::are_equal("A,  , t, e, s, t,  , s, t, r, i, n, g, ", r);
      
      r = basic_string<char_t>::empty_string;
      for (auto iterator = s.begin(); iterator != s.end(); ++iterator)
        r += *iterator + basic_string<char_t> {", "};
      assert::are_equal("A,  , t, e, s, t,  , s, t, r, i, n, g, ", r);
      
      r = basic_string<char_t>::empty_string;
      for (auto iterator = s.cbegin(); iterator != s.cend(); iterator++)
        r += *iterator + basic_string<char_t> {", "};
      assert::are_equal("A,  , t, e, s, t,  , s, t, r, i, n, g, ", r);
    }
    
    void test_method_(index_of_string) {
      assert::are_equal(2_z, basic_string<char_t> {"A test string to test"}.index_of("test"));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of("tist"));
    }
    
    void test_method_(index_of_string_with_start_index) {
      assert::are_equal(2_z, basic_string<char_t> {"A test string to test"}.index_of("test", 0));
      assert::are_equal(2_z, basic_string<char_t> {"A test string to test"}.index_of("test", 2));
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.index_of("test", 3));
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.index_of("test", 17));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of("test", 18));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of("test", 22);});
    }
    
    void test_method_(index_of_string_with_start_index_and_count) {
      assert::are_equal(2_z, basic_string<char_t> {"A test string to test"}.index_of("test", 1, 6));
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.index_of("test", 3, 18));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of("test", 3, 6));
    }
    
    void test_method_(index_of_value_type) {
      assert::are_equal(4_z, basic_string<char_t> {"A test string to test"}.index_of(char_t {'s'}));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of('z'));
    }
    
    void test_method_(index_of_value_type_with_start_index) {
      assert::are_equal(4_z, basic_string<char_t> {"A test string to test"}.index_of(char_t {'s'}, 0));
      assert::are_equal(7_z, basic_string<char_t> {"A test string to test"}.index_of(char_t {'s'}, 6));
      assert::are_equal(7_z, basic_string<char_t> {"A test string to test"}.index_of(char_t {'s'}, 7));
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.index_of(char_t {'s'}, 19));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of(char_t {'s'}, 20));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of('s', 22);});
    }

    void test_method_(index_of_any) {
      assert::are_equal(2_z, basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 's', 't'}));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}));
    }

    void test_method_(index_of_any_with_start_index) {
      assert::are_equal(7_z, basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 's', 't'}, 6));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}, 6));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 's', 't'}, 22);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}, 22);});
    }

    void test_method_(index_of_any_with_start_index_and_count) {
      assert::are_equal(10_z, basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 'u', 'v'}, 6, 5));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}, 6, 5));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 's', 't'}, 22);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}, 22);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 's', 't'}, 6, 16);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}, 6, 16);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'i', 'o', 's', 't'}, 22, 5);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.index_of_any({'b', 'c', 'h', 'v'}, 22, 5);});
    }
    
    void test_method_(insert) {
      assert::are_equal("Inserted text in a test string", basic_string<char_t> {"a test string"}.insert(0, "Inserted text in "));
      assert::are_equal("A test with inserted text string", basic_string<char_t> {"A test string"}.insert(7, "with inserted text "));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.insert(22, "with inserted text ");});
    }
    
    void test_method_(last_index_of_string) {
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.last_index_of("test"));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of("tist"));
    }
    
    void test_method_(last_index_of_string_with_start_index) {
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.last_index_of("test", 0));
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.last_index_of("test", 16));
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.last_index_of("test", 17));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of("test", 18));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of("test", 22);});
    }
    
    void test_method_(last_index_of_string_with_start_index_and_count) {
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.last_index_of("test", 16, 5));
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.last_index_of("test", 3, 18));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of("test", 18, 3));
    }
    
    void test_method_(last_index_of_value_type) {
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.last_index_of(char_t {'s'}));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of('z'));
    }
    
    void test_method_(last_index_of_value_type_with_start_index) {
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.last_index_of(char_t {'s'}, 0));
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.last_index_of(char_t {'s'}, 16));
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.last_index_of(char_t {'s'}, 17));
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.last_index_of(char_t {'s'}, 19));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of(char_t {'s'}, 20));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of('s', 22);});
    }

    void test_method_(last_index_of_any) {
      assert::are_equal(20_z, basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 's', 't'}));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}));
    }
    
    void test_method_(last_index_of_any_with_start_index) {
      assert::are_equal(20_z, basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 's', 't'}, 6));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}, 6));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 's', 't'}, 22);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}, 22);});
    }
    
    void test_method_(last_index_of_any_with_start_index_and_count) {
      assert::are_equal(10_z, basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 'u', 'v'}, 6, 5));
      assert::are_equal(basic_string<char_t>::npos, basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}, 6, 5));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 's', 't'}, 22);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}, 22);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 's', 't'}, 6, 16);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}, 6, 16);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'i', 'o', 's', 't'}, 22, 5);});
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"A test string to test"}.last_index_of_any({'b', 'c', 'h', 'v'}, 22, 5);});
    }

    void test_method_(pad_left) {
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(0));
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(21));
      assert::are_equal(" A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(22));
      assert::are_equal("          A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(31));
    }
    
    void test_method_(pad_left_with_padding_char) {
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(0, char_t {'*'}));
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(21, char_t {'*'}));
      assert::are_equal("*A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(22, char_t {'*'}));
      assert::are_equal("**********A test string to test", basic_string<char_t> {"A test string to test"}.pad_left(31, char_t {'*'}));
    }
    
    void test_method_(pad_right) {
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_right(0));
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_right(21));
      assert::are_equal("A test string to test ", basic_string<char_t> {"A test string to test"}.pad_right(22));
      assert::are_equal("A test string to test          ", basic_string<char_t> {"A test string to test"}.pad_right(31));
    }
    
    void test_method_(pad_right_with_padding_char) {
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_right(0, char_t {'*'}));
      assert::are_equal("A test string to test", basic_string<char_t> {"A test string to test"}.pad_right(21, char_t {'*'}));
      assert::are_equal("A test string to test*", basic_string<char_t> {"A test string to test"}.pad_right(22, char_t {'*'}));
      assert::are_equal("A test string to test**********", basic_string<char_t> {"A test string to test"}.pad_right(31, char_t {'*'}));
    }
    
    void test_method_(quoted) {
      assert::are_equal("\"A test string to test\"", basic_string<char_t> {"A test string to test"}.quoted());
      auto result = basic_string<char_t> {"\"A test string to test\""}.quoted();
      assert::are_equal("\"\\\"A test string to test\\\"\"", basic_string<char_t> {"\"A test string to test\""}.quoted());
      assert::are_equal("\"A test \\\"string\\\" to test\"", basic_string<char_t> {"A test \"string\" to test"}.quoted());
    }
    
    void test_method_(quoted_with_delimiter) {
      assert::are_equal("$A test string to test$", basic_string<char_t> {"A test string to test"}.quoted('$'));
      assert::are_equal("$\\$A test string to test\\$$", basic_string<char_t> {"$A test string to test$"}.quoted('$'));
      assert::are_equal("$A test \\$string\\$ to test$", basic_string<char_t> {"A test $string$ to test"}.quoted('$'));
    }
    
    void test_method_(quoted_with_delimiter_and_escape) {
      assert::are_equal("$A test string to test$", basic_string<char_t> {"A test string to test"}.quoted('$', '%'));
      assert::are_equal("$%$A test string to test%$$", basic_string<char_t> {"$A test string to test$"}.quoted('$', '%'));
      assert::are_equal("$A test %$string%$ to test$", basic_string<char_t> {"A test $string$ to test"}.quoted('$', '%'));
    }
    
    void test_method_(remove_with_start_index) {
      assert::are_equal("", basic_string<char_t> {"abc123ABC"}.remove(0));
      assert::are_equal("abc", basic_string<char_t> {"abc123ABC"}.remove(3));
      assert::are_equal("abc123ABC", basic_string<char_t> {"abc123ABC"}.remove(9));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"abc123ABC"}.remove(10);});
    }
    
    void test_method_(remove_with_index_and_count) {
      assert::are_equal("abcABC", basic_string<char_t> {"abc123ABC"}.remove(3, 3));
      assert::are_equal("abc", basic_string<char_t> {"abc123ABC"}.remove(3, 6));
      assert::throws<index_out_of_range_exception>([] {basic_string<char_t> {"abc123ABC"}.remove(8, 2);});
    }

    void test_method_(replace_value_type) {
      assert::are_equal("This*is*the*beast*of*the*beast", basic_string<char_t> {"This is the beast of the beast"}.replace(' ', '*'));
      assert::are_equal("This is thE bEast of thE bEast", basic_string<char_t> {"This is the beast of the beast"}.replace('e', 'E'));
    }

    void test_method_(replace_string) {
      assert::are_equal("Thare are the beast of the beast", basic_string<char_t> {"This is the beast of the beast"}.replace("is", "are"));
      assert::are_equal("Th  the beast of the beast", basic_string<char_t> {"This is the beast of the beast"}.replace("is", ""));
      assert::are_equal("This text has\\_unescaped\\_\\_underscores !", basic_string<char_t> {"This text has_unescaped__underscores !"}.replace("_", "\\_"));
    }

    void test_method_(rfind) {
      assert::are_equal(17_z, basic_string<char_t> {"A test string to test"}.rfind("test"));
      assert::are_equal(19_z, basic_string<char_t> {"A test string to test"}.rfind(char_t {'s'}));
    }

    void test_method_(split) {
      assert::are_equal(array<basic_string<char_t>> {}, basic_string<char_t> {""}.split({'+', '-', '='}));
      assert::are_equal(array<basic_string<char_t>> {"a"}, basic_string<char_t> {"a"}.split({'+', '-', '='}));
      assert::are_equal((array<basic_string<char_t>> {"100", "42", "142"}), basic_string<char_t> {"100 42\t142"}.split());
      assert::are_equal((array<basic_string<char_t>> {"100", "42", "142"}), basic_string<char_t> {"100+42=142"}.split({'+', '-', '='}));
      assert::are_equal(array<basic_string<char_t>> {"100+42=142"}, basic_string<char_t> {"100+42=142"}.split({'%', '*'}));
      assert::are_equal(array<basic_string<char_t>> {"100+42=142"}, basic_string<char_t> {"100+42=142"}.split({}));
      assert::are_equal((array<basic_string<char_t>> {"a", "b", "c"}), basic_string<char_t> {"a,b,c"}.split(','));
      assert::are_equal((array<basic_string<char_t>> {"a", "", "", "b", "", "c"}), basic_string<char_t> {"a,,,b,,c"}.split(','));
    }
    
    void test_method_(split_count) {
      assert::are_equal((array<basic_string<char_t>> {"42", " 12, 19"}), basic_string<char_t> {"42, 12, 19"}.split({',', ' '}, 2));
      assert::are_equal((array<basic_string<char_t>> {"42", "", "12", ".19"}), basic_string<char_t> {"42..12..19"}.split({'.'}, 4));
      assert::are_equal(array<basic_string<char_t>> {"Banana"}, basic_string<char_t> {"Banana"}.split({','}, 2));
      assert::are_equal(array<basic_string<char_t>> {"Darb\nSmarba "}, basic_string<char_t> {"Darb\nSmarba "}.split({}, 1));
    }
    
    void test_method_(split_with_string_split_option_remove_empty_entries) {
      assert::are_equal(array<basic_string<char_t>> {"a", "b", "c"}, basic_string<char_t> {"a,,,b,,c"}.split(',', string_split_options::remove_empty_entries));
    }
    
    void test_method_(split_with_string_split_optio_none) {
      assert::are_equal(array<basic_string<char_t>> {"a", "", "", "b", "", "c"}, basic_string<char_t> {"a,,,b,,c"}.split(',', string_split_options::none));
    }

    void test_method_(starts_with_value_type) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with(char_t {'A'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'a'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'B'}));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'b'}));
    }
    
    void test_method_(starts_with_value_type_ingore_case_false) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with(char_t {'A'}, false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'a'}, false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'B'}, false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'b'}, false));
    }
    
    void test_method_(starts_with_value_type_ingore_case_true) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with(char_t {'A'}, true));
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with(char_t {'a'}, true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'B'}, true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with(char_t {'b'}, true));
    }
    
    void test_method_(starts_with_basic_string) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("A test"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a TeSt"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("A string"));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a StRiNg"));
    }
    
    void test_method_(starts_with_basic_string_and_ignore_case_false) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("A test", false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a TeSt", false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("A string", false));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a StRiNg", false));
    }
    
    void test_method_(starts_with_basic_string_and_ignore_case_true) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("A test", true));
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("a TeSt", true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("A string", true));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a StRiNg", true));
    }
    
    void test_method_(starts_with_basic_string_and_string_comparison_ordinale) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("A test", string_comparison::ordinal));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a TeSt", string_comparison::ordinal));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("A string", string_comparison::ordinal));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a StRiNg", string_comparison::ordinal));
    }
    
    void test_method_(starts_with_basic_string_and_string_comparison_ordinal_ignore_case) {
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("A test", string_comparison::ordinal_ignore_case));
      assert::are_equal(true, basic_string<char_t> {"A test string"}.starts_with("a TeSt", string_comparison::ordinal_ignore_case));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("A string", string_comparison::ordinal_ignore_case));
      assert::are_equal(false, basic_string<char_t> {"A test string"}.starts_with("a StRiNg", string_comparison::ordinal_ignore_case));
    }

    void test_method_(substr) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.substr());
    }

    void test_method_(substr_with_start_index) {
      assert::are_equal("test string", basic_string<char_t> {"A test string"}.substr(2));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(14);});
      assert::are_equal("test", basic_string<char_t> {"A test string"}.substr(2, 4));
    }

    void test_method_(substr_with_start_index_and_length) {
      assert::are_equal("test", basic_string<char_t> {"A test string"}.substr(2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(2, 12);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(14, 4);});
    }

    void test_method_(substring_with_start_index) {
      assert::are_equal("test string", basic_string<char_t> {"A test string"}.substring(2));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substring(14);});
      assert::are_equal("test", basic_string<char_t> {"A test string"}.substring(2, 4));
    }
    
    void test_method_(substring_with_start_index_and_length) {
      assert::are_equal("test", basic_string<char_t> {"A test string"}.substring(2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substring(2, 12);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substring(14, 4);});
    }

    void test_method_(to_lower) {
      assert::are_equal("a test string", basic_string<char_t> {"a test string"}.to_lower());
      assert::are_equal("a test string", basic_string<char_t> {"A TEST STRING"}.to_lower());
      assert::are_equal("a test string", basic_string<char_t> {"A tEsT sTrInG"}.to_lower());
      assert::are_equal("a test string", basic_string<char_t> {"A tEsT sTrInG"}.to_lower());
    }

    void test_method_(to_string) {
      auto s = basic_string<char_t> {"A test string"};
      assert::is_instance_of<string>(s.to_string());
      assert::are_equal("A test string", s.to_string());
    }
    
    void test_method_(to_title_case) {
      assert::are_equal("A Test String", basic_string<char_t> {"a test string"}.to_title_case());
      assert::are_equal("A TEST STRING", basic_string<char_t> {"A TEST STRING"}.to_title_case());
      assert::are_equal("A Test String", basic_string<char_t> {"A tEsT sTrInG"}.to_title_case());
      assert::are_equal("A Test String", basic_string<char_t> {"A tEsT sTrInG"}.to_title_case());
    }

    void test_method_(to_u16string) {
      auto s = basic_string<char_t> {"A test string"};
      assert::is_instance_of<u16string>(s.to_u16string());
      assert::are_equal(u"A test string", s.to_u16string());
    }
    
    void test_method_(to_u32string) {
      auto s = basic_string<char_t> {"A test string"};
      assert::is_instance_of<u32string>(s.to_u32string());
      assert::are_equal(U"A test string", s.to_u32string());
    }
    
    void test_method_(to_u8string) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {"A test string"};
      assert::is_instance_of<u8string>(s.to_u8string());
      assert::are_equal(u8"A test string", s.to_u8string());
#endif
    }
    
    void test_method_(to_upper) {
      assert::are_equal("A TEST STRING", basic_string<char_t> {"A TEST STRING"}.to_upper());
      assert::are_equal("A TEST STRING", basic_string<char_t> {"a test string"}.to_upper());
      assert::are_equal("A TEST STRING", basic_string<char_t> {"A tEsT sTrInG"}.to_upper());
      assert::are_equal("A TEST STRING", basic_string<char_t> {"A tEsT sTrInG"}.to_upper());
    }

    void test_method_(to_wstring) {
      auto s = basic_string<char_t> {"A test string"};
      assert::is_instance_of<wstring>(s.to_wstring());
      assert::are_equal(u"A test string", s.to_wstring());
    }
    
    void test_method_(trim) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"A test string "}.trim());
      assert::are_equal("A test string", basic_string<char_t> {" A test string"}.trim());
      assert::are_equal("A test string", basic_string<char_t> {" A test string "}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"  A test string   "}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"   A test string  "}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"A test string\t"}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"\tA test string"}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"\tA test string\t"}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"\t A test string\t\t "}.trim());
      assert::are_equal("A test string", basic_string<char_t> {"\t\t A test string\t "}.trim());
    }
    
    void test_method_(trim_with_trim_char) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string*"}.trim(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"*A test string"}.trim(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"*A test string*"}.trim(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"**A test string***"}.trim(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"***A test string**"}.trim(char_t {'*'}));
    }
    
    void test_method_(trim_with_trim_chars) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string*"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string+"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string-"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"*A test string"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"+A test string"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"-A test string"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"*A test string*"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"+A test string+"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"-A test string-"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"**A test string***"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"++A test string+++"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"--A test string---"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"***A test string**"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"+++A test string++"}.trim({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"---A test string--"}.trim({'*', '+', '-'}));
    }
    
    void test_method_(trim_end) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim_end());
      assert::are_equal("A test string", basic_string<char_t> {"A test string "}.trim_end());
      assert::are_equal(" A test string", basic_string<char_t> {" A test string"}.trim_end());
      assert::are_equal(" A test string", basic_string<char_t> {" A test string "}.trim_end());
      assert::are_equal("  A test string", basic_string<char_t> {"  A test string   "}.trim_end());
      assert::are_equal("   A test string", basic_string<char_t> {"   A test string  "}.trim_end());
      assert::are_equal("A test string", basic_string<char_t> {"A test string\t"}.trim_end());
      assert::are_equal("\tA test string", basic_string<char_t> {"\tA test string"}.trim_end());
      assert::are_equal("\tA test string", basic_string<char_t> {"\tA test string\t"}.trim_end());
      assert::are_equal("\t A test string", basic_string<char_t> {"\t A test string\t\t "}.trim_end());
      assert::are_equal("\t\t A test string", basic_string<char_t> {"\t\t A test string\t "}.trim_end());
    }
    
    void test_method_(trim_end_with_trim_char) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim_end(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string*"}.trim_end(char_t {'*'}));
      assert::are_equal("*A test string", basic_string<char_t> {"*A test string"}.trim_end(char_t {'*'}));
      assert::are_equal("*A test string", basic_string<char_t> {"*A test string*"}.trim_end(char_t {'*'}));
      assert::are_equal("**A test string", basic_string<char_t> {"**A test string***"}.trim_end(char_t {'*'}));
      assert::are_equal("***A test string", basic_string<char_t> {"***A test string**"}.trim_end(char_t {'*'}));
    }
    
    void test_method_(trim_end_with_trim_chars) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim_end({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string*"}.trim_end({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string+"}.trim_end({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"A test string-"}.trim_end({'*', '+', '-'}));
      assert::are_equal("*A test string", basic_string<char_t> {"*A test string"}.trim_end({'*', '+', '-'}));
      assert::are_equal("+A test string", basic_string<char_t> {"+A test string"}.trim_end({'*', '+', '-'}));
      assert::are_equal("-A test string", basic_string<char_t> {"-A test string"}.trim_end({'*', '+', '-'}));
      assert::are_equal("*A test string", basic_string<char_t> {"*A test string*"}.trim_end({'*', '+', '-'}));
      assert::are_equal("+A test string", basic_string<char_t> {"+A test string+"}.trim_end({'*', '+', '-'}));
      assert::are_equal("-A test string", basic_string<char_t> {"-A test string-"}.trim_end({'*', '+', '-'}));
      assert::are_equal("**A test string", basic_string<char_t> {"**A test string***"}.trim_end({'*', '+', '-'}));
      assert::are_equal("++A test string", basic_string<char_t> {"++A test string+++"}.trim_end({'*', '+', '-'}));
      assert::are_equal("--A test string", basic_string<char_t> {"--A test string---"}.trim_end({'*', '+', '-'}));
      assert::are_equal("***A test string", basic_string<char_t> {"***A test string**"}.trim_end({'*', '+', '-'}));
      assert::are_equal("+++A test string", basic_string<char_t> {"+++A test string++"}.trim_end({'*', '+', '-'}));
      assert::are_equal("---A test string", basic_string<char_t> {"---A test string--"}.trim_end({'*', '+', '-'}));
    }
    
    void test_method_(trim_start) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim_start());
      assert::are_equal("A test string ", basic_string<char_t> {"A test string "}.trim_start());
      assert::are_equal("A test string", basic_string<char_t> {" A test string"}.trim_start());
      assert::are_equal("A test string ", basic_string<char_t> {" A test string "}.trim_start());
      assert::are_equal("A test string   ", basic_string<char_t> {"  A test string   "}.trim_start());
      assert::are_equal("A test string  ", basic_string<char_t> {"   A test string  "}.trim_start());
      assert::are_equal("A test string\t", basic_string<char_t> {"A test string\t"}.trim_start());
      assert::are_equal("A test string", basic_string<char_t> {"\tA test string"}.trim_start());
      assert::are_equal("A test string\t", basic_string<char_t> {"\tA test string\t"}.trim_start());
      assert::are_equal("A test string\t\t ", basic_string<char_t> {"\t A test string\t\t "}.trim_start());
      assert::are_equal("A test string\t ", basic_string<char_t> {"\t\t A test string\t "}.trim_start());
    }
    
    void test_method_(trim_start_with_trim_char) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim_start(char_t {'*'}));
      assert::are_equal("A test string*", basic_string<char_t> {"A test string*"}.trim_start(char_t {'*'}));
      assert::are_equal("A test string", basic_string<char_t> {"*A test string"}.trim_start(char_t {'*'}));
      assert::are_equal("A test string*", basic_string<char_t> {"*A test string*"}.trim_start(char_t {'*'}));
      assert::are_equal("A test string***", basic_string<char_t> {"**A test string***"}.trim_start(char_t {'*'}));
      assert::are_equal("A test string**", basic_string<char_t> {"***A test string**"}.trim_start(char_t {'*'}));
    }
    
    void test_method_(trim_start_with_trim_chars) {
      assert::are_equal("A test string", basic_string<char_t> {"A test string"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string*", basic_string<char_t> {"A test string*"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string+", basic_string<char_t> {"A test string+"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string-", basic_string<char_t> {"A test string-"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"*A test string"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"+A test string"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string", basic_string<char_t> {"-A test string"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string*", basic_string<char_t> {"*A test string*"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string+", basic_string<char_t> {"+A test string+"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string-", basic_string<char_t> {"-A test string-"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string***", basic_string<char_t> {"**A test string***"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string+++", basic_string<char_t> {"++A test string+++"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string---", basic_string<char_t> {"--A test string---"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string**", basic_string<char_t> {"***A test string**"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string++", basic_string<char_t> {"+++A test string++"}.trim_start({'*', '+', '-'}));
      assert::are_equal("A test string--", basic_string<char_t> {"---A test string--"}.trim_start({'*', '+', '-'}));
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                 Static Methods
    
    void test_method_(compare_with_string_and_string) {
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {""}, basic_string<char_t>::empty_string));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test string"}));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, basic_string<char_t> {"A test string"}));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A TeSt StRiNg"}));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test strong"}));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, basic_string<char_t> {"A test string"}));
    }
    
    void test_method_(compare_with_basic_string_basic_string_and_ignore_case_to_false) {
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {""}, basic_string<char_t>::empty_string, false));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test string"}, false));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, basic_string<char_t> {"A test string"}, false));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A TeSt StRiNg"}, false));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test strong"}, false));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, basic_string<char_t> {"A test string"}, false));
    }
    
    void test_method_(compare_with_basic_string_basic_string_and_ignore_case_to_true) {
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {""}, basic_string<char_t>::empty_string, true));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test string"}, true));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, basic_string<char_t> {"A test string"}, true));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A TeSt StRiNg"}, true));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test strong"}, true));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, basic_string<char_t> {"A test string"}, true));
    }
    
    void test_method_(compare_with_basic_string_basic_string_and_string_comparison_ordinal) {
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {""}, basic_string<char_t>::empty_string, string_comparison::ordinal));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test string"}, string_comparison::ordinal));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, basic_string<char_t> {"A test string"}, string_comparison::ordinal));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A TeSt StRiNg"}, string_comparison::ordinal));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test strong"}, string_comparison::ordinal));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, basic_string<char_t> {"A test string"}, string_comparison::ordinal));
    }
    
    void test_method_(compare_with_basic_string_basic_string_and_string_comparison_ordinal_ignore_case) {
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {""}, basic_string<char_t>::empty_string, string_comparison::ordinal_ignore_case));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test string"}, string_comparison::ordinal_ignore_case));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, basic_string<char_t> {"A test string"}, string_comparison::ordinal_ignore_case));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A TeSt StRiNg"}, string_comparison::ordinal_ignore_case));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, basic_string<char_t> {"A test strong"}, string_comparison::ordinal_ignore_case));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, basic_string<char_t> {"A test string"}, string_comparison::ordinal_ignore_case));
    }
    
    void test_method_(compare_with_string_index_string_index_and_length) {
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {""}, 0, basic_string<char_t>::empty_string, 0, 0));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {""}, 1, basic_string<char_t>::empty_string, 0, 0);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {""}, 0, basic_string<char_t>::empty_string, 1, 0);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {""}, 0, basic_string<char_t>::empty_string, 0, 1);});

      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 0, basic_string<char_t> {"A test string"}, 0, 13));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 2, basic_string<char_t> {"A test string"}, 2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 13, basic_string<char_t> {"A test string"}, 2, 1);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 2, basic_string<char_t> {"A test string"}, 13, 1);});

      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, 0, basic_string<char_t> {"A test string"}, 0, 13));
      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, 2, basic_string<char_t> {"A test string"}, 2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, 13, basic_string<char_t> {"A test string"}, 2, 1);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A TeSt StRiNg"}, 2, basic_string<char_t> {"A test string"}, 13, 1);});

      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 0, basic_string<char_t> {"A TeSt StRiNg"}, 0, 13));
      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 2, basic_string<char_t> {"A TeSt StRiNg"}, 2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 13, basic_string<char_t> {"A TeSt StRiNg"}, 2, 1);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 2, basic_string<char_t> {"A TeSt StRiNg"}, 13, 1);});

      assert::is_negative(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 0, basic_string<char_t> {"A test strong"}, 0, 13));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 2, basic_string<char_t> {"A test strong"}, 2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 13, basic_string<char_t> {"A test strong"}, 2, 1);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test string"}, 2, basic_string<char_t> {"A test strong"}, 13, 1);});

      assert::is_positive(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, 0, basic_string<char_t> {"A test string"}, 0, 13));
      assert::is_zero(basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, 2, basic_string<char_t> {"A test string"}, 2, 4));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, 13, basic_string<char_t> {"A test string"}, 2, 1);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::compare(basic_string<char_t> {"A test strong"}, 2, basic_string<char_t> {"A test string"}, 13, 1);});
    }
    
    void test_method_(concat_with_four_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A ", "test ", "string ", "to test"));
    }

    void test_method_(concat_with_four_u16_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(u"A ", u"test ", u"string ", u"to test"));
    }

    void test_method_(concat_with_four_u32_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(U"A ", U"test ", U"string ", U"to test"));
    }
    
    void test_method_(concat_with_four_u8_string_literals) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::concat(u8"A ", u8"test ", u8"string ", u8"to test"));
#endif
    }

    void test_method_(concat_with_four_wstring_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(L"A ", L"test ", L"string ", L"to test"));
    }
    
    void test_method_(concat_with_four_mixed_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A ", u"test ", U"string ", L"to test"));
    }
    
    void test_method_(concat_with_four_char_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char> {"A "}, basic_string<char> {"test "}, basic_string<char> {"string "}, basic_string<char> {"to test"}));
    }
    
    void test_method_(concat_with_four_char16_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char16> {"A "}, basic_string<char16> {"test "}, basic_string<char16> {"string "}, basic_string<char16> {"to test"}));
    }
    
    void test_method_(concat_with_four_char32_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char32> {"A "}, basic_string<char32> {"test "}, basic_string<char32> {"string "}, basic_string<char32> {"to test"}));
    }

    void test_method_(concat_with_four_char8_basic_string) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char8> {"A "}, basic_string<char8> {"test "}, basic_string<char8> {"string "}, basic_string<char8> {"to test"}));
#endif
    }
    
    void test_method_(concat_with_four_wchar_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<wchar> {"A "}, basic_string<wchar> {"test "}, basic_string<wchar> {"string "}, basic_string<wchar> {"to test"}));
    }
    
    void test_method_(concat_with_four_mixed_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char> {"A "}, basic_string<char16> {"test "}, basic_string<char32> {"string "}, basic_string<wchar> {"to test"}));
    }
    
    void test_method_(concat_with_four_object) {
      assert::are_equal("00:45:12 8720.3", basic_string<char_t>::concat(45_m + 12_s, " ", 87, 20.3));
    }
    
    void test_method_(concat_with_three_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A test ", "string ", "to test"));
    }
    
    void test_method_(concat_with_three_u16_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(u"A test ", u"string ", u"to test"));
    }
    
    void test_method_(concat_with_three_u32_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(U"A test ", U"string ", U"to test"));
    }
    
    void test_method_(concat_with_three_u8_string_literals) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::concat(u8"A test ", u8"string ", u8"to test"));
#endif
    }
    
    void test_method_(concat_with_three_wstring_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(L"A test ", L"string ", L"to test"));
    }
    
    void test_method_(concat_with_three_mixed_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A test ", U"string ", L"to test"));
    }
    
    void test_method_(concat_with_three_char_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char> {"A test "}, basic_string<char> {"string "}, basic_string<char> {"to test"}));
    }
    
    void test_method_(concat_with_three_char16_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char16> {"A test "}, basic_string<char16> {"string "}, basic_string<char16> {"to test"}));
    }
    
    void test_method_(concat_with_three_char32_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char32> {"A test "}, basic_string<char32> {"string "}, basic_string<char32> {"to test"}));
    }
    
    void test_method_(concat_with_three_char8_basic_string) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char8> {"A test "}, basic_string<char8> {"string "}, basic_string<char8> {"to test"}));
#endif
    }
    
    void test_method_(concat_with_three_wchar_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<wchar> {"A test "}, basic_string<wchar> {"string "}, basic_string<wchar> {"to test"}));
    }
    
    void test_method_(concat_with_three_mixed_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char> {"A test "}, basic_string<char32> {"string "}, basic_string<wchar> {"to test"}));
    }
                                                                              
    void test_method_(concat_with_three_object) {
      assert::are_equal("00:45:12 8720.3", basic_string<char_t>::concat(45_m + 12_s, " ", 8720.3));
    }
    
    void test_method_(concat_with_two_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A test string ", "to test"));
    }
    
    void test_method_(concat_with_two_u16_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(u"A test string ", u"to test"));
    }
    
    void test_method_(concat_with_two_u32_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(U"A test string ", U"to test"));
    }
    
    void test_method_(concat_with_two_u8_string_literals) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::concat(u8"A test string ", u8"to test"));
#endif
    }
    
    void test_method_(concat_with_two_wstring_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(L"A test string ", L"to test"));
    }
    
    void test_method_(concat_with_two_mixed_string_literals) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A test string ", L"to test"));
    }
    
    void test_method_(concat_with_two_char_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char> {"A test string "}, basic_string<char> {"to test"}));
    }
    
    void test_method_(concat_with_two_char16_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char16> {"A test string "}, basic_string<char16> {"to test"}));
    }
    
    void test_method_(concat_with_two_char32_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char32> {"A test string "}, basic_string<char32> {"to test"}));
    }
    
    void test_method_(concat_with_two_char8_basic_string) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char8> {"A test string "}, basic_string<char8> {"to test"}));
#endif
    }
    
    void test_method_(concat_with_two_wchar_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<wchar> {"A test string "}, basic_string<wchar> {"to test"}));
    }
    
    void test_method_(concat_with_two_mixed_basic_string) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(basic_string<char> {"A test string "}, basic_string<wchar> {"to test"}));
    }
    
    void test_method_(concat_with_two_object) {
      assert::are_equal("00:45:128720.3", basic_string<char_t>::concat(45_m + 12_s, 8720.3));
    }
    
    void test_method_(concat_with_array) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat(array<basic_string<char_t>> {"A ", "test ", "string ", "to test"}));
    }
    
    void test_method_(concat_with_initializer_list) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat({"A ", "test ", "string ", "to test"}));
    }
    
    void test_method_(concat_with_object) {
      assert::are_equal("A test string to test", basic_string<char_t>::concat("A test string to test"));
      assert::are_equal("00:45:12", basic_string<char_t>::concat(45_m + 12_s));
      assert::are_equal("8720.3", basic_string<char_t>::concat(8720.3));
    }
    
    void test_method_(demangle) {
      string_assert::does_not_start_with("xtd::collections::generic::list<float", typeid(xtd::collections::generic::list<float>).name());
      string_assert::starts_with("xtd::collections::generic::list<float", basic_string<char_t>::demangle(typeid(xtd::collections::generic::list<float>).name()));
    }

    void test_method_(equals_with_two_string) {
      assert::is_true(basic_string<char_t>::equals("A test string", "A test string"));
      assert::is_false(basic_string<char_t>::equals("A test string", "A tEsT sTrInG"));
      assert::is_false(basic_string<char_t>::equals("A tEsT sTrInG", "A test string"));
      assert::is_false(basic_string<char_t>::equals("A test string", "B test strong"));
      assert::is_false(basic_string<char_t>::equals("B test strong", "A test string"));
    }
    
    void test_method_(equals_with_two_string_and_ignore_case_to_false) {
      assert::is_true(basic_string<char_t>::equals("A test string", "A test string", false));
      assert::is_false(basic_string<char_t>::equals("A test string", "A tEsT sTrInG", false));
      assert::is_false(basic_string<char_t>::equals("A tEsT sTrInG", "A test string", false));
      assert::is_false(basic_string<char_t>::equals("A test string", "B test strong", false));
      assert::is_false(basic_string<char_t>::equals("B test strong", "A test string", false));
    }
    
    void test_method_(equals_with_two_string_and_ignore_case_to_true) {
      assert::is_true(basic_string<char_t>::equals("A test string", "A test string", true));
      assert::is_true(basic_string<char_t>::equals("A test string", "A tEsT sTrInG", true));
      assert::is_true(basic_string<char_t>::equals("A tEsT sTrInG", "A test string", true));
      assert::is_false(basic_string<char_t>::equals("A test string", "B test strong", true));
      assert::is_false(basic_string<char_t>::equals("B test strong", "A test string", true));
    }

    void test_method_(format_char) {
      assert::are_equal("A test string to test", basic_string<char_t>::format("{}", "A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format("{}", u"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format("{}", U"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format("{}", u8"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format("{}", L"A test string to test"));
    }
    
    void test_method_(format_char16) {
      assert::are_equal("A test string to test", basic_string<char_t>::format(u"{}", "A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u"{}", u"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u"{}", U"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u"{}", u8"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u"{}", L"A test string to test"));
    }
    
    void test_method_(format_char32) {
      assert::are_equal("A test string to test", basic_string<char_t>::format(U"{}", "A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(U"{}", u"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(U"{}", U"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(U"{}", u8"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(U"{}", L"A test string to test"));
    }
    
    void test_method_(format_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      assert::are_equal("A test string to test", basic_string<char_t>::format(u8"{}", "A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u8"{}", u"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u8"{}", U"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u8"{}", u8"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(u8"{}", L"A test string to test"));
#endif
    }
    
    void test_method_(format_wchar) {
      assert::are_equal("A test string to test", basic_string<char_t>::format(L"{}", "A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(L"{}", u"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(L"{}", U"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(L"{}", u8"A test string to test"));
      assert::are_equal("A test string to test", basic_string<char_t>::format(L"{}", L"A test string to test"));
    }

    void test_method_(is_empty) {
      assert::is_true(basic_string<char_t>::is_empty(basic_string<char_t> {}));
      assert::is_true(basic_string<char_t>::is_empty(basic_string<char_t>::empty_string));
      assert::is_false(basic_string<char_t>::is_empty(basic_string<char_t> {"A test string"}));
    }

    void test_method_(join) {
      assert::are_equal("1, 2, 3, 4, 5", basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}));
    }

    void test_method_(join_with_index) {
      assert::are_equal("3, 4, 5", basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 2));
      assert::are_equal("", basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 5));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 6);});
    }

    void test_method_(join_with_index_and_count) {
      assert::are_equal("3, 4, 5", basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 2, 3));
      assert::are_equal("1, 2, 3, 4, 5", basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 0, 5));
      assert::are_equal("", basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 5, 0));
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 6, 0);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 5, 1);});
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t>::join(", ", {1, 2, 3, 4, 5}, 2, 4);});
    }
    
    void test_method_(parse) {
      assert::are_equal(42, basic_string<char_t>::template parse<int>("42"));
    }

    void test_method_(sprintf_char) {
      if constexpr(std::is_same<char_t, char16>::value) return;
      else if constexpr(std::is_same<char_t, char32>::value) return;
#if defined(__xtd__cpp_lib_char8_t)
      else if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else if constexpr (std::is_same<char_t, wchar>::value) return;
      else assert::are_equal("A test string to test", basic_string<char_t>::sprintf("%s", "A test string to test"));
    }

    void test_method_(sprintf_char16) {
      if constexpr(std::is_same<char_t, char16>::value) return;
      else if constexpr(std::is_same<char_t, char32>::value) return;
#if defined(__xtd__cpp_lib_char8_t)
      else if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else if constexpr (std::is_same<char_t, wchar>::value) return;
      else assert::are_equal("A test string to test", basic_string<char_t>::sprintf(u"%s", "A test string to test"));
    }

    void test_method_(sprintf_char32) {
      if constexpr(std::is_same<char_t, char16>::value) return;
      else if constexpr(std::is_same<char_t, char32>::value) return;
#if defined(__xtd__cpp_lib_char8_t)
      else if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else if constexpr (std::is_same<char_t, wchar>::value) return;
      else assert::are_equal("A test string to test", basic_string<char_t>::sprintf(U"%s", "A test string to test"));
    }

    void test_method_(sprintf_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char16>::value) return;
      else if constexpr(std::is_same<char_t, char32>::value) return;
      else if constexpr(std::is_same<char_t, char8>::value) return;
      else if constexpr (std::is_same<char_t, wchar>::value) return;
      else assert::are_equal("A test string to test", basic_string<char_t>::sprintf(u8"%s", "A test string to test"));
#endif
    }

    void test_method_(sprintf_wchar) {
      if constexpr(std::is_same<char_t, char16>::value) return;
      else if constexpr(std::is_same<char_t, char32>::value) return;
#if defined(__xtd__cpp_lib_char8_t)
      else if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      else if constexpr (std::is_same<char_t, wchar>::value) return;
      else assert::are_equal("A test string to test", basic_string<char_t>::sprintf(L"%s", "A test string to test"));
    }

    void test_method_(try_parse) {
      auto result = 0;
      assert::is_true(basic_string<char_t>::template try_parse<int>("42", result));
      assert::are_equal(42, result);

      result = 0;
      assert::is_false(basic_string<char_t>::template try_parse<int>("42S", result));
      assert::are_equal(0, result);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                      Operators
    void test_method_(indexer_operator) {
      auto s = basic_string<char_t>("A test string");
      assert::are_equal(char_t {'A'}, s[0]);
      assert::are_equal(char_t {' '}, s[1]);
      assert::are_equal(char_t {'t'}, s[2]);
      assert::are_equal(char_t {'e'}, s[3]);
      assert::are_equal(char_t {'s'}, s[4]);
      assert::are_equal(char_t {'t'}, s[5]);
      assert::are_equal(char_t {' '}, s[6]);
      assert::are_equal(char_t {'s'}, s[7]);
      assert::are_equal(char_t {'t'}, s[8]);
      assert::are_equal(char_t {'r'}, s[9]);
      assert::are_equal(char_t {'i'}, s[10]);
      assert::are_equal(char_t {'n'}, s[11]);
      assert::are_equal(char_t {'g'}, s[12]);
      assert::throws<index_out_of_range_exception>([&]{s[13];});
      assert::throws<index_out_of_range_exception>([&]{basic_string<char_t> {}[0];});
    }

    void test_method_(cast_operator_base_type) {
      auto s = std::basic_string<char_t> {};
      s = basic_string<char_t>("A test string");
      collection_assert::are_equal(std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, s);
    }

    void test_method_(equal_operator_basic_string_char) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char>("A test string");
      s1 = s2;
      assert::are_equal("A test string", s1);
      assert::are_equal("A test string", s2);
    }

    void test_method_(equal_operator_basic_string_char16) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char16>(u"A test string");
      s1 = s2;
      assert::are_equal(u"A test string", s1);
      assert::are_equal(u"A test string", s2);
    }

    void test_method_(equal_operator_basic_string_char32) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char32>(U"A test string");
      s1 = s2;
      assert::are_equal(U"A test string", s1);
      assert::are_equal(U"A test string", s2);
    }

    void test_method_(equal_operator_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char8>(u8"A test string");
      s1 = s2;
      assert::are_equal(u8"A test string", s1);
      assert::are_equal(u8"A test string", s2);
#endif
    }

    void test_method_(equal_operator_basic_string_wchar) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<wchar>(L"A test string");
      s1 = s2;
      assert::are_equal(L"A test string", s1);
      assert::are_equal(L"A test string", s2);
    }

    void test_method_(equal_operator_move_basic_string_char) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char>("A test string");
      s1 = std::move(s2);
      assert::are_equal("A test string", s1);
    }
    
    void test_method_(equal_operator_move_basic_string_char16) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char16>(u"A test string");
      s1 = std::move(s2);
      assert::are_equal(u"A test string", s1);
    }
    
    void test_method_(equal_operator_move_basic_string_char32) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char32>(U"A test string");
      s1 = std::move(s2);
      assert::are_equal(U"A test string", s1);
    }
    
    void test_method_(equal_operator_move_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<char8>(u8"A test string");
      s1 = std::move(s2);
      assert::are_equal(u8"A test string", s1);
#endif
    }
    
    void test_method_(equal_operator_move_basic_string_wchar) {
      auto s1 = basic_string<char_t> {};
      auto s2 = basic_string<wchar>(L"A test string");
      s1 = std::move(s2);
      assert::are_equal(L"A test string", s1);
    }

    void test_method_(equal_operator_std_basic_string_char) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char>("A test string");
      s1 = s2;
      assert::are_equal("A test string", s1);
      assert::are_equal("A test string", s2);
    }
    
    void test_method_(equal_operator_std_basic_string_char16) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char16>(u"A test string");
      s1 = s2;
      assert::are_equal(u"A test string", s1);
      assert::are_equal(u"A test string", s2);
    }
    
    void test_method_(equal_operator_std_basic_string_char32) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char32>(U"A test string");
      s1 = s2;
      assert::are_equal(U"A test string", s1);
      assert::are_equal(U"A test string", s2);
    }
    
    void test_method_(equal_operator_std_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char8>(u8"A test string");
      s1 = s2;
      assert::are_equal(u8"A test string", s1);
      assert::are_equal(u8"A test string", s2);
#endif
    }
    
    void test_method_(equal_operator_std_basic_string_wchar) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<wchar>(L"A test string");
      s1 = s2;
      assert::are_equal(L"A test string", s1);
      assert::are_equal(L"A test string", s2);
    }

    void test_method_(equal_operator_move_std_basic_string_char) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char>("A test string");
      s1 = std::move(s2);
      assert::are_equal("A test string", s1);
    }
    
    void test_method_(equal_operator_move_std_basic_string_char16) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char16>(u"A test string");
      s1 = std::move(s2);
      assert::are_equal(u"A test string", s1);
    }
    
    void test_method_(equal_operator_move_std_basic_string_char32) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char32>(U"A test string");
      s1 = std::move(s2);
      assert::are_equal(U"A test string", s1);
    }
    
    void test_method_(equal_operator_move_std_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<char8>(u8"A test string");
      s1 = std::move(s2);
      assert::are_equal(u8"A test string", s1);
#endif
    }
    
    void test_method_(equal_operator_move_std_basic_string_wchar) {
      auto s1 = basic_string<char_t> {};
      auto s2 = std::basic_string<wchar>(L"A test string");
      s1 = std::move(s2);
      assert::are_equal(L"A test string", s1);
    }

    void test_method_(equal_operator_char_pointer) {
      auto s1 = basic_string<char_t> {};
      auto s2 = "A test string";
      s1 = s2;
      assert::are_equal("A test string", s1);
      assert::are_equal("A test string", s2);
    }
    
    void test_method_(equal_operator_char16_pointer) {
      auto s1 = basic_string<char_t> {};
      auto s2 = u"A test string";
      s1 = s2;
      assert::are_equal(u"A test string", s1);
      assert::are_equal(u"A test string", s2);
    }
    
    void test_method_(equal_operator_char32_pointer) {
      auto s1 = basic_string<char_t> {};
      auto s2 = U"A test string";
      s1 = s2;
      assert::are_equal(U"A test string", s1);
      assert::are_equal(U"A test string", s2);
    }
    
    void test_method_(equal_operator_char8_pointer) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {};
      auto s2 = u8"A test string";
      s1 = s2;
      assert::are_equal(u8"A test string", s1);
      assert::are_equal(u8"A test string", s2);
#endif
    }
    
    void test_method_(equal_operator_wchar_pointer) {
      auto s1 = basic_string<char_t> {};
      auto s2 = L"A test string";
      s1 = s2;
      assert::are_equal(L"A test string", s1);
      assert::are_equal(L"A test string", s2);
    }

    void test_method_(equal_operator_char) {
      auto s = basic_string<char_t> {};
      auto c = 'C';
      s = c;
      assert::are_equal('C', c);
      assert::are_equal("C", s);
    }

    void test_method_(equal_operator_char16) {
      auto s = basic_string<char_t> {};
      auto c = u'C';
      s = c;
      assert::are_equal(u'C', c);
      assert::are_equal("C", s);
    }

    void test_method_(equal_operator_char32) {
      auto s = basic_string<char_t> {};
      auto c = U'C';
      s = c;
      assert::are_equal(U'C', c);
      assert::are_equal("C", s);
    }

    void test_method_(equal_operator_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {};
      auto c = u8'C';
      s = c;
      assert::are_equal(u8'C', c);
      assert::are_equal("C", s);
#endif
    }

    void test_method_(equal_operator_wchar) {
      auto s = basic_string<char_t> {};
      auto c = L'C';
      s = c;
      assert::are_equal(L'C', c);
      assert::are_equal("C", s);
    }

    void test_method_(equal_operator_initializer_list_char) {
      auto s = basic_string<char_t> {};
      auto il = std::initializer_list<char> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal("A test string", s);
    }

    void test_method_(equal_operator_initializer_list_char16) {
      auto s = basic_string<char_t> {};
      auto il = std::initializer_list<char16> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal(u"A test string", s);
    }

    void test_method_(equal_operator_initializer_list_char32) {
      auto s = basic_string<char_t> {};
      auto il = std::initializer_list<char32> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal(U"A test string", s);
    }

    void test_method_(equal_operator_initializer_list_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {};
      auto il = std::initializer_list<char8> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal(u8"A test string", s);
#endif
    }

    void test_method_(equal_operator_initializer_list_wchar) {
      auto s = basic_string<char_t> {};
      auto il = std::initializer_list<wchar> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal(L"A test string", s);
    }

    void test_method_(addition_assignment_operator_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char> {" string"};
      s1 += s2;
      assert::are_equal("A test string", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_assignment_operator_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char16> {u" string"};
      s1 += s2;
      assert::are_equal(u"A test string", s1);
      assert::are_equal(u" string", s2);
    }
    
    void test_method_(addition_assignment_operator_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char32> {U" string"};
      s1 += s2;
      assert::are_equal(U"A test string", s1);
      assert::are_equal(U" string", s2);
    }
    
    void test_method_(addition_assignment_operator_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char8> {u8" string"};
      s1 += s2;
      assert::are_equal(u8"A test string", s1);
      assert::are_equal(u8" string", s2);
#endif
    }
    
    void test_method_(addition_assignment_operator_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<wchar> {L" string"};
      s1 += s2;
      assert::are_equal(L"A test string", s1);
      assert::are_equal(L" string", s2);
    }

    void test_method_(addition_assignment_operator_move_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char> {" string"};
      s1 += std::move(s2);
      assert::are_equal("A test string", s1);
    }
    
    void test_method_(addition_assignment_operator_move_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char16> {u" string"};
      s1 += std::move(s2);
      assert::are_equal(u"A test string", s1);
    }
    
    void test_method_(addition_assignment_operator_move_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char32> {U" string"};
      s1 += std::move(s2);
      assert::are_equal(U"A test string", s1);
    }
    
    void test_method_(addition_assignment_operator_move_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char8> {u8" string"};
      s1 += std::move(s2);
      assert::are_equal(u8"A test string", s1);
#endif
    }
    
    void test_method_(addition_assignment_operator_move_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<wchar> {L" string"};
      s1 += std::move(s2);
      assert::are_equal(L"A test string", s1);
    }

    void test_method_(addition_assignment_operator_std_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char> {" string"};
      s1 += s2;
      assert::are_equal("A test string", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_assignment_operator_std_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char16> {u" string"};
      s1 += s2;
      assert::are_equal(u"A test string", s1);
      assert::are_equal(u" string", s2);
    }
    
    void test_method_(addition_assignment_operator_std_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char32> {U" string"};
      s1 += s2;
      assert::are_equal(U"A test string", s1);
      assert::are_equal(U" string", s2);
    }
    
    void test_method_(addition_assignment_operator_std_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char8> {u8" string"};
      s1 += s2;
      assert::are_equal(u8"A test string", s1);
      assert::are_equal(u8" string", s2);
#endif
    }
    
    void test_method_(addition_assignment_operator_std_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<wchar> {L" string"};
      s1 += s2;
      assert::are_equal(L"A test string", s1);
      assert::are_equal(L" string", s2);
    }

    void test_method_(addition_assignment_operator_char_pointer) {
      auto s = basic_string<char_t> {"A test"};
      s += " string";
      assert::are_equal("A test string", s);
    }
    
    void test_method_(addition_assignment_operator_char16_pointer) {
      auto s = basic_string<char_t> {"A test"};
      s += u" string";
      assert::are_equal(u"A test string", s);
    }
    
    void test_method_(addition_assignment_operator_char32_pointer) {
      auto s = basic_string<char_t> {"A test"};
      s += U" string";
      assert::are_equal(U"A test string", s);
    }
    
    void test_method_(addition_assignment_operator_char8_pointer) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {"A test"};
      s += u8" string";
      assert::are_equal(u8"A test string", s);
#endif
    }
    
    void test_method_(addition_assignment_operator_wchar_pointer) {
      auto s = basic_string<char_t> {"A test"};
      s += L" string";
      assert::are_equal(L"A test string", s);
    }

    void test_method_(addition_assignment_operator_char) {
      auto s = basic_string<char_t> {"A test"};
      s += '$';
      assert::are_equal("A test$", s);
    }
    
    void test_method_(addition_assignment_operator_char16) {
      auto s = basic_string<char_t> {"A test"};
      s += u'$';
      assert::are_equal(u"A test$", s);
    }
    
    void test_method_(addition_assignment_operator_char32) {
      auto s = basic_string<char_t> {"A test"};
      s += U'$';
      assert::are_equal(U"A test$", s);
    }
    
    void test_method_(addition_assignment_operator_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {"A test"};
      s += u8'$';
      assert::are_equal(u8"A test$", s);
#endif
    }
    
    void test_method_(addition_assignment_operator_wchar) {
      auto s = basic_string<char_t> {"A test"};
      s += L'$';
      assert::are_equal(L"A test$", s);
    }
    
    void test_method_(addition_operator_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char16> {u" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char32> {U" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char8> {u8" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(" string", s2);
#endif
    }
    
    void test_method_(addition_operator_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<wchar> {L" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_move_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char> {" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char16> {u" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char32> {U" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char8> {u8" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
#endif
    }
    
    void test_method_(addition_operator_move_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<wchar> {L" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char> {" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char16> {u" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char32> {U" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char8> {u8" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
      assert::are_equal(" string", s2);
#endif
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<wchar> {L" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char16> {u" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char32> {U" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char8> {u8" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
#endif
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<wchar> {L" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_std_basic_string_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_std_basic_string_char16) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char16> {u" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(u" string", s2);
    }
    
    void test_method_(addition_operator_std_basic_string_char32) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char32> {U" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(U" string", s2);
    }
    
    void test_method_(addition_operator_std_basic_string_char8) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<char8> {u8" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(u8" string", s2);
#endif
    }
    
    void test_method_(addition_operator_std_basic_string_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = std::basic_string<wchar> {L" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
      assert::are_equal(L" string", s2);
    }

    void test_method_(addition_operator_char_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = " string";
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_char16_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = u" string";
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_char32_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = U" string";
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_char8_pointer_rhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = u8" string";
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
#endif
    }
    
    void test_method_(addition_operator_wchar_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = L" string";
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal("A test", s1);
    }
    
    void test_method_(addition_operator_move_lhs_char_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = " string";
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_lhs_char16_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = u" string";
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_lhs_char32_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = U" string";
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_move_lhs_char8_pointer_rhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = u8" string";
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
#endif
    }
    
    void test_method_(addition_operator_move_lhs_wchar_pointer_rhs) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = L" string";
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3);
      assert::is_empty(s1);
    }
    
    void test_method_(addition_operator_char_pointer_lhs) {
      auto s1 = "A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_char16_pointer_lhs) {
      auto s1 = u"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_char32_pointer_lhs) {
      auto s1 = U"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_char8_pointer_lhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = u8"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal(" string", s2);
#endif
    }
    
    void test_method_(addition_operator_wchar_pointer_lhs) {
      auto s1 = L"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3);
      assert::are_equal(" string", s2);
    }
    
    void test_method_(addition_operator_char_pointer_lhs_move_rhs) {
      auto s1 = "A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
    }
    
    void test_method_(addition_operator_char16_pointer_lhs_move_rhs) {
      auto s1 = u"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
    }
    
    void test_method_(addition_operator_char32_pointer_lhs_move_rhs) {
      auto s1 = U"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
    }
    
    void test_method_(addition_operator_char8_pointer_lhs_move_rhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s1 = u8"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
#endif
    }
    
    void test_method_(addition_operator_wchar_pointer_lhs_move_rhs) {
      auto s1 = L"A test";
      auto s2 = basic_string<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3);
    }
    
    void test_method_(addition_operator_char_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = '$';
      auto r = s + c;
      assert::are_equal("A test$", r);
      assert::are_equal("A test", s);
      assert::are_equal('$', c);
    }
    
    void test_method_(addition_operator_char16_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = u'$';
      auto r = s + c;
      assert::are_equal("A test$", r);
      assert::are_equal("A test", s);
      assert::are_equal(u'$', c);
    }
    
    void test_method_(addition_operator_char32_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = U'$';
      auto r = s + c;
      assert::are_equal("A test$", r);
      assert::are_equal("A test", s);
      assert::are_equal(U'$', c);
    }
    
    void test_method_(addition_operator_char8_rhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {"A test"};
      auto c = u8'$';
      auto r = s + c;
      assert::are_equal("A test$", r);
      assert::are_equal("A test", s);
      assert::are_equal(u8'$', c);
#endif
    }
    
    void test_method_(addition_operator_wchar_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = L'$';
      auto r = s + c;
      assert::are_equal("A test$", r);
      assert::are_equal("A test", s);
      assert::are_equal(L'$', c);
    }
    
    void test_method_(addition_operator_move_lhs_char_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = '$';
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r);
      assert::is_empty(s);
      assert::are_equal('$', c);
    }
    
    void test_method_(addition_operator_move_lhs_char16_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = u'$';
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r);
      assert::is_empty(s);
      assert::are_equal(u'$', c);
    }
    
    void test_method_(addition_operator_move_lhs_char32_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = U'$';
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r);
      assert::is_empty(s);
      assert::are_equal(U'$', c);
    }
    
    void test_method_(addition_operator_move_lhs_char8_rhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto s = basic_string<char_t> {"A test"};
      auto c = u8'$';
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r);
      assert::is_empty(s);
      assert::are_equal(u8'$', c);
#endif
    }
    
    void test_method_(addition_operator_move_lhs_wchar_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = L'$';
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r);
      assert::is_empty(s);
      assert::are_equal(L'$', c);
    }
    
    void test_method_(addition_operator_char_lhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = '$';
      auto r = c + s;
      assert::are_equal("$A test", r);
      assert::are_equal('$', c);
      assert::are_equal("A test", s);
    }
    
    void test_method_(addition_operator_char16_rlhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = u'$';
      auto r = c + s;
      assert::are_equal("$A test", r);
      assert::are_equal(u'$', c);
      assert::are_equal("A test", s);
    }
    
    void test_method_(addition_operator_char32_lhs) {
      auto c = U'$';
      auto s = basic_string<char_t> {"A test"};
      auto r = c + s;
      assert::are_equal("$A test", r);
      assert::are_equal(U'$', c);
      assert::are_equal("A test", s);
    }
    
    void test_method_(addition_operator_char8_lhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto c = u8'$';
      auto s = basic_string<char_t> {"A test"};
      auto r = c + s;
      assert::are_equal("$A test", r);
      assert::are_equal(u8'$', c);
      assert::are_equal("A test", s);
#endif
    }
    
    void test_method_(addition_operator_wchar_lhs) {
      auto c = L'$';
      auto s = basic_string<char_t> {"A test"};
      auto r = c + s;
      assert::are_equal("$A test", r);
      assert::are_equal(L'$', c);
      assert::are_equal("A test", s);
    }
    
    void test_method_(addition_operator_char_lhs_move_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = '$';
      auto r = c + std::move(s);
      assert::are_equal("$A test", r);
      assert::are_equal('$', c);
    }
    
    void test_method_(addition_operator_char16_rlhs_move_rhs) {
      auto s = basic_string<char_t> {"A test"};
      auto c = u'$';
      auto r = c + std::move(s);
      assert::are_equal("$A test", r);
      assert::are_equal(u'$', c);
    }
    
    void test_method_(addition_operator_char32_lhs_move_rhs) {
      auto c = U'$';
      auto s = basic_string<char_t> {"A test"};
      auto r = c + std::move(s);
      assert::are_equal("$A test", r);
      assert::are_equal(U'$', c);
    }
    
    void test_method_(addition_operator_char8_lhs_move_rhs) {
#if defined(__xtd__cpp_lib_char8_t)
      auto c = u8'$';
      auto s = basic_string<char_t> {"A test"};
      auto r = c + std::move(s);
      assert::are_equal("$A test", r);
      assert::are_equal(u8'$', c);
#endif
    }
    
    void test_method_(addition_operator_wchar_lhs_move_rhs) {
      auto c = L'$';
      auto s = basic_string<char_t> {"A test"};
      auto r = c + std::move(s);
      assert::are_equal("$A test", r);
      assert::are_equal(L'$', c);
    }
    
    void test_method_(output_stream_operator_char) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char_t> {" string"};
      
      std::basic_stringstream<char> ss;
      ss << s1 << s2;
      assert::are_equal("A test string", ss.str());
    }
    
    void test_method_(output_stream_operator_wchar) {
      auto s1 = basic_string<char_t> {"A test"};
      auto s2 = basic_string<char_t> {" string"};
      
      std::basic_stringstream<wchar> ss;
      ss << s1 << s2;
      assert::are_equal(L"A test string", ss.str());
    }

    void test_method_(input_stream_operator_char) {
      auto is = basic_string<char> {"TestString"};
      std::basic_istringstream<char> iss {is};
      
      auto s = basic_string<char_t> {};
      iss >> s;
      assert::are_equal("TestString", s);
    }

    void test_method_(input_stream_operator_wchar) {
      auto is = basic_string<wchar> {L"TestString"};
      std::basic_istringstream<wchar> iss {is};
      
      auto s = basic_string<char_t> {};
      iss >> s;
      assert::are_equal("TestString", s);
    }
  };
}
