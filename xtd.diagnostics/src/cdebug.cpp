#include "../include/xtd/diagnostics/cdebug.hpp"
#include "../include/xtd/diagnostics/debugstreambuf.hpp"

namespace {
  xtd::diagnostics::debugstreambuf cdebugstreambuf;
}

namespace xtd {
  std::ostream cdebug(&cdebugstreambuf);
}
