#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process>
#include <xtd/native/process_creation_flags>
#include "../../../../include/xtd/native/win32/strings.hpp"
#include <xtd/native/process_window_style>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <array>
#include <filesystem>
#include <cstdlib>
#include <map>
#include <Windows.h>

using namespace std;
using namespace std::filesystem;
using namespace xtd::native;

namespace {
  auto process_infos = map<intmax_t, tuple<intmax_t, intmax_t, wstring, wstring, wstring, wstring>> {};
  class file_handle_streambuf : public std::streambuf {
  public:
    explicit file_handle_streambuf(HANDLE file_handle) : file_handle_(file_handle) {}
    ~file_handle_streambuf() { CloseHandle(file_handle_); }
    
  protected:
    int underflow() override {
      auto number_of_bytes_read = DWORD {};
      ReadFile(file_handle_, &value_, 1, &number_of_bytes_read, nullptr);
      if (number_of_bytes_read == 1) {
        this->setg(&value_, &value_, &value_ + 1);
        return value_;
      }
      return std::streambuf::underflow(); // EOF
    }
    
    int overflow(int c) override {
      value_ = static_cast<char>(c);
      auto number_of_bytes_written = DWORD {};
      if (WriteFile(file_handle_, &value_, 1, &number_of_bytes_written, nullptr) == 0) {
        this->setp(&value_, &value_);
        return 0;
      }
      return std::streambuf::overflow(c); // EOF
    }
    
    HANDLE file_handle_ = INVALID_HANDLE_VALUE;
    char value_ = EOF;
  };
  
  class process_istream : public std::istream {
  public:
    explicit process_istream(HANDLE file_handle) : std::istream(&stream_buf_), stream_buf_(file_handle) {}
    
  private:
    file_handle_streambuf stream_buf_;
  };
  
  class process_ostream : public std::ostream {
  public:
    explicit process_ostream(HANDLE file_handle) : std::ostream(&stream_buf_), stream_buf_(file_handle) {}
    
  private:
    file_handle_streambuf stream_buf_;
  };
  
  void initialize() {
    static auto initilized = false;
    if (initilized) return;
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    initilized = true;
  }
}

int32_t process::base_priority(int32_t priority) {
  static auto base_priorities = map<int32_t, int32_t> {{IDLE_PRIORITY_CLASS, 4}, {BELOW_NORMAL_PRIORITY_CLASS, 6}, {NORMAL_PRIORITY_CLASS, 8}, {ABOVE_NORMAL_PRIORITY_CLASS, 10}, {HIGH_PRIORITY_CLASS, 13}, {REALTIME_PRIORITY_CLASS, 24}};
  auto it = base_priorities.find(priority);
  if (it == base_priorities.end()) it = base_priorities.find(NORMAL_PRIORITY_CLASS);
  return it->second;
}

bool process::kill(intmax_t handle) {
  if (handle == 0) return false;
  return TerminateProcess(reinterpret_cast<HANDLE>(handle), static_cast<uint32_t>(-1)) != 0;
}

bool process::priority_class(intmax_t process, int32_t priority) {
  return SetPriorityClass(reinterpret_cast<HANDLE>(process), priority) == TRUE;
}

intmax_t process::shell_execute(const std::string& verb, const std::string& file_name, const std::string& arguments, const std::string& working_directory, int32_t process_window_style) {
  initialize();
  static auto window_styles = map<int32_t, int32_t> {{PROCESS_WINDOW_STYLE_NORMAL, SW_NORMAL}, {PROCESS_WINDOW_STYLE_HIDDEN, SW_HIDE}, {PROCESS_WINDOW_STYLE_MINIMIZED, SW_SHOWMINIMIZED}, {PROCESS_WINDOW_STYLE_MAXIMIZED, SW_SHOWMAXIMIZED}};
  auto wverb = win32::strings::to_wstring(verb);
  auto wfile_name = win32::strings::to_wstring(file_name);
  auto warguments = win32::strings::to_wstring(arguments);
  auto wworking_directory =  working_directory != "" ? win32::strings::to_wstring(working_directory) : filesystem::current_path().wstring();
  auto shell_execute_info = SHELLEXECUTEINFO {};
  shell_execute_info.cbSize = sizeof(SHELLEXECUTEINFO);
  shell_execute_info.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;
  shell_execute_info.hwnd = nullptr;
  shell_execute_info.lpVerb = wverb != L"" ? wverb.c_str() : nullptr;
  shell_execute_info.lpFile = wfile_name.c_str();
  shell_execute_info.lpParameters = warguments != L"" ? warguments.c_str() : nullptr;
  shell_execute_info.lpDirectory = wworking_directory.c_str();
  shell_execute_info.nShow = window_styles[process_window_style];
  shell_execute_info.hInstApp = nullptr;
  if (ShellExecuteEx(&shell_execute_info) == 0) return 0;
  process_infos[reinterpret_cast<intmax_t>(shell_execute_info.hInstApp)] = make_tuple(reinterpret_cast<intmax_t>(shell_execute_info.hProcess), 0, move(wverb), move(wfile_name), move(warguments), move(wworking_directory));
  return reinterpret_cast<intmax_t>(shell_execute_info.hInstApp);
}

