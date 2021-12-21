#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../include/xtd/argument_out_of_range_exception.h"
#include "../include/xtd/format_exception.h"
#include "../include/xtd/invalid_operation_exception.h"
#include "../include/xtd/date_time.h"
#include "../include/xtd/unused.h"

using namespace std;
using namespace std::chrono;
using namespace xtd;

namespace {
  // Number of ticks per time unit
  const int64_t ticks_per_millisecond = 10000;
  const int64_t ticks_per_second = ticks_per_millisecond * 1000;
  const int64_t ticks_per_minute = ticks_per_second * 60;
  const int64_t ticks_per_hour = ticks_per_minute * 60;
  const int64_t ticks_per_day = ticks_per_hour * 24;
  
  // Number of milliseconds per time unit
  const int64_t mllis_per_second = 1000;
  const int64_t millis_per_minute = mllis_per_second * 60;
  const int64_t millis_per_our = millis_per_minute * 60;
  const int64_t millis_per_day = millis_per_our * 24;
  
  // Number of seconds per time unit
  const int64_t seconds_per_minute = 60;
  const int64_t seconds_per_our = seconds_per_minute * 60;
  const int64_t seconds_per_day = seconds_per_our * 24;

  // Number of days in a non-leap year
  const int64_t days_per_year = 365;
  // Number of days in 4 years
  const int64_t days_per_4_years = days_per_year * 4 + 1; // 1461
  // Number of days in 100 years
  const int64_t days_per_100_years = days_per_4_years * 25 - 1; // 36524
  // Number of days in 400 years
  const int64_t days_per_400_years = days_per_100_years * 4 + 1; // 146097
  
  // Number of days from 1/1/0001 to 12/31/1600
  const int64_t days_to_1601 = days_per_400_years * 4; // 584388
  // Number of days from 1/1/0001 to 12/30/1899
  const int64_t days_to_1899 = days_per_400_years * 4 + days_per_100_years * 3 - 367;
  // Number of days from 1/1/0001 to 12/31/1969
  const int64_t days_to_1970 = days_per_400_years * 4 + days_per_100_years * 3 + days_per_4_years * 17 + days_per_year; // 719,162
  // Number of days from 1/1/0001 to 12/31/9999
  const int64_t days_to_10000 = days_per_400_years * 25 - 366; // 3652059
 
  const int64_t min_ticks = 0;
  const int64_t max_ticks = days_to_10000 * ticks_per_day - 1;
  const int64_t max_millis = days_to_10000 * millis_per_day;
  
  const int64_t file_time_offset = days_to_1601 * ticks_per_day;
  const int64_t double_date_offset = days_to_1899 * ticks_per_day;
  
  //constexpr ticks ticks_offset_1970 = ticks(621672202500000000LL);
  //constexpr seconds seconds_offset_1970 = seconds(62167220250LL);
  //constexpr ticks ticks_offset_1970 = ticks(ticks_per_day * days_to_1970);
  constexpr seconds seconds_offset_1970 = seconds(seconds_per_day * days_to_1970);
 }

date_time date_time::max_value = xtd::ticks(max_ticks);
date_time date_time::min_value = xtd::ticks(min_ticks);

date_time::date_time(xtd::ticks ticks) : value_(ticks) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw argument_out_of_range_exception(csf_);
  
  /// @todo remove after using it...
  unused_(max_millis);
  unused_(file_time_offset);
  unused_(double_date_offset);
  unused_(seconds_offset_1970);

  unused_(days_to_1970);
  unused_(seconds_per_day);
}

date_time::date_time(xtd::ticks ticks, xtd::date_time_kind kind) : value_(ticks), kind_(kind) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw argument_out_of_range_exception(csf_);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day) {
  set_date_time(year, month, day, 0, 0, 0, 0, date_time_kind::unspecified);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second) {
  set_date_time(year, month, day, hour, minute, second, 0, date_time_kind::unspecified);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, date_time_kind kind) {
  set_date_time(year, month, day, hour, minute, second, 0, kind);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond) {
  set_date_time(year, month, day, hour, minute, second, millisecond, date_time_kind::unspecified);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind) {
  set_date_time(year, month, day, hour, minute, second, millisecond, kind);
}

date_time date_time::date() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return date_time(year, month, day, 0, 0, 0, 0, kind_);
}

uint32_t date_time::day() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return day;
}

