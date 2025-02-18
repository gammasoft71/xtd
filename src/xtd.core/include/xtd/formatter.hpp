/// @file
/// @brief Contains xtd::enum_object struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "internal/__formatter.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Provides the base class to format any object.
  /// ```cpp
  /// template <class type_t>
  /// struct formatter;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/formatter>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about format, see [Format number, dates other types](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/overview) guide.
  template <class type_t>
  struct formatter {
    xtd::string operator()(const type_t& value, const xtd::string& format, const std::locale& locale) {
      return __polymorphic_formatter__(value, format, locale, std::is_polymorphic<type_t>());
    }
  };
}
