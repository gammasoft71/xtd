#define _CRT_SECURE_NO_WARNINGS
#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

#include <time.h>
#if defined (WIN32)
static time_t __make_utc_date_time(struct tm* tm) noexcept { return _mkgmtime(tm); }
#else
static time_t __make_utc_date_time(struct tm* tm) noexcept { return timegm(tm); }
#endif

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace {
  static std::tm to_local_time(time_t time) noexcept {return *std::localtime(&time);}
  //static std::tm to_local_time(const std::chrono::system_clock::time_point& time) noexcept {return to_local_time(std::chrono::system_clock::to_time_t(time));}
  static std::tm to_local_time(std::tm time) noexcept {
    if (xtd::to_string(time, "Z") != "" && xtd::to_string(time, "Z") == "UTC") return to_local_time(__make_utc_date_time(&time));
    return to_local_time(mktime(&time));
  }
  
  static std::tm to_universal_time(time_t time) noexcept {return *std::gmtime(&time);}
#if !defined (WIN32)
  static std::tm to_universal_time(const std::chrono::system_clock::time_point& time) noexcept {return to_universal_time(std::chrono::system_clock::to_time_t(time));}
#endif
  static std::tm to_universal_time(std::tm time) noexcept {
    if (xtd::to_string(time, "Z") != "" && xtd::to_string(time, "Z") == "UTC") return to_universal_time(mktime(&time));
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
#if !defined (WIN32)
	  time.tm_gmtoff = 0;
	  time.tm_zone = nullptr;
#endif

	  return utc ? to_universal_time(time) : to_local_time(time);
  }

  std::tm make_time(int year, int month, int day, bool utc=false) {return make_time(year, month, day, 0, 0, 0, utc); }
   
  template<typename time_t>
  time_t make_time(int year, int month, int day, int hour, int minute, int second, bool utc=false);
  
  template<>
  std::tm make_time<std::tm>(int year, int month, int day, int hour, int minute, int second, bool utc) {return make_time(year, month, day, hour, minute, second, utc);}
  
  template<>
  std::chrono::system_clock::time_point make_time<std::chrono::system_clock::time_point>(int year, int month, int day, int hour, int minute, int second, bool utc) {
    std::tm time = make_time(year, month, day, hour, minute, second, utc);
    return std::chrono::system_clock::from_time_t(mktime(&time));
  }
  
  template<typename time_t>
  time_t make_time(int year, int month, int day, bool utc=false);
  
  template<>
  std::tm make_time<std::tm>(int year, int month, int day, bool utc) {return make_time(year, month, day, utc);}
  
  template<>
  std::chrono::system_clock::time_point make_time<std::chrono::system_clock::time_point>(int year, int month, int day, bool utc) {
    std::tm time = make_time(year, month, day, utc);
    return std::chrono::system_clock::from_time_t(mktime(&time));
  }
}

namespace unit_tests {
  template <typename value_t>
  class test_wstring_date_time_format;
  
#if !WIN32
  test_class_attribute<test_wstring_date_time_format<std::tm>> test_wstring_date_time_format_class_std_tm_attr {"test_wstring_date_time_format<std::tm>"};
  test_class_attribute<test_wstring_date_time_format<std::chrono::system_clock::time_point>> test_wstring_date_time_format_class_std_chrono_system_clock_time_point_attr {"test_wstring_date_time_format<std::chrono::system_clock::time_point>"};
#endif
  
