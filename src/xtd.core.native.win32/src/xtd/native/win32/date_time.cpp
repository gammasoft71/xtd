#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <time.h>
#include <Windows.h>

using namespace std;
using namespace xtd::native;

bool date_time::is_daylight(time_t time) {
  tm value {};
  localtime_s(&value, &time);
  return value.tm_isdst != 0;
}
