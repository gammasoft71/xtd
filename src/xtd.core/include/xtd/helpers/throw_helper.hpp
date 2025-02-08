/// @file
/// @brief Contains xtd::helpers::exception_case enum class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../internal/__xtd_source_location.hpp"
#include "exception_case.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::helpers namespace contains helpers for xtd objects, sush as exception static class.
  namespace helpers {
    /// @brief The xtd::helpers::throw_helper class is used to throw an exception in the xtd framework.
    /// @par Definition
    /// ```cpp
    /// class throw_helper;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/helpers/throw_helper>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core helpers
    /// @warning Internal use only
    class throw_helper {
    public:
      /// @brief Represents the internal source location type.
      /// @warning Internal use only
      using source_location = __xtd_source_location__;
      
      /// @cond
      throw_helper() = delete;
      /// @endcond
      
      /// @brief Throws an exption with specified exception case.
      /// @param ecase One of xtd::helpers::exception_case values.
      /// @warning Internal use only
      static void throws(xtd::helpers::exception_case ecase, const source_location& location = source_location::current());
      /// @brief Throws an exption with specified exception case, and message.
      /// @param ecase One of xtd::helpers::exception_case values.
      /// @param message The message associate to the exception.
      /// @warning Internal use only
      static void throws(xtd::helpers::exception_case ecase, const char* message, const source_location& location = source_location::current());
    };
  }
}
