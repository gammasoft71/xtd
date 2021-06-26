#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger.h>
#include <xtd/native/assert_dialog_results.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#define UNICODE
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
  std::wstring system_dir(MAX_PATH + 1, '\0');
  UINT system_dir_size = GetSystemDirectory(system_dir.data(), (UINT)system_dir.length());
  if (system_dir_size == 0) return false;
  system_dir.resize(system_dir_size);

  STARTUPINFO startup_info = {};
  startup_info.cb = sizeof(startup_info);
  PROCESS_INFORMATION process_information = {};
  if (CreateProcess(nullptr, (system_dir + L"\\vsjitdebugger.exe -p " + std::to_wstring(GetCurrentProcessId())).data(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startup_info, &process_information) == 0) return false;
  CloseHandle(process_information.hThread);
  CloseHandle(process_information.hProcess);
  while (!IsDebuggerPresent()) Sleep(100);
  return true;
}

int32_t debugger::show_assert_dialog(const std::string& text, const std::string& caption) {
  return MessageBox(nullptr, win32::strings::to_wstring(text).c_str(), win32::strings::to_wstring(caption).c_str(), MB_ICONERROR | MB_ABORTRETRYIGNORE | MB_DEFBUTTON3);
}

void debugger::log(int32_t level, const std::string& category, const std::string& message) {
  OutputDebugStringA(message.c_str());
}
