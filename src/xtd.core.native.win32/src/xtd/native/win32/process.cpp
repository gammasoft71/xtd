#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>
#include <cstdlib>
#include <Windows.h>

using namespace std;
using namespace std::filesystem;
using namespace xtd::native;

namespace {
  std::string shell_execute() {
    return "explorer";
  }

  bool is_known_uri(const string& command_line) {
    static vector<string> schemes = {"file", "ftp", "gopher", "http", "https", "mailto", "net.pipe", "net.tcp", "news", "nntp"};
    for (auto scheme : schemes)
      if (command_line.find(scheme + ":") == 0) return true;
    return false;
  }
  
  bool is_valid_shell_execute_process(const string& command_line, const std::string& working_directory) {
    return exists(command_line) || exists(path(working_directory)/path(command_line)) || is_known_uri(command_line);
  }
}

intptr_t process::create(const string& file_name, const string& arguments, int32_t process_creation_flags, const std::string& working_directory) {
  auto command_line = file_name + (arguments == "" ? "" : (" " + arguments));
  if ((process_creation_flags & USE_SHELL_EXECUTE_PROCESS) == USE_SHELL_EXECUTE_PROCESS && is_valid_shell_execute_process(command_line, working_directory))
    command_line = shell_execute() + " " + (exists(path(working_directory)/path(command_line)) ? (path(working_directory)/path(command_line)).string() : command_line);

  STARTUPINFO startup_info {};
  startup_info.cb = sizeof(STARTUPINFO);
  PROCESS_INFORMATION process_information;
  process_creation_flags &= ~USE_SHELL_EXECUTE_PROCESS;
  if (CreateProcessA(nullptr, command_line.data(), nullptr, nullptr, false, process_creation_flags, nullptr, working_directory == "" ? nullptr : working_directory.c_str(), &startup_info, &process_information) == 0) return 0;
  return reinterpret_cast<intptr_t>(process_information.hProcess);
}

bool process::kill(intptr_t handle) {
  if (handle == 0) return false;
  return TerminateProcess(reinterpret_cast<HANDLE>(handle), static_cast<uint32_t>(-1)) != 0;
}

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  bool result = WaitForSingleObject(reinterpret_cast<HANDLE>(process), INFINITE) == 0;
  if (result) GetExitCodeProcess(reinterpret_cast<HANDLE>(process), reinterpret_cast<LPDWORD>(&exit_code));
  CloseHandle(reinterpret_cast<HANDLE>(process));
  return result;
}
