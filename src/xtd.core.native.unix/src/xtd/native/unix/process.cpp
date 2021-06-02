#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <vector>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>

using namespace xtd::native;

intptr_t process::create(const std::string& command_line) {
  pid_t process = fork();
  if (process == 0) {
    auto command_line_args = xtd::native::unix::strings::split(command_line, {' '}, 2);
    std::vector<char*> execvp_args(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size()-1] = nullptr;
    
    execvp(execvp_args[0], execvp_args.data());
  }
  return static_cast<intptr_t>(process);
}

bool process::kill(intptr_t process) {
  if (process == 0) return false;
  return ::kill(static_cast<pid_t>(process), SIGKILL) == 0;
}

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  siginfo_t wait_info {};
  wait_info.si_pid = static_cast<pid_t>(process);
  waitid(P_PID, static_cast<pid_t>(process), &wait_info, WEXITED | WSTOPPED | WCONTINUED | WNOWAIT);
  exit_code = wait_info.si_status;
  return true;
}
