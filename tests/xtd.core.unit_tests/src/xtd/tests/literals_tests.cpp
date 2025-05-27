#include <xtd/translator_literals>
#include <xtd/environment>
#include <xtd/is>
#include <xtd/translator>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
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
    
    void test_method_(_b_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {256_b;});
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
    
    void test_method_(_i8_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {128_i8;});
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
    
    void test_method_(_i16_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {32768_i8;});
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
    
    void test_method_(_i32_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {2147483648_i32;});
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
    
    void test_method_(_s8_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {128_s8;});
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
    
    void test_method_(_s16_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {32768_s16;});
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

    void test_method_(_s32_operator_on_long_double) {
      auto v = 42.0_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_unsigned_long_long) {
      auto v = 42_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {2147483648_s32;});
    }

    void test_method_(_s32_operator_on_char_ptr) {
      auto v = "42"_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_s32;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_s32_operator_on_char8_ptr) {
      auto v = u8"42"_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_s32;});
    }
#endif
    
    void test_method_(_s32_operator_on_char16_ptr) {
      auto v = u"42"_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_s32;});
    }
    
    void test_method_(_s32_operator_on_char32_ptr) {
      auto v = U"42"_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_s32;});
    }
    
    void test_method_(_s32_operator_on_wchar_ptr) {
      auto v = L"42"_s32;
      assert::is_true(is<int32>(v));
      assert::are_equal(42_s32, v);
    }
    
    void test_method_(_s32_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_s32;});
    }

    void test_method_(_s64_operator_on_long_double) {
      auto v = 42.0_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_unsigned_long_long) {
      auto v = 42_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_char_ptr) {
      auto v = "42"_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_s64;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_s64_operator_on_char8_ptr) {
      auto v = u8"42"_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_s64;});
    }
#endif
    
    void test_method_(_s64_operator_on_char16_ptr) {
      auto v = u"42"_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_s64;});
    }
    
    void test_method_(_s64_operator_on_char32_ptr) {
      auto v = U"42"_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_s64;});
    }
    
    void test_method_(_s64_operator_on_wchar_ptr) {
      auto v = L"42"_s64;
      assert::is_true(is<int64>(v));
      assert::are_equal(42_s64, v);
    }
    
    void test_method_(_s64_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_s64;});
    }

    void test_method_(_u8_operator_on_long_double) {
      auto v = 42.0_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_unsigned_long_long) {
      auto v = 42_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {256_u8;});
    }

    void test_method_(_u8_operator_on_char_ptr) {
      auto v = "42"_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_u8;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_u8_operator_on_char8_ptr) {
      auto v = u8"42"_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_u8;});
    }
#endif
    
    void test_method_(_u8_operator_on_char16_ptr) {
      auto v = u"42"_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_u8;});
    }
    
    void test_method_(_u8_operator_on_char32_ptr) {
      auto v = U"42"_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_u8;});
    }
    
    void test_method_(_u8_operator_on_wchar_ptr) {
      auto v = L"42"_u8;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_u8, v);
    }
    
    void test_method_(_u8_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_u8;});
    }
    
    void test_method_(_u16_operator_on_long_double) {
      auto v = 42.0_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_unsigned_long_long) {
      auto v = 42_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {65536_u16;});
    }

    void test_method_(_u16_operator_on_char_ptr) {
      auto v = "42"_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_u16;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_u16_operator_on_char8_ptr) {
      auto v = u8"42"_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_u16;});
    }
#endif
    
    void test_method_(_u16_operator_on_char16_ptr) {
      auto v = u"42"_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_u16;});
    }
    
    void test_method_(_u16_operator_on_char32_ptr) {
      auto v = U"42"_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_u16;});
    }
    
    void test_method_(_u16_operator_on_wchar_ptr) {
      auto v = L"42"_u16;
      assert::is_true(is<uint16>(v));
      assert::are_equal(42_u16, v);
    }
    
    void test_method_(_u16_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_u16;});
    }
    
    void test_method_(_u32_operator_on_long_double) {
      auto v = 42.0_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_unsigned_long_long) {
      auto v = 42_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_unsigned_long_long_with_overflow) {
      assert::throws<xtd::overflow_exception>([] {4294967296_u32;});
    }

    void test_method_(_u32_operator_on_char_ptr) {
      auto v = "42"_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_u32;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_u32_operator_on_char8_ptr) {
      auto v = u8"42"_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_u32;});
    }
