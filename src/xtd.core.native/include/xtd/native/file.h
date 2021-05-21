/// @file
/// @brief Contains file API.
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
#include "file_attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains file native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ file final {
    protected:
      /// @brief Gets the file attributes.
      /// @param path A string containing the file path.
      /// @return The file attributes. (see file_attribute.h file).
      /// @warning Internal use only
      static int32_t get_file_attributes(const std::string& path);
    };
  }
}
