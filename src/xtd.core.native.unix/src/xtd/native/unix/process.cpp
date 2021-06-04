#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
using namespace std::filesystem;
using namespace xtd::native;

namespace {
  std::string shell_execute() {
#if defined(__APPLE__)
    return "open";
#else
    return "xdg-open";
#endif
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
  
  vector<string> split_arguments(const string& line_argument) {
    vector<string> arguments;
    bool skip_next_space = false;
    bool quotes_empty = false;
    int left_space_count = 0;
    int right_space_count = 0;
    string argument;
    
    for (size_t index = 0; index < line_argument.size(); index++) {
      if (line_argument[index] == '\"') {
        if (!left_space_count) quotes_empty = true;
        if (quotes_empty == true)
          left_space_count++;
        else
          right_space_count++;
        skip_next_space = left_space_count!= right_space_count && left_space_count % 2 != 0;
      } else {
        if (quotes_empty == true && left_space_count > 1&& left_space_count % 2 != 0) argument += '\"';
        if (left_space_count > 2)
          quotes_empty = false;
      }
      
      if (!skip_next_space && argument != "" && line_argument[index] == ' ') {
        if (quotes_empty == false && left_space_count > 1 && right_space_count > 1 && right_space_count % 2 != 0) argument += '\"';
        arguments.push_back(argument);
        argument = "";
        left_space_count = right_space_count = 0;
        skip_next_space = false;
      } else if (line_argument[index] != '\"')
        argument += line_argument[index];
    }
    
    if (argument != "") {
      if (quotes_empty == false && left_space_count > 1 && right_space_count > 1 && right_space_count % 2 != 0) argument += '\"';
      arguments.push_back(argument);
    }
    return arguments;
  }
}

intptr_t process::create(const string& file_name, const string& arguments, int32_t process_creation_flags, const std::string& working_directory) {
  auto command_line = file_name + (arguments == "" ? "" : (" " + arguments));
  pid_t process = fork();
  if (process == 0) {
    vector<string> command_line_args;
    if ((process_creation_flags & USE_SHELL_EXECUTE_PROCESS) == USE_SHELL_EXECUTE_PROCESS && is_valid_shell_execute_process(command_line, working_directory)) {
      command_line_args.push_back(shell_execute());
      command_line_args.push_back(exists(path(working_directory)/path(command_line)) ? (path(working_directory)/path(command_line)).string() : command_line);
    } else {
      command_line_args = split_arguments(arguments);
      command_line_args.insert(command_line_args.begin(), file_name);
    }
    std::vector<char*> execvp_args(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size()-1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(errno);
  }
  return static_cast<intptr_t>(process);
}

bool process::kill(intptr_t process) {
  if (process == 0) return false;
  return ::kill(static_cast<pid_t>(process), SIGTERM) == 0;
}

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  siginfo_t wait_info {};
  wait_info.si_pid = static_cast<pid_t>(process);
  waitid(P_PID, static_cast<pid_t>(process), &wait_info, WEXITED | WSTOPPED | WCONTINUED | WNOWAIT);
  exit_code = wait_info.si_status;
  return true;
}
