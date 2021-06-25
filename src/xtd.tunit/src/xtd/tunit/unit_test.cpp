#include "../../../include/xtd/tunit/unit_test.h"

#if defined(_WIN32)
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
int __tunit_argc = __argc;
char** __tunit_argv = __argv;
#else
int __tunit_argc;
char** __tunit_argv;

namespace {
  __attribute__((constructor)) void startup_program(int argc, char **argv) {
    __tunit_argc = argc;
    __tunit_argv = argv;
  }
}
#endif

xtd::tunit::unit_test::unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept : arguments(__tunit_argv == nullptr ? 0 : __tunit_argv + 1, __tunit_argv == nullptr ? 0 : __tunit_argv + __tunit_argc), name_(__tunit_argv == nullptr ? "(unknown)" : get_filename(__tunit_argv[0])), event_listener_(std::move(event_listener)) {
}
