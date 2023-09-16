#include "../../include/xtd/time_span.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/divided_by_zero_exception.h"
#include "../../include/xtd/double_object.h"
#include "../../include/xtd/int32_object.h"
#include "../../include/xtd/int64_object.h"
#include "../../include/xtd/math.h"

using namespace xtd;

const time_span time_span::max_value {xtd::int64_object::max_value};
const time_span time_span::min_value {xtd::int64_object::min_value};
const time_span time_span::zero {0};

time_span::time_span() : ticks_(0) {
}

time_span::time_span(int64 ticks) : ticks_(ticks) {
}

time_span::time_span(xtd::ticks ticks) : ticks_(ticks.count()) {
}

time_span::time_span(int32 hours, int32 minutes, int32 seconds) : time_span(0, hours, minutes, seconds, 0, 0, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds) : time_span(days, hours, minutes, seconds, 0, 0, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds, int32 millisocnds) : time_span(days, hours, minutes, seconds, millisocnds, 0, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds, int32 millisocnds, int32 microseconds) : time_span(days, hours, minutes, seconds, millisocnds, microseconds, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds, int32 millisocnds, int32 microseconds, int32 nanoseconds) : ticks_(ticks_per_day * days + ticks_per_hour * hours + ticks_per_minute * minutes + ticks_per_second * seconds + ticks_per_millisecond * millisocnds + ticks_per_microsecond * microseconds + nanoseconds / nanoseconds_per_tick)  {
}

time_span::time_span(uint32 hours, uint32 minutes, uint32 seconds) : time_span(0u, hours, minutes, seconds, 0u, 0u, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds) : time_span(days, hours, minutes, seconds, 0u, 0u, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds, uint32 millisocnds) : time_span(days, hours, minutes, seconds, millisocnds, 0u, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds, uint32 millisocnds, uint32 microseconds) : time_span(days, hours, minutes, seconds, millisocnds, microseconds, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds, uint32 millisocnds, uint32 microseconds, uint32 nanoseconds) : ticks_(as<int32>(ticks_per_day * days + ticks_per_hour * hours + ticks_per_minute * minutes + ticks_per_second * seconds + ticks_per_millisecond * millisocnds + ticks_per_microsecond * microseconds + nanoseconds / nanoseconds_per_tick))  {
}

time_span& time_span::operator +=(const time_span& value) {
  ticks_ += value.ticks_;
  return *this;
}

time_span& time_span::operator -=(const time_span& value) {
  ticks_ -= value.ticks_;
  return *this;
}

time_span time_span::operator +(const time_span& value) {
  return add(value);
}

time_span time_span::operator -(const time_span& value) {
  return subtract(value);
}

double time_span::operator *(const time_span& value) {
  return multiply(value);
}

time_span time_span::operator *(double value) {
  return multiply(value);
}

double time_span::operator /(const time_span& value) {
  return divide(value);
}

time_span time_span::operator /(double value) {
  return divide(value);
}

time_span time_span::operator +() {
  return *this;
}

time_span time_span::operator -() {
  return negate();
}

time_span& time_span::operator ++() {
  ++ticks_;
  return *this;
}

time_span time_span::operator ++(int) {
  return time_span(ticks_++);
}

time_span& time_span::operator --() {
  --ticks_;
  return *this;
}

time_span time_span::operator --(int) {
  return time_span(ticks_--);
}

int32 time_span::days() const noexcept {
  return as<int32>(ticks_ / ticks_per_day);
}

int32 time_span::hours() const noexcept {
  return as<int32>(ticks_ % ticks_per_day / ticks_per_hour);
}

int32 time_span::microseconds() const noexcept {
  return as<int32>(ticks_ % ticks_per_day % ticks_per_hour % ticks_per_minute % ticks_per_second % ticks_per_millisecond / ticks_per_microsecond);
}

int32 time_span::milliseconds() const noexcept {
  return as<int32>(ticks_ % ticks_per_day % ticks_per_hour % ticks_per_minute % ticks_per_second / ticks_per_millisecond);
}

int32 time_span::minutes() const noexcept {
  return as<int32>(ticks_ % ticks_per_day % ticks_per_hour / ticks_per_minute);
}

int32 time_span::nanoseconds() const noexcept {
  return as<int32>(ticks_ % ticks_per_day % ticks_per_hour % ticks_per_minute % ticks_per_second % ticks_per_millisecond % ticks_per_microsecond * nanoseconds_per_tick);
}

int32 time_span::seconds() const noexcept {
  return as<int32>(ticks_ % ticks_per_day % ticks_per_hour % ticks_per_minute / ticks_per_second);
}

int64 time_span::ticks() const noexcept {
  return ticks_;
}

xtd::ticks time_span::ticks_duration() const noexcept {
  return xtd::ticks {ticks_};
}

double time_span::total_days() const noexcept {
  return as<double>(ticks_) / ticks_per_day;
}

std::chrono::days time_span::total_days_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::days>(ticks_duration());
}

double time_span::total_hours() const noexcept {
  return as<double>(ticks_) / ticks_per_hour;
}

std::chrono::hours time_span::total_hours_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::hours>(ticks_duration());
}

