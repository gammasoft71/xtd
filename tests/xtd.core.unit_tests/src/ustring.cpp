#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_ustring) {
  public:
    void test_method_(default_constructor) {
      ustring s;
      assert::is_zero(s.length());
      assert::is_true_(s.is_empty());
    }

    void test_method_(constructor_with_ustring) {
      ustring s1 = "test";
      ustring s2 = s1;
      assert::are_equal_(4UL, s2.length());
      assert::are_equal_("test", s2);
    }

    void test_method_(constructor_with_literal) {
      ustring s = "test";
      assert::are_equal_(4UL, s.length());
      assert::are_equal_("test", s);
    }

    void test_method_(constructor_with_string) {
      string s1 = "test";
      ustring s2 = s1;
      assert::are_equal_(4UL, s2.length());
      assert::are_equal_("test", s2);
    }

    void test_method_(constructor_with_w_literal) {
      ustring s = L"test";
      assert::are_equal_(4UL, s.length());
      assert::are_equal_("test", s);
    }

    void test_method_(constructor_with_wstring) {
      wstring s1 = L"test";
      ustring s2 = s1;
      assert::are_equal_(4UL, s2.length());
      assert::are_equal_("test", s2);
    }

    void test_method_(constructor_with_u8_literal) {
      ustring s = u8"test";
      assert::are_equal_(4UL, s.length());
      assert::are_equal_("test", s);
    }
    
    void test_method_(constructor_with_u8string) {
      u8string s1 = u8"test";
      ustring s2 = s1;
      assert::are_equal_(4UL, s2.length());
      assert::are_equal_("test", s2);
    }

    void test_method_(constructor_with_u16_literal) {
      ustring s = u"test";
      assert::are_equal_(4UL, s.length());
      assert::are_equal_("test", s);
    }
    
    void test_method_(constructor_with_u16string) {
      u16string s1 = u"test";
      ustring s2 = s1;
      assert::are_equal_(4UL, s2.length());
      assert::are_equal_("test", s2);
    }

    void test_method_(constructor_with_u32_literal) {
      ustring s = U"test";
      assert::are_equal_(4UL, s.length());
      assert::are_equal_("test", s);
    }
    
    void test_method_(constructor_with_u32string) {
      u32string s1 = U"test";
      ustring s2 = s1;
      assert::are_equal_(4UL, s2.length());
      assert::are_equal_("test", s2);
    }
  };
}
