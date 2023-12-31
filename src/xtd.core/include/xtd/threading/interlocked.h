/// @file
/// @brief Contains xtd::threading::interlocked class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../lock.h"
#include "../object.h"
#include "../static.h"
#include "../types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides atomic operations for variables that are shared by multiple threads.
    /// @code
    /// class core_export_ interlocked static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::threading::interlocked
    /// @par Header
    /// @code #include <xtd/threading/interlocked> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks The methods of this class help protect against errors that can occur when the scheduler switches contexts while a thread is updating a variable that can be accessed by other threads, or when two threads are executing concurrently on separate processors. The members of this class do not throw exceptions.
    /// @remarks The xtd::threading::interlocked::increment and xtd::threading::interlocked::decrement methods increment or decrement a variable and store the resulting value in a single operation. On most computers, incrementing a variable is not an atomic operation, requiring the following steps:
    /// @remarks   1. Load a value from an instance variable into a register.
    /// @remarks   2. Increment or decrement the value.
    /// @remarks   3. Store the value in the instance variable.
    /// @remarks If you do not use xtd::threading::interlocked::increment and xtd::threading::interlocked::decrement, a thread can be preempted after executing the first two steps. Another thread can then execute all three steps. When the first thread resumes execution, it overwrites the value in the instance variable, and the effect of the increment or decrement performed by the second thread is lost.
    /// @remarks The xtd::threading::exchange method atomically exchanges the values of the specified variables. The compare_exchange method combines two operations: comparing two values and storing a third value in one of the variables, based on the outcome of the comparison. The compare and exchange operations are performed as an atomic operation.
    /// @par Examples
    /// The following code example shows a thread-safe resource locking mechanism.
    /// @include interlocked.cpp
    class core_export_ interlocked static_ {
    public:
      /// @brief Adds two 32-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return int32 The new value stored at location.
      static int32 add(int32& location, int32 value) noexcept;
      /// @brief Adds two 64-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return int64 The new value stored at location.
      static int64 add(int64& location, int64 value) noexcept;
      
      /// @brief Compares two Double for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static double compare_exchange(double& location, double value, double comparand) noexcept;
      /// @brief Compares two 32-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with Comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param Comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static int32 compare_exchange(int32& location, int32 value, int32 comparand) noexcept;
      /// @brief Compares two 64-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static int64 compare_exchange(int64& location, int64 value, int64 comparand) noexcept;
      /// @cond
      static slong compare_exchange(slong& location, slong value, slong comparand) noexcept;
      /// @endcond
      /// @brief Compares two platform-specific handles or pointers for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static void* compare_exchange(void*& location, void* value, void* comparand) noexcept;
      /// @brief Compares two objects for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      template<typename type_t>
      static type_t compare_exchange(object& location, const object& value, const object& comparand) noexcept {
        type_t retValue = location;
        lock_(location) {
          if (location.equals(comparand)) location = value;
        }
        return retValue;
      }
      /// @brief Compares two instances of the specified reference type type_t for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      template<typename type_t>
      static type_t compare_exchange(type_t& location, type_t value, type_t comparand) noexcept {
        type_t retValue = location;
        lock_(location) {
          if (location == comparand) location = value;
        }
        return retValue;
      }
      /// @brief Compares two Single for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static float compare_exchange(float& location, float value, float comparand) noexcept;
      
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      /// @par Examples
      /// The following code example shows a thread-safe way to increment and decrement an integer value. SafeInstanceCount will always be zero. However, UnsafeInstanceCount will not necessarily be zero because a race condition occurs between incrementing and decrementing the count. This effect is especially marked on a multiprocessor computer.
      /// @include interlocked_decrement.cpp
      static int32 decrement(int32& location) noexcept;
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      static int64 decrement(int64& location) noexcept;
      
      /// @brief Sets a variable of the specified type type_t to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      template<typename type_t>
      static type_t exchange(type_t& location, type_t value) {
        type_t original = location;
        lock_(location)
          location = value;
        return original;
      }
      /// @brief Sets a double-precision floating point number to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location_d parameter is set.
      /// @return The original value of location_d.
      static double exchange(double& location, double value) noexcept;
      /// @brief Sets a 32-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @par Examples
      /// The following code example shows a thread-safe resource locking mechanism.
      /// @include interlocked.cpp
      static int32 exchange(int32& location, int32 value) noexcept;
      /// @brief Sets a 64-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      static int64 exchange(int64& location, int64 value) noexcept;
      /// @cond
      static slong exchange(slong& location, slong value) noexcept;
      /// @endcond
      /// @brief Sets a platform-specific handles or pointers to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      static void* exchange(void*& location, void* value) noexcept;
      /// @brief Sets an object to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      template<typename type_t>
      static type_t exchange(object& location, const object& value) noexcept {
        type_t original = location;
        lock_(location)
          location = value;
        return original;
      }
      /// @brief Sets a double-precision floating point number to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location_f parameter is set.
      /// @return The original value of location_f.
      static float exchange(float& location, float value) noexcept;
      
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      /// @par Examples
      /// The following code example shows a thread-safe way to increment and decrement an integer value. SafeInstanceCount will always be zero. However, UnsafeInstanceCount will not necessarily be zero because a race condition occurs between incrementing and decrementing the count. This effect is especially marked on a multiprocessor computer.
      /// @include interlocked_decrement.cpp
      static int32 increment(int32& location) noexcept;
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      static int64 increment(int64& location) noexcept;
      
      /// @brief Synchronizes memory access as follows: The processor that executes the current thread cannot reorder instructions in such a way that memory accesses before the call to xtd::threading::interlocked::memory_barrier execute after memory accesses that follow the call to xtd::threading::interlocked::memory_barrier.
      /// @remarks This method was added to the xtd::threading::interlocked class as a convenience; it's a wrapper for the xtd::threading::thread::memory_barrier method.
      /// @remarks xtd::threading::interlocked::memory_barrier is required only on multiprocessor systems that have weak memory ordering (for example, a system that employs multiple Intel Itanium processors).
      /// @remarks For most purposes, the lock_ statement, or the Monitor class provide easier ways to synchronize data.
      static void memory_barrier() noexcept;
      
      /// @brief Returns a 64-bit value, loaded as an atomic operation.
      /// @param location The 64-bit value to be loaded.
      /// @return The loaded value.
      static int64 read(int64& location) noexcept;
      
    private:
    };
  }
}
