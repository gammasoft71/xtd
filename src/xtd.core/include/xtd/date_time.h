#pragma once
#include <chrono>
#include <ctime>
#include "object.h"
#include "ticks.h"
#include "ustring.h"

namespace xtd {
  enum class date_time_kind {
    unspecified,
    utc,
    local,
  };
  
  enum class day_of_week {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
  
  class core_export_ date_time : public object {
  public:
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
    date_time_kind kind() const noexcept;
    xtd::ticks ticks() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    static date_time from_time_t(std::time_t value);
    static date_time now();
    static date_time utc_now();
    xtd::ustring to_string() const noexcept override;
    xtd::ustring to_string(const ustring& format) const;
    std::time_t to_time_t() const;
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
