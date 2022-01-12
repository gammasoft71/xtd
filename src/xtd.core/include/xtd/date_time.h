/// @file
/// @brief Contains xtd::date_time class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include <ctime>
#include "date_time_kind.h"
#include "day_of_week.h"
#include "icomparable.h"
#include "iequatable.h"
#include "object.h"
#include "ticks.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class time_zone_info;
  /// @endcond
  
  /// @brief Represents an instant in time, typically expressed as a date and time of day.
  /// @code
  /// class core_export_ date_time : public xtd::icomparable<date_time>, public xtd::iequatable<date_time>, public xtd::object
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::date_time
  /// @par Implements
  /// xtd::icomparable <>, xtd::iequatable <>
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The xtd::date_time value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.
  /// @remarks Time values are measured in 100-nanosecond units called ticks. A particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar. The number excludes ticks that would be added by leap seconds. For example, a ticks value of 31241376000000000L represents the date Friday, January 01, 0100 12:00:00 midnight. A xtd::date_time value is always expressed in the context of an explicit or default calendar.
  /// @note If you are working with a ticks value that you want to convert to some other time interval, such as minutes or seconds, you should use the xtd::time_span::ticks_per_day, xtd::time_span::ticks_per_hour, xtd::time_span::ticks_per_minute, xtd::time_span::ticks_per_second, or xtd::time_span::ticks_per_millisecond constant to perform the conversion. For example, to add the number of seconds represented by a specified number of ticks to the xtd::date_time::second component of a xtd::date_time value, you can use the expression date_value.second() + n_ticks/timespan.ticks_per_second.
  /// For example, a ticks value of 31241376000000000LL represents the date, Friday, January 01, 0100 12:00:00 midnight. A xtd::date_time value is always expressed in the context of an explicit or default calendar.
  /// @par Instantiating a xtd::date_time object
  /// You can create a new xtd::dateTime value in any of the following ways:
  ///    * By calling any of the overloads of the xtd::date_time constructor that allow you to specify specific elements of the date and time value (such as the year, month, and day, or the number of ticks). The following statement illustrates a call to one of the xtd::date_time constructors to create a date with a specific year, month, day, hour, minute, and second.
  /// @code
  /// xtd::date_time date1(2008, 5, 1, 8, 30, 52);
  /// @endcode
  ///
  ///    * By assigning the xtd::date_time object a date and time value returned by a property or method. The following example assigns the current date and time, the current Coordinated Universal Time (UTC) date and time, and the current date to three new date_time variables.
  /// @code
  /// date_time date1 = date_time::now();
  /// date_time date2 = date_time::utc_now();
  /// date_time date3 = date_time::today();
  /// @endcode
  ///
  ///    * By parsing the xtd::ustring representation of a date and time value. The xtd::date_time::parse, xtd::date_time::parse_exact, xtd::date_time::try_parse, and xtd::date_time::try_parse_exact methods all convert a xtd::ustring to its equivalent date and time value. The following example uses the xtd::date_time::parse method to parse a xtd::ustring and convert it to a xtd::date_time value.
  /// @code
  /// ustring date_string = "5/1/2008 8:30:52";
  /// date_time date1 = date_time::parse(date_string);
  /// @endcode
  /// Note that the xtd::date_time::try_parse and xtd::date_time::try_parse_exact methods indicate whether a particular xtd::ustring contains a valid representation of a xtd::date_time value in addition to performing the conversion.
  ///
  ///    * By calling the xtd::date_time structure's implicit default constructor. The following example illustrates a call to the xtd::date_time implicit default constructor.
  /// @code
  /// date_time dat1;
  /// // The following method call displays 1/01/0001 00:00:00.
  /// console::write_line(dat1.to_string());
  /// // The following method call displays true.
  /// console::write_line(dat1.equals(date_time::min_value));
  /// @endcode
  /// @par Examples
  /// The following example demonstrates how to compare roughly equivalent xtd::date_time values, accepting a small margin of difference when declaring them equal.
  /// @include date_time.cpp
  class core_export_ date_time : public xtd::icomparable<date_time>, public xtd::iequatable<date_time>, public xtd::object {
  public:
    /// @name Alias
    
    /// @{
    /// /// @brief Represents a time point of date_time objects.
    using time_point = xtd::ticks;
    /// @}
    
    /// @name Fields
    
    /// @{
    /// @brief Represents the largest possible value of xtd::date_time. This field is read-only.
    /// @remarks The value of this constant is equivalent to 23:59:59.9999999 UTC, December 31, 9999 in the Gregorian calendar, exactly one 100-nanosecond tick before 00:00:00 UTC, January 1, 10000.
    /// @par Examples
    /// The following example instantiates a xtd::date_time object by passing its constructor an xtd::ticks value that represents a number of ticks.
    /// Before invoking the constructor, the example ensures that this value is greater than or equal to date_time::min_value.ticks() and less than or equal to date_time::max_value.ticks().
    /// If not, it throws an xtd::argument_out_of_range_exception.
    /// @include date_time_max_value.cpp
    static const date_time max_value;
    /// @brief Represents the smallest possible value of xtd::date_time. This field is read-only.
    /// @par Examples
    /// The following example instantiates a xtd::date_time object by passing its constructor an xtd::ticks value that represents a number of ticks.
    /// Before invoking the constructor, the example ensures that this value is greater than or equal to date_time::min_value.ticks() and less than or equal to date_time::max_value.ticks().
    /// If not, it throws an xtd::argument_out_of_range_exception.
    /// @include date_time_max_value.cpp
    /// @remarks The value of this constant is equivalent to 00:00:00.0000000 UTC, January 1, 0001, in the Gregorian calendar.
    /// @remarks xtd::date_time::min_vvalue defines the date and time that is assigned to an uninitialized xtd::date_time variable. The following example illustrates this.
    /// @include date_time_min_value.cpp
    static const date_time min_value;
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::date_time structure.
    /// @Remarks xtd::date_time is initialized by default with xtd::date_time::min_value.
    date_time() = default;
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    /// @par Example
    /// The following example demonstrates one of the xtd::date_time constructors.
    /// @include date_time_ticks.cpp
    explicit date_time(xtd::ticks ticks);
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks and to Coordinated Universal Time (UTC) or local time.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    date_time(xtd::ticks ticks, xtd::date_time_kind kind);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, and day.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999. -or- month is less than 1 or greater than 12. -or- day is less than 1 or greater than the number of days in month.
    /// @par Example
    /// The following example uses the date_time(uint32_t, uint32_t, uint32_t) constructor to instantiate a xtd::date_time value. The example also illustrates that this overload creates a xtd::date_time value whose time component equals midnight (or 0:00).
    /// @code
    /// date_time date1(2010, 8, 18);
    /// console::write_line(date1.to_string());
    /// // The example displays the following output:
    /// //      8/18/2010 12:00:00 AM
    /// @endcode
    /// @remarks This constructor interprets year, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32_t year, uint32_t month, uint32_t day);
    /// @brief Initializes a new instance of the xttd::date_time structure to the specified year, month, day, hour, minute, and second.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999. -or- month is less than 1 or greater than 12. -or- day is less than 1 or greater than the number of days in month. -or- hour is less than 0 or greater than 23. -or- minute is less than 0 or greater than 59. -or- second is less than 0 or greater than 59.
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second);
    /// @brief Initializes a new instance of the DateTime structure to the specified year, month, day, hour, minute, second, and Coordinated Universal Time (UTC) or local time.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @param kind One of the enumeration values that indicates whether year, month, day, hour, minute and second specify a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999. -or- month is less than 1 or greater than 12. -or- day is less than 1 or greater than the number of days in month. -or- hour is less than 0 or greater than 23. -or- minute is less than 0 or greater than 59 -or- second is less than 0 or greater than 59.
    /// @par Example
    /// The following example uses the date_time(uint32_t, uint32_t, uint32_tt, uint32_tt, uint32_t, uint32_t, xtd::date_time_kind) constructor to instantiate a xtd::date_time value.
    /// @code
    /// date_time date1(2010, 8, 18, 16, 32, 0, date_time_kind::local);
    /// console::write_line("{0} {1}", date1, date1.kind());
    /// // The example displays the following output, in this case for en-us culture:
    /// //      8/18/2010 4:32:00 PM Localv
    /// @endcode
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, date_time_kind kind);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, day, hour, minute, second, and millisecond.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @param millisecond The milliseconds (0 through 999).
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999. -or- month is less than 1 or greater than 12. -or- day is less than 1 or greater than the number of days in month. -or- hour is less than 0 or greater than 23. -or- minute is less than 0 or greater than 59 -or- second is less than 0 or greater than 59 -or- millisecond is less than 0 or greater than 999.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, day, hour, minute, second, millisecond, and Coordinated Universal Time (UTC) or local time.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @param millisecond The milliseconds (0 through 999).
    /// @param kind One of the enumeration values that indicates whether year, month, day, hour, minute and second specify a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999. -or- month is less than 1 or greater than 12. -or- day is less than 1 or greater than the number of days in month. -or- hour is less than 0 or greater than 23. -or- minute is less than 0 or greater than 59 -or- second is less than 0 or greater than 59 -or- millisecond is less than 0 or greater than 999.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind);
    /// @}
    
    /// @cond
    date_time(const date_time&) = default;
    date_time(date_time&&) = default;
    date_time& operator=(const date_time&) = default;
    /// @endcond
    
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the date component of this instance.
    /// @return A new object with the same date as this instance, and the time value set to 12:00:00 midnight (00:00:00).
    /// @par Example
    /// The following example uses the xtd::date_time::date property to extract the date component of a xtd::date_time value with its time component set to zero (or 0:00:00, or midnight). It also illustrates that, depending on the format string used when displaying the xtd::date_time value, the time component can continue to appear in formatted output.
    /// @include date_time_date.cpp
    /// @remarks The value of the xtd::date_time::kind property of the returned xtd::date_time value is the same as that of the current instance.
    /// @remarks Because the xtd::date_time type represents both dates and times in a single type, it is important to avoid misinterpreting a date returned by the xtd::date property as a date and time.
    date_time date() const noexcept;
    
    /// @brief Gets the day of the month represented by this instance.
    /// @return The day component, expressed as a value between 1 and 31.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::day property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    /// @remarks The xtd::date_time::day property always returns the day of the month in the Gregorian calendar.
    uint32_t day() const noexcept;
    
    /// @brief Gets the day of the week represented by this instance.
    /// @return An enumerated constant that indicates the day of the week of this xtd::date_time value.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::day_of_week property and the xtd::day_of_week enumeration.
    /// @include date_time_day_of_week.cpp
    /// @remarks The value of the constants in the xtd::day_of_week enumeration ranges from xtd::day_of_week::sunday to xtd::day_of_week::saturday. If cast to an integer, its value ranges from zero (which indicates xtd::day_of_week::sunday) to six (which indicates xtd::day_of_week::saturday).
    /// @remarks The xtd::date_time::day_of_week property returns an enumerated constant; it does not reflect a system's regional and language settings. To retrieve a string representing a localized weekday name for a particular date, call one of the overloads of the xtd::date_time::to_string method that includes a format parameter and pass it either the "h" or "H" format strings.
    xtd::day_of_week day_of_week() const noexcept;
    
    /// @brief Gets the day of the year represented by this instance.
    /// @return The day of the year, expressed as a value between 1 and 366.
    /// @par Example
    /// The following example displays the day of the year of December 31 for the years 2010-2020 in the Gregorian calendar. Note that the example shows that December 31 is the 366th day of the year in leap years.
    /// @include date_time_day_of_year.cpp
    /// @remarks The xtd::date_time::day_of_year property takes leap years into account when it calculates the day of the year. The property value always reflects the day of the year in the Gregorian calendar, regardless of the current culture's current calendar.
    uint32_t day_of_year() const noexcept;
    
    /// @brief Gets the hour component of the date represented by this instance.
    /// @return The hour component, expressed as a value between 0 and 23.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::hour property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    /// @remarks The value of the xtd::date_time::hour property is always expressed using a 24-hour clock. To retrieve a string that represents the hour of a date and time using a 12-hour clock, call the xtd::date_time::to_string(ustring) method with the "x" format specifier. For example:
    /// @code
    /// date_time date1(2008, 4, 1, 18, 53, 0);
    /// console::write_line(date1.to_string("X"));                                   // Displays 6
    /// console::write_line("{0}, {1}", date1.to_string("X"), date1.to_string("a")); // Displays 6 PM
    /// @endcode
    uint32_t hour() const noexcept;
    
    /// @brief Gets a value that indicates whether the time represented by this instance is based on local time, Coordinated Universal Time (UTC), or neither.
    /// @return One of the enumeration values that indicates what the current time represents. The default is xtd::date_time_kind::unspecified.
    /// @par Example
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_kind.cpp
    /// @remarks You can explicitly set the xtd::date_time::xtd::date_time::kind property of a new xtd::date_time value to a particular xtd::date_time_kind value by calling the xtd::date_time::specify_kind method.
    /// @remarks The xtd::date_time::kind property allows a xtd::date_time value to clearly reflect either Coordinated Universal Time (UTC) or the local time. In contrast, the xtd::date_time_offset structure can unambiguously reflect any time in any time zone as a single point in time.
    date_time_kind kind() const noexcept;
    
    /// @brief Gets the milliseconds component of the date represented by this instance.
    /// @return The milliseconds component, expressed as a value between 0 and 999.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::millisecond property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    /// @remarks You can display the string representation of the xtd::date::time::millisecond property by using the "b" or "B" format specifier. For example, the following code displays a string that contains the number of milliseconds in a date and time to the console.
    /// @code
    /// date_time date1(2008, 1, 1, 0, 30, 45, 125);
    /// console::write_line("milliseconds: {0:b}", date1); // displays milliseconds: 125
    /// @endcode
    /// @remarks You can also display the millisecond component together with the other components of a date and time value by using the "s" standard format specifier. For example:
    /// @code
    /// date_time date2(2008, 1, 1, 0, 30, 45, 125);
    /// Console.WriteLine("Date: {0:s}", date2);
    /// // Displays the following output to the console:
    /// //      Date: 2008-01-01T00:30:45.1250000
    /// @endcode
    uint32_t millisecond() const noexcept;
    
    /// @brief Gets the minute component of the date represented by this instance.
    /// @return The minute component, expressed as a value between 0 and 59.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::minute property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    uint32_t minute() const noexcept;
    
    /// @brief Gets the month component of the date represented by this instance.
    /// @return The month component, expressed as a value between 1 and 12.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::month property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    uint32_t month() const noexcept;
    
    /// @brief Gets a xtd::date_time object that is set to the current date and time on this computer, expressed as the local time.
    /// @return An object whose value is the current local date and time.
    /// @par Example
    /// The following example uses the xtd::date_time::now and xtd::date_time::utc_now properties to retrieve the current local date and time and the current universal coordinated (UTC) date and time. It then uses the formatting conventions of a number of locale to display the strings, along with the values of the their xtd::datte_time::kind properties.
    /// @include date_time_now.cpp
    /// @remarks The xtd::date_time::now property returns a xtd::date_time value that represents the current date and time on the local computer. Note that there is a difference between a xtd::date_time value, which represents the number of ticks that have elapsed since midnight of January 1, 0001, and the string representation of that xtd::date_time value, which expresses a date and time value in a culture-specific-specific format. For information on formatting date and time values, see the to_string method. The following example displays the short date and time string in a number of culture-specific formats.
    /// @include date_time_now2.cpp
    static date_time now() noexcept;
    
    /// @brief Gets the seconds component of the date represented by this instance.
    /// @return The seconds component, expressed as a value between 0 and 59.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::second property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    uint32_t second() const noexcept;
    /// @brief Gets the number of ticks that represent the date and time of this instance.
    /// @return The number of ticks that represent the date and time of this instance. The value is between xtd::date_time::min_value.ticks and xtd::date_time::max_value.ticks.
    /// @par Examples
    /// The following example uses the xtd::date_time::ticks property to display the number of ticks that have elapsed since the beginning of the century.
    /// @include date_time_ticks2.cpp
    xtd::ticks ticks() const noexcept;
    
    /// @brief Gets the time of day for this instance.
    /// @return A time interval that represents the fraction of the day that has elapsed since midnight.
    /// @par Example
    /// The following example displays the value of the xtd::date_time::time_of_day property for an array of xtd::date_time values. It also contrasts the return value with the string returned by the "t" standard format string in a composite formatting operation.
    /// @include date_time_time_of_day.cpp
    /// @remarks Unlike the xtd::date_time::date property. which returns a xtd::date_time value that represents a date without its time component, the xtd::date_time::time_of_day property returns a xtd::date_time::time_point value that represents a xtd::date_time value's time component.
    /// @remarks If you want to display the time of day or retrieve the string representation of the time of day of a DateTime value, you can instead call an overload of the ToString method that has a format parameter or use the composite formatting feature with the "t" or "T" standard format string.
    time_point time_of_day() const noexcept;
    
    /// @brief Gets the current date.
    /// @return An object that is set to today's date, with the time component set to 00:00:00.
    /// @par Example
    /// The following example uses the xtd::date_time::date property to retrieve the current date. It also illustrates how a xtd::date_time value can be formatted using some of the standard date and time format strings. Note that the output produced by the third call to the xtd::date_time::to_string(const xtd::ustring&) method uses the g format specifier to include the time component, which is zero.
    /// @include date_time_today.cpp
    /// @remarks The return value is a xtd::date_time whose xtd::date_time::kind property returns xtd::date_time_kind::local.
    /// @remarks Because it returns the current date without the current time, the xtd::date_time::today property is suitable for use in applications that work with dates only. In contrast, the xtd::date_time::time_of_day property returns the current time without the current date, and the xtd::date_timextd::date_timextd::date_time::now property returns both the current date and the current time.
    static date_time today() noexcept;
    
    /// @brief Gets a xtd::date_time object that is set to the current date and time on this computer, expressed as the Coordinated Universal Time (UTC).
    /// @return An object whose value is the current UTC date and time.
    /// @par Example
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_king.cpp
    /// @remarks The resolution of this property depends on the system timer, which depends on the underlying operating system. It tends to be between 0.5 and 15 milliseconds.
    /// @remarks The return value is a xtd::date_time whose xtd::date_time::kind property returns xtd::date_time_kind::utc.
    /// @remarks An alternative to using xtd::date_time::utc_now is xtd::date_time_offset::utc_now. While the former indicates that a date and time value is Coordinated Universal Time (UTC) by assigning xtd::date_time_kind::utc to its xtd::date_time::kind property, the latter assigns the date and time value the UTC time's offset (equal to xtd::ticks(0)).
    static date_time utc_now() noexcept;
    
    /// @brief Gets the year component of the date represented by this instance.
    /// @return The year, between 1 and 9999.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::year property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32_t year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = moment.hour();
    ///
    /// // minute gets 57.
    /// uint23_t minute = moment.minute();
    ///
    /// // second gets 32.
    /// uint23_t second = moment.second();
    ///
    /// // millisecond gets 11.
    /// uint23_t millisecond = moment.millisecond();
    /// @endcode
    /// @remarks The xtd::date_time::year property returns the year of the current instance in the Gregorian calendar.
    uint32_t year() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Returns a new xtd::date_time that adds the value of the specified std::chrono::duration to the value of this instance.
    /// @param value A positive or negative time interval.
    /// @return An object whose value is the sum of the date and time represented by this instance and the time interval represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::add method. It calculates the day of the week that is 36 days (864 hours) from this moment.
    /// @include date_time_add.cpp
    /// @remarks You can use the xtd::date_time::add method to add more than one kind of time interval (days, hours, minutes, seconds, or milliseconds) in a single operation. This method's behavior is identical to that of the addition operator. The xtd::date_time::addxtd::date_time structure also supports specialized addition methods (such as xtd::date_time::add_days, xtd::date_time::add_hours, and xtd::date_time::add_minutes) for each time interval.
    /// @remarks The xtd::date_time::add method takes into account leap years and the number of days in a month when performing date arithmetic.
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation. The xtd::date_time::kind property of the new xtd::date_time instance is the same as that of the current instance.
    template<typename rep_t, typename period_t>
    date_time add(std::chrono::duration<rep_t, period_t> value) const {
      return add(std::chrono::duration_cast<time_point>(value));
    }
    /// @brief Returns a new xtd::date_time that adds the value of the specified xtd::date_time::time_point to the value of this instance.
    /// @param value A positive or negative time interval.
    /// @return An object whose value is the sum of the date and time represented by this instance and the time interval represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Example
    /// The following example demonstrates the xtd::date_time::add method. It calculates the day of the week that is 36 days (864 hours) from this moment.
    /// @include date_time_add.cpp
    /// @remarks You can use the xtd::date_time::add method to add more than one kind of time interval (days, hours, minutes, seconds, or milliseconds) in a single operation. This method's behavior is identical to that of the addition operator. The xtd::date_time::addxtd::date_time structure also supports specialized addition methods (such as xtd::date_time::add_days, xtd::date_time::add_hours, and xtd::date_time::add_minutes) for each time interval.
    /// @remarks The xtd::date_time::add method takes into account leap years and the number of days in a month when performing date arithmetic.
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation. The xtd::date_time::kind property of the new xtd::date_time instance is the same as that of the current instance.
    date_time add(time_point value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of days to the value of this instance.
    /// @param value A number of whole and fractional days. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of days represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Example
    /// The following example uses the xtd::date_time::add_days method to determine the day of the week 36 days after the current date.
    /// @include date_time_add_days.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks The fractional part of value is the fractional part of a day. For example, 4.5 is equivalent to 4 days, 12 hours, 0 minutes, 0 seconds, 0 milliseconds, and 0 ticks.
    /// @remarks The xtd::date_time::add_days method takes into account leap years and the number of days in a month when performing date arithmetic.
    date_time add_days(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of hours to the value of this instance.
    /// @param value A number of whole and fractional hours. The value parameter can be negative or positive.A number of whole and fractional hours. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of hours represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Example
    /// The following example uses the xtd::date_time::add_hours method to add a number of whole and fractional values to a date and time. It also illustrates the loss of precision caused by passing the method a value that includes a fractional component.
    /// @include date_time_add_hours.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation. The xtd::date_time::kind property of the returned xtd::date_time object is the same as that of value.
    /// @remarks The fractional part of value is the fractional part of an hour. For example, 4.5 is equivalent to 4 hours, 30 minutes, 0 seconds, 0 milliseconds, and 0 ticks.
    /// @remarks Converting time intervals of less than an hour to a fraction can involve a loss of precision if the result is a non-terminating repeating decimal. (For example, one minute is 0.016667 of an hour.) If this is problematic, you can use the xtd::date_time::add method, which enables you to specify more than one kind of time interval in a single method call and eliminates the need to convert time intervals to fractional parts of an hour.
    date_time add_hours(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of milliseconds to the value of this instance.
    /// @param value A number of whole and fractional milliseconds. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of milliseconds represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Example
    /// The following example uses the xtd::date_timeadd_milliseconds method to add one millisecond and 1.5 milliseconds to a xtd::date_time value. It then displays each new value and displays the difference between it and the original value. The difference is displayed both as a time span and as a number of ticks. The example makes it clear that one millisecond equals 10,000 ticks. It also shows that fractional milliseconds are rounded before performing the addition; the xtd::date_time value that results from adding 1.5 milliseconds to the original date is 2 milliseconds greater than the original date.
    /// @include datte_time_add_milliseconds.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks The fractional part of value is the fractional part of a millisecond. For example, 4.5 is equivalent to 4 milliseconds and 5000 ticks, where one millisecond = 10000 ticks.
    /// @remarks The value parameter is rounded to the nearest integer.
    date_time add_milliseconds(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of minutes to the value of this instance.
    /// @param value A number of whole and fractional minutes. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of minutes represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Example
    /// The following example uses the xtd::date_time::add_minutes method to add a number of whole and fractional values to a date and time.
    /// @include date_tile_add_minutes.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks The fractional part of value is the fractional part of a minute. For example, 4.5 is equivalent to 4 minutes, 30 seconds, 0 milliseconds, and 0 ticks.
    date_time add_minutes(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of months to the value of this instance.
    /// @param months A number of months. The months parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and months
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value. -or- months is less than -120,000 or greater than 120,000.
    /// @par Example
    /// The following example adds between zero and fifteen months to the last day of December, 2015. In this case, the xtd::date_time::add_months method returns the date of the last day of each month, and successfully handles leap years.
    /// @include date_time_add_months.cpp
    date_time add_months(int32_t months) const;
    date_time add_seconds(double value) const;
    date_time add_ticks(int64 value) const;
    date_time add_years(int32_t value) const;
    int32_t compare_to(const object& obj) const noexcept override;
    int32_t compare_to(const date_time& value) const noexcept override;
    static int32_t days_in_month(uint32_t year, uint32_t month);
    
    bool equals(const date_time&) const noexcept override;
    bool equals(const object&) const noexcept override;
    static date_time from_binary(int64_t date_data);
    static date_time from_file_time(xtd::ticks fileTime);
    static date_time from_file_time_utc(xtd::ticks fileTime);
    template<typename rep_t, typename period_t>
    static date_time from_duration(std::chrono::duration<rep_t, period_t> value) {
      return from_duration(value, date_time_kind::unspecified);
    }
    template<typename rep_t, typename period_t>
    static date_time from_duration(std::chrono::duration<rep_t, period_t> value, date_time_kind kind) {
      return date_time(std::chrono::duration_cast<xtd::ticks>(value), kind);
    }
    static date_time from_time_t(std::time_t value);
    static date_time from_time_t(std::time_t value, date_time_kind kind);
    static date_time from_tm(const std::tm& value);
    static date_time from_tm(const std::tm& value, date_time_kind kind);
    bool is_daylight_saving_time() const noexcept;
    static bool is_leap_year(uint32_t year);
    xtd::ustring parse() const;
    static date_time specify_kind(date_time value, date_time_kind kind);
    
    /// @brief Returns a xtd::ustring that represents the current xtd::date_time.
    /// @param format Format-control String.
    /// @return A xtd::ustring that represents the current xtdd::date_time.
    /// @remarks The formatting codes for sprintf are listed below:
    /// | Format | Print                                                                                                                       |
    /// |--------|-----------------------------------------------------------------------------------------------------------------------------|
    /// | \%a    | writes abbreviated weekday name, e.g. Fri (locale dependent).                                                               |
    /// | \%A    | writes full weekday name, e.g. Friday (locale dependent).                                                                   |
    /// | \%b    | writes abbreviated month name, e.g. Oct (locale dependent)                                                                  |
    /// | \%B    | writes full month name, e.g. October (locale dependent).                                                                    |
    /// | \%c    | writes standard date and time string, e.g. Sun Oct 17 04:41:13 2010 (locale dependent).                                     |
    /// | \%C    | writes first 2 digits of year as a decimal number (range [00,99]).                                                          |
    /// | \%d    | writes day of the month as a decimal number (range [01,31]).                                                                |
    /// | \%D    | equivalent to "%m/%d/%y".                                                                                                   |
    /// | \%e    | writes day of the month as a decimal number (range [1,31]).                                                                 |
    /// | \%Ec   | writes alternative date and time string, e.g. using 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale.  |
    /// | \%EC   | Writes name of the base year (period) in the locale's alternative representation, e.g. 平成 (Heisei era) in ja_JP            |
    /// | \%Ex   | writes alternative date representation, e.g. using 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale.   |
    /// | \%EX   | writes alternative time representation (locale dependent).                                                                  |
    /// | \%Ey   | writes year as offset from locale's alternative calendar period %EC.                                                        |
    /// | \%EY   | writes year in the alternative representation, e.g.平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale.   |
    /// | \%F    | equivalent to "%Y-%m-%d" (the ISO 8601 date format).                                                                        |
    /// | \%g    | writes last 2 digits of ISO 8601 week-based year, i.e. the year that contains the specified week (range [00,99]).           |
    /// | \%G    | writes ISO 8601 week-based year, i.e. the year that contains the specified week.                                            |
    /// | \%h    | synonym of b.                                                                                                               |
    /// | \%H    | writes hour as a decimal number, 24 hour clock (range [00-23]).                                                             |
    /// | \%I    | writes hour as a decimal number, 12 hour clock (range [01,12]).                                                             |
    /// | \%j    | writes day of the year as a decimal number (range [001,366]).                                                               |
    /// | \%m    | writes month as a decimal number (range [01,12]).                                                                           |
    /// | \%M    | writes minute as a decimal number (range [00,59]).                                                                          |
    /// | \%Od   | writes zero-based day of the month using the alternative numeric system, e.g 二十七 instead of 27 in ja_JP locale.           |
    /// | \%Oe   | writes one-based day of the month using the alternative numeric system, e.g. 二十七 instead of 27 in ja_JP locale.           |
    /// | \%OH   | writes hour from 24-hour clock using the alternative numeric system, e.g. 十八 instead of 18 in ja_JP locale.                |
    /// | \%OI   | writes hour from 12-hour clock using the alternative numeric system, e.g. 六 instead of 06 in ja_JP locale.                 |
    /// | \%Om   | writes month using the alternative numeric system, e.g. 十二 instead of 12 in ja_JP locale.                                  |
    /// | \%OM   | writes minute using the alternative numeric system, e.g. 二十五 instead of 25 in ja_JP locale.                               |
    /// | \%OS   | writes second using the alternative numeric system, e.g. 二十四 instead of 24 in ja_JP locale.                               |
    /// | \%Ou   | writes weekday, where Monday is 1, using the alternative numeric system, e.g. 二 instead of 2 in ja_JP locale.              |
    /// | \%OU   | writes week of the year, as by %U, using the alternative numeric system, e.g. 五十二 instead of 52 in ja_JP locale.           |
    /// | \%OV   | writes week of the year, as by %V, using the alternative numeric system, e.g. 五十二 instead of 52 in ja_JP locale.           |
    /// | \%Ow   | writes weekday, where Sunday is 0, using the alternative numeric system, e.g. 二 instead of 2 in ja_JP locale.               |
    /// | \%OW   | writes week of the year, as by %W, using the alternative numeric system, e.g. 五十二 instead of 52 in ja_JP locale.           |
    /// | \%Oy   | writes last 2 digits of year using the alternative numeric system, e.g. 十一 instead of 11 in ja_JP locale.                  |
    /// | \%p    | writes localized a.m. or p.m. (locale dependent).                                                                           |
    /// | \%r    | writes localized 12-hour clock time (locale dependent).                                                                     |
    /// | \%R    | equivalent to "%H:%M".                                                                                                      |
    /// | \%S    | writes second as a decimal number (range [00,60]).                                                                          |
    /// | \%T    | equivalent to "%H:%M:%S" (the ISO 8601 time format)                                                                         |
    /// | \%u    | writes weekday as a decimal number, where Monday is 1 (ISO 8601 format) (range [1-7]).                                      |
    /// | \%U    | writes week of the year as a decimal number (Sunday is the first day of the week) (range [00,53]).                          |
    /// | \%V    | writes ISO 8601 week of the year (range [01,53]).                                                                           |
    /// | \%w    | writes weekday as a decimal number, where Sunday is 0 (range [0-6]).                                                        |
    /// | \%W    | writes week of the year as a decimal number (Monday is the first day of the week) (range [00,53]).                          |
    /// | \%x    | writes localized date representation (locale dependent).                                                                    |
    /// | \%X    | writes localized time representation, e.g. 18:40:20 or 6:40:20 PM (locale dependent).                                       |
    /// | \%y    | writes last 2 digits of year as a decimal number (range [00,99]).                                                           |
    /// | \%Y    | writes year as a decimal number, e.g. 2017.                                                                                 |
    /// | \%z    | writes offset from UTC in the ISO 8601 format (e.g. -0430), or no characters if the time zone information is not available. |
    /// | \%Z    | writes locale-dependent time zone name or abbreviation, or no characters if the time zone information is not available.     |
    /// | \%\%   | writes literal %. The full conversion specification must be %%.                                                             |
    /// | \%n    | writes newline character.                                                                                                   |
    /// | \%t    | writes horizontal tab character.                                                                                            |
    /// @par Example
    /// The foloowwing examplel shows hoow to use xtd::date_time::sprintf with differentt formats
    /// @include date_time_sprintf.cpp
    /// @remarks See <a href="https://en.cppreference.com/w/cpp/io/manip/put_time">std::put_time</a> for more information.
    xtd::ustring sprintf(const ustring& format) const;
    time_point subtract(const date_time& value) const;
    template<typename rep_t, typename period_t>
    date_time subtract(std::chrono::duration<rep_t, period_t> value) const {
      return subtract(std::chrono::duration_cast<time_point>(value));
    }
    date_time subtract(time_point value) const;
    int64_t to_binary() const;
    date_time to_local_time() const;
    const xtd::ustring to_long_date_string() const;
    const xtd::ustring to_long_time_string() const;
    const xtd::ustring to_short_date_string() const;
    const xtd::ustring to_short_time_string() const;
    xtd::ustring to_string() const noexcept override;
    xtd::ustring to_string(const ustring& format) const;
    std::time_t to_time_t() const;
    std::tm to_tm() const;
    date_time to_universal_time() const;
    /// @}
    
    /// @name Operators
    
    /// @{
    operator time_point() const;
    date_time& operator+=(date_time value);
    date_time& operator-=(date_time value);
    date_time operator+();
    date_time operator-();
    date_time operator+(const date_time& value) const;
    date_time operator-(const date_time& value) const;
    date_time& operator++();
    date_time operator++(int);
    date_time& operator--();
    date_time operator--(int);
    /// @}
    
  private:
    friend class time_zone_info;
    xtd::ticks utc_offset() const;
    void get_date_time(uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year,  int32_t& day_of_week) const;
    void set_date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind);
    
    xtd::ticks value_ {0};
    date_time_kind kind_ {date_time_kind::unspecified};
  };
  
  /// @cond
  std::ostream& operator <<(std::ostream& os, const date_time& value) noexcept;
  /// @endcond
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline std::string to_string(const date_time& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
}
