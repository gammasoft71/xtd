#include <xtd/literals>
#include <xtd/is>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(lietarls_tests) {
    //_________________________________________________________________________
    //                                                       Character suffixes
    void test_method_(_c_operator_on_unsigned_long_long) {
      auto v = 97_c;
      assert::is_true(is<char32>(v));
      assert::are_equal(L'a'_c, v);
    }
    
    void test_method_(_c_operator_on_char) {
      auto v = 'a'_c;
      assert::is_true(is<char32>(v));
      assert::are_equal('a'_c, v);
    }
    
    void test_method_(_c_operator_on_char16) {
      auto v = u'a'_c;
      assert::is_true(is<char32>(v));
      assert::are_equal(u'a'_c, v);
    }
    
    void test_method_(_c_operator_on_char32) {
      auto v = U'a'_c;
      assert::is_true(is<char32>(v));
      assert::are_equal(U'a'_c, v);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_c_operator_on_char8) {
      auto v = u8'a'_c;
      assert::is_true(is<char32>(v));
      assert::are_equal(u8'a'_c, v);
    }
#endif
    
    void test_method_(_c_operator_on_wchar) {
      auto v = L'a'_c;
      assert::is_true(is<char32>(v));
      assert::are_equal(L'a'_c, v);
    }
    
    //_________________________________________________________________________
    //                                                         Numeric suffixes
    void test_method_(_b_operator_on_long_double) {
      auto v = 42.0_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_unsigned_long_long) {
      auto v = 42_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_char_ptr) {
      auto v = "42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_b;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_b_operator_on_char8_ptr) {
      auto v = u8"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_b;});
    }
#endif
    
    void test_method_(_b_operator_on_char16_ptr) {
      auto v = u"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_b;});
    }

    void test_method_(_b_operator_on_char32_ptr) {
      auto v = U"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_b;});
    }

    void test_method_(_b_operator_on_wchar_ptr) {
      auto v = L"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_b;});
    }

    void test_method_(_d_operator_on_long_double) {
      auto v = 42.0_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_unsigned_long_long) {
      auto v = 42_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_char_ptr) {
      auto v = "42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_d;});
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_d_operator_on_char8_ptr) {
      auto v = u8"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_d;});
    }
#endif
    
    void test_method_(_d_operator_on_char16_ptr) {
      auto v = u"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_d;});
    }

    void test_method_(_d_operator_on_char32_ptr) {
      auto v = U"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_d;});
    }

    void test_method_(_d_operator_on_wchar_ptr) {
      auto v = L"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_d;});
    }

    void test_method_(_f_operator_on_long_double) {
      auto v = 42.0_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_unsigned_long_long) {
      auto v = 42_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_char_ptr) {
      auto v = "42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_f;});
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_f_operator_on_char8_ptr) {
      auto v = u8"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_f;});
    }
#endif
    
    void test_method_(_f_operator_on_char16_ptr) {
      auto v = u"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_f;});
    }

    void test_method_(_f_operator_on_char32_ptr) {
      auto v = U"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_f;});
    }

    void test_method_(_f_operator_on_wchar_ptr) {
      auto v = L"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_f;});
    }

    void test_method_(_i8_operator_on_long_double) {
      auto v = 42.0_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_unsigned_long_long) {
      auto v = 42_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_char_ptr) {
      auto v = "42"_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_i8;});
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_i8_operator_on_char8_ptr) {
      auto v = u8"42"_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_i8;});
    }
#endif
    
    void test_method_(_i8_operator_on_char16_ptr) {
      auto v = u"42"_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_i8;});
    }

    void test_method_(_i8_operator_on_char32_ptr) {
      auto v = U"42"_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_i8;});
    }

    void test_method_(_i8_operator_on_wchar_ptr) {
      auto v = L"42"_i8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_i8, v);
    }
    
    void test_method_(_i8_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_i8;});
    }

    void test_method_(_i16_operator_on_long_double) {
      auto v = 42.0_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_unsigned_long_long) {
      auto v = 42_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_char_ptr) {
      auto v = "42"_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_i16;});
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_i16_operator_on_char8_ptr) {
      auto v = u8"42"_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_i16;});
    }
