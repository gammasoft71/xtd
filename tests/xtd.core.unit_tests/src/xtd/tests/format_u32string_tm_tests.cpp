#define _CRT_SECURE_NO_WARNINGS
#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

#include <time.h>
#if defined(_WIN32)
static time_t __make_utc_date_time(struct tm* tm) noexcept {return _mkgmtime(tm);}
#else
static time_t __make_utc_date_time(struct tm* tm) noexcept {return timegm(tm);}
#endif

using namespace xtd;
using namespace xtd::tunit;

namespace {
  static std::tm to_local_time(time_t time) noexcept {return *std::localtime(&time);}
  //static std::tm to_local_time(const std::chrono::system_clock::time_point& time) noexcept {return to_local_time(std::chrono::system_clock::to_time_t(time));}
  static std::tm to_local_time(std::tm time) noexcept {
    auto dt = date_time::from_tm(time);
    if (xtd::date_time::sprintf("%Z", dt) != "" && xtd::date_time::sprintf("%Z", dt) == "UTC") return to_local_time(__make_utc_date_time(&time));
    return to_local_time(mktime(&time));
  }
  
  static std::tm to_universal_time(time_t time) noexcept {return *std::gmtime(&time);}
  #if !defined(_WIN32)
  [[maybe_unused]] static std::tm to_universal_time(const std::chrono::system_clock::time_point& time) noexcept {return to_universal_time(std::chrono::system_clock::to_time_t(time));}
  #endif
  [[maybe_unused]] static std::tm to_universal_time(std::tm time) noexcept {
    auto dt = date_time::from_tm(time);
    if (xtd::date_time::sprintf("%Z", dt) != "" && xtd::date_time::sprintf("%Z", dt) == "UTC") return to_universal_time(mktime(&time));
    return to_universal_time(__make_utc_date_time(&time));
  }
  
  std::tm make_time(int year, int month, int day, int hour, int minute, int second, bool utc = false) {
    std::tm time;
    time.tm_year = year - 1900;
    time.tm_mon = month - 1;
    time.tm_mday = day;
    time.tm_hour = hour;
    time.tm_min = minute;
    time.tm_sec = second;
    time.tm_wday = 0;
    time.tm_yday = 0;
    time.tm_isdst = -1;
    #if !defined(_WIN32)
    time.tm_gmtoff = 0;
    time.tm_zone = nullptr;
    #endif
    
    return utc ? to_universal_time(time) : to_local_time(time);
  }
  
  std::tm make_time(int year, int month, int day, bool utc = false) {return make_time(year, month, day, 0, 0, 0, utc);}
  
  template<class time_t>
  time_t make_time(int year, int month, int day, int hour, int minute, int second, bool utc = false);
  
  template<>
  std::tm make_time<std::tm>(int year, int month, int day, int hour, int minute, int second, bool utc) {return make_time(year, month, day, hour, minute, second, utc);}
  
  template<>
  std::chrono::system_clock::time_point make_time<std::chrono::system_clock::time_point>(int year, int month, int day, int hour, int minute, int second, bool utc) {
    std::tm time = make_time(year, month, day, hour, minute, second, utc);
    return std::chrono::system_clock::from_time_t(mktime(&time));
  }
  
  template<class time_t>
  time_t make_time(int year, int month, int day, bool utc = false);
  
  template<>
  std::tm make_time<std::tm>(int year, int month, int day, bool utc) {return make_time(year, month, day, utc);}
  
  template<>
  std::chrono::system_clock::time_point make_time<std::chrono::system_clock::time_point>(int year, int month, int day, bool utc) {
    std::tm time = make_time(year, month, day, utc);
    return std::chrono::system_clock::from_time_t(mktime(&time));
  }
}

namespace xtd::tests {
  template<class value_t>
  class format_u32string_tm_tests;
  
  test_class_attribute<format_u32string_tm_tests<std::tm>> format_u32string_tm_tests_class_std_tm_attr {"format_u32string_tm_tests<std::tm>"};
  test_class_attribute<format_u32string_tm_tests<std::chrono::system_clock::time_point>> format_u32string_tm_tests_class_std_chrono_system_clock_time_point_attr {"format_u32string_tm_tests<std::chrono::system_clock::time_point>"};
  
  template<class value_t>
  class format_u32string_tm_tests : public test_class {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }

