#include "../include/xtd/argument_out_of_range_exception.h"
#include "../include/xtd/as.h"
#include "../include/xtd/char_object.h"
#include "../include/xtd/format_exception.h"
#include "../include/xtd/invalid_operation_exception.h"
#include "../include/xtd/date_time.h"
#include "../include/xtd/math.h"
#include "../include/xtd/not_implemented_exception.h"
#include "../include/xtd/time_zone_info.h"
#include "../include/xtd/unused.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <tuple>

using namespace std;
using namespace std::chrono;
using namespace xtd;

namespace {
  // Number of ticks per time unit
  const int64 ticks_per_millisecond = 10000;
  const int64 ticks_per_second = ticks_per_millisecond * 1000;
  const int64 ticks_per_minute = ticks_per_second * 60;
  const int64 ticks_per_hour = ticks_per_minute * 60;
  const int64 ticks_per_day = ticks_per_hour * 24;
  
  // Number of seconds per time unit
  const int64 seconds_per_minute = 60;
  const int64 seconds_per_our = seconds_per_minute * 60;
  const int64 seconds_per_day = seconds_per_our * 24;
  
  // Number of days in a non-leap year
  const int64 days_per_year = 365;
  // Number of days in 4 years
  const int64 days_per_4_years = days_per_year * 4 + 1; // 1461
  // Number of days in 100 years
  const int64 days_per_100_years = days_per_4_years * 25 - 1; // 36524
  // Number of days in 400 years
  const int64 days_per_400_years = days_per_100_years * 4 + 1; // 146097
  
  // Number of days from 1/1/0001 to 12/31/1600
  const int64 days_to_1601 = days_per_400_years * 4; // 584388
  // Number of days from 1/1/0001 to 12/31/1969
  const int64 days_to_1970 = days_per_400_years * 4 + days_per_100_years * 3 + days_per_4_years * 17 + days_per_year; // 719,162
  // Number of days from 1/1/0001 to 12/31/9999
  const int64 days_to_10000 = days_per_400_years * 25 - 366; // 3652059
  
  const ticks min_ticks = ticks(0);
  const ticks max_ticks = ticks(days_to_10000 * ticks_per_day - 1);
  
  const ticks file_time_offset = ticks(days_to_1601* ticks_per_day);
  
  constexpr seconds seconds_offset_1970 = seconds(seconds_per_day* days_to_1970);
  
  static tuple<uint32, uint32> get_year_and_day_of_year(int64 days) {
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
    
    return make_tuple(as<uint32>(year), as<uint32>(day_of_year));
  }
  
  static uint32 get_year(int64 days) {
    auto [year, day_of_year] = get_year_and_day_of_year(days);
    return year;
  }
  
  static uint32 get_day_of_year(int64 days) {
    auto [year, day_of_year] = get_year_and_day_of_year(days);
    return day_of_year;
  }
  
  static tuple<uint32, uint32> get_month_and_day(int64 day_of_year, uint32 year) {
    auto month = 1_u32;
    auto day = day_of_year;
    for (auto days_in_month = as<int64>(date_time::days_in_month(year, month)); day >= days_in_month; days_in_month = date_time::days_in_month(year, month)) {
      ++month;
      day -= days_in_month;
    }
    return make_tuple(month, as<uint32>(day));
  }

  static uint32 get_month(int64 day_of_year, uint32 year) {
    auto [month, day] = get_month_and_day(day_of_year, year);
    return month;
  }
  
  static uint32 get_day(int64 day_of_year, uint32 year) {
    auto [month, day] = get_month_and_day(day_of_year, year);
    return day;
  }
}

const date_time date_time::max_value {max_ticks};
const date_time date_time::min_value {min_ticks};

date_time::date_time(int64 ticks) : value_(ticks) {
  if (ticks < min_value.value_.count() || ticks > max_value.value_.count()) throw argument_out_of_range_exception {csf_};
}

date_time::date_time(xtd::ticks ticks) : value_(ticks) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw argument_out_of_range_exception {csf_};
}

date_time::date_time(int64 ticks, xtd::date_time_kind kind) : value_(ticks), kind_(kind) {
  if (ticks < min_value.value_.count() || ticks > max_value.value_.count()) throw argument_out_of_range_exception {csf_};
}

