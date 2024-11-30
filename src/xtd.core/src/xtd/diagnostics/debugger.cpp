#include "../../../include/xtd/diagnostics/debugger.hpp"
#include "../../../include/xtd/diagnostics/debug_break.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::diagnostics;

bool debugger::is_attached() {
  return native::debugger::is_attached();
}

void debugger::debug_break() {
  debug_break_();
}

bool debugger::is_logging() {
  return native::debugger::is_logging();
}

bool debugger::launch() {
  if (is_attached()) return true;
  return native::debugger::launch();
}

void debugger::log(int32 level, const string& category, const string& message) {
  return native::debugger::log(level, category, message);
}
