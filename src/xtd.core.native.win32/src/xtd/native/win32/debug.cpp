#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <windows.h>

using namespace xtd::native;

void debug::assert_message_box(bool condition, const std::string& message) {
  ASSERT(condition);
}

void debug::write_to_output(const std::string& message) {
  OutputDebugStringA(message.c_str());
}
