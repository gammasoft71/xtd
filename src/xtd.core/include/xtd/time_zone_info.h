/// @file
/// @brief Contains xtd::time_zone_info class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
    /// | ------------------ | ------------------------------------------- | ------------------------------------------ | ------------------------------------------------- | ------------------------------------------------- |
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
      uint32 day() const noexcept;
      
      /// @brief Gets the day of the week on which the time change occurs.
      /// @return The day of the week on which the time change occurs.
      /// @remarks The xtd::time_zone_info::transition_time::day_of_week property returns a valid value only if the xtd::time_zone_info::transition_time::is_fixed_date_rule property is false.
      /// @remarks The xtd::time_zone_info::transition_time::day_of_week property indicates the day of the week on which a floating-date rule is applied (for example, the second Sunday of November). In contrast, the xtd::time_zone_info::transition_time::day property indicates the day of the month on which a fixed-date rule is applied (for example, April 15).
      xtd::day_of_week day_of_week() const noexcept;
      
      /// @brief Gets a value indicating whether the time change occurs at a fixed date and time (such as November 1) or a floating date and time (such as the last Sunday of October).
      /// @return true if the time change rule is fixed-date; false if the time change rule is floating-date.
      /// @remarks A fixed-date rule indicates that the transition occurs on the same date and time of each year to which the adjustment rule applies. For example, a time change that occurs every November 3 follows a fixed-date rule. A floating-date rule indicates that the transition occurs on a specific day of a specific week of a specific month for each year to which the adjustment rule applies. For example, a time change that occurs on the first Sunday of November follows a floating-date rule.
      /// @remarks The value of the xtd::time_zone_info::transition_time::is_fixed_date_rule property determines which properties of a xtd::time_zone_info::transition_time object have valid values. The following table indicates which properties are affected by the value of the xtd::time_zone_info::transition_time::is_fixed_date_rule property.
      /// | transition_time property   | is_fixed_date_rule = true | is_fixed_date_rule = false |
      /// | -------------------------- | ------------------------- | -------------------------- |
      /// | @code day @endcode         | Valid                     | Unused                     |
      /// | @code day_of_week @endcode | Unused                    | Valid                      |
      /// | @code week @endcode        | Unused                    | Valid                      |
      /// | @code month @endcode       | Valid                     | Valid                      |
      /// | @code time_of_day @endcode | Valid                     | Valid                      |
      bool is_fixed_rule() const noexcept;
      
      /// @brief Gets the month in which the time change occurs.
      /// @return The month in which the time change occurs.
      /// @remarks Valid values for the xtd::time_zone_info::transition_time::month property range from 1 to 12.
      /// @remarks The xtd::time_zone_info::transition_time::month property is used for both fixed-date and floating-date rules.
      uint32 month() const noexcept;
      
      /// @brief Gets the hour, minute, and second at which the time change occurs.
      /// @return The time of day at which the time change occurs.
      /// @remarks For transitions from standard time to daylight saving time, the xtd::time_zone_info::transition_time::time_of_day value represents the time of the transition in the time zone's standard time. For transitions from daylight saving time to standard time, it represents the time of the transition in the time zone's daylight saving time.
      /// @remarks The xtd::time_zone_info::transition_time::time_of_day property defines only the time of a time change, but not its date. The date is determined by the xtd::time_zone_info::transition_time::month and xtd::time_zone_info::transition_time::day properties for fixed-rule changes, and by the xtd::time_zone_info::transition_time::month, xtd::time_zone_info::transition_time::week, and xtd::time_zone_info::transition_time::day_of_week properties for floating-rule changes. The date component of this xtd::date_time value is ignored; the value of the year, month, and day is always 1.
      /// @remarks The xtd::time_zone_info::transition_time::time_of_day property is used for both fixed-date and floating-date transitions.
      xtd::date_time time_of_day() const noexcept;
      
      /// @brief Gets the week of the month in which a time change occurs.
      /// @return The week of the month in which the time change occurs.
      /// @remarks The value of the xtd::time_zone_info::transition_time::week property is used only for time changes with floating-date rules. Valid values can range from 1 to 5.
      /// @remarks The xtd::time_zone_info::transition_time::month property defines the month in which the time change occurs. The xtd::time_zone_info::transition_time::week property determines the week on which the transition occurs. The xtd::time_zone_info::transition_time::day_of_week property defines the day of the week on which the transition occurs. The value of the xtd::time_zone_info::transition_time::week property is determined as shown in the following table.
      /// | If the Week property value is | The transition occurs on                                                                                                             |
      /// | ----------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
      /// | 1                             | The first occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month.  |
      /// | 2                             | The second occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month. |
      /// | 3                             | The third occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month.  |
      /// | 4                             | The fourth occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month. |
      /// | 5                             | The last occurrence of the xtd::time_zone_info::transition_time::day_of_week value in xtd::time_zone_info::transition_time::month.   |
      /// @remarks For example, if a transition occurs on the first Sunday of March, the value of the xtd::time_zone_info::transition_time::week property is 1. If it occurs on the last Sunday of March, the value of the xtd::time_zone_info::transition_time::week property is 5.
      uint32 week() const noexcept;
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
      static transition_time create_fixed_date_rule(date_time time_of_day, uint32 month, uint32 day);
      
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
      static transition_time create_floating_date_rule(date_time time_of_day, uint32 month, uint32 week, xtd::day_of_week day_of_week);
      
      bool equals(const transition_time& tt) const noexcept override;
      /// @}
      
    private:
      uint32 day_ = 0;
      xtd::day_of_week day_of_week_ = xtd::day_of_week::sunday;
      bool is_fixed_date_rule_ = true;
      uint32 month_ = 0;
      xtd::date_time time_of_day_;
      uint32 week_ = 0;
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
      /// @brief Gets the date when the adjustment rule ceases to be in effect.
      /// @return A xtd::date_time value that indicates the end date of the adjustment rule.
      /// @remarks The value of the xtd::time_zone_info::adjustement_rule::date_end property is a date value without a time component.
      /// @remarks Because the end date of the current adjustment rule is typically not known, you can assign @verbatim date_time::max_value().date() @endverbatim to the xtd::time_zone_info::adjustement_rule::date_end property when you create a custom adjustment rule.
      /// @warning Unless there is a compelling reason to do otherwise, you should define the adjustment rule's end date to occur within the time interval during which the time zone observes standard time. Unless there is a compelling reason to do so, you should not define the adjustment rule's end date to occur within the time interval during which the time zone observes daylight saving time. For example, if a time zone's transition from daylight saving time occurs on the third Sunday of March and its transition to daylight saving time occurs on the first Sunday of October, the effective end date of the adjustment rule should not be December 31 of a particular year, since that date occurs within the period of daylight saving time.
      const xtd::date_time& date_end() const noexcept;
      
      /// @brief Gets the date when the adjustment rule takes effect.
      /// @return A xtd::date_time value that indicates when the adjustment rule takes effect.
      /// @remarks The value of the xtd::time_zone_info::adjustement_rule::date_start property is a date value without a time component. It defines the date on which a particular adjustment rule goes into effect. This is the date in which a set of transitions (which typically are defined by one transition to daylight savings time and one transition back to standard time) go into effect. For example, an adjustment rule might go into effect on January 1, 2017, that provides for a transition to daylight savings time on the second Sunday of March and for a transition back to standard time on the first Sunday of November. Note that the starting date of the adjustment rule is not tied to the date of the first transition.
      /// @remarks You can assign @verbatim date_time::min_value().date() @endverbatim to the xtd::time_zone_info::adjustement_rule::date_end property when you create a custom adjustment rule for use in a time zone-aware application that does not have to work with historic time zone information.
      /// @warning Unless there is a compelling reason to do otherwise, you should define the adjustment rule's start date to occur within the time interval during which the time zone observes standard time. Unless there is a compelling reason to do so, you should not define the adjustment rule's start date to occur within the time interval during which the time zone observes daylight saving time. For example, if a time zone's transition from daylight saving time occurs on the third Sunday of March and its transition to daylight saving time occurs on the first Sunday of October, the effective start date of the adjustment rule should not be January 1 of a particular year, since that date occurs within the period of daylight saving time.
      const xtd::date_time& date_start() const noexcept;
      
      /// @brief Gets the amount of time that is required to form the time zone's daylight saving time. This amount of time is added to the time zone's offset from Coordinated Universal Time (UTC).
      /// @return A xtd::time_span object that indicates the amount of time to add to the standard time changes as a result of the adjustment rule.
      /// @remarks The following formula defines a time zone's daylight saving time:
      /// @code
      /// time_tone_time = base_utc_offset + daylight_delta + utc_time
      /// @encode
      /// @remarks The value of the xtd::time_zone_info::adjustement_rule::daylight_delta property can range from 14 hours to -14 hours.
      /// @note The xtd::time_zone_info::adjustement_rule::daylight_delta property measures the difference between the time zone's standard time and its daylight saving time. It does not apply to changes in a time zone's standard offset from Coordinated Universal Time (UTC). To represent a time zone that has changed its standard time offset from UTC, you must call the CreateCustomTimeZone method to create a new time zone.
      /// @remarks The most common value of the xtd::time_zone_info::adjustement_rule::daylight_delta property is 1.0 hours. The application of the daylight saving time adjustment rule increases the time zone's offset from Coordinated Universal Time (UTC) by one hour.
      xtd::time_span daylight_delta() const noexcept;
      
      /// @brief Gets information about the annual transition from daylight saving time back to standard time.
      /// @return A xtd::time_zone_info::transition_time object that defines the annual transition from daylight saving time back to the time zone's standard time.
      /// @remarks The xtd::time_zone_info::transition_time object returned by the xtd::time_zone_info::transition_time::daylight_transition_end property defines either a fixed-date rule or a floating-date rule for the return to standard time. A fixed-date rule provides the month, day, and time of day on which the transition occurs. A floating-date rule provides the month, week, day of the week, and time of day on which the transition occurs.
      transition_time daylight_transition_end() const noexcept;
      
      /// @brief Gets information about the annual transition from standard time to daylight saving time.
      /// @return A xtd::time_zone_info::transition_time object that defines the annual transition from a time zone's standard time to daylight saving time.
      /// @remarks The xtd::time_zone_info::transition_time object returned by the xtd::time_zone_info::transition_time::daylight_transition_start property defines either a fixed-date rule or a floating-date rule for the transition to daylight saving time. A fixed-date rule provides the month, day, and time of day on which the transition occurs. A floating-date rule provides the month, the week, the day of the week, and the time of day on which the transition occurs.
      transition_time daylight_transition_start() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const adjustement_rule& ar) const noexcept override;
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
    ticks base_utc_offset() const noexcept;
    
    /// @brief Gets the display name for the current time zone's daylight saving time.
    /// @return string The display name for the time zone's daylight saving time.
    /// @remarks The display name is localized based on the culture installed with the Windows operating system.
    /// @remarks A DaylightName property whose value is not ustring.Empty or null does not necessarily indicate that the time zone supports daylight saving time. To determine whether the time zone supports daylight saving time, check the value of its SupportsDaylightSavingTime property.
    /// @remarks In most cases, the DaylightName property of time zones defined in the registry is not ustring.Empty or null. However, the DaylightName property of custom time zones can be set to ustring.Empty. This occurs when custom time zones are created by the time_zone_info.CreateCustomTimeZone(ustring, TimeSpan, ustring, ustring) or the time_zone_info.CreateCustomTimeZone(ustring, TimeSpan, ustring, ustring, ustring, time_zone_info.AdjustmentRule[], Boolean) overload and the disableDaylightSavingTime parameter is true. Therefore, your code should never assume that the value of the DaylightName property is not null or empty.
    /// @remarks The DaylightName property is equivalent to the DaylightName property of the TimeZone class.
    const ustring& daylight_name() const noexcept;
    
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
    const ustring& display_name() const noexcept;
    
    /// @brief Gets the time zone identifier.
    /// @return string The time zone identifier.
    /// @remarks The time zone identifier is a key string that uniquely identifies a particular time zone. It can be passed as a parameter to the FindSystemTimeZoneById method to retrieve a particular time zone from the registry.
    const ustring& id() const noexcept;
    
    /// @brief Gets a time_zone_info object that represents the local time zone.
    /// @return time_zone_info An object that represents the local time zone.
    static const time_zone_info& local() noexcept;
    
    /// @brief Gets the display name for the time zone's standard time.
    /// @return The display name of the time zone's standard time.
    /// @remarks The display name is localized based on the culture installed with the Windows operating system.
    /// @remarks The StandardName property is identical to the StandardName property of the TimeZone class.
    /// @remarks The value of the StandardName property is usually, but not always, identical to that of the Id property.
    const ustring& standard_name() const noexcept;
    
    /// @brief Gets a value indicating whether the time zone has any daylight saving time rules.*
    /// @return bool true if the time zone supports daylight saving time; otherwise, false.
    /// @remarks The value of the SupportsDaylightSavingTime property for the local time zone returned by the time_zone_info.Local property reflects the setting of the Control Panel Date and Time application's checkbox that defines whether the system automatically adjusts for daylight saving time. If it is unchecked, or if no checkbox is displayed for a time zone, the value of this property is false.
    bool supports_daylight_saving_time() const noexcept;
    
    /// @brief Gets a time_zone_info object that represents the Coordinated Universal Time (UTC) zone.
    /// @return time_zone_info An object that represents the Coordinated Universal Time (UTC) zone.
    static const time_zone_info& utc() noexcept;
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
    static const std::list<time_zone_info>& get_system_time_zones() noexcept;
    
    int32 compare_to(const time_zone_info& tzi) const noexcept override;
    
    /// @brief Converts a time to the time in a particular time zone.
    /// @param date_time The date and time to convert.
    /// @param destination_time_zone The time zone to convert dateTime to.
    /// @return The date and time in the destination time zone.
    /// @exception xtd::argument_exception The value of the date_time parameter represents an invalid time.
    static xtd::date_time convert_time(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone);
    /// @brief Converts a time from one time zone to another.
    /// @param date_time The date and time to convert.
    /// @param source_time_zone The time zone of date_time.
    /// @param destination_time_zone The time zone to convert date_time to.
    /// @return The date and time in the destination time zone that corresponds to the dateTime parameter in the source time zone.
    /// @exception xtd::argument_exception The xtd::date_time::kind property of the date_time parameter is xtd::date_time_kind::local, but the source_time_tone parameter does not equal xtd::date_time_kind::local.<br>-or-<br>The xtd::date_time::kind property of the date_time parameter is xtd::date_time_kind::utc, but the source_time_zone parameter does not equal xtd::date_time_kind::utc.<br>-or-<br>The date_time parameter is an invalid time (that is, it represents a time that does not exist because of a time zone's adjustment rules).
    static xtd::date_time convert_time(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone, const xtd::time_zone_info& destination_time_zone);
    
    /// @brief Converts a time to the time in another time zone based on the time zone's identifier.
    /// @param date_time The date and time to convert.
    /// @param destination_time_zone_id The identifier of the destination time zone.
    /// @return The date and time in the destination time zone.
    static xtd::date_time convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::ustring& destination_time_zone_id);
    /// @brief Converts a time from one time zone to another based on time zone identifiers.
    /// @param date_time The date and time to convert.
    /// @param source_time_zone_id The identifier of the source time zone.
    /// @param destintion_time_zone_id The identifier of the destination time zone.
    /// @return The date and time in the destination time zone that corresponds to the dateTime parameter in the source time zone.
    static xtd::date_time convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::ustring& source_time_zone_id, const xtd::ustring& destination_time_zone_id);
    
    /// @brief Converts a Coordinated Universal Time (UTC) to the time in a specified time zone.
    /// @param date_time The Coordinated Universal Time (UTC).
    /// @param destination_time_zone The time zone to convert dateTime to.
    /// @return The date and time in the destination time zone. Its xtd::date_time::kind property is xtd::date_time_kind::utc if destination_time_zone is xtd::date_time_kind::utc; otherwise, its xtd::date_time::kind property is xtd::date_time_kind::unspecified.
    static xtd::date_time convert_from_utc(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone);
    
    /// @brief Converts the time in a specified time zone to Coordinated Universal Time (UTC).
    /// @param date_time The date and time to convert.
    /// @param source_time_zone The time zone of dateTime.
    /// @return The Coordinated Universal Time (UTC) that corresponds to the date_time parameter. The xtd::date_time object's xtd::date_time::kind property is always set to xtd::date_time_kind::utc.
    static xtd::date_time convert_to_utc(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone);
    /// @brief Converts the specified date and time to Coordinated Universal Time (UTC).
    /// @param date_time The date and time to convert.
    /// @return The Coordinated Universal Time (UTC) that corresponds to the date_time parameter. The xtd::date_time value's xtd::date_time::kind property is always set to xtd::date_time_kind::utc.
    static xtd::date_time convert_to_utc(const xtd::date_time& date_time);
    
    bool equals(const time_zone_info& tzi) const noexcept override;
    
    /// @brief Retrieves an array of xtd::time_zone_info::adjustment_rule objects that apply to the current xtd::time_zone_info object.
    /// @return An array of objects for this time zone.
    std::vector<adjustement_rule> get_adjustement_rules() const noexcept;
    
    /// @brief Indicates whether a specified date and time falls in the range of daylight saving time for the time zone of the current xtd::time_zone_info object.
    /// @param date_time A date and time value.
    /// @return true if the date_time parameter is a daylight saving time; otherwise, false.
    bool is_daylight_saving_time(const xtd::date_time& date_time) const noexcept;
    
    /// @brief Retrieves a time_zone_info object from the registry based on its identifier.
    /// @param id The time zone identifier, which corresponds to the Id property.
    /// @return An object whose identifier is the value of the id parameter.
    /// @exception ArgumentNullException The id parameter is null.
    /// @exception TimeZoneNotFoundException The time zone identifier specified by id was not found. This means that a registry key whose name matches id does not exist, or that the key exists but does not contain any time zone data.
    static time_zone_info time_find_system_time_zone_by_id(const ustring& id);
    
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
