/// @file
/// @brief Contains #scope_success_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <utility>
#define __XTD_CORE_INTERNAL__
#include "internal/__xtd_scope.hpp"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Nowadays, every C++ developer is familiar with the Resource Acquisition Is Initialization ([RAII](https://en.cppreference.com/w/cpp/language/raii)) technique. It binds resource acquisition and release to initialization and destruction of a variable that holds the resource. There are times when writing a special class for such a variable is not worth the effort. This is when xtd xtd::scope_success comes into play. xtd::scope_success is executed only if no exception
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks #scope_exit_, #scope_success_ and #scope_fail_ are themselves RAII utilities.
  /// @remarks They are designed to make scope-based cleanup and control flow more concise and expressive.
  /// @remarks See also #scope_success_ keyword helper.
  ///
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto main() -> int {
  ///   try {
  ///     scope_exit_ {
  ///       console::write_line("always (scope_exit)");
  ///     };
  ///     scope_success_ {
  ///       console::write_line("only on success (scope_success)");
  ///     };
  ///     scope_fail_ {
  ///       console::write_line("only on failure (scope_fail)");
  ///     };
  ///
  ///     console::write_line("begin");
  ///     // ...
  ///     console::write_line("do something...");
  ///     // Remove the comment from the following line to test failure
  ///     //throw invalid_operation_exception {};
  ///     // ...
  ///     console::write_line("end normally");
  ///   } catch (...) {
  ///     console::write_line("caught exception!");
  ///   }
  /// }
  ///
  /// // This code produces the following output if success :
  /// //
  /// // begin
  /// // do something...
  /// // end normally
  /// // only on success (scope_success)
  /// // always (scope_exit)
  ///
  /// // This code produces the following output if throws exception :
  /// //
  /// // begin
  /// // do something...
  /// // only on failure (scope_fail)
  /// // always (scope_exit)
  /// // caught exception!
  /// ```
  struct scope_success { };
  
  /// @cond
  template<typename function_t>
  auto operator+(scope_success, function_t&& function) {
    return __xtd_scope_success_object__<function_t> {std::forward<function_t>(function)};
  }
  /// @endcond
}

/// @brief Nowadays, every C++ developer is familiar with the Resource Acquisition Is Initialization ([RAII](https://en.cppreference.com/w/cpp/language/raii)) technique. It binds resource acquisition and release to initialization and destruction of a variable that holds the resource. There are times when writing a special class for such a variable is not worth the effort. This is when xtd #scope_success_ comes into play. #scope_success_ is executed only if no exception
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks #scope_exit_, #scope_success_ and #scope_fail_ are themselves RAII utilities.
/// @remarks They are designed to make scope-based cleanup and control flow more concise and expressive.
/// @remarks See also xtd::scope_success struct.
///
/// ```cpp
/// #include <xtd/xtd>
///
/// auto main() -> int {
///   try {
///     scope_exit_ {
///       console::write_line("always (scope_exit)");
///     };
///     scope_success_ {
///       console::write_line("only on success (scope_success)");
///     };
///     scope_fail_ {
///       console::write_line("only on failure (scope_fail)");
///     };
///
///     console::write_line("begin");
///     // ...
///     console::write_line("do something...");
///     // Remove the comment from the following line to test failure
///     //throw invalid_operation_exception {};
///     // ...
///     console::write_line("end normally");
///   } catch (...) {
///     console::write_line("caught exception!");
///   }
/// }
///
/// // This code produces the following output if success :
/// //
/// // begin
/// // do something...
/// // end normally
/// // only on success (scope_success)
/// // always (scope_exit)
///
/// // This code produces the following output if throws exception :
/// //
/// // begin
/// // do something...
/// // only on failure (scope_fail)
/// // always (scope_exit)
/// // caught exception!
/// ```
#define scope_success_ [[maybe_unused]] auto __xtd_scope_id__(__xtd__scope_success__, __LINE__) = xtd::scope_success{} + [&]
