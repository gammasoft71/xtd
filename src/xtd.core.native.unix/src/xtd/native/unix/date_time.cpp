#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <ctime>

using namespace std;
using namespace xtd::native;

#if !defined(__ANDROID__)
#include <sys/timeb.h>
#else
struct timeb {
  time_t    time;   /* [XSI] Seconds since the Epoch */
  unsigned short  millitm;  /* [XSI] Milliseconds since the Epoch */
  short   timezone; /* [XSI] Minutes west of CUT */
  short   dstflag;  /* [XSI] non-zero if DST in effect */
};

int ftime(struct timeb*);
#endif

int32_t date_time::gmt_time(time_t time, uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week) {
  struct tm value;
  if (gmtime_r(&time, &value) == nullptr)
    return -1;
  
  year = value.tm_year + 1900;
  month = value.tm_mon + 1;
  day = value.tm_mday;
  hour = value.tm_hour;
  minute = value.tm_min;
  second = value.tm_sec;
  day_of_year = value.tm_yday + 1;
  day_of_week = value.tm_wday;
  return 0;
}

bool date_time::is_daylight(time_t time) {
  struct tm value;
  localtime_r(&time, &value);
  return value.tm_isdst != 0;
}

int32_t date_time::local_time(time_t time, uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week) {
  struct tm value;
  if (localtime_r(&time, &value) == nullptr)
    return -1;
  
  year = static_cast<uint32_t>(value.tm_year + 1900);
  month = static_cast<uint32_t>(value.tm_mon + 1);
  day = static_cast<uint32_t>(value.tm_mday);
  hour = static_cast<uint32_t>(value.tm_hour);
  minute = static_cast<uint32_t>(value.tm_min);
  second = static_cast<uint32_t>(value.tm_sec);
  day_of_year = static_cast<uint32_t>(value.tm_yday + 1);
  day_of_week = value.tm_wday;
  return 0;
}

int32_t date_time::make_gmt_time(time_t& time, uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second) {
  struct tm local_time {};
  local_time.tm_year = year - 1900;
  local_time.tm_mon = month - 1;
  local_time.tm_mday = day;
  local_time.tm_hour = hour;
  local_time.tm_min = minute;
  local_time.tm_sec = second;
  local_time.tm_isdst = -1;

  time_t local = mktime(&local_time);
  struct tm gmt_time;
  if (gmtime_r(&local, &gmt_time) == nullptr)
    return -1;
  
  time_t gmt = mktime(&gmt_time);
  time = local + (local - gmt + (gmt_time.tm_isdst > 0 ? 3600 : 0));
  return  0;
}

int32_t date_time::make_local_time(time_t& time, uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second) {
  struct tm gmt_time {};
  gmt_time.tm_year = year - 1900;
  gmt_time.tm_mon = month - 1;
  gmt_time.tm_mday = day;
  gmt_time.tm_hour = hour;
  gmt_time.tm_min = minute;
  gmt_time.tm_sec = second;
  gmt_time.tm_isdst = -1;

  time_t gmt = mktime(&gmt_time);
  struct tm local_time;
  if (gmtime_r(&gmt, &local_time) == nullptr)
    return -1;

  time_t local = mktime(&local_time);
  time = gmt + (gmt - local + (local_time.tm_isdst > 0 ? 3600 : 0));
  return 0;
}
