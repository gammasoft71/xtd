/// @file
/// @brief Contains xtd::native::settings API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <xtd/core_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace configuration {
    class settings;
  }
  /// @endcond

  /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains settings native API.
    /// @par Namespace
    /// xtd::forms::native
    /// @par Library
    /// xtd.forms.native
    /// @ingroup xtd_forms_native native
    /// @warning Internal use only
    class core_native_export_ settings final {
      friend xtd::configuration::settings;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Gets settings path from product name and company name.
      /// @return A string that represents the settings file extension :
      /// @remarks * ".ini" on Windows
      /// @remarks * " Preferences" on macos.
      /// @remarks * ".conf" on linux.
      /// @warning Internal use only
      static std::string get_file_extension();
      /// @}
    };
  }
}
