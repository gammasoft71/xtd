#include "../include/xtd/text/string_builder.hpp"
#include "../include/xtd/collections/generic/list.hpp"
#include "../include/xtd/collections/generic/dictionary.hpp"
#include "../include/xtd/argument_out_of_range_exception.hpp"
#include "../include/xtd/as.hpp"
#include "../include/xtd/char_object.hpp"
#include "../include/xtd/format_exception.hpp"
#include "../include/xtd/invalid_operation_exception.hpp"
#include "../include/xtd/date_time.hpp"
#include "../include/xtd/math.hpp"
#include "../include/xtd/not_implemented_exception.hpp"
#include "../include/xtd/time_zone_info.hpp"
#include "../include/xtd/unused.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <tuple>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::helpers;
using namespace xtd::text;

namespace {
  // Number of ticks per time unit
  constexpr auto ticks_per_millisecond = 10000ll;
  constexpr auto ticks_per_second = ticks_per_millisecond * 1000ll;
  constexpr auto ticks_per_minute = ticks_per_second * 60ll;
  constexpr auto ticks_per_hour = ticks_per_minute * 60ll;
  constexpr auto ticks_per_day = ticks_per_hour * 24ll;
  
  // Number of seconds per time unit
  constexpr auto seconds_per_minute = 60ll;
  constexpr auto seconds_per_our = seconds_per_minute * 60ll;
  constexpr auto seconds_per_day = seconds_per_our * 24ll;
  
  // Number of days in a non-leap year
  constexpr auto days_per_year = 365ll;
  // Number of days in 4 years
  constexpr auto days_per_4_years = days_per_year * 4 + 1; // 1461
  // Number of days in 100 years
  constexpr auto days_per_100_years = days_per_4_years * 25 - 1; // 36524
  // Number of days in 400 years
  constexpr auto days_per_400_years = days_per_100_years * 4 + 1; // 146097
  
  // Number of days from 1/1/0001 to 12/31/1600
  constexpr auto days_to_1601 = days_per_400_years * 4; // 584388
  // Number of days from 1/1/0001 to 12/31/1969
  constexpr auto days_to_1970 = days_per_400_years * 4 + days_per_100_years * 3 + days_per_4_years * 17 + days_per_year; // 719,162
  // Number of days from 1/1/0001 to 12/31/9999
  constexpr auto days_to_10000 = days_per_400_years * 25 - 366; // 3652059
  
  constexpr auto min_ticks = ticks {0};
  constexpr auto max_ticks = ticks {days_to_10000* ticks_per_day - 1};
  
  constexpr auto file_time_offset = ticks {days_to_1601 * ticks_per_day};
  
  constexpr auto seconds_offset_1970 = std::chrono::seconds(seconds_per_day* days_to_1970);
  
  const auto custom_formats = dictionary<char, string> {{'d', "M/d/yyyy"}, {'D', "dddd, MMMM d, yyyy"}, {'f', "dddd, MMMM d, yyyy HH:mm"}, {'F', "dddd, MMMM d, yyyy HH:mm:ss"}, {'g', "M/d/yyyy HH:mm"}, {'G', "M/d/yyyy HH:mm:ss"}, {'m', "MMMM d"}, {'M', "MMMM d"}, {'o', "yyyy-MM-ddTHH:mm:ss.fffffffK"}, {'O', "yyyy-MM-ddTHH:mm:ss.fffffffK"}, {'r', "ddd, dd MMM yyyy HH:mm:ss G\\MT"}, {'R', "ddd, dd MMM yyyy HH:mm:ss G\\MT"}, {'s', "yyyy-MM-ddTHH:mm:ss"}, {'t', "HH:mm"}, {'T', "HH:mm:ss"}, {'u', "yyyy-MM-dd HH:mm:ssZ"}, {'U', "dddd, MMMM d, yyyy HH:mm:ss"}, {'y', "MMMM yyyy"}, {'Y', "MMMM yyyy"}};
  
  static std::tuple<uint32, uint32> get_year_and_day_of_year(int64 days) {
    auto year = 1_s64;
    auto day_of_year = days;
    
    if (day_of_year >= days_per_400_years) {
      auto chunks = day_of_year / days_per_400_years;
      year += chunks * 400;
      day_of_year -= chunks * days_per_400_years;
    }
    
    if (day_of_year >= days_per_100_years) {
      auto chunks = day_of_year / days_per_100_years;
      if (chunks == 4) chunks = 3;
      year += chunks * 100;
      day_of_year -= chunks * days_per_100_years;
    }
    
    if (day_of_year >= days_per_4_years) {
      auto chunks = day_of_year / days_per_4_years;
      year += chunks * 4;
      day_of_year -= chunks * days_per_4_years;
    }
    
    if (day_of_year >= days_per_year) {
      auto chunks = day_of_year / days_per_year;
      if (chunks == 4) chunks = 3;
      year += chunks;
      day_of_year -= chunks * days_per_year;
    }
    
    return std::make_tuple(as<uint32>(year), as<uint32>(day_of_year));
  }
  
