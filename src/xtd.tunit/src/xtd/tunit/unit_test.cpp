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
  __attribute__((constructor)) void startup_program(int argc, char** argv) {
    __tunit_argc = argc;
    __tunit_argv = argv;
  }
}
#endif

xtd::tunit::unit_test::unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept : unit_test(std::move(event_listener), __tunit_argc, __tunit_argv) {
}

xtd::tunit::unit_test::unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener, int argc, char* argv[]) noexcept : arguments(argv == nullptr ? 0 : argv + 1, argv == nullptr ? 0 : argv + argc), name_(get_filename(argv[0])), event_listener_(std::move(event_listener)) {
}
