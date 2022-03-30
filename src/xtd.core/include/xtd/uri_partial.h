/// @file
/// @brief Contains Switch::System::UriPartial enum.
#pragma once

#include "ustring.h"

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
  
  /// @cond
  inline std::ostream& operator<<(std::ostream& os, const uri_partial value) {return os << to_string(value, { {uri_partial::scheme, "scheme"}, {uri_partial::authority, "authority"}, {uri_partial::path, "path"}, {uri_partial::query, "query"}});}
  inline std::wostream& operator<<(std::wostream& os, const uri_partial value) {return os << to_string(value, { {uri_partial::scheme, L"scheme"}, {uri_partial::authority, L"authority"}, {uri_partial::path, L"path"}, {uri_partial::query, L"query"}});}
  /// @endcond
}
