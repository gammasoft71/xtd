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
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class date_time;
  class time_zone_info;
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
    public:
      struct time_zone_transition_time {
        uint32_t day {0};
        uint32_t day_of_week {0};
        bool is_fixed_date_rule {false};
        uint32_t month {0};
        uint32_t time_of_day_hour {0};
        uint32_t time_of_day_minute {0};
        uint32_t time_of_day_second {0};
        uint32_t week {0};
      };
      
      struct time_zone_adjustement_rule {
        tm date_end;
        tm date_start;
        int64_t daylight_delta {0};
        time_zone_transition_time daylight_transition_end;
        time_zone_transition_time daylight_transition_start_;
      };
      
      struct time_zone_info {
        std::string id;
        int64_t base_utc_offset {0};
        std::string daylight_name;
        std::string display_name;
        std::string standard_name;
        bool supports_daylight_saving_time {false};
      };

  private:
      date_time() = delete;
      
    protected:
      friend xtd::date_time;
      friend xtd::time_zone_info;
      /// @name Protected methods
      
      /// @{
      /// @internal
      /// @brief Gets a time_zone_info object that represents the local time zone.
      /// @return An object that represents the local time zone.
      /// @warning Internal use only
      static time_zone_info get_local_time_zone();

      /// @internal
      /// @brief Returns a sorted collection of all the time zones about which information is available on the local system.
      /// @return An array of time_zone_info objects.
      /// @warning Internal use only
      static std::vector<time_zone_info> get_system_time_zones();

      std::vector<time_zone_adjustement_rule> get_adjustement_rules(const std::string& id);
      
      /// @internal
      /// @brief Indicates whether the ttime_t is within the daylight saving time range for the current time zone.
      /// @return true if the time is within the daylight saving time range for the local time zone; otherwise false.
      /// @warning Internal use only
      static bool is_daylight(std::time_t time);
      /// @}
    };
  }
}