#endif
    
    void test_method_(_i16_operator_on_char16_ptr) {
      auto v = u"42"_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_i16;});
    }

    void test_method_(_i16_operator_on_char32_ptr) {
      auto v = U"42"_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_i16;});
    }

    void test_method_(_i16_operator_on_wchar_ptr) {
      auto v = L"42"_i16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_i16, v);
    }
    
    void test_method_(_i16_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_i16;});
    }

    void test_method_(_i32_operator_on_long_double) {
      auto v = 42.0_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_unsigned_long_long) {
      auto v = 42_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_char_ptr) {
      auto v = "42"_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_i32;});
    }

#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_i32_operator_on_char8_ptr) {
      auto v = u8"42"_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_i32;});
    }
#endif
    
    void test_method_(_i32_operator_on_char16_ptr) {
      auto v = u"42"_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_i32;});
    }

    void test_method_(_i32_operator_on_char32_ptr) {
      auto v = U"42"_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_i32;});
    }

    void test_method_(_i32_operator_on_wchar_ptr) {
      auto v = L"42"_i32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_i32, v);
    }
    
    void test_method_(_i32_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_i32;});
    }

    void test_method_(_i64_operator_on_long_double) {
      auto v = 42.0_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_unsigned_long_long) {
      auto v = 42_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_char_ptr) {
      auto v = "42"_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_i64;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_i64_operator_on_char8_ptr) {
      auto v = u8"42"_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_i64;});
    }
#endif
    
    void test_method_(_i64_operator_on_char16_ptr) {
      auto v = u"42"_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_i64;});
    }
    
    void test_method_(_i64_operator_on_char32_ptr) {
      auto v = U"42"_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_i64;});
    }
    
    void test_method_(_i64_operator_on_wchar_ptr) {
      auto v = L"42"_i64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_i64, v);
    }
    
    void test_method_(_i64_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_i64;});
    }

    void test_method_(_s8_operator_on_long_double) {
      auto v = 42.0_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_unsigned_long_long) {
      auto v = 42_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_char_ptr) {
      auto v = "42"_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_s8;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_s8_operator_on_char8_ptr) {
      auto v = u8"42"_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_s8;});
    }
#endif
    
    void test_method_(_s8_operator_on_char16_ptr) {
      auto v = u"42"_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_s8;});
    }
    
    void test_method_(_s8_operator_on_char32_ptr) {
      auto v = U"42"_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_s8;});
    }
    
    void test_method_(_s8_operator_on_wchar_ptr) {
      auto v = L"42"_s8;
      assert::is_true(is<sbyte>(v));
      assert::are_equal(42_s8, v);
    }
    
    void test_method_(_s8_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_s8;});
    }

    void test_method_(_s16_operator_on_long_double) {
      auto v = 42.0_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_unsigned_long_long) {
      auto v = 42_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_char_ptr) {
      auto v = "42"_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_s16;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_s16_operator_on_char8_ptr) {
      auto v = u8"42"_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_s16;});
    }
#endif
    
    void test_method_(_s16_operator_on_char16_ptr) {
      auto v = u"42"_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_s16;});
    }
    
    void test_method_(_s16_operator_on_char32_ptr) {
      auto v = U"42"_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_s16;});
    }
    
    void test_method_(_s16_operator_on_wchar_ptr) {
      auto v = L"42"_s16;
      assert::is_true(is<int16>(v));
      assert::are_equal(42_s16, v);
    }
    
    void test_method_(_s16_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_s16;});
    }

    //_________________________________________________________________________
    //                                                          String suffixes
    void test_method_(_s_operator_on_char_ptr) {
      auto v = "string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_s_operator_on_char8_ptr) {
      auto v = u8"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }
#endif
    
    void test_method_(_s_operator_on_char16_ptr) {
      auto v = u"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }
    
    void test_method_(_s_operator_on_char32_ptr) {
      auto v = U"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }

    void test_method_(_sd_operator_on_long_double) {
      auto v = 42.0_sd;
      assert::is_instance_of<string>(v);
      assert::are_equal("42", v);
    }

    void test_method_(_sd_operator_on_unsigned_long_long) {
      auto v = 42_sd;
      assert::is_instance_of<string>(v);
      assert::are_equal("42", v);
    }
    
    //_________________________________________________________________________
    //                                         String with translation suffixes

    //_________________________________________________________________________
    //                                                       Time span suffixes
  };
}
