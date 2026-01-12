/// @file
/// @brief Contains interlocked API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#define __XTD_VALUE_TYPE_NATIVE__
#include "value_types.hpp"
#undef __XTD_VALUE_TYPE_NATIVE__
#include "types.hpp"
#include <xtd/core_native_export>
#include <cstddef>
#include <ctime>
#include <cstdint>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace threading {
    class interlocked;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains interlocked native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ interlocked final {
    public:
    private:
      interlocked() = delete;
      
    protected:
      friend xtd::threading::interlocked;
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Adds two 32-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return std::int32_t The new value stored at location.
      /// @warning Internal use only
      static auto add(std::int32_t& location, std::int32_t value) -> std::int32_t;
      /// @brief Adds two 64-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return std::int64_t The new value stored at location.
      /// @warning Internal use only
      static auto add(int64_t& location, std::int64_t value) -> std::int64_t;
      
      /// @brief Compares two 32-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with Comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param Comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static auto compare_exchange(std::int32_t& location, std::int32_t value, std::int32_t comparand) -> std::int32_t;
      /// @brief Compares two 64-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static auto compare_exchange(int64_t& location, std::int64_t value, std::int64_t comparand) -> std::int64_t;
      /// @brief Compares two __slong__ signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static auto compare_exchange(__slong__& location, __slong__ value, __slong__ comparand) -> __slong__;
      /// @brief Compares two platform-specific handles or pointers for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static auto compare_exchange(void*& location, void* value, void* comparand) -> void*;
      
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      /// @warning Internal use only
      static auto decrement(std::int32_t& location) -> std::int32_t;
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      /// @warning Internal use only
      static auto decrement(int64_t& location) -> std::int64_t;
      
      /// @brief Sets a 32-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static auto exchange(std::int32_t& location, std::int32_t value) -> std::int32_t;
      /// @brief Sets a 64-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static auto exchange(int64_t& location, std::int64_t value) -> std::int64_t;
      /// @brief Sets a __slong__ signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static auto exchange(__slong__& location, __slong__ value) -> __slong__;
      /// @brief Sets a platform-specific handles or pointers to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static auto exchange(void*& location, void* value) -> void*;
      
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      /// @warning Internal use only
      static auto increment(std::int32_t& location) -> std::int32_t;
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      /// @warning Internal use only
      static auto increment(int64_t& location) -> std::int64_t;
      /// @}
    };
  }
}
