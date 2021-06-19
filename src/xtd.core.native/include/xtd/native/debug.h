/// @file
/// @brief Contains debug API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "constant_special_item_id_list.h"
#include "environment_variable_target.h"
#include "platform_ids.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace diagnostics {
    class debug;
    class default_trace_listener;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains debug native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ debug final {
      friend xtd::diagnostics::debug;
      friend xtd::diagnostics::default_trace_listener;
    protected:
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param message The message to show in message box.
      static void assert_message_box(bool condition, const std::string& message);
      /// @brief Writes a specified message to the debuger output.
      /// @param message Message to write.
      /// @warning Internal use only
      static void write_to_output(const std::string& message);
    };
  }
}
