#include <sstream>
#include <xtd/date_time>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(date_time_tests) {
    static std::tm make_tm(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) {
      std::tm date = {};
      date.tm_year = year - 1900;
      date.tm_mon = month - 1;
      date.tm_mday = day;
      date.tm_hour = hour;
      date.tm_min = minute;
      date.tm_sec = second;
      return date;
    }
    
    void test_method_(create_date_with_default_constructor) {
      auto d = date_time {};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::is_zero(d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::is_zero(d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 0:00:00 AM", d.to_string());
    }
    
    void test_method_(create_date_with_ticks) {
      auto d = date_time {std::chrono::duration_cast<ticks>(std::chrono::seconds(42))};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::seconds(42)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::is_zero(d.hour());
      assert::is_zero(d.minute());
      assert::are_equal(42u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 0:00:42 AM", d.to_string());
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_unspecified) {
      auto d = date_time {std::chrono::duration_cast<ticks>(std::chrono::minutes(24)), date_time_kind::unspecified};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::minutes(24)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::is_zero(d.hour());
      assert::are_equal(24u, d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 0:24:00 AM", d.to_string());
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_loacal) {
      auto d = date_time {std::chrono::duration_cast<ticks>(std::chrono::minutes(24)), date_time_kind::local};
      assert::are_equal(date_time_kind::local, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::minutes(24)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::is_zero(d.hour());
      assert::are_equal(24u, d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 0:24:00 AM", d.to_string());
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_utc) {
      auto d = date_time {std::chrono::duration_cast<ticks>(std::chrono::hours(12)), date_time_kind::utc};
      assert::are_equal(date_time_kind::utc, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::hours(12)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::are_equal(12u, d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 12:00:00 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day) {
      auto d = date_time {1971, 1, 5};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::is_zero(d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 0:00:00 AM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second) {
      auto d = date_time {1971, 1, 5, 21, 10, 30};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_and_date_time_kind_unspecified) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::unspecified};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_and_date_time_kind_local) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      assert::are_equal(date_time_kind::local, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_and_date_time_kind_utc) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::utc};
      assert::are_equal(date_time_kind::utc, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, 242};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::are_equal(242u, d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond_and_date_time_kind_unspecified) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, 242, date_time_kind::unspecified};
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::are_equal(242u, d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond_and_date_time_kind_local) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, 242, date_time_kind::local};
      assert::are_equal(date_time_kind::local, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::are_equal(242u, d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond_and_date_time_kind_utc) {
      auto d = date_time {1971, 1, 5, 21, 10, 30, 242, date_time_kind::utc};
      assert::are_equal(date_time_kind::utc, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::are_equal(242u, d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(create_date_max_value) {
      auto d = date_time::max_value;
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(3155378975999999999ll, d.ticks());
      assert::are_equal(9999u, d.year());
      assert::are_equal(12u, d.month());
      assert::are_equal(31u, d.day());
      assert::are_equal(23u, d.hour());
      assert::are_equal(59u, d.minute());
      assert::are_equal(59u, d.second());
      assert::are_equal(999u, d.millisecond());
      assert::are_equal("12/31/9999 11:59:59 PM", d.to_string());
    }
    
    void test_method_(create_date_min_value) {
      auto d = date_time::min_value;
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::is_zero(d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::is_zero(d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 0:00:00 AM", d.to_string());
    }
    
    void test_method_(create_date_now) {
      assert::are_equal(date_time_kind::local, date_time::now().kind());
      assert::is_not_zero(date_time::now().ticks());
      assert::are_equal(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()), date_time::now().to_time_t());
    }
    
    void test_method_(create_date_utc_now) {
      assert::are_equal(date_time_kind::utc, date_time::utc_now().kind());
      assert::is_not_zero(date_time::utc_now().ticks());
      assert::are_equal(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()), date_time::utc_now().to_local_time().to_time_t());
    }
    
    void test_method_(from_duration) {
      auto d = date_time::from_duration(std::chrono::hours(12));
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::hours(12)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::are_equal(12u, d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 12:00:00 PM", d.to_string());
    }
    
    void test_method_(from_duration_local) {
      auto d = date_time::from_duration(std::chrono::hours(12), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::hours(12)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::are_equal(12u, d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 12:00:00 PM", d.to_string());
    }
    
    void test_method_(from_duration_utc) {
      auto d = date_time::from_duration(std::chrono::hours(12), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind());
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::hours(12)).count(), d.ticks());
      assert::are_equal(1u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(1u, d.day());
      assert::are_equal(12u, d.hour());
      assert::is_zero(d.minute());
      assert::is_zero(d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/1/0001 12:00:00 PM", d.to_string());
    }
    
    void test_method_(from_time_t) {
      auto tms = make_tm(1971, 1, 5, 21, 10, 30);
      auto d = date_time::from_time_t(std::mktime(&tms));
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(std::mktime(&tms), d.to_local_time().to_time_t());
    }
    
    void test_method_(from_time_t_local) {
      auto tms = make_tm(1971, 1, 5, 21, 10, 30);
      auto d = date_time::from_time_t(std::mktime(&tms), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind());
      assert::are_equal(std::mktime(&tms), d.to_time_t());
    }
    
    void test_method_(from_time_t_utc) {
      auto tms = make_tm(1971, 1, 5, 21, 10, 30);
      auto d = date_time::from_time_t(std::mktime(&tms), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind());
      assert::are_equal(std::mktime(&tms), d.to_local_time().to_time_t());
    }
    
    void test_method_(from_tm) {
      auto d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30));
      assert::are_equal(date_time_kind::unspecified, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(from_tm_local) {
      auto d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(from_tm_utc) {
      auto d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind());
      assert::are_equal(1971u, d.year());
      assert::are_equal(1u, d.month());
      assert::are_equal(5u, d.day());
      assert::are_equal(21u, d.hour());
      assert::are_equal(10u, d.minute());
      assert::are_equal(30u, d.second());
      assert::is_zero(d.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d.to_string());
    }
    
    void test_method_(add_duration) {
      auto d1 = date_time {std::chrono::seconds(20), date_time_kind::local};
      auto d2 = d1.add(std::chrono::seconds(22));
      assert::are_equal(std::chrono::duration_cast<ticks>(std::chrono::seconds(42)).count(), d2.ticks());
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(1u, d2.day());
      assert::is_zero(d2.hour());
      assert::is_zero(d2.minute());
      assert::are_equal(42u, d2.second());
      assert::is_zero(d2.millisecond());
    }
    
    void test_method_(add_time_span) {
      auto d1 = date_time {ticks(20), date_time_kind::local};
      auto d2 = d1.add(time_span(22));
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(ticks(42).count(), d2.ticks());
      assert::are_equal(1u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(1u, d2.day());
      assert::is_zero(d2.hour());
      assert::is_zero(d2.minute());
      assert::is_zero(d2.second());
      assert::is_zero(d2.millisecond());
    }
    
    void test_method_(add_days) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_days(6.5);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(12u, d2.day());
      assert::are_equal(9u, d2.hour());
      assert::are_equal(10u, d2.minute());
      assert::are_equal(30u, d2.second());
      assert::is_zero(d2.millisecond());
      assert::are_equal("1/12/1971 9:10:30 AM", d2.to_string());
    }
    
    void test_method_(add_hours) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_hours(6.5);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(6u, d2.day());
      assert::are_equal(3u, d2.hour());
      assert::are_equal(40u, d2.minute());
      assert::are_equal(30u, d2.second());
      assert::is_zero(d2.millisecond());
      assert::are_equal("1/6/1971 3:40:30 AM", d2.to_string());
    }
    
    void test_method_(add_milliseconds) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_milliseconds(6.5);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(5u, d2.day());
      assert::are_equal(21u, d2.hour());
      assert::are_equal(10u, d2.minute());
      assert::are_equal(30u, d2.second());
      assert::are_equal(6u, d2.millisecond());
      assert::are_equal("1/5/1971 9:10:30 PM", d2.to_string());
    }
    
    void test_method_(add_minutes) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_minutes(6.5);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(5u, d2.day());
      assert::are_equal(21u, d2.hour());
      assert::are_equal(17u, d2.minute());
      assert::are_equal(0u, d2.second());
      assert::is_zero(d2.millisecond());
      assert::are_equal("1/5/1971 9:17:00 PM", d2.to_string());
    }
    
    void test_method_(add_months) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_months(6);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(7u, d2.month());
      assert::are_equal(5u, d2.day());
      assert::are_equal(21u, d2.hour());
      assert::are_equal(10u, d2.minute());
      assert::are_equal(30u, d2.second());
      assert::is_zero(d2.millisecond());
      assert::are_equal("7/5/1971 9:10:30 PM", d2.to_string());
    }
    
    void test_method_(add_seconds) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_seconds(6.5);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(5u, d2.day());
      assert::are_equal(21u, d2.hour());
      assert::are_equal(10u, d2.minute());
      assert::are_equal(36u, d2.second());
      assert::are_equal(500u, d2.millisecond());
      assert::are_equal("1/5/1971 9:10:36 PM", d2.to_string());
    }
    
    void test_method_(add_ticks) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_ticks(65000000);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1971u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(5u, d2.day());
      assert::are_equal(21u, d2.hour());
      assert::are_equal(10u, d2.minute());
      assert::are_equal(36u, d2.second());
      assert::are_equal(500u, d2.millisecond());
      assert::are_equal("1/5/1971 9:10:36 PM", d2.to_string());
    }
    
    void test_method_(add_years) {
      auto d1 = date_time {1971, 1, 5, 21, 10, 30, date_time_kind::local};
      auto d2 = d1.add_years(6);
      assert::are_equal(date_time_kind::local, d2.kind());
      assert::are_equal(1977u, d2.year());
      assert::are_equal(1u, d2.month());
      assert::are_equal(5u, d2.day());
      assert::are_equal(21u, d2.hour());
      assert::are_equal(10u, d2.minute());
      assert::are_equal(30u, d2.second());
      assert::is_zero(d2.millisecond());
      assert::are_equal("1/5/1977 9:10:30 PM", d2.to_string());
    }
  };
}
