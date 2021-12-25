/// @file
/// @brief Contains xtd::time_zone_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "day_of_week.h"
#include "icomparable.h"
#include "iequatable.h"
#include "date_time.h"
#include "object.h"
#include "ticks.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents any time zone in the world.
  /// @code
  /// class core_export_ time_zone_info : public xtd::icomparable<time_zone_info>, public xtd::iequatable<time_zone_info>, public xtd::object
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::time_zone_info
  /// @par Implements
  /// xtd::icomparable <>, xtd::iequatable <>
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks A time zone is a geographical region in which the same time is used.
  /// @remarks The time_zone_info class offers significant enhancements over the TimeZone class, which provides only limited functionality.
  /// @remarks The TimeZone class recognizes only the local time zone, and can convert times between Coordinated Universal Time (UTC) and local time. A time_zone_info object can represent any time zone, and methods of the time_zone_info class can be used to convert the time in one time zone to the corresponding time in any other time zone. The members of the time_zone_info class support the following operations:
  /// * Retrieving a time zone that is already defined by the operating system.
  /// * Enumerating the time zones that are available on a system.
  /// * Converting times between different time zones.
  /// * Creating a new time zone that is not already defined by the operating system.
  /// * Serializing a time zone for later retrieval.
  /// @note An instance of the time_zone_info class is immutable. Once an object has been instantiated, its values cannot be modified.
  class core_export_ time_zone_info : public xtd::icomparable<time_zone_info>, public xtd::iequatable<time_zone_info>, public xtd::object {
  public:
    class transition_time : public xtd::object {
    public:
      /// @cond
      transition_time() = default;
      transition_time(const transition_time&) = default;
      transition_time(transition_time&&) = default;
      transition_time& operator=(const transition_time&) = default;
      /// @endcond

      /// @name Properties
      
      /// @{
      uint32_t day() const noexcept {return day_;}
      
      xtd::day_of_week day_of_week() const noexcept {return day_of_week_;}
      
      bool is_fixed_rule() const noexcept {return is_fixed_date_rule_;}
      
      uint32_t month() const noexcept {return month_;}
      
      xtd::date_time time_of_day() const noexcept {return time_of_day_;}
      
      uint32_t week() const noexcept {return week_;}
      /// @}
      
    private:
      uint32_t day_ = 0;
      xtd::day_of_week day_of_week_ = xtd::day_of_week::sunday;
      bool is_fixed_date_rule_ = true;
      uint32_t month_ = 0;
      xtd::date_time time_of_day_;
      uint32_t week_ = 0;
    };
    
    class adjustement_rule : public xtd::object {
    public:
      /// @cond
      adjustement_rule() = default;
      adjustement_rule(const adjustement_rule&) = default;
      adjustement_rule(adjustement_rule&&) = default;
      adjustement_rule& operator=(const adjustement_rule&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      const xtd::date_time& date_end() const noexcept {return date_end_;}
      
      const xtd::date_time& date_start() const noexcept {return date_start_;}

      xtd::ticks daylight_delta() const noexcept {return daylight_delta_;}

      transition_time daylight_transition_end() const noexcept {return daylight_transition_end_;}

      transition_time daylight_transition_start() const noexcept {return daylight_transition_start_;}
      /// @}
      
    private:
      xtd::date_time date_end_ {date_time::max_value};
      xtd::date_time date_start_ {date_time::min_value};
      xtd::ticks daylight_delta_ {std::chrono::duration_cast<xtd::ticks>(std::chrono::hours(1))};
      transition_time daylight_transition_end_;
      transition_time daylight_transition_start_;
    };
        
    /// @cond
    time_zone_info() = default;
    time_zone_info(const ustring& id, const ticks& base_utc_offset, const ustring& daylight_name, const ustring& display_name, const ustring& standard_name, bool supports_daylight_saving_time);
    time_zone_info(const time_zone_info&) = default;
    time_zone_info(time_zone_info&&) = default;
    time_zone_info& operator=(const time_zone_info&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the time difference between the current time zone's standard time and Coordinated Universal Time (UTC).
    /// @return TimeSpan An object that indicates the time difference between the current time zone's standard time and Coordinated Universal Time (UTC).
    /// @remarks The time span returned by the BaseUtcOffset property can range from 14 hours (for a time zone that is 14 hours ahead of Coordinated Universal Time (UTC)) to -14 hours (for a time zone that is 14 hours behind UTC). Time zones that are ahead of UTC have a positive offset; time zones that are behind UTC have a negative offset.
    /// @remarks The BaseUtcOffset value is represented as a whole number of minutes. It cannot include a fractional number of minutes.
    /// @note Because BaseUtcOffset is a property of the time_zone_info object rather than the time_zone_info.AdjustmentRule object, the time_zone_info class applies a single offset from UTC to all of a time zone's adjustments. To reflect a time zone that has modified its offset from UTC, you must create a new time zone using the CreateCustomTimeZone method.
    /// @note The BaseUtcOffset property differs from the GetUtcOffset method in the following ways:
    /// * The BaseUtcOffset property returns the difference between UTC and the time zone's standard time; the GetUtcOffset method returns the difference between UTC and the time zone's time at a particular point in time.
    /// * The GetUtcOffset method reflects the application of any adjustment rules to the time zone; the BaseUtcOffset property does not.
    ticks base_utc_offset() const {
      return base_utc_offset_;
    }
    
    /// @brief Gets the display name for the current time zone's daylight saving time.
    /// @return string The display name for the time zone's daylight saving time.
    /// @remarks The display name is localized based on the culture installed with the Windows operating system.
    /// @remarks A DaylightName property whose value is not ustring.Empty or null does not necessarily indicate that the time zone supports daylight saving time. To determine whether the time zone supports daylight saving time, check the value of its SupportsDaylightSavingTime property.
    /// @remarks In most cases, the DaylightName property of time zones defined in the registry is not ustring.Empty or null. However, the DaylightName property of custom time zones can be set to ustring.Empty. This occurs when custom time zones are created by the time_zone_info.CreateCustomTimeZone(ustring, TimeSpan, ustring, ustring) or the time_zone_info.CreateCustomTimeZone(ustring, TimeSpan, ustring, ustring, ustring, time_zone_info.AdjustmentRule[], Boolean) overload and the disableDaylightSavingTime parameter is true. Therefore, your code should never assume that the value of the DaylightName property is not null or empty.
    /// @remarks The DaylightName property is equivalent to the DaylightName property of the TimeZone class.
    const ustring& daylight_name() const {
      return daylight_name_;
    }
    
    /// @brief Gets the general display name that represents the time zone.
    /// @return string The time zone's general display name.
    /// @remarks The display name is localized based on the culture installed with the Windows operating system.
    /// @remarks Time zone display names for Windows system time zones follow a fairly standard format. The first portion of the display name is the time zone's base offset from Coordinated Universal Time, which is indicated by the acronym GMT (for Greenwich Mean Time), enclosed in parentheses. For Coordinated Universal Time, the GMT acronym with no offset is enclosed in parentheses. This is followed by a string that identifies the time zone or one or more of the cities, regions, or countries in the time zone. For example:
    /// @code
    /// (GMT) Greenwich Mean Time : Dublin, Edinburgh, Lisbon, London
    /// (GMT+02:00) Athens, Beirut, Istanbul, Minsk
    /// (GMT-02:00) Mid-Atlantic
    /// (GMT-07:00) Mountain Time (US & Canada)
    ///  @endcode
    const ustring& display_name() const {
      return display_name_;
    }
    
    /// @brief Gets the time zone identifier.
    /// @return string The time zone identifier.
    /// @remarks The time zone identifier is a key string that uniquely identifies a particular time zone. It can be passed as a parameter to the FindSystemTimeZoneById method to retrieve a particular time zone from the registry.
    const ustring& id() const {
      return id_;
    }
    
    /// @brief Gets a time_zone_info object that represents the local time zone.
    /// @return time_zone_info An object that represents the local time zone.
    static const time_zone_info& local();
    
    /// @brief Gets the display name for the time zone's standard time.
    /// @return The display name of the time zone's standard time.
    /// @remarks The display name is localized based on the culture installed with the Windows operating system.
    /// @remarks The StandardName property is identical to the StandardName property of the TimeZone class.
    /// @remarks The value of the StandardName property is usually, but not always, identical to that of the Id property.
    const ustring& standard_name() const {
      return standard_name_;
    }
    
    /// @brief Gets a value indicating whether the time zone has any daylight saving time rules.*
    /// @return bool true if the time zone supports daylight saving time; otherwise, false.
    /// @remarks The value of the SupportsDaylightSavingTime property for the local time zone returned by the time_zone_info.Local property reflects the setting of the Control Panel Date and Time application's checkbox that defines whether the system automatically adjusts for daylight saving time. If it is unchecked, or if no checkbox is displayed for a time zone, the value of this property is false.
    bool supports_daylight_saving_time() const {
      return supports_daylight_saving_time_;
    }
    
    /// @brief Gets a time_zone_info object that represents the Coordinated Universal Time (UTC) zone.
    /// @return time_zone_info An object that represents the Coordinated Universal Time (UTC) zone.
    static const time_zone_info& utc();
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Converts the specified date and time to Coordinated Universal Time (UTC).
    /// @param dateTime The date and time to convert.
    /// @return date_time The Coordinated Universal Time (UTC) that corresponds to the dateTime parameter. The DateTime value's Kind property is always set to DateTimeKind.Utc.
    /// @exception ArgumentNullException dateTime is null.
    /// @exception ArgumentException time_zone_info::Local().IsInvalidDateTime(dateTime) returns true.
    static xtd::date_time convert_time_to_utc(const xtd::date_time& date_time);
    
    /// @brief Returns a sorted collection of all the time zones about which information is available on the local system.
    /// @return An read-only Array of time_zone_info objects.
    static const std::list<time_zone_info>& get_system_time_zones();
    
    int32_t compare_to(const time_zone_info& tzi) const noexcept override;
    int32_t compare_to(const object& obj) const noexcept override;
    
    static xtd::date_time convert_time(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone);
    static xtd::date_time convert_time(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone, const xtd::time_zone_info& destination_time_zone);

    static xtd::date_time convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::ustring& destination_time_zone_id);
    static xtd::date_time convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone_id, const xtd::time_zone_info& destination_time_zone_id);

    static xtd::date_time convert_from_utc(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone);

    static xtd::date_time convert_to_utc(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone);
    static xtd::date_time convert_to_utc(const xtd::date_time& date_time);

    bool equals(const time_zone_info& tzi) const noexcept override;
    bool equals(const object& obj) const noexcept override;
    
    bool is_daylight_saving_time (const xtd::date_time& date_time) const;

    /// @brief Retrieves a time_zone_info object from the registry based on its identifier.
    /// @param id The time zone identifier, which corresponds to the Id property.
    /// @return An object whose identifier is the value of the id parameter.
    /// @exception ArgumentNullException The id parameter is null.
    /// @exception TimeZoneNotFoundException The time zone identifier specified by id was not found. This means that a registry key whose name matches id does not exist, or that the key exists but does not contain any time zone data.
    static const time_zone_info& time_find_system_time_zone_by_id(const ustring& id);
    
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    ustring id_;
    ticks base_utc_offset_;
    ustring daylight_name_;
    ustring display_name_;
    ustring standard_name_;
    bool supports_daylight_saving_time_ = false;
  };

  /// @cond
  std::ostream& operator <<(std::ostream& os, const time_zone_info& tzi) noexcept;
  /// @endcond
}
