#if defined(__linux__)
#include "../../include/xtd/environment.h"

using namespace std;
using namespace xtd;

string __translator_get_system_language__() {
  return strings::to_lower(strings::substring(environment::get_environment_variable("LANG"), 0, 2));
}

#endif
