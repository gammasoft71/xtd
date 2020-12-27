#if defined(_WIN32)
#include "../../include/xtd/environment.h"
#include <Windows.h>

using namespace std;
using namespace xtd;

string __translator_get_system_language__() {
  if (!environment::get_environment_variable("LANG").empty()) return strings::to_lower(strings::substring(environment::get_environment_variable("LANG"), 0, 2));
  char data[256] = {0};
  GetLocaleInfoA(LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, data, 256);
  return data;
}

#endif
