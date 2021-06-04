/// @file
/// @brief Contains process API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace diagnostics {
    class process;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains process native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ process final {
      friend xtd::diagnostics::process;
    protected:
      /// @brief Creates a process with specified command line.
      /// @param command_line Message to write.
      /// @return The created process handle.
      /// @warning Internal use only
      static intptr_t create(const std::string& file_name, const std::string& arguments, int32_t process_creation_flags);
      /// @brief Kill process.
      /// @param process The process handle to kill.
      /// @warning Internal use only
      static bool kill(intptr_t process);
      /// @brief Wait process.
      /// @param process The process handle to kill.
      /// @param exit Receives the process exit code.
      /// @warning Internal use only
      static bool wait(intptr_t process, int32_t& exit_code);
    };
  }
}
