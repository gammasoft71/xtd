#define _CRT_SECURE_NO_WARNINGS
#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(format_u8string_date_time_tests) {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }
    
    void test_method_(format_with_none) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment) {
      assert::are_equal(u8"                1/2/2019 3:04:05 AM", format(u8"{, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_2) {
      assert::are_equal(u8"                1/2/2019 3:04:05 AM", format(u8"{, +35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment) {
      assert::are_equal(u8"                1/2/2019 3:04:05 AM", format(u8"{0, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_2) {
      assert::are_equal(u8"                1/2/2019 3:04:05 AM", format(u8"{0, +35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero_2) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{, +0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{0, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero_2) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{0, +0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and__right_alignment) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM                ", format(u8"{,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and__right_alignment) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM                ", format(u8"{0,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_right_alignment_to_zero) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_to_zero) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{0, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_right_alignment_empty) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_empty) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{0,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_alignment_invalid) {
      assert::throws<format_exception>([] {format(u8"{,a}", date_time {2019, 1, 2, 3, 4, 5});});
      assert::throws<format_exception>([] {format(u8"{, }", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_with_sequence_number_and_alignment_invalid) {
      assert::throws<format_exception>([] {format(u8"{0,a}", date_time {2019, 1, 2, 3, 4, 5});});
      assert::throws<format_exception>([] {format(u8"{0, }", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_short_date_with_none) {
      assert::are_equal(u8"1/2/2019", format(u8"{:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_short_date_with_sequence_number) {
      assert::are_equal(u8"1/2/2019", format(u8"{0:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date_with_none) {
      assert::are_equal(u8"Wednesday, January 2, 2019", format(u8"{:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date_with_sequence_number) {
      assert::are_equal(u8"Wednesday, January 2, 2019", format(u8"{0:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_full_date_short_time_with_none) {
      assert::are_equal(u8"Wednesday, January 2, 2019 3:04 AM", format(u8"{:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_short_time_with_sequence_number) {
      assert::are_equal(u8"Wednesday, January 2, 2019 3:04 AM", format(u8"{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time_with_none) {
      assert::are_equal(u8"Wednesday, January 2, 2019 3:04:05 AM", format(u8"{:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time_with_sequence_number) {
      assert::are_equal(u8"Wednesday, January 2, 2019 3:04:05 AM", format(u8"{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_short_with_none) {
      assert::are_equal(u8"1/2/2019 3:04 AM", format(u8"{:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_short_with_sequence_number) {
      assert::are_equal(u8"1/2/2019 3:04 AM", format(u8"{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_long_with_none) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_long_with_sequence_number) {
      assert::are_equal(u8"1/2/2019 3:04:05 AM", format(u8"{0:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_month_day_with_none) {
      assert::are_equal(u8"January 2", format(u8"{:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_none_2) {
      assert::are_equal(u8"January 2", format(u8"{:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_sequence_number) {
      assert::are_equal(u8"January 2", format(u8"{0:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_sequence_number_2) {
      assert::are_equal(u8"January 2", format(u8"{0:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_iso_8601_with_none) {
      assert::are_equal(u8"2019-01-02T03:04:05.0000000Z", format(u8"{:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_none_2) {
      assert::are_equal(u8"2019-01-02T03:04:05.0000000Z", format(u8"{:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_sequence_number) {
      assert::are_equal(u8"2019-01-02T03:04:05.0000000Z", format(u8"{0:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_sequence_number_2) {
      assert::are_equal(u8"2019-01-02T03:04:05.0000000Z", format(u8"{0:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_none) {
      assert::are_equal(u8"Wed, 02 Jan 2019 03:04:05 GMT", format(u8"{:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_none_2) {
      assert::are_equal(u8"Wed, 02 Jan 2019 03:04:05 GMT", format(u8"{:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_sequence_number) {
      assert::are_equal(u8"Wed, 02 Jan 2019 03:04:05 GMT", format(u8"{0:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_sequence_number_2) {
      assert::are_equal(u8"Wed, 02 Jan 2019 03:04:05 GMT", format(u8"{0:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_sortable_with_none) {
      assert::are_equal(u8"2019-01-02T03:04:05", format(u8"{:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_sortable_with_sequence_number) {
      assert::are_equal(u8"2019-01-02T03:04:05", format(u8"{0:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time_with_none) {
      assert::are_equal(u8"3:04 AM", format(u8"{:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time_with_sequence_number) {
      assert::are_equal(u8"3:04 AM", format(u8"{0:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time_with_none) {
      assert::are_equal(u8"3:04:05 AM", format(u8"{:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time_with_sequence_number) {
      assert::are_equal(u8"3:04:05 AM", format(u8"{0:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_sortable_with_none) {
      assert::are_equal(u8"2019-01-02 03:04:05Z", format(u8"{:u}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_universal_sortable_with_sequence_number) {
      assert::are_equal(u8"2019-01-02 03:04:05Z", format(u8"{0:u}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_universal_full_with_none) {
      assert::are_equal(u8"Wednesday, January 2, 2019 3:04:05 AM", format(u8"{:U}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_universal_full_with_sequence_number) {
      assert::are_equal(u8"Wednesday, January 2, 2019 3:04:05 AM", format(u8"{0:U}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_year_month_with_none) {
      assert::are_equal(u8"January 2019", format(u8"{:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_none_2) {
      assert::are_equal(u8"January 2019", format(u8"{:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_sequence_number) {
      assert::are_equal(u8"January 2019", format(u8"{0:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_sequence_number_2) {
      assert::are_equal(u8"January 2019", format(u8"{0:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
  };
}