  static uint32 get_year(int64 days) {
    auto [year, day_of_year] = get_year_and_day_of_year(days);
    return year;
  }
  
  static uint32 get_day_of_year(int64 days) {
    auto [year, day_of_year] = get_year_and_day_of_year(days);
    return day_of_year;
  }
  
  static std::tuple<uint32, uint32> get_month_and_day(int64 day_of_year, uint32 year) {
    auto month = 1_u32;
    auto day = day_of_year;
    for (auto days_in_month = as<int64>(date_time::days_in_month(year, month)); day >= days_in_month; days_in_month = date_time::days_in_month(year, month)) {
      ++month;
      day -= days_in_month;
    }
    return std::make_tuple(month, as<uint32>(day));
  }
  
  static uint32 get_month(int64 day_of_year, uint32 year) {
    auto [month, day] = get_month_and_day(day_of_year, year);
    return month;
  }
  
  static uint32 get_day(int64 day_of_year, uint32 year) {
    auto [month, day] = get_month_and_day(day_of_year, year);
    return day;
  }
  
  static std::tm make_tm_time(int year, int month, int day, int hour, int minute, int second) {
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
    
    return time;
  }
  
  static array<string> get_days(const std::locale& loc) {
    auto days = list<string> {};
    for (auto index = 1; index <= 7; ++index)
      days.add(date_time::sprintf("%A", date_time::from_tm(make_tm_time(1970, 1, index + 4, 0, 0, 0)), loc));
    return days.to_array();
  }
  
  static array<string> get_months(const std::locale& loc) {
    auto months = list<string> {};
    for (auto index = 1; index <= 12; ++index)
      months.add(date_time::sprintf("%B", date_time::from_tm(make_tm_time(1970, index, 1, 0, 0, 0)), loc));
    return months.to_array();
  }
  
  static array<string> get_short_days(const std::locale& loc) {
    auto days = list<string> {};
    for (auto index = 1; index <= 7; ++index)
      days.add(date_time::sprintf("%a", date_time::from_tm(make_tm_time(1970, 1, index + 4, 0, 0, 0)), loc));
    return days.to_array();
  }
  
  static array<string> get_short_months(const std::locale& loc) {
    static auto months = list<string> {};
    if (months.count()) return months.to_array();
    for (auto index = 1; index <= 12; ++index)
      months.add(date_time::sprintf("%b", date_time::from_tm(make_tm_time(1970, index, 1, 0, 0, 0)), loc));
    return months.to_array();
  }
  
  static string get_time_suffix(const date_time& dt, const std::locale& loc) {
    auto suffix = date_time::sprintf("%p", dt, loc);
    if (!string::is_empty(suffix)) return suffix;
    suffix = date_time::sprintf("%p", dt, std::locale("en_US"));
    if (!string::is_empty(suffix)) return suffix;
    return dt.hour() / 12 ? "PM" : "AM";
  }
  
  static array<string> get_time_suffixes(const std::locale& loc) {
    auto suffixes = list<string> {};
    for (auto dt : {date_time::from_tm(make_tm_time(1970, 1, 1, 1, 0, 0)), date_time::from_tm(make_tm_time(1970, 1, 1, 13, 0, 0))})
      suffixes.add(get_time_suffix(dt, loc));
    return suffixes.to_array();
  }
  
  static size to_string_custom_char_count(const string& format, size& index, size max_char) {
    auto character = format[index];
    auto count = 1_z;
    while (index + count < format.length() && format[index + count] == character) ++count;
    index += count - 1;
    return math::min(max_char, count);
  }
  
  static string to_string_custom_day(const string& format, size& index, uint32 day, const date_time& dt, const std::locale& loc) {
    auto count = to_string_custom_char_count(format, index, 4_z);
    if (count == 4) return date_time::sprintf("%A", dt, loc);
    if (count == 3) return date_time::sprintf("%a", dt, loc);
    if (count == 2) return string::format("{:D2}", day);
    return string::format("{:D}", day);
  }
  
  static string to_string_custom_fraction(const string& format, size& index, int64 ticks) {
    bool remove_trailing_zeros = (format[index] == 'F');
    auto count = to_string_custom_char_count(format, index, 7_z);
    auto fraction = ticks % ticks_per_second / static_cast<int64>(math::pow(10, 7 - as<double>(count)));
    auto result = string::format(string::format("{{:D{}}}", count), fraction);
    if (!remove_trailing_zeros) return result;
    while (!string::is_empty(result) && result[result.length() - 1] == '0')
      result = result.substr(0, result.length() - 1);
    return result;
  }
  
  static string to_string_custom_hour(const string& format, size& index, uint32 hour) {
    auto count = to_string_custom_char_count(format, index, 2_z);
    if (count == 2) return string::format("{:D2}", hour);
    return string::format("{:D}", hour);
  }
  
