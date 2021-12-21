#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std;
using namespace xtd::native;

namespace {
  const int64_t ticks_per_millisecond = 10000;
  const int64_t ticks_per_second = ticks_per_millisecond * 1000;
  constexpr int64_t ticks_diff_betwin_date_time_file_and_os = 116444736000000000ULL; // Diff between 01/01/1601 and 01/01/1970 in ticks.
}

int32_t date_time::gmt_time(time_t time, uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week) {
  ULARGE_INTEGER uli {};
  uli.QuadPart = (time * ticks_per_second) + ticks_diff_betwin_date_time_file_and_os;
  FILETIME ft {uli.LowPart, uli.HighPart};
  SYSTEMTIME st {};
  if (FileTimeToSystemTime(&ft, &st) == 0) return -1;
  
  year = st.wYear;
  month = st.wMonth;
  day = st.wDay;
  hour = st.wHour;
  minute = st.wMinute;
  second = st.wSecond;
  day_of_year = (uint32_t)((time - make_gmt_time(st.wYear, 1, 1, 0, 0, 0)) / (86400)) + 1;
  day_of_week = st.wDayOfWeek;
  return 0;
}

bool date_time::is_daylight(time_t time) {
  struct tm value {};
  localtime_s(&value, &time);
  return value.tm_isdst != 0;
}

int32_t date_time::local_time(time_t time, uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week) {
  ULARGE_INTEGER uli {};
  uli.QuadPart = (time * ticks_per_second) + ticks_diff_betwin_date_time_file_and_os;
  FILETIME ft {uli.LowPart, uli.HighPart};
  FILETIME locFt {};
  if (FileTimeToLocalFileTime((const FILETIME*)&ft, &locFt) == 0) return -1;
  
  SYSTEMTIME st {};
  if (FileTimeToSystemTime(&locFt, &st) == 0) return -1;
  
  year = st.wYear;
  month = st.wMonth;
  day = st.wDay;
  hour = st.wHour;
  minute = st.wMinute;
  second = st.wSecond;
  day_of_year = (uint32_t)((time - make_gmt_time(st.wYear, 1, 1, 0, 0, 0)) / (86400)) + 1;
  day_of_week = st.wDayOfWeek;
  return 0;
}

time_t date_time::make_gmt_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second) {
  SYSTEMTIME st {(WORD)year, (WORD)month, 0, (WORD)day, (WORD)hour, (WORD)minute, (WORD)second, 0};
  FILETIME ft {};
  if (SystemTimeToFileTime(&st, &ft) == 0) return -1;
  
  ULARGE_INTEGER lt = {ft.dwLowDateTime, ft.dwHighDateTime};
  lt.QuadPart -= ticks_diff_betwin_date_time_file_and_os;
  lt.QuadPart /= ticks_per_second;
  return lt.QuadPart;
}

time_t date_time::make_local_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second) {
  SYSTEMTIME st {(WORD)year, (WORD)month, 0, (WORD)day, (WORD)hour, (WORD)minute, (WORD)second, 0};
  FILETIME ft {};
  if (SystemTimeToFileTime(&st, &ft) == 0) return -1;
  
  FILETIME ftUtc;
  if (LocalFileTimeToFileTime((const FILETIME*)&ft, &ftUtc) == 0) return -1;
  
  ULARGE_INTEGER lt {ftUtc.dwLowDateTime, ftUtc.dwHighDateTime};
  lt.QuadPart -= ticks_diff_betwin_date_time_file_and_os;
  lt.QuadPart /= ticks_per_second;
  return lt.QuadPart;
}
