/// @file
/// @brief Contains stack_trace API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace diagnostics {
    class stack_frame;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains stack_trace native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ stack_trace final {
      stack_trace() = delete;
      friend xtd::diagnostics::stack_frame;
    protected:
      /// @name Protected aliaes
      
      /// @{
      /// @brief Represents a frame object that contains file name,line, column, method name and offset.
      using frame = std::tuple<std::string, size_t, size_t, std::string, size_t>;
      /// @brief Represents a frame collection.
      using frames = std::vector<frame>;
      /// @}

      /// @name Protected Static Methods
      
      /// @{
      /// @brief Play system sound.
      /// @param sound The sound to play (see souund.h).
      /// @warning Internal use only
      static frames get_frames(size_t skip_frames);
      /// @}
    };
  }
}