  static string to_string_custom_minute(const string& format, size& index, uint32 minute) {
    auto count = to_string_custom_char_count(format, index, 2_z);
    if (count == 2) return string::format("{:D2}", minute);
    return string::format("{:D}", minute);
  }
  
  static string to_string_custom_month(const string& format, size& index, uint32 month, const date_time& dt, const std::locale& loc) {
    auto count = to_string_custom_char_count(format, index, 4_z);
    if (count == 4) return date_time::sprintf("%B", dt, loc);
    if (count == 3) return date_time::sprintf("%b", dt, loc);
    if (count == 2) return string::format("{:D2}", month);
    return string::format("{:D}", month);
  }
  
  static string to_string_custom_offset_utc(const string& format, size& index, int64 offset_sec) {
    auto count = to_string_custom_char_count(format, index, 3_z);
    if (count == 3) return string::format("{}{:D2}:{:D2}", offset_sec >= 0 ? "+" : "", offset_sec / 3600, math::abs(offset_sec % 3600) / 60);
    if (count == 2) return string::format("{}{:D2}", offset_sec >= 0 ? "+" : "", offset_sec / 3600);
    return string::format("{}{:D}", offset_sec >= 0 ? "+" : "", offset_sec / 3600);
  }
  
  static string to_string_custom_second(const string& format, size& index, uint32 second) {
    auto count = to_string_custom_char_count(format, index, 2_z);
    if (count == 2) return string::format("{:D2}", second);
    return string::format("{:D}", second);
  }
  
  static string to_string_custom_time_suffix(const string& format, size& index, uint32 hour, const date_time& dt, const std::locale& loc) {
    auto count = to_string_custom_char_count(format, index, 2_z);
    return get_time_suffix(dt, loc).substring(0, count);
  }
  
  static string to_string_custom_time_zone_information(const string& format, size& index, date_time_kind kind, int64 offset_sec) {
    auto tmp_index = 0_z;
    return kind == date_time_kind::local ? to_string_custom_offset_utc("zzz", tmp_index, offset_sec) : "Z";
  }
  
  static string to_string_custom_year(const string& format, size& index, uint32 year) {
    auto count = to_string_custom_char_count(format, index, 4_z);
    if (count >= 3) return string::format("{:D4}", year);
    return string::format("{:D2}", year % 100);
  }
  
  #if defined(_WIN32)
  inline struct tm* to_tm(const time_t* timer, struct tm* buf) noexcept {
    localtime_s(buf, timer);
    return buf;
  }
  #else
  inline struct tm* to_tm(const time_t* timer, struct tm* buf) noexcept {
    return localtime_r(timer, buf);
  }
  #endif
  
  string date_time_formatter(string fmt, const std::tm& time, uint32 nanoseconds, const std::locale& loc) {
    auto dt = xtd::date_time(time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    dt.add_ticks(nanoseconds * 100);
    return dt.to_string(fmt, loc);
  }
}

const date_time date_time::max_value {max_ticks};
const date_time date_time::min_value {min_ticks};

date_time::date_time(int64 ticks) : value_(ticks) {
  if (ticks < min_value.value_.count() || ticks > max_value.value_.count()) throw_helper::throws(exception_case::argument_out_of_range);
}

date_time::date_time(xtd::ticks ticks) : value_(ticks) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw_helper::throws(exception_case::argument_out_of_range);
}

date_time::date_time(int64 ticks, xtd::date_time_kind kind) : value_(ticks), kind_(kind) {
  if (ticks < min_value.value_.count() || ticks > max_value.value_.count()) throw_helper::throws(exception_case::argument_out_of_range);
}

date_time::date_time(xtd::ticks ticks, xtd::date_time_kind kind) : value_(ticks), kind_(kind) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw_helper::throws(exception_case::argument_out_of_range);
}

date_time::date_time(uint32 year, uint32 month, uint32 day) {
  set_date_time(year, month, day, 0, 0, 0, 0, date_time_kind::unspecified);
}

date_time::date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second) {
  set_date_time(year, month, day, hour, minute, second, 0, date_time_kind::unspecified);
}

date_time::date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, date_time_kind kind) {
  set_date_time(year, month, day, hour, minute, second, 0, kind);
}

date_time::date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, uint32 millisecond) {
  set_date_time(year, month, day, hour, minute, second, millisecond, date_time_kind::unspecified);
}

date_time::date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, uint32 millisecond, date_time_kind kind) {
  set_date_time(year, month, day, hour, minute, second, millisecond, kind);
}

date_time date_time::date() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return date_time {year, month, day, 0, 0, 0, 0, kind_};
}

uint32 date_time::day() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return day;
}

xtd::day_of_week date_time::day_of_week() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return as<xtd::day_of_week>(day_of_week);
}

uint32 date_time::day_of_year() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return day_of_year;
}

uint32 date_time::hour() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return hour;
}

date_time_kind date_time::kind() const noexcept {
  return kind_;
}

uint32 date_time::millisecond() const noexcept {
  return std::chrono::duration_cast<std::chrono::milliseconds>(value_).count() % 1000;
}

