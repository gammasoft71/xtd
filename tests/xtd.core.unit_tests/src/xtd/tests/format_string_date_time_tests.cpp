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
  class test_class_(format_string_date_time_tests) {
    inline static std::locale previous_locale;
    static void class_initialize_(class_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    static void class_cleanup_(class_cleanup) {
      std::locale::global(previous_locale);
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_default_argument) {
      assert::are_equal("1/2/2019 03:04", format("{0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_left_alignment) {
      assert::are_equal("                     1/2/2019 03:04", format("{0, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_left_alignment_wth_plus) {
      assert::are_equal("                     1/2/2019 03:04", format("{0,+35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_left_to_zero) {
      assert::are_equal("1/2/2019 03:04", format("{0,0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_right_alignment) {
      assert::are_equal("1/2/2019 03:04                     ", format("{0,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_right_alignment_to_zero) {
      assert::are_equal("1/2/2019 03:04", format("{0,-0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_alignment_empty) {
      assert::are_equal("1/2/2019 03:04", format("{0,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_alignment_invalid) {
      assert::throws<format_exception>([] {format("{0,a}", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_short_date) {
      assert::are_equal("1/2/2019", format("{0:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_long_date) {
      assert::are_equal("Wednesday, January 2, 2019", format("{0:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_full_date_short_time) {
      assert::are_equal("Wednesday, January 2, 2019 03:04", format("{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_full_date_long_time) {
      assert::are_equal("Wednesday, January 2, 2019 03:04:05", format("{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_genral_short) {
      assert::are_equal("1/2/2019 03:04", format("{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_genral_long) {
      assert::are_equal("1/2/2019 03:04:05", format("{0:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_month_day) {
      assert::are_equal("January 2", format("{0:m}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_month_day_2) {
      assert::are_equal("January 2", format("{0:M}", date_time {2019, 1, 2}));
    }

    void test_method_(format_iso_8601) {
      assert::are_equal("2019-01-02T03:04:05.0000000Z", format("{0:o}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_iso_8601_2) {
      assert::are_equal("2019-01-02T03:04:05.0000000Z", format("{0:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }

    void test_method_(format_rfc1123) {
      assert::are_equal("Wed, 02 Jan 2019 03:04:05 G1T", format("{0:r}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_rfc1123_2) {
      assert::are_equal("Wed, 02 Jan 2019 03:04:05 G1T", format("{0:R}", date_time {2019, 1, 2, 3, 4, 5}));
    }

    void test_method_(format_sortable) {
      assert::are_equal("2019-01-02T03:04:05", format("{0:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_short_time) {
      assert::are_equal("03:04", format("{0:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_long_time) {
      assert::are_equal("03:04:05", format("{0:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_sortable) {
      assert::are_equal("2019-01-02 03:04:05Z", format("{0:u}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_universal_full) {
      assert::are_equal("Wednesday, January 2, 2019 03:04:05", format("{0:U}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_year_month) {
      assert::are_equal("January 2019", format("{0:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }

    void test_method_(format_year_month2) {
      assert::are_equal("January 2019", format("{0:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
  };
}
