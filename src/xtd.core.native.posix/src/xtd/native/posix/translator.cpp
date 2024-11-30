#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#include <xtd/native/environment>
#include "../../../../include/xtd/native/posix/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

std::string translator::get_system_locale() {
  if (!environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS).empty()) return environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  return "";
}
