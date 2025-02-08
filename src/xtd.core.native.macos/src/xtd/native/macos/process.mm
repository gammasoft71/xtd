#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process>
#include <xtd/native/process_creation_flags>
#include <xtd/native/priority_class>
#include <xtd/native/process_window_style>
#include "../../../../include/xtd/native/macos/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <signal.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <TargetConditionals.h>

using namespace xtd::native;

namespace {
  class file_descriptor_streambuf : public std::streambuf {
  public:
    explicit file_descriptor_streambuf(int32_t file_descriptor) : file_descriptor_(file_descriptor) {}
    ~file_descriptor_streambuf() {close(file_descriptor_);}
    
  protected:
    int32_t underflow() override {
      if (read(file_descriptor_, &value_, 1) == 1) {
        this->setg(&value_, &value_, &value_ + 1);
        return value_;
      }
      return std::streambuf::underflow(); // EOF
    }
    
    int32_t overflow(int32_t c) override {
      value_ = static_cast<char>(c);
      if (write(file_descriptor_, &value_, 1) != -1) {
        this->setp(&value_, &value_);
        return 0;
      }
      return std::streambuf::overflow(c); // EOF
    }
    
    int32_t file_descriptor_ = 0;
    char value_ = EOF;
  };
  
  class process_istream : public std::istream {
  public:
    explicit process_istream(int32_t file_descriptor) : std::istream(&stream_buf_), stream_buf_(file_descriptor) {}
    
  private:
    file_descriptor_streambuf stream_buf_;
  };
  
  class process_ostream : public std::ostream {
  public:
    explicit process_ostream(int32_t file_descriptor) : std::ostream(&stream_buf_), stream_buf_(file_descriptor) {}
    
  private:
    file_descriptor_streambuf stream_buf_;
  };
  
  std::string shell_execute_command() {
    return "open";
  }
  
  std::string get_full_file_name_with_extension(std::function<std::vector<std::string>(const std::string& str, const std::vector<char>& separators, size_t count, bool)> splitter, const std::string& file_name, const std::string& working_directory = "") {
    auto path_directories = std::string {getenv("PATH") == nullptr ? "" : getenv("PATH")};
    path_directories += ":/Applications:/Applications/Utilities:/System/Applications:/System/Applications/Utilities:/opt/homebrew/bin";
    auto user = std::string {getenv("USER") != nullptr ? getenv("USER") : ""};
    if (user != "") path_directories += ":/Users/" + user + "/Applications";
    
    static auto standard_extensions = std::set<std::string> {"", ".action", ".apk", ".app", ".bin", ".command", ".csh", ".ipa", ".ksh", ".osx", ".out", ".run", ".sh", ".workflow"};
    auto extensions = std::filesystem::path(file_name).has_extension() ? std::set<std::string> {""} : standard_extensions;
    for (auto extension : extensions) {
      auto file_name_with_extension = file_name + extension;
      if (working_directory != "" && exists(std::filesystem::path(working_directory) / file_name_with_extension)) return (std::filesystem::path(working_directory) / file_name_with_extension).string();
      if (std::filesystem::path(file_name_with_extension).has_root_directory()) return file_name_with_extension;
      if (std::filesystem::exists(std::filesystem::current_path() / file_name_with_extension)) return (std::filesystem::current_path() / file_name_with_extension).string();
      for (auto directory : splitter(path_directories, {':'}, std::numeric_limits<size_t>::max(), false))
        if (exists(std::filesystem::path(directory) / file_name_with_extension)) return (std::filesystem::path(directory) / file_name_with_extension).string();
    }
    return file_name;
  }
  
  bool is_valid_process(std::function<std::vector<std::string>(const std::string& str, const std::vector<char>& separators, size_t count, bool)> splitter, const std::string& command_line, const std::string& working_directory) {
    auto full_file_name_with_extension = get_full_file_name_with_extension(splitter, command_line, working_directory);
    return std::filesystem::exists(full_file_name_with_extension);
  }
  
