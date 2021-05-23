#include <xtd/strings.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_strings) {
  public:
    void test_method_(compare) {
      assert::is_zero(strings::compare("a", "a"));
      assert::is_negative(strings::compare("a", "b"));
      assert::is_positive(strings::compare("b", "a"));
    }
    
    void test_method_(compare_ignore_case_false) {
      assert::is_not_zero(strings::compare("a", "A", false));
    }
    
    void test_method_(compare_ignore_case_true) {
      assert::is_zero(strings::compare("a", "A", true));
    }
    
    void test_method_(compare_index_length) {
      assert::is_not_zero(strings::compare("abcde", 1, "debcaf", 1, 2));
      assert::is_zero(strings::compare("abcde", 1, "debcaf", 2, 2));
    }
    
    void test_method_(compare_index_length_ingore_case_false) {
      assert::is_not_zero(strings::compare("abcde", 1, "DEBCAF", 2, 2, false));
    }
    
    void test_method_(compare_index_length_ingore_case_true) {
      assert::is_zero(strings::compare("abcde", 1, "DEBCAF", 2, 2, true));
    }

    void test_method_(concat_char_pointers) {
      assert::are_equal("abcd", strings::concat("a", "b", "c", "d"));
    }

    void test_method_(concat_strings) {
      assert::are_equal("abcd", strings::concat("a"s, "b"s, "c"s, "d"s));
    }

    void test_method_(concat_ints) {
      assert::are_equal("124342", strings::concat(1, 24, 3, 42));
    }
    
    void test_method_(concat_any) {
      assert::are_equal("12434.2", strings::concat("1", 24, '3', 4.2));
    }
    
    void test_method_(concat_initializer_list) {
      assert::are_equal(L"1234", strings::concat({L"1", L"2", L"3", L"4"}));
    }
    
    void test_method_(concat_vector) {
      assert::are_equal(L"1234", strings::concat(std::vector {L"1", L"2", L"3", L"4"}));
    }

    void test_method_(concat_any_to_wstring) {
      assert::are_equal(L"12434.2", strings::concat<wchar_t>("1", 24, '3', 4.2));
    }
    
    void test_method_(contains) {
      assert::is_true(strings::contains("abcd", "bc"));
      assert::is_false(strings::contains("abcd", "ad"));
    }
    
    void test_method_(ends_with_char) {
      assert::is_true(strings::ends_with("abcd", 'd'));
      assert::is_false(strings::ends_with("abcd", 'D'));
      assert::is_false(strings::ends_with("abcd", 'B'));
    }

    void test_method_(ends_with_string) {
      assert::is_true(strings::ends_with("abcd", "cd"));
      assert::is_false(strings::ends_with("abcd", "ab"));
    }

    void test_method_(ends_with_string_ignore_case_false) {
      assert::is_true(strings::ends_with("abcd", "cd", false));
      assert::is_false(strings::ends_with("abcd", "CD", false));
      assert::is_false(strings::ends_with("abcd", "AB", false));
    }
    
    void test_method_(ends_with_string_ignore_case_true) {
      assert::is_true(strings::ends_with("abcd", "cd", true));
      assert::is_true(strings::ends_with("abcd", "CD", true));
      assert::is_false(strings::ends_with("abcd", "AB", true));
    }

    void test_method_(string_format_with_automatic_arguments) {
      assert::are_equal("42 str 24", strings::format("{} {} {}", 42, "str", 24));
    }

    void test_method_(string_format_with_indexed_arguments) {
      assert::are_equal("42 str 24 str 42", strings::format("{0} {1} {2} {1} {0}", 42, "str", 24));
    }
    
    void test_method_(string_sprintf_with_one_argument) {
      std::string s = strings::sprintf("%d", 42);
      assert::are_equal("42", s);
    }
    
    void test_method_(wstring_sprintf_with_one_argument) {
       assert::are_equal(L"42", strings::sprintf(L"%d", 42));
    }

    void test_method_(u16string_sprintf_with_one_argument) {
      assert::are_equal(u"", strings::sprintf(u"%d", 42));
    }

    void test_method_(u32string_sprintf_with_one_argument) {
      assert::are_equal(U"", strings::sprintf(U"%d", 42));
    }

    void test_method_(string_sprintf_with_string_argument) {
      assert::are_equal("str", strings::sprintf("%s", "str"s));
    }

    /// @todo Debug on Windows
    ///void test_method_(wstring_sprintf_with_string_argument) {
    ///  assert::are_equal(L"str", strings::sprintf(L"%s", "str"s));
    ///}

    void test_method_(string_sprintf_with_wstring_argument) {
      assert::are_equal("str", strings::sprintf("%ls", L"str"s));
    }

    void test_method_(wstring_sprintf_with_wstring_argument) {
      assert::are_equal(L"str", strings::sprintf(L"%ls", L"str"s));
    }
    
    void test_method_(get_hash_code) {
      assert::are_equal(strings::get_hash_code("01234"), strings::get_hash_code("01234"));
      assert::are_not_equal(strings::get_hash_code("01235"), strings::get_hash_code("01234"));
    }
    
    void test_method_(index_of_char) {
      assert::are_equal(3U, strings::index_of("01234", '3'));
      assert::are_equal(3U, strings::index_of("0123434", '3'));
    }

    void test_method_(index_of_string) {
      assert::are_equal(2U, strings::index_of("01234", "23"));
      assert::are_equal(2U, strings::index_of("0123423", "23"));
    }
    
    void test_method_(index_of_char_start_index) {
      assert::are_equal(5U, strings::index_of("0123434", '3', 4));
    }
    
    void test_method_(index_of_string_start_index) {
      assert::are_equal(5U, strings::index_of("0123423", "23", 3));
    }
    
    void test_method_(index_of_char_start_index_count) {
      assert::are_equal(std::string::npos, strings::index_of("012346734", '3', 4, 2));
    }
    
    void test_method_(index_of_string_start_index_count) {
      assert::are_equal(std::string::npos, strings::index_of("012346723", "23", 3, 2));
    }
    
    void test_method_(index_of_any) {
      assert::are_equal(2U, strings::index_of_any("01234", {'5', '3', '2'}));
    }
    
    void test_method_(index_of_any_start_index) {
      assert::are_equal(3U, strings::index_of_any("01234", {'5', '3', '2'}, 3));
    }
    
    void test_method_(index_of_any_start_index_and_count) {
      assert::are_equal(2U, strings::index_of_any("01234", {'5', '2'}, 2, 1));
      assert::are_equal(std::string::npos, strings::index_of_any("01234", {'5', '3'}, 0, 2));
    }
    
    void test_method_(insert) {
      assert::are_equal("012345", strings::insert("345", 0, "012"));
    }
    
    void test_method_(join_const_char_pointer_array) {
      assert::are_equal("One, Two, Three", strings::join(", ", {"One", "Two", "Three"}));
    }

    void test_method_(join_int_array) {
      assert::are_equal("1, 2, 3", strings::join(", ", {1, 2, 3}));
    }

    void test_method_(join_int_array_index) {
      assert::are_equal("2, 3, 4, 5", strings::join(", ", {1, 2, 3, 4, 5}, 1));
    }

    void test_method_(join_int_array_index_count) {
      assert::are_equal("2, 3", strings::join(", ", {1, 2, 3, 4, 5}, 1, 2));
    }
    
    void test_method_(last_index_of_char) {
      assert::are_equal(3U, strings::last_index_of("01234", '3'));
      assert::are_equal(5U, strings::last_index_of("0123434", '3'));
    }
    
    void test_method_(last_index_of_string) {
      assert::are_equal(2U, strings::last_index_of("01234", "23"));
      assert::are_equal(5U, strings::last_index_of("0123423", "23"));
    }
    
    void test_method_(last_index_of_char_start_index) {
      assert::are_equal(5U, strings::last_index_of("0123434", '3', 4));
    }
    
    void test_method_(last_index_of_string_start_index) {
      assert::are_equal(5U, strings::last_index_of("0123423", "23", 3));
    }
    
    void test_method_(last_index_of_char_start_index_count) {
      assert::are_equal(std::string::npos, strings::last_index_of("012346734", '3', 4, 2));
    }
    
    void test_method_(last_index_of_string_start_index_count) {
      assert::are_equal(std::string::npos, strings::last_index_of("012346723", "23", 3, 2));
    }
    
    void test_method_(last_index_of_any) {
      assert::are_equal(3U, strings::last_index_of_any("01234", {'5', '3', '2'}));
    }
    
    void test_method_(last_index_of_any_start_index) {
      assert::are_equal(3U, strings::last_index_of_any("01234", {'5', '3', '2'}, 3));
    }
    
    void test_method_(last_index_of_any_start_index_and_count) {
      assert::are_equal(2U, strings::last_index_of_any("01234", {'5', '2'}, 2, 1));
      assert::are_equal(std::string::npos, strings::last_index_of_any("01234", {'5', '3'}, 0, 2));
    }

    void test_method_(pad_left) {
      assert::are_equal("       str", strings::pad_left("str", 10));
    }
    
    void test_method_(pad_left_mul) {
      assert::are_equal("*******str", strings::pad_left("str", 10, '*'));
    }

    void test_method_(pad_right) {
      assert::are_equal("str       ", strings::pad_right("str", 10));
    }
    
    void test_method_(pad_right_mul) {
      assert::are_equal("str*******", strings::pad_right("str", 10, '*'));
    }

    void test_method_(remove_start_index) {
      assert::are_equal("012", strings::remove("0123456", 3));
    }
    
    void test_method_(remove_start_index_count) {
      assert::are_equal("01256", strings::remove("0123456", 3, 2));
    }

    void test_method_(remove_start_index_out_of_range) {
      assert::are_equal("0123456", strings::remove("0123456", 10));
    }

    void test_method_(remove_start_index_count_out_of_range) {
      assert::are_equal("012", strings::remove("0123456", 3, 10));
    }

    void test_method_(replace_char) {
      assert::are_equal("accribuce", strings::replace("attribute", 't', 'c'));
    }
    
    void test_method_(replace_string) {
      assert::are_equal("hola world and hola me", strings::replace("hello world and hello me", "hello", "hola"));
    }
    
    void test_method_(split) {
      collection_assert::are_equal({"One", "Two", "Three", "Four", "Five", "Six", "Seven"}, strings::split("One Two\vThree\fFour\rFive\nSix\nSeven"));
    }
    
    void test_method_(split_empty_separators) {
      collection_assert::are_equal({"One", "Two", "Three", "Four", "Five", "Six", "Seven"}, strings::split("One Two\vThree\fFour\rFive\nSix\nSeven", {}));
    }
    
    void test_method_(split_one_separators) {
      collection_assert::are_equal({"One Two", "Three", "Four", "Five", "Six", "Seven"}, strings::split("One Two,Three,Four,Five,Six,Seven", {','}));
    }
    
    void test_method_(split_separators) {
      collection_assert::are_equal({"One", "Two", "", "Three", "", "Four", "Five", "Six", "Seven"}, strings::split("One Two::Three,:Four.Five/Six,Seven", {' ', ',', ':', '.', '/'}));
    }
    
    void test_method_(split_separators_split_option_none) {
      collection_assert::are_equal({"One", "Two", "", "Three", "", "Four", "Five", "Six", "Seven"}, strings::split("One Two::Three,:Four.Five/Six,Seven", {' ', ',', ':', '.', '/'}, string_split_options::none));
    }
    
    void test_method_(split_separators_split_option_remove_empty_entries) {
      collection_assert::are_equal({"One", "Two", "Three", "Four", "Five", "Six", "Seven"}, strings::split("One      Two::Three,:Four......Five/Six,,,,,,,Seven", {' ', ',', ':', '.', '/'}, string_split_options::remove_empty_entries));
    }
    
    void test_method_(split_separators_count_split_option_remove_empty_entries) {
      collection_assert::are_equal({"One", "Two", "Three,:Four......Five/Six,,,,,,,Seven"}, strings::split("One      Two::Three,:Four......Five/Six,,,,,,,Seven", {' ', ',', ':', '.', '/'}, 3, string_split_options::remove_empty_entries));
    }
    
    void test_method_(start_with_char) {
      assert::is_true(strings::starts_with("Hello, World!", 'H'));
      assert::is_false(strings::starts_with("Hello, World!", 'h'));
    }
 
    void test_method_(start_with_char_ignore_case_false) {
      assert::is_true(strings::starts_with("Hello, World!", 'H', false));
      assert::is_false(strings::starts_with("Hello, World!", 'h', false));
    }
    
    void test_method_(start_with_char_ignore_case_true) {
      assert::is_true(strings::starts_with("Hello, World!", 'H', true));
      assert::is_true(strings::starts_with("Hello, World!", 'h', true));
    }

    void test_method_(start_with_string) {
      assert::is_true(strings::starts_with("Hello, World!", "Hello"));
      assert::is_false(strings::starts_with("Hello, World!", "hello"));
    }

    void test_method_(start_with_string_ignore_case_false) {
      assert::is_true(strings::starts_with("Hello, World!", "Hello", false));
      assert::is_false(strings::starts_with("Hello, World!", "hello", false));
    }
    
    void test_method_(start_with_string_ignore_case_true) {
      assert::is_true(strings::starts_with("Hello, World!", "Hello", true));
      assert::is_true(strings::starts_with("Hello, World!", "hello", true));
    }
    
    void test_method_(substring) {
      assert::are_equal("23456", strings::substring("0123456", 2));
    }
    
    void test_method_(substring_length) {
      assert::are_equal("234", strings::substring("0123456", 2, 3));
    }
    
    void test_method_(substring_start_index_out_of_range) {
      assert::are_equal("", strings::substring("0123456", 10));
    }
    
    void test_method_(substring_count_out_of_range) {
      assert::are_equal("23456", strings::substring("0123456", 2, 10));
    }
    
    void test_method_(to_array) {
      collection_assert::are_equal({'0', '1', '2', '3', '4', '5', '6'}, strings::to_array("0123456"));
    }
    
    void test_method_(to_array_start_index) {
      collection_assert::are_equal({'2', '3', '4', '5', '6'}, strings::to_array("0123456", 2));
    }
    
    void test_method_(to_array_start_index_length) {
      collection_assert::are_equal({'2', '3', '4'}, strings::to_array("0123456", 2, 3));
    }
    
    void test_method_(to_array_start_index_out_of_range) {
      collection_assert::are_equal(std::vector<char> {}, strings::to_array("0123456", 10));
    }
    
    void test_method_(to_array_start_index_length_out_of_range) {
      collection_assert::are_equal({'2', '3', '4', '5', '6'}, strings::to_array("0123456", 2, 10));
    }
    
    void test_method_(to_lower) {
      assert::are_equal("abcdef", strings::to_lower("ABCDEF"));
    }
    
    void test_method_(to_upper) {
      assert::are_equal("ABCDEF", strings::to_upper("abcdef"));
    }
    
    void test_method_(trim_end) {
      assert::are_equal("abcdef", strings::trim_end("abcdef   "));
    }
    
    void test_method_(trim_end_char) {
      assert::are_equal("abcdef", strings::trim_end("abcdef***", '*'));
    }

    void test_method_(trim_end_chars) {
      assert::are_equal("abcdef", strings::trim_end("abcdef****   +++", {'*', ' ', '+'}));
    }
    
    void test_method_(trim_start) {
      assert::are_equal("abcdef", strings::trim_start("   abcdef"));
    }
    
    void test_method_(trim_start_char) {
      assert::are_equal("abcdef", strings::trim_start("***abcdef", '*'));
    }
    
    void test_method_(trim_start_chars) {
      assert::are_equal("abcdef", strings::trim_start("****   +++abcdef", {'*', ' ', '+'}));
    }
    
    void test_method_(trim) {
      assert::are_equal("abcdef", strings::trim("   abcdef     "));
    }
    
    void test_method_(trim_char) {
      assert::are_equal("abcdef", strings::trim("***abcdef******", '*'));
    }
    
    void test_method_(trim_chars) {
      assert::are_equal("abcdef", strings::trim("****   +++abcdef** ++++++    **", {'*', ' ', '+'}));
    }
  };
}
