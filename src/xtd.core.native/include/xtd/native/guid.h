/// @file
/// @brief Contains guid API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "constant_special_item_id_list"
#include "environment_variable_target"
#include "platform_ids"
#include <xtd/core_native_export>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  struct guid;
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
      guid() = delete;
      friend xtd::guid;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Generates a globally unique identifier (GUID).
      /// @return A 16-element byte array containing GUID.
      /// @remarks A GUID is a 128-bit integer (16 bytes) that can be used across all computers and networks wherever a unique identifier is required. Such an identifier has a very low probability of being duplicated.
      /// @warning Internal use only
      static std::vector<uint_least8_t> new_guid();
      /// @}
    };
  }
}
