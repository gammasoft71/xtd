/// @file
/// @brief Contains culture_info API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstddef>
#include <string>
#include <vector>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace globalization {
    class culture_info;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains culture_info native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ culture_info final {
      culture_info() = delete;
      friend xtd::globalization::culture_info;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Gets the current culture infi name.
      /// @return A std::string that contains the current culture name.
      /// @remarks The current culture is the locale name of the OS.
      /// @warning Internal use only
      static std::string current_name();
      /// @}
    };
  }
}
