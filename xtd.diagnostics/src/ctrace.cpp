#include "../include/xtd/diagnostics/ctrace.hpp"
#include "../include/xtd/diagnostics/tracestreambuf.hpp"

namespace {
  xtd::diagnostics::tracestreambuf ctracestreambuf;
}

namespace xtd {
  std::ostream ctrace(&ctracestreambuf);
}
