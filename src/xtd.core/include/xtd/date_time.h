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
  class core_export_ date_time : public xtd::icomparable<date_time>, public xtd::iequatable<date_time>, public xtd::object {
  public:
    /// @name Alias
    
    /// @{
    using time_point = xtd::ticks;
    /// @}
    
    /// @name Fields
    
    /// @{
    static date_time max_value;
    static date_time min_value;
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::date_time structure.
    date_time() = default;
    /// @brief Initializes a new instance of the DateTime structure to a specified number of ticks.
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
    date_time add_months(double value) const;
    date_time add_seconds(double value) const;
    date_time add_ticks(int64 value) const;
    date_time add_years(double value) const;
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
      return date_time(std::chrono::duration_cast<xtd::ticks>(value), date_time_kind::local);
    }
    template<typename rep_t, typename period_t>
    static date_time from_duration_utc(std::chrono::duration<rep_t, period_t> value) {
      return date_time(std::chrono::duration_cast<xtd::ticks>(value), date_time_kind::utc);
    }
    static date_time from_time_t(std::time_t value);
    static date_time from_time_t_utc(std::time_t value);
    static date_time from_tm(const std::tm& value);
    static date_time from_tm_utc(const std::tm& value);
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
    void get_date_time(uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year,  int32_t& day_of_week) const;
    void set_date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind);

    xtd::ticks value_ {0};
    date_time_kind kind_ {date_time_kind::unspecified};
  };
  
  /// @cond
  std::ostream& operator <<(std::ostream& os, const date_time& ver) noexcept;
  /// @endcond

  template<>
  inline std::string to_string(const date_time& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
}
