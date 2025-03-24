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
    
    void test_method_(format_date_time_local_with_std_tm_with_default_argument) {
      assert::are_equal(u"2019-01-02 03:04:05", format(u"{0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_left_alignment) {
      assert::are_equal(u"                2019-01-02 03:04:05", format(u"{0, 35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_left_alignment_wth_plus) {
      assert::are_equal(u"                2019-01-02 03:04:05", format(u"{0,+35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_left_to_zero) {
      assert::are_equal(u"2019-01-02 03:04:05", format(u"{0,0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_right_alignment) {
      assert::are_equal(u"2019-01-02 03:04:05                ", format(u"{0,-35}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_right_alignment_to_zero) {
      assert::are_equal(u"2019-01-02 03:04:05", format(u"{0,-0}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_alignment_empty) {
      assert::are_equal(u"2019-01-02 03:04:05", format(u"{0,}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_alignment_invalid) {
      assert::throws<format_exception>([] {format(u"{0,a}", date_time {2019, 1, 2, 3, 4, 5});});
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_date_argument_and_zero_fill) {
      assert::are_equal(u"01/02/2019", format(u"{0:d}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_date_argument) {
      assert::are_equal(u"1/02/2019", format(u"{0:D}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_utc_with_std_tm_with_alternative_full_date_time_argument) {
      #if defined(__APPLE__)
      assert::are_equal(u"Wed Jan  2 03:04:05 2019", format(u"{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
      #elif defined(_WIN32)
      assert::are_equal(u"1/2/2019 3:04:05 AM", format(u"{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
      #else
      string_assert::starts_with("Wed 02 Jan 2019 03:04:05 AM", format(u"{0:f}", date_time {2019, 1, 2, 3, 4, 5}));
      #endif
    }
    
    void test_method_(format_date_time_utc_with_std_tm_with_full_date_time_argument) {
      #if defined(__APPLE__)
      assert::are_equal(u"Wed Jan  2 03:04:05 2019", format(u"{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
      #elif defined(_WIN32)
      assert::are_equal(u"1/2/2019 3:04:05 AM", format(u"{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
      #else
      string_assert::starts_with("Wed 02 Jan 2019 03:04:05 AM", format(u"{0:F}", date_time {2019, 1, 2, 3, 4, 5}));
      #endif
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_alternative_general_argument) {
      #if defined(__APPLE__)
      assert::are_equal(u"Wed Jan  2 03:04:05 2019", format(u"{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
      #elif defined(_WIN32)
      assert::are_equal(u"1/2/2019 3:04:05 AM", format(u"{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
      #else
      string_assert::starts_with("Wed 02 Jan 2019 03:04:05 AM", format(u"{0:g}", date_time {2019, 1, 2, 3, 4, 5}));
      #endif
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_general_argument) {
      assert::are_equal(u"2019-01-02 03:04:05", format(u"{0:G}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_brief_weekday_name_argument) {
      assert::are_equal(u"Wed", format(u"{0:h}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_weekday_name_argument) {
      assert::are_equal(u"Wednesday", format(u"{0:H}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_day_argument_and_zero_fill) {
      assert::are_equal(u"02", format(u"{0:i}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_day_argument) {
      assert::are_equal(u"2", format(u"{0:I}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_brief_month_name_argument) {
      assert::are_equal(u"Jan", format(u"{0:j}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_name_argument) {
      assert::are_equal(u"January", format(u"{0:J}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_argument_and_zero_fill) {
      assert::are_equal(u"01", format(u"{0:k}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_argument) {
      assert::are_equal(u"1", format(u"{0:K}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_year_on_two_digits_argument) {
      assert::are_equal(u"19", format(u"{0:l}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_year_argument) {
      assert::are_equal(u"2019", format(u"{0:L}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_day_argument) {
      assert::are_equal(u"January 2", format(u"{0:M}", date_time {2019, 1, 2}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_natural_date_argument) {
      assert::are_equal(u"Wednesday, 2 January 2019", format(u"{0:n}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_natural_date_time_argument) {
      assert::are_equal(u"Wednesday, 2 January 2019 3:04:05", format(u"{0:N}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_ordinary_date_argument) {
      assert::are_equal(u"2 January 2019", format(u"{0:O}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_sortable_argument) {
      assert::are_equal(u"2019-01-02T03:04:05.0000000", format(u"{0:s}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_argument_and_zero_fill) {
      assert::are_equal(u"03:04:05", format(u"{0:t}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_argument) {
      assert::are_equal(u"3:04:05", format(u"{0:T}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_alternative_universale_argument_and_zero_fill) {
      assert::are_equal(u"2019-01-02 03:04:05", format(u"{0:u}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_universale_argument_and_zero_fill) {
      assert::are_equal(u"Wednesday, 2 January 2019 3:04:05", format(u"{0:U}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_without_seconds_argument_and_zero_fill) {
      assert::are_equal(u"03:04", format(u"{0:v}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_without_seconds_argument) {
      assert::are_equal(u"3:04", format(u"{0:V}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_year_on_two_digits_argument) {
      assert::are_equal(u"January 19", format(u"{0:y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_year_argument) {
      assert::are_equal(u"January 2019", format(u"{0:Y}", date_time {2019, 1, 2, 3, 4, 5}));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_zone_argument) {
      #if defined(__APPLE__)
      assert::are_equal(u"UTC", format(u"{0:Z}", date_time {2019, 1, 2, 3, 4, 5}.to_universal_time()));
      #elif defined(_WIN32)
      // This test is commented, because the result is time zone dependent.
      // assert::are_equal(u"Coordinated Universal time_t", format(u"{0:Z}", date_time {2019, 1, 2, 3, 4, 5}.to_universal_time()));
      #else
      assert::are_equal(u"UTC", format(u"{0:Z}", date_time {2019, 1, 2, 3, 4, 5}.to_universal_time()));
      #endif
    }
  };
}
