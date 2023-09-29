/// @file
/// @brief Contains xtd::uri_kind enum.
#pragma once
#include "enum.h"

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
}

/// @cond
template<> struct xtd::enum_register<xtd::uri_kind> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::uri_kind> {{xtd::uri_kind::relative_or_absolute, "relative_or_absolute"}, {xtd::uri_kind::absolute, "absolute"}, {xtd::uri_kind::relative, "relative"}};}
};
/// @endcond
