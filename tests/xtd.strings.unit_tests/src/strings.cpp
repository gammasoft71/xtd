#include <xtd/strings>
#include <xtd/tunit>

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
    
    void test_method_(compare_index_and_length) {
      assert::is_not_zero(strings::compare("abcde", 1, "debcaf", 1, 2));
      assert::is_zero(strings::compare("abcde", 1, "debcaf", 2, 2));
    }
    
    void test_method_(compare_index_length_and_ingore_case_false) {
      assert::is_not_zero(strings::compare("abcde", 1, "DEBCAF", 2, 2, false));
    }
    
    void test_method_(compare_index_length_and_ingore_case_true) {
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
    
    void test_method_(ends_with) {
      assert::is_true(strings::ends_with("abcd", "cd"));
      assert::is_false(strings::ends_with("abcd", "ab"));
    }
    
    void test_method_(ends_with_ignore_case_false) {
      assert::is_true(strings::ends_with("abcd", "cd", false));
      assert::is_false(strings::ends_with("abcd", "CD", false));
      assert::is_false(strings::ends_with("abcd", "AB", false));
    }
    
    void test_method_(ends_with_ignore_case_true) {
      assert::is_true(strings::ends_with("abcd", "cd", true));
      assert::is_true(strings::ends_with("abcd", "CD", true));
      assert::is_false(strings::ends_with("abcd", "AB", true));
    }

    void test_method_(string_format_with_one_argument) {
      std::string s = strings::format("%d", 42);
      assert::are_equal("42", s);
    }
    
    void test_method_(wstring_format_with_one_argument) {
       assert::are_equal(L"42", strings::format(L"%d", 42));
    }

    void test_method_(u16string_format_with_one_argument) {
      assert::are_equal(u"", strings::format(u"%d", 42));
    }

    void test_method_(u32string_format_with_one_argument) {
      assert::are_equal(U"", strings::format(U"%d", 42));
    }

    void test_method_(string_format_with_string_argument) {
      assert::are_equal("str", strings::format("%s", "str"s));
    }

    void test_method_(wstring_format_with_string_argument) {
      assert::are_equal(L"str", strings::format(L"%s", "str"s));
    }

    void test_method_(string_format_with_wstring_argument) {
      assert::are_equal("str", strings::format("%ls", L"str"s));
    }

    void test_method_(wstring_format_with_wstring_argument) {
      assert::are_equal(L"str", strings::format(L"%ls", L"str"s));
    }
    
    void test_method_(index_of_char) {
      assert::are_equal(3, strings::index_of("01234", '3'));
    }
    
    void test_method_(index_of_string) {
      assert::are_equal(2, strings::index_of("01234", "23"));
    }
    
    void test_method_(index_of_char_start_index) {
      assert::are_equal(5, strings::index_of("0123434", '3', 4));
    }
    
    void test_method_(index_of_string_start_index) {
      assert::are_equal(5, strings::index_of("0123423", "23", 3));
    }
    
    void test_method_(index_of_char_start_index_count) {
      assert::are_equal(std::string::npos, strings::index_of("012346734", '3', 4, 2));
    }
    
    void test_method_(index_of_string_start_index_count) {
      assert::are_equal(std::string::npos, strings::index_of("012346723", "23", 3, 2));
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

    void test_method_(replace_char) {
      assert::are_equal("accribuce", strings::replace("attribute", 't', 'c'));
    }

    void test_method_(replace_string) {
      assert::are_equal("hola world and hola me", strings::replace("hello world and hello me", "hello", "hola"));
    }
  };
}
