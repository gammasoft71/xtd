#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#include <xtd/native/environment>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

std::string translator::get_system_language() {
  if (!environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS).empty()) return unix::strings::to_lower(unix::strings::substring(environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS), 0, 2));
  return "";
}