date_time::date_time(xtd::ticks ticks, xtd::date_time_kind kind) : value_(ticks), kind_(kind) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw argument_out_of_range_exception {csf_};
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
  return duration_cast<milliseconds>(value_).count() % 1000;
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
  system_clock::time_point now = system_clock::now();
  auto now_ticks = duration_cast<xtd::ticks>(now.time_since_epoch()) % ticks_per_second;
  return from_time_t(system_clock::to_time_t(now), date_time_kind::local).add(now_ticks);
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
  if (months < -120000 || months > 120000) throw argument_out_of_range_exception {csf_};
  
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  auto i = as<int32>(month - 1 + months);
  if (i >= 0) {
    month = as<uint32>(i % 12 + 1);
    year = year + as<uint32>(i / 12);
  } else {
    month = as<uint32>(12 + (i + 1) % 12);
    year = year + as<uint32>((i - 11) / 12);
  }
  if (year < 1u || year > 9999u) throw argument_out_of_range_exception {csf_};
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
  if (month < 1 || month > 12) throw argument_out_of_range_exception {csf_};
  if (month == 2) return is_leap_year(year) ? 29 : 28;
  if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
  return 31;
}

bool date_time::equals(const date_time& other) const noexcept {
  return value_.count() == other.value_.count();
}

date_time date_time::from_binary(int64 date_data) {
  return date_time {xtd::ticks(date_data & 0x3FFFFFFFFFFFFFFFLL), as<date_time_kind>(as<int32>(((date_data & 0xC000000000000000LL) >> 62) & 0x0000000000000003LL))};
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
  if (file_time < 0) throw argument_out_of_range_exception {csf_};
  return date_time {xtd::ticks(file_time) + file_time_offset, date_time_kind::utc};
}

date_time date_time::from_time_t(std::time_t value) {
  return from_time_t(value, date_time_kind::unspecified);
}

date_time date_time::from_time_t(std::time_t value, date_time_kind kind) {
  return date_time::specify_kind(date_time(duration_cast<xtd::ticks>(seconds(value) + seconds_offset_1970), date_time_kind::utc), kind);
}

date_time date_time::from_tm(const tm& value) {
  return from_tm(value, date_time_kind::unspecified);
}

date_time date_time::from_tm(const tm& value, date_time_kind kind) {
  return date_time(value.tm_year + 1900, value.tm_mon + 1, value.tm_mday, value.tm_hour, value.tm_min, value.tm_sec, kind);
}

vector<ustring> date_time::get_date_time_formats() const noexcept {
  auto date_time_formats = vector<ustring> {};
  //for (auto format : formats)
  for (auto format = 'a'; format <= 'z'; ++format) {
    try {
      date_time_formats.emplace_back(self_.to_string(ustring::format("{}", format)));
    } catch(...) {
    }
    try {
      date_time_formats.emplace_back(self_.to_string(ustring::format("{}", char_object::to_upper(format))));
    } catch(...) {
    }
  }
  return date_time_formats;
}

bool date_time::is_daylight_saving_time() const noexcept {
  if (kind_ != date_time_kind::local) return false;
  return native::date_time::is_daylight((duration_cast<seconds>(value_) - seconds_offset_1970).count());
}

