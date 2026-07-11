/// @file
/// @brief Contains xtd::startup class and #startup_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "threading/tasks/task.hpp"
#include "threading/tasks/wtask.hpp"
#include "argument_collection.hpp"
#include "callable.hpp"
#include "delegate.hpp"
#include "environment.hpp"
#include "exception.hpp"
#include "static.hpp"

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
    /// @name Public Static Methods
    
    /// @{
    /// @brief Safely call the specified application's main entry point.
    /// @param main_function The main method to safety call.
    /// @remarks The main_function is called in try and catch. If an exception occurs, a generic message is displayed.
    /// @remarks The xtd::threading::thread::join_all method are call before exit. See xtd::threading::thread::join_all for more information.
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
    static auto run(auto main_function) -> int {
      try {
        auto exit_code = internal_run(main_function);
        xtd::threading::thread::join_all();
        return exit_code;
      } catch (const std::exception& e) {
        return xtd::exception::show_exception(e);
      } catch (...) {
        return xtd::exception::show_exception();
      }
    }
    
    /// @brief Safely call the specified application's main entry point, argc and argv.
    /// @param main_function The main method to safety call.
    /// @param argc the main argc param.
    /// @param argv the main argv param.
    /// @remarks The main_function is called in try and catch. If an exception occurs, a generic message is displayed.
    /// @remarks The xtd::threading::thread::join_all method are call before exit. See xtd::threading::thread::join_all for more information.
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
    static auto run(auto main_function, int argc, char* argv[]) -> int {
      xtd::environment::set_command_line_args({argv, argv + argc});
      return run(main_function);
    }
    /// @}
       
  private:
    static auto args() -> xtd::argument_collection {
      auto args = xtd::environment::get_command_line_args();
      return {args.begin() + 1, args.end()};
    }

    static auto argv_data() -> char** {return argv().data();}
    static auto argv_length() -> int {return xtd::as<int>(argv().length());}
    static auto argv() -> xtd::array<char*>& {
      if (!argv_.empty()) return argv_;
      argv_ = array<char*>(xtd::environment::get_command_line_args().length());
      for (auto index = 0_z; index < xtd::environment::get_command_line_args().length(); ++index)
        argv_[index] = const_cast<char*>(xtd::environment::get_command_line_args()[index].data());
      return argv_;
    }
    
    static auto internal_run(xtd::callable<void> auto main_function) -> int {main_function(); return xtd::environment::exit_code();}
    static auto internal_run(xtd::callable<void, int, char* []> auto main_function) -> int {main_function(argv_length(), argv_data()); return xtd::environment::exit_code();}
    static auto internal_run(xtd::callable<void, const xtd::argument_collection&> auto main_function) -> int {main_function(args()); return xtd::environment::exit_code();}
    
    static auto internal_run(xtd::callable<int> auto main_function) -> int {return main_function();}
    static auto internal_run(xtd::callable<int, int, char* []> auto main_function) -> int {return main_function(argv_length(), argv_data());}
    static auto internal_run(xtd::callable<int, const xtd::argument_collection&> auto main_function) -> int {return main_function(args());}

    static auto internal_run(xtd::callable<xtd::threading::tasks::task<>> auto main_function) -> int {main_function().wait(); return xtd::environment::exit_code();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::task<>, int, char* []> auto main_function) -> int {main_function(argv_length(), argv_data()).wait(); return xtd::environment::exit_code();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::task<>, const xtd::argument_collection&> auto main_function) -> int {main_function(args()).wait(); return xtd::environment::exit_code();}

    static auto internal_run(xtd::callable<xtd::threading::tasks::task<int>> auto main_function) -> int {return main_function().result();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::task<int>, int, char* []> auto main_function) -> int {return main_function(argv_length(), argv_data()).result();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::task<int>, const xtd::argument_collection&> auto main_function) -> int {return main_function(args()).result();}

    static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<>> auto main_function) -> int {main_function().wait(); return xtd::environment::exit_code();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<>, int, char* []> auto main_function) -> int {main_function(argv_length(), argv_data()).wait(); return xtd::environment::exit_code();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<>, const xtd::argument_collection&> auto main_function) -> int {main_function(args()).wait(); return xtd::environment::exit_code();}

    static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<int>> auto main_function) -> int {return main_function().result();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<int>, int, char* []> auto main_function) -> int {return main_function(argv_length(), argv_data()).result();}
    static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<int>, const xtd::argument_collection&> auto main_function) -> int {return main_function(args()).result();}

    inline static xtd::array<char*> argv_;
  };
}

/// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the main procedure that should run when the application starts.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param main_method The main method.
/// @par Implementation
/// ```cpp
/// auto main() -> int {
///   return xtd::startup::run(main_method);
/// }
/// ```
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
#define startup_(...) \
  auto main() -> int { \
    return xtd::startup::run(__VA_ARGS__); \
  } \
  auto __xtd_opaque_ftews__ = 0 // force to end with semicolon
