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

namespace xtd {
  class core_export_ date_time : public icomparable<date_time>, public iequatable<date_time>, public object {
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
    date_time() = default;
    date_time(xtd::ticks ticks);
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
      return date_time(std::chrono::duration_cast<xtd::ticks>(value), date_time_kind::unspecified);
    }
    template<typename rep_t, typename period_t>
    static date_time from_duration(std::chrono::duration<rep_t, period_t> value, date_time_kind kind) {
      return date_time(std::chrono::duration_cast<xtd::ticks>(value), kind);
    }
    static date_time from_time_t(std::time_t value);
    static date_time from_time_t(std::time_t value, date_time_kind kind);
    static date_time from_tm(tm& value);
    static date_time from_tm(tm& value, date_time_kind kind);
    bool is_daylight_saving_time() const noexcept;
    static bool is_leap_year(uint32_t year);
    xtd::ustring parse() const;
    static date_time specify_kind(date_time value, date_time_kind kind);
    time_point subtract(const date_time& value) const;
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
    date_time to_universal_time() const;
    /// @}
    
    /// @Name Operators
    
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
    void set_date_time(uint32_t year, uint32 month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind);

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
