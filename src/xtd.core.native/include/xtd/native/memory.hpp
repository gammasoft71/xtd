/// @file
/// @brief Contains memory API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "constant_special_item_id_list.hpp"
#include "environment_variable_target.hpp"
#include "platform_ids.hpp"
#include <xtd/core_native_export>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class memory_information;
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains memory native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ memory final {
      memory() = delete;
      friend xtd::memory_information;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Gets the total physical memory in bytes.
      /// @return The total physical memory value.
      /// @warning Internal use only
      static size_t get_total_physical_memory();
      /// @brief Gets the total process memory in bytes.
      /// @return The total process memory value.
      /// @warning Internal use only
      static size_t get_total_process_memory();
      /// @brief Gets the total virtual memory in bytes.
      /// @return The total virtual memory value.
      /// @warning Internal use only
      static size_t get_total_virtual_memory();
      
      /// @brief Gets the used physical memory in bytes.
      /// @return The used physical memory value.
      /// @warning Internal use only
      static size_t get_used_physical_memory();
      /// @brief Gets the used process memory in bytes.
      /// @return The used process memory value.
      /// @warning Internal use only
      static size_t get_used_process_memory();
      /// @brief Gets the used virtual memory in bytes.
      /// @return The used virtual memory value.
      /// @warning Internal use only
      static size_t get_used_virtual_memory();
      /// @}
    };
  }
}
