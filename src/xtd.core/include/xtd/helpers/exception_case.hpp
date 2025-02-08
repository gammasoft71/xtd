/// @file
/// @brief Contains xtd::helpers::exception_case enum class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::helpers namespace contains helpers for xtd objects, sush as exception static class.
  namespace helpers {
    /// @brief Represents the exception case used by the xtd::helpers::exception helper class.
    /// @par Definition
    /// ```cpp
    /// enum class exception_case;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/helpers/exception_case>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core helpers
    /// @warning Internal use only
    enum class exception_case {
      /// @brief The argument is not valid.
      argument,
      /// @brief The argument is null.
      argument_null,
      /// @brief The argument is out of range.
      argument_out_of_range,
      /// @brief The format is not valid.
      format,
      /// @brief The format does not contains close backet.
      format_no_close_bracket,
      /// @brief The format does not contains open backet.
      format_no_open_bracket,
      /// @brief The format does not contains start colon.
      format_no_start_colon,
      /// @brief The index is out of range.
      index_out_of_range,
      /// @brief The operation is not valid.
      invalid_operation,
      /// @brief The pointer is null.
      null_pointer,
      /// @brief The rank is not valid.
      rank,
    };
  }
}
