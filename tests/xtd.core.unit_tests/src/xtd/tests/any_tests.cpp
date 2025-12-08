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
    
    auto test_method_(format_empty) {
      any a;
      assert::are_equal("{}", string::format("{}", a));
    }
    
    auto test_method_(format_byte) {
      any a = byte(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_char) {
      any a = 'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    /*
    auto test_method_(format_char8) {
      any a = u8'a';
      assert::are_equal("a", string::format("{}", a));
    }
     */
    
    auto test_method_(format_char16) {
      any a = u'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    auto test_method_(format_char32) {
      any a = U'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    auto test_method_(format_char_pointer) {
      any a = "string";
      assert::are_equal("string", string::format("{}", a));
    }
    
    auto test_method_(format_double) {
      any a = double(.42);
      assert::are_equal("0.42", string::format("{}", a));
    }
    
    auto test_method_(format_int16) {
      any a = int16(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_int32) {
      any a = int32(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_int64) {
      any a = int32(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_sbyte) {
      any a = sbyte(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_single) {
      any a = .42f;
      assert::are_equal("0.42", string::format("{}", a));
    }
    
    auto test_method_(format_std_string) {
      any a = std::string {"string"};
      assert::are_equal("string", string::format("{}", a));
    }
    
    auto test_method_(format_string8) {
      any a = std::u8string {u8"string"};
      assert::are_equal(u8"string", string::format("{}", a));
    }
    
    auto test_method_(format_string16) {
      any a = std::u16string {u"string"};
      assert::are_equal(u"string", string::format("{}", a));
    }
    
    auto test_method_(format_string32) {
      any a = std::u32string {U"string"};
      assert::are_equal(U"string", string::format("{}", a));
    }
    
    auto test_method_(format_uint16) {
      any a = uint16(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_uint32) {
      any a = uint32(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_uint64) {
      any a = uint64(42);
      assert::are_equal("42", string::format("{}", a));
    }
    
    auto test_method_(format_string) {
      any a1 = "string"_s;
      assert::are_equal("string", string::format("{}", a1));
      any a2 = u8"string"_s;
      assert::are_equal("string", string::format("{}", a2));
      any a3 = u"string"_s;
      assert::are_equal("string", string::format("{}", a3));
      any a4 = U"string"_s;
      assert::are_equal("string", string::format("{}", a4));
      any a5 = L"string"_s;
      assert::are_equal("string", string::format("{}", a5));
    }
    
    auto test_method_(format_wchar) {
      any a = L'a';
      assert::are_equal("a", string::format("{}", a));
    }
    
    auto test_method_(format_wstring) {
      any a = std::wstring {L"string"};
      assert::are_equal(L"string", string::format("{}", a));
    }
    
    auto test_method_(format_without_register_any_stringer) {
      any a = foo {};
      assert::are_equal("(unregistered)", string::format("{}", a));
    }
    
    auto test_method_(format_with_register_any_stringer) {
      any a = foo {};
      register_any_stringer<foo>([](auto value) {return value.to_string();});
      assert::are_equal("foo string", string::format("{}", a));
      unregister_any_stringer<foo>();
    }
    
    auto test_method_(format_with_unregister_any_stringer) {
      any a = foo {};
      register_any_stringer<foo>([](auto value) {return value.to_string();});
      unregister_any_stringer<foo>();
      assert::are_equal("(unregistered)", string::format("{}", a));
    }
  };
}
