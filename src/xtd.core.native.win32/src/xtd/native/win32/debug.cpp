#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#define UNICODE
#include <assert.h>
#include <windows.h>

using namespace xtd::native;

void debug::assert_message_box(bool condition, const std::string& message) {
  auto wmessage = win32::strings::to_wstring(message);
  auto wfile = win32::strings::to_wstring(__FILE__);
  _wassert(wmessage.c_str(), wfile.c_str(), __LINE__);
}

void debug::write_to_output(const std::string& message) {
  OutputDebugStringA(message.c_str());
}