  bool is_valid_uri(const std::string& command_line) {
    static auto schemes = std::vector<std::string> {"file", "ftp", "gopher", "http", "https", "mailto", "net.pipe", "net.tcp", "news", "nntp"};
    auto iterator = std::find_if(schemes.begin(), schemes.end(), [&](auto scheme) {return command_line.find(scheme + ":") == 0;});
    return iterator != schemes.end();
  }
  
  bool is_valid_shell_execute_process(std::function<std::vector<std::string>(const std::string& str, const std::vector<char>& separators, size_t count, bool)> splitter, const std::string& command_line, const std::string& working_directory) {
    return command_line == "" || is_valid_process(splitter, command_line, working_directory) || is_valid_uri(command_line);
  }
  
  std::vector<std::string> split_arguments(const std::string& line_argument) {
    auto arguments = std::vector<std::string> {};
    auto skip_next_space = false;
    auto quotes_empty = false;
    auto left_space_count = 0;
    auto right_space_count = 0;
    auto argument = std::string {};
    
    for (auto index = size_t {0}; index < line_argument.size(); ++index) {
      if (line_argument[index] == '\"') {
        if (!left_space_count) quotes_empty = true;
        if (quotes_empty == true)
          left_space_count++;
        else
          right_space_count++;
        skip_next_space = left_space_count != right_space_count && left_space_count % 2 != 0;
      } else {
        if (quotes_empty == true && left_space_count > 1 && left_space_count % 2 != 0) argument += '\"';
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
    static auto base_priorities = std::map<int32_t, int32_t> {{IDLE_PRIORITY_CLASS, PRIO_MIN}, {BELOW_NORMAL_PRIORITY_CLASS, PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4}, {NORMAL_PRIORITY_CLASS, PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 2}, {ABOVE_NORMAL_PRIORITY_CLASS, PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4}, {HIGH_PRIORITY_CLASS, PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8}, {REALTIME_PRIORITY_CLASS, PRIO_MAX}};
    auto it = base_priorities.find(priority);
    if (it == base_priorities.end()) return false;
    base_priority = it->second;
    return true;
  }
}

int32_t process::base_priority(int32_t priority) {
  auto base_priority = PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 2;
  compute_base_priority(priority, base_priority);
  return base_priority;
}

bool process::kill(intmax_t process) {
  if (process == 0) return false;
  return ::kill(static_cast<pid_t>(process), SIGTERM) == 0;
}

bool process::priority_class(intmax_t process, int32_t priority) {
  auto base_priority = PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 2;
  if (compute_base_priority(priority, base_priority) == false) return false;
  return setpriority(PRIO_PROCESS, static_cast<id_t>(process), base_priority) == 0;
}

intmax_t process::shell_execute(const std::string& verb, const std::string& file_name, const std::string& arguments, const std::string& working_directory, int32_t process_window_style) {
  auto process = fork();
  if (process == 0) {
    auto is_shell_execute = is_valid_shell_execute_process(&macos::strings::split, file_name, working_directory);
    if (is_shell_execute) {
      for (auto arg : split_arguments(arguments))
        if (!(is_shell_execute = is_valid_shell_execute_process(&macos::strings::split, arg, working_directory))) break;
    }
    auto command_line_args = std::vector<std::string> {};
    if (is_shell_execute) {
      if (verb == "runas") {
        if (file_name == "") return 0;
        command_line_args.insert(command_line_args.begin(), std::string("do shell script \"") + file_name + (arguments != "" ? " " + arguments : "") + std::string("\" with administrator privileges"));
        command_line_args.insert(command_line_args.begin(), "-e");
        command_line_args.insert(command_line_args.begin(), "osascript");
      } else if (verb == "print") {
        if (file_name == "") return 0;
        command_line_args.insert(command_line_args.begin(), file_name);
        command_line_args.insert(command_line_args.begin(), "lpr");
      } else if (verb == "" || verb == "open" || verb == "explore" || verb == "edit" || verb == "runas" || verb == "runasuser" || verb == "print") {
        if (verb == "") command_line_args = split_arguments(arguments);
        if ((verb == "open" || verb == "runas" || verb == "runasuser") && file_name == "") return 0;
        if (verb == "explore" && (file_name == "" || !std::filesystem::is_directory(file_name))) return 0;
        if (verb == "edit" && (file_name == "" || !std::filesystem::is_regular_file(file_name) || (std::filesystem::status(file_name).permissions() & std::filesystem::perms::owner_write) != std::filesystem::perms::owner_write)) return 0;
        if ((verb == "runas" || verb == "runasuser")  && (file_name == "" || (std::filesystem::status(file_name).permissions() & std::filesystem::perms::owner_exec) != std::filesystem::perms::owner_exec)) return 0;
        command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&macos::strings::split, file_name, working_directory));
        command_line_args.insert(command_line_args.begin(), shell_execute_command());
      } else {
        command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&macos::strings::split, file_name, working_directory));
        command_line_args.insert(command_line_args.begin(), verb);
      }
    } else {
      command_line_args = split_arguments(arguments);
      if (working_directory != "") std::filesystem::current_path(working_directory.c_str());
      command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&macos::strings::split, file_name));
    }
    auto execvp_args = std::vector<char*>(command_line_args.size() + 1);
    for (size_t index = 0; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size() - 1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(-1);
  }
  return static_cast<intmax_t>(process);
}

