#include "../../../include/xtd/diagnostics/debugger.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::diagnostics;

bool debugger::is_attached() {
  return native::debugger::is_attached();
}

void debugger::debug_break() {
  return debug_break_();
}

bool debugger::is_logging() {
  return native::debugger::is_logging();
}

bool debugger::launch() {
  return native::debugger::launch();
}

void debugger::log(int level, std::string& category, const std::string& message) {

}
