/// @file
/// @brief Contains date time API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstddef>
#include <ctime>
#include <string>
#include <vector>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class date_time;
  class time_zone_info;
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains date time native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ date_time final {
    public:
      struct time_zone_info {
        struct transition_time {
          uint_least32_t day {0};
          uint_least32_t day_of_week {0};
          bool is_fixed_date_rule {false};
          uint_least32_t month {0};
          uint_least32_t time_of_day_hour {0};
          uint_least32_t time_of_day_minute {0};
          uint_least32_t time_of_day_second {0};
          uint_least32_t week {0};
        };
        
        struct adjustement_rule {
          uint_least32_t date_start_year;
          uint_least32_t date_start_month;
          uint_least32_t date_start_day;
          uint_least32_t date_start_hour;
          uint_least32_t date_start_minute;
          uint_least32_t date_start_second;
          uint_least32_t date_end_year;
          uint_least32_t date_end_month;
          uint_least32_t date_end_day;
          uint_least32_t date_end_hour;
          uint_least32_t date_end_minute;
          uint_least32_t date_end_second;
          int_least64_t daylight_delta {0};
          time_zone_info::transition_time daylight_transition_start_;
          time_zone_info::transition_time daylight_transition_end;
        };
        
        std::string id;
        int_least64_t base_utc_offset {0};
        std::string daylight_name;
        std::string display_name;
        std::string standard_name;
        bool supports_daylight_saving_time {false};
        std::vector<time_zone_info::adjustement_rule> adjustement_rules;
      };
      
    private:
      date_time() = delete;
      
    protected:
      friend xtd::date_time;
      friend xtd::time_zone_info;
      /// @name Protected methods
      
      /// @{
      /// @brief Gets a time_zone_info object that represents the local time zone.
      /// @return An object that represents the local time zone.
      /// @warning Internal use only
      static time_zone_info get_local_time_zone();
      
      /// @brief Returns a sorted collection of all the time zones about which information is available on the local system.
      /// @return An array of time_zone_info objects.
      /// @warning Internal use only
      static std::vector<time_zone_info> get_system_time_zones();
      
      /// @brief Gets the utc offset for the specified local time.
      /// @return the utc offset for the specified local time in seconds.
      /// @warning Internal use only
      static time_t utc_offset(std::time_t time);
      
      /// @brief Indicates whether the ttime_t is within the daylight saving time range for the current time zone.
      /// @return true if the time is within the daylight saving time range for the local time zone; otherwise false.
      /// @warning Internal use only
      static bool is_daylight(std::time_t time);
      /// @}
    };
  }
}
