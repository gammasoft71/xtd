//#define __XTD_CORE_INTERNAL__
//#include "../../include/xtd/internal/__duration_formatter.h"
//#undef __XTD_CORE_INTERNAL__
#include "../../include/xtd/time_span.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/int64_object.h"
#include "../../include/xtd/math.h"

using namespace xtd;

const time_span time_span::max_value {xtd::int64_object::max_value};
const time_span time_span::min_value {xtd::int64_object::min_value};
const time_span time_span::zero {0};

time_span::time_span() : value_(0) {
}

time_span::time_span(int64 ticks) : value_(ticks) {
}

time_span::time_span(xtd::ticks ticks) : value_(ticks.count()) {
}

time_span::time_span(int32 hours, int32 minutes, int32 seconds) : time_span(0, hours, minutes, seconds, 0, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds) : time_span(days, hours, minutes, seconds, 0, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds, int32 millisocnds) : time_span(days, hours, minutes, seconds, millisocnds, 0)  {
}

time_span::time_span(int32 days, int32 hours, int32 minutes, int32 seconds, int32 millisocnds, int32) : value_(ticks_per_day * days + ticks_per_hour * hours + ticks_per_minute * minutes + ticks_per_second * seconds + ticks_per_microsecond * millisocnds + ticks_per_microsecond * ticks_per_microsecond)  {
}

time_span::time_span(uint32 hours, uint32 minutes, uint32 seconds) : time_span(0u, hours, minutes, seconds, 0u, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds) : time_span(days, hours, minutes, seconds, 0u, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds, uint32 millisocnds) : time_span(days, hours, minutes, seconds, millisocnds, 0u)  {
}

time_span::time_span(uint32 days, uint32 hours, uint32 minutes, uint32 seconds, uint32 millisocnds, uint32) : value_(ticks_per_day * days + ticks_per_hour * hours + ticks_per_minute * minutes + ticks_per_second * seconds + ticks_per_microsecond * millisocnds + ticks_per_microsecond * ticks_per_microsecond)  {
}

time_span& time_span::operator +=(const time_span& value) {
  value_ += value.value_;
  return *this;
}

time_span& time_span::operator -=(const time_span& value) {
  value_ -= value.value_;
  return *this;
}

time_span time_span::operator +(const time_span& value) {
  time_span result = *this;
  result += value;
  return result;
}

time_span time_span::operator -(const time_span& value) {
  time_span result = *this;
  result -= value;
  return result;
}

time_span& time_span::operator ++() {
  ++value_;
  return *this;
}

time_span time_span::operator ++(int) {
  return time_span(value_++);
}

time_span& time_span::operator --() {
  --value_;
  return *this;
}

time_span time_span::operator --(int) {
  return time_span(value_--);
}

int32 time_span::days() const noexcept {
  return as<int32>(value_ / ticks_per_day);
}

int32 time_span::hours() const noexcept {
  return as<int32>(value_ % ticks_per_day / ticks_per_hour);
}

int32 time_span::microseconds() const noexcept{
  return as<int32>(value_ % ticks_per_day % ticks_per_hour % ticks_per_minute % ticks_per_second % ticks_per_milliecond / ticks_per_microsecond);
}

int32 time_span::milliseconds() const noexcept {
  return as<int32>(value_ % ticks_per_day % ticks_per_hour % ticks_per_minute % ticks_per_second / ticks_per_milliecond);
}

int32 time_span::minutes() const noexcept {
  return as<int32>(value_ % ticks_per_day % ticks_per_hour / ticks_per_minute);
}

int32 time_span::seconds() const noexcept {
  return as<int32>(value_ % ticks_per_day % ticks_per_hour % ticks_per_minute / ticks_per_second);
}

xtd::ticks time_span::ticks() const noexcept {
  return xtd::ticks {value_};
}

std::chrono::days time_span::total_days() const noexcept {
  return std::chrono::duration_cast<std::chrono::days>(ticks());
}