xtd::day_of_week date_time::day_fo_week() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return static_cast<xtd::day_of_week>(day_of_week);
}

uint32_t date_time::day_of_year() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return day_of_year;
}

uint32_t date_time::hour() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return hour;
}

date_time_kind date_time::kind() const noexcept {
  return kind_;
}

date_time date_time::now() noexcept {
  return from_time_t(system_clock::to_time_t(system_clock::now()), date_time_kind::local);
}

uint32_t date_time::second() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return second;
}

xtd::ticks date_time::ticks() const noexcept {
  return value_;
}

date_time::time_point date_time::time_of_day() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return duration_cast<time_point>(chrono::hours(hour)) + duration_cast<time_point>(chrono::minutes(minute)) + duration_cast<time_point>(chrono::seconds(second));
}

date_time date_time::to_day() noexcept {
  date_time to_day = now();
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  to_day.get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return date_time(year, month, day, 0, 0, 0, 0, to_day.kind_);
}

date_time date_time::utc_now() noexcept {
  return from_time_t(system_clock::to_time_t(system_clock::now()), date_time_kind::utc);
}

uint32_t date_time::years() const noexcept {
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return year;
}

int32_t date_time::compare_to(const object& obj) const noexcept {
  if (!dynamic_cast<const date_time*>(&obj)) return 1;
  return compare_to(static_cast<const date_time&>(obj));
}

int32_t date_time::compare_to(const date_time& value) const noexcept {
  if (value_ < value.value_) return -1;
  if (value_ > value.value_) return 1;
  if ( kind_ < value.kind_) return -1;
  if (kind_ < value.kind_) return 1;
  return 0;
}

bool date_time::equals(const date_time& other) const noexcept {
  return value_ == other.value_ && kind_ == other.kind_;
}

bool date_time::equals(const object& other) const noexcept {
  return dynamic_cast<const date_time*>(&other) && equals(static_cast<const date_time&>(other));
}

date_time date_time::from_time_t(std::time_t value) {
  return from_time_t(value, date_time_kind::unspecified);
}

date_time date_time::from_time_t(std::time_t value, date_time_kind kind) {
  date_time result;
  result.value_ = duration_cast<xtd::ticks>(chrono::seconds(value) + seconds_offset_1970);
  result.kind_ = kind;
  return result;
}

xtd::ustring date_time::to_string() const noexcept {
  return to_string("G");
}

