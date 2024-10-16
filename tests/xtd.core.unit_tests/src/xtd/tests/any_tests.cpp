#include <xtd/register_any_stringer>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(any_tests) {
    class foo {
    public:
      foo() = default;
      
      string to_string() const noexcept {return "foo string";}
    };
    
    void test_method_(format_empty) {
      std::any a;
      assert::are_equal("{}", string::format("{}", a));
    }
    
    void test_method_(format_byte) {
      std::any a = byte(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_char) {
      std::any a = 'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    /*
    void test_method_(format_char8) {
      std::any a = u8'a';
      assert::are_equal("a", string::format("{}", a));
    }
     */
    
    void test_method_(format_char16) {
      std::any a = u'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    void test_method_(format_char32) {
      std::any a = U'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    void test_method_(format_char_pointer) {
      std::any a = "string";
      assert::are_equal("string", string::format("{}", a));
    }
    
    void test_method_(format_double) {
      std::any a = double(.42);
      assert::are_equal("0.42", string::format("{}", a));
    }
    
    void test_method_(format_int16) {
      std::any a = int16(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_int32) {
      std::any a = int32(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_int64) {
      std::any a = int32(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_sbyte) {
      std::any a = sbyte(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_single) {
      std::any a = .42f;
      assert::are_equal("0.42", string::format("{}", a));
    }
    
    void test_method_(format_string) {
      std::any a = std::string {"string"};
      assert::are_equal("string", string::format("{}", a));
    }
    
    void test_method_(format_string8) {
#if defined(__xtd__cpp_lib_char8_t)
      std::any a = std::u8string {u8"string"};
      assert::are_equal(u8"string", string::format("{}", a));
#endif
    }
    
    void test_method_(format_string16) {
      std::any a = std::u16string {u"string"};
      assert::are_equal(u"string", string::format("{}", a));
    }
    
    void test_method_(format_string32) {
      std::any a = std::u32string {U"string"};
      assert::are_equal(U"string", string::format("{}", a));
    }
    
    void test_method_(format_uint16) {
      std::any a = uint16(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_uint32) {
      std::any a = uint32(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_uint64) {
      std::any a = uint64(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    void test_method_(format_ustring) {
      std::any a1 = "string"_s;
      assert::are_equal("string", string::format("{}", a1));
      std::any a2 = u8"string"_s;
      assert::are_equal("string", string::format("{}", a2));
      std::any a3 = u"string"_s;
      assert::are_equal("string", string::format("{}", a3));
      std::any a4 = U"string"_s;
      assert::are_equal("string", string::format("{}", a4));
      std::any a5 = L"string"_s;
      assert::are_equal("string", string::format("{}", a5));
    }
    
    void test_method_(format_wchar) {
      std::any a = L'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    void test_method_(format_wstring) {
      std::any a = std::wstring {L"string"};
      assert::are_equal(L"string", string::format("{}", a));
    }
    
    void test_method_(format_without_register_any_stringer) {
      std::any a = foo {};
      assert::are_equal("(unregistered)", string::format("{}", a));
    }
    
    void test_method_(format_with_register_any_stringer) {
      std::any a = foo {};
      register_any_stringer<foo>([](auto value) {return value.to_string();});
      assert::are_equal("foo string", string::format("{}", a));
      unregister_any_stringer<foo>();
    }
    
    void test_method_(format_with_unregister_any_stringer) {
      std::any a = foo {};
      register_any_stringer<foo>([](auto value) {return value.to_string();});
      unregister_any_stringer<foo>();
      assert::are_equal("(unregistered)", string::format("{}", a));
    }
  };
}
