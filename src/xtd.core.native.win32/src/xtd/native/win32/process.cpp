#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstdlib>
#include <Windows.h>

using namespace xtd::native;

namespace {
  std::string shell_execute() {
    return "explorer ";
  }
}

intptr_t process::create(const std::string& command_line, int32_t process_creation_flags) {
  STARTUPINFO startup_info {};
  startup_info.cb = sizeof(STARTUPINFO);
  PROCESS_INFORMATION process_information;
  CreateProcessA(nullptr, const_cast<LPSTR>(((process_creation_flags & USE_SHELL_EXECUTE_PROCESS) == USE_SHELL_EXECUTE_PROCESS ? shell_execute() + command_line : command_line).c_str()), nullptr, nullptr, true, process_creation_flags, nullptr, nullptr, &startup_info, &process_information);
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
