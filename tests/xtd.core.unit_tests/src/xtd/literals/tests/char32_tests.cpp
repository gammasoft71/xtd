#include <xtd/literals/char32>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(char32_tests) {
        auto test_method_(_c_operator_on_unsigned_long_long) {
          auto v = 97_c;
          assert::is_true(is<char32>(v));
          assert::are_equal(L'a'_c, v);
        }
        
        auto test_method_(_c_operator_on_char) {
          auto v = 'a'_c;
          assert::is_true(is<char32>(v));
          assert::are_equal('a'_c, v);
        }
        
        auto test_method_(_c_operator_on_char16) {
          auto v = u'a'_c;
          assert::is_true(is<char32>(v));
          assert::are_equal(u'a'_c, v);
        }
        
        auto test_method_(_c_operator_on_char32) {
          auto v = U'a'_c;
          assert::is_true(is<char32>(v));
          assert::are_equal(U'a'_c, v);
        }
        
        auto test_method_(_c_operator_on_char8) {
          auto v = u8'a'_c;
            assert::is_true(is<char32>(v));
            assert::are_equal(u8'a'_c, v);
        }
        
        auto test_method_(_c_operator_on_wchar) {
          auto v = L'a'_c;
          assert::is_true(is<char32>(v));
          assert::are_equal(L'a'_c, v);
        }
      };
    }
  }
}