    void test_method_(format_with_none) {
      assert::are_equal("1/2/2019 03:04:05", format("{}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number) {
      assert::are_equal("1/2/2019 03:04:05", format("{0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_left_alignment) {
      assert::are_equal("                  1/2/2019 03:04:05", format("{, 35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_left_alignment_2) {
      assert::are_equal("                  1/2/2019 03:04:05", format("{, +35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment) {
      assert::are_equal("                  1/2/2019 03:04:05", format("{0, 35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_2) {
      assert::are_equal("                  1/2/2019 03:04:05", format("{0, +35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero) {
      assert::are_equal("1/2/2019 03:04:05", format("{, 0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_left_alignment_to_zero_2) {
      assert::are_equal("1/2/2019 03:04:05", format("{, +0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero) {
      assert::are_equal("1/2/2019 03:04:05", format("{0, 0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and_left_alignment_to_zero_2) {
      assert::are_equal("1/2/2019 03:04:05", format("{0, +0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and__right_alignment) {
      assert::are_equal("1/2/2019 03:04:05                  ", format("{,-35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and__right_alignment) {
      assert::are_equal("1/2/2019 03:04:05                  ", format("{0,-35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_right_alignment_to_zero) {
      assert::are_equal("1/2/2019 03:04:05", format("{, 0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_to_zero) {
      assert::are_equal("1/2/2019 03:04:05", format("{0, 0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_right_alignment_empty) {
      assert::are_equal("1/2/2019 03:04:05", format("{,}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_sequence_number_and_right_alignment_empty) {
      assert::are_equal("1/2/2019 03:04:05", format("{0,}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_with_none_and_alignment_invalid) {
      assert::throws<format_exception>([] {format("{,a}", make_time<value_t>(2019, 1, 2, 3, 4, 5));});
      assert::throws<format_exception>([] {format("{, }", make_time<value_t>(2019, 1, 2, 3, 4, 5));});
    }
    
    void test_method_(format_with_sequence_number_and_alignment_invalid) {
      assert::throws<format_exception>([] {format("{0,a}", make_time<value_t>(2019, 1, 2, 3, 4, 5));});
      assert::throws<format_exception>([] {format("{0, }", make_time<value_t>(2019, 1, 2, 3, 4, 5));});
    }
    
    void test_method_(format_short_date_with_none) {
      assert::are_equal("1/2/2019", format("{:d}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_short_date_with_sequence_number) {
      assert::are_equal("1/2/2019", format("{0:d}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_long_date_with_none) {
      assert::are_equal("Wednesday, January 2, 2019", format("{:D}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_long_date_with_sequence_number) {
      assert::are_equal("Wednesday, January 2, 2019", format("{0:D}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_full_date_short_time_with_none) {
      assert::are_equal("Wednesday, January 2, 2019 03:04", format("{:f}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_full_date_short_time_with_sequence_number) {
      assert::are_equal("Wednesday, January 2, 2019 03:04", format("{0:f}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_full_date_long_time_with_none) {
      assert::are_equal("Wednesday, January 2, 2019 03:04:05", format("{:F}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_full_date_long_time_with_sequence_number) {
      assert::are_equal("Wednesday, January 2, 2019 03:04:05", format("{0:F}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_general_short_with_none) {
      assert::are_equal("1/2/2019 03:04", format("{:g}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_general_short_with_sequence_number) {
      assert::are_equal("1/2/2019 03:04", format("{0:g}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_general_long_with_none) {
      assert::are_equal("1/2/2019 03:04:05", format("{:G}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_general_long_with_sequence_number) {
      assert::are_equal("1/2/2019 03:04:05", format("{0:G}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_month_day_with_none) {
      assert::are_equal("January 2", format("{:m}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_month_day_with_none_2) {
      assert::are_equal("January 2", format("{:M}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_month_day_with_sequence_number) {
      assert::are_equal("January 2", format("{0:m}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_month_day_with_sequence_number_2) {
      assert::are_equal("January 2", format("{0:M}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_iso_8601_with_none) {
      assert::are_equal("2019-01-02T03:04:05.0000000Z", format("{:o}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_iso_8601_with_none_2) {
      assert::are_equal("2019-01-02T03:04:05.0000000Z", format("{:O}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_iso_8601_with_sequence_number) {
      assert::are_equal("2019-01-02T03:04:05.0000000Z", format("{0:o}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_iso_8601_with_sequence_number_2) {
      assert::are_equal("2019-01-02T03:04:05.0000000Z", format("{0:O}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_rfc1123_with_none) {
      assert::are_equal("Wed, 02 Jan 2019 03:04:05 GMT", format("{:r}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_rfc1123_with_none_2) {
      assert::are_equal("Wed, 02 Jan 2019 03:04:05 GMT", format("{:R}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_rfc1123_with_sequence_number) {
      assert::are_equal("Wed, 02 Jan 2019 03:04:05 GMT", format("{0:r}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_rfc1123_with_sequence_number_2) {
      assert::are_equal("Wed, 02 Jan 2019 03:04:05 GMT", format("{0:R}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_sortable_with_none) {
      assert::are_equal("2019-01-02T03:04:05", format("{:s}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_sortable_with_sequence_number) {
      assert::are_equal("2019-01-02T03:04:05", format("{0:s}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_short_time_with_none) {
      assert::are_equal("03:04", format("{:t}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_short_time_with_sequence_number) {
      assert::are_equal("03:04", format("{0:t}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_long_time_with_none) {
      assert::are_equal("03:04:05", format("{:T}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_long_time_with_sequence_number) {
      assert::are_equal("03:04:05", format("{0:T}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_universal_sortable_with_none) {
      assert::are_equal("2019-01-02 03:04:05Z", format("{:u}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_universal_sortable_with_sequence_number) {
      assert::are_equal("2019-01-02 03:04:05Z", format("{0:u}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_universal_full_with_none) {
      assert::are_equal("Wednesday, January 2, 2019 03:04:05", format("{:U}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_universal_full_with_sequence_number) {
      assert::are_equal("Wednesday, January 2, 2019 03:04:05", format("{0:U}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_year_month_with_none) {
      assert::are_equal("January 2019", format("{:y}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_year_month_with_none_2) {
      assert::are_equal("January 2019", format("{:Y}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_year_month_with_sequence_number) {
      assert::are_equal("January 2019", format("{0:y}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_year_month_with_sequence_number_2) {
      assert::are_equal("January 2019", format("{0:Y}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
  };
}
