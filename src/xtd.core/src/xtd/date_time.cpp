#include "../include/xtd/date_time.h"

using namespace std;
using namespace std::chrono;
using namespace xtd;

namespace {
  constexpr ticks ticks_to_1970 = ticks(621672202500000000LL);
  constexpr ticks date_time_minimum_value = ticks(0);
  constexpr ticks date_time_maximum_value = ticks(2534022971990000000LL) + ticks_to_1970;
};

date_time date_time::max_value {date_time_maximum_value};
date_time date_time::min_value {date_time_minimum_value};

date_time::date_time(xtd::ticks ticks) : value_(ticks) {  
}

date_time_kind date_time::kind() const noexcept {
  return kind_;
}

date_time date_time::from_time_t(std::time_t value) {
  date_time result;
  result.value_ = duration_cast<ticks>(chrono::seconds(value)) + ticks_to_1970;
  return result;
}

date_time date_time::now() {
  return from_time_t(system_clock::to_time_t(system_clock::now()));
}

xtd::ustring date_time::to_string() const noexcept {
  return to_string("{:u}");
}

ustring date_time::to_string(const ustring& format) const {
  return ustring::format(format, system_clock::from_time_t(to_time_t()));
}

std::time_t date_time::to_time_t() const {
  return duration_cast<chrono::seconds>(value_ - ticks_to_1970).count();
}

std::ostream& xtd::operator<<(std::ostream& os, const date_time& dt) noexcept {
  return os << dt.to_string();
}