uint32 date_time::minute() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return minute;
}

uint32 date_time::month() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return month;
}

date_time date_time::now() noexcept {
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  auto now_ticks = std::chrono::duration_cast<xtd::ticks>(now.time_since_epoch()) % ticks_per_second;
  return from_time_t(std::chrono::system_clock::to_time_t(now), date_time_kind::local).add(now_ticks);
}

uint32 date_time::second() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return second;
}

int64 date_time::ticks() const noexcept {
  return value_.count();
}

xtd::ticks date_time::ticks_duration() const noexcept {
  return value_;
}

time_span date_time::time_of_day() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return time_span {hour, minute, second};
}

date_time date_time::today() noexcept {
  auto today = now();
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = today.get_date_time();
  return date_time {year, month, day, 0, 0, 0, 0, today.kind_};
}

date_time date_time::utc_now() noexcept {
  return now().to_universal_time();
}

uint32 date_time::year() const noexcept {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return year;
}

date_time date_time::add(const time_span& value) const {
  return date_time {value_ + value.ticks_duration(), kind_};
}

date_time date_time::add_days(double days) const {
  return date_time {value_ + xtd::ticks(as<int64>(days * ticks_per_day)), kind_};
}

date_time date_time::add_hours(double hours) const {
  return date_time {value_ + xtd::ticks(as<int64>(hours * ticks_per_hour)), kind_};
}

date_time date_time::add_milliseconds(double milliseconds) const {
  return date_time {value_ + xtd::ticks(as<int64>(milliseconds * ticks_per_millisecond)), kind_};
}

date_time date_time::add_minutes(double minute) const {
  return date_time {value_ + xtd::ticks(as<int64>(minute * ticks_per_minute)), kind_};
}

date_time date_time::add_months(int32 months) const {
  if (months < -120000 || months > 120000) throw_helper::throws(exception_case::argument_out_of_range);
  
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  auto index = as<int32>(month - 1 + months);
  if (index >= 0) {
    month = as<uint32>(index % 12 + 1);
    year = year + as<uint32>(index / 12);
  } else {
    month = as<uint32>(12 + (index + 1) % 12);
    year = year + as<uint32>((index - 11) / 12);
  }
  if (year < 1u || year > 9999u) throw_helper::throws(exception_case::argument_out_of_range);
  auto days = as<uint32>(days_in_month(year, month));
  if (day > days) day = days;
  return date_time(year, month, day, hour, minute, second, kind_);
}

date_time date_time::add_seconds(double value) const {
  return date_time {value_ + xtd::ticks(as<int64>(value * ticks_per_second)), kind_};
}

date_time date_time::add_ticks(int64 value) const {
  return date_time {value_ + xtd::ticks(value), kind_};
}

date_time date_time::add_years(int32 value) const {
  return add_months(value * 12);
}

int32 date_time::compare_to(const date_time& value) const noexcept {
  if (value_.count() < value.value_.count()) return -1;
  if (value_.count() > value.value_.count()) return 1;
  return 0;
}

int32 date_time::days_in_month(uint32 year, month_of_year month) {
  return days_in_month(year, as<uint32>(month));
}

int32 date_time::days_in_month(uint32 year, uint32 month) {
  if (month < 1 || month > 12) throw_helper::throws(exception_case::argument_out_of_range);
  if (month == 2) return is_leap_year(year) ? 29 : 28;
  if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
  return 31;
}

bool date_time::equals(const object& obj) const noexcept {
  return is<date_time>(obj) && equals(static_cast<const date_time&>(obj));
}

bool date_time::equals(const date_time& other) const noexcept {
  return value_.count() == other.value_.count();
}

size date_time::get_hash_code() const noexcept {
  return hash_code::combine(value_.count(), kind_);
}

date_time date_time::from_binary(int64 date_data) {
  return date_time {date_data & 0x3FFFFFFFFFFFFFFFLL, as<date_time_kind>(as<int32>(((date_data & 0xC000000000000000LL) >> 62) & 0x0000000000000003LL))};
}

date_time date_time::from_duration(const time_span& value) {
  return from_duration(value, date_time_kind::unspecified);
}

date_time date_time::from_duration(const time_span& value, date_time_kind kind) {
  return date_time {value.ticks(), kind};
}

date_time date_time::from_file_time(int64 file_time) {
  return from_file_time_utc(file_time).to_local_time();
}

date_time date_time::from_file_time_utc(int64 file_time) {
  if (file_time < 0) throw_helper::throws(exception_case::argument_out_of_range);
  return date_time {xtd::ticks(file_time) + file_time_offset, date_time_kind::utc};
}

date_time date_time::from_time_t(std::time_t value) {
  return from_time_t(value, date_time_kind::unspecified);
}

date_time date_time::from_time_t(std::time_t value, date_time_kind kind) {
  return date_time::specify_kind(date_time(std::chrono::duration_cast<xtd::ticks>(std::chrono::seconds(value) + seconds_offset_1970), date_time_kind::utc), kind);
}

