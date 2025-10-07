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
    namespace tests {
      class culture_info_tests;
    }
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
      friend xtd::globalization::tests::culture_info_tests;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Gets the current locale name.
      /// @return A std::string that contains the current locale name.
      /// @warning Internal use only
      static std::string current_locale_name();
      
      /// @brief Gets system locale names.
      /// @return A std::vector<std::string> that contains the system locale names.
      /// @warning Internal use only
      static std::vector<std::string> system_locale_names();
      /// @}
    };
  }
}
