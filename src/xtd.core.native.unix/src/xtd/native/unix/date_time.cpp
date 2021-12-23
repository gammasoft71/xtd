#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <ctime>

using namespace std;
using namespace xtd::native;

bool date_time::is_daylight(time_t time) {
  tm value;
  localtime_r(&time, &value);
  return value.tm_isdst != 0;
}
