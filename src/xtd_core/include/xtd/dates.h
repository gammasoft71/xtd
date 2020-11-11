#pragma once
#include <chrono>
#include <ctime>

#if defined (WIN32)
static time_t __make_local_date_time(struct tm *tm) noexcept {return mktime(tm);}
static time_t __make_utc_date_time(struct tm *tm) noexcept {return _mkgmtime(tm);}
#else
static time_t __make_local_date_time(struct tm *tm) noexcept {return mktime(tm);}
static time_t __make_utc_date_time(struct tm *tm) noexcept {return timegm(tm);}
#endif

namespace xtd {
  enum class date_time_kind {
    utc,
    local,
  };
  
  enum class day_of_week {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
  
  class date_times {
  public:
    static std::tm create(date_time_kind kind = date_time_kind::local) noexcept {return create(min(), kind);}
    
    static std::tm create(time_t time, date_time_kind kind = date_time_kind::utc) noexcept {return kind == date_time_kind::utc ? to_universal_time(time) : to_local_time(time);}
    
    static std::tm create(const tm& time, date_time_kind kind = date_time_kind::utc) noexcept {return kind == date_time_kind::utc ? to_universal_time(time) : to_local_time(time);}
    
    static std::tm create(int year, int month, int day, date_time_kind kind = date_time_kind::local) noexcept {
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
    
    static std::tm create(int year, int month, int day, int hour, int minute, int second, date_time_kind kind = date_time_kind::local) noexcept {
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
    
    //static std::tm min() noexcept {return to_local_time(static_cast<time_t>(-62135596800));}
    static std::tm min() noexcept {return to_local_time(static_cast<time_t>(0));}
    static std::tm max() noexcept {return to_local_time(static_cast<time_t>(253402300799));}
    
    static std::tm to_local_time(time_t time) noexcept {return *std::localtime(&time);}
    static std::tm to_local_time(const std::chrono::system_clock::time_point& time) noexcept {return to_local_time(std::chrono::system_clock::to_time_t(time));}
    static std::tm to_local_time(std::tm time) noexcept {
      if (time.tm_zone != nullptr && std::string(time.tm_zone) == "UTC") return to_local_time(__make_utc_date_time(&time));
      return to_local_time(__make_local_date_time(&time));
    }
    
    static std::tm to_universal_time(time_t time) noexcept {return *std::gmtime(&time);}
    static std::tm to_universal_time(const std::chrono::system_clock::time_point& time) noexcept {return to_universal_time(std::chrono::system_clock::to_time_t(time));}
    static std::tm to_universal_time(std::tm time) noexcept {
      if (time.tm_zone != nullptr && std::string(time.tm_zone) != "UTC") return to_universal_time(__make_local_date_time(&time));
      return to_universal_time(__make_utc_date_time(&time));
    }
    
    static std::tm now() {return to_local_time(std::chrono::system_clock::now());}
    
    static std::tm utc_now() {return to_universal_time(std::chrono::system_clock::now());}
  };
}


/*
using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::string_literals;

// The main entry point for the application.
int main() {
  tm now = xtd::date_times::now();
  tm utc_now = xtd::date_times::utc_now();
  tm loc = xtd::date_times::create(2019, 4, 6, 3, 4, 5);
  tm utc = xtd::date_times::create(2019, 4, 6, 1, 4, 5, xtd::date_time_kind::utc);
  
  cout << strings::format("min {0} {0:Z}", xtd::date_times::min()) << endl;
  cout << strings::format("min {0} {0:Z}", xtd::date_times::to_local_time(xtd::date_times::min())) << endl;
  cout << strings::format("min {0} {0:Z}", xtd::date_times::to_universal_time(xtd::date_times::min())) << endl;
  cout << endl;
  cout << strings::format("max {0} {0:Z}", xtd::date_times::max()) << endl;
  cout << strings::format("max {0} {0:Z}", xtd::date_times::to_local_time(xtd::date_times::max())) << endl;
  cout << strings::format("max {0} {0:Z}", xtd::date_times::to_universal_time(xtd::date_times::max())) << endl;
  cout << endl;
  cout << strings::format("empty {0} {0:Z}", xtd::date_times::create()) << endl;
  cout << strings::format("empty {0} {0:Z}", xtd::date_times::create(date_time_kind::local)) << endl;
  cout << strings::format("empty {0} {0:Z}", xtd::date_times::create(date_time_kind::utc)) << endl;
  cout << endl;
  cout << strings::format("now {0} {0:Z}", now) << endl;
  cout << strings::format("now {0} {0:Z}", xtd::date_times::to_local_time(now)) << endl;
  cout << strings::format("now {0} {0:Z}", xtd::date_times::to_universal_time(now)) << endl;
  cout << endl;
  cout << strings::format("loc {0} {0:Z}", loc) << endl;
  cout << strings::format("loc {0} {0:Z}", xtd::date_times::to_local_time(loc)) << endl;
  cout << strings::format("loc {0} {0:Z}", xtd::date_times::to_universal_time(loc)) << endl;
  cout << endl;
  cout << strings::format("utc now {0} {0:Z}", utc_now) << endl;
  cout << strings::format("utc now {0} {0:Z}", xtd::date_times::to_local_time(utc_now)) << endl;
  cout << strings::format("utc now {0} {0:Z}", xtd::date_times::to_universal_time(utc_now)) << endl;
  cout << endl;
  cout << strings::format("utc {0} {0:Z}", utc) << endl;
  cout << strings::format("utc {0} {0:Z}", xtd::date_times::to_local_time(utc)) << endl;
  cout << strings::format("utc {0} {0:Z}", xtd::date_times::to_universal_time(utc)) << endl;
}

*/