#endif
    
    void test_method_(_u32_operator_on_char16_ptr) {
      auto v = u"42"_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_u32;});
    }
    
    void test_method_(_u32_operator_on_char32_ptr) {
      auto v = U"42"_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_u32;});
    }
    
    void test_method_(_u32_operator_on_wchar_ptr) {
      auto v = L"42"_u32;
      assert::is_true(is<uint32>(v));
      assert::are_equal(42_u32, v);
    }
    
    void test_method_(_u32_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_u32;});
    }
    
    void test_method_(_u64_operator_on_long_double) {
      auto v = 42.0_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_unsigned_long_long) {
      auto v = 42_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_char_ptr) {
      auto v = "42"_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_u64;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_u64_operator_on_char8_ptr) {
      auto v = u8"42"_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_u64;});
    }
#endif
    
    void test_method_(_u64_operator_on_char16_ptr) {
      auto v = u"42"_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_u64;});
    }
    
    void test_method_(_u64_operator_on_char32_ptr) {
      auto v = U"42"_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_u64;});
    }
    
    void test_method_(_u64_operator_on_wchar_ptr) {
      auto v = L"42"_u64;
      assert::is_true(is<uint64>(v));
      assert::are_equal(42_u64, v);
    }
    
    void test_method_(_u64_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_u64;});
    }
    
    void test_method_(_uz_operator_on_long_double) {
      auto v = 42.0_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_unsigned_long_long) {
      auto v = 42_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_char_ptr) {
      auto v = "42"_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_uz;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_uz_operator_on_char8_ptr) {
      auto v = u8"42"_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_uz;});
    }
#endif
    
    void test_method_(_uz_operator_on_char16_ptr) {
      auto v = u"42"_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_uz;});
    }
    
    void test_method_(_uz_operator_on_char32_ptr) {
      auto v = U"42"_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_uz;});
    }
    
    void test_method_(_uz_operator_on_wchar_ptr) {
      auto v = L"42"_uz;
      assert::is_true(is<size>(v));
      assert::are_equal(42_uz, v);
    }
    
    void test_method_(_uz_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_uz;});
    }
    
    void test_method_(_z_operator_on_long_double) {
      auto v = 42.0_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_unsigned_long_long) {
      auto v = 42_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_char_ptr) {
      auto v = "42"_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_invalid_char_ptr) {
      assert::throws<xtd::format_exception>([] {"42str"_z;});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_z_operator_on_char8_ptr) {
      auto v = u8"42"_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_invalid_char8_ptr) {
      assert::throws<xtd::format_exception>([] {u8"42str"_z;});
    }
