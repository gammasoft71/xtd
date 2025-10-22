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
  class test_class_(format_u32string_date_time_tests) {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }
    
    void test_method_(format_with_none) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment) {
      assert::are_equal(U"                1/2/2019 3:04:05 AM", format(U"{, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_2) {
      assert::are_equal(U"                1/2/2019 3:04:05 AM", format(U"{, +35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment) {
      assert::are_equal(U"                1/2/2019 3:04:05 AM", format(U"{0, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_2) {
      assert::are_equal(U"                1/2/2019 3:04:05 AM", format(U"{0, +35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero_2) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{, +0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{0, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero_2) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{0, +0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and__right_alignment) {
      assert::are_equal(U"1/2/2019 3:04:05 AM                ", format(U"{,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and__right_alignment) {
      assert::are_equal(U"1/2/2019 3:04:05 AM                ", format(U"{0,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_right_alignment_to_zero) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_to_zero) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{0, 0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_right_alignment_empty) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_empty) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{0,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_with_none_and_alignment_invalid) {
      assert::throws<format_exception>([] {format(U"{,a}", date_time {2019, 1, 2, 3, 4, 5});});
      assert::throws<format_exception>([] {format(U"{, }", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_with_sequence_number_and_alignment_invalid) {
      assert::throws<format_exception>([] {format(U"{0,a}", date_time {2019, 1, 2, 3, 4, 5});});
      assert::throws<format_exception>([] {format(U"{0, }", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_short_date_with_none) {
      assert::are_equal(U"1/2/2019", format(U"{:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_short_date_with_sequence_number) {
      assert::are_equal(U"1/2/2019", format(U"{0:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date_with_none) {
      assert::are_equal(U"Wednesday, January 2, 2019", format(U"{:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date_with_sequence_number) {
      assert::are_equal(U"Wednesday, January 2, 2019", format(U"{0:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_full_date_short_time_with_none) {
      assert::are_equal(U"Wednesday, January 2, 2019 3:04 AM", format(U"{:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_short_time_with_sequence_number) {
      assert::are_equal(U"Wednesday, January 2, 2019 3:04 AM", format(U"{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time_with_none) {
      assert::are_equal(U"Wednesday, January 2, 2019 3:04:05 AM", format(U"{:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time_with_sequence_number) {
      assert::are_equal(U"Wednesday, January 2, 2019 3:04:05 AM", format(U"{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_short_with_none) {
      assert::are_equal(U"1/2/2019 3:04 AM", format(U"{:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_short_with_sequence_number) {
      assert::are_equal(U"1/2/2019 3:04 AM", format(U"{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_long_with_none) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_general_long_with_sequence_number) {
      assert::are_equal(U"1/2/2019 3:04:05 AM", format(U"{0:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_month_day_with_none) {
      assert::are_equal(U"January 2", format(U"{:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_none_2) {
      assert::are_equal(U"January 2", format(U"{:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_sequence_number) {
      assert::are_equal(U"January 2", format(U"{0:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_with_sequence_number_2) {
      assert::are_equal(U"January 2", format(U"{0:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_iso_8601_with_none) {
      assert::are_equal(U"2019-01-02T03:04:05.0000000Z", format(U"{:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_none_2) {
      assert::are_equal(U"2019-01-02T03:04:05.0000000Z", format(U"{:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_sequence_number) {
      assert::are_equal(U"2019-01-02T03:04:05.0000000Z", format(U"{0:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_with_sequence_number_2) {
      assert::are_equal(U"2019-01-02T03:04:05.0000000Z", format(U"{0:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_none) {
      assert::are_equal(U"Wed, 02 Jan 2019 03:04:05 GMT", format(U"{:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_none_2) {
      assert::are_equal(U"Wed, 02 Jan 2019 03:04:05 GMT", format(U"{:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_sequence_number) {
      assert::are_equal(U"Wed, 02 Jan 2019 03:04:05 GMT", format(U"{0:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_with_sequence_number_2) {
      assert::are_equal(U"Wed, 02 Jan 2019 03:04:05 GMT", format(U"{0:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_sortable_with_none) {
      assert::are_equal(U"2019-01-02T03:04:05", format(U"{:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_sortable_with_sequence_number) {
      assert::are_equal(U"2019-01-02T03:04:05", format(U"{0:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time_with_none) {
      assert::are_equal(U"3:04 AM", format(U"{:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time_with_sequence_number) {
      assert::are_equal(U"3:04 AM", format(U"{0:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time_with_none) {
      assert::are_equal(U"3:04:05 AM", format(U"{:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time_with_sequence_number) {
      assert::are_equal(U"3:04:05 AM", format(U"{0:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_sortable_with_none) {
      assert::are_equal(U"2019-01-02 03:04:05Z", format(U"{:u}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_universal_sortable_with_sequence_number) {
      assert::are_equal(U"2019-01-02 03:04:05Z", format(U"{0:u}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_universal_full_with_none) {
      assert::are_equal(U"Wednesday, January 2, 2019 3:04:05 AM", format(U"{:U}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_universal_full_with_sequence_number) {
      assert::are_equal(U"Wednesday, January 2, 2019 3:04:05 AM", format(U"{0:U}", date_time {2019, 1, 2, 3, 4, 5, date_time_kind::utc}));
    }
    
    void test_method_(format_year_month_with_none) {
      assert::are_equal(U"January 2019", format(U"{:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_none_2) {
      assert::are_equal(U"January 2019", format(U"{:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_sequence_number) {
      assert::are_equal(U"January 2019", format(U"{0:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month_with_sequence_number_2) {
      assert::are_equal(U"January 2019", format(U"{0:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
  };
}