double time_span::total_microseconds() const noexcept {
  return as<double>(ticks_) / ticks_per_microsecond;
}

std::chrono::microseconds time_span::total_microseconds_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::microseconds>(ticks_duration());
}

double time_span::total_milliseconds() const noexcept {
  return as<double>(ticks_) / ticks_per_millisecond;
}

std::chrono::milliseconds time_span::total_milliseconds_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::milliseconds>(ticks_duration());
}

double time_span::total_minutes() const noexcept {
  return as<double>(ticks_) / ticks_per_minute;
}

std::chrono::minutes time_span::total_minutes_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::minutes>(ticks_duration());
}

double time_span::total_nanoseconds() const noexcept {
  return as<double>(ticks_) * nanoseconds_per_tick;
}

std::chrono::nanoseconds time_span::total_nanoseconds_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(ticks_duration());
}

double time_span::total_seconds() const noexcept {
  return as<double>(ticks_) / ticks_per_second;
}

std::chrono::seconds time_span::total_seconds_duration() const noexcept {
  return std::chrono::duration_cast<std::chrono::seconds>(ticks_duration());
}

time_span time_span::add(const time_span& ts) const noexcept {
  return time_span {ticks_ + ts.ticks_};
}

int32 time_span::compare_to(const time_span& value) const noexcept {
  return ticks_ < value.ticks_ ? -1 : ticks_ > value.ticks_ ? 1 : 0;
}

double time_span::divide(const time_span& ts) const {
  if (ts.ticks_ == 0) throw divided_by_zero_exception {csf_};
  return as<double>(ticks_) / ts.ticks_;
}

time_span time_span::divide(double divisor) const {
  if (divisor == 0) throw divided_by_zero_exception {csf_};
  return time_span {static_cast<int64>(ticks_ / divisor)};
}

time_span time_span::duration() const noexcept {
  return time_span {math::abs(ticks_)};
}

bool time_span::equals(const time_span& value) const noexcept {
  return ticks_ == value.ticks_;
}

bool time_span::equals(time_span t1, time_span t2) {
  return  t1.equals(t2);
}

time_span time_span::from_days(double value) {
  return interval(value, millis_per_day);
}

