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
#include <string>
#include <vector>

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
      static int32_t gmt_time(time_t time, uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week);
      static bool is_daylight(time_t time);
      static int32_t local_time(time_t time, uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week);
      static time_t make_gmt_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second);
      static time_t make_local_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second);
      /// @}
    };
  }
}
