/// @file
/// @brief Contains xtd::uri_format enum.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Controls how URI information is escaped.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks This enumeration is used by the xtd::uri::get_components method to specify the level of character escaping in the returned URI.
  /// @remarks RFC 2396 defines the standard escaping for URIs, and is available at https://rfc-editor.org.
  /// @remarks xtd::uri_format::safe_unescaped leaves the following characters escaped if the character has a reserved meaning in the requested xtd::uri_components: "%", "#", "?", "/", "\", and "@".
  enum class uri_format {
    /// @brief Characters that have a reserved meaning in the requested URI components remain escaped. All others are not escaped. See Remarks.
    safe_unescaped = 0,
    /// @brief No escaping is performed.
    unescaped = 1,
    /// @brief Escaping is performed according to the rules in RFC 2396.
    uri_escaped = 2,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::uri_format> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::uri_format> {{xtd::uri_format::safe_unescaped, "safe_unescaped"}, {xtd::uri_format::unescaped, "unescaped"}, {xtd::uri_format::uri_escaped, "uri_escaped"}};}
};
/// @endcond
