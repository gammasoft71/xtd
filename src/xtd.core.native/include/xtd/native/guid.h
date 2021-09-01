/// @file
/// @brief Contains guid API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "constant_special_item_id_list.h"
#include "environment_variable_target.h"
#include "platform_ids.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class guid;
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains guid native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ guid final {
      friend xtd::guid;
    protected:
      /// @brief Generates a globally unique identifier (GUID).
      /// @return A 16-element byte array containing GUID.
      /// @remarks A GUID is a 128-bit integer (16 bytes) that can be used across all computers and networks wherever a unique identifier is required. Such an identifier has a very low probability of being duplicated.
      /// @warning Internal use only
      static std::vector<uint8_t> new_guid();
    };
  }
}
