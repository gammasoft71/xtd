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
  class file_handle_streambuf : public std::streambuf {
  public:
    file_handle_streambuf(HANDLE file_handlle) : fille_handle_(file_handlle) {}
    ~file_handle_streambuf() { CloseHandle(fille_handle_); }

  protected:
    int underflow() override {
      DWORD number_of_bytes_read = 0;
      ReadFile(fille_handle_, &value_, 1, &number_of_bytes_read, nullptr);
      if (number_of_bytes_read == 1) {
        this->setg(&value_, &value_, &value_ + 1);
        return value_;
      }
      return std::streambuf::underflow(); // EOF
    }

    int overflow(int c) override {
      value_ = static_cast<char>(c);
      DWORD number_of_bytes_written = 0;
      WriteFile(fille_handle_, &value_, 1, &number_of_bytes_written, nullptr);
      if (number_of_bytes_written != -1) {
        this->setp(&value_, &value_);
        return 0;
      }
      return std::streambuf::overflow(c); // EOF
    }

    HANDLE fille_handle_;
    char value_ = EOF;
  };

  class process_istream : public std::istream {
  public:
    process_istream(HANDLE file_handle) : std::istream(&stream_buf_), stream_buf_(file_handle) {}

  private:
    file_handle_streambuf stream_buf_;
  };

  class process_ostream : public std::ostream {
  public:
    process_ostream(HANDLE file_handle) : std::ostream(&stream_buf_), stream_buf_(file_handle) {}

  private:
    file_handle_streambuf stream_buf_;
  };

  std::string shell_execute() {
    return "explorer";
  }
}

tuple<intptr_t, unique_ptr<ostream>, unique_ptr<istream>, unique_ptr<istream>> process::create(const string& file_name, const string& arguments, int32_t process_creation_flags, const string& working_directory, tuple<bool, bool, bool> redirect_standard_streams) {
  if ((process_creation_flags & USE_SHELL_EXECUTE_PROCESS) == USE_SHELL_EXECUTE_PROCESS) {
    HANDLE process = ShellExecuteA(nullptr, nullptr, file_name.c_str(), arguments != "" ? arguments.c_str() : nullptr, working_directory != "" ? working_directory.c_str() : nullptr, SW_NORMAL);
    return make_tuple(reinterpret_cast<intptr_t>(process), nullptr, nullptr, nullptr);
  }

  auto [redirect_standard_input, redirect_standard_output, redirect_standard_error] = redirect_standard_streams;
  STARTUPINFO startup_info {};
  startup_info.cb = sizeof(STARTUPINFO);
  if (redirect_standard_input || redirect_standard_output || redirect_standard_error) startup_info.dwFlags |= STARTF_USESTDHANDLES;
  char temp_path_name[MAX_PATH];
  GetTempPathA(MAX_PATH, temp_path_name);

  if (redirect_standard_error) {
    char temp_file_name[MAX_PATH];
    GetTempFileNameA(temp_path_name, "err", 0, temp_file_name);
    HANDLE file_handle = CreateFileA(temp_file_name, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    startup_info.hStdError = file_handle;
  }

  if (redirect_standard_input) {
    char temp_file_name[MAX_PATH];
    GetTempFileNameA(temp_path_name, "in", 0, temp_file_name);
    HANDLE file_handle = CreateFileA(temp_file_name, GENERIC_READ, 0, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    startup_info.hStdInput = file_handle;
  }

  if (redirect_standard_output) {
    char temp_file_name[MAX_PATH];
    GetTempFileNameA(temp_path_name, "out", 0, temp_file_name);
    HANDLE file_handle = CreateFileA(temp_file_name, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    startup_info.hStdOutput = file_handle;
  }

  PROCESS_INFORMATION process_information;
  process_creation_flags &= ~USE_SHELL_EXECUTE_PROCESS;
  if (CreateProcessA(nullptr, (file_name + (arguments == "" ? "" : (" " + arguments))).data(), nullptr, nullptr, false, process_creation_flags, nullptr, working_directory == "" ? nullptr : working_directory.c_str(), &startup_info, &process_information) == 0) return make_tuple(0, nullptr, nullptr, nullptr);
  return make_tuple(reinterpret_cast<intptr_t>(process_information.hProcess), make_unique<process_ostream>(startup_info.hStdInput), make_unique<process_istream>(startup_info.hStdOutput), make_unique<process_istream>(startup_info.hStdError));
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
