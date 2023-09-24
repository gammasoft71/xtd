/// @file
/// @brief Contains xtd::date_time class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "chrono"
#include <ctime>
#include "date_time_kind"
#include "day_of_week"
#include "icomparable"
#include "iequatable"
#include "month_of_year"
#include "object"
#include "ticks"
#include "time_span"
#include "ustring"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class time_zone_info;
  /// @endcond
  
  /// @name Boxed types
  
  /// @{
  /// @brief Represents an instant in time, typically expressed as a date and time of day.
  /// @code
  /// class core_export_ date_time : public xtd::icomparable<date_time>, public xtd::iequatable<date_time>, public xtd::object
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::date_time
  /// @par Implements
  /// xtd::icomparable <>, xtd::iequatable <>
  /// @par Header
  /// @code #include <xtd/date_time> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks The xtd::date_time value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.
  /// @remarks Time values are measured in 100-nanosecond units called ticks. A particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar. The number excludes ticks that would be added by leap seconds. For example, a ticks value of 31241376000000000L represents the date Friday, January 01, 0100 12:00:00 midnight. A xtd::date_time value is always expressed in the context of an explicit or default calendar.
  /// @note If you are working with a ticks value that you want to convert to some other time interval, such as minutes or seconds, you should use the xtd::time_span::ticks_per_day, xtd::time_span::ticks_per_hour, xtd::time_span::ticks_per_minute, xtd::time_span::ticks_per_second, or xtd::time_span::ticks_per_millisecond constant to perform the conversion. For example, to add the number of seconds represented by a specified number of ticks to the xtd::date_time::second component of a xtd::date_time value, you can use the expression date_value.second() + n_ticks/timespan.ticks_per_second.
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
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
    /// @remarks xtd::date_time::min_value defines the date and time that is assigned to an uninitialized xtd::date_time variable. The following example illustrates this.
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
    /// @par Examples
    /// The following example demonstrates one of the xtd::date_time constructors.
    /// @include date_time_ticks.cpp
    explicit date_time(int64 ticks);
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    /// @par Examples
    /// The following example demonstrates one of the xtd::date_time constructors.
    /// @include date_time_ticks.cpp
    explicit date_time(xtd::ticks ticks);
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks and to Coordinated Universal Time (UTC) or local time.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    date_time(int64 ticks, xtd::date_time_kind kind);
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks and to Coordinated Universal Time (UTC) or local time.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    date_time(xtd::ticks ticks, xtd::date_time_kind kind);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, and day.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999.<br>-or-<br>month is less than 1 or greater than 12.<br>-or-<br>day is less than 1 or greater than the number of days in month.
    /// @par Examples
    /// The following example uses the date_time(uint32, uint32, uint32) constructor to instantiate a xtd::date_time value. The example also illustrates that this overload creates a xtd::date_time value whose time component equals midnight (or 0:00).
    /// @code
    /// date_time date1(2010, 8, 18);
    /// console::write_line(date1.to_string());
    /// // The example displays the following output:
    /// //      8/18/2010 12:00:00 AM
    /// @endcode
    /// @remarks This constructor interprets year, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32 year, uint32 month, uint32 day);
    /// @brief Initializes a new instance of the xttd::date_time structure to the specified year, month, day, hour, minute, and second.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999.<br>-or-<br>month is less than 1 or greater than 12.<br>-or-<br>day is less than 1 or greater than the number of days in month.<br>-or-<br>hour is less than 0 or greater than 23.<br>-or-<br>minute is less than 0 or greater than 59.<br>-or-<br>second is less than 0 or greater than 59.
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, day, hour, minute, second, and Coordinated Universal Time (UTC) or local time.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @param kind One of the enumeration values that indicates whether year, month, day, hour, minute and second specify a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999.<br>-or-<br>month is less than 1 or greater than 12.<br>-or-<br>day is less than 1 or greater than the number of days in month.<br>-or-<br>hour is less than 0 or greater than 23.<br>-or-<br>minute is less than 0 or greater than 59<br>-or-<br>second is less than 0 or greater than 59.
    /// @par Examples
    /// The following example uses the date_time(uint32, uint32, uint32t, uint32t, uint32, uint32, xtd::date_time_kind) constructor to instantiate a xtd::date_time value.
    /// @code
    /// date_time date1(2010, 8, 18, 16, 32, 0, date_time_kind::local);
    /// console::write_line("{0} {1}", date1, date1.kind());
    /// // The example displays the following output, in this case for en-us culture:
    /// //      8/18/2010 4:32:00 PM Localv
    /// @endcode
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, date_time_kind kind);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, day, hour, minute, second, and millisecond.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @param millisecond The milliseconds (0 through 999).
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999.<br>-or-<br>month is less than 1 or greater than 12.<br>-or-<br>day is less than 1 or greater than the number of days in month.<br>-or-<br>hour is less than 0 or greater than 23.<br>-or-<br>minute is less than 0 or greater than 59<br>-or-<br>second is less than 0 or greater than 59<br>-or-<br>millisecond is less than 0 or greater than 999.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, uint32 millisecond);
    /// @brief Initializes a new instance of the xtd::date_time structure to the specified year, month, day, hour, minute, second, millisecond, and Coordinated Universal Time (UTC) or local time.
    /// @param year The year (1 through 9999).
    /// @param month The month (1 through 12).
    /// @param day The day (1 through the number of days in month).
    /// @param hour The hours (0 through 23).
    /// @param minute The minutes (0 through 59).
    /// @param second The seconds (0 through 59).
    /// @param millisecond The milliseconds (0 through 999).
    /// @param kind One of the enumeration values that indicates whether year, month, day, hour, minute and second specify a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999.<br>-or-<br>month is less than 1 or greater than 12.<br>-or-<br>day is less than 1 or greater than the number of days in month.<br>-or-<br>hour is less than 0 or greater than 23.<br>-or-<br>minute is less than 0 or greater than 59<br>-or-<br>second is less than 0 or greater than 59<br>-or-<br>millisecond is less than 0 or greater than 999.
    /// @remarks This constructor interpretsyear, month, and day as a year, month, and day in the Gregorian calendar.
    date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, uint32 millisecond, date_time_kind kind);
    /// @}
    
    /// @cond
    date_time(const date_time&) = default;
    date_time(date_time&&) = default;
    date_time& operator =(const date_time&) = default;
    /// @endcond
    
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the date component of this instance.
    /// @return A new object with the same date as this instance, and the time value set to 12:00:00 midnight (00:00:00).
    /// @par Examples
    /// The following example uses the xtd::date_time::date property to extract the date component of a xtd::date_time value with its time component set to zero (or 0:00:00, or midnight). It also illustrates that, depending on the format string used when displaying the xtd::date_time value, the time component can continue to appear in formatted output.
    /// @include date_time_date.cpp
    /// @remarks The value of the xtd::date_time::kind property of the returned xtd::date_time value is the same as that of the current instance.
    /// @remarks Because the xtd::date_time type represents both dates and times in a single type, it is important to avoid misinterpreting a date returned by the xtd::date property as a date and time.
    date_time date() const noexcept;
    
    /// @brief Gets the day of the month represented by this instance.
    /// @return The day component, expressed as a value between 1 and 31.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::day property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
    ///
    /// // month gets 1 (January).
    /// uint23_t month = moment.month();
    ///
    /// // day gets 13.
    /// uint23_t day = moment.day();
    ///
    /// // hour gets 3.
    /// uint23_t hour = momentour();
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
    uint32 day() const noexcept;
    
    /// @brief Gets the day of the week represented by this instance.
    /// @return An enumerated constant that indicates the day of the week of this xtd::date_time value.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::day_of_week property and the xtd::day_of_week enumeration.
    /// @include date_time_day_of_week.cpp
    /// @remarks The value of the constants in the xtd::day_of_week enumeration ranges from xtd::day_of_week::sunday to xtd::day_of_week::saturday. If cast to an integer, its value ranges from zero (which indicates xtd::day_of_week::sunday) to six (which indicates xtd::day_of_week::saturday).
    /// @remarks The xtd::date_time::day_of_week property returns an enumerated constant; it does not reflect a system's regional and language settings. To retrieve a string representing a localized weekday name for a particular date, call one of the overloads of the xtd::date_time::to_string method that includes a format parameter and pass it either the "h" or "H" format strings.
    xtd::day_of_week day_of_week() const noexcept;
    
    /// @brief Gets the day of the year represented by this instance.
    /// @return The day of the year, expressed as a value between 1 and 366.
    /// @par Examples
    /// The following example displays the day of the year of December 31 for the years 2010-2020 in the Gregorian calendar. Note that the example shows that December 31 is the 366th day of the year in leap years.
    /// @include date_time_day_of_year.cpp
    /// @remarks The xtd::date_time::day_of_year property takes leap years into account when it calculates the day of the year. The property value always reflects the day of the year in the Gregorian calendar, regardless of the current culture's current calendar.
    uint32 day_of_year() const noexcept;
    
    /// @brief Gets the hour component of the date represented by this instance.
    /// @return The hour component, expressed as a value between 0 and 23.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::hour property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
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
    uint32 hour() const noexcept;
    
    /// @brief Gets a value that indicates whether the time represented by this instance is based on local time, Coordinated Universal Time (UTC), or neither.
    /// @return One of the enumeration values that indicates what the current time represents. The default is xtd::date_time_kind::unspecified.
    /// @par Examples
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_kind.cpp
    /// @remarks You can explicitly set the xtd::date_time::xtd::date_time::kind property of a new xtd::date_time value to a particular xtd::date_time_kind value by calling the xtd::date_time::specify_kind method.
    /// @remarks The xtd::date_time::kind property allows a xtd::date_time value to clearly reflect either Coordinated Universal Time (UTC) or the local time. In contrast, the xtd::date_time_offset structure can unambiguously reflect any time in any time zone as a single point in time.
    date_time_kind kind() const noexcept;
    
    /// @brief Gets the milliseconds component of the date represented by this instance.
    /// @return The milliseconds component, expressed as a value between 0 and 999.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::millisecond property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
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
    uint32 millisecond() const noexcept;
    
    /// @brief Gets the minute component of the date represented by this instance.
    /// @return The minute component, expressed as a value between 0 and 59.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::minute property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
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
    uint32 minute() const noexcept;
    
    /// @brief Gets the month component of the date represented by this instance.
    /// @return The month component, expressed as a value between 1 and 12.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::month property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
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
    uint32 month() const noexcept;
    
    /// @brief Gets a xtd::date_time object that is set to the current date and time on this computer, expressed as the local time.
    /// @return An object whose value is the current local date and time.
    /// @par Examples
    /// The following example uses the xtd::date_time::now and xtd::date_time::utc_now properties to retrieve the current local date and time and the current universal coordinated (UTC) date and time. It then uses the formatting conventions of a number of locale to display the strings, along with the values of the their xtd::datte_time::kind properties.
    /// @include date_time_now.cpp
    /// @remarks The xtd::date_time::now property returns a xtd::date_time value that represents the current date and time on the local computer. Note that there is a difference between a xtd::date_time value, which represents the number of ticks that have elapsed since midnight of January 1, 0001, and the string representation of that xtd::date_time value, which expresses a date and time value in a culture-specific-specific format. For information on formatting date and time values, see the to_string method. The following example displays the short date and time string in a number of culture-specific formats.
    /// @include date_time_now2.cpp
    static date_time now() noexcept;
    
    /// @brief Gets the seconds component of the date represented by this instance.
    /// @return The seconds component, expressed as a value between 0 and 59.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::second property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
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
    uint32 second() const noexcept;

    /// @brief Gets the number of ticks that represent the date and time of this instance.
    /// @return The number of ticks that represent the date and time of this instance. The value is between xtd::date_time::min_value.ticks and xtd::date_time::max_value.ticks.
    /// @par Examples
    /// The following example uses the xtd::date_time::ticks property to display the number of ticks that have elapsed since the beginning of the century.
    /// @include date_time_ticks2.cpp
    int64 ticks() const noexcept;
    
    /// @brief Gets the number of ticks that represent the date and time of this instance.
    /// @return The number of ticks that represent the date and time of this instance. The value is between xtd::date_time::min_value.ticks and xtd::date_time::max_value.ticks.
    /// @par Examples
    /// The following example uses the xtd::date_time::ticks property to display the number of ticks that have elapsed since the beginning of the century.
    /// @include date_time_ticks2.cpp
    xtd::ticks ticks_duration() const noexcept;

    /// @brief Gets the time of day for this instance.
    /// @return A time interval that represents the fraction of the day that has elapsed since midnight.
    /// @par Examples
    /// The following example displays the value of the xtd::date_time::time_of_day property for an array of xtd::date_time values. It also contrasts the return value with the string returned by the "t" standard format string in a composite formatting operation.
    /// @include date_time_time_of_day.cpp
    /// @remarks Unlike the xtd::date_time::date property. which returns a xtd::date_time value that represents a date without its time component, the xtd::date_time::time_of_day property returns a xtd::time_span value that represents a xtd::date_time value's time component.
    /// @remarks If you want to display the time of day or retrieve the string representation of the time of day of a xtd::date_time value, you can instead call an overload of the ToString method that has a format parameter or use the composite formatting feature with the "t" or "T" standard format string.
    xtd::time_span time_of_day() const noexcept;
    
    /// @brief Gets the current date.
    /// @return An object that is set to today's date, with the time component set to 00:00:00.
    /// @par Examples
    /// The following example uses the xtd::date_time::date property to retrieve the current date. It also illustrates how a xtd::date_time value can be formatted using some of the standard date and time format strings. Note that the output produced by the third call to the xtd::date_time::to_string(const xtd::ustring&) method uses the g format specifier to include the time component, which is zero.
    /// @include date_time_today.cpp
    /// @remarks The return value is a xtd::date_time whose xtd::date_time::kind property returns xtd::date_time_kind::local.
    /// @remarks Because it returns the current date without the current time, the xtd::date_time::today property is suitable for use in applications that work with dates only. In contrast, the xtd::date_time::time_of_day property returns the current time without the current date, and the xtd::date_timextd::date_timextd::date_time::now property returns both the current date and the current time.
    static date_time today() noexcept;
    
    /// @brief Gets a xtd::date_time object that is set to the current date and time on this computer, expressed as the Coordinated Universal Time (UTC).
    /// @return An object whose value is the current UTC date and time.
    /// @par Examples
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_king.cpp
    /// @remarks The resolution of this property depends on the system timer, which depends on the underlying operating system. It tends to be between 0.5 and 15 milliseconds.
    /// @remarks The return value is a xtd::date_time whose xtd::date_time::kind property returns xtd::date_time_kind::utc.
    /// @remarks An alternative to using xtd::date_time::utc_now is xtd::date_time_offset::utc_now. While the former indicates that a date and time value is Coordinated Universal Time (UTC) by assigning xtd::date_time_kind::utc to its xtd::date_time::kind property, the latter assigns the date and time value the UTC time's offset (equal to xtd::ticks(0)).
    static date_time utc_now() noexcept;
    
    /// @brief Gets the year component of the date represented by this instance.
    /// @return The year, between 1 and 9999.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::year property.
    /// @code
    /// xtd::date_time moment(1999, 1, 13, 3, 57, 32, 11);
    /// // year gets 1999.
    /// uint32 year = moment.year();
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
    uint32 year() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Returns a new xtd::date_time that adds the value of the specified xtd::time_span to the value of this instance.
    /// @param value A positive or negative time interval.
    /// @return An object whose value is the sum of the date and time represented by this instance and the time interval represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::add method. It calculates the day of the week that is 36 days (864 hours) from this moment.
    /// @include date_time_add.cpp
    /// @remarks You can use the xtd::date_time::add method to add more than one kind of time interval (days, hours, minutes, seconds, or milliseconds) in a single operation. This method's behavior is identical to that of the addition operator. The xtd::date_time::addxtd::date_time structure also supports specialized addition methods (such as xtd::date_time::add_days, xtd::date_time::add_hours, and xtd::date_time::add_minutes) for each time interval.
    /// @remarks The xtd::date_time::add method takes into account leap years and the number of days in a month when performing date arithmetic.
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation. The xtd::date_time::kind property of the new xtd::date_time instance is the same as that of the current instance.
    date_time add(const xtd::time_span& value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of days to the value of this instance.
    /// @param value A number of whole and fractional days. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of days represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Examples
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
    /// @par Examples
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
    /// @par Examples
    /// The following example uses the xtd::date_timeadd_milliseconds method to add one millisecond and 1.5 milliseconds to a xtd::date_time value. It then displays each new value and displays the difference between it and the original value. The difference is displayed both as a time span and as a number of ticks. The example makes it clear that one millisecond equals 10,000 ticks. It also shows that fractional milliseconds are rounded before performing the addition; the xtd::date_time value that results from adding 1.5 milliseconds to the original date is 2 milliseconds greater than the original date.
    /// @include date_time_add_milliseconds.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks The fractional part of value is the fractional part of a millisecond. For example, 4.5 is equivalent to 4 milliseconds and 5000 ticks, where one millisecond = 10000 ticks.
    /// @remarks The value parameter is rounded to the nearest integer.
    date_time add_milliseconds(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of minutes to the value of this instance.
    /// @param value A number of whole and fractional minutes. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of minutes represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Examples
    /// The following example uses the xtd::date_time::add_minutes method to add a number of whole and fractional values to a date and time.
    /// @include date_tile_add_minutes.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks The fractional part of value is the fractional part of a minute. For example, 4.5 is equivalent to 4 minutes, 30 seconds, 0 milliseconds, and 0 ticks.
    date_time add_minutes(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of months to the value of this instance.
    /// @param months A number of months. The months parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and months
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.<br>-or-<br>months is less than -120,000 or greater than 120,000.
    /// @par Examples
    /// The following example adds between zero and fifteen months to the last day of December, 2015. In this case, the xtd::date_time::add_months method returns the date of the last day of each month, and successfully handles leap years.
    /// @include date_time_add_months.cpp
    /// @remarks This method does not change the value of this xtd::date_time object. Instead, it returns a new xtd::date_time object whose value is the result of this operation.
    /// @remarks The xtd::date_time::add_months method calculates the resulting month and year, taking into account leap years and the number of days in a month, then adjusts the day part of the resulting xtd::date_time object. If the resulting day is not a valid day in the resulting month, the last valid day of the resulting month is used. For example, March 31st + 1 month = April 30th, and March 31st - 1 month = February 28 for a non-leap year and February 29 for a leap year.
    date_time add_months(int32 months) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of seconds to the value of this instance.
    /// @param value A number of whole and fractional seconds. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of seconds represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @par Examples
    /// The following example uses the xtd::date_time::add_seconds method to add 30 seconds and the number of seconds in one day to a xtd::date_time value. It then displays each new value and displays the difference between it and the original value. The difference is displayed both as a time span and as a number of ticks.
    /// @include date_time_seconds.cpp
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks The fractional part of value is the fractional part of a second. For example, 4.5 is equivalent to 4 seconds, 500 milliseconds, and 0 ticks.
    date_time add_seconds(double value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of ticks to the value of this instance.
    /// @param value A number of 100-nanosecond ticks. The value parameter can be positive or negative.
    /// @return An object whose value is the sum of the date and time represented by this instance and the time represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    date_time add_ticks(int64 value) const;
    
    /// @brief Returns a new xtd::date_time that adds the specified number of years to the value of this instance.
    /// @param value A number of years. The value parameter can be negative or positive.
    /// @return An object whose value is the sum of the date and time represented by this instance and the number of years represented by value.
    /// @exception xtd::argument_out_of_range_exception The resulting xtd::date_time is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @remarks This method does not change the value of this xtd::date_time object. Instead, it returns a new xtd::date_time object whose value is the result of this operation.
    /// @remarks The xtd::date_time::add_years method calculates the resulting year taking into account leap years. The month and time-of-day part of the resulting xtd::date_time object remains the same as this instance.
    /// @remarks If the current instance represents the leap day in a leap year, the return value depends on the target date:
    /// * If value + xtd::date_time::year() is also a leap year, the return value represents the leap day in that year. For example, if four years is added to February 29, 2012, the date returned is February 29, 2016.
    /// * If value + xtd::date_time::year() is not a leap year, the return value represents the day before the leap day in that year. For example, if one year is added to February 29, 2012, the date returned is February 28, 2013.
    /// @par Examples
    /// The following example illustrates using the xtd::date_time::add_years method with a xtd::date_time value that represents a leap year day. It displays the date for the fifteen years prior to and the fifteen years that follow February 29, 2000.
    date_time add_years(int32 value) const;
    
    int32 compare_to(const date_time& value) const noexcept override;
    
    /// @brief Returns the number of days in the specified month and year.
    /// @param year The year.
    /// @param month The month (one of xtd::month_of_year values).
    /// @return The number of days in month for the specified year.<br>
    /// For example, if month equals 2 for February, the return value is 28 or 29 depending upon whether year is a leap year.
    /// @exception xtd::argument_out_of_range_exception month is less than 1 or greater than 12.<br>-or-<br>year is less than 1 or greater than 9999.
    /// @par Examples
    /// The following example demonstrates how to use the xtd::date_time::days_in_month method to determine the number of days in July 2001, February 1998 (a non-leap year), and February 1996 (a leap year).
    /// @include date_time_days_in_month.cpp
    /// @par Examples
    /// The following example displays the number of days in each month of a year specified in an integer array.
    /// @include date_time_days_in_month2.cpp
    /// @remarks The xtd::date_time::days_in_month method always interprets month and year as the month and year of the Gregorian calendar.
    static int32 days_in_month(uint32 year, month_of_year month);
    
    /// @brief Returns the number of days in the specified month and year.
    /// @param year The year.
    /// @param month The month (a number ranging from 1 to 12).
    /// @return The number of days in month for the specified year.<br>
    /// For example, if month equals 2 for February, the return value is 28 or 29 depending upon whether year is a leap year.
    /// @exception xtd::argument_out_of_range_exception month is less than 1 or greater than 12.<br>-or-<br>year is less than 1 or greater than 9999.
    /// @par Examples
    /// The following example demonstrates how to use the xtd::date_time::days_in_month method to determine the number of days in July 2001, February 1998 (a non-leap year), and February 1996 (a leap year).
    /// @include date_time_days_in_month.cpp
    /// @par Examples
    /// The following example displays the number of days in each month of a year specified in an integer array.
    /// @include date_time_days_in_month2.cpp
    /// @remarks The xtd::date_time::days_in_month method always interprets month and year as the month and year of the Gregorian calendar.
    static int32 days_in_month(uint32 year, uint32 month);
    
    bool equals(const date_time&) const noexcept override;
    
    /// @brief Deserializes a 64-bit binary value and recreates an original serialized xtd::date_time object.
    /// @param date_data A 64-bit signed integer that encodes the xtd::date_time::kind property in a 2-bit field and the xtd::date_time::ticks property in a 62-bit field.
    /// @return An object that is equivalent to the xtd::date_time object that was serialized by the xtd::date_time::to_binary() method.
    /// @exception xtd::argument_exception date_data is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @remarks Use the xtd::date_time::to_binary method to convert the value of the current xtd::date_time object to a binary value. Subsequently, use the binary value and the xtd::date_time::from_binary method to recreate the original xtd::date_time object.
    /// @note In some cases, the xtd::date_time value returned by the xtd::date_time::from_binary method is not identical to the original xtd::date_time value supplied to the xtd::date_time::to_binary method.
    static date_time from_binary(int64 date_data);
    
    /// @brief Converts the specified Windows file time to an equivalent local time.
    /// @param file_time A Windows file time expressed in ticks.
    /// @return An object that represents the local time equivalent of the date and time represented by the file_time parameter.
    /// @exception xtd::argument_out_of_range_exception file_time is less than 0 or represents a time greater than xtd::date_time:::max_value.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::from_file_time method.
    /// @code
    /// xtd::ticks file_age(int64 file_creation_time) {
    ///   xtd::date_time now = xtd::date_time::now();
    ///   try {
    ///     xtd::date_time fcreation_fime = xtd::date_time::from_file_time(file_creation_time);
    ///     xtd::ticks file_age = now.subtract(fcreation_time);
    ///     return file_age;
    ///   } catch (const xtd::argument_out_of_range_exception&) {
    ///     // file_creation_time is not valid, so re-throw the exception.
    ///     throw;
    ///   }
    /// }
    /// @endcode
    /// @remarks A Windows file time is a 64-bit value that represents the number of 100-nanosecond intervals that have elapsed since 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC). Windows uses a file time to record when an application creates, accesses, or writes to a file.
    /// @remarks The file_time parameter specifies a file time expressed in 100-nanosecond ticks.
    /// @remarks The return value is a xtd::date_time whose xtd::date_time::kind property is xtd::date_time_kind::local.
    static date_time from_file_time(int64 file_time);
    /// @brief Converts the specified Windows file time to an equivalent UTC time.
    /// @param file_time A Windows file time expressed in ticks.
    /// @return An object that represents the UTC time equivalent of the date and time represented by the file_time parameter.
    /// @exception xtd::argument_out_of_range_exception file_time is less than 0 or represents a time greater than xtd::date_time:::max_value.
    /// @remarks A Windows file time is a 64-bit value that represents the number of 100-nanosecond intervals that have elapsed since 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC). Windows uses a file time to record when an application creates, accesses, or writes to a file.
    /// @remarks The file_time parameter specifies a file time expressed in 100-nanosecond ticks.
    /// @remarks The return value is a xtd::date_time whose xtd::date_time::kind property is xtd::date_time:::utc.
    static date_time from_file_time_utc(int64 file_time);
    
    /// @brief Converts the specified xtd::time_span to an equivalent unspecified time.
    /// @param value A time interval from the start of the Clock's epoch.
    /// @return An object that represents the unspecified time equivalent of the date and time represented by the file_time parameter.
    /// @exception xtd::argument_out_of_range_exception value is less than xtd::date_time:::min_value or represents a time greater than xtd::date_time:::max_value.
    static date_time from_duration(const time_span& value);
    /// @brief Converts the specified xtd::time_span to an equivalent to Coordinated Universal Time (UTC) or local time..
    /// @param value A time interval from the start of the Clock's epoch.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @return An object that represents the unspecified time equivalent of the date and time represented by the file_time parameter.
    /// @exception xtd::argument_out_of_range_exception value is less than xtd::date_time:::min_value or represents a time greater than xtd::date_time:::max_value.
    static date_time from_duration(const time_span& value, date_time_kind kind);

    /// @brief Converts the specified <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a> to an equivalent unspecified time.
    /// @param value A time interval from the start of the Clock's epoch.
    /// @return An object that represents the unspecified time equivalent of the date and time represented by the value parameter.
    /// @exception xtd::argument_out_of_range_exception value is less than xtd::date_time:::min_value or represents a time greater than xtd::date_time:::max_value.
    /// @remarks <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a> is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
    /// @remarks See <a href="https://en.cppreference.com/w/c/chrono.h">std::chrono</a> for more information.
    static date_time from_time_t(std::time_t value);
    /// @brief Converts the specified <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a> to an equivalent to Coordinated Universal Time (UTC) or local time.
    /// @param value A time interval from the start of the Clock's epoch.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @return An object that represents the unspecified time equivalent of the date and time represented by the value parameter.
    /// @exception xtd::argument_out_of_range_exception value is less than xtd::date_time:::min_value or represents a time greater than xtd::date_time:::max_value.
    /// @remarks <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a> is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
    /// @remarks See <a href="https://en.cppreference.com/w/c/chrono.h">std::chrono</a> for more information.
    static date_time from_time_t(std::time_t value, date_time_kind kind);
    
    /// @brief Converts the specified <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> to an equivalent unspecified time.
    /// @param value A <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> struct.
    /// @return An object that represents the unspecified time equivalent of the date and time represented by the value parameter.
    /// @exception xtd::argument_out_of_range_exception value.ttm_year is less than 1 or greater than 9999.<br>-or-<br>tvalue.tm_mon is less than 1 or greater than 12.<br>-or-<br>value.tm_mday is less than 1 or greater than the number of days in month.<br>-or-<br>value.tm_hour is less than 0 or greater than 23.<br>-or-<br>value.tm_min is less than 0 or greater than 59<br>-or-<br>vale.tm_sec is less than 0 or greater than 59.
    /// @remarks <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> is a structure holding a calendar date and time broken down into its components. is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
    /// @remarks See <a href="https://en.cppreference.com/w/c/chrono.h">std::chrono</a> for more information.
    static date_time from_tm(const std::tm& value);
    /// @brief Converts the specified <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a><a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> to an equivalent to Coordinated Universal Time (UTC) or local time.
    /// @param value A <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> struct.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @return An object that represents the unspecified time equivalent of the date and time represented by the value parameter.
    /// @exception xtd::argument_out_of_range_exception value.ttm_year is less than 1 or greater than 9999.<br>-or-<br>tvalue.tm_mon is less than 1 or greater than 12.<br>-or-<br>value.tm_mday is less than 1 or greater than the number of days in month.<br>-or-<br>value.tm_hour is less than 0 or greater than 23.<br>-or-<br>value.tm_min is less than 0 or greater than 59<br>-or-<br>vale.tm_sec is less than 0 or greater than 59.
    /// @remarks <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> is a structure holding a calendar date and time broken down into its components. is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
    /// @remarks See <a href="https://en.cppreference.com/w/c/chrono.h">std::chrono</a> for more information.
    static date_time from_tm(const std::tm& value, date_time_kind kind);
    
    /// @brief Indicates whether this instance of xtd::date_time is within the daylight saving time range for the current time zone.
    /// @return true if the value of the xtd::date_time::kind property is xtd::date_time_kind::local or xtd::date_time_kind::unspecified and the value of this instance ofxtd::date_time is within the daylight saving time range for the local time zone; false if xtd::date_time::kind is xtd::date_time_kind::utc.
    /// @remarks This method determines whether the current xtd::date_time value falls within the daylight saving time range of the local time zone, which is returned by the xtd::time_zone_info::local property. You can determine whether a time zone supports daylight saving time by retrieving the value of its xtd::time_zone_info::supports_daylight_saving_time property. For time zones that observe daylight saving time, you can determine when the transition to and from daylight saving time occurs by retrieving the xtd::time_zone_info::adjustment_rule array returned by the time zone's xtd::time_zone_info::get_adjustmen_rules property.
    /// @remarks If the current xtd::date_time value represents either an ambiguous or an invalid time in the local time zone, the method returns false.
    bool is_daylight_saving_time() const noexcept;
    
    /// @brief Returns an indication whether the specified year is a leap year.
    /// @param year A 4-digit year.
    /// @return true if year is a leap year; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception year is less than 1 or greater than 9999.
    static bool is_leap_year(uint32 year);
    
    /// @brief Converts the string representation of a date and time to its xtd::date_time equivalent by using the conventions of the current culture.
    /// @param s A string that contains a date and time to convert. See The string to parse for more information.
    /// @return An object that is equivalent to the date and time contained in s.
    /// @exception xtd::format_exception s does not contain a valid string representation of a date and time.
    /// @remarks If s contains time zone information, this method returns a xtd::date_time value whose xtd::date_time::kind property is xtd::date_time_kind::local and converts the date and time in s to local time. Otherwise, it performs no time zone conversion and returns a xtd::date_time value whose Kind property is DateTimeKind.Unspecified.
    /// @remarks This overload attempts to parse s by using the formatting conventions of the current culture. The current culture is indicated by the CurrentCulture property. To parse a string using the formatting conventions of a specific culture, call the Parse(String, IFormatProvider) or the Parse(String, IFormatProvider, DateTimeStyles) overloads.
    /// @remarks This overload attempts to parse s by using DateTimeStyles.AllowWhiteSpaces style.
    static date_time parse(const xtd::ustring& s);
    
    /// @brief Creates a new xtd::date_time object that has the same number of ticks as the specified xtd::date_time, but is designated as either local time, Coordinated Universal Time (UTC), or neither, as indicated by the specified xtd::date_time_kind value.
    /// @param value A date and time.
    /// @param kind One of the enumeration values that indicates whether the new object represents local time, UTC, or neither.
    /// @return A new object that has the same number of ticks as the object represented by the value parameter and the xtd::date_time_kind value specified by the kind parameter.
    /// @par Examples
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_kind.cpp
    static date_time specify_kind(const date_time& value, date_time_kind kind);
    
    /// @brief Returns a xtd::ustring that represents the current xtd::date_time.
    /// @param format Format-control String.
    /// @param value The xtd::date_time object to format.
    /// @return A xtd::ustring that represents the current xtd::date_time.
    /// @par Examples
    /// The foloowwing example shows how to use xtd::date_time::sprintf with differentt formats.
    /// @include date_time_sprintf.cpp
    /// @remarks The formatting codes for sprintf are listed below:
    /// | Format | Print                                                                                                                       |
    /// | ------ | --------------------------------------------------------------------------------------------------------------------------- |
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
    /// @remarks See <a href="https://en.cppreference.com/w/cpp/io/manip/put_time">std::put_time</a> for more information.
    static xtd::ustring sprintf(const ustring& format, const date_time& value);
    
    /// @brief Returns a new xtd::time_span that subtracts the specified date and time from the value of this instance.
    /// @param value The date and time value to subtract.
    /// @return A time interval that is equal to the date and time represented by this instance minus the date and time represented by value.
    /// @exception xtd::argument_out_of_range_exception The result is less than xtd::date_time:::min_value or represents a time greater than xtd::date_time:::max_value.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::subtract method and the subtraction operator.
    /// @include date_time_subtract.cpp
    /// @remarks The xtd::date_time::subtract(const xtd::date_time&) method determines the difference between two dates. To subtract a time interval from the current instance, call the xtd::date_time::subtract(xtd::time_span) method. To subtract a particular time interval from the current instance, call the method that adds that time interval to the current date, and supply a negative value as the method argument. For example, to subtract two months from the current date, call the xtd::date_time::add_months method with a value of -2.
    /// @remarks If the date and time of the current instance is earlier than value, the method returns a xtd::time_span object that represents a negative time span. That is, the value of all of its non-zero properties (such as xtd::date_time::days or xtd::date_time::ticks) is negative.
    /// @remarks The xtd::date_time::subtract(const xtd::date_time&) method does not consider the value of the xtd::date_time::kind property of the two xtd::date_time values when performing the subtraction. Before subtracting xtd::date_time::date_time objects, ensure that the objects represent times in the same time zone. Otherwise, the result will include the difference between time zones.
    /// @note The xtd::date_time_offset::subtract(const xtd::date_time_offset&) method does consider the difference between time zones when performing the subtraction.
    xtd::time_span subtract(const date_time& value) const;
    /// @brief Returns a new xtd::date_time that subtracts the specified duration from the value of this instance.
    /// @param value The time interval to subtract.
    /// @return An object that is equal to the date and time represented by this instance minus the time interval represented by value.
    /// @exception xtd::argument_out_of_range_exception The result is less than xtd::date_time:::min_value or represents a time greater than xtd::date_time:::max_value.
    /// @par Examples
    /// The following example demonstrates the xtd::date_time::subtract method and the subtraction operator.
    /// @include date_time_subtract.cpp
    /// @remarks The xtd::date_time::subtract(xtd::time_span) method returns the date that is a specified time interval difference from the current instance. To determine the time interval between two dates, call the xtd::date_time::subtract(const xtd::date_time&) method. To subtract a particular time interval from the current instance, call the method that adds that time interval to the current date, and supply a negative value as the method argument. For example, to subtract two months from the current date, call the xtd::date_time::add_months method with a value of -2.
    /// @remarks This method does not change the value of this xtd::date_time. Instead, it returns a new xtd::date_time whose value is the result of this operation.
    /// @remarks Ordinarily, the xtd::date_time::subtract(xtd::time_span) method subtracts a xtd::time_span object that represents a positive time span and returns a xtd::date_time value that is earlier than the date and time of the current instance. However, if the xtd::time_span object represents a negative time span, the xtd::date_time::subtract(xtd::time_span) method returns a xtd::date_time value that is later than the date and time of the current instance.
    /// @remarks The xtd::date_time::subtract(xtd::time_span) method allows you to subtract a time interval that consists of more than one unit of time (such as a given number of hours and a given number of minutes). To subtract a single unit of time (such as years, months, or days) from the xtd::date_time instance, you can pass a negative numeric value as a parameter to any of the following methods:
    /// * xtd::date_time::add_years, to subtract a specific number of years from the current date and time instance.
    /// * xtd::date_time::add_months, to subtract a specific number of months from the current date and time instance.
    /// * xtd::date_time::add_days, to subtract a specific number of days from the current date and time instance.
    /// * xtd::date_time::add_hours, to subtract a specific number of hours from the current date and time instance.
    /// * xtd::date_time::add_minutes, to subtract a specific number of minutes from the current date and time instance.
    /// * xtd::date_time::add_seconds, to subtract a specific number of seconds from the current date and time instance.
    /// * xtd::date_time::add_milliseconds, to subtract a specific number of milliseconds from the current date and time instance.
    /// * xtd::date_time::add_ticks, to subtract a specific number of ticks from the current date and time instance.
    date_time subtract(const xtd::time_span& value) const;
    
    /// @brief Serializes the current xtd::date_time object to a 64-bit binary value that subsequently can be used to recreate the xtd::date_time object.
    /// @return A 64-bit signed integer that encodes the xtd::date_time::kind and xtd::date_time::ticks properties.
    /// @remarks Use the xtd::date_time::to_binary method to convert the value of the current xtd::date_time object to a binary value. Subsequently, use the binary value and the xtd::date_time::from_binary method to recreate the original xtd::date_time object.
    int64 to_binary() const;
    
    /// @remarks Converts the value of the current xtd::date_time object to a Windows file time.
    /// @return The value of the current xtd::date_time object expressed as a Windows file time.
    /// @exception xtd::argument_out_of_range_exception The resulting file time would represent a date and time before 12:00 midnight January 1, 1601 C.E. UTC.
    /// @remarks A Windows file time is a 64-bit value that represents the number of 100-nanosecond intervals that have elapsed since 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC). Windows uses a file time to record when an application creates, accesses, or writes to a file.
    /// @remarks The xtd::date_time::to_file_time method uses the xtd::date_time::kind property to determine whether the current xtd::date_time object is a local time, a UTC time, or an unspecified kind of time which is treated as a local time.
    int64 to_file_time() const;
    /// @remarks Converts the value of the current xtd::date_time object to a Windows file time.
    /// @return The value of the current xtd::date_time object expressed as a Windows file time.
    /// @exception xtd::argument_out_of_range_exception The resulting file time would represent a date and time before 12:00 midnight January 1, 1601 C.E. UTC.
    /// @remarks A Windows file time is a 64-bit value that represents the number of 100-nanosecond intervals that have elapsed since 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC). Windows uses a file time to record when an application creates, accesses, or writes to a file.
    /// @remarks The xtd::date_time::to_file_time_utc method uses the xtd::date_time::to_file_timextd::date_time::kind property to determine whether the current xtd::date_time object is a local time, a UTC time, or an unspecified kind of time which is treated as a UTC time. If it is a local time, it converts the time to UTC before performing the conversion to a Windows file time.
    int64 to_file_time_utc() const;
    
    /// @brief Converts the value of the current xtd::date_time object to local time.
    /// @return An object whose xtd::date_time::kind property is xtd::date_time_kind::local, and whose value is the local time equivalent to the value of the current xtd::date_time object, or xtd::date_time::max_value if the converted value is too large to be represented by a xtd::date_time object, or xtd::date_time::min_value if the converted value is too small to be represented as a xtd::date_time object.
    /// @par Examples
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_kind.cpp
    /// @remarks The local time is equal to the Coordinated Universal Time (UTC) time plus the UTC offset. For more information about the UTC offset, see xtd::time_zone_info::get_utc_offset. The conversion also takes into account the daylight saving time rule that applies to the time represented by the current xtd::date_time object.
    /// @remarks The value returned by the xtd::date_time::to_local_time method is determined by the xtd::date_time::kind property of the current xtd::date_time object. The following table describes the possible results.
    /// | Kind                             | Results                                                                                                                                                |
    /// | -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------ |
    /// | xtd::date_time_kind::utc         | This instance of xtd::date_timextd::date_time is converted to local time.                                                                              |
    /// | xtd::date_time_kind::local       | No conversion is performed.                                                                                                                            |
    /// | xtd::date_time_kind::unspecified | This instance of xtd::date_time is assumed to be a UTC time, and the conversion is performed as if xtd::date_time::kind were xtd::date_time_kind::utc. |
    /// @note The xtd::date_time::to_local_time method converts a xtd::date_time:: value from UTC to local time. To convert the time in any designated time zone to local time, use the xtd::time_zone_info::convert_time method.
    /// @remarks The value returned by the conversion is a xtd::date_time whose xtd::date_time::Kind property always returns xtd::date_time_kind::local. Consequently, a valid result is returned even if xtd::date_time::to_local_time is applied repeatedly to the same xtd::date_time.
    date_time to_local_time() const;
    
    /// @brief Converts the value of the current xtd::date_time object to its equivalent long date string representation.
    /// @return A string that contains the long date string representation of the current xtd::date_time object.
    /// @remarks The return value is identical to the value returned by specifying the "n" standard xtd::date_time format string with the xtd::date_time::to_string(const xtd::ustring&) method.
    const xtd::ustring to_long_date_string() const;
    
    /// @brief Converts the value of the current xtd::date_time object to its equivalent long time string representation.
    /// @return A string that contains the long time string representation of the current xtd::date_time object.
    /// @remarks The return value is identical to the value returned by specifying the "T" standard xtd::date_time format string with the xtd::date_time::to_string(const xtd::ustring&) method.
    const xtd::ustring to_long_time_string() const;
    
    /// @brief Converts the value of the current xtd::date_time object to its equivalent short date string representation.
    /// @return A string that contains the short date string representation of the current xtd::date_time object.
    /// @remarks The return value is identical to the value returned by specifying the "D" standard xtd::date_time format string with the xtd::date_time::to_string(const xtd::ustring&) method.
    const xtd::ustring to_short_date_string() const;
    
    /// @brief Converts the value of the current xtd::date_time object to its equivalent short time string representation.
    /// @return A string that contains the short time string representation of the current xtd::date_time object.
    /// @remarks The return value is identical to the value returned by specifying the "V" standard xtd::date_time format string with the xtd::date_time::to_string(const xtd::ustring&) method.
    const xtd::ustring to_short_time_string() const;
    
    /// @brief Converts the value of the current xtd::date_time object to its equivalent string representation using the formatting conventions of the current culture.
    /// @return A string representation of the value of the current xtd::date_time object.
    /// @remarks The return value is identical to the value returned by specifying the "G" standard xtd::date_time format string with the xtd::date_time::to_string(const xtd::ustring&) method.
    xtd::ustring to_string() const noexcept override;
    /// @brief Converts the value of the current xtd::date_time object to its equivalent string representation using the specified format and the formatting conventions of the current culture.
    /// @param format A standard or custom date and time format string.
    /// @return A string representation of value of the current xtd::date_time object as specified by format.
    /// @exception xtd::format_excpetion The length of format is 1, and it is not a valid format characters<br>-or-<br>The length si greater than 1.
    /// @par Examples
    /// The foloowwing example shows how to use xtd::date_time::to_string(const xtd::ustring&) with differentt formats.
    /// @include date_time_to_string_format.cpp
    /// @remarks The formatting codes for xtd::date_time::to_string (const xtd::ustring&) are listed below:
    /// | Format | Print                                                                                                                       |
    /// | ------ | --------------------------------------------------------------------------------------------------------------------------- |
    /// | 'a'    | writes "PM" or "AM"                                                                                                         |
    /// | 'b'    | writes 3 digit millisecond, e.G. 012                                                                                        |
    /// | 'B'    | wrties millisecond, eg 12                                                                                                   |
    /// | 'c'    | writes 7 digit tick, e.G. 0000123                                                                                           |
    /// | 'C'    | writes tick, e.G. 123                                                                                                       |
    /// | 'd'    | writes date MM/dd/y, e.g. 01/05/42                                                                                          |
    /// | 'D'    | writes date M/dd/y, e.g. 1/055/42                                                                                           |
    /// | 'e'    | writes 2 digit second, e.G. 03                                                                                              |
    /// | 'B'    | writes second, e.G. 3                                                                                                       |
    /// | 'f'    | writes alternative date and time string, e.g. using 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale.  |
    /// | 'F'    | writes standard date and time string, e.g. Sun Oct 17 04:41:13 2010 (locale dependent).                                     |
    /// | 'g'    | writes alternative date and time string, e.g. using 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale.  |
    /// | 'G'    | writes standard date and time string, e.g. Sun Oct 17 04:41:13 2010 (locale dependent).                                     |
    /// | 'h'    | writes abbreviated weekday name, e.g. Fri (locale dependent).                                                               |
    /// | 'H'    | writes full weekday name, e.g. Friday (locale dependent).                                                                   |
    /// | 'i'    | writes 2 digit day, e.g. 05                                                                                                 |
    /// | 'I'    | writes day, e.G. 5                                                                                                          |
    /// | 'j'    | writes abbreviated month name, e.g. Oct (locale dependent)                                                                  |
    /// | 'J'    | writes full month name, e.g. October (locale dependent).                                                                    |
    /// | 'k'    | writes 2 digit month, e.g. 01                                                                                               |
    /// | 'K'    | writes month, e.g. 1                                                                                                        |
    /// | 'l'    | writes 2 digit year, e.g. 71                                                                                                |
    /// | 'L'    | writes 4 digit year, e.g. 1971                                                                                              |
    /// | 'm'    | writes year, e.g. 42                                                                                                        |
    /// | 'M'    | writes full month name and day, e.g. October, 5 (locale dependent).                                                         |
    /// | 'n'    | writes full weekday name, day, fulll month and year, e.g. Tuesday, 1 April 2008                                             |
    /// | 'N'    | writes full weekday name, day, fulll month, year, hour, minute ans second, e.g. Tuesday, 1 April 2008 18:07:05              |
    /// | 'o'    | writes day, full month and year, e.g. 5 January 42                                                                          |
    /// | 'O'    | writes day, full month and year, e.g. 5 January 42                                                                          |
    /// | 'p'    | writes 2 digit minute, e.G. 06                                                                                              |
    /// | 'P'    | writes minute, e.G. 6                                                                                                       |
    /// | 's'    | writes sortable date/time pattern yyyy-MM-ddThh:mm:ss.ttttttt. e.g. 1971-05-01T21:32:24:42.004567                           |
    /// | 't'    | writes time hh/mm/ss, e.g. 02:04:06                                                                                         |
    /// | 'T'    | writes time h/mm/ss, e.g. 2:04:06                                                                                           |
    /// | 'u'    | writes sortable short date/time pattern y-MM-dd hh:mm:ss. e.g. 1971-05-01 9:32:24:42                                        |
    /// | 'U'    | writes full weekday name, day, fulll month, year, hour, minute ans second, e.g. Tuesday, 1 April 2008 18:07:05              |
    /// | 'v'    | writes time hh/mm, e.g. 02:04                                                                                               |
    /// | 'V'    | writes time h/mm, e.g. 2:04                                                                                                 |
    /// | 'w'    | writes 2 digit hour (24H), e.g. 07                                                                                          |
    /// | 'W'    | writes hour (24H), e.g. 7                                                                                                   |
    /// | 'x'    | writes 2 digit hour (12H), e.g. 07                                                                                          |
    /// | 'X'    | writes hour (12H), e.g. 7                                                                                                   |
    /// | 'y'    | writes full month name and year, e.g. October, 71 (locale dependent).                                                       |
    /// | 'Y'    | writes full month name and year, e.g. October, 1971 (locale dependent).                                                     |
    /// | 'z'    | writes time zone "local" or "UTC".                                                                                          |
    /// | 'Z'    | writes time zone "local" or "UTC".                                                                                          |
    xtd::ustring to_string(const ustring& format) const;
    
    /// @remarks Converts the value of the current xtd::date_time object to <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a>.
    /// @return The value of the current xtd::date_time object expressed as <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a>.
    /// @remarks <a href="https://en.cppreference.com/w/cpp/chrono/c/time_t">std::time_t</a> is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
    /// @remarks See <a href="https://en.cppreference.com/w/c/chrono.h">std::chrono</a> for more information.
    std::time_t to_time_t() const;
    
    /// @remarks Converts the value of the current xtd::date_time object to <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a>.
    /// @return The value of the current xtd::date_time object expressed as <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a>.
    /// @remarks <a href="https://en.cppreference.com/w/c/chrono/tm">std::tm</a> is a structure holding a calendar date and time broken down into its components. is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
    /// @remarks See <a href="https://en.cppreference.com/w/c/chrono.h">std::chrono</a> for more information.
    std::tm to_tm() const;
    
    /// @brief Converts the value of the current xtd::date_time object to Coordinated Universal Time (UTC).
    /// @return An object whose xtd::date_time::kind property is xtd::date_time_kind::utc, and whose value is the UTC equivalent to the value of the current xtd::date_time object, or xtd::date_time::max_value if the converted value is too large to be represented by a xtd::date_time object, or xtd::date_time::min_value if the converted value is too small to be represented by a xtd::date_time object.
    /// @par Examples
    /// The following example uses the xtd::date_time::specify_kind method to demonstrate how the xtd::date_time::kind property influences the xtd::date_time::to_local_time and xtd::date_time::to_universal_time conversion methods.
    /// @include date_time_specify_kind.cpp
    /// @remarks The Coordinated Universal Time (UTC) is equal to the local time minus the UTC offset. For more information about the UTC offset, see xtd::time_zone_info::get_utc_offset. The conversion also takes into account the daylight saving time rule that applies to the time represented by the current xtd::date_time object.
    /// @remarks The value returned by the xtd::date_time::to_universal_time method is determined by the xtd::date_time::kind property of the current xtd::date_time object. The following table describes the possible results.
    /// | Kind                             | Results                                                                                                                                 |
    /// | -------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
    /// | xtd::date_time_kind::utc         | No conversion is performed.                                                                                                             |
    /// | xtd::date_time_kind::local       | The current xtd::date_time object is converted to UTC.                                                                                  |
    /// | xtd::date_time_kind::unspecified | The current xtd::date_time object is assumed to be a local time, and the conversion is performed as if xtd::date_time::kind were Local. |
    date_time to_universal_time() const;
    /// @}
    
    /// @cond
    operator xtd::time_span() const;
    date_time operator +=(const date_time& value) = delete;
    date_time operator +=(const time_span& value);
    time_span operator -=(const date_time& value);
    time_span operator -=(const time_span& value);
    date_time operator +();
    date_time operator -();
    date_time operator +(const date_time& value) const = delete;
    date_time operator +(const time_span& value) const;
    time_span operator -(const date_time& value) const;
    date_time operator -(const time_span& value) const;
    date_time& operator ++();
    date_time operator ++(int32);
    date_time& operator --();
    date_time operator --(int32);
    /// @endcond
    
  private:
    friend class time_zone_info;
    xtd::ticks utc_offset() const;
    std::tuple<uint32, uint32, uint32, uint32, uint32, uint32, uint32, int32> get_date_time() const;
    void set_date_time(uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute, uint32 second, uint32 millisecond, date_time_kind kind);
    
    xtd::ticks value_ {0};
    date_time_kind kind_ {date_time_kind::unspecified};
  };
  /// @}
  
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
