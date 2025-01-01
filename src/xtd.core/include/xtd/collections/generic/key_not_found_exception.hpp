/// @file
/// @brief Contains xtd::collections::generic::key_not_found_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../system_exception.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The exception that is thrown when the key specified for accessing an element in a collection does not match any key in the collection.
      /// ```cpp
      /// class key_not_found_exception : public xtd::system_exception
      /// ```
      /// @par Inheritance
      /// xtd::system_exception → xtd::collections::generic::key_not_found_exception
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/key_not_found_exception>
      /// ```
      /// @par Namespace
      /// xtd::collections
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core exceptions
      /// @par Examples
      /// The following example demonstrates how to throw and catch an key_not_found_exception.
      /// @include key_not_found_exception.cpp
      class key_not_found_exception : public xtd::system_exception {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Create a new instance of class key_not_found_exception
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @remarks Message is set with the default message associate to the exception.
        explicit key_not_found_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class key_not_found_exception
        /// @param message Message string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit key_not_found_exception(const xtd::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class key_not_found_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        template<typename exception_t>
        key_not_found_exception(const xtd::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::system_exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_KEYNOTFOUND));}
         /// @}
        
        /// @cond
        key_not_found_exception(const key_not_found_exception&) = default;
        key_not_found_exception& operator =(const key_not_found_exception&) = default;
        /// @endcond
      };
    }
  }
}
