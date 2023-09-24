/// @file
/// @brief Contains xtd::uri_partial enum.
#pragma once
#include "enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the parts of a URI for the xtd::uri::get_left_part method.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The xtd::uri_partial enumeration defines the values that can be passed to the xtd::uri::get_lLeft_part method.
  enum class uri_partial {
    /// @brief The scheme segment of the URI.
    scheme = 0,
    /// @brief The scheme and authority segments of the URI.
    authority = 1,
    /// @brief The scheme, authority, and path segments of the URI.
    path = 2,
    /// @brief The scheme, authority, path, and query segments of the URI.
    query = 3,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::uri_partial> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::uri_partial> {{xtd::uri_partial::scheme, "scheme"}, {xtd::uri_partial::authority, "authority"}, {xtd::uri_partial::path, "path"}, {xtd::uri_partial::query, "query"}};}
};
/// @endcond
