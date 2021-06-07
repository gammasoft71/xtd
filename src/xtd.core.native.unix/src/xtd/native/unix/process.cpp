#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#include <xtd/native/process_window_style.h>
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
    file_descriptor_streambuf(int file_descriptor) : file_descriptor_(file_descriptor) {}
    ~file_descriptor_streambuf() {close(file_descriptor_);}
    
  protected:
    int underflow() override {
      if (read(file_descriptor_, &value_, 1) == 1) {
        this->setg(&value_, &value_, &value_+1);
        return value_;
      }
      return std::streambuf::underflow(); // EOF
    }
    
    int overflow(int c) override {
      value_ = static_cast<char>(c);
      if (write(file_descriptor_, &value_, 1) != -1) {
        this->setp(&value_, &value_);
        return 0;
      }
      return std::streambuf::overflow(c); // EOF
    }
    
    int file_descriptor_;
    char value_ = EOF;
  };

  class process_istream : public std::istream {
  public:
    process_istream(int file_descriptor) : std::istream(&stream_buf_), stream_buf_(file_descriptor) {}
    
  private:
    file_descriptor_streambuf stream_buf_;
  };
  
  class process_ostream : public std::ostream {
  public:
    process_ostream(int file_descriptor) : std::ostream(&stream_buf_), stream_buf_(file_descriptor) {}
    
  private:
    file_descriptor_streambuf stream_buf_;
  };

  std::string shell_execute_command() {
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
    return command_line == "" || exists(command_line) || exists(path(working_directory)/path(command_line)) || is_known_uri(command_line);
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

tuple<intptr_t, unique_ptr<ostream>, unique_ptr<istream>, unique_ptr<istream>> process::create(const string& file_name, const string& arguments, const string& working_directory, int32_t process_creation_flags, int32_t process_window_style, tuple<bool, bool, bool> redirect_standard_streams) {
  auto [redirect_standard_input, redirect_standard_output, redirect_standard_error] = redirect_standard_streams;

  int pipe_stdin[2];
  if (redirect_standard_input) pipe(pipe_stdin);
  int pipe_stdout[2];
  if (redirect_standard_output) pipe(pipe_stdout);
  int pipe_stderr[2];
  if (redirect_standard_error) pipe(pipe_stderr);
  
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
    if (working_directory != "") current_path(working_directory);
    command_line_args = split_arguments(arguments);
    command_line_args.insert(command_line_args.begin(), file_name);
    std::vector<char*> execvp_args(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size()-1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(errno);
  }
  
  if (redirect_standard_input) close(pipe_stdin[0]);
  if (redirect_standard_output) close(pipe_stdout[1]);
  if (redirect_standard_error) close(pipe_stderr[1]);

  return make_tuple(static_cast<intptr_t>(process), make_unique<process_ostream>(pipe_stdin[1]), make_unique<process_istream>(pipe_stdout[0]), make_unique<process_istream>(pipe_stderr[0]));
}

bool process::kill(intptr_t process) {
  if (process == 0) return false;
  return ::kill(static_cast<pid_t>(process), SIGTERM) == 0;
}

intptr_t process::shell_execute(const std::string& file_name, const std::string& arguments, const std::string& working_directory, int32_t process_window_style) {
  pid_t process = fork();
  if (process == 0) {
    vector<string> command_line_args;
    command_line_args = split_arguments(arguments);
    if (is_valid_shell_execute_process(file_name, working_directory)) {
      auto command_working_directory = working_directory != "" ? working_directory : current_path().string();
      command_line_args.insert(command_line_args.begin(), exists(path(command_working_directory)/path(file_name)) ? (path(command_working_directory)/path(file_name)).string() : file_name);
      command_line_args.insert(command_line_args.begin(), shell_execute_command());
    } else {
      if (working_directory != "") current_path(working_directory);
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

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  siginfo_t wait_info {};
  wait_info.si_pid = static_cast<pid_t>(process);
  waitid(P_PID, static_cast<pid_t>(process), &wait_info, WEXITED | WSTOPPED | WCONTINUED | WNOWAIT);
  exit_code = wait_info.si_status;
  return true;
}