time_span time_span::from_days(std::chrono::days value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_hours(double value) {
  return interval(value, millis_per_hour);
}

time_span time_span::from_hours(std::chrono::hours value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_microseconds(double value) {
  if (double_object::is_NaN(value)) throw argument_exception {csf_};
  if (double_object::is_infinity(value) || value < as<double>(time_span::min_value.ticks() / ticks_per_microsecond) || value > as<double>(time_span::max_value.ticks() / ticks_per_microsecond)) throw overflow_exception {csf_};
  return from_ticks(static_cast<int64>(value * ticks_per_microsecond));
}

time_span time_span::from_microseconds(std::chrono::microseconds value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_milliseconds(double value) {
  return interval(value, 1);
}

time_span time_span::from_milliseconds(std::chrono::milliseconds value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_minutes(double value) {
  return interval(value, millis_per_minute);
}

time_span time_span::from_minutes(std::chrono::minutes value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_nanoseconds(double value) {
  if (double_object::is_NaN(value)) throw argument_exception {csf_};
  return from_ticks(static_cast<int64>(value / nanoseconds_per_tick));
}

time_span time_span::from_nanoseconds(std::chrono::nanoseconds value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_seconds(double value) {
  return interval(value, millis_per_second);
}

time_span time_span::from_seconds(std::chrono::seconds value) {
  return from_ticks(std::chrono::duration_cast<xtd::ticks>(value));
}

time_span time_span::from_ticks(int64 ticks) {
  return time_span {ticks};
}

time_span time_span::from_ticks(xtd::ticks ticks) {
  return time_span {ticks};
}

double time_span::multiply(const time_span& ts) const noexcept {
  return as<double>(ticks_) * ts.ticks_;
}

time_span time_span::multiply(double factor) const noexcept {
  return time_span {static_cast<int64>(ticks_ * factor)};
}

time_span time_span::negate() const {
  if (*this == time_span::min_value) throw overflow_exception {csf_};
  return time_span {-ticks_};
}

time_span time_span::parse(const ustring& value) {
  auto result = time_span {};
  switch (try_parse_internal(value, result)) {
    case parse_format: throw format_exception {csf_};
    case parse_overflow: throw overflow_exception {csf_};
  }
  return result;
}

time_span time_span::subtract(const time_span& ts) const noexcept {
  return time_span {ticks_ - ts.ticks_};
}

xtd::ustring time_span::to_string() const noexcept {
  return to_string("G");
}

ustring time_span::to_string(const ustring& format) const {
  auto fmt = format;
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) throw format_exception("Invalid format"_t, csf_);
  
  switch (fmt[0]) {
    case 'c': return make_string_from_duration(true);
    case 'd': return ustring::format("{}", math::abs(days()));
    case 'D': return ustring::format("{:d2}", math::abs(days()));
    case 'f': return ustring::format("{}{}.{}:{:d2}:{:d2}.{:d7}", ticks() < 0 ? "-" : "", math::abs(days()), math::abs(hours()), math::abs(minutes()), math::abs(seconds()), math::abs(ticks() % ticks_per_second));
    case 'F': return ustring::format("{}{}.{:d2}:{:d2}:{:d2}.{:d7}", ticks() < 0 ? "-" : "", math::abs(days()), math::abs(hours()), math::abs(minutes()), math::abs(seconds()), math::abs(ticks() % ticks_per_second));
    case 'g': return make_string_from_duration(false);
    case 'G': return make_string_from_duration(true);
    case 'h': return ustring::format("{}", math::abs(hours()));
    case 'H': return ustring::format("{:d2}", math::abs(hours()));
    case 'l': return ustring::format("{}", math::abs(milliseconds()));
    case 'L': return ustring::format("{:d3}", math::abs(milliseconds()));
    case 'm': return ustring::format("{}", math::abs(minutes()));
    case 'M': return ustring::format("{:d2}", math::abs(minutes()));
    case 'o': return ustring::format("{}", ticks() < 0 ? "-" : "");
    case 'O': return ustring::format("{}", ticks() < 0 ? "-" : "+");
    case 's': return ustring::format("{}", math::abs(seconds()));
    case 'S': return ustring::format("{:d2}", math::abs(seconds()));
    case 't': return ustring::format("{0:d}", math::abs(ticks() % ticks_per_second));
    case 'T': return ustring::format("{:d7}", math::abs(ticks() % ticks_per_second));
    default: throw xtd::format_exception("Invalid format");
  }
}

bool time_span::try_parse(const ustring& value, time_span& result) {
  return try_parse_internal(value, result) == 0;
}

time_span time_span::interval(double value, int scale) {
  if (double_object::is_NaN(value)) throw argument_exception {csf_};
  auto tmp = value * scale;
  auto millis = tmp + (value >= 0 ? 0.5 : -0.5);
  if ((millis > int64_object::max_value / ticks_per_millisecond) || (millis < int64_object::min_value / ticks_per_millisecond))  throw overflow_exception {csf_};
  return time_span(static_cast<int64>(millis) * ticks_per_millisecond);
}

ustring time_span::make_string_from_duration(bool constant) const {
  auto result = ustring::empty_string;
  if (ticks() < 0) result += '-';
  if (days()) result += ustring::format("{}.", math::abs(days()));
  result += ustring::format(constant ? "{:d2}:{:d2}:{:d2}" : "{:d}:{:d2}:{:d2}", math::abs(hours()), math::abs(minutes()), math::abs(seconds()));
  if (ticks() % ticks_per_second) result += ustring::format(".{:d7}", math::abs(ticks() % ticks_per_second));
  return result;
}

int32 time_span::try_parse_internal(const ustring& value, time_span& result) {
  result = time_span::zero;

  if (value.empty()) return parse_format;

  auto days = 0, hours = 0, minutes = 0, seconds = 0, ticks = 0;
  auto items = value.split({'-', ':', '.', '\0'}, string_split_options::remove_empty_entries);
  
  if (items.size() == 1ul) {
    if (int32_object::try_parse(items[0], days) == false) return parse_format;
  }
  
  if (items.size() == 2ul) {
    if (int32_object::try_parse(items[0], hours) == false) return parse_format;
    if (int32_object::try_parse(items[1], minutes) == false) return parse_format;
  }
  
  if (items.size() == 3ul) {
    if (int32_object::try_parse(items[0], hours) == false) return parse_format;
    if (int32_object::try_parse(items[1], minutes) == false) return parse_format;
    if (int32_object::try_parse(items[2], seconds) == false) return parse_format;
  }
  
  if (items.size() == 4ul) {
    if (int32_object::try_parse(items[0], days) == false) return parse_format;
    if (int32_object::try_parse(items[1], hours) == false) return parse_format;
    if (int32_object::try_parse(items[2], minutes) == false) return parse_format;
    if (int32_object::try_parse(items[3], seconds) == false) return false;
  }
  
  if (items.size() == 5ul) {
    if (items[4].size() != 7) return parse_format;
    
    if (int32_object::try_parse(items[0], days) == false) return parse_format;
    if (int32_object::try_parse(items[1], hours) == false) return parse_format;
    if (int32_object::try_parse(items[2], minutes) == false) return parse_format;
    if (int32_object::try_parse(items[3], seconds) == false) return parse_format;
    if (int32_object::try_parse(items[4], ticks) == false) return parse_format;
  }
  
  if (items.size() > 5ul) return parse_format;
  if (value.last_index_of('-') != ustring::npos && value.last_index_of('-') != 0ul) return parse_format;
  if (items.size() == 5ul && value.last_index_of(':') > value.last_index_of('.')) return parse_format;
  
  if (0 > hours || hours > 24) return parse_overflow;
  if (0 > minutes || minutes > 60) return parse_overflow;
  if (0 > seconds || seconds > 60) return parse_overflow;
  
  result = time_span {days * ticks_per_day + hours * ticks_per_hour + minutes * ticks_per_minute + seconds * ticks_per_second + ticks};
  if (value[0] == '-') result = result.negate();
  return parse_succeed;
}
