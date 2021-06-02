#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstdlib>

using namespace xtd::native;

intptr_t process::create(const std::string& command_line) {
  ::system(command_line.c_str());
  return 0;
}

bool process::kill(intptr_t handle) {
  if (handle == 0) return false;
  return true;
}

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  return true;
}
