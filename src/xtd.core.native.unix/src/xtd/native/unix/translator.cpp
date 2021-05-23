#if defined(__linux__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator.h>
#include <xtd/native/environment.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

std::string translator::get_system_language() {
  return unix::strings::to_lower(unix::strings::substring(environment::get_environment_variable("LANG"), 0, 2));
}
#endif