date_time date_time::from_tm(const tm& value) {
  return from_tm(value, date_time_kind::unspecified);
}

date_time date_time::from_tm(const tm& value, date_time_kind kind) {
  return date_time(value.tm_year + 1900, value.tm_mon + 1, value.tm_mday, value.tm_hour, value.tm_min, value.tm_sec, kind);
}

array<string> date_time::get_date_time_formats() const noexcept {
  auto date_time_formats = list<string> {};
  //for (auto format : formats)
  for (auto format = 'a'; format <= 'z'; ++format) {
    try {
      date_time_formats.add(self_.to_string(string::format("{}", format)));
    } catch (...) {
    }
    try {
      date_time_formats.add(self_.to_string(string::format("{}", char_object::to_upper(format))));
    } catch (...) {
    }
  }
  return date_time_formats.to_array();
}

bool date_time::is_daylight_saving_time() const noexcept {
  if (kind_ != date_time_kind::local) return false;
  return native::date_time::is_daylight((std::chrono::duration_cast<std::chrono::seconds>(value_) - seconds_offset_1970).count());
}

bool date_time::is_leap_year(uint32 year) {
  if (year < 1 || year > 9999) throw_helper::throws(exception_case::argument_out_of_range);
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

date_time date_time::parse(const xtd::string& s) {
  return parse(s, std::locale {});
}

date_time date_time::parse(const xtd::string& s, const std::locale& loc) {
  auto result = date_time {};
  if (!try_parse(s, result, loc)) throw_helper::throws(exception_case::format);
  return result;
}

date_time date_time::specify_kind(const date_time& value, date_time_kind kind) {
  if (kind == date_time_kind::local && value.kind_ != date_time_kind::local) return value.to_local_time();
  if (kind == date_time_kind::utc && value.kind_ != date_time_kind::utc) return value.to_universal_time();
  if (kind == date_time_kind::unspecified) return date_time(value.value_, date_time_kind::unspecified);
  return value;
}

string date_time::sprintf(const string& format, const date_time& value) {
  return sprintf(format, value, std::locale {});
}

string date_time::sprintf(const string& format, const date_time& value, const std::locale& loc) {
  auto result = std::stringstream {};
  result.imbue(loc);
  auto tm_value = value.to_tm();
  result << std::put_time(&tm_value, format.chars().c_str());
  return result.str();
}

time_span date_time::subtract(const date_time& value) const {
  return time_span {value_ - value.value_};
}

date_time date_time::subtract(const time_span& value) const {
  return date_time {value_ - value.ticks_duration()};
}

int64 date_time::to_binary() const {
  return (value_.count() & 0x3FFFFFFFFFFFFFFFLL) + ((as<int64>(kind_) << 62) & 0xC000000000000000LL);
}

int64 date_time::to_file_time() const {
  return to_universal_time().to_file_time_utc();
}

int64 date_time::to_file_time_utc() const {
  auto value = kind_ == date_time_kind::unspecified ? to_universal_time().value_ : value_;
  auto result = (value - file_time_offset).count();
  if (result < 0) throw_helper::throws(exception_case::argument_out_of_range);
  return result;
}

date_time date_time::to_local_time() const {
  if (kind_ == date_time_kind::local) return self_;
  
  auto utc_offset = this->utc_offset();
  if (value_ + utc_offset > max_value.value_) return date_time(value_, date_time_kind::local);
  
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return date_time {ticks_duration() + utc_offset, date_time_kind::local};
}

const xtd::string date_time::to_long_date_string() const {
  return to_string("D");
}

const xtd::string date_time::to_long_time_string() const {
  return to_string("T");
}

const xtd::string date_time::to_short_date_string() const {
  return to_string("d");
}

const xtd::string date_time::to_short_time_string() const {
  return to_string("t");
}

xtd::string date_time::to_string() const noexcept {
  return to_string("G");
}

string date_time::to_string(const string& format) const {
  return to_string(format, std::locale {});
}

string date_time::to_string(const string& format, const std::locale& loc) const {
  if (format.length() > 1) return to_string_custom(format, loc);
  if (xtd::string::is_empty(format)) return to_string_custom(custom_formats['G'], loc);
  
  if (!custom_formats.contains_key(format[0])) throw_helper::throws(exception_case::format, "Invalid format");
  return to_string_custom(custom_formats[format[0]], loc);
}

string date_time::to_string(const std::locale& loc) const {
  return to_string("", loc);
}

std::time_t date_time::to_time_t() const {
  return (std::chrono::duration_cast<std::chrono::seconds>(date_time::specify_kind(self_, date_time_kind::utc).value_) - seconds_offset_1970).count();
}

std::tm date_time::to_tm() const {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  std::tm result {};
  result.tm_sec = as<int32>(second);
  result.tm_min = as<int32>(minute);
  result.tm_hour = as<int32>(hour);
  result.tm_mday = as<int32>(day);
  result.tm_mon = as<int32>(month) - 1;
  result.tm_year = as<int32>(year) - 1900;
  result.tm_wday = day_of_week;
  result.tm_yday = as<int32>(day_of_year);
  result.tm_isdst = is_daylight_saving_time();
  return result;
}

date_time::operator time_span() const {
  return time_span(value_);
}

date_time date_time::to_universal_time() const {
  if (kind_ == date_time_kind::utc) return self_;
  
  auto utc_offset = this->utc_offset();
  if (value_ < utc_offset) return date_time(value_, date_time_kind::utc);
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return date_time {ticks_duration() - utc_offset, date_time_kind::utc};
}

bool date_time::try_parse(const string& s, date_time& result) noexcept {
  return try_parse(s, result, std::locale {});
}

bool date_time::try_parse(const string& s, date_time& result, const std::locale& loc) noexcept {
  return try_parse_exact(s, array<string> {"d", "D", "f", "F", "g", "G", "m", "M", "o", "O", "r", "R", "s", "t", "T", "u", "U", "y", "Y"}, result, loc);
}

bool date_time::try_parse_exact(const string& text, const string& format, date_time& result) noexcept {
  return try_parse_exact(text, format, result, std::locale {});
}

namespace {
  bool try_parse_exact_year(const string& text, const string& format, size& text_index, size& format_index, uint32& year) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 4_z);
    if (count == 1) ++count;
    if (count == 3) ++count;
    if (uint32_object::try_parse(text.substring(text_index, count), year) == false) return false;
    text_index += count;
    if (count <= 2) year +=  year < 30 ? 2000 : 1900;
    return true;
  }
  
  bool try_parse_exact_month(const string& text, const string& format, size& text_index, size& format_index, uint32& month, const std::locale& loc) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 4_z);
    if (count == 3 || count == 4) {
      auto months = count == 3 ? get_short_months(loc) : get_months(loc);
      for (auto index = 0_z; index < months.length(); ++index)
        if (text.substring(text_index).starts_with(months[index])) {
          month = as<int32>(index + 1);
          text_index += months[index].length();
          return true;
        }
      return false;
    }
    if (uint32_object::try_parse(text.substring(text_index, count), month) == false) return false;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_day(const string& text, const string& format, size& text_index, size& format_index, uint32& day, const std::locale& loc) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 4_z);
    if (count == 3 || count == 4) {
      auto days = count == 3 ? get_short_days(loc) : get_days(loc);
      for (auto index = 0_z; index < days.length(); ++index)
        if (text.substring(text_index).starts_with(days[index])) {
          //day = as<int32>(index + 1);
          text_index += days[index].length();
          return true;
        }
      return false;
    }
    auto parsed_day = 0_u32;
    if (uint32_object::try_parse(text.substring(text_index, count), parsed_day) == false) return false;
    if (parsed_day < 1 || parsed_day > 31) return false;
    day = parsed_day;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_hour_12(const string& text, const string& format, size& text_index, size& format_index, uint32& hour) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 2_z);
    auto parsed_hour = 0_u32;
    if (uint32_object::try_parse(text.substring(text_index, count), parsed_hour) == false) return false;
    if (parsed_hour > 12) return false;
    hour = parsed_hour;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_hour_24(const string& text, const string& format, size& text_index, size& format_index, uint32& hour) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 2_z);
    auto parsed_hour = 0_u32;
    if (uint32_object::try_parse(text.substring(text_index, count), parsed_hour) == false) return false;
    if (parsed_hour > 23) return false;
    hour = parsed_hour;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_minute(const string& text, const string& format, size& text_index, size& format_index, uint32& minute) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 2_z);
    auto parsed_minute = 0_u32;
    if (uint32_object::try_parse(text.substring(text_index, count), parsed_minute) == false) return false;
    if (parsed_minute > 59) return false;
    minute = parsed_minute;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_second(const string& text, const string& format, size& text_index, size& format_index, uint32& second) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 2_z);
    auto parsed_second = 0_u32;
    if (uint32_object::try_parse(text.substring(text_index, count), parsed_second) == false) return false;
    if (parsed_second > 59) return false;
    second = parsed_second;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_fraction(const string& text, const string& format, size& text_index, size& format_index, int64& fraction) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 7_z);
    auto parsed_fraction = 0_u64;
    if (uint64_object::try_parse(text.substring(text_index, count), parsed_fraction) == false) return false;
    fraction = parsed_fraction * static_cast<int64>(std::pow(10, 7 - count));
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_time_suffix(const string& text, const string& format, size& text_index, size& format_index, uint32& hour, const std::locale& loc) noexcept {
    auto count = to_string_custom_char_count(format, format_index, 2_z);
    auto suffix = text.substring(text_index, count);
    if (suffix == get_time_suffixes(loc)[0].substring(0, count)) {
      if (hour == 12) hour = 0;
    } else if (suffix == get_time_suffixes(loc)[1].substring(0, count)) {
      if (hour < 12) hour += 12;
    } else return false;
    text_index += count;
    return true;
  }
  
  bool try_parse_exact_offset_utc(const string& text, const string& format, size& text_index, size& format_index, int64& ticks) noexcept {
    if (text[text_index] == 'Z') {
      text_index++;
      return true;
    }
    
    auto negative = (text[text_index] == '-');
    if (text[text_index] != '+' && text[text_index] != '-') return false;
    ++text_index;
    auto offset_hour = 0_u32;
    if (uint32_object::try_parse(text.substring(text_index, 2), offset_hour) == false) return false;
    text_index += 2;
    auto offset_minute = 0_u32;
    if (text[text_index] == ':') {
      ++text_index;
      if (uint32_object::try_parse(text.substring(text_index, 2), offset_minute) == false) return false;
      text_index += 2;
    }
    auto offset_ticks = ((offset_hour * 60 + offset_minute) * 60ll * 10000000ll);
    if (negative) offset_ticks = -offset_ticks;
    ticks -= offset_ticks;
    return true;
  }
}

