/// @file
/// @brief Contains xtd::iformatable interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "generic_stream_output.hpp"
#include "interface.hpp"
//#include "globalization/culture_info.hpp"
#include <locale>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace globalization {
    class culture_info;
  }
  /// @endcond
  
  /// @brief Provides functionality to format the value of an object into a string representation.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @remarks The xtd::iformattable interface converts an object to its string representation based on a format string and a locale.
  /// @remarks A format string typically defines the general appearance of an object. For example, the xtd framework supports the following:
  /// @remarks * Standard format strings for formatting enumeration values (see [Enumeration Format Strings]()).
  /// @remarks * Standard and custom format strings for formatting numeric values (see [Standard Numeric Format Strings]() and [Custom Numeric Format Strings]()).
  /// @remarks * Standard and custom format strings for formatting date and time values (see [Standard Date and Time Format Strings]() and [Custom Date and Time Format Strings]()).
  /// @remarks * Standard and custom format strings for formatting time intervals (see [Standard time_span Format Strings]() and [Custom TimeSpan Format Strings]()).
  /// @remarks You can also define your own format strings to support formatting of your application-defined types.
  /// @remarks The xtd::iformattable interface defines a single method, xtd::iformatable::to_string, that supplies formatting services for the implementing type. The xtd::iformatable::to_string method can be called directly. In addition, it is called automatically by the xtd::convert.to_string methods, and by methods that use the composite formatting feature in the xtd framework. Such methods include xtd::console::write_line, xtd::string::format, and xtd::text::string_builder::apend_format, among others. The ToString method is called for each format item in the method's format string.
  /// @remarks The xtd::iformattable interface is implemented by the base data types.
  /// @par Notes to Implementers
  /// Classes that require more control over the formatting of strings than xtd::iformattable::to_string() provides should implement xtd::iformattable.
  /// A class that implements xtd::iformattable must support the "G" (general) format specifier. Besides the "G" specifier, the class can define the list of format specifiers that it supports. In addition, the class must be prepared to handle a format specifier that is null. For more information about formatting and formatting codes, see [Formatting Type]()s
  /// @par Examples
  /// The following example shows how to use xtd::iformatable interface.
  /// @include iformatable.cpp
  class iformatable interface_ {
  public:
    /// @name Public Methods
    
    /// @{
    /// @brief Formats the value of the current instance using the specified format.
    /// @param format The format to use <br>-or-<br> A xtd::string::empty_string ("") to use the default format defined for the type of the xtd::iformattable implementation.
    /// @param culture An xtd::globalization::culture_info object that contains culture information.
    /// @return The value of the current instance in the specified format.
    virtual xtd::string to_string(const xtd::string& format, const globalization::culture_info& culture) const = 0;
    /// @}
  };
}
