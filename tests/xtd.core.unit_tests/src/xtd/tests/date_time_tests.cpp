#include <sstream>
#include <xtd/date_time>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace std::chrono;
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
      date_time d;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::is_zero(d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks) {
      date_time d(duration_cast<ticks>(seconds(42)));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(seconds(42)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::are_equal(42u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 00:00:42", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_unspecified) {
      date_time d(duration_cast<ticks>(minutes(24)), date_time_kind::unspecified);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(minutes(24)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::are_equal(24u, d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 00:24:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_loacal) {
      date_time d(duration_cast<ticks>(minutes(24)), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(minutes(24)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::are_equal(24u, d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 00:24:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_utc) {
      date_time d(duration_cast<ticks>(hours(12)), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(hours(12)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::are_equal(12u, d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 12:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day) {
      date_time d(1971, 1, 5);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second) {
      date_time d(1971, 1, 5, 21, 10, 30);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_and_date_time_kind_unspecified) {
      date_time d(1971, 1, 5, 21, 10, 30, date_time_kind::unspecified);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_and_date_time_kind_local) {
      date_time d(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_and_date_time_kind_utc) {
      date_time d(1971, 1, 5, 21, 10, 30, date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond) {
      date_time d(1971, 1, 5, 21, 10, 30, 242);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::are_equal(242u, d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond_and_date_time_kind_unspecified) {
      date_time d(1971, 1, 5, 21, 10, 30, 242, date_time_kind::unspecified);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::are_equal(242u, d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond_and_date_time_kind_local) {
      date_time d(1971, 1, 5, 21, 10, 30, 242, date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::are_equal(242u, d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day_hour_minute_second_millisecond_and_date_time_kind_utc) {
      date_time d(1971, 1, 5, 21, 10, 30, 242, date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::are_equal(242u, d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_max_value) {
      date_time d = date_time::max_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(3155378975999999999ll, d.ticks(), csf_);
      assert::are_equal(9999u, d.year(), csf_);
      assert::are_equal(12u, d.month(), csf_);
      assert::are_equal(31u, d.day(), csf_);
      assert::are_equal(23u, d.hour(), csf_);
      assert::are_equal(59u, d.minute(), csf_);
      assert::are_equal(59u, d.second(), csf_);
      assert::are_equal(999u, d.millisecond(), csf_);
      assert::are_equal("9999-12-31 23:59:59", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_min_value) {
      date_time d = date_time::min_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::is_zero(d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_now) {
      assert::are_equal(date_time_kind::local, date_time::now().kind(), csf_);
      assert::is_not_zero(date_time::now().ticks(), csf_);
      assert::are_equal(system_clock::to_time_t(system_clock::now()), date_time::now().to_time_t(), csf_);
    }
    
    void test_method_(create_date_utc_now) {
      assert::are_equal(date_time_kind::utc, date_time::utc_now().kind(), csf_);
      assert::is_not_zero(date_time::utc_now().ticks(), csf_);
      assert::are_equal(system_clock::to_time_t(system_clock::now()), date_time::utc_now().to_local_time().to_time_t(), csf_);
    }
    
    void test_method_(from_duration) {
      date_time d = date_time::from_duration(hours(12));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(hours(12)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::are_equal(12u, d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 12:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(from_duration_local) {
      date_time d = date_time::from_duration(hours(12), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(hours(12)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::are_equal(12u, d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 12:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(from_duration_utc) {
      date_time d = date_time::from_duration(hours(12), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(hours(12)).count(), d.ticks(), csf_);
      assert::are_equal(1u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(1u, d.day(), csf_);
      assert::are_equal(12u, d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1-01-01 12:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(from_time_t) {
      struct tm tms = make_tm(1971, 1, 5, 21, 10, 30);
      date_time d = date_time::from_time_t(std::mktime(&tms));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(std::mktime(&tms), d.to_local_time().to_time_t(), csf_);
    }
    
    void test_method_(from_time_t_local) {
      struct tm tms = make_tm(1971, 1, 5, 21, 10, 30);
      date_time d = date_time::from_time_t(std::mktime(&tms), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(std::mktime(&tms), d.to_time_t(), csf_);
    }
    
    void test_method_(from_time_t_utc) {
      struct tm tms = make_tm(1971, 1, 5, 21, 10, 30);
      date_time d = date_time::from_time_t(std::mktime(&tms), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(std::mktime(&tms), d.to_local_time().to_time_t(), csf_);
    }
    
    void test_method_(from_tm) {
      date_time d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(from_tm_local) {
      date_time d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(from_tm_utc) {
      date_time d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(1971u, d.year(), csf_);
      assert::are_equal(1u, d.month(), csf_);
      assert::are_equal(5u, d.day(), csf_);
      assert::are_equal(21u, d.hour(), csf_);
      assert::are_equal(10u, d.minute(), csf_);
      assert::are_equal(30u, d.second(), csf_);
      assert::is_zero(d.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
    
    void test_method_(add_duration) {
      date_time d1(seconds(20), date_time_kind::local);
      date_time d2 = d1.add(seconds(22));
      assert::are_equal(duration_cast<ticks>(seconds(42)).count(), d2.ticks(), csf_);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(1u, d2.day(), csf_);
      assert::is_zero(d2.hour(), csf_);
      assert::is_zero(d2.minute(), csf_);
      assert::are_equal(42u, d2.second());
      assert::is_zero(d2.millisecond(), csf_);
    }
    
    void test_method_(add_time_span) {
      date_time d1(ticks(20), date_time_kind::local);
      date_time d2 = d1.add(time_span(22));
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(ticks(42).count(), d2.ticks(), csf_);
      assert::are_equal(1u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(1u, d2.day(), csf_);
      assert::is_zero(d2.hour(), csf_);
      assert::is_zero(d2.minute(), csf_);
      assert::is_zero(d2.second(), csf_);
      assert::is_zero(d2.millisecond(), csf_);
    }
    
    void test_method_(add_days) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_days(6.5);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(12u, d2.day(), csf_);
      assert::are_equal(9u, d2.hour(), csf_);
      assert::are_equal(10u, d2.minute(), csf_);
      assert::are_equal(30u, d2.second(), csf_);
      assert::is_zero(d2.millisecond(), csf_);
      assert::are_equal("1971-01-12 09:10:30", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_hours) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_hours(6.5);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(6u, d2.day(), csf_);
      assert::are_equal(3u, d2.hour(), csf_);
      assert::are_equal(40u, d2.minute(), csf_);
      assert::are_equal(30u, d2.second(), csf_);
      assert::is_zero(d2.millisecond(), csf_);
      assert::are_equal("1971-01-06 03:40:30", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_milliseconds) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_milliseconds(6.5);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(5u, d2.day(), csf_);
      assert::are_equal(21u, d2.hour(), csf_);
      assert::are_equal(10u, d2.minute(), csf_);
      assert::are_equal(30u, d2.second(), csf_);
      assert::are_equal(6u, d2.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_minutes) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_minutes(6.5);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(5u, d2.day(), csf_);
      assert::are_equal(21u, d2.hour(), csf_);
      assert::are_equal(17u, d2.minute(), csf_);
      assert::are_equal(0u, d2.second(), csf_);
      assert::is_zero(d2.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:17:00", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_months) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_months(6);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(7u, d2.month(), csf_);
      assert::are_equal(5u, d2.day(), csf_);
      assert::are_equal(21u, d2.hour(), csf_);
      assert::are_equal(10u, d2.minute(), csf_);
      assert::are_equal(30u, d2.second(), csf_);
      assert::is_zero(d2.millisecond(), csf_);
      assert::are_equal("1971-07-05 21:10:30", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_seconds) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_seconds(6.5);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(5u, d2.day(), csf_);
      assert::are_equal(21u, d2.hour(), csf_);
      assert::are_equal(10u, d2.minute(), csf_);
      assert::are_equal(36u, d2.second(), csf_);
      assert::are_equal(500u, d2.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:36", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_ticks) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_ticks(65000000);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1971u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(5u, d2.day(), csf_);
      assert::are_equal(21u, d2.hour(), csf_);
      assert::are_equal(10u, d2.minute(), csf_);
      assert::are_equal(36u, d2.second(), csf_);
      assert::are_equal(500u, d2.millisecond(), csf_);
      assert::are_equal("1971-01-05 21:10:36", d2.to_string("u"), csf_);
    }
    
    void test_method_(add_years) {
      date_time d1(1971, 1, 5, 21, 10, 30, date_time_kind::local);
      date_time d2 = d1.add_years(6);
      assert::are_equal(date_time_kind::local, d2.kind(), csf_);
      assert::are_equal(1977u, d2.year(), csf_);
      assert::are_equal(1u, d2.month(), csf_);
      assert::are_equal(5u, d2.day(), csf_);
      assert::are_equal(21u, d2.hour(), csf_);
      assert::are_equal(10u, d2.minute(), csf_);
      assert::are_equal(30u, d2.second(), csf_);
      assert::is_zero(d2.millisecond(), csf_);
      assert::are_equal("1977-01-05 21:10:30", d2.to_string("u"), csf_);
    }
  };
}
