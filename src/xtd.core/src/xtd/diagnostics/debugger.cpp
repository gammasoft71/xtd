#include "../../../include/xtd/diagnostics/debugger.hpp"
#include "../../../include/xtd/diagnostics/debug_break.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::diagnostics;

auto debugger::is_attached() -> bool {
  return native::debugger::is_attached();
}

auto debugger::debug_break() -> void {
  debug_break_();
}

auto debugger::is_logging() -> bool {
  return native::debugger::is_logging();
}

auto debugger::launch() -> bool {
  if (is_attached()) return true;
  return native::debugger::launch();
}

auto debugger::log(int32 level, const string& category, const string& message) -> void {
  return native::debugger::log(level, category, message);
}
