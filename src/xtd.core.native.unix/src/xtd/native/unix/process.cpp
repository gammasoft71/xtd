#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#include <xtd/native/priority_class.h>
#include <xtd/native/process_window_style.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <functional>
#include <map>
#include <set>
#include <signal.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

using namespace std;
using namespace std::filesystem;
using namespace xtd::native;

namespace {
  class file_descriptor_streambuf : public streambuf {
  public:
    file_descriptor_streambuf(int file_descriptor) : file_descriptor_(file_descriptor) {}
    ~file_descriptor_streambuf() {close(file_descriptor_);}
    
  protected:
    int underflow() override {
      if (read(file_descriptor_, &value_, 1) == 1) {
        this->setg(&value_, &value_, &value_+1);
        return value_;
      }
      return streambuf::underflow(); // EOF
    }
    
    int overflow(int c) override {
      value_ = static_cast<char>(c);
      if (write(file_descriptor_, &value_, 1) != -1) {
        this->setp(&value_, &value_);
        return 0;
      }
      return streambuf::overflow(c); // EOF
    }
    
    int file_descriptor_;
    char value_ = EOF;
  };

  class process_istream : public istream {
  public:
    process_istream(int file_descriptor) : istream(&stream_buf_), stream_buf_(file_descriptor) {}
    
  private:
    file_descriptor_streambuf stream_buf_;
  };
  
  class process_ostream : public ostream {
  public:
    process_ostream(int file_descriptor) : ostream(&stream_buf_), stream_buf_(file_descriptor) {}
    
  private:
    file_descriptor_streambuf stream_buf_;
  };

  string shell_execute_command() {
#if defined(__APPLE__)
    return "open";
#else
    return "xdg-open";
#endif
  }

  string get_full_file_name_with_extension(function<vector<string>(const string& str, const vector<char>& separators, size_t count, bool)> splitter, const string& file_name, const string& working_directory = "") {
    string path_directories = getenv("PATH") == nullptr ? "" : getenv("PATH");
#if defined(__APPLE__)
    path_directories += ":/Applications:/Applications/Utilities:/System/Applications:/System/Applications/Utilities";
    string user = getenv("USER") != nullptr ? getenv("USER") : "";
    if (user != "") path_directories += ":/Users/" + user + "/Applications";
#endif
    
    static set<string> standard_extensions = {"", ".action", ".apk", ".app", ".bin", ".command", ".csh", ".ipa", ".ksh", ".osx", ".out", ".run", ".sh", ".workflow"};
    set<string> extensions = path(file_name).has_extension() ? set<string> {""} : standard_extensions;
    for(auto extension : extensions) {
      auto file_name_with_extension = file_name + extension;
      if (working_directory != "" && exists(path(working_directory)/file_name_with_extension)) return (path(working_directory)/file_name_with_extension).string();
      if (path(file_name_with_extension).has_root_directory()) return file_name_with_extension;
      if (exists(current_path()/file_name_with_extension)) return (current_path()/file_name_with_extension).string();
      for (auto directory : splitter(path_directories, {':'}, numeric_limits<size_t>::max(), false))
        if (exists(path(directory)/file_name_with_extension)) return (path(directory)/file_name_with_extension).string();
    }
    return file_name;
  }
  
  bool is_valid_process(function<vector<string>(const string& str, const vector<char>& separators, size_t count, bool)> splitter, const string& command_line, const string& working_directory) {
    auto full_file_name_with_extension = get_full_file_name_with_extension(splitter, command_line, working_directory);
    return exists(full_file_name_with_extension);
  }

  bool is_valid_uri(const string& command_line) {
    static vector<string> schemes = {"file", "ftp", "gopher", "http", "https", "mailto", "net.pipe", "net.tcp", "news", "nntp"};
    for (auto scheme : schemes)
      if (command_line.find(scheme + ":") == 0) return true;
    return false;
  }

