/// @file
/// @brief Contains interlocked API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "types"
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
      /// @name Protected methods
      
      /// @{
      /// @brief Adds two 32-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return int_least32_t The new value stored at location.
      /// @warning Internal use only
      static int_least32_t add(int_least32_t& location, int_least32_t value);
      /// @brief Adds two 64-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return int_least64_t The new value stored at location.
      /// @warning Internal use only
      static int_least64_t add(int_least64_t& location, int_least64_t value);
      
      /// @brief Compares two 32-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with Comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param Comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static int_least32_t compare_exchange(int_least32_t& location, int_least32_t value, int_least32_t comparand);
      /// @brief Compares two 64-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static int_least64_t compare_exchange(int_least64_t& location, int_least64_t value, int_least64_t comparand);
      /// @brief Compares two __slong__ signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static __slong__ compare_exchange(__slong__& location, __slong__ value, __slong__ comparand);
      /// @brief Compares two platform-specific handles or pointers for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      /// @warning Internal use only
      static void* compare_exchange(void*& location, void* value, void* comparand);
      
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      /// @warning Internal use only
      static int_least32_t decrement(int_least32_t& location);
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      /// @warning Internal use only
      static int_least64_t decrement(int_least64_t& location);
      
      /// @brief Sets a 32-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static int_least32_t exchange(int_least32_t& location, int_least32_t value);
      /// @brief Sets a 64-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static int_least64_t exchange(int_least64_t& location, int_least64_t value);
      /// @brief Sets a __slong__ signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static __slong__ exchange(__slong__& location, __slong__ value);
      /// @brief Sets a platform-specific handles or pointers to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @warning Internal use only
      static void* exchange(void*& location, void* value);
      
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      /// @warning Internal use only
      static int_least32_t increment(int_least32_t& location);
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      /// @warning Internal use only
      static int_least64_t increment(int_least64_t& location);
      /// @}
    };
  }
}
