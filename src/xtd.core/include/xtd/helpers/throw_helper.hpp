/// @file
/// @brief Contains xtd::helpers::throw_helper class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../internal/__xtd_source_location.hpp"
#include "../type.hpp"
#include "exception_case.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace net {
    namespace sockets {
      enum class socket_error;
    }
  }
  /// @endcond
  
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
    class throw_helper {
    public:
      /// @brief Represents the internal source location type.
      /// @warning Internal use only
      using source_location = __xtd_source_location__;
      
      /// @cond
      throw_helper() = delete;
      /// @endcond
      
      /// @brief Throws an exption with specified exception case.
      /// @param exception_case One of xtd::helpers::exception_case values.
      [[noreturn]] static void throws(xtd::helpers::exception_case exception_case, const source_location& location = source_location::current());
      /// @brief Throws an exption with specified exception case, and message.
      /// @param exception_case One of xtd::helpers::exception_case values.
      /// @param message The message associate to the exception.
      [[noreturn]] static void throws(xtd::helpers::exception_case exception_case, const char* message, const source_location& location = source_location::current());
      /// @brief Throws an exption with specified exception case, and message.
      /// @param exception_case The xtd::helpers::exception_case::format_not_iformatable value.
      /// @param type The type associate to the exception.
      /// @remarks This overload can only be used with the xtd::helpers::exception_case::format_not_iformatable value.
      [[noreturn]] static void throws(xtd::helpers::exception_case exception_case, const xtd::type& type, const source_location& location = source_location::current());
      /// @brief Throws an exption with specified exception case, and message.
      /// @param exception_case The xtd::helpers::exception_case::format_not_iformatable value.
      /// @param type The type associate to the exception.
      /// @remarks This overload can only be used with the xtd::helpers::exception_case::socket value.
      [[noreturn]] static void throws(xtd::helpers::exception_case exception_case, const xtd::net::sockets::socket_error& error, const source_location& location = source_location::current());
    };
  }
}
