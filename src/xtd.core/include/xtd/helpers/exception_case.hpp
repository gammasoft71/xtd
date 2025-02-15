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
      /// @brief The mutex is abandoned.
      abandoned_mutex,
      /// @brief The argument is not valid.
      argument,
      /// @brief The argument is null.
      argument_null,
      /// @brief The argument is out of range.
      argument_out_of_range,
      /// @brief The post-phase action of a xtd::threading::barrier fails.
      barrier_post_phase,
      /// @brief The directory is not found.
      directory_not_found,
      /// @brief The end of stream is reached.
      end_of_stream,
      /// @brief The file is not found.
      file_not_found,
      /// @brief The format is not valid.
      format,
      /// @brief The format contains close backet_without_open_bracket.
      format_closing_bracket_without_open_bracket,
      /// @brief The format contains open backet_without_end_bracket.
      format_opened_bracket_without_end_bracket,
      /// @brief The format does not contains start colon.
      format_no_start_colon,
      /// @brief The object is not iformatable.
      format_not_iformatable,
      /// @brief The index is out of range.
      index_out_of_range,
      /// @brief The cast is not valid.
      invalid_cast,
      /// @brief The operation is not valid.
      invalid_operation,
      /// @brief I/O erreror occurs.
      io,
      /// @brief The key is not found.
      key_not_found,
      /// @brief The method or operation is not implemented.
      not_implemented,
      /// @brief The method or operation is not supported.
      not_supported,
      /// @brief The pointer is null.
      null_pointer,
      /// @brief The object is closed.
      object_closed,
      /// @brief The operation is canceled.
      operation_canceled,
      /// @brief Arithmetic overflow.
      overflow,
      /// @brief The path is too long.
      path_too_long,
      /// @brief The platform is not supported.
      platform_not_supported,
      /// @brief The rank is not valid.
      rank,
      /// @brief The access is denied.
      unauthorized_access,
    };
  }
}
