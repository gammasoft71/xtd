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
#include "scope_exit.hpp"
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
    /// @remarks `main_function` can be one of following signatures :
    /// * @verbatim auto main_function() -> void {} @endverbatim
    /// * @verbatim auto main_function() -> int {} @endverbatim
    /// * @verbatim auto main_function() -> xtd::threading::tasks::task<> {} @endverbatim
    /// * @verbatim auto main_function() -> xtd::threading::tasks::task<int> {} @endverbatim
    /// * @verbatim auto main_function() -> xtd::threading::tasks::wtask<> {} @endverbatim
    /// * @verbatim auto main_function() -> xtd::threading::tasks::wtask<int> {} @endverbatim
    ///
    /// * @verbatim auto main_function(const xtd::argument_collection& args) -> void {} @endverbatim
    /// * @verbatim auto main_function(const xtd::argument_collection& args) -> int {} @endverbatim
    /// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::task<> {} @endverbatim
    /// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::task<int> {} @endverbatim
    /// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::wtask<> {} @endverbatim
    /// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::wtask<int> {} @endverbatim
    ///
    /// * @verbatim auto main_function(int argc, char* argv[]) -> void {} @endverbatim
    /// * @verbatim auto main_function(int argc, char* argv[]) -> int {} @endverbatim
    /// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::task<> {} @endverbatim
    /// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::task<int> {} @endverbatim
    /// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::wtask<> {} @endverbatim
    /// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::wtask<int> {} @endverbatim
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
    template<typename main_function_t>
    [[nodiscard]] static auto run(main_function_t&& main_function) noexcept -> int {
      try {
        scope_exit_ {xtd::threading::thread::join_all();};
        return internal_run(std::forward<main_function_t>(main_function));
      } catch (const std::exception& e) {
        return xtd::exception::show_exception(e);
      } catch (...) {
        return xtd::exception::show_exception();
      }
    }
    /// @}
       
  private:
    [[nodiscard]] static auto args() noexcept -> xtd::argument_collection {
      static auto args = xtd::argument_collection {};
      if (!args.empty()) return args;
      const auto& command_line_args = xtd::environment::get_command_line_args();
      args = {command_line_args.begin() + 1, command_line_args.end()};
      return args;
    }

    [[nodiscard]] static auto argv_data() noexcept -> char** {return argv().data();}
    [[nodiscard]] static auto argv_length() noexcept -> int {return xtd::as<int>(argv().length());}
    [[nodiscard]] static auto argv() noexcept -> xtd::array<char*>& {
      static auto argv = xtd::array<char*> {};
      if (!argv.empty()) return argv;
      argv = array<char*>(xtd::environment::get_command_line_args().length());
      for (auto index = xtd::usize {0}; index < xtd::environment::get_command_line_args().length(); ++index)
        argv[index] = const_cast<char*>(xtd::environment::get_command_line_args()[index].data());
      return argv;
    }
    
    [[nodiscard]] static auto internal_run(xtd::callable<void> auto&& main_function) -> int {main_function(); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<int> auto&& main_function) -> int {return main_function();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::task<>> auto&& main_function) -> int {main_function().wait(); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::task<int>> auto&& main_function) -> int {return main_function().result();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<>> auto&& main_function) -> int {main_function(); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<int>> auto&& main_function) -> int {return main_function().result();}

    [[nodiscard]] static auto internal_run(xtd::callable<void, const xtd::argument_collection&> auto&& main_function) -> int {main_function(args()); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<int, const xtd::argument_collection&> auto&& main_function) -> int {return main_function(args());}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::task<>, const xtd::argument_collection&> auto&& main_function) -> int {main_function(args()).wait(); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::task<int>, const xtd::argument_collection&> auto&& main_function) -> int {return main_function(args()).result();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<>, const xtd::argument_collection&> auto&& main_function) -> int {main_function(args()); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<int>, const xtd::argument_collection&> auto&& main_function) -> int {return main_function(args()).result();}

    [[nodiscard]] static auto internal_run(xtd::callable<void, int, char* []> auto&& main_function) -> int {main_function(argv_length(), argv_data()); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<int, int, char* []> auto&& main_function) -> int {return main_function(argv_length(), argv_data());}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::task<>, int, char* []> auto&& main_function) -> int {main_function(argv_length(), argv_data()).wait(); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::task<int>, int, char* []> auto&& main_function) -> int {return main_function(argv_length(), argv_data()).result();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<>, int, char* []> auto&& main_function) -> int {main_function(argv_length(), argv_data()); return xtd::environment::exit_code();}
    [[nodiscard]] static auto internal_run(xtd::callable<xtd::threading::tasks::wtask<int>, int, char* []> auto&& main_function) -> int {return main_function(argv_length(), argv_data()).result();}
  };
}

/// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the main procedure that should run when the application starts.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param main_function The main function.
/// @par Implementation
/// ```cpp
/// auto main() -> int {
///   return xtd::startup::run(main_function);
/// }
/// ```
/// @remarks `main_function` can be one of following signatures :
/// * @verbatim auto main_function() -> void {} @endverbatim
/// * @verbatim auto main_function() -> int {} @endverbatim
/// * @verbatim auto main_function() -> xtd::threading::tasks::task<> {} @endverbatim
/// * @verbatim auto main_function() -> xtd::threading::tasks::task<int> {} @endverbatim
/// * @verbatim auto main_function() -> xtd::threading::tasks::wtask<> {} @endverbatim
/// * @verbatim auto main_function() -> xtd::threading::tasks::wtask<int> {} @endverbatim
///
/// * @verbatim auto main_function(const xtd::argument_collection& args) -> void {} @endverbatim
/// * @verbatim auto main_function(const xtd::argument_collection& args) -> int {} @endverbatim
/// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::task<> {} @endverbatim
/// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::task<int> {} @endverbatim
/// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::wtask<> {} @endverbatim
/// * @verbatim auto main_function(const xtd::argument_collection& args) -> xtd::threading::tasks::wtask<int> {} @endverbatim
///
/// * @verbatim auto main_function(int argc, char* argv[]) -> void {} @endverbatim
/// * @verbatim auto main_function(int argc, char* argv[]) -> int {} @endverbatim
/// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::task<> {} @endverbatim
/// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::task<int> {} @endverbatim
/// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::wtask<> {} @endverbatim
/// * @verbatim auto main_function(int argc, char* argv[]) -> xtd::threading::tasks::wtask<int> {} @endverbatim
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
  auto ___xtd_opaque_ftews___ = 0 // force to end with semicolon