bool date_time::try_parse_exact(const string& text, const string& format, date_time& result, const std::locale& loc) noexcept {
  if (string::is_empty(text) || string::is_empty(format)) return false;
  auto fmt = (format.length() == 1_z && custom_formats.contains_key(format[0])) ? custom_formats[format[0]] : format;
  auto txt = text;
  auto valid = true;
  
  auto year = 1_u32, month = 1_u32, day = 1_u32, hour = 0_u32, minute = 0_u32, second = 0_u32;
  auto ticks = 0_s64;
  
  auto txt_index = 0_z;
  for (auto fmt_index = 0_z; valid && fmt_index < fmt.length(); ++fmt_index) {
    switch (fmt[fmt_index]) {
      case 'y': valid = try_parse_exact_year(txt, fmt, txt_index, fmt_index, year); break;
      case 'M': valid = try_parse_exact_month(txt, fmt, txt_index, fmt_index, month, loc); break;
      case 'd': valid = try_parse_exact_day(txt, fmt, txt_index, fmt_index, day, loc); break;
      case 'H': valid = try_parse_exact_hour_24(txt, fmt, txt_index, fmt_index, hour); break;
      case 'h': valid = try_parse_exact_hour_12(txt, fmt, txt_index, fmt_index, hour); break;
      case 'm': valid = try_parse_exact_minute(txt, fmt, txt_index, fmt_index, minute); break;
      case 's': valid = try_parse_exact_second(txt, fmt, txt_index, fmt_index, second); break;
      case 'f': valid = try_parse_exact_fraction(txt, fmt, txt_index, fmt_index, ticks); break;
      case 't': valid = try_parse_exact_time_suffix(txt, fmt, txt_index, fmt_index, hour, loc); break;
      case 'K': valid = try_parse_exact_offset_utc(txt, fmt, txt_index, fmt_index, ticks); break;
      default: valid = fmt[fmt_index] == text[txt_index++]; break;
    }
  }
  if (!valid) return false;
  result = {year, month, day, hour, minute, second};
  result = result.add_ticks(ticks);
  
  return true;
}