#endif
    
    void test_method_(_z_operator_on_char16_ptr) {
      auto v = u"42"_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_invalid_char16_ptr) {
      assert::throws<xtd::format_exception>([] {u"42str"_z;});
    }
    
    void test_method_(_z_operator_on_char32_ptr) {
      auto v = U"42"_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_invalid_char32_ptr) {
      assert::throws<xtd::format_exception>([] {U"42str"_z;});
    }
    
    void test_method_(_z_operator_on_wchar_ptr) {
      auto v = L"42"_z;
      assert::is_true(is<size>(v));
      assert::are_equal(42_z, v);
    }
    
    void test_method_(_z_operator_on_invalid_wchar_ptr) {
      assert::throws<xtd::format_exception>([] {L"42str"_z;});
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
    
    void test_method_(_s_operator_on_wchar_ptr) {
      auto v = L"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }

    void test_method_(_sb_operator_on_long_double) {
      auto v = 42.0_sb;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
    }
    
    void test_method_(_sb_operator_on_unsigned_long_long) {
      auto v = 42_sb;
      assert::is_instance_of<string>(v);
      assert::are_equal("101010", v);
    }

    void test_method_(_sb2_operator_on_long_double) {
      auto v = 42.0_sb2;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
    }
    
    void test_method_(_sb2_operator_on_unsigned_long_long) {
      auto v = 42_sb2;
      assert::is_instance_of<string>(v);
      assert::are_equal("101010", v);
    }

    void test_method_(_sb4_operator_on_long_double) {
      auto v = 42.0_sb4;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
    }

    void test_method_(_sb4_operator_on_unsigned_long_long) {
      auto v = 42_sb4;
      assert::is_instance_of<string>(v);
      assert::are_equal("101010", v);
    }

    void test_method_(_sb8_operator_on_long_double) {
      auto v = 42.0_sb8;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
    }
    
    void test_method_(_sb8_operator_on_unsigned_long_long) {
      auto v = 42_sb8;
      assert::is_instance_of<string>(v);
      assert::are_equal("00101010", v);
    }

    void test_method_(_sb16_operator_on_long_double) {
      auto v = 42.0_sb16;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
    }
    
    void test_method_(_sb16_operator_on_unsigned_long_long) {
      auto v = 42_sb16;
      assert::is_instance_of<string>(v);
      assert::are_equal("0000000000101010", v);
    }

    void test_method_(_sb32_operator_on_long_double) {
      auto v = 42.0_sb32;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
    }
    
    void test_method_(_sb32_operator_on_unsigned_long_long) {
      auto v = 42_sb32;
      assert::is_instance_of<string>(v);
      assert::are_equal("00000000000000000000000000101010", v);
    }

    void test_method_(_sb64_operator_on_long_double) {
      auto v = 42.0_sb64;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("0100000001000101000000000000000000000000000000000000000000000000", v);
    }
    
    void test_method_(_sb64_operator_on_unsigned_long_long) {
      auto v = 42_sb64;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("0000000000000000000000000000000000000000000000000000000000101010", v);
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

    void test_method_(_sx_operator_on_long_double) {
      auto v = 42.0_sx;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("0x1.5p+5", v);
    }
    
    void test_method_(_sx_operator_on_unsigned_long_long) {
      auto v = 42_sx;
      assert::is_instance_of<string>(v);
      assert::are_equal("2a", v);
    }
    
    void test_method_(_sx2_operator_on_unsigned_long_long) {
      auto v = 42_sx2;
      assert::is_instance_of<string>(v);
      assert::are_equal("2a", v);
    }
    
    void test_method_(_sx4_operator_on_unsigned_long_long) {
      auto v = 42_sx4;
      assert::is_instance_of<string>(v);
      assert::are_equal("002a", v);
    }
    
    void test_method_(_sx8_operator_on_unsigned_long_long) {
      auto v = 42_sx8;
      assert::is_instance_of<string>(v);
      assert::are_equal("0000002a", v);
    }
    
    void test_method_(_sx16_operator_on_unsigned_long_long) {
      auto v = 42_sx16;
      assert::is_instance_of<string>(v);
      assert::are_equal("000000000000002a", v);
    }

    void test_method_(_sX_operator_on_long_double) {
      auto v = 42.0_sX;
      assert::is_instance_of<string>(v);
      if (environment::os_version().is_macos()) assert::are_equal("0x1.5p+5", v);
    }
    
    void test_method_(_sX_operator_on_unsigned_long_long) {
      auto v = 42_sX;
      assert::is_instance_of<string>(v);
      assert::are_equal("2A", v);
    }
    
    void test_method_(_sX2_operator_on_unsigned_long_long) {
      auto v = 42_sX2;
      assert::is_instance_of<string>(v);
      assert::are_equal("2A", v);
    }
    
    void test_method_(_sX4_operator_on_unsigned_long_long) {
      auto v = 42_sX4;
      assert::is_instance_of<string>(v);
      assert::are_equal("002A", v);
    }
    
    void test_method_(_sX8_operator_on_unsigned_long_long) {
      auto v = 42_sX8;
      assert::is_instance_of<string>(v);
      assert::are_equal("0000002A", v);
    }
    
    void test_method_(_sX16_operator_on_unsigned_long_long) {
      auto v = 42_sX16;
      assert::is_instance_of<string>(v);
      assert::are_equal("000000000000002A", v);
    }

    //_________________________________________________________________________
    //                                         String with translation suffixes
    void test_method_(_t_operator_on_char_ptr) {
      auto v = "Belgium"_t;
      assert::are_equal("Belgium"_t, string {v});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_t_operator_on_char8_ptr) {
      auto v = u8"Belgium"_t;
      assert::are_equal(u8"Belgium"_t, string {v});
    }
#endif
    
    void test_method_(_t_operator_on_char16_ptr) {
      auto v = u"Belgium"_t;
      assert::are_equal("Belgium"_t, string {v});
    }
    
    void test_method_(_t_operator_on_char32_ptr) {
      auto v = U"Belgium"_t;
      assert::are_equal("Belgium"_t, string {v});
    }
    
    void test_method_(_t_operator_on_wchar_ptr) {
      auto v = L"Belgium"_t;
      assert::are_equal("Belgium"_t, string {v});
    }
  };
}
