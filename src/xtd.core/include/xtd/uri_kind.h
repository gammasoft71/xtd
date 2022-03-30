/// @file
/// @brief Contains Switch::System::uri_kind enum.
#pragma once

#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the kinds of Uris for the xtd::uri::is_well_formed_uri_string and several xtd::uri methods.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks Absolute URIs are characterized by a complete reference to the resource (example: http://www.contoso.com/index.html), while a relative URI depends on a previously defined base URI (example: /index.html).
  /// @remarks The following list shows some APIs that use the xtd::uri_kind enum:
  /// * xtd::uri::uri(const xtd::utring&, xtd::uri_kind)
  /// * xtd::uri::is_well_formed_uri_string(const xtd::utring&, xtd::uri_kind)
  /// * xtd::uri::try_create(const xtd::utring&, xtd::uri_kind, xtd::uri&)
  enum class uri_kind {
    /// @brief The kind of the xtd::uri is indeterminate.
    relative_or_absolute = 0,
    /// @brief The xtd::uri is an absolute xtd::uri.
    absolute = 1,
    /// @brief The xtd::uri is a relative xtd::uri.
    relative = 2,
  };
  
  /// @cond
  inline std::ostream& operator<<(std::ostream& os, const uri_kind value) {return os << to_string(value, {{uri_kind::relative_or_absolute, "relative_or_absolute"}, {uri_kind::absolute, "absolute"}, {uri_kind::relative, "relative"}});}
  inline std::wostream& operator<<(std::wostream& os, const uri_kind value) {return os << to_string(value, {{uri_kind::relative_or_absolute, L"relative_or_absolute"}, {uri_kind::absolute, L"absolute"}, {uri_kind::relative, L"relative"}});}
  /// @endcond
}
