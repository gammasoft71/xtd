#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#include <xtd/native/assert_dialog_results.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#define UNICODE
#include <cassert>
#include <windows.h>

using namespace xtd::native;

int32_t debug::show_assert_dialog(const std::string& text, const std::string& caption) {
  return MessageBox(nullptr, win32::strings::to_wstring(text).c_str(), win32::strings::to_wstring(caption).c_str(), MB_ICONERROR | MB_ABORTRETRYIGNORE | MB_DEFBUTTON3);
}

void debug::write_to_output(const std::string& message) {
  OutputDebugStringA(message.c_str());
}
