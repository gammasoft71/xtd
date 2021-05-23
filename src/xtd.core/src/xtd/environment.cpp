#include "../../include/xtd/environment.h"
#include "../../include/xtd/argument_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

int __exit_code = 0;

int xtd::environment::exit_code() noexcept {return __exit_code;}

void xtd::environment::exit_code(int value) noexcept {__exit_code = value;}

xtd::collections::specialized::string_vector xtd::environment::get_command_line_args() noexcept {
  return xtd::native::environment::get_command_line_args();
}

std::map<std::string, std::string>& xtd::environment::get_environment_variables(environment_variable_target target) {
  if (target == environment_variable_target::process) return xtd::native::environment::get_environment_variables(ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  if(target == environment_variable_target::user) return xtd::native::environment::get_environment_variables(ENVIRONMENT_VARIABLE_TARGET_USER);
  if(target == environment_variable_target::machine) return xtd::native::environment::get_environment_variables(ENVIRONMENT_VARIABLE_TARGET_MACHINE);
  throw argument_exception("Invalid environment variable target value"_t);
}
