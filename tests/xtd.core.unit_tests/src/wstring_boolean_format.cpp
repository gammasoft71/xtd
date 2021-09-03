#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_wstring_boolean_format) {
  public:
    void test_method_(format_false_with_default_argument) {
      assert::are_equal(L"false", xtd::ustring::format(L"{0}", false), csf_);
    }

    void test_method_(format_true_with_default_argument) {
      assert::are_equal(L"true", xtd::ustring::format(L"{0}", true), csf_);
    }

    void test_method_(format_false_with_left_alignment) {
      assert::are_equal(L"     false", ustring::format(L"{0,10}", false), csf_);
    }
    
    void test_method_(format_true_with_left_alignment) {
      assert::are_equal(L"      true", ustring::format(L"{0,10}", true), csf_);
    }
    
    void test_method_(format_false_with_right_alignment) {
      assert::are_equal(L"false     ", ustring::format(L"{0, -10}", false), csf_);
    }
    
    void test_method_(format_true_with_right_alignment) {
      assert::are_equal(L"true      ", ustring::format(L"{0, -10}", true), csf_);
    }
    
    void test_method_(format_false_with_zero_alignment) {
      assert::are_equal(L"false", ustring::format(L"{0,0}", false), csf_);
    }
    
    void test_method_(formatn_true_with_zer_alignment) {
      assert::are_equal(L"true", ustring::format(L"{0,0}", true), csf_);
    }
    
    void test_method_(format_false_with_binary_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:b}", false), csf_);
    }
    
    void test_method_(format_true_with_binaryl_argument) {
      assert::are_equal(L"1", xtd::ustring::format(L"{0:B}", true), csf_);
    }
    
    void test_method_(format_false_with_decimal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:d}", false), csf_);
    }
    
    void test_method_(format_true_with_decimal_argument) {
      assert::are_equal(L"1", xtd::ustring::format(L"{0:D}", true), csf_);
    }
    
    void test_method_(format_false_with_general_argument) {
      assert::are_equal(L"false", xtd::ustring::format(L"{0:g}", false), csf_);
    }
    
    void test_method_(format_true_with_general_argument) {
      assert::are_equal(L"true", xtd::ustring::format(L"{0:G}", true), csf_);
    }

    void test_method_(format_false_with_octal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:o}", false), csf_);
    }
    
    void test_method_(format_true_with_octal_argument) {
      assert::are_equal(L"1", xtd::ustring::format(L"{0:O}", true), csf_);
    }
    
    void test_method_(format_false_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:x}", false), csf_);
    }
    
    void test_method_(format_true_with_hexadecimal_argument) {
      assert::are_equal(L"1", xtd::ustring::format(L"{0:X}", true), csf_);
    }
    
    void test_method_(format_false_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format(L"{0:e}", true);}, csf_);
    }
    
    void test_method_(format_true_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format(L"{0:z1}", true);}, csf_);
    }
  };
}
