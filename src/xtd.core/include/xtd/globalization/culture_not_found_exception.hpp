/// @file
/// @brief Contains xtd::globalization::culture_not_found_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../system_exception.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as xtd::globalization::string_info and xtd::globalization::text_info provide advanced globalization functionalities, including surrogate support and text element processing.
  namespace globalization {
    /// @brief The exception that is thrown when the key specified for accessing an element in a collection does not match any key in the collection.
    /// ```cpp
    /// class culture_not_found_exception : public xtd::system_exception
    /// ```
    /// @par Inheritance
    /// xtd::system_exception → xtd::globalization::culture_not_found_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/globalization/culture_not_found_exception>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core globalization
    /// @par Examples
    /// The following example demonstrates how to throw and catch an culture_not_found_exception.
    /// @include culture_not_found_exception.cpp
    class core_export_ culture_not_found_exception : public xtd::system_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class culture_not_found_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      explicit culture_not_found_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class culture_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit culture_not_found_exception(const xtd::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class culture_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      template<class exception_t>
      culture_not_found_exception(const xtd::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::system_exception(message == xtd::nullopt ? get_default_message() : message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_ARGUMENT));}
      /// @}
      
      /// @cond
      culture_not_found_exception(const culture_not_found_exception&) = default;
      culture_not_found_exception& operator =(const culture_not_found_exception&) = default;
      /// @endcond
      
    private:
      static const xtd::string& get_default_message();
    };
  }
}
