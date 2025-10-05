/// @file
/// @brief Contains xtd::globalization::culture_type enum class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../enum.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as xtd::globalization::string_info and xtd::globalization::text_info provide advanced globalization functionalities, including surrogate support and text element processing.
  namespace globalization {
    /// @brief Defines the types of culture lists that can be retrieved using the xtd::globalization::culture_info::get_cultures method.
    /// @par Header
    /// ```cpp
    /// #include <xtd/globalization/culture_type>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class culture_types {
      /// @brief Cultures that are associated with a language but are not specific to a country/region.
      neutral_cultures = 0b1,
      /// @brief Cultures that are specific to a country/region.
      specific_cultures = 0b10,
      /// @brief This member is deprecated. All cultures that are installed in the Windows operating system.
      installed_win32_cultures = 0b100,
      /// @brief All cultures that are recognized by xtd, including neutral and specific cultures and custom cultures created by the user.
      /// @remarks On xtd running on Windows, Linux and macOS, it includes culture data defined in the [ICU libraries](https://icu.unicode.org/).
      all_cultures = 0b111
    };
  }
}

/// @cond
flags_attribute_(xtd::globalization, culture_types);

template<> struct xtd::enum_register<xtd::globalization::culture_types> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::globalization::culture_types> { {xtd::globalization::culture_types::neutral_cultures, "neutral_cultures"}, {xtd::globalization::culture_types::specific_cultures, "specific_cultures"}, {xtd::globalization::culture_types::installed_win32_cultures, "installed_win32_cultures"}, {xtd::globalization::culture_types::all_cultures, "all_cultures"}};}
};
/// @endcond
