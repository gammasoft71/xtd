/// @file
/// @brief Contains path API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/core_native_export.h>
#include <csttdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::core::native namespace contains internal native API definitions to access underlying oerating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains path native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ path final {
    public:
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