process::started_process process::start(const string& file_name, const string& arguments, const string& working_directory, int32_t process_window_style, int32_t process_creation_flags, tuple<bool, bool, bool> redirect_standard_streams) {
  initialize();
  auto [redirect_standard_input, redirect_standard_output, redirect_standard_error] = redirect_standard_streams;
  auto startup_info = STARTUPINFO {};
  startup_info.cb = sizeof(STARTUPINFOA);
  if (redirect_standard_input || redirect_standard_output || redirect_standard_error) startup_info.dwFlags |= STARTF_USESTDHANDLES;
  auto security_attributes = SECURITY_ATTRIBUTES {};
  security_attributes.nLength = sizeof(SECURITY_ATTRIBUTES);
  security_attributes.bInheritHandle = TRUE;
  
  auto pipe_stdin = array<HANDLE, 2> {};
  if (redirect_standard_input) {
    CreatePipe(&pipe_stdin[0], &pipe_stdin[1], &security_attributes, 0);
    SetHandleInformation(pipe_stdin[1], HANDLE_FLAG_INHERIT, 0);
    startup_info.hStdInput = pipe_stdin[0];
  }
  
  auto pipe_stdout = array<HANDLE, 2> {};
  if (redirect_standard_output) {
    CreatePipe(&pipe_stdout[0], &pipe_stdout[1], &security_attributes, 0);
    SetHandleInformation(pipe_stdout[0], HANDLE_FLAG_INHERIT, 0);
    startup_info.hStdOutput = pipe_stdout[1];
  }
  
  auto pipe_stderr = array<HANDLE, 2> {};
  if (redirect_standard_error) {
    CreatePipe(&pipe_stderr[0], &pipe_stderr[1], &security_attributes, 0);
    SetHandleInformation(pipe_stderr[0], HANDLE_FLAG_INHERIT, 0);
    startup_info.hStdError = pipe_stderr[1];
  }
  
  auto process_information = PROCESS_INFORMATION {};
  if (CreateProcess(nullptr, win32::strings::to_wstring(file_name + (arguments == "" ? "" : (" " + arguments))).data(), nullptr, nullptr, true, process_creation_flags, nullptr, working_directory == "" ? nullptr : win32::strings::to_wstring(working_directory).c_str(), &startup_info, &process_information) == 0) return make_tuple(0, 0, nullptr, nullptr, nullptr);
  
  if (redirect_standard_input) CloseHandle(pipe_stdin[0]);
  if (redirect_standard_output) CloseHandle(pipe_stdout[1]);
  if (redirect_standard_error) CloseHandle(pipe_stderr[1]);
  
  process_infos[reinterpret_cast<intmax_t>(process_information.hProcess)] = make_tuple(reinterpret_cast<intmax_t>(process_information.hProcess), reinterpret_cast<intmax_t>(process_information.hThread), L"", win32::strings::to_wstring(file_name), win32::strings::to_wstring(arguments), win32::strings::to_wstring(working_directory));
  
  return make_tuple(reinterpret_cast<intmax_t>(process_information.hProcess), static_cast<int32_t>(process_information.dwProcessId), make_unique<process_ostream>(pipe_stdin[1]), make_unique<process_istream>(pipe_stdout[0]), make_unique<process_istream>(pipe_stderr[0]));
}

bool process::wait(intmax_t process, int32_t& exit_code) {
  initialize();
  if (process == 0) return false;
  auto it = process_infos.find(process);
  if (it == process_infos.end()) return false;
  if (get<1>(it->second) != 0) {
    if (WaitForSingleObject(reinterpret_cast<HANDLE>(get<0>(it->second)), INFINITE) == 0xFFFFFFFF) return false;
    GetExitCodeProcess(reinterpret_cast<HANDLE>(get<0>(it->second)), reinterpret_cast<LPDWORD>(&exit_code));
    CloseHandle(reinterpret_cast<HANDLE>(get<0>(it->second)));
  }
  if (get<1>(it->second) != 0) CloseHandle(reinterpret_cast<HANDLE>(get<1>(it->second)));
  process_infos.erase(it);
  return true;
}
