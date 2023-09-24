/// @file
/// @brief Contains xtd::date_time_kind enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies whether a DateTime object represents a local time, a Coordinated Universal Time (UTC), or is not specified as either local time or UTC.
  /// @par Namespace
  /// xtd
  /// @par Header
  /// @code #include <xtd/date_time_kind> @endcode
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks A member of the xtd::date_time_kind enumeration is returned by the xtd::date_time::kind property.
  /// @remarks The members of the xtd::date_time_kind enumeration are used in conversion operations between local time and Coordinated Universal Time (UTC), but not in comparison or arithmetic operations.
  enum class date_time_kind {
    /// @brief The time represented is not specified as either local time or Coordinated Universal Time (UTC).
    unspecified,
    /// @brief The time represented is UTC.
    utc,
    /// @brief The time represented is local time.
    local,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::date_time_kind> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::date_time_kind> {{xtd::date_time_kind::unspecified, "unspecified"}, {xtd::date_time_kind::utc, "utc"}, {xtd::date_time_kind::local, "local"}};}
};
/// @endcond
