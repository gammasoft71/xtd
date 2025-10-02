#define _CRT_SECURE_NO_WARNINGS
#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(format_u16string_date_time_tests) {
    inline static std::locale previous_locale;
    static void class_initialize_(class_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    static void class_cleanup_(class_cleanup) {
      std::locale::global(previous_locale);
    }
    
    void test_method_(format_with_none) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment) {
      assert::are_equal(u"                     1/2/2019 03:04", format(u"{, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_2) {
      assert::are_equal(u"                     1/2/2019 03:04", format(u"{, +35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment) {
      assert::are_equal(u"                     1/2/2019 03:04", format(u"{0, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_2) {
      assert::are_equal(u"                     1/2/2019 03:04", format(u"{0, +35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero_2) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{, +0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{0, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero_2) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{0, +0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and__right_alignment) {
      assert::are_equal(u"1/2/2019 03:04                     ", format(u"{,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and__right_alignment) {
      assert::are_equal(u"1/2/2019 03:04                     ", format(u"{0,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_right_alignment_to_zero) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_to_zero) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{0, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_right_alignment_empty) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_empty) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{0,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_alignment_invalid) {
      assert::throws<format_exception>([] {format(u"{,a}", date_time {2019, 1, 2, 3, 4, 5});});
      assert::throws<format_exception>([] {format(u"{, }", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_with_sequence_number_and_alignment_invalid) {
      assert::throws<format_exception>([] {format(u"{0,a}", date_time {2019, 1, 2, 3, 4, 5});});
      assert::throws<format_exception>([] {format(u"{0, }", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_short_date_with_none) {
      assert::are_equal(u"1/2/2019", format(u"{:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_short_date_with_sequence_number) {
      assert::are_equal(u"1/2/2019", format(u"{0:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date_with_none) {
      assert::are_equal(u"Wednesday, January 2, 2019", format(u"{:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date_with_sequence_number) {
      assert::are_equal(u"Wednesday, January 2, 2019", format(u"{0:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_full_date_short_time_with_none) {
      assert::are_equal(u"Wednesday, January 2, 2019 03:04", format(u"{:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_short_time_with_sequence_number) {
      assert::are_equal(u"Wednesday, January 2, 2019 03:04", format(u"{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time_with_none) {
      assert::are_equal(u"Wednesday, January 2, 2019 03:04:05", format(u"{:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time_with_sequence_number) {
      assert::are_equal(u"Wednesday, January 2, 2019 03:04:05", format(u"{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_genral_short_with_none) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_genral_short_with_sequence_number) {
      assert::are_equal(u"1/2/2019 03:04", format(u"{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_genral_long_with_none) {
      assert::are_equal(u"1/2/2019 03:04:05", format(u"{:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_genral_long_with_sequence_number) {
      assert::are_equal(u"1/2/2019 03:04:05", format(u"{0:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_month_day_with_none) {
      assert::are_equal(u"January 2", format(u"{:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_none_2) {
      assert::are_equal(u"January 2", format(u"{:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_sequence_number) {
      assert::are_equal(u"January 2", format(u"{0:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_sequence_number_2) {
      assert::are_equal(u"January 2", format(u"{0:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_iso_8601_with_none) {
      assert::are_equal(u"2019-01-02T03:04:05.0000000Z", format(u"{:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_none_2) {
      assert::are_equal(u"2019-01-02T03:04:05.0000000Z", format(u"{:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_sequence_number) {
      assert::are_equal(u"2019-01-02T03:04:05.0000000Z", format(u"{0:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_sequence_number_2) {
      assert::are_equal(u"2019-01-02T03:04:05.0000000Z", format(u"{0:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_none) {
      assert::are_equal(u"Wed, 02 Jan 2019 03:04:05 G1T", format(u"{:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_none_2) {
      assert::are_equal(u"Wed, 02 Jan 2019 03:04:05 G1T", format(u"{:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_sequence_number) {
      assert::are_equal(u"Wed, 02 Jan 2019 03:04:05 G1T", format(u"{0:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_sequence_number_2) {
      assert::are_equal(u"Wed, 02 Jan 2019 03:04:05 G1T", format(u"{0:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_sortable_with_none) {
      assert::are_equal(u"2019-01-02T03:04:05", format(u"{:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_sortable_with_sequence_number) {
      assert::are_equal(u"2019-01-02T03:04:05", format(u"{0:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time_with_none) {
      assert::are_equal(u"03:04", format(u"{:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time_with_sequence_number) {
      assert::are_equal(u"03:04", format(u"{0:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time_with_none) {
      assert::are_equal(u"03:04:05", format(u"{:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time_with_sequence_number) {
      assert::are_equal(u"03:04:05", format(u"{0:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_sortable_with_none) {
      assert::are_equal(u"2019-01-02 03:04:05Z", format(u"{:u}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_sortable_with_sequence_number) {
      assert::are_equal(u"2019-01-02 03:04:05Z", format(u"{0:u}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_full_with_none) {
      assert::are_equal(u"Wednesday, January 2, 2019 03:04:05", format(u"{:U}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_full_with_sequence_number) {
      assert::are_equal(u"Wednesday, January 2, 2019 03:04:05", format(u"{0:U}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_none) {
      assert::are_equal(u"January 2019", format(u"{:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_none_2) {
      assert::are_equal(u"January 2019", format(u"{:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_sequence_number) {
      assert::are_equal(u"January 2019", format(u"{0:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_sequence_number_2) {
      assert::are_equal(u"January 2019", format(u"{0:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
  };
}
