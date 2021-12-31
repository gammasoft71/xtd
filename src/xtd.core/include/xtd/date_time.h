/// @file
/// @brief Contains xtd::date_time class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
    /// @remarks The value of this constant is equivalent to 00:00:00.0000000 UTC, January 1, 0001, in the Gregorian calendar.
    /// @remarks xtd::date_time::min_vvalue defines the date and time that is assigned to an uninitialized xtd::date_time variable. The following example illustrates this.
    /// @include date_time_min_value.cpp
    /// @par Examples
    /// The following example instantiates a xtd::date_time object by passing its constructor an xtd::ticks value that represents a number of ticks.
    /// Before invoking the constructor, the example ensures that this value is greater than or equal to date_time::min_value.ticks() and less than or equal to date_time::max_value.ticks().
    /// If not, it throws an xtd::argument_out_of_range_exception.
    /// @include date_time_max_value.cpp
    static const date_time min_value;
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::date_time structure.
    date_time() = default;
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    /// @remarks The xtd::date_time::kind property is initialized to xtd::date_time_kind::unspecified.
    date_time(xtd::ticks ticks);
    /// @brief Initializes a new instance of the xtd::date_time structure to a specified number of ticks and to Coordinated Universal Time (UTC) or local time.
    /// @param ticks A date and time expressed in the number of 100-nanosecond intervals that have elapsed since January 1, 0001 at 00:00:00.000 in the Gregorian calendar.
    /// @param kind One of the enumeration values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither.
    /// @exception xtd::argument_out_of_range_exception ticks is less than xtd::date_time::min_value or greater than xtd::date_time::max_value.
    date_time(xtd::ticks ticks, xtd::date_time_kind kind);
    date_time(uint32_t year, uint32_t month, uint32_t day);
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second);
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, date_time_kind kind);
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond);
    date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind);
    /// @}
    
    /// @cond
    date_time(const date_time&) = default;
    date_time(date_time&&) = default;
    date_time& operator=(const date_time&) = default;
    /// @endcond
    

    /// @name Properties

    /// @{
    date_time date() const noexcept;
    uint32_t day() const noexcept;
    xtd::day_of_week day_fo_week() const noexcept;
    uint32_t day_of_year() const noexcept;
    uint32_t hour() const noexcept;
    date_time_kind kind() const noexcept;
    uint32_t millisecond() const noexcept;
    uint32_t minute() const noexcept;
    uint32_t month() const noexcept;
    static date_time now() noexcept;
    uint32_t second() const noexcept;
    xtd::ticks ticks() const noexcept;
    time_point time_of_day() const noexcept;
    static date_time to_day() noexcept;
    static date_time utc_now() noexcept;
    uint32_t year() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    template<typename rep_t, typename period_t>
    date_time add(std::chrono::duration<rep_t, period_t> value) const {
      return add(std::chrono::duration_cast<time_point>(value));
    }
    date_time add(time_point value) const;
    date_time add_days(double value) const;
    date_time add_hours(double value) const;
    date_time add_milliseconds(double value) const;
    date_time add_minutes(double value) const;
    date_time add_months(int32_t value) const;
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

  template<>
  inline std::string to_string(const date_time& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
}