bool date_time::try_parse_exact(const string& text, const array<string>& formats, date_time& result) noexcept {
  return try_parse_exact(text, formats, result, std::locale {});
}

bool date_time::try_parse_exact(const string& text, const array<string>& formats, date_time& result, const std::locale& loc) noexcept {
  for (auto& format : formats)
    if (try_parse_exact(text, format, result, loc)) return true;
  return false;
}

date_time date_time::operator +=(const time_span& value) {
  return add(value);
}

time_span date_time::operator -=(const date_time& value) {
  return subtract(value);
}

time_span date_time::operator -=(const time_span& value) {
  return subtract(value);
}

date_time date_time::operator +() {
  return date_time(+value_, kind_);
}

date_time date_time::operator -() {
  return date_time(-value_, kind_);
}

date_time date_time::operator +(const time_span& value) const {
  auto result = self_;
  result.value_ += value.ticks_duration();
  return result;
}

time_span date_time::operator -(const date_time& value) const {
  return subtract(value);
}

date_time date_time::operator -(const time_span& value) const {
  auto result = self_;
  result.value_ -= value.ticks_duration();
  return result;
}

date_time& date_time::operator ++() {
  ++value_;
  return self_;
}

date_time date_time::operator ++(int32) {
  return date_time(value_++, kind_);
}

date_time& date_time::operator --() {
  --value_;
  return self_;
}

date_time date_time::operator --(int32) {
  return date_time {value_--, kind_};
}

std::tuple<uint32, uint32, uint32, uint32, uint32, uint32, uint32, int32> date_time::get_date_time() const {
  auto days = value_.count() / ticks_per_day;
  auto day_of_year = get_day_of_year(days);
  
  auto year = get_year(days);
  auto month = get_month(day_of_year, year);
  auto day = get_day(day_of_year, year);
  auto hour = static_cast<uint32>(value_.count() / ticks_per_hour % 24);
  auto minute = static_cast<uint32>(value_.count() / ticks_per_minute % 60);
  auto second = static_cast<uint32>(value_.count() / ticks_per_second % 60);
  auto day_of_week = (static_cast<int32>(value_.count() / ticks_per_day + 1) % 7);
  return std::make_tuple(year, month, day + 1, hour, minute, second, day_of_year + 1, day_of_week);
}

