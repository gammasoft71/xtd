#pragma once
#include "environment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the main procedure that should run when the application starts.
  /// @par Library
  /// xtd.core
  /// @param main_class The class that contains the static main method.
  /// @par Examples
  /// This example show a main method without arguments and without return code
  /// @include main1.cpp
  /// @par
  /// This example show a main method with a return code without arguments
  /// @include main2.cpp
  /// @par
  /// This example show a main method with argument and without return code
  /// @include main3.cpp
  /// @par
  /// This example show a main method with argument and return code
  /// @include main4.cpp
  /// @ingroup keywords
  #define startup_(main_class) \
    int main(int argc, char* argv[]) {\
      class startup {\
      public:\
        startup() = delete; \
        static int run(void (*main_function)(), int argc, char* argv[]) {main_function(); return xtd::environment::exit_code();}\
        static int run(int (*main_function)(), int argc, char* argv[]) {return main_function();}\
        static int run(void (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {main_function(argc, argv); return xtd::environment::exit_code();}\
        static int run(void (*main_function)(xtd::collections::specialized::string_vector), int argc, char* argv[]) {main_function({argv + 1, argv + argc}); return xtd::environment::exit_code();}\
        static int run(void (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {main_function({argv + 1, argv + argc}); return xtd::environment::exit_code();}\
        static int run(int (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {return main_function(argc, argv);}\
        static int run(int (*main_function)(xtd::collections::specialized::string_vector), int argc, char* argv[]) {return main_function({argv + 1, argv + argc});}\
        static int run(int (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {return main_function({argv + 1, argv + argc});}\
      };\
      return startup::run(main_class::main, argc, argv);\
    } \
    int __startup_force_to_end_with_semicolon__ = 0
}
