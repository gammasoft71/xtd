/// @file
/// @brief Contains xtd::source_location method.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "../internal/__xtd_source_location.h"
#undef __XTD_CORE_INTERNAL__
#include "../object.h"
#include "../ptr.h"
#include "../size.h"
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::source_location class represents certain information about the source code, such as file names, line numbers, and function names. Previously, functions that desire to obtain this information about the call site (for logging, testing, or debugging purposes) must use macros so that [predefined macros](https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros) like `__LINE__` and `__FILE__` are expanded in the context of the caller. The xtd::source_location class provides a better alternative.
  /// ```cpp
  /// class core_export_ source_location : public xtd::object
  /// ```
  /// @par Inheritance
  /// xtd::object → xtd::source_location
  /// @par Header
  /// ```cpp
  /// #include <xtd/source_location>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core debug
  /// @remarks The xtd::source_location is used by xtd::diagnostics::stack_frame and xtd::diagnostics::stack_trace.
  /// @remarks The xtd::source_location is same as [std::source_location](https://en.cppreference.com/w/cpp/utility/source_location).
  class core_export_ source_location : public xtd::object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::source_location class.
    source_location();
    /// @}
    
    /// @cond
    source_location(source_location&& other);
    source_location(const source_location& other);
    source_location& operator =(source_location&& other);
    source_location& operator =(const source_location& other);
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the column number represented by this object.
    /// @return The column number represented by this object.
    /// @remarks Returns 0 when the column number is unknown.
    xtd::size column() const noexcept;
    /// @brief Gets the name of the current source file represented by this object, represented as a null-terminated byte string.
    /// @return The name of the current source file represented by this object.
    /// @remarks Returns xtd::string::empty_string (`""`) when the source file is unknown.
    const xtd::string& file_name() const noexcept;
    /// @brief Gets the name of the function associated with the position represented by this object, if any.
    /// @return If this object represents a position in a body of a function, returns a string corresponding to the name of the function; otherwise, an xtd::string::empty_string (`""`) is returned.
    const xtd::string& function_name() const noexcept;
    /// @brief Gets the line number represented by this object.
    /// @return The line number represented by this object.
    /// @remarks Returns 0 when the line number is unknown.
    xtd::size line() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    xtd::string to_string() const noexcept override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Crates a new xtd::source_location object corresponding to the location of the call site.
    /// @return The currentsouce location informations.
    /// @remarks If xtd::source_location::current is invoked directly (via a function call that names xtd::source_location::current), it returns a source_location object with implementation-defined values representing the location of the call. The values should be affected by the [#line preprocessor directive](https://en.cppreference.com/w/cpp/preprocessor/line) in the same manner as the predefined macros `__LINE__` and `__FILE__`.
    /// @remarks If xtd::source_location::current is used in a [default member initializer](https://en.cppreference.com/w/cpp/language/data_members#Member_initialization), the return value corresponds to the location of the constructor definition or [aggregate initialization](https://en.cppreference.com/w/cpp/language/aggregate_initialization) that initializes the data member.
    /// @remarks If xtd::source_location::current is used in a default argument, the return value corresponds to the location of the call to xtd::source_location::current at the call site.
    /// @remarks If xtd::source_location::current is invoked in any other manner, the return value is unspecified.
    /// @note xtd::source_location::current typically requires compiler's built-in implementation.
    static source_location current(const __xtd_source_location__& value = __xtd_source_location__::current()) noexcept;
    /// @}
    
  private:
    source_location(const xtd::string& file, xtd::size line, const xtd::string& func, xtd::size column);
    struct data;
    xtd::ptr<data> data_;
  };
}
