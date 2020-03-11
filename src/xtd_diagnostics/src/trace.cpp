#include <cassert>
void __assert__(bool condition) {assert(condition);}

#include "../include/xtd/diagnostics/trace.h"
#include "../include/xtd/diagnostics/default_trace_listener.h"

#if defined(_WIN32)
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
int __trace_argc = __argc;
char** __trace_argv = __argv;
#else
int __trace_argc;
char** __trace_argv;

namespace {
  __attribute__((constructor)) void startup_program(int argc, char **argv) {
    __trace_argc = argc;
    __trace_argv = argv;
  }
}
#endif

xtd::diagnostics::trace_listener_collection __listeners__ {std::make_shared<xtd::diagnostics::default_trace_listener>()};

bool xtd::diagnostics::trace::auto_flush_ = false;
unsigned int xtd::diagnostics::trace::indent_level_ = 0;
unsigned int xtd::diagnostics::trace::indent_size_ = 4;
xtd::diagnostics::trace_listener_collection& xtd::diagnostics::trace::listeners_ = __listeners__;
bool xtd::diagnostics::trace::use_global_lock_ = true;
std::mutex xtd::diagnostics::trace::global_lock_;
std::string xtd::diagnostics::trace::source_name_ = __trace_argv[0];
