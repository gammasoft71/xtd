#include "../../include/xtd/environment.h"
#include "../../include/xtd/startup.h"
#include "../../include/xtd/threading/thread.h"

#define __XTD_CORE_INTERNAL__
#include "../../include/xtd/internal/__show_generic_exception_message.h"
#undef __XTD_CORE_INTERNAL__

using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::threading;

void startup::init_safe_run() {
}

void startup::end_safe_run() {
  thread::join_all();
}

int startup::run(void (*main_function)(), int, char* []) {
  main_function(); return environment::exit_code();
}

int startup::run(void (*main_function)()) {
  main_function();
  return environment::exit_code();
}

int startup::run(void (*main_function)(int, char* []), int argc, char* argv[]) {
  main_function(argc, argv);
  return environment::exit_code();
}

int startup::run(void (*main_function)(const string_vector&), int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}
int startup::run(int (*main_function)(), int, char* []) {
  return main_function();
}

int startup::run(int (*main_function)()) {
  return main_function();
}

int startup::run(int (*main_function)(int, char* []), int argc, char* argv[]) {
  return main_function(argc, argv);
}

int startup::run(int (*main_function)(const string_vector&), int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

void startup::show_generic_exception_message(const std::exception& e) {
  __show_generic_exception_message__(e);
}

void startup::show_generic_exception_message() {
  __show_generic_exception_message__();
}
