#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#define UNICODE
#include <cassert>
#include <windows.h>

using namespace xtd::native;

void debug::assert_message_box(bool condition, const std::string& caption, const std::string& message) {
  auto result = MessageBox(nullptr, win32::strings::to_wstring(message).c_str(), win32::strings::to_wstring(caption).c_str(), MB_ICONERROR | MB_ABORTRETRYIGNORE | MB_DEFBUTTON3);
  if (result == IDABORT) exit(EXIT_FAILURE);
  else if (result == IDRETRY) _CrtDbgBreak();
}

void debug::write_to_output(const std::string& message) {
  OutputDebugStringA(message.c_str());
}
