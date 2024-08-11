#include <xtd/register_any_stringer>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std::literals;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(any_tests) {
    class foo {
    public:
      foo() = default;
      
      ustring to_string() const noexcept {return "foo string";}
    };
    
    void test_method_(format_empty) {
      std::any a;
      assert::are_equal("{}", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_byte) {
      std::any a = byte(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_char) {
      std::any a = 'a';
      assert::are_equal("a", ustring::format("{}", a), csf_);
    }
    
    /*
    void test_method_(format_char8) {
      std::any a = u8'a';
      assert::are_equal("a", ustring::format("{}", a), csf_);
    }
     */
    
    void test_method_(format_char16) {
      std::any a = u'a';
      assert::are_equal("a", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_char32) {
      std::any a = U'a';
      assert::are_equal("a", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_char_pointer) {
      std::any a = "string";
      assert::are_equal("string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_double) {
      std::any a = double(.42);
      assert::are_equal("0.42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_int16) {
      std::any a = int16(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_int32) {
      std::any a = int32(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_int64) {
      std::any a = int32(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_sbyte) {
      std::any a = sbyte(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_single) {
      std::any a = .42f;
      assert::are_equal("0.42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_string) {
      std::any a = "string"s;
      assert::are_equal("string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_string8) {
      std::any a = u8"string"s;
      assert::are_equal(u8"string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_string16) {
      std::any a = u"string"s;
      assert::are_equal(u"string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_string32) {
      std::any a = U"string"s;
      assert::are_equal(U"string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_uint16) {
      std::any a = uint16(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_uint32) {
      std::any a = uint32(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_uint64) {
      std::any a = uint64(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_ustring) {
      std::any a1 = "string"_s;
      assert::are_equal("string", ustring::format("{}", a1), csf_);
      std::any a2 = u8"string"_s;
      assert::are_equal("string", ustring::format("{}", a2), csf_);
      std::any a3 = u"string"_s;
      assert::are_equal("string", ustring::format("{}", a3), csf_);
      std::any a4 = U"string"_s;
      assert::are_equal("string", ustring::format("{}", a4), csf_);
      std::any a5 = L"string"_s;
      assert::are_equal("string", ustring::format("{}", a5), csf_);
    }
    
    void test_method_(format_wchar) {
      std::any a = L'a';
      assert::are_equal("a", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_wstring) {
      std::any a = L"string"s;
      assert::are_equal(L"string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_without_register_any_stringer) {
      std::any a = foo {};
      assert::are_equal("(unregistered)", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_with_register_any_stringer) {
      std::any a = foo {};
      register_any_stringer<foo>([](auto value) {return value.to_string();});
      assert::are_equal("foo string", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_with_unregister_any_stringer) {
      std::any a = foo {};
      register_any_stringer<foo>([](auto value) {return value.to_string();});
      unregister_any_stringer<foo>();
      assert::are_equal("(unregistered)", ustring::format("{}", a), csf_);
    }
  };
}
