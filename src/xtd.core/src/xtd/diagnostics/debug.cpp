#include <cassert>

#include "../include/xtd/diagnostics/debug.h"
#include "../include/xtd/diagnostics/default_trace_listener.h"

#if defined(_WIN32)
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
int __debug_argc = __argc;
char** __debug_argv = __argv;
#else
int __debug_argc;
char** __debug_argv;

namespace {
  __attribute__((constructor)) void startup_program(int argc, char **argv) {
    __debug_argc = argc;
    __debug_argv = argv;
  }
}
#endif

extern xtd::diagnostics::trace_listener_collection __listeners__;
extern char** __diagnostics_argv;

bool xtd::diagnostics::debug::auto_flush_ = false;
unsigned int xtd::diagnostics::debug::indent_level_ = 0;
unsigned int xtd::diagnostics::debug::indent_size_ = 4;
xtd::diagnostics::trace_listener_collection& xtd::diagnostics::debug::listeners_ = __listeners__;
bool xtd::diagnostics::debug::use_global_lock_ = true;
std::mutex xtd::diagnostics::debug::global_lock_;
std::string xtd::diagnostics::debug::source_name_ = __debug_argv[0];
