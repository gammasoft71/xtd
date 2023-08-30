/// @file
/// @brief Contains startup class and #startup_ keyword.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__startup.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the xtd::startup object that can be used in the main method to safely call the application's main entry point.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  class startup final static_ {
  public:
    /// @brief Safely call the specified application's main entry point, argc and argv.
    /// @param main_function The main method to safety call.
    /// @param argc the main argc param.
    /// @param argv the main argv param.
    /// @remarks The main_function is called in try and catch. If an exception occurs, a generic message is displayed.
    /// @remarks The xtd::threading::thread::join_all method are cal before exit. See xtd::threading::thread::join_all for more information.
    /// @remarks The xtd::startup::run method is used by the keyword #startup_.
    /// @param main_class The class that contains the static main method.
    /// @par Examples
    /// This example show a main_function without arguments and without return code
    /// @include startup1.cpp
    /// @par
    /// This example show a main_function with a return code and without arguments
    /// @include startup2.cpp
    /// @par
    /// This example show a main_function with argument and without return code
    /// @include startup3.cpp
    /// @par
    /// This example show a main_function with argument and return code
    /// @include startup4.cpp
    template <typename main_function_t>
    static int safe_run(main_function_t main_function, int argc, char* argv[]) {
      try {
        init_safe_run();
        auto exit_code = __startup__::run(main_function, argc, argv);
        end_safe_run();
        return exit_code;
      } catch(const std::exception& e) {
        generic_exception_message(e);
      } catch(...) {\
        generic_exception_message();
      }
      return 0;
    }
    
    /// @brief Safely call the specified application's main entry point.
    /// @param main_function The main method to safety call.
    /// @remarks The main_function is called in try and catch. If an exception occurs, a generic message is displayed.
    /// @remarks The xtd::threading::thread::join_all method are cal before exit. See xtd::threading::thread::join_all for more information.
    /// @remarks The xtd::startup::run method is used by the keyword #startup_.
    /// @param main_class The class that contains the static main method.
    /// @par Examples
    /// This example show a main_function without arguments and without return code
    /// @include startup1.cpp
    /// @par
    /// This example show a main_function with a return code and without arguments
    /// @include startup2.cpp
    /// @par
    /// This example show a main_function with argument and without return code
    /// @include startup3.cpp
    /// @par
    /// This example show a main_function with argument and return code
    /// @include startup4.cpp
    template <typename main_function_t>
    static int safe_run(main_function_t main_function) {
      try {
        init_safe_run();
        auto exit_code = __startup__::run(main_function);
        end_safe_run();
        return exit_code;
      } catch(const std::exception& e) {
        generic_exception_message(e);
      } catch(...) {\
        generic_exception_message();
      }
      return 0;
    }
    
  private:
    static void init_safe_run();
    static void end_safe_run();
    static void generic_exception_message(const std::exception& e);
    static void generic_exception_message();
  };
}

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
    return xtd::startup::safe_run(main_class::main, argc, argv);\
  }\
  auto __startup_force_to_end_with_semicolon__ = 0