xtd::ticks date_time::utc_offset() const {
  return std::chrono::duration_cast<xtd::ticks>(std::chrono::seconds(native::date_time::utc_offset((std::chrono::duration_cast<std::chrono::seconds>(value_) - seconds_offset_1970).count())));
}

void date_time::set_date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, uint32 millisecond, date_time_kind kind) {
  [[maybe_unused]] auto [max_year, max_month, max_day, max_hour, max_minute, max_second, max_day_of_year, max_day_of_week] = max_value.get_date_time();
  [[maybe_unused]] auto [min_year, min_month, min_day, min_hour, min_minute, min_second, min_day_of_year, min_day_of_week] = min_value.get_date_time();
  
  if (year  < min_year ||
    (year == min_year && month  < min_month) ||
    (year == min_year && month == min_month && day  < min_day) ||
    (year == min_year && month == min_month && day == min_day && hour  < min_hour) ||
    (year == min_year && month == min_month && day == min_day && hour == min_hour && minute  < min_minute) ||
    (year == min_year && month == min_month && day == min_day && hour == min_hour && minute == min_minute && second < min_second))
    throw_helper::throws(exception_case::argument_out_of_range);
    
  if (year  > max_year ||
    (year == max_year && month  > max_month) ||
    (year == max_year && month == max_month && day  > max_day) ||
    (year == max_year && month == max_month && day == max_day && hour > max_hour) ||
    (year == max_year && month == max_month && day == max_day && hour == max_hour && minute > max_minute) ||
    (year == max_year && month == max_month && day == max_day && hour == max_hour && minute == max_minute && second > max_second))
    throw_helper::throws(exception_case::argument_out_of_range);
    
  auto days = as<int64>(day - 1);
  
  for (auto index = 1_u32; index < month; ++index)
    days += days_in_month(year, index);
    
  --year;
  days += (year * days_per_year) + (year / 4) - (year / 100) + (year / 400);
  value_ = xtd::ticks(days * ticks_per_day + hour * ticks_per_hour + minute * ticks_per_minute + second * ticks_per_second + millisecond * ticks_per_millisecond);
  kind_ = kind;
}

string date_time::to_string_custom(const string& format, const std::locale& loc) const {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  auto offset_sec = kind_ == date_time_kind::utc ? 0 : utc_offset().count() / ticks_per_second;
  
  string result;
  for (auto index = 0_z; index < format.length(); ++index) {
    if (format[index] == '\\') result += index + 1 < format.length() ? as<string>(format[++index]) : ""_s;
    else {
      switch (format[index]) {
        case 'd': result += to_string_custom_day(format, index, day, self_, loc); break;
        case 'f':
        case 'F': result += to_string_custom_fraction(format, index, ticks()); break;
        case 'h': result += to_string_custom_hour(format, index, hour % 12 == 0 && hour != 0 ? 12 : hour % 12); break;
        case 'H': result += to_string_custom_hour(format, index, hour); break;
        case 'K': result += to_string_custom_time_zone_information(format, index, kind_, offset_sec); break;
        case 'm': result += to_string_custom_minute(format, index, minute); break;
        case 'M': result += to_string_custom_month(format, index, month, self_, loc); break;
        case 's': result += to_string_custom_second(format, index, second); break;
        case 't': result += to_string_custom_time_suffix(format, index, hour, self_, loc); break;
        case 'y': result += to_string_custom_year(format, index, year); break;
        case 'z': result += to_string_custom_offset_utc(format, index, offset_sec); break;
        default: result += format[index]; break;
      }
    }
  }
  
  return result;
}

// These four following metheds are defined in include/xtd/internal/__date_time_formater.hpp file
std::string __date_time_formatter(std::string fmt, const std::tm& time, xtd::uint32 nanoseconds, const std::locale& loc) {
  return date_time_formatter(fmt, time, nanoseconds, loc);
}

std::wstring __date_time_formatter(std::wstring fmt, const std::tm& time, xtd::uint32 nanoseconds, const std::locale& loc) {
  return date_time_formatter(fmt, time, nanoseconds, loc).to_wstring();
}

std::string __date_time_formatter(const std::string& fmt, time_t time, xtd::uint32 nanoseconds, const std::locale& loc) {
  tm buf;
  return date_time_formatter(fmt, *to_tm(&time, &buf), nanoseconds, loc);
}

std::wstring __date_time_formatter(const std::wstring& fmt, time_t time, xtd::uint32 nanoseconds, const std::locale& loc) {
  tm buf;
  return date_time_formatter(fmt, *to_tm(&time, &buf), nanoseconds, loc).to_wstring();
}
