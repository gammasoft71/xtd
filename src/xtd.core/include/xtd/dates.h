#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/date_time.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/date_time.hpp> - Will be removed in version 0.4.0."
#endif
#include "date_time.hpp"

#if defined (WIN32)
static time_t __make_local_date_time(struct tm *tm) noexcept {return mktime(tm);}
static time_t __make_utc_date_time(struct tm *tm) noexcept {return _mkgmtime(tm);}
#else
static time_t __make_local_date_time(struct tm *tm) noexcept {return mktime(tm);}
static time_t __make_utc_date_time(struct tm *tm) noexcept {return timegm(tm);}
#endif

namespace xtd {
  class [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] date_times {
  public:
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm create(date_time_kind kind = date_time_kind::local) noexcept {return create(min(), kind);}
    
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm create(time_t time, date_time_kind kind = date_time_kind::utc) noexcept {return kind == date_time_kind::utc ? to_universal_time(time) : to_local_time(time);}
    
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm create(const tm& time, date_time_kind kind = date_time_kind::utc) noexcept {return kind == date_time_kind::utc ? to_universal_time(time) : to_local_time(time);}
    
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm create(int year, int month, int day, date_time_kind kind = date_time_kind::local) noexcept {
      std::tm time;
      time.tm_year = year - 1900;
      time.tm_mon = month - 1;
      time.tm_mday = day;
      time.tm_hour = time.tm_min = time.tm_sec = time.tm_wday = time.tm_yday = 0;
      time.tm_isdst = -1;
      time.tm_gmtoff = 0;
      time.tm_zone = nullptr;
      return create(time, kind);
    }
    
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm create(int year, int month, int day, int hour, int minute, int second, date_time_kind kind = date_time_kind::local) noexcept {
      std::tm time;
      time.tm_year = year - 1900;
      time.tm_mon = month - 1;
      time.tm_mday = day;
      time.tm_hour = hour;
      time.tm_min = minute;
      time.tm_sec = second;
      time.tm_wday = time.tm_yday = 0;
      time.tm_isdst = -1;
      time.tm_gmtoff = 0;
      time.tm_zone = nullptr;
      return create(time, kind);
    }
    
    [[deprecated("Replaced by xtd::dat_time::min_value - Will be removed in version 0.4.0.")]] static std::tm min() noexcept {return to_local_time(static_cast<time_t>(0));}
    [[deprecated("Replaced by xtd::dat_time::max_value - Will be removed in version 0.4.0.")]] static std::tm max() noexcept {return to_local_time(static_cast<time_t>(253402300799));}
    
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm to_local_time(time_t time) noexcept {return *std::localtime(&time);}
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm to_local_time(const std::chrono::system_clock::time_point& time) noexcept {return to_local_time(std::chrono::system_clock::to_time_t(time));}
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm to_local_time(std::tm time) noexcept {
      if (time.tm_zone != nullptr && std::string(time.tm_zone) == "UTC") return to_local_time(__make_utc_date_time(&time));
      return to_local_time(__make_local_date_time(&time));
    }
    
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm to_universal_time(time_t time) noexcept {return *std::gmtime(&time);}
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm to_universal_time(const std::chrono::system_clock::time_point& time) noexcept {return to_universal_time(std::chrono::system_clock::to_time_t(time));}
    [[deprecated("Replaced by xtd::dat_time - Will be removed in version 0.4.0.")]] static std::tm to_universal_time(std::tm time) noexcept {
      if (time.tm_zone != nullptr && std::string(time.tm_zone) != "UTC") return to_universal_time(__make_local_date_time(&time));
      return to_universal_time(__make_utc_date_time(&time));
    }
    
    [[deprecated("Replaced by xtd::dat_time::now - Will be removed in version 0.4.0.")]] static std::tm now() {return to_local_time(std::chrono::system_clock::now());}
    
    [[deprecated("Replaced by xtd::dat_time::now_utc - Will be removed in version 0.4.0.")]] static std::tm utc_now() {return to_universal_time(std::chrono::system_clock::now());}
  };
}