process::started_process process::start(const std::string& file_name, const std::string& arguments, const std::string& working_directory, int32_t process_window_style, int32_t process_creation_flags, std::tuple<bool, bool, bool> redirect_standard_streams) {
  if (!is_valid_process(&macos::strings::split, file_name, working_directory)) return std::make_tuple(0, 0, std::unique_ptr<std::ostream> {}, std::unique_ptr<std::istream> {}, std::unique_ptr<std::istream> {});

  auto [redirect_standard_input, redirect_standard_output, redirect_standard_error] = redirect_standard_streams;
  auto pipe_result = 0;
  int32_t pipe_stdin[] = {0, 0};
  if (redirect_standard_input) pipe_result = pipe(pipe_stdin);
  int32_t pipe_stdout[] = {0, 0};
  if (redirect_standard_output) pipe_result = pipe(pipe_stdout);
  int32_t pipe_stderr[] = {0, 0};
  if (redirect_standard_error) pipe_result = pipe(pipe_stderr);
  if (pipe_result) {/*do nothing*/}
  
  auto process = fork();
  if (process == 0) {
    if (redirect_standard_input) {
      close(pipe_stdin[1]);
      dup2(pipe_stdin[0], STDIN_FILENO);
    }
    
    if (redirect_standard_output) {
      close(pipe_stdout[0]);
      dup2(pipe_stdout[1], STDOUT_FILENO);
    }
    
    if (redirect_standard_error) {
      close(pipe_stderr[0]);
      dup2(pipe_stderr[1], STDERR_FILENO);
    }
    
    auto command_line_args = std::vector<std::string> {};
    if (working_directory != "") std::filesystem::current_path(working_directory.c_str());
    command_line_args = split_arguments(arguments);
    command_line_args.insert(command_line_args.begin(), get_full_file_name_with_extension(&macos::strings::split, file_name));
    auto execvp_args = std::vector<char*>(command_line_args.size() + 1);
    for (auto index = size_t {0}; index < command_line_args.size(); ++index)
      execvp_args[index] = command_line_args[index].data();
    execvp_args[execvp_args.size() - 1] = nullptr;
    execvp(execvp_args[0], execvp_args.data());
    exit(-1);
  }
  
  if (redirect_standard_input) close(pipe_stdin[0]);
  if (redirect_standard_output) close(pipe_stdout[1]);
  if (redirect_standard_error) close(pipe_stderr[1]);
  
  return std::make_tuple(static_cast<intmax_t>(process), static_cast<int32_t>(process), std::make_unique<process_ostream>(pipe_stdin[1]), std::make_unique<process_istream>(pipe_stdout[0]), std::make_unique<process_istream>(pipe_stderr[0]));
}

bool process::wait(intmax_t process, int32_t& exit_code) {
  if (process == 0) return false;
  auto wait_info = siginfo_t {};
  wait_info.si_pid = static_cast<pid_t>(process);
  waitid(P_PID, static_cast<pid_t>(process), &wait_info, WEXITED | WSTOPPED | WCONTINUED | WNOWAIT);
  exit_code = wait_info.si_status;
  return true;
}
