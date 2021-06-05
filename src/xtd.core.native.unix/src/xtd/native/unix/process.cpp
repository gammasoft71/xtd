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
  class file_descriptor_streambuf : public std::streambuf {
  public:
    file_descriptor_streambuf(int fd) : fd_(fd) {}
    ~file_descriptor_streambuf() {close(fd_);}
    
  protected:
    int underflow() override {
      if (read(fd_, &value_, 1) == 1) {
        this->setg(&value_, &value_, &value_+1);
        return value_;
      }
      return std::streambuf::underflow(); // EOF
    }
    
    int overflow(int c) override {
      value_ = static_cast<char>(c);
      if (write(fd_, &value_, 1) != -1) {
        this->setp(&value_, &value_);
        return 0;
      }
      return std::streambuf::overflow(c); // EOF
    }
    
    int fd_;
    char value_ = EOF;
    std::string buffer_;
  };
  
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
  // Set following three lines in parameters...
  bool redirect_standard_input = false;
  bool redirect_standard_output = true;
  bool redirect_standard_error = false;
  
  auto command_line = file_name + (arguments == "" ? "" : (" " + arguments));
  int pipe_stdin[2];
  pipe(pipe_stdin);
  int pipe_stdout[2];
  pipe(pipe_stdout);
  int pipe_stderr[2];
  pipe(pipe_stderr);
  
  pid_t process = fork();
  if (process == 0) {
    if (redirect_standard_input) {
      close(pipe_stdin[1]);
      dup2(pipe_stdin[0], 0);
    }
    
    if (redirect_standard_output) {
      close(pipe_stdout[0]);
      dup2(pipe_stdout[1], 1);
    }
    
    if (redirect_standard_error) {
      close(pipe_stderr[0]);
      dup2(pipe_stderr[1], 2);
    }
    
    vector<string> command_line_args;
    if ((process_creation_flags & USE_SHELL_EXECUTE_PROCESS) == USE_SHELL_EXECUTE_PROCESS && is_valid_shell_execute_process(command_line, working_directory)) {
      command_line_args.push_back(shell_execute());
      command_line_args.push_back(exists(path(working_directory)/path(command_line)) ? (path(working_directory)/path(command_line)).string() : command_line);
    } else {
      if (working_directory != "") current_path(working_directory);
      command_line_args = split_arguments(arguments);
      command_line_args.insert(command_line_args.begin(), file_name);
    }
    std::vector<char*> execvp_args(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size()-1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(errno);
  } else {
    if (redirect_standard_input) close(pipe_stdin[0]);
    if (redirect_standard_output) close(pipe_stdout[1]);
    if (redirect_standard_error) close(pipe_stderr[1]);
    
    file_descriptor_streambuf file_descriptor_streambuf_stdin(pipe_stdin[1]);
    std::ostream process_stdin_stream(&file_descriptor_streambuf_stdin);
    file_descriptor_streambuf file_descriptor_streambuf_stdout(pipe_stdout[0]);
    std::istream process_stdout_stream(&file_descriptor_streambuf_stdout);
    file_descriptor_streambuf file_descriptor_streambuf_stderr(pipe_stderr[0]);
    std::istream process_stderr_stream(&file_descriptor_streambuf_stderr);
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