bool date_time::is_leap_year(uint32 year) {
  if (year < 1 || year > 9999) throw argument_out_of_range_exception {csf_};
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

date_time date_time::parse(const xtd::ustring& s) {
  throw not_implemented_exception {csf_};
}

date_time date_time::specify_kind(const date_time& value, date_time_kind kind) {
  if (kind == date_time_kind::local && value.kind_ != date_time_kind::local) return value.to_local_time();
  if (kind == date_time_kind::utc && value.kind_ != date_time_kind::utc) return value.to_universal_time();
  if (kind == date_time_kind::unspecified) return date_time(value.value_, date_time_kind::unspecified);
  return value;
}

ustring date_time::sprintf(const ustring& format, const date_time& value) {
  auto result = std::stringstream {};
  result.imbue(locale());
  auto tm_value = value.to_tm();
  result << std::put_time(&tm_value, format.c_str());
  return result.str();
}

time_span date_time::subtract(const date_time& value) const {
  return time_span {value_ - value.value_};
}

date_time date_time::subtract(const time_span& value) const {
  return date_time {value_ - value.ticks_duration()};
}

int64 date_time::to_binary() const {
  return (duration_cast<seconds>(value_).count() & 0x3FFFFFFFFFFFFFFFLL) + ((as<int64>(kind_) << 62) & 0xC000000000000000LL);
}

int64 date_time::to_file_time() const {
  return to_universal_time().to_file_time_utc();
}

int64 date_time::to_file_time_utc() const {
  auto value = kind_ == date_time_kind::unspecified ? to_universal_time().value_ : value_;
  auto result = (value - file_time_offset).count();
  if (result < 0) throw argument_out_of_range_exception {csf_};
  return result;
}

date_time date_time::to_local_time() const {
  if (kind_ == date_time_kind::local) return *this;
  
  auto utc_offset = this->utc_offset();
  if (value_ + utc_offset > max_value.value_) return date_time(value_, date_time_kind::local);
  
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return date_time {ticks_duration() + utc_offset, date_time_kind::local};
}

const xtd::ustring date_time::to_long_date_string() const {
  return to_string("n");
}

const xtd::ustring date_time::to_long_time_string() const {
  return to_string("T");
}

const xtd::ustring date_time::to_short_date_string() const {
  return to_string("D");
}

const xtd::ustring date_time::to_short_time_string() const {
  return to_string("V");
}

xtd::ustring date_time::to_string() const noexcept {
  return to_string("G");
}

ustring date_time::to_string(const ustring& format) const {
  auto fmt = format;
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) throw format_exception("Invalid format"_t, csf_);
  
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  switch (fmt[0]) {
    case 'a': return ustring::format("{}", hour / 12 ? "PM" : "AM");
    case 'b': return ustring::format("{:D3}", millisecond());
    case 'B': return ustring::format("{}", millisecond());
    case 'c': return ustring::format("{:D7}", ticks() % ticks_per_millisecond);
    case 'C': return ustring::format("{}", ticks() % ticks_per_millisecond);
    case 'd': return ustring::format("{:D2}/{:D2}/{:D}", month, day, year);
    case 'D': return ustring::format("{:D}/{:D2}/{:D}", month, day, year);
    case 'e': return ustring::format("{:D2}", second);
    case 'E': return ustring::format("{}", second);
    case 'f': return sprintf("%Ec", *this);
    case 'F': return sprintf("%c", *this);
    case 'g': return sprintf("%Ec", *this);
    case 'G': return sprintf("%c", *this);
    case 'h': return sprintf("%a", *this);
    case 'H': return sprintf("%A", *this);
    case 'i': return ustring::format("{:D2}", day);
    case 'I': return ustring::format("{:D}", day);
    case 'j': return sprintf("%b", *this);
    case 'J': return sprintf("%B", *this);
    case 'k': return ustring::format("{:D2}", month);
    case 'K': return ustring::format("{:D}", month);
    case 'l': return ustring::format("{:D2}", year % 100);
    case 'L': return ustring::format("{:D4}", year);
    case 'm': return ustring::format("{:D}", year);
    case 'M': return ustring::format("{} {:D}", sprintf("%B", *this), day);
    case 'n': return ustring::format("{}, {:D} {} {:D}", sprintf("%A", *this), day, sprintf("%B", *this), year);
    case 'N': return ustring::format("{}, {:D} {} {:D} {:D}:{:D2}:{:D2}", sprintf("%A", *this), day, sprintf("%B", *this), year, hour, minute, second);
    case 'o':
    case 'O': return ustring::format("{:D} {} {:D}", day, sprintf("%B", *this), year);
    case 'p': return ustring::format("{:D2}", minute);
    case 'P': return ustring::format("{}", minute);
    case 's': return ustring::format("{:D4}-{:D2}-{:D2}T{:D2}:{:D2}:{:D2}.{:D7}", year, month, day, hour, minute, second, value_.count() % ticks_per_second);
    case 'S': return ustring::format("{:D4}-{:D2}-{:D2}T{:D2}:{:D2}:{:D2}.{:D3}", year, month, day, hour, minute, second, value_.count() % ticks_per_second / 10000);
    case 't': return ustring::format("{:D2}:{:D2}:{:D2}", hour, minute, second);
    case 'T': return ustring::format("{:D}:{:D2}:{:D2}", hour, minute, second);
    case 'u': return ustring::format("{:D}-{:D2}-{:D2} {:D2}:{:D2}:{:D2}", year, month, day, hour, minute, second);
    case 'U': return ustring::format("{}, {:D} {} {:D} {:D}:{:D2}:{:D2}", sprintf("%A", *this), day, sprintf("%B", *this), year, hour, minute, second);
    case 'v': return ustring::format("{:D2}:{:D2}", hour, minute);
    case 'V': return ustring::format("{:D}:{:D2}", hour, minute);
    case 'w': return ustring::format("{:D2}", hour);
    case 'W': return ustring::format("{:D}", hour);
    case 'x': return ustring::format("{:D2}", hour % 12);
    case 'X': return ustring::format("{:D}", hour % 12);
    case 'y': return ustring::format("{} {:D}", sprintf("%B", *this), year % 100);
    case 'Y': return ustring::format("{} {:D}", sprintf("%B", *this), year);
    case 'z':
    case 'Z': return kind_ == date_time_kind::local ? time_zone_info::local().id().c_str() : time_zone_info::utc().id().c_str();
  }
  throw format_exception {"Invalid format"_t, csf_};
}

