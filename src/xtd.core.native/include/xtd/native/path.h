/// @file
/// @brief Contains path API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <csttdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains path native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ path final {
    protected:
      /// @brief Gets the current directory.
      /// @return The current directory.
      /// @warning Internal use only
      static std::string get_current_dirirectory();
      
      /// @brief Gets temp path.
      /// @return The temp path.
      /// @warning Internal use only
      static std::string get_temp_path();
    };
  }
}