ustring date_time::to_string(const ustring& format) const {
  auto fmt = format;
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) format_exception("Invalid format", csf_);
    
  uint32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32 day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  tm time {};
  time.tm_year = year - 1900;
  time.tm_mon = month - 1;
  time.tm_mday = day;
  time.tm_hour = hour;
  time.tm_min = minute;
  time.tm_sec = second;
  time.tm_yday = day_of_year - 1;
  time.tm_wday = day_of_week;
  time.tm_isdst = -1;
  
  switch (fmt[0]) {
    case 'd': return __sprintf("%02d/%02d/%d", month, day, year);
    case 'D': return __sprintf("%d/%02d/%d", month, day, year);
    case 'f': return __tm_formatter("%Ec", time, std::locale());
    case 'F': return __tm_formatter("%c", time, std::locale());
    case 'g': return __tm_formatter("%Ec", time, std::locale());
    case 'G': return __tm_formatter("%c", time, std::locale());
    case 'h': return __sprintf("%s", __get_brief_weekday_name<char>(time, std::locale()).c_str());
    case 'H': return __sprintf("%s", __get_weekday_name<char>(time, std::locale()).c_str());
    case 'i': return __sprintf("%02d", day);
    case 'I': return __sprintf("%d", day);
    case 'j': return __sprintf("%s", __get_brief_month_name<char>(time, std::locale()).c_str());
    case 'J': return __sprintf("%s", __get_month_name<char>(time, std::locale()).c_str());
    case 'k': return __sprintf("%02d", time.tm_mon + 1);
    case 'K': return __sprintf("%d", time.tm_mon + 1);
    case 'l': return __sprintf("%02d", time.tm_year % 100);
    case 'L': return __sprintf("%d", time.tm_year + 1900);
    case 'm':
    case 'M': return __sprintf("%s %d", __get_month_name<char>(time, std::locale()).c_str(), day);
    case 'n': return __sprintf("%s, %d %s %d", __get_weekday_name<char>(time, std::locale()).c_str(), day, __get_month_name<char>(time, std::locale()).c_str(), time.tm_year + 1900);
    case 'N': return __sprintf("%s, %d %s %d %d:%02d:%02d", __get_weekday_name<char>(time, std::locale()).c_str(), day, __get_month_name<char>(time, std::locale()).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return __sprintf("%d %s %d", day, __get_month_name<char>(time, std::locale()).c_str(), time.tm_year + 1900);
    case 's': return __sprintf("%d-%02d-%02dT%02d:%02d:%02d", time.tm_year + 1900, time.tm_mon+1, day, time.tm_hour, time.tm_min, time.tm_sec);
    case 't': return __sprintf("%02d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return __sprintf("%d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return __sprintf("%d-%02d-%02d %02d:%02d:%02d", time.tm_year + 1900, time.tm_mon+1, day, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return __sprintf("%s, %d %s %d %d:%02d:%02d", __get_weekday_name<char>(time, std::locale()).c_str(), day, __get_month_name<char>(time, std::locale()).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return __sprintf("%02d:%02d", time.tm_hour, time.tm_min);
    case 'V': return __sprintf("%d:%02d", time.tm_hour, time.tm_min);
    case 'y': return __sprintf("%s %d", __get_month_name<char>(time, std::locale()).c_str(), time.tm_year % 100);
    case 'Y': return __sprintf("%s %d", __get_month_name<char>(time, std::locale()).c_str(), time.tm_year + 1900);
    case 'z':
    case 'Z': return __tm_formatter("%Z", time, std::locale());
    default: format_exception("Invalid format"); return {};
  }
}

std::time_t date_time::to_time_t() const {
  return (duration_cast<chrono::seconds>(value_) - seconds_offset_1970).count();
}

void date_time::get_date_time(uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year,  int32_t& day_of_week) const {
  if (kind_ == date_time_kind::local)
    native::date_time::local_time(to_time_t(), year, month, day, hour, minute, second, day_of_year, day_of_week);
  else
    native::date_time::gmt_time(to_time_t(), year, month, day, hour, minute, second, day_of_year, day_of_week);
}

void date_time::set_date_time(uint32_t year, uint32 month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind) {
  uint32 day_of_year = 0;
  int32 day_of_week = 0;
  
  uint32 max_year = 1, max_month = 1, max_day = 1, max_hour = 0, max_minute = 0, max_second = 0;
  max_value.get_date_time(max_year, max_month, max_day, max_hour, max_minute, max_second, day_of_year, day_of_week);
  
  uint32 min_year = 1, min_month = 1, min_day = 1, min_hour = 0, min_minute = 0, min_second = 0;
  min_value.get_date_time(min_year, min_month, min_day, min_hour, min_minute, min_second, day_of_year, day_of_week);
  
  if (year  < min_year ||
      (year == min_year && month  < min_month) ||
      (year == min_year && month == min_month && day  < min_day) ||
      (year == min_year && month == min_month && day == min_day && hour  < min_hour) ||
      (year == min_year && month == min_month && day == min_day && hour == min_hour && minute  < min_minute) ||
      (year == min_year && month == min_month && day == min_day && hour == min_hour && minute == min_minute && second < min_second))
    throw argument_out_of_range_exception(csf_);
  
  if (year  > max_year ||
      (year == max_year && month  > max_month) ||
      (year == max_year && month == max_month && day  > max_day) ||
      (year == max_year && month == max_month && day == max_day && hour > max_hour) ||
      (year == max_year && month == max_month && day == max_day && hour == max_hour && minute > max_minute) ||
      (year == max_year && month == max_month && day == max_day && hour == max_hour && minute == max_minute && second > max_second))
    throw argument_out_of_range_exception(csf_);
  
  int64 seconds = kind == date_time_kind::local ? native::date_time::make_local_time(year, month, day, hour, minute, second) : native::date_time::make_gmt_time(year, month, day, hour, minute, second);
  if (seconds == -1)
    throw invalid_operation_exception(csf_);
  
  kind_ = kind;
  value_ = duration_cast<xtd::ticks>(chrono::seconds(seconds) + seconds_offset_1970);
}

std::ostream& xtd::operator<<(std::ostream& os, const date_time& dt) noexcept {
  return os << dt.to_string();
}
