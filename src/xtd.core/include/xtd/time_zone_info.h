/// @file
/// @brief Contains xtd::time_zone_info class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "argument_out_of_range_exception.h"
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
    /// @name Claasses
    
    /// @{
    /// @brief Provides information about a specific time change, such as the change from daylight saving time to standard time or vice versa, in a particular time zone.
    /// @code
    /// class transition_time : public xtd::iequatable<transition_time>, public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::time_zone_info::transition_time
    /// @par Implements
    /// xtd::iequatable <>
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system
    /// @remarks You can use the xtx::time_zone_info::transition_time structure to indicate when a transition from standard time to daylight saving time, or from daylight saving time back to standard time, occurs. This structure supports both fixed-date rules and floating-date rules. Use fixed-date rules for time transitions that occur on a specific day of a specific month (such as 2:00 A.M. on November 3). Use floating-date rules for time transitions that occur on a specific day of a specific week of a specific month (such as 2:00 A.M. on the first Sunday of November).
    /// @remarks The following table compares the properties used in fixed-date and floating-date transitions:
    /// |                    | Month                                       | Week                                       | Day                                               | Time                                              |
    /// |--------------------|---------------------------------------------|--------------------------------------------|---------------------------------------------------|---------------------------------------------------|
    /// | Fixed-date rule    | xtd::time_zone_info::transition_time::month | N/A                                        | xtd::time_zone_info::transition_time::day         | xtd::time_zone_info::transition_time::time_of_day |
    /// | Floating-date rule | xtd::time_zone_info::transition_time::month | xtd::time_zone_info::transition_time::week | xtd::time_zone_info::transition_time::day_of_week | xtd::time_zone_info::transition_time::time_of_day |
    /// @remarks For both fixed-date and floating-date transitions, the xtd::time_zone_info::transition_time::time_of_day property gets the time at which the time change occurs. For transitions from standard to daylight saving time, this is the time zone's standard time value. For transitions from daylight saving to standard time, this is the time zone's daylight saving time value. This is a xtd::date_time value whose date component is ignored; its year, month, and day value must always equal 1.
    /// @note An instance of the xtd::time_zone_info::transition_time structure is immutable. Once an object has been created, its values cannot be modified.
    /// @remarks A xtd::time_zone_info::transition_time object can be created by calling the static xtd::time_zone_info::transition_time::create_fixed_date_rule and xtd::time_zone_info::transition_time::create_floating_date_rule methods to create a fixed or floating-date rule, respectively. The starting and ending xtd::time_zone_info::transition_time objects are then supplied as parameters to the xtd::time_zone_info::adjustment_rule::create_adjustment_rule method to create a new adjustment rule that includes this transition time information.
    /// @remarks The xtd::time_zone_info::transition_time::daylight_transition_start and xtd::time_zone_info::transition_time::daylight_transition_end properties of an xtd::time_zone_info::adjustment_rule object return a xtd::time_zone_info::transition_time object.
    class transition_time : public xtd::iequatable<transition_time>, public xtd::object {
    public:
      /// @cond
      transition_time() = default;
      transition_time(const transition_time&) = default;
      transition_time(transition_time&&) = default;
      transition_time& operator =(const transition_time&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the day on which the time change occurs.
      /// @return The day on which the time change occurs.
      /// @remarks The xtd::time_zone_info::transition_time::day property returns a valid value only if the xtd::time_zone_info::transition_time::is_fixed_date_rule property is true.
      /// @remarks The xtd::time_zone_info::transition_time::day property value corresponds to the value of the day parameter of the xtd::time_zone_info::transition_time::create_fixed_date_rule method. If its value is greater than the number of days in the month of the transition, the transition occurs on the last day of the month.
      /// @remarks The xtd::time_zone_info::transition_time::day property indicates the day of the month on which a fixed-date rule is applied (for example, April 15). In contrast, the xtd::time_zone_info::transition_time::day_of_week property indicates the day of the week on which a floating-date rule is applied (for example, the second Sunday of November).
      uint32_t day() const noexcept {return day_;}
      
      /// @brief Gets the day of the week on which the time change occurs.
      /// @return The day of the week on which the time change occurs.
      /// @remarks The xtd::time_zone_info::transition_time::day_of_week property returns a valid value only if the xtd::time_zone_info::transition_time::is_fixed_date_rule property is false.
      /// @remarks The xtd::time_zone_info::transition_time::day_of_week property indicates the day of the week on which a floating-date rule is applied (for example, the second Sunday of November). In contrast, the xtd::time_zone_info::transition_time::day property indicates the day of the month on which a fixed-date rule is applied (for example, April 15).
      xtd::day_of_week day_of_week() const noexcept {return day_of_week_;}
      
      /// @brief Gets a value indicating whether the time change occurs at a fixed date and time (such as November 1) or a floating date and time (such as the last Sunday of October).
      /// @return true if the time change rule is fixed-date; false if the time change rule is floating-date.
      /// @remarks A fixed-date rule indicates that the transition occurs on the same date and time of each year to which the adjustment rule applies. For example, a time change that occurs every November 3 follows a fixed-date rule. A floating-date rule indicates that the transition occurs on a specific day of a specific week of a specific month for each year to which the adjustment rule applies. For example, a time change that occurs on the first Sunday of November follows a floating-date rule.
      /// @remarks The value of the xtd::time_zone_info::transition_time::is_fixed_date_rule property determines which properties of a xtd::time_zone_info::transition_time object have valid values. The following table indicates which properties are affected by the value of the xtd::time_zone_info::transition_time::is_fixed_date_rule property.
      /// | transition_time property   | is_fixed_date_rule = true | is_fixed_date_rule = false |
      /// |----------------------------|---------------------------|----------------------------|
      /// | @code day @endcode         | Valid                     | Unused                     |
      /// | @code day_of_week @endcode | Unused                    | Valid                      |
      /// | @code week @endcode        | Unused                    | Valid                      |
      /// | @code month @endcode       | Valid                     | Valid                      |
      /// | @code time_of_day @endcode | Valid                     | Valid                      |
      bool is_fixed_rule() const noexcept {return is_fixed_date_rule_;}
      
      /// @brief Gets the month in which the time change occurs.
      /// @return The month in which the time change occurs.
      /// @remarks Valid values for the xtd::time_zone_info::transition_time::month property range from 1 to 12.
      /// @remarks The xtd::time_zone_info::transition_time::month property is used for both fixed-date and floating-date rules.
      uint32_t month() const noexcept {return month_;}
      
      /// @brief Gets the hour, minute, and second at which the time change occurs.
      /// @return The time of day at which the time change occurs.
      /// @remarks For transitions from standard time to daylight saving time, the xtd::time_zone_info::transition_time::time_of_day value represents the time of the transition in the time zone's standard time. For transitions from daylight saving time to standard time, it represents the time of the transition in the time zone's daylight saving time.
      /// @remarks The xtd::time_zone_info::transition_time::time_of_day property defines only the time of a time change, but not its date. The date is determined by the xtd::time_zone_info::transition_time::month and xtd::time_zone_info::transition_time::day properties for fixed-rule changes, and by the xtd::time_zone_info::transition_time::month, xtd::time_zone_info::transition_time::week, and xtd::time_zone_info::transition_time::day_of_week properties for floating-rule changes. The date component of this xtd::date_time value is ignored; the value of the year, month, and day is always 1.
      /// @remarks The xtd::time_zone_info::transition_time::time_of_day property is used for both fixed-date and floating-date transitions.
      xtd::date_time time_of_day() const noexcept {return time_of_day_;}
      
      /// @brief Gets the week of the month in which a time change occurs.
      /// @return The week of the month in which the time change occurs.
      /// @remarks The value of the xtd::time_zone_info::transition_time::week property is used only for time changes with floating-date rules. Valid values can range from 1 to 5.
      /// @remarks The xtd::time_zone_info::transition_time::month property defines the month in which the time change occurs. The xtd::time_zone_info::transition_time::week property determines the week on which the transition occurs. The xtd::time_zone_info::transition_time::day_of_week property defines the day of the week on which the transition occurs. The value of the xtd::time_zone_info::transition_time::week property is determined as shown in the following table.
      /// | If the Week property value is | The transition occurs on                                                                                                             |
      /// |-------------------------------|--------------------------------------------------------------------------------------------------------------------------------------|
      /// | 1                             | The first occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month.  |
      /// | 2                             | The second occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month. |
      /// | 3                             | The third occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month.  |
      /// | 4                             | The fourth occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month. |
      /// | 5                             | The last occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month.   |
      /// @remarks For example, if a transition occurs on the first Sunday of March, the value of the xtd::time_zone_info::transition_time::week property is 1. If it occurs on the last Sunday of March, the value of the xtd::time_zone_info::transition_time::week property is 5.
      uint32_t week() const noexcept {return week_;}
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Defines a time change that uses a fixed-date rule (that is, a time change that occurs on a specific day of a specific month).
      /// @param time_of_day The time at which the time change occurs. This parameter corresponds to the xtd::time_zone_info::transition_time::ttime_of_day property.
      /// @param month The month in which the time change occurs. This parameter corresponds to the xtd::time_zone_info::transition_time::month property.
      /// @param day The day of the month on which the time change occurs. This parameter corresponds to the xtd::time_zone_info::transition_time::day property.
      /// @return Data about the time change.
      /// @exception xtd::argument_exception The time_of_day parameter has a non-default date component.<br>-or-<br>The time_of_day parameter's Kind property is not unspecified.<br>-or-<br>The time_of_day parameter does not represent a whole number of milliseconds.
      /// @exception xtd::argument_out_of_range_exception The month parameter is less than 1 or greater than 12.<br>-or-<br>The day parameter is less than 1 or greater than 31.
      /// @remarks This method creates a fixed-date rule (that is, a time change that occurs on a specific day of a specific month). For example, a time change that always occurs on October 28 follows a fixed-date rule.
      /// @remarks For transitions from standard time to daylight saving time, the timeOfDay argument represents the time of the transition in the time zone's standard time. For transitions from daylight saving time to standard time, it represents the time of the transition in the time zone's daylight saving time. Note that this is a xtd::date_time value whose year, month, and date values must all equal 1.
      static transition_time create_fixed_date_rule(date_time time_of_day, uint32_t month, uint32_t day) {
        if (time_of_day.year() != 1 || time_of_day.month() != 1 || time_of_day.day() != 1 || time_of_day.kind() != date_time_kind::unspecified) throw argument_exception(csf_);
        if (month < 1 || month > 12 || day < 1 || day > 31) throw argument_out_of_range_exception(csf_);
        transition_time result;
        result.day_ = day;
        result.is_fixed_date_rule_ = false;
        result.month_ = month;
        result.time_of_day_ = time_of_day;
        return result;
      }
      
      /// @brief Defines a time change that uses a floating-date rule (that is, a time change that occurs on a specific day of a specific week of a specific month).
      /// @param time_of_day The time at which the time change occurs. This parameter corresponds to the xtd::time_zone_info::transition_time::ttime_of_day property.
      /// @param month The month in which the time change occurs. This parameter corresponds to the xtd::time_zone_info::transition_time::month property.
      /// @param week The week of the month in which the time change occurs. Its value can range from 1 to 5, with 5 representing the last week of the month. This parameter corresponds to the xtd::time_zone_info::transition_time::week property
      /// @param day_of_week The day of the week on which the time change occurs. This parameter corresponds to the xtd::time_zone_info::transition_time::day_of_week property.
      /// @return Data about the time change.
      /// @exception xtd::argument_exception The time_of_day parameter has a non-default date component.<br>-or-<br>The time_of_day parameter's Kind property is not unspecified.<br>-or-<br>The time_of_day parameter does not represent a whole number of milliseconds.
      /// @exception xtd::argument_out_of_range_exception The month parameter is less than 1 or greater than 12.<br>-or-<br>The week parameter is less than 1 or greater than 5.
      /// @remarks This method creates a floating-date rule (that is, a time change that occurs on a specific day of a specific week of a specific month). For example, a time change that occurs on the last Sunday of October follows a floating-date rule.
      /// @remarks For transitions from standard time to daylight saving time, the time_of_day argument represents the time of the transition in the time zone's standard time. For transitions from daylight saving time to standard time, it represents the time of the transition in the time zone's daylight saving time. Note that this is a xtd::date_time value whose year, month, and date values must all equal 1.
      static transition_time create_floating_date_rule(date_time time_of_day, uint32_t month, uint32_t week, xtd::day_of_week day_of_week) {
        if (time_of_day.year() != 1 || time_of_day.month() != 1 || time_of_day.day() != 1 || time_of_day.kind() != date_time_kind::unspecified) throw argument_exception(csf_);
        if (month < 1 || month > 12 || week < 1 || week > 5) throw argument_out_of_range_exception(csf_);
        transition_time result;
        result.day_of_week_ = day_of_week;
        result.is_fixed_date_rule_ = false;
        result.month_ = month;
        result.time_of_day_ = time_of_day;
        result.week_ = week;
        return result;
      }
      
      bool equals(const transition_time& tt) const noexcept override {return day_ == tt.day_ && day_of_week_ == tt.day_of_week_ && is_fixed_date_rule_ == tt.is_fixed_date_rule_ && month_ == tt.month_ && time_of_day_ == tt.time_of_day_ && week_ == tt.week_;}
      bool equals(const object& obj) const noexcept override {return is<transition_time>(obj) && equals(static_cast<const transition_time&>(obj));}
      /// @}
      
    private:
      uint32_t day_ = 0;
      xtd::day_of_week day_of_week_ = xtd::day_of_week::sunday;
      bool is_fixed_date_rule_ = true;
      uint32_t month_ = 0;
      xtd::date_time time_of_day_;
      uint32_t week_ = 0;
    };
    
    /// @brief Provides information about a time zone adjustment, such as the transition to and from daylight saving time.
    /// @code
    /// class adjustement_rule : public xtd::iequatable<adjustement_rule>, public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::adjustement_rule
    /// @par Implements
    /// xtd::iequatable <>
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system
    /// @remarks The xtd::time_zone_info::adjustment_rule class defines the effective start and end dates of a particular time change to and from daylight saving time, respectively, as well as its delta (the exact amount by which the adjustment causes the time zone's standard time to change). In addition, two properties return xtd::txtd::time_zone_info::transition_time objects that define when each transition to and from standard time occurs.
    /// @note An instance of the xtd::time_zone_info::adjustment_rule class is immutable. Once an object has been created, its values cannot be modified.
    /// @remarks To create a xtd::time_zone_info::adjustment_rule object, call the static xtd::time_zone_info::adjustment_rule::create_adjustment_rule method. You can then supply an array of xtd::time_zone_info::adjustment_rule objects to two of the overloads of the xtd::time_zone_info::create_custom_time_zone method. To retrieve the adjustment rules of a particular time zone, call its xtd::time_zone_info::get_adjustment_rules method, which returns an array of xtd::time_zone_info::adjustment_rule objects.
    class adjustement_rule : public xtd::iequatable<adjustement_rule>, public xtd::object {
    public:
      /// @cond
      adjustement_rule() = default;
      adjustement_rule(const adjustement_rule&) = default;
      adjustement_rule(adjustement_rule&&) = default;
      adjustement_rule& operator =(const adjustement_rule&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief
      const xtd::date_time& date_end() const noexcept {return date_end_;}
      
      const xtd::date_time& date_start() const noexcept {return date_start_;}
      
      xtd::ticks daylight_delta() const noexcept {return daylight_delta_;}
      
      transition_time daylight_transition_end() const noexcept {return daylight_transition_end_;}
      
      transition_time daylight_transition_start() const noexcept {return daylight_transition_start_;}
      /// @}
      
      
      /// @name Methods
      
      /// @{
      bool equals(const adjustement_rule& ar) const noexcept override {return date_end_ == ar.date_end_ && date_start_ == ar.date_start_ && daylight_delta_ == ar.daylight_delta_ && daylight_transition_end_ == ar.daylight_transition_end_ && daylight_transition_start_ == ar.daylight_transition_start_;}
      bool equals(const object& obj) const noexcept override {return is<adjustement_rule>(obj) && equals(static_cast<const adjustement_rule&>(obj));}
      /// @}
      
    private:
      xtd::date_time date_end_ {date_time::max_value};
      xtd::date_time date_start_ {date_time::min_value};
      xtd::ticks daylight_delta_ {0};
      transition_time daylight_transition_end_;
      transition_time daylight_transition_start_;
    };
    /// @}
    
    /// @cond
    time_zone_info() = default;
    time_zone_info(const ustring& id, const ticks& base_utc_offset, const ustring& daylight_name, const ustring& display_name, const ustring& standard_name, bool supports_daylight_saving_time);
    time_zone_info(const time_zone_info&) = default;
    time_zone_info(time_zone_info&&) = default;
    time_zone_info& operator =(const time_zone_info&) = default;
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
    /// @return date_time The Coordinated Universal Time (UTC) that corresponds to the dateTime parameter. The xtd::date_time value's Kind property is always set to xtd::date_timeKind.Utc.
    /// @exception ArgumentNullException dateTime is null.
    /// @exception ArgumentException time_zone_info::Local().IsInvalidxtd::date_time(dateTime) returns true.
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
    
    std::vector<adjustement_rule> get_adjustement_rules() const;
    
    bool is_daylight_saving_time(const xtd::date_time& date_time) const;
    
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
    std::vector<adjustement_rule> adjustement_rules_;
  };
}
