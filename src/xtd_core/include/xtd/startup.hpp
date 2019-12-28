#pragma once
#include <string>
#include <vector>
#include "environment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
/// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the Main procedure that should run when the application starts.
/// @par Library
/// Switch.Core
/// @param main_class The class that contains the static Main method.
/// @par Examples
/// This example show a Main method without arguments and without return code
/// @include Main1.cpp
/// @par
/// This example show a Main method with a return code without arguments
/// @include Main2.cpp
/// @par
/// This example show a Main method with argument and without return code
/// @include Main3.cpp
/// @par
/// This example show a Main method with argument and return code
/// @include Main4.cpp
/// @ingroup Keywords
#define startup_(main_class) \
  int main(int argc, char* argv[]) {\
    struct startup {\
      startup() = delete; \
      static int run(void (*main_function)(), const std::vector<std::string>& args) {main_function(); return xtd::environment::exit_code();}\
      static int run(int (*main_function)(), const std::vector<std::string>& args) {return main_function();}\
      static int run(void (*main_function)(std::vector<std::string>), const std::vector<std::string>& args) {main_function(args); return xtd::environment::exit_code();}\
      static int run(void (*main_function)(const std::vector<std::string>&), const std::vector<std::string>& args) {main_function(args); return xtd::environment::exit_code();}\
      static int run(int (*main_function)(std::vector<std::string>), const std::vector<std::string>& args) {return main_function(args);}\
      static int run(int (*main_function)(const std::vector<std::string>&), const std::vector<std::string>& args) {return main_function(args);}\
    };\
    return startup::run(main_class::main, {argv + 1, argv + argc});\
  } \
  int __startup_force_to_end_with_semicolon__ = 0
}
