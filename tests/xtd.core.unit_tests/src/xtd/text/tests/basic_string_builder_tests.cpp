#include <xtd/text/basic_string_builder>
#include <xtd/argument_exception>
#include <xtd/argument_out_of_range_exception>
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
#include <sstream>

using namespace xtd;
using namespace xtd::text;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  template <typename value_t>
  class basic_string_builder_tests;

  test_class_attribute<basic_string_builder_tests<char>> basic_string_builder_tests_class_char_attr {"basic_string_builder_tests<char>"};
  test_class_attribute<basic_string_builder_tests<char16>> basic_string_builder_tests_class_char16_attr {"basic_string_builder_tests<char16>"};
  test_class_attribute<basic_string_builder_tests<char32>> basic_string_builder_tests_class_char32_attr {"basic_string_builder_tests<char32>"};
#if defined(__xtd__cpp_lib_char8_t)
  test_class_attribute<basic_string_builder_tests<char8>> basic_string_builder_tests_class_char8_attr {"basic_string_builder_tests<char8>"};
#endif
  test_class_attribute<basic_string_builder_tests<wchar>> basic_string_builder_tests_class_wchar_attr {"basic_string_builder_tests<wchar>"};

  template <typename char_t>
  class basic_string_builder_tests : public test_class {
  public:
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Aliases
    void test_method_(base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_<typename basic_string_builder<char_t>::base_type>(), csf_);
    }
    
    void test_method_(traits_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::traits_type>(), typeof_<typename basic_string_builder<char_t>::traits_type>(), csf_);
    }
    
    void test_method_(value_type) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<char_t>(), typeof_<typename basic_string_builder<char_t>::value_type>(), csf_);
    }
    
    void test_method_(allocator_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::allocator_type>(), typeof_<typename basic_string_builder<char_t>::allocator_type>(), csf_);
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::size_type>(), typeof_<typename basic_string_builder<char_t>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::difference_type>(), typeof_<typename basic_string_builder<char_t>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<char_t&>(), typeof_<typename basic_string_builder<char_t>::reference>(), csf_);
    }
    
    void test_method_(const_reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<const char_t&>(), typeof_<typename basic_string_builder<char_t>::const_reference>(), csf_);
    }
    
    void test_method_(pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<char_t*>(), typeof_<typename basic_string_builder<char_t>::pointer>(), csf_);
    }
    
    void test_method_(const_pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<const char_t*>(), typeof_<typename basic_string_builder<char_t>::const_pointer>(), csf_);
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::iterator>(), typeof_<typename basic_string_builder<char_t>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_iterator>(), typeof_<typename basic_string_builder<char_t>::const_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::reverse_iterator>(), typeof_<typename basic_string_builder<char_t>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_reverse_iterator>(), typeof_<typename basic_string_builder<char_t>::const_reverse_iterator>(), csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                         Fields
    void test_method_(npos) {
      assert::are_equal(size_object::max_value, basic_string_builder<char_t>::npos, csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                   Constructors
    void test_method_(default_constructor) {
      auto s = basic_string_builder<char_t> {};
      assert::is_zero(s.length(), csf_);
    }

    void test_method_(constructor_with_basic_string_builder) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal("A test string", basic_string_builder<char_t>(s).to_string(), csf_);
      assert::are_equal("A test string", s.to_string(), csf_);
      assert::is_empty(basic_string_builder<char_t>(basic_string_builder<char_t>("")), csf_);
    }
    
    void test_method_(constructor_with_basic_string_builder_and_index) {
      assert::are_equal("string", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7).to_string(), csf_);
      assert::are_equal("g", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 12).to_string(), csf_);
      assert::is_empty(basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 13).to_string(), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 14);}, csf_);
    }
    
    void test_method_(constructor_with_basic_string_and_index_and_count) {
      assert::are_equal("str", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7, 3).to_string(), csf_);
      assert::are_equal("string", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7, 6).to_string(), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7, 7).to_string();}, csf_);
    }
    
    void test_method_(move_constructor_with_basic_string) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal("A test string", basic_string_builder<char_t>(std::move(s)).to_string(), csf_);
      assert::is_empty(s, csf_);
    }
    
    void test_method_(constructor_with_count_and_character) {
      auto s = basic_string_builder<char_t>(10, char_t {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }
    
    void test_method_(constructor_with_count_and_pointer) {
      auto b = basic_string<char_t>("A test string\U0001F603");
      auto p = b.c_str();
      auto s = basic_string_builder<char_t>(p);
      assert::are_equal("A test string\U0001F603", s.to_string(), csf_);
    }
    
    void test_method_(constructor_with_count_and_pointer_and_count) {
      auto b = basic_string<char_t>("A test string");
      auto p = b.c_str();
      auto s = basic_string_builder<char_t>(p, 6);
      assert::are_equal("A test", s.to_string(), csf_);
    }
    
    void test_method_(constructor_with_first_and_last) {
      auto s = xtd::basic_string<char_t>("A test string");
      assert::are_equal("test string", basic_string_builder<char_t>(s.begin() + 2, s.end()).to_string(), csf_);
    }
    
    void test_method_(constructor_with_initializer_list) {
      assert::are_equal("A test string", basic_string_builder<char_t>(std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}).to_string(), csf_);
    }
    
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                     Properties
    
    void test_method_(back) {
      assert::throws<index_out_of_range_exception>([] {basic_string_builder<char_t> {}.back();}, csf_);
      assert::are_equal(char_t {'g'}, basic_string_builder<char_t> {"A test string"}.back(), csf_);
    }
    
    void test_method_(begin) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.begin();
      assert::are_equal(char_t {'A'}, *iterator++, csf_);
      assert::are_equal(char_t {' '}, *iterator++, csf_);
      assert::are_equal(char_t {'e'}, *++iterator, csf_);
      assert::are_equal(char_t {'e'}, *iterator++, csf_);
      assert::are_equal(char_t {'s'}, *iterator, csf_);
      assert::are_equal(char_t {'i'}, *(iterator + 6), csf_);
    }
    
    void test_method_(c_str) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string_builder<char_t> {}.c_str()), csf_);
      assert::is_empty(basic_string_builder<char_t> {}.c_str(), csf_);
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.c_str(), csf_);
    }
    
    void test_method_(capacity) {
      assert::is_not_zero(basic_string_builder<char_t> {}.capacity(), csf_);
    }
    
    void test_method_(cbegin) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.cbegin();
      assert::are_equal(char_t {'A'}, *iterator++, csf_);
      assert::are_equal(char_t {' '}, *iterator++, csf_);
      assert::are_equal(char_t {'e'}, *++iterator, csf_);
      assert::are_equal(char_t {'e'}, *iterator++, csf_);
      assert::are_equal(char_t {'s'}, *iterator, csf_);
      assert::are_equal(char_t {'i'}, *(iterator + 6), csf_);
    }
    
    void test_method_(chars) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_(basic_string_builder<char_t> {}.chars()), csf_);
      assert::is_empty(basic_string_builder<char_t> {}.chars(), csf_);
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.chars(), csf_);
    }
    
    void test_method_(cend) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.cend();
      assert::does_not_throw([&]{ [[maybe_unused]] auto v = *iterator;}, csf_);
    }
    
    void test_method_(data) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
      //assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string_builder<char_t> {}.data()), csf_);
      assert::is_empty(basic_string_builder<char_t> {}.data(), csf_);
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.data(), csf_);
    }
    
    void test_method_(empty) {
      assert::is_true(basic_string_builder<char_t> {}.empty(), csf_);
      assert::is_false(basic_string_builder<char_t> {"A test string"}.empty(), csf_);
    }
    
    void test_method_(end) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.end();
      assert::does_not_throw([&]{ [[maybe_unused]] auto v = *iterator;}, csf_);
    }
    
    void test_method_(front) {
      assert::throws<index_out_of_range_exception>([] {basic_string_builder<char_t> {}.front();}, csf_);
      assert::are_equal(char_t {'A'}, basic_string_builder<char_t> {"A test string"}.front(), csf_);
    }
    
    void test_method_(length) {
      assert::is_zero(basic_string_builder<char_t> {}.length(), csf_);
      assert::are_equal(13_z, basic_string_builder<char_t> {"A test string"}.length(), csf_);
    }
    
    void test_method_(max_size) {
      assert::is_not_zero(basic_string_builder<char_t> {}.max_size(), csf_);
    }
    
    void test_method_(size) {
      assert::is_zero(basic_string_builder<char_t> {}.size(), csf_);
      assert::are_equal(13_z, basic_string_builder<char_t> {"A test string"}.size(), csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Methods

    void test_method_(at) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal(char_t {'A'}, s.at(0), csf_);
      assert::are_equal(char_t {' '}, s.at(1), csf_);
      assert::are_equal(char_t {'t'}, s.at(2), csf_);
      assert::are_equal(char_t {'e'}, s.at(3), csf_);
      assert::are_equal(char_t {'s'}, s.at(4), csf_);
      assert::are_equal(char_t {'t'}, s.at(5), csf_);
      assert::are_equal(char_t {' '}, s.at(6), csf_);
      assert::are_equal(char_t {'s'}, s.at(7), csf_);
      assert::are_equal(char_t {'t'}, s.at(8), csf_);
      assert::are_equal(char_t {'r'}, s.at(9), csf_);
      assert::are_equal(char_t {'i'}, s.at(10), csf_);
      assert::are_equal(char_t {'n'}, s.at(11), csf_);
      assert::are_equal(char_t {'g'}, s.at(12), csf_);
      assert::throws<index_out_of_range_exception>([&]{s.at(13);}, csf_);
      assert::throws<index_out_of_range_exception>([&]{basic_string_builder<char_t> {}.at(0);}, csf_);
    }
    
    void test_method_(compare) {
      assert::is_zero(basic_string_builder<char_t> {"A test string"}.compare(basic_string<char_t> {"A test string"}), csf_);
      assert::is_zero(basic_string_builder<char_t> {"A test string"}.compare(1, 9, basic_string<char_t> {"B test strong"}, 1, 9), csf_);
      assert::is_negative(basic_string_builder<char_t> {"A test string"}.compare(basic_string<char_t> {"B test strong"}), csf_);
      assert::is_positive(basic_string_builder<char_t> {"B test strong"}.compare(basic_string<char_t> {"A test string"}), csf_);
    }
    
    void test_method_(equals_object) {
      auto s1 = basic_string_builder<char_t> {"A test string"};
      auto s2 = basic_string_builder<char_t> {"A test string"};
      auto& o1 = static_cast<object&>(s2);
      auto o2 = object {};
      assert::is_true(s1.equals(o1), csf_);
      assert::is_false(s1.equals(o2), csf_);
    }

    void test_method_(equals) {
      assert::is_true(basic_string_builder<char_t> {"A test string"}.equals(basic_string_builder<char_t> {"A test string"}), csf_);
      assert::is_false(basic_string_builder<char_t> {"A test string"}.equals(basic_string_builder<char_t> {"B test strong"}), csf_);
      assert::is_false(basic_string_builder<char_t> {"B test strong"}.equals(basic_string_builder<char_t> {"A test string"}), csf_);
    }
    
    void test_method_(find) {
      assert::are_equal(2_z, basic_string_builder<char_t> {"A test string"}.find(basic_string<char_t> {"test"}), csf_);
      assert::are_equal(4_z, basic_string_builder<char_t> {"A test string"}.find(char_t {'s'}), csf_);
    }
    
    void test_method_(find_first_of) {
      assert::are_equal(2_z, basic_string_builder<char_t> {"A test string to test"}.find_first_of(basic_string<char_t> {"tuvw"}), csf_);
      assert::are_equal(4_z, basic_string_builder<char_t> {"A test string to test"}.find_first_of(char_t {'s'}), csf_);
    }
    
    void test_method_(find_first_not_of) {
      assert::are_equal(15_z, basic_string_builder<char_t> {"A test string to test"}.find_first_not_of(basic_string<char_t> {"Aeginrst "}), csf_);
      assert::are_equal(1_z, basic_string_builder<char_t> {"A test string to test"}.find_first_not_of(char_t {'A'}), csf_);
    }

    void test_method_(find_last_of) {
      assert::are_equal(15_z, basic_string_builder<char_t> {"A test string to test"}.find_last_of(basic_string<char_t> {"Baco"}), csf_);
      assert::are_equal(16_z, basic_string_builder<char_t> {"A test string to test"}.find_last_of(char_t {' '}), csf_);
    }

    void test_method_(find_last_not_of) {
      assert::are_equal(12_z, basic_string_builder<char_t> {"A test string to test"}.find_last_not_of(basic_string<char_t> {"eost "}), csf_);
      assert::are_equal(19_z, basic_string_builder<char_t> {"A test string to test"}.find_last_not_of(char_t {'t'}), csf_);
    }
    
    void test_method_(get_allocator) {
      assert::are_equal(typeof_<typename std::allocator<char_t>>(), typeof_(basic_string_builder<char_t> {"A test string"}.get_allocator()), csf_);
    }

    void test_method_(get_base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_(basic_string_builder<char_t> {}.get_base_type()), csf_);
      assert::is_empty(basic_string_builder<char_t> {}.get_base_type(), csf_);
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.get_base_type(), csf_);
    }
    
    void test_method_(get_hash_code) {
      assert::are_equal(basic_string_builder<char_t> {"01234"}.get_hash_code(), basic_string_builder<char_t> {"01234"}.get_hash_code(), csf_);
      assert::are_not_equal(basic_string_builder<char_t> {"01235"}.get_hash_code(), basic_string_builder<char_t> {"01234"}.get_hash_code(), csf_);
    }
    
    void test_method_(rfind) {
      assert::are_equal(17_z, basic_string_builder<char_t> {"A test string to test"}.rfind(basic_string<char_t> {"test"}), csf_);
      assert::are_equal(19_z, basic_string_builder<char_t> {"A test string to test"}.rfind(char_t {'s'}), csf_);
    }
    
    void test_method_(substr) {
      assert::are_equal("A test string", basic_string_builder<char_t> {"A test string"}.substr().to_string(), csf_);
    }
    
    void test_method_(substr_with_start_index) {
      assert::are_equal("test string", basic_string_builder<char_t> {"A test string"}.substr(2).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t> {"A test string"}.substr(14);}, csf_);
      assert::are_equal("test", basic_string_builder<char_t> {"A test string"}.substr(2, 4).to_string(), csf_);
    }
    
    void test_method_(substr_with_start_index_and_length) {
      assert::are_equal("test", basic_string_builder<char_t> {"A test string"}.substr(2, 4).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(2, 12);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(14, 4);}, csf_);
    }

    void test_method_(to_string) {
      auto s = basic_string_builder<char_t> {"A test string"};
      assert::is_instance_of<string>(s.to_string(), csf_);
      assert::are_equal("A test string", s.to_string(), csf_);
    }
    
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                      Operators
    void test_method_(indexer_operator) {
      auto s = basic_string_builder<char_t>("A test string");
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
      assert::throws<index_out_of_range_exception>([&]{basic_string_builder<char_t> {}[0];}, csf_);
    }

    void test_method_(cast_operator_base_type) {
      auto s = std::basic_string<char_t> {};
      s = basic_string_builder<char_t>("A test string");
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, s, csf_);
    }

    void test_method_(equal_operator_basic_string) {
      auto s1 = basic_string_builder<char_t> {};
      auto s2 = basic_string_builder<char_t>("A test string");
      s1 = s2;
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::are_equal("A test string", s2.to_string(), csf_);
    }
    
    void test_method_(equal_operator_move_basic_string) {
      auto s1 = basic_string_builder<char_t> {};
      auto s2 = basic_string_builder<char_t>("A test string");
      s1 = std::move(s2);
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(equal_operator_pointer) {
      auto s1 = basic_string_builder<char_t> {};
      auto b = basic_string<char_t> {"A test string"};
      auto s2 = b.c_str();
      s1 = s2;
      assert::are_equal("A test string", s1.to_string(), csf_);
     }
    
    void test_method_(equal_operator_value_type) {
      auto s = basic_string_builder<char_t> {};
      auto c = char_t {'C'};
      s = c;
      assert::are_equal(char_t {'C'}, c, csf_);
      assert::are_equal("C", s.to_string(), csf_);
    }
    
    void test_method_(equal_operator_initializer_list_value_type) {
      auto s = basic_string_builder<char_t> {};
      auto il = std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal("A test string", s.to_string(), csf_);
    }
    
    void test_method_(addition_assignment_operator_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      s1 += s2;
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_assignment_operator_move_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      s1 += std::move(s2);
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_assignment_operator_value_type_pointer) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto b = basic_string<char_t> {" string"};
      s += b.c_str();
      assert::are_equal("A test string", s.to_string(), csf_);
    }
    
    void test_method_(addition_assignment_operator_value_type) {
      auto s = basic_string_builder<char_t> {"A test"};
      s += char_t {'$'};
      assert::are_equal("A test$", s.to_string(), csf_);
    }
    
    void test_method_(addition_operator_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal("A test", s1.to_string(), csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_operator_move_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s1, csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s1, csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal("A test", s1.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_operator_value_type_pointer_rhs) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto b = basic_string<char_t> {" string"};
      auto s2 = b.c_str();
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal("A test", s1.to_string(), csf_);
    }
    
    void test_method_(addition_operator_move_lhs_char_pointer_rhs) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto b = basic_string<char_t> {" string"};
      auto s2 = b.c_str();
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s1, csf_);
    }
    
    void test_method_(addition_operator_value_type_pointer_lhs) {
      auto b = basic_string<char_t> {"A test"};
      auto s1 = b.c_str();
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_operator_value_type_pointer_lhs_move_rhs) {
      auto b = basic_string<char_t> {"A test"};
      auto s1 = b.c_str();
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_operator_value_type_rhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = s + c;
      assert::are_equal("A test$", r.to_string(), csf_);
      assert::are_equal("A test", s.to_string(), csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
    }
    
    void test_method_(addition_operator_move_lhs_value_type_rhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r.to_string(), csf_);
      assert::is_empty(s, csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
    }
    
    void test_method_(addition_operator_value_type_lhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = c + s;
      assert::are_equal("$A test", r.to_string(), csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
      assert::are_equal("A test", s.to_string(), csf_);
    }
    
    void test_method_(addition_operator_value_type_lhs_move_rhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = c + std::move(s);
      assert::are_equal("$A test", r.to_string(), csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
      assert::is_empty(s, csf_);
    }
    
    void test_method_(output_stream_operator_char) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      
      std::basic_stringstream<char> ss;
      ss << s1 << s2;
      assert::are_equal("A test string", ss.str(), csf_);
    }
    
    void test_method_(output_stream_operator_wchar) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      
      std::basic_stringstream<wchar> ss;
      ss << s1 << s2;
      assert::are_equal(L"A test string", ss.str(), csf_);
    }

    void test_method_(input_stream_operator_char) {
      auto is = basic_string_builder<char> {"TestString"};
      std::basic_istringstream<char> iss {is};
      
      auto s = basic_string_builder<char_t> {};
      iss >> s;
      assert::are_equal("TestString", s.to_string(), csf_);
    }

    void test_method_(input_stream_operator_wchar) {
      auto is = basic_string_builder<wchar> {L"TestString"};
      std::basic_istringstream<wchar> iss {is};
      
      auto s = basic_string_builder<char_t> {};
      iss >> s;
      assert::are_equal("TestString", s.to_string(), csf_);
    }
  };
}