  bool is_valid_shell_execute_process(function<vector<string>(const string& str, const vector<char>& separators, size_t count, bool)> splitter, const string& command_line, const string& working_directory) {
    return command_line == "" || is_valid_process(splitter, command_line, working_directory) || is_valid_uri(command_line);
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
  
  bool compute_base_priority(int32_t priority, int32_t& base_priority) {
    static map<int32_t, int32_t> base_priorities {{IDLE_PRIORITY_CLASS, PRIO_MIN}, {BELOW_NORMAL_PRIORITY_CLASS, PRIO_MIN + (PRIO_MAX - PRIO_MIN)/4}, {NORMAL_PRIORITY_CLASS, PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 2}, {ABOVE_NORMAL_PRIORITY_CLASS, PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4}, {HIGH_PRIORITY_CLASS, PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8}, {REALTIME_PRIORITY_CLASS, PRIO_MAX}};
    auto it = base_priorities.find(priority);
    if (it == base_priorities.end()) return false;
    base_priority = it->second;
    return true;
  }
}

int32_t process::base_priority(int32_t priority) {
  int32_t base_priority = PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2;
  compute_base_priority(priority, base_priority);
  return base_priority;
}

bool process::kill(intptr_t process) {
  if (process == 0) return false;
  return ::kill(static_cast<pid_t>(process), SIGTERM) == 0;
}

bool process::priority_class(intptr_t process, int32_t priority) {
  int32_t base_priority = PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2;
  if (compute_base_priority(priority, base_priority) == false) return false;
  return setpriority(PRIO_PROCESS, static_cast<id_t>(process), base_priority) == 0;
}

intptr_t process::shell_execute(const std::string& verb, const string& file_name, const string& arguments, const string& working_directory, int32_t process_window_style) {
  pid_t process = fork();
  if (process == 0) {
    bool is_shell_execute = is_valid_shell_execute_process(&unix::strings::split, file_name, working_directory);
    if (is_shell_execute) {
      for (auto arg : split_arguments(arguments))
        if (!(is_shell_execute = is_valid_shell_execute_process(&unix::strings::split, arg, working_directory))) break;
    }
    vector<string> command_line_args;
    if (is_shell_execute) {
#if defined(__APPLE__)
      if (verb == "runas") {
        if (file_name == "") return 0;
        command_line_args.insert(command_line_args.begin(), string("do shell script \"") + file_name + (arguments != "" ? " " + arguments : "") + string("\" with administrator privileges"));
        command_line_args.insert(command_line_args.begin(), "-e");
        command_line_args.insert(command_line_args.begin(), "osascript");
      } else if (verb == "print") {
        if (file_name == "") return 0;
        command_line_args.insert(command_line_args.begin(), file_name);
        command_line_args.insert(command_line_args.begin(), "lpr");
      } else
#endif
      if (verb == "" || verb == "open" || verb == "explore" || verb == "edit" || verb == "runas" || verb == "runasuser" || verb == "print") {
        if (verb == "") command_line_args = split_arguments(arguments);
        if ((verb == "open" || verb == "runas" || verb == "runasuser") && file_name == "") return 0;
        if (verb == "explore" && (file_name == "" || !is_directory(file_name))) return 0;
        if (verb == "edit" && (file_name == "" || !is_regular_file(file_name) || (status(file_name).permissions() & perms::owner_write) != perms::owner_write)) return 0;
        if ((verb == "runas" || verb == "runasuser")  && (file_name == "" || (status(file_name).permissions() & perms::owner_exec) != perms::owner_exec)) return 0;
        command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&unix::strings::split, file_name, working_directory));
        command_line_args.insert(command_line_args.begin(), shell_execute_command());
      } else {
        command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&unix::strings::split, file_name, working_directory));
        command_line_args.insert(command_line_args.begin(), verb);
      }
    } else {
      command_line_args = split_arguments(arguments);
      if (working_directory != "") chdir(working_directory.c_str());
      command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&unix::strings::split, file_name));
    }
    vector<char*> execvp_args(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size()-1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(-1);
  }
  return static_cast<intptr_t>(process);
}

process::started_process process::start(const string& file_name, const string& arguments, const string& working_directory, int32_t process_window_style, int32_t process_creation_flags, tuple<bool, bool, bool> redirect_standard_streams) {
  auto [redirect_standard_input, redirect_standard_output, redirect_standard_error] = redirect_standard_streams;
  
  int pipe_result = 0;
  int pipe_stdin[2];
  if (redirect_standard_input) pipe_result = pipe(pipe_stdin);
  int pipe_stdout[2];
  if (redirect_standard_output) pipe_result = pipe(pipe_stdout);
  int pipe_stderr[2];
  if (redirect_standard_error) pipe_result = pipe(pipe_stderr);
  if (pipe_result) {/*do nothing*/}
  
  if (!is_valid_process(&unix::strings::split, file_name, working_directory)) return make_tuple(0, 0, make_unique<process_ostream>(pipe_stdin[1]), make_unique<process_istream>(pipe_stdout[0]), make_unique<process_istream>(pipe_stderr[0]));;
  
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
    if (working_directory != "") chdir(working_directory.c_str());
    command_line_args = split_arguments(arguments);
    command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&unix::strings::split, file_name));
    vector<char*> execvp_args(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size()-1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(-1);
  }
  
  if (redirect_standard_input) close(pipe_stdin[0]);
  if (redirect_standard_output) close(pipe_stdout[1]);
  if (redirect_standard_error) close(pipe_stderr[1]);
  
  return make_tuple(static_cast<intptr_t>(process), static_cast<int32_t>(process), make_unique<process_ostream>(pipe_stdin[1]), make_unique<process_istream>(pipe_stdout[0]), make_unique<process_istream>(pipe_stderr[0]));
}

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  siginfo_t wait_info {};
  wait_info.si_pid = static_cast<pid_t>(process);
  waitid(P_PID, static_cast<pid_t>(process), &wait_info, WEXITED | WSTOPPED | WCONTINUED | WNOWAIT);
  exit_code = wait_info.si_status;
  return true;
}
