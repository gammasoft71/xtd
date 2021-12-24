/// @file
/// @brief Contains date time API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstddef>
#include <ctime>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class date_time;
  /// @endcond

  /// @internal
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @internal
    /// @brief Contains date time native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ date_time final {
      date_time() = delete;
      friend xtd::date_time;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @internal
      /// @brief Indicates whether the ttime_t is within the daylight saving time range for the current time zone.
      /// @return true if the time is within the daylight saving time range for the local time zone; otherwise false.
      /// @warning Internal use only
      static bool is_daylight(std::time_t time);
      /// @}
    };
  }
}