std::time_t date_time::to_time_t() const {
  return (duration_cast<seconds>(date_time::specify_kind(*this, date_time_kind::utc).value_) - seconds_offset_1970).count();
}

std::tm date_time::to_tm() const {
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  std::tm result {};
  result.tm_sec = as<int32>(second);
  result.tm_min = as<int32>(minute);
  result.tm_hour = as<int32>(hour);
  result.tm_mday = as<int32>(day);
  result.tm_mon = as<int32>(month - 1);
  result.tm_year = as<int32>(year - 1900);
  result.tm_wday = day_of_week;
  result.tm_yday = as<int32>(day_of_year);
  result.tm_isdst = is_daylight_saving_time();
  return result;
}

date_time::operator time_span() const {
  return time_span(value_);
}

date_time date_time::to_universal_time() const {
  if (kind_ == date_time_kind::utc) return *this;
  
  auto utc_offset = this->utc_offset();
  if (value_ < utc_offset) return date_time(value_, date_time_kind::utc);
  [[maybe_unused]] auto [year, month, day, hour, minute, second, day_of_year, day_of_week] = get_date_time();
  return date_time {ticks_duration() - utc_offset, date_time_kind::utc};
}

bool date_time::try_parse(const ustring& s, date_time& result) noexcept {
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
  auto result = *this;
  result.value_ += value.ticks_duration();
  return result;
}

time_span date_time::operator -(const date_time& value) const {
  return subtract(value);
}

date_time date_time::operator -(const time_span& value) const {
  auto result = *this;
  result.value_ -= value.ticks_duration();
  return result;
}

date_time& date_time::operator ++() {
  ++value_;
  return *this;
}

date_time date_time::operator ++(int32) {
  return date_time(value_++, kind_);
}

date_time& date_time::operator --() {
  --value_;
  return *this;
}

date_time date_time::operator --(int32) {
  return date_time {value_--, kind_};
}

tuple<uint32, uint32, uint32, uint32, uint32, uint32, uint32, int32> date_time::get_date_time() const {
  auto days = value_.count() / ticks_per_day;
  auto day_of_year = get_day_of_year(days);
  
  auto year = get_year(days);
  auto month = get_month(day_of_year, year);
  auto day = get_day(day_of_year, year);
  auto hour = static_cast<uint32>(value_.count() / ticks_per_hour % 24);
  auto minute = static_cast<uint32>(value_.count() / ticks_per_minute % 60);
  auto second = static_cast<uint32>(value_.count() / ticks_per_second % 60);
  auto day_of_week = (static_cast<int32>(value_.count() / ticks_per_day + 1) % 7);
  return make_tuple(year, month, day + 1, hour, minute, second, day_of_year + 1, day_of_week);
}

xtd::ticks date_time::utc_offset() const {
  return duration_cast<xtd::ticks>(seconds(native::date_time::utc_offset((duration_cast<seconds>(value_) - seconds_offset_1970).count())));
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
    throw argument_out_of_range_exception {csf_};
    
  if (year  > max_year ||
    (year == max_year && month  > max_month) ||
    (year == max_year && month == max_month && day  > max_day) ||
    (year == max_year && month == max_month && day == max_day && hour > max_hour) ||
    (year == max_year && month == max_month && day == max_day && hour == max_hour && minute > max_minute) ||
    (year == max_year && month == max_month && day == max_day && hour == max_hour && minute == max_minute && second > max_second))
    throw argument_out_of_range_exception {csf_};
    
  auto days = as<int64>(day - 1);
  
  for (auto index = 1_u32; index < month; ++index)
    days += days_in_month(year, index);
    
  --year;
  days += (year * days_per_year) + (year / 4) - (year / 100) + (year / 400);
  value_ = xtd::ticks(days * ticks_per_day + hour * ticks_per_hour + minute * ticks_per_minute + second * ticks_per_second + millisecond * ticks_per_millisecond);
  kind_ = kind;
}
