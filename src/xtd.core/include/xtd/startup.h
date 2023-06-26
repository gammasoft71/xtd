/// @file
/// @brief Contains #startup_ keyword.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "environment.h"
#include "static.h"
#include "system_exception.h"
#include "ustring.h"
#include "collections/specialized/string_vector.h"
#include "console.h"
#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__
#include "xtd/forms/application.h"
#include "xtd/forms/exception_box.h"
#endif

/// @cond
struct __startup__ final static_ {
  static int run(void (*main_function)(), int, char* []) {main_function(); return xtd::environment::exit_code();}
  static int run(void (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {main_function(argc, argv); return xtd::environment::exit_code();}
  static int run(void (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {main_function({argv + 1, argv + argc}); return xtd::environment::exit_code();}
  static int run(int (*main_function)(), int, char* []) {return main_function();}
  static int run(int (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {return main_function(argc, argv);}
  static int run(int (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {return main_function({argv + 1, argv + argc});}
};

#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__
inline void __startup_catch_exception__(const std::exception& e) {xtd::forms::application::open_forms().size() > 0 ? xtd::forms::exception_box::show(xtd::forms::application::open_forms()[0].get(), e, xtd::forms::application::product_name()) : xtd::forms::exception_box::show(e, xtd::forms::application::product_name());}
inline void __startup_catch_exception__() {xtd::forms::application::open_forms().size() > 0 ? xtd::forms::exception_box::show(xtd::forms::application::open_forms()[0].get(), xtd::forms::application::product_name()) : xtd::forms::exception_box::show(xtd::forms::application::product_name());}
#else
inline void __startup_catch_exception__(const std::exception& e) {std::cerr << std::endl << xtd::ustring::format("Unhandled exception: {}", dynamic_cast<const xtd::system_exception*>(&e) ? static_cast<const xtd::system_exception&>(e).to_string() :  e.what()) << std::endl;}
inline void __startup_catch_exception__() { std::cerr << std::endl << xtd::ustring::format("Unhandled exception: Unknown exception occurred") << std::endl;}
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the main procedure that should run when the application starts.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @param main_class The class that contains the static main method.
  /// @par Examples
  /// This example show a main method without arguments and without return code
  /// @include main1.cpp
  /// @par
  /// This example show a main method with a return code and without arguments
  /// @include main2.cpp
  /// @par
  /// This example show a main method with argument and without return code
  /// @include main3.cpp
  /// @par
  /// This example show a main method with argument and return code
  /// @include main4.cpp
#define startup_(main_class) \
  auto main(int argc, char* argv[])->int {\
    try {\
      return __startup__::run(main_class::main, argc, argv);\
    } catch(const std::exception& e) {\
      __startup_catch_exception__(e);\
    } catch(...) {\
      __startup_catch_exception__();\
    }\
  }\
  auto __startup_force_to_end_with_semicolon__ = 0
}