std::chrono::hours time_span::total_hours() const noexcept {
  return std::chrono::duration_cast<std::chrono::hours>(ticks());
}

std::chrono::microseconds time_span::total_microseconds() const noexcept {
  return std::chrono::duration_cast<std::chrono::microseconds>(ticks());
}

std::chrono::milliseconds time_span::total_milliseconds() const noexcept {
  return std::chrono::duration_cast<std::chrono::milliseconds>(ticks());
}

std::chrono::minutes time_span::total_minutes() const noexcept {
  return std::chrono::duration_cast<std::chrono::minutes>(ticks());
}

std::chrono::seconds time_span::total_seconds() const noexcept {
  return std::chrono::duration_cast<std::chrono::seconds>(ticks());
}

int32 time_span::compare_to(const time_span& value) const noexcept {
  return value_ < value.value_ ? -1 : value_ > value.value_ ? 1 : 0;
}

bool time_span::equals(const time_span& value) const noexcept {
  return value_ == value.value_;
}

xtd::ustring time_span::to_string() const noexcept {
  return to_string("G");
}

ustring time_span::to_string(const ustring& format) const {
  //return ustring::format(format, ticks());
  auto fmt = format;
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) throw format_exception("Invalid format"_t, csf_);
  
  switch (fmt[0]) {
    case 'c': return make_string_from_duration(true);
    case 'd': return ustring::format("{}", math::abs(days()));
    case 'D': return ustring::format("{:d2}", math::abs(days()));
    case 'f': return ustring::format("{}{}:{}:{:d2}:{:d2}.{:d3}{:d4}", ticks().count() < 0 ? "-" : "", math::abs(days()), math::abs(hours()), math::abs(minutes()), math::abs(seconds()), math::abs(milliseconds()), math::abs(ticks().count() % ticks_per_milliecond));
    case 'F': return ustring::format("{}{}:{:d2}:{:d2}:{:d2}.{:d3}{:d4}", ticks().count() < 0 ? "-" : "", math::abs(days()), math::abs(hours()), math::abs(minutes()), math::abs(seconds()), math::abs(milliseconds()), math::abs(ticks().count() % ticks_per_milliecond));
    case 'g': return make_string_from_duration(false);
    case 'G': return make_string_from_duration(true);
    case 'h': return ustring::format("{}", math::abs(hours()));
    case 'H': return ustring::format("{:d2}", math::abs(hours()));
    case 'l': return ustring::format("{}", math::abs(milliseconds()));
    case 'L': return ustring::format("{:d3}", math::abs(milliseconds()));
    case 'm': return ustring::format("{}", math::abs(minutes()));
    case 'M': return ustring::format("{:d2}", math::abs(minutes()));
    case 'o': return ustring::format("{}", ticks().count() < 0 ? "-" : "");
    case 'p': return ustring::format("{}", ticks().count() < 0 ? "-" : "+");
    case 's': return ustring::format("{}", math::abs(seconds()));
    case 'S': return ustring::format("{:d2}", math::abs(seconds()));
    case 't': return ustring::format("{:d3}{:d4}", math::abs(milliseconds()), math::abs(ticks().count() % ticks_per_milliecond));
    case 'T': return ustring::format("{:d3}{:d4}", math::abs(milliseconds()), math::abs(ticks().count() % ticks_per_milliecond));
    default: __format_exception("Invalid format"); return {};
  }
}

ustring time_span::make_string_from_duration(bool constant) const {
  ustring result;
  if (ticks().count() < 0) result += '-';
  if (days()) result += ustring::format("{}.", math::abs(days()));
  result += ustring::format(constant ? "{:d2}:{:d2}:{:d2}" : "{:d}:{:d2}:{:d2}", math::abs(hours()), math::abs(minutes()), math::abs(seconds()));
  if (ticks().count() % ticks_per_second) result += ustring::format(".{:d3}{:d4}", math::abs(milliseconds()), math::abs(ticks().count() % ticks_per_milliecond));
  return result;
}
