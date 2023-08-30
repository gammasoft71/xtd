#include "../../include/xtd/startup.h"
#include "../../include/xtd/threading/thread.h"

#define __XTD_CORE_INTERNAL__
#include "../../include/xtd/internal/__startup_catch_exception.h"
#undef __XTD_CORE_INTERNAL__

using namespace xtd;
using namespace xtd::threading;

void startup::init_safe_run() {
}

void startup::end_safe_run() {
  thread::join_all();
}

void startup::generic_exception_message(const std::exception& e) {
  __startup_catch_exception__(e);
}

void startup::generic_exception_message() {
  __startup_catch_exception__();
}
