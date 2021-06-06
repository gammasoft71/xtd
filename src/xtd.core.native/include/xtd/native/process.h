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
#include <memory>
#include <string>
#include <tuple>

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
      /// @brief Creates a process with specified file name, specified arguments, specified process creation flags, specified working directory, and specified boolean tuples that represent redirect standard streams.
      /// @param file_name Message to write.
      /// @return The created process handle.
      /// @warning Internal use only
      static std::tuple<intptr_t, std::unique_ptr<std::ostream>, std::unique_ptr<std::istream>, std::unique_ptr<std::istream>> create(const std::string& file_name, const std::string& arguments, int32_t process_creation_flags, const std::string& working_directory, std::tuple<bool, bool, bool> redirect_standard_streams);
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
