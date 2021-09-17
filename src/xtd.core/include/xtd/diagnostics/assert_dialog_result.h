/// @file
/// @brief Contains xtd::diagnostics::assert_dialog_result enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
  /// @brief Specifies identifiers to indicate the return value of an assertt dialog box.
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
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, assert_dialog_result value) {return os << to_string(value, {{assert_dialog_result::abort, "abort"}, {assert_dialog_result::retry, "retry"}, {assert_dialog_result::ignore, "ignore"}});}
    inline std::wostream& operator<<(std::wostream& os, assert_dialog_result value) {return os << to_string(value, {{assert_dialog_result::abort, L"abort"}, {assert_dialog_result::retry, L"retry"}, {assert_dialog_result::ignore, L"ignore"}});}
    /// @endcond
  }
}
