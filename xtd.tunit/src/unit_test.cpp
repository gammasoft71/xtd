#include "../include/xtd/unit_test.hpp"

#if defined(_WIN32)
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
#else
int __argc;
char** __argv;

namespace {
  __attribute__((constructor)) void startup_program(int argc, char **argv) {
    __argc = argc;
    __argv = argv;
  }
}
#endif

xtd::tunit::unit_test::unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept : arguments(__argv + 1, __argv + __argc), name_(get_filename(__argv[0])), event_listener_(std::move(event_listener)) {
}
