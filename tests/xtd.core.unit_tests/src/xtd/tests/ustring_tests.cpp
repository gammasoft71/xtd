#include <xtd/string>
#include <xtd/argument_out_of_range_exception>
#include <xtd/index_out_of_range_exception>
#include <xtd/null_pointer_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(ustring_tests) {
    void test_method_(default_constructor) {
      string s;
      assert::is_zero(s.length(), csf_);
      assert::is_true(string::is_empty(s), csf_);
    }
    
    void test_method_(constructor_with_ustring) {
      string s1 = "test";
      string s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(constructor_with_literal) {
      string s = "test";
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(constructor_with_string) {
      std::string s1 = "test";
      string s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(constructor_with_w_literal) {
      string s = L"test";
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(constructor_with_wstring) {
      std::wstring s1 = L"test";
      string s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(constructor_with_u8_literal) {
      string s = u8"test";
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_u8string) {
      std::u8string s1 = u8"test";
      string s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
#endif
    
    void test_method_(constructor_with_u16_literal) {
      string s = u"test";
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(constructor_with_u16string) {
      std::u16string s1 = u"test";
      string s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(constructor_with_u32_literal) {
      string s = U"test";
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(constructor_with_u32string) {
      std::u32string s1 = U"test";
      string s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(constructor_with_char_ptr_null) {
      char* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }

    void test_method_(constructor_with_const_char_ptr_null) {
      const char* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(constructor_with_char8_ptr_null) {
      char8* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(constructor_with_const_char8_ptr_null) {
      const char8* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
#endif
    
    void test_method_(constructor_with_char16_ptr_null) {
      char16* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(constructor_with_const_char16_ptr_null) {
      const char16* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(constructor_with_char32_ptr_null) {
      char32* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(constructor_with_const_char32_ptr_null) {
      const char32* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(constructor_with_wchar_ptr_null) {
      wchar* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(constructor_with_const_wchar_ptr_null) {
      const wchar* ptr = nullptr;
      assert::throws<null_pointer_exception>([&]{string s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_string) {
      auto s1 = std::string {"test"};
      string s2;
      s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_equal_with_u8string1) {
      auto s1 = std::u8string {u8"test"};
      string s2;
      s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
#endif
    
    void test_method_(operator_equal_with_u16string1) {
      auto s1 = std::u16string {u"test"};
      string s2;
      s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(operator_equal_with_u32string1) {
      auto s1 = std::u32string {U"test"};
      string s2;
      s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(operator_equal_with_ustring1) {
      auto s1 = string {"test"};
      string s2;
      s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }
    
    void test_method_(operator_equal_with_wstring1) {
      auto s1 = std::wstring {L"test"};
      string s2;
      s2 = s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("test", s2, csf_);
    }

    void test_method_(operator_equal_with_literal) {
      auto p = "test";
      string s;
      s = p;
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }

    void test_method_(operator_equal_with_non_const_literal) {
      auto p = "test";
      string s;
      s = const_cast<char*>(p);
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }

    void test_method_(operator_equal_with_u8_literal) {
      auto p = u8"test";
      string s;
      s = p;
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_equal_with_non_const_u8_literal) {
      auto p = u8"test";
      string s;
      s = const_cast<char8*>(p);
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
#endif

    void test_method_(operator_equal_with_u16_literal) {
      auto p = u"test";
      string s;
      s = p;
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(operator_equal_with_non_const_u16_literal) {
      auto p = u"test";
      string s;
      s = const_cast<char16*>(p);
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }

    void test_method_(operator_equal_with_u32_literal) {
      auto p = U"test";
      string s;
      s = p;
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(operator_equal_with_non_const_u32_literal) {
      auto p = U"test";
      string s;
      s = const_cast<char32*>(p);
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }

    void test_method_(operator_equal_with_w_literal) {
      auto p = L"test";
      string s;
      s = p;
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }
    
    void test_method_(operator_equal_with_non_const_w_literal) {
      auto p = L"test";
      string s;
      s = const_cast<wchar*>(p);
      assert::are_equal(4_z, s.length(), csf_);
      assert::are_equal("test", s, csf_);
    }

    void test_method_(operator_equal_with_char_ptr_null) {
      char* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_const_char_ptr_null) {
      const char* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_equal_with_char8_ptr_null) {
      char8* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_const_char8_ptr_null) {
      const char8* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
#endif
    
    void test_method_(operator_equal_with_char16_ptr_null) {
      char16* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_const_char16_ptr_null) {
      const char16* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_char32_ptr_null) {
      char32* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_const_char32_ptr_null) {
      const char32* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_wchar_ptr_null) {
      wchar* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_equal_with_const_wchar_ptr_null) {
      const wchar* ptr = nullptr;
      string s;
      assert::throws<null_pointer_exception>([&]{s = ptr;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_string) {
      auto s1 = std::string {"s1"};
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_plus_equal_with_u8string) {
      auto s1 = std::u8string {u8"s1"};
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
#endif
    
    void test_method_(operator_plus_equal_with_u16string) {
      auto s1 = std::u16string {u"s1"};
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_u32string) {
      auto s1 = std::u32string {U"s1"};
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_ustring) {
      auto s1 = string {"s1"};
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_wstring) {
      auto s1 = std::wstring {L"s1"};
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_literal) {
      auto s1 = "s1";
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_u8_literal) {
      auto s1 = u8"s1";
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_u16_literal) {
      auto s1 = u"s1";
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_u32_literal) {
      auto s1 = U"s1";
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_w_literal) {
      auto s1 = L"s1";
      string s2 = "s2";
      s2 += s1;
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_cast_literal) {
      auto s1 = "s1";
      string s2 = "s2";
      s2 += const_cast<char*>(s1);
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_plus_equal_with_const_cast_u8_literal) {
      auto s1 = u8"s1";
      string s2 = "s2";
      s2 += const_cast<char8*>(s1);
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
#endif
    
    void test_method_(operator_plus_equal_with_const_cast_u16_literal) {
      auto s1 = u"s1";
      string s2 = "s2";
      s2 += const_cast<char16*>(s1);
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_cast_u32_literal) {
      auto s1 = U"s1";
      string s2 = "s2";
      s2 += const_cast<char32*>(s1);
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_cast_w_literal) {
      auto s1 = L"s1";
      string s2 = "s2";
      s2 += const_cast<wchar*>(s1);
      assert::are_equal(4_z, s2.length(), csf_);
      assert::are_equal("s2s1", s2, csf_);
    }
    
    void test_method_(operator_plus_equal_with_char_ptr_null) {
      char* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_char_ptr_null) {
      const char* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_plus_equal_with_char8_ptr_null) {
      char8* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_char8_ptr_null) {
      const char8* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
#endif
    
    void test_method_(operator_plus_equal_with_char16_ptr_null) {
      char16* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_char16_ptr_null) {
      const char16* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_char32_ptr_null) {
      char32* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_char32_ptr_null) {
      const char32* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_wchar_ptr_null) {
      wchar* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }
    
    void test_method_(operator_plus_equal_with_const_wchar_ptr_null) {
      const wchar* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&] {s2 += s1;}, csf_);
    }

    void test_method_(operator_plus_with_string) {
      auto s1 = std::string {"s1"};
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_plus_with_u8string) {
      auto s1 = std::u8string {u8"s1"};
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
#endif
    
    void test_method_(operator_plus_with_u16string) {
      auto s1 = std::u16string {u"s1"};
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
    
    void test_method_(operator_plus_with_u32string) {
      auto s1 = std::u32string {U"s1"};
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
    
    void test_method_(operator_plus_with_ustring) {
      auto s1 = string {"s1"};
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
    
    /*
    void test_method_(operator_plus_with_wstring) {
      auto s1 = std::wstring {L"s1"};
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
     */

    void test_method_(operator_plus_with_literal) {
      auto s1 = "s1";
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_u8_literal) {
      auto s1 = u8"s1";
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_u16_literal) {
      auto s1 = u"s1";
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_u32_literal) {
      auto s1 = U"s1";
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_w_literal) {
      auto s1 = L"s1";
      string s2 = "s2";
      string s3 = s2 + s1;
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_const_cast_literal) {
      auto s1 = "s1";
      string s2 = "s2";
      string s3 = s2 + const_cast<char*>(s1);
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_plus_with_const_cast_u8_literal) {
      auto s1 = u8"s1";
      string s2 = "s2";
      string s3 = s2 + const_cast<char8*>(s1);
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }
#endif

    void test_method_(operator_plus_with_const_cast_u16_literal) {
      auto s1 = u"s1";
      string s2 = "s2";
      string s3 = s2 + const_cast<char16*>(s1);
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_const_cast_u32_literal) {
      auto s1 = U"s1";
      string s2 = "s2";
      string s3 = s2 + const_cast<char32*>(s1);
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_const_cast_w_literal) {
      auto s1 = L"s1";
      string s2 = "s2";
      string s3 = s2 + const_cast<wchar*>(s1);
      assert::are_equal(4_z, s3.length(), csf_);
      assert::are_equal("s2s1", s3, csf_);
    }

    void test_method_(operator_plus_with_char_ptr_null) {
      char* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }
    
    void test_method_(operator_plus_with_const_char_ptr_null) {
      const char* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_plus_with_char8_ptr_null) {
      char8* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }
    
    void test_method_(operator_plus_with_const_char8_ptr_null) {
      const char8* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }
#endif

    void test_method_(operator_plus_with_char16_ptr_null) {
      char16* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }
    
    void test_method_(operator_plus_with_const_char16_ptr_null) {
      const char16* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }

    void test_method_(operator_plus_with_char32_ptr_null) {
      char32* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }
    
    void test_method_(operator_plus_with_const_char32_ptr_null) {
      const char32* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }

    void test_method_(operator_plus_with_wchar_ptr_null) {
      wchar* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }
    
    void test_method_(operator_plus_with_const_wchar_ptr_null) {
      const wchar* s1 = nullptr;
      string s2 = "s2";
      assert::throws<null_pointer_exception>([&]{string s3 = s2 + s1;}, csf_);
    }

    void test_method_(compare) {
      assert::is_zero(string::compare("a", "a"), csf_);
      assert::is_negative(string::compare("a", "b"), csf_);
      assert::is_positive(string::compare("b", "a"), csf_);
    }
    
    void test_method_(compare_ignore_case_false) {
      assert::is_not_zero(string::compare("a", "A", false), csf_);
    }
    
    void test_method_(compare_ignore_case_true) {
      assert::is_zero(string::compare("a", "A", true), csf_);
    }
    
    void test_method_(compare_index_length) {
      assert::is_not_zero(string::compare("abcde", 1, "debcaf", 1, 2), csf_);
      assert::is_zero(string::compare("abcde", 1, "debcaf", 2, 2), csf_);
    }
    
    void test_method_(compare_index_length_ingore_case_false) {
      assert::is_not_zero(string::compare("abcde", 1, "DEBCAF", 2, 2, false), csf_);
    }
    
    void test_method_(compare_index_length_ingore_case_true) {
      assert::is_zero(string::compare("abcde", 1, "DEBCAF", 2, 2, true), csf_);
    }
    
    void test_method_(concat_char_pointers) {
      assert::are_equal("abcd", string::concat("a", "b", "c", "d"), csf_);
    }
    
    void test_method_(concat_strings) {
      assert::are_equal("abcd", string::concat(std::string {"a"}, std::string {"b"}, std::string {"c"}, std::string {"d"}), csf_);
    }
    
    void test_method_(concat_ints) {
      assert::are_equal("124342", string::concat(1, 24, 3, 42), csf_);
    }
    
    void test_method_(concat_any) {
      assert::are_equal("12434.2", string::concat("1", 24, '3', 4.2), csf_);
    }
    
    void test_method_(concat_initializer_list) {
      assert::are_equal(L"1234", string::concat({L"1", L"2", L"3", L"4"}), csf_);
    }
    
    void test_method_(concat_vector) {
      assert::are_equal(L"1234", string::concat(std::vector {L"1", L"2", L"3", L"4"}), csf_);
    }
    
    void test_method_(contains) {
      assert::is_true(string("abcd").contains("bc"), csf_);
      assert::is_false(string("abcd").contains("ad"), csf_);
    }
    
    void test_method_(ends_with_char) {
      assert::is_true(string("abcd").ends_with('d'), csf_);
      assert::is_false(string("abcd").ends_with('D'), csf_);
      assert::is_false(string("abcd").ends_with('B'), csf_);
    }
    
    void test_method_(ends_with_string) {
      assert::is_true(string("abcd").ends_with("cd"), csf_);
      assert::is_false(string("abcd").ends_with("ab"), csf_);
    }
    
    void test_method_(ends_with_string_ignore_case_false) {
      assert::is_true(string("abcd").ends_with("cd", false), csf_);
      assert::is_false(string("abcd").ends_with("CD", false), csf_);
      assert::is_false(string("abcd").ends_with("AB", false), csf_);
    }
    
    void test_method_(ends_with_string_ignore_case_true) {
      assert::is_true(string("abcd").ends_with("cd", true), csf_);
      assert::is_true(string("abcd").ends_with("CD", true), csf_);
      assert::is_false(string("abcd").ends_with("AB", true), csf_);
    }
    
    void test_method_(string_format_with_automatic_arguments) {
      assert::are_equal("42 str 24", string::format("{} {} {}", 42, "str", 24), csf_);
    }
    
    void test_method_(string_format_with_indexed_arguments) {
      assert::are_equal("42 str 24 str 42", string::format("{0} {1} {2} {1} {0}", 42, "str", 24), csf_);
    }
    
    void test_method_(string_sprintf_with_one_argument) {
      std::string s = string::sprintf("%d", 42);
      assert::are_equal("42", s, csf_);
    }
    
    void test_method_(wstring_sprintf_with_one_argument) {
      assert::are_equal(L"42", string::sprintf(L"%d", 42), csf_);
    }
    
    void test_method_(u16string_sprintf_with_one_argument) {
      assert::are_equal(u"42", string::sprintf(u"%d", 42), csf_);
    }
    
    void test_method_(u32string_sprintf_with_one_argument) {
      assert::are_equal(U"42", string::sprintf(U"%d", 42), csf_);
    }
    
    void test_method_(string_sprintf_with_string_argument) {
      assert::are_equal("str", string::sprintf("%s", std::string {"str"}), csf_);
    }
    
    /// @todo Debug on Windows
    ///void test_method_(wstring_sprintf_with_string_argument) {
    ///  assert::are_equal(L"str", string::sprintf(L"%s", "str"s), csf_);
    ///}
    
    void test_method_(string_sprintf_with_wstring_argument) {
      assert::are_equal("str", string::sprintf("%ls", std::wstring {L"str"}), csf_);
    }
    
    void test_method_(wstring_sprintf_with_wstring_argument) {
      assert::are_equal(L"str", string::sprintf(L"%ls", std::wstring {L"str"}), csf_);
    }
    
    void test_method_(get_hash_code) {
      assert::are_equal(string("01234").get_hash_code(), string("01234").get_hash_code(), csf_);
      assert::are_not_equal(string("01235").get_hash_code(), string("01234").get_hash_code(), csf_);
    }
    
    void test_method_(index_of_char) {
      assert::are_equal(3_z, string("01234").index_of('3'), csf_);
      assert::are_equal(3_z, string("0123434").index_of('3'), csf_);
    }
    
    void test_method_(index_of_string) {
      assert::are_equal(2_z, string("01234").index_of("23"), csf_);
      assert::are_equal(2_z, string("0123423").index_of("23"), csf_);
    }
    
    void test_method_(index_of_char_start_index) {
      assert::are_equal(5_z, string("0123434").index_of('3', 4), csf_);
    }
    
    void test_method_(index_of_string_start_index) {
      assert::are_equal(5_z, string("0123423").index_of("23", 3), csf_);
    }
    
    void test_method_(index_of_char_start_index_count) {
      assert::are_equal(string::npos, string("012346734").index_of('3', 4, 2), csf_);
    }
    
    void test_method_(index_of_string_start_index_count) {
      assert::are_equal(string::npos, string("012346723").index_of("23", 3, 2), csf_);
    }
    
    void test_method_(index_of_any) {
      assert::are_equal(2_z, string("01234").index_of_any({'5', '3', '2'}), csf_);
    }
    
    void test_method_(index_of_any_start_index) {
      assert::are_equal(3_z, string("01234").index_of_any({'5', '3', '2'}, 3), csf_);
    }
    
    void test_method_(index_of_any_start_index_and_count) {
      assert::are_equal(2_z, string("01234").index_of_any({'5', '2'}, 2, 1), csf_);
      assert::are_equal(string::npos, string("01234").index_of_any({'5', '3'}, 0, 2), csf_);
    }
    
    void test_method_(insert) {
      assert::are_equal("012345", string("345").insert(0, "012"), csf_);
    }
    
    void test_method_(join_const_char_pointer_array) {
      assert::are_equal("One, Two, Three", string::join(", ", {"One", "Two", "Three"}), csf_);
    }
    
    void test_method_(join_int_array) {
      assert::are_equal("1, 2, 3", string::join(", ", {1, 2, 3}), csf_);
    }
    
    void test_method_(join_int_array_index) {
      assert::are_equal("2, 3, 4, 5", string::join(", ", {1, 2, 3, 4, 5}, 1), csf_);
    }
    
    void test_method_(join_int_array_index_count) {
      assert::are_equal("2, 3", string::join(", ", {1, 2, 3, 4, 5}, 1, 2), csf_);
    }
    
    void test_method_(last_index_of_char) {
      assert::are_equal(3_z, string("01234").last_index_of('3'), csf_);
      assert::are_equal(5_z, string("0123434").last_index_of('3'), csf_);
    }
    
    void test_method_(last_index_of_string) {
      assert::are_equal(2_z, string("01234").last_index_of("23"), csf_);
      assert::are_equal(5_z, string("0123423").last_index_of("23"), csf_);
    }
    
    void test_method_(last_index_of_char_start_index) {
      assert::are_equal(5_z, string("0123434").last_index_of('3', 4), csf_);
    }
    
    void test_method_(last_index_of_string_start_index) {
      assert::are_equal(5_z, string("0123423").last_index_of("23", 3), csf_);
    }
    
    void test_method_(last_index_of_char_start_index_count) {
      assert::are_equal(string::npos, string("012346734").last_index_of('3', 4, 2), csf_);
    }
    
    void test_method_(last_index_of_string_start_index_count) {
      assert::are_equal(string::npos, string("012346723").last_index_of("23", 3, 2), csf_);
    }
    
    void test_method_(last_index_of_any) {
      assert::are_equal(3_z, string("01234").last_index_of_any({'5', '3', '2'}), csf_);
    }
    
    void test_method_(last_index_of_any_start_index) {
      assert::are_equal(3_z, string("01234").last_index_of_any({'5', '3', '2'}, 3), csf_);
    }
    
    void test_method_(last_index_of_any_start_index_and_count) {
      assert::are_equal(2_z, string("01234").last_index_of_any({'5', '2'}, 2, 1), csf_);
      assert::are_equal(string::npos, string("01234").last_index_of_any({'5', '3'}, 0, 2), csf_);
    }
    
    void test_method_(pad_left) {
      assert::are_equal("       str", string("str").pad_left(10), csf_);
    }
    
    void test_method_(pad_left_mul) {
      assert::are_equal("*******str", string("str").pad_left(10, '*'), csf_);
    }
    
    void test_method_(pad_right) {
      assert::are_equal("str       ", string("str").pad_right(10), csf_);
    }
    
    void test_method_(pad_right_mul) {
      assert::are_equal("str*******", string("str").pad_right(10, '*'), csf_);
    }
    
    void test_method_(remove_start_index) {
      assert::are_equal("012", string("0123456").remove(3), csf_);
    }
    
    void test_method_(remove_start_index_count) {
      assert::are_equal("01256", string("0123456").remove(3, 2), csf_);
    }
    
    void test_method_(remove_start_index_out_of_range) {
      assert::throws<index_out_of_range_exception>([]{string("0123456").remove(10);}, csf_);
    }
    
    void test_method_(remove_start_index_count_out_of_range) {
      assert::throws<index_out_of_range_exception>([]{string("0123456").remove(3, 10);}, csf_);
    }
    
    void test_method_(replace_char) {
      assert::are_equal("accribuce", string("attribute").replace('t', 'c'), csf_);
    }
    
    void test_method_(replace_string) {
      assert::are_equal("ola world and ola me", string("hello world and hello me").replace("hello", "ola"), csf_);
    }
    
    void test_method_(split) {
      collection_assert::are_equal({"One", "Two", "Three", "Four", "Five", "Six", "Seven"}, string("One Two\vThree\fFour\rFive\nSix\nSeven").split(), csf_);
    }
    
    void test_method_(split_empty_separators) {
      collection_assert::are_equal({"One", "Two", "Three", "Four", "Five", "Six", "Seven"}, string("One Two\vThree\fFour\rFive\nSix\nSeven").split(array<char> {}), csf_);
    }
    
    void test_method_(split_one_separators) {
      collection_assert::are_equal({"One Two", "Three", "Four", "Five", "Six", "Seven"}, string("One Two,Three,Four,Five,Six,Seven").split(','), csf_);
    }
    
    void test_method_(split_separators) {
      collection_assert::are_equal({"One", "Two", "", "Three", "", "Four", "Five", "Six", "Seven"}, string("One Two::Three,:Four.Five/Six,Seven").split({' ', ',', ':', '.', '/'}), csf_);
    }
    
    void test_method_(split_separators_split_option_none) {
      collection_assert::are_equal({"One", "Two", "", "Three", "", "Four", "Five", "Six", "Seven"}, string("One Two::Three,:Four.Five/Six,Seven").split({' ', ',', ':', '.', '/'}, string_split_options::none), csf_);
    }
    
    void test_method_(split_separators_split_option_remove_empty_entries) {
      collection_assert::are_equal({"One", "Two", "Three", "Four", "Five", "Six", "Seven"}, string("One      Two::Three,:Four......Five/Six,,,,,,,Seven").split({' ', ',', ':', '.', '/'}, string_split_options::remove_empty_entries), csf_);
    }
    
    void test_method_(split_separators_count_split_option_remove_empty_entries) {
      collection_assert::are_equal({"One", "Two", "Three,:Four......Five/Six,,,,,,,Seven"}, string("One      Two::Three,:Four......Five/Six,,,,,,,Seven").split({' ', ',', ':', '.', '/'}, 3, string_split_options::remove_empty_entries), csf_);
    }
    
    void test_method_(start_with_char) {
      assert::is_true(string("Hello, World!").starts_with('H'), csf_);
      assert::is_false(string("Hello, World!").starts_with('h'), csf_);
    }
    
    void test_method_(start_with_char_ignore_case_false) {
      assert::is_true(string("Hello, World!").starts_with('H', false), csf_);
      assert::is_false(string("Hello, World!").starts_with('h', false), csf_);
    }
    
    void test_method_(start_with_char_ignore_case_true) {
      assert::is_true(string("Hello, World!").starts_with('H', true), csf_);
      assert::is_true(string("Hello, World!").starts_with('h', true), csf_);
    }
    
    void test_method_(start_with_string) {
      assert::is_true(string("Hello, World!").starts_with("Hello"), csf_);
      assert::is_false(string("Hello, World!").starts_with("hello"), csf_);
    }
    
    void test_method_(start_with_string_ignore_case_false) {
      assert::is_true(string("Hello, World!").starts_with("Hello", false), csf_);
      assert::is_false(string("Hello, World!").starts_with("hello", false), csf_);
    }
    
    void test_method_(start_with_string_ignore_case_true) {
      assert::is_true(string("Hello, World!").starts_with("Hello", true), csf_);
      assert::is_true(string("Hello, World!").starts_with("hello", true), csf_);
    }
    
    void test_method_(substring) {
      assert::are_equal("23456", string("0123456").substring(2), csf_);
    }
    
    void test_method_(substring_length) {
      assert::are_equal("234", string("0123456").substring(2, 3), csf_);
    }
    
    void test_method_(substring_start_index_out_of_range) {
      assert::throws<argument_out_of_range_exception>([]{string("0123456").substring(10);}, csf_);
    }
    
    void test_method_(substring_count_out_of_range) {
      assert::throws<argument_out_of_range_exception>([]{string("0123456").substring(2, 10);}, csf_);
    }
    
    void test_method_(to_array) {
      collection_assert::are_equal({'0', '1', '2', '3', '4', '5', '6'}, string("0123456").to_array(), csf_);
    }
    
    void test_method_(to_array_start_index) {
      collection_assert::are_equal({'2', '3', '4', '5', '6'}, string("0123456").to_array(2), csf_);
    }
    
    void test_method_(to_array_start_index_length) {
      collection_assert::are_equal({'2', '3', '4'}, string("0123456").to_array(2, 3), csf_);
    }
    
    void test_method_(to_array_start_index_out_of_range) {
      collection_assert::are_equal(std::vector<char> {}, string("0123456").to_array(10), csf_);
    }
    
    void test_method_(to_array_start_index_length_out_of_range) {
      collection_assert::are_equal({'2', '3', '4', '5', '6'}, string("0123456").to_array(2, 10), csf_);
    }
    
    void test_method_(to_lower) {
      assert::are_equal("abcdef", string("ABCDEF").to_lower(), csf_);
    }
    
    void test_method_(to_title_case) {
      assert::are_equal("Abc DEF Ghi Jkl Mno", string("abc DEF gHi JKl mnO").to_title_case(), csf_);
    }
    
    void test_method_(to_upper) {
      assert::are_equal("ABCDEF", string("abcdef").to_upper(), csf_);
    }
    
    void test_method_(trim_end) {
      assert::are_equal("abcdef", string("abcdef   ").trim_end(), csf_);
    }
    
    void test_method_(trim_end_char) {
      assert::are_equal("abcdef", string("abcdef***").trim_end('*'), csf_);
    }
    
    void test_method_(trim_end_chars) {
      assert::are_equal("abcdef", string("abcdef****   +++").trim_end({'*', ' ', '+'}), csf_);
    }
    
    void test_method_(trim_start) {
      assert::are_equal("abcdef", string("   abcdef").trim_start(), csf_);
    }
    
    void test_method_(trim_start_char) {
      assert::are_equal("abcdef", string("***abcdef").trim_start('*'), csf_);
    }
    
    void test_method_(trim_start_chars) {
      assert::are_equal("abcdef", string("****   +++abcdef").trim_start({'*', ' ', '+'}), csf_);
    }
    
    void test_method_(trim) {
      assert::are_equal("abcdef", string("   abcdef     ").trim(), csf_);
    }
    
    void test_method_(trim_char) {
      assert::are_equal("abcdef", string("***abcdef******").trim('*'), csf_);
    }
    
    void test_method_(trim_chars) {
      assert::are_equal("abcdef", string("****   +++abcdef** ++++++    **").trim({'*', ' ', '+'}), csf_);
    }
  };
}
