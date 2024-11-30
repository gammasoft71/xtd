#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#include <xtd/native/assert_dialog_results>
#include "../../../../include/xtd/native/win32/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cassert>
#include <sstream>
#include <windows.h>

using namespace xtd::native;

void debugger::debug_break() {
  DebugBreak();
}

bool debugger::is_attached() {
  return IsDebuggerPresent() != 0;
}

bool debugger::is_logging() {
  return is_attached();
}

bool debugger::launch() {
  // https://stackoverflow.com/questions/20337870/what-is-the-equivalent-of-system-diagnostics-debugger-launch-in-unmanaged-code
  auto system_dir = std::wstring(MAX_PATH, '\0');
  auto system_dir_size = GetSystemDirectory(system_dir.data(), (UINT)system_dir.size());
  if (system_dir_size == 0) return false;
  system_dir.resize(system_dir_size);
  
  auto startup_info = STARTUPINFO {};
  startup_info.cb = sizeof(startup_info);
  auto process_information = PROCESS_INFORMATION {};
  if (CreateProcess(nullptr, (system_dir + L"\\vsjitdebugger.exe -p " + std::to_wstring(GetCurrentProcessId())).data(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startup_info, &process_information) == 0) return false;
  CloseHandle(process_information.hThread);
  CloseHandle(process_information.hProcess);
  while (!IsDebuggerPresent()) Sleep(100);
  return true;
}

int32_t debugger::show_assert_dialog(const std::string& text, const std::string& caption) {
  return MessageBox(nullptr, win32::strings::to_wstring(text).c_str(), win32::strings::to_wstring(caption).c_str(), MB_TOPMOST | MB_ICONERROR | MB_ABORTRETRYIGNORE | MB_DEFBUTTON3);
}

void debugger::log(int32_t level, const std::string& category, const std::string& message) {
  OutputDebugString(win32::strings::to_wstring(message).c_str());
}
