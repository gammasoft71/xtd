/// @file
/// @brief Contains xtd::diagnostics::assert_dialog_result enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies identifiers to indicate the return value of an assert dialog box.
    /// @code
    /// enum class assert_dialog_result
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/assert_dialog_result> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::diagnostics::debug::show_assert_dialog method use this enumeration.
    enum class assert_dialog_result {
      /// @brief The assert dialog return value is Abort (usually sent from a button labeled Abort).
      abort = 3,
      /// @brief The assert dialog return value is Retry (usually sent from a button labeled Retry).
      retry = 4,
      /// @brief The assert dialog return value is Ignore (usually sent from a button labeled Ignore).
      ignore = 5,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::diagnostics::assert_dialog_result> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::assert_dialog_result> {{xtd::diagnostics::assert_dialog_result::abort, "abort"}, {xtd::diagnostics::assert_dialog_result::retry, "retry"}, {xtd::diagnostics::assert_dialog_result::ignore, "ignore"}};}
};
/// @endcond
