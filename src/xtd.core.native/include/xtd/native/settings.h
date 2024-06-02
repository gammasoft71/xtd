/// @file
/// @brief Contains xtd::native::settings API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/core_native_export.h>

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
    /// @remarks On Windows settings are stored in registry with "HKEY_CURRENT_USER\Software\company_name\product_name" key.
    /// @remarks On macos settings are stored in "~/Library/Preferences/product_name Preferences" file.
    /// @remarks On linux settings are stored in "~/.product_name" file.
    /// @warning Internal use only
    class core_native_export_ settings final static_ {
      friend xtd::configuration::settings;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Gets settings path from product name and company name.
      /// @param company_name The company name to make the settings path.
      /// @param product_name The product name to make the settings path.
      /// @return A string that represents the settings path.
      /// @remarks On Windows settings are stored in "application_path/product_name.ini" file.
      /// @remarks On macos settings are stored in "~/Library/Preferences/company_name/product_name Preferences" file.
      /// @remarks On linux settings are stored in "~/.consig/company_name/product_name.conf" file.
      /// @warning Internal use only
      static std::string get_path(const std::string& company_name, const std::string& product_name);
      /// @}
    };
  }
}