  template<typename value_t>
  class test_wstring_date_time_format : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_default_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_left_alignment) {
#if __APPLE__
      assert::are_equal(L"           Wed Jan  2 03:04:05 2019", ustring::format(L"{0, 35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"                1/2/2019 3:04:05 AM", ustring::format(L"{0, 35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"    Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0, 35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_left_alignment_wth_plus) {
#if __APPLE__
      assert::are_equal(L"           Wed Jan  2 03:04:05 2019", ustring::format(L"{0,+35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"                1/2/2019 3:04:05 AM", ustring::format(L"{0,+35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"    Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0,+35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }

    void test_method_(format_date_time_local_with_left_to_zero) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0,0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0,0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0,0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_right_alignment) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019           ", ustring::format(L"{0,-35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM                ", ustring::format(L"{0,-35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0,-35}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }

    void test_method_(format_date_time_local_with_right_alignment_to_zero) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0,-0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0,-0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0,-0}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_alignment_empty) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0,}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0,}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0,}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_alignment_invalid) {
      assert::throws<format_exception>([]{ustring::format(L"{0,a}", make_time<value_t>(2019, 1, 2, 3, 4, 5));});
    }

    void test_method_(format_date_time_local_with_std_tm_with_date_argument_and_zero_fill) {
      assert::are_equal(L"01/02/2019", ustring::format(L"{0:d}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_date_argument) {
      assert::are_equal(L"1/02/2019", ustring::format(L"{0:D}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_utc_with_std_tm_with_alternative_full_date_time_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0:f}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0:f}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0:f}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_utc_with_std_tm_with_full_date_time_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0:F}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0:F}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0:F}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }

    void test_method_(format_date_time_local_with_std_tm_with_alternative_general_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0:g}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0:g}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0:g}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_general_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", ustring::format(L"{0:G}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", ustring::format(L"{0:G}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", ustring::format(L"{0:G}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_brief_weekday_name_argument) {
      assert::are_equal(L"Wed", ustring::format(L"{0:h}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_weekday_name_argument) {
      assert::are_equal(L"Wednesday", ustring::format(L"{0:H}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_day_argument_and_zero_fill) {
      assert::are_equal(L"02", ustring::format(L"{0:i}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_day_argument) {
      assert::are_equal(L"2", ustring::format(L"{0:I}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_brief_month_name_argument) {
      assert::are_equal(L"Jan", ustring::format(L"{0:j}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_name_argument) {
      assert::are_equal(L"January", ustring::format(L"{0:J}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_argument_and_zero_fill) {
      assert::are_equal(L"01", ustring::format(L"{0:k}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_argument) {
      assert::are_equal(L"1", ustring::format(L"{0:K}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_year_on_two_digits_argument) {
      assert::are_equal(L"19", ustring::format(L"{0:l}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_year_argument) {
      assert::are_equal(L"2019", ustring::format(L"{0:L}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_day_argument) {
      assert::are_equal(L"January 2", ustring::format(L"{0:M}", make_time<value_t>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_natural_date_argument) {
      assert::are_equal(L"Wednesday, 2 January 2019", ustring::format(L"{0:n}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_natural_date_time_argument) {
      assert::are_equal(L"Wednesday, 2 January 2019 3:04:05", ustring::format(L"{0:N}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_ordinary_date_argument) {
      assert::are_equal(L"2 January 2019", ustring::format(L"{0:O}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_sortable_argument) {
      assert::are_equal(L"2019-01-02T03:04:05", ustring::format(L"{0:s}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_argument_and_zero_fill) {
      assert::are_equal(L"03:04:05", ustring::format(L"{0:t}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_argument) {
      assert::are_equal(L"3:04:05", ustring::format(L"{0:T}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_alternative_universale_argument_and_zero_fill) {
      assert::are_equal(L"2019-01-02 03:04:05", ustring::format(L"{0:u}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_universale_argument_and_zero_fill) {
      assert::are_equal(L"Wednesday, 2 January 2019 3:04:05", ustring::format(L"{0:U}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_without_seconds_argument_and_zero_fill) {
      assert::are_equal(L"03:04", ustring::format(L"{0:v}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_without_seconds_argument) {
      assert::are_equal(L"3:04", ustring::format(L"{0:V}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_year_on_two_digits_argument) {
      assert::are_equal(L"January 19", ustring::format(L"{0:y}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_year_argument) {
      assert::are_equal(L"January 2019", ustring::format(L"{0:Y}", make_time<value_t>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_zone_argument) {
#if __APPLE__
      assert::are_equal(L"UTC", ustring::format(L"{0:Z}", to_universal_time(make_time<value_t>(2019, 1, 2, 3, 4, 5))));
#elif WIN32 && _WIN64
      assert::are_equal(L"", ustring::format(L"{0:Z}", to_universal_time(make_time<value_t>(2019, 1, 2, 3, 4, 5))));
#elif WIN32
      assert::are_equal(L"Coordinated Universal time_t", ustring::format(L"{0:Z}", to_universal_time(make_time<value_t>(2019, 1, 2, 3, 4, 5))));
#else
      assert::are_equal(L"GMT", ustring::format(L"{0:Z}", to_universal_time(make_time<value_t>(2019, 1, 2, 3, 4, 5))));
#endif
    }
  };
}
