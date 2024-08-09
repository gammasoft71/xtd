/// @file
/// @brief Contains xtd::memory_information class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "core_export.h"
#include "size.h"
#include "static.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about the memory. This class is static.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system system_information
  /// @par Examples
  /// The following example shows how to retrieve some information about the memory.
  /// @include memory_information.cpp
  class core_export_ memory_information static_ {
  public:
   
    /// @name Public Static Methods
    
    /// @{
    /// @brief Gets the the free physical memory in bytes.
    /// @return The free physical memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    /// @remarks The free physical memory is equal to xtd::memory_information::get_total_physical_memory minus xtd::memory_information::get_used_physical_memory.
    static xtd::size get_free_physical_memory() noexcept;
    
    /// @brief Gets the the free process memory in bytes.
    /// @return The free process memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    /// @remarks The free process memory is equal to xtd::memory_information::get_total_process_memory minus xtd::memory_information::get_used_process_memory.
    static xtd::size get_free_process_memory() noexcept;

    /// @brief Gets the the free virtual memory in bytes.
    /// @return The free virtual memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    /// @remarks The free virtual memory is equal to xtd::memory_information::get_total_virtual_memory minus xtd::memory_information::get_used_virtual_memory.
    static xtd::size get_free_virtual_memory() noexcept;

    /// @brief Gets the the total physical memory in bytes.
    /// @return The total physical memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    /// @remarks The total physical memory corresponds to the amount of RAM on the computer or the amount of RAM allocated to the virtual machine in the case of virtualisation.
    static xtd::size get_total_physical_memory() noexcept;
    
    /// @brief Gets the the total physical memory in bytes.
    /// @return The total process memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    /// @remarks There is no strict predefined limit on the amount of memory an individual process can use
    /// @remarks Some OS allow you to set resource usage limits for processes using the ulimit command. For example, a user or system administrator can set a memory limit for a particular process.
    /// @remarks If the user has specified a limit, then the total memory will be equal to this limit; otherwise it will be equal to xtd::memory_information::get_free_virtual_memory.
    static xtd::size get_total_process_memory() noexcept;
    
    /// @brief Gets the the total virtual memory in bytes.
    /// @return The total virtual memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    /// @remarks Each OS has its own way of managing and allocating virtual memory.
    /// @remarks It is possible that the OS has no virtual memory, in which case the method will return 0.
    static xtd::size get_total_virtual_memory() noexcept;

    /// @brief Gets the the used physical memory information in bytes.
    /// @return The used physical memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    static xtd::size get_used_physical_memory() noexcept;
    
    /// @brief Gets the the used physical memory in bytes.
    /// @return The used process memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    static xtd::size get_used_process_memory() noexcept;
    
    /// @brief Gets the the used virtual memory in bytes.
    /// @return The used virtual memory value.
    /// @par Examples
    /// The following example shows how to retrieve some information about the memory.
    /// @include memory_information.cpp
    static xtd::size get_used_virtual_memory() noexcept;
    /// @}
  };
}
