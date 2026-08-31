/// @file
/// @brief Contains xtd::time_span class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "chrono.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "iformatable.hpp"
#include "object.hpp"
#include "parse.hpp"
#include "ticks.hpp"
#include "types.hpp"
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represents a time interval.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example instantiates a The following example instantiates a xtd::time_span object that represents the difference between two dates. It then displays the xtd::time_span object's properties. object that represents the difference between two dates. It then displays the xtd::time_span object's properties.
  /// @include time_span.cpp
  class time_span : public xtd::object, public xtd::iequatable<time_span>, public icomparable<time_span>, public iformatable {
  public:
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the maximum xtd::time_span value. This field is read-only.
    /// @remarks The value of this field is equivalent to xtd::int64_object::max_value ticks. The string representation of this value is positive 10675199.02:48:05.4775807, or slightly more than 10,675,199 days.
    static const time_span max_value;
    
    /// @brief Represents the minimum xtd::time_span value. This field is read-only.
    /// @remarks The value of this field is equivalent to xtd::int64_object::min_value ticks. The string representation of this value is negative 10675199.02:48:05.4775808, or slightly more than negative 10,675,199 days.
    static const time_span min_value;
    
    /// @brief Represents the number of nanoseconds per tick. This field is constant.
    /// @remarks The value of this constant is 100.
    static constexpr xtd::int64 nanoseconds_per_tick = 100ll;
    
    /// @brief Represents the number of ticks in 1 microsecond. This field is constant.
    /// @remarks The value of this constant is 10.
    static constexpr xtd::int64 ticks_per_microsecond = 10ll;
    
    /// @brief Represents the number of ticks in 1 millisecond. This field is constant.
    /// @remarks The value of this constant is 10 thousand; that is, 10,000.
    static constexpr xtd::int64 ticks_per_millisecond = ticks_per_microsecond * 1'000;
    
    /// @brief Represents the number of ticks in 1 second.
    /// @remarks he value of this constant is 10 million; that is, 10'000'000.
    static constexpr xtd::int64 ticks_per_second = ticks_per_millisecond * 1'000;
    
    /// @brief Represents the number of ticks in 1 minute. This field is constant.
    /// @remarks The value of this constant is 600 million; that is, 600'000'000.
    static constexpr xtd::int64 ticks_per_minute = ticks_per_second * 60;
    
    /// @brief Represents the number of ticks in 1 hour. This field is constant.
    /// @remarks The value of this constant is 36 billion; that is, 36'000'000'000.
    static constexpr xtd::int64 ticks_per_hour = ticks_per_minute * 60;
    
    /// @brief Represents the number of ticks in 1 day. This field is constant.
    /// @remarks The value of this constant is 864 billion; that is, 864'000'000'000.
    static constexpr xtd::int64 ticks_per_day = ticks_per_hour * 24;
    
    /// @brief Represents the zero xtd::time_span value. This field is read-only.
    /// @remarks Because the value of the Zero field is a xtd::time_span object that represents a zero time value, you can compare it with other xtd::time_span objects to determine whether the latter represent positive, non-zero, or negative time intervals. You can also use this field to initialize a xtd::time_span object to a zero time value.
    static const time_span zero;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::time_span structure to the specified number of ticks.
    /// @param tiks A time period expressed in 100-nanosecond units.
    /// @remarks A single tick represents one hundred nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond.
    explicit time_span(xtd::int64 ticks);
    /// @brief Initializes a new instance of the xtd::time_span structure to the specified number of ticks.
    /// @param tiks A time period expressed in 100-nanosecond units.
    /// @remarks A single tick represents one hundred nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond.
    explicit time_span(xtd::ticks ticks);
    /// @brief Initializes a new instance of the xtd::time_span structure to the specified number of ticks.
    /// @param tiks A time period expressed in 100-nanosecond units.
    /// @remarks A single tick represents one hundred nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond.
    /// @remarks See [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) for more information.
    template<typename duration_t, typename period_t = std::ratio<1>> // Can't be explicit by design.
    time_span(const std::chrono::duration<duration_t, period_t>& value) : time_span(static_cast<int64>(std::chrono::duration_cast<xtd::ticks>(value).count())) {}
    /// @brief Initializes a new instance of the xtd::time_span structure to a specified number of hours, minutes, and seconds.
    /// @param hours Number of hours.
    /// @param minutes Number of minutes.
    /// @param seconds Number of seconds.
    /// @exception xtd::argument_out_of_range_exception The parameters specify a xtd::time_span value less than xtd::time_span::min_value or greater than xtd::time_span::max_value.
    /// @remarks The specified hours, minutes, and seconds are converted to ticks, and that value initializes this instance.
    time_span(xtd::int32 hours, xtd::int32 minutes, xtd::int32 seconds);
    /// @brief Initializes a new instance of the xtd::time_span structure to a specified number of days, hours, minutes, and seconds.
    /// @param days Number of days.
    /// @param hours Number of hours.
    /// @param minutes Number of minutes.
    /// @param seconds Number of seconds.
    /// @exception xtd::argument_out_of_range_exception The parameters specify a xtd::time_span value less than xtd::time_span::min_value or greater than xtd::time_span::max_value.
    /// @remarks The specified days, hours, minutes, and seconds are converted to ticks, and that value initializes this instance.
    time_span(xtd::int32 days, xtd::int32 hours, xtd::int32 minutes, xtd::int32 seconds);
    /// @brief Initializes a new instance of the xtd::time_span structure to a specified number of days, hours, minutes, seconds, and millisonds.
    /// @param days Number of days.
    /// @param hours Number of hours.
    /// @param minutes Number of minutes.
    /// @param seconds Number of seconds.
    /// @param milliseconds Number of milliseconds.
    /// @exception xtd::argument_out_of_range_exception The parameters specify a xtd::time_span value less than xtd::time_span::min_value or greater than xtd::time_span::max_value.
    /// @remarks The specified days, hours, minutes, seconds, and millisonds are converted to ticks, and that value initializes this instance.
    time_span(xtd::int32 days, xtd::int32 hours, xtd::int32 minutes, xtd::int32 seconds, xtd::int32 milliseconds);
    /// @brief Initializes a new instance of the xtd::time_span structure to a specified number of days, hours, minutes, seconds, millisonds, and microseconds.
    /// @param days Number of days.
    /// @param hours Number of hours.
    /// @param minutes Number of minutes.
    /// @param seconds Number of seconds.
    /// @param milliseconds Number of milliseconds.
    /// @param microseconds Number of microseconds.
    /// @exception xtd::argument_out_of_range_exception The parameters specify a xtd::time_span value less than xtd::time_span::min_value or greater than xtd::time_span::max_value.
    /// @remarks The specified days, hours, minutes, seconds, millisonds and microseconds are converted to ticks, and that value initializes this instance.
    time_span(xtd::int32 days, xtd::int32 hours, xtd::int32 minutes, xtd::int32 seconds, xtd::int32 milliseconds, xtd::int32 microseconds);
    /// @brief Initializes a new instance of the xtd::time_span structure to a specified number of days, hours, minutes, seconds, millisonds, and microseconds.
    /// @param days Number of days.
    /// @param hours Number of hours.
    /// @param minutes Number of minutes.
    /// @param seconds Number of seconds.
    /// @param milliseconds Number of milliseconds.
    /// @param microseconds Number of microseconds.
    /// @param nanoseconds Number of nanoseconds.
    /// @exception xtd::argument_out_of_range_exception The parameters specify a xtd::time_span value less than xtd::time_span::min_value or greater than xtd::time_span::max_value.
    /// @remarks The specified days, hours, minutes, seconds, millisonds and microseconds are converted to ticks, and that value initializes this instance.
    time_span(xtd::int32 days, xtd::int32 hours, xtd::int32 minutes, xtd::int32 seconds, xtd::int32 milliseconds, xtd::int32 microseconds, xtd::int32 nanoseconds);
    /// @}
    
    /// @cond
    time_span();
    time_span(const time_span&) = default;
    time_span(time_span&&) = default;
    time_span(xtd::uint32 hours, xtd::uint32 minutes, xtd::uint32 seconds);
    time_span(xtd::uint32 days, xtd::uint32 hours, xtd::uint32 minutes, xtd::uint32 seconds);
    time_span(xtd::uint32 days, xtd::uint32 hours, xtd::uint32 minutes, xtd::uint32 seconds, xtd::uint32 milliseconds);
    time_span(xtd::uint32 days, xtd::uint32 hours, xtd::uint32 minutes, xtd::uint32 seconds, xtd::uint32 milliseconds, xtd::uint32 microseconds);
    time_span(xtd::uint32 days, xtd::uint32 hours, xtd::uint32 minutes, xtd::uint32 seconds, xtd::uint32 milliseconds, xtd::uint32 microseconds, xtd::uint32 nanoseconds);
    
    auto operator =(const time_span&) -> time_span& = default;
    auto operator +=(const time_span& value) -> time_span&;
    auto operator -=(const time_span& value) -> time_span&;
    auto operator +(const time_span& value) const -> time_span;
    auto operator -(const time_span& value) const -> time_span;
    auto operator *(const time_span& value) const -> double;
    auto operator *(double value) const -> time_span;
    auto operator /(const time_span& value) const -> double;
    auto operator /(double value) const -> time_span;
    auto operator +() const -> time_span;
    auto operator -() const -> time_span;
    auto operator ++() -> time_span&;
    auto operator ++(int) -> time_span;
    auto operator --() -> time_span&;
    auto operator --(int) -> time_span;
    friend auto operator << (std::ostream& os, const time_span& value) -> std::ostream& {return os << value.to_string();}
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the days component of the time interval represented by the current xtd::time_span structure.
    /// @return The day component of this instance. The return value can be positive or negative.
    /// @remarks The xtd::time_span::days property represents whole days, whereas the xtd::time_span::total_days property represents whole and fractional days.
    [[nodiscard]] auto days() const noexcept -> xtd::int32;
    
    /// @brief Gets the hours component of the time interval represented by the current xtd::time_span structure.
    /// @return The hour component of the current xtd::time_span structure. The return value ranges from -23 through 23.
    /// @remarks The xtd::time_span::hours property represents whole hours, whereas the xtd::time_span::total_hours property represents whole and fractional hours.
    [[nodiscard]] auto hours() const noexcept -> xtd::int32;
    
    /// @brief Gets the microseconds component of the time interval represented by the current xtd::time_span structure.
    /// @return The hour component of the current xtd::time_span structure. The return value ranges from -999 through 999.
    /// @remarks The xtd::time_span::microseconds property represents whole microseconds, whereas the xtd::time_span::total_microseconds property represents whole and fractional microseconds.
    [[nodiscard]] auto microseconds() const noexcept -> xtd::int32;
    
    /// @brief Gets the milliseconds component of the time interval represented by the current xtd::time_span structure.
    /// @return The millisecond component of the current xtd::time_span structure. The return value ranges from -999 through 999.
    /// @remarks The xtd::time_span::milliseconds property represents whole milliseconds, whereas the xtd::time_span::total_milliseconds property represents whole and fractional milliseconds.
    [[nodiscard]] auto milliseconds() const noexcept -> xtd::int32;
    
    /// @brief Gets the minutes component of the time interval represented by the current xtd::time_span structure.
    /// @return The minute component of the current xtd::time_span structure. The return value ranges from -59 through 59.
    /// @remarks The xtd::time_span::minutes property represents whole minutes, whereas the xtd::time_span::total_minutes property represents whole and fractional minutes.
    [[nodiscard]] auto minutes() const noexcept -> xtd::int32;
    
    /// @brief Gets the nanoseconds component of the time interval represented by the current xtd::time_span structure.
    /// @return The nanosecond component of the current xtd::time_span structure. The return value ranges from -999 through 999.
    /// @remarks The xtd::time_span::nanoseconds property represents whole nanoseconds, whereas the xtd::time_span::total_nanoseconds property represents whole and fractional nanoseconds.
    [[nodiscard]] auto nanoseconds() const noexcept -> xtd::int32;
    
    /// @brief Gets the seconds component of the time interval represented by the current xtd::time_span structure.
    /// @return The second component of the current xtd::time_span structure. The return value ranges from -59 through 59.
    /// @remarks The xtd::time_span::seconds property represents whole seconds, whereas the xtd::time_span::total_seconds property represents whole and fractional seconds.
    [[nodiscard]] auto seconds() const noexcept -> xtd::int32;
    
    /// @brief Gets the number of ticks that represent the value of the current xtd::time_span structure.
    /// @return The number of ticks contained in this instance.
    /// @remarks The smallest unit of time is the tick, which is equal to 100 nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond. The value of the xtd::time_span::ticks property can be negative or positive to represent a negative or positive time interval.
    [[nodiscard]] auto ticks() const noexcept -> xtd::int64;
    
    /// @brief Gets the number of ticks that represent the value of the current xtd::time_span structure.
    /// @return The number of ticks contained in this instance.
    /// @remarks The smallest unit of time is the tick, which is equal to 100 nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond. The value of the xtd::time_span::ticks property can be negative or positive to represent a negative or positive time interval.
    [[nodiscard]] auto ticks_duration() const noexcept -> xtd::ticks;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional days.
    /// @return The total number of days represented by this instance.
    /// @remarks The xtd::time_span::total_days property represents whole and fractional days, whereas the xtd::time_span::days property represents whole days.
    [[nodiscard]] auto total_days() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional days.
    /// @return The total number of days represented by this instance.
    /// @remarks The xtd::time_span::total_days_duration property represents whole and fractional days, whereas the xtd::time_span::days property represents whole days.
    [[nodiscard]] auto total_days_duration() const noexcept -> std::chrono::days;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional hours.
    /// @return The total number of hours represented by this instance.
    /// @remarks The xtd::time_span::total_hours property represents whole and fractional hours, whereas the xtd::time_span::hours property represents whole hours.
    [[nodiscard]] auto total_hours() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional hours.
    /// @return The total number of hours represented by this instance.
    /// @remarks The xtd::time_span::total_hours_duration property represents whole and fractional hours, whereas the xtd::time_span::hours property represents whole hours.
    [[nodiscard]] auto total_hours_duration() const noexcept -> std::chrono::hours;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional microseconds.
    /// @return The total number of microseconds represented by this instance.
    /// @remarks The xtd::time_span::total_microseconds property represents whole and fractional microseconds, whereas the xtd::time_span::microseconds property represents whole microseconds.
    [[nodiscard]] auto total_microseconds() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional microseconds.
    /// @return The total number of microseconds represented by this instance.
    /// @remarks The xtd::time_span::total_microseconds_duration property represents whole and fractional microseconds, whereas the xtd::time_span::microseconds property represents whole microseconds.
    [[nodiscard]] auto total_microseconds_duration() const noexcept -> std::chrono::microseconds;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional milliseconds.
    /// @return The total number of milliseconds represented by this instance.
    /// @remarks The xtd::time_span::total_milliseconds property represents whole and fractional milliseconds, whereas the xtd::time_span::milliseconds property represents whole milliseconds.
    [[nodiscard]] auto total_milliseconds() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional milliseconds.
    /// @return The total number of milliseconds represented by this instance.
    /// @remarks The xtd::time_span::total_milliseconds_duration property represents whole and fractional milliseconds, whereas the xtd::time_span::milliseconds property represents whole milliseconds.
    [[nodiscard]] auto total_milliseconds_duration() const noexcept -> std::chrono::milliseconds;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional minutes.
    /// @return The total number of minutes represented by this instance.
    /// @remarks The xtd::time_span::total_minutes property represents whole and fractional minutes, whereas the xtd::time_span::minutes property represents whole minutes.
    [[nodiscard]] auto total_minutes() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional minutes.
    /// @return The total number of minutes represented by this instance.
    /// @remarks The xtd::time_span::total_minutes_duration property represents whole and fractional minutes, whereas the xtd::time_span::minutes property represents whole minutes.
    [[nodiscard]] auto total_minutes_duration() const noexcept -> std::chrono::minutes;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional nanoseconds.
    /// @return The total number of nanoseconds represented by this instance.
    /// @remarks The xtd::time_span::total_nanoseconds property represents whole and fractional nanoseconds, whereas the xtd::time_span::nanoseconds property represents whole nanoseconds.
    [[nodiscard]] auto total_nanoseconds() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional nanoseconds.
    /// @return The total number of nanoseconds represented by this instance.
    /// @remarks The xtd::time_span::total_nanoseconds_duration property represents whole and fractional nanoseconds, whereas the xtd::time_span::nanoseconds property represents whole nanoseconds.
    [[nodiscard]] auto total_nanoseconds_duration() const noexcept -> std::chrono::nanoseconds;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional seconds.
    /// @return The total number of seconds represented by this instance.
    /// @remarks The xtd::time_span::total_seconds property represents whole and fractional seconds, whereas the xtd::time_span::seconds property represents whole seconds.
    [[nodiscard]] auto total_seconds() const noexcept -> double;
    
    /// @brief Gets the value of the current xtd::time_span structure expressed in whole and fractional seconds.
    /// @return The total number of seconds represented by this instance.
    /// @remarks The xtd::time_span::total_seconds_duration property represents whole and fractional seconds, whereas the xtd::time_span::seconds property represents whole seconds.
    [[nodiscard]] auto total_seconds_duration() const noexcept -> std::chrono::seconds;
    
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Returns a new xtd::time_span object whose value is the sum of the specified xtd::time_span object and this instance.
    /// @param ts The time interval to add.
    /// @return A new object that represents the value of this instance plus the value of ts.
    /// @remarks The return value is a new xtd::time_span; the original xtd::time_span is not modified.
    [[nodiscard]] auto add(const time_span& ts) const noexcept -> time_span;
    
    [[nodiscard]] auto compare_to(const time_span& value) const noexcept -> xtd::int32 override;
    
    /// @brief Returns a double value that's the result of dividing this instance by ts.
    /// @param ts The value to be divided by.
    /// @return A new value that represents result of dividing this instance by the value of ts.
    [[nodiscard]] auto divide(const time_span& ts) const -> double;
    /// @brief Returns a new xtd::time_span object whose value is the result of dividing this instance by the specified divisor.
    /// @param divisor The value to be divided by.
    /// @return A new object that represents the value of this instance divided by the value of divisor.
    [[nodiscard]] auto divide(double divisor) const -> time_span;
    
    /// @brief Returns a new xtd::time_span object whose value is the absolute value of the current xtd::time_span object.
    /// @return A new object whose value is the absolute value of the current xtd::time_span object.
    [[nodiscard]] auto duration() const noexcept -> time_span;
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const object& value) const noexcept -> bool override;
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param value The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const time_span& value) const noexcept -> bool override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
    
    /// @brief Returns a new xtd::time_spam object which value is the result of multiplication of this instance and the specified factor.
    /// @param factor The value to be multiplied by.
    /// @return A double that represents the value of this instance multiplied by the value of factor.
    [[nodiscard]] auto multiply(const time_span& ts) const noexcept -> double;
    /// @brief Returns a new xtd::time_spam object which value is the result of multiplication of this instance and the specified factor.
    /// @param factor The value to be multiplied by.
    /// @return A new object that represents the value of this instance multiplied by the value of factor.
    [[nodiscard]] auto multiply(double factor) const noexcept -> time_span;
    
    /// @brief Returns a new xtd::time_spam object whose value is the negated value of this instance.
    /// @return A new object with the same numeric value as this instance, but with the opposite sign.
    /// @exception xtd::overflow_exception The negated value of this instance cannot be represented by a xtd::time_spam; that is, the value of this instance is xtd::time_spam::min_value.
    [[nodiscard]] auto negate() const -> time_span;
    
    /// @brief Returns a new xtd::time_span object whose value is the difference between the specified xtd::time_span object and this instance.
    /// @param ts The time interval to be subtracted.
    /// @return A new time interval whose value is the result of the value of this instance minus the value of ts.
    /// @remarks The return value is a new xtd::time_span; the original xtd::time_span is not modified.
    [[nodiscard]] auto subtract(const time_span& ts) const noexcept -> time_span;
    
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    /// @brief Converts the value of the current xtd::time_span object to its equivalent string representation by using the specified format.
    /// @param format A single format specifier that indicates how to format the value of this xtd::time_span.
    /// @return The string representation of the current xtd::time_span value in the format specified by the format parameter.
    /// @exception xtd::format_exception The format parameter is not recognized or is not supported.
    /// @remarks The format parameter can be any valid standard specifier for XTD::time_span values. If format is equal to xtd::string::empty_string (""), the return value of the current xtd::time_span object is formatted with the common format specifier ("c").
    /// @remarks The formatting codes for xtd::time_span::to_string (const xtd::string&) are listed below:
    /// | Format | Print                                                                                                                       |
    /// | ------ | --------------------------------------------------------------------------------------------------------------------------- |
    /// | 'c'    | write duration with optional ticks d.hh.mm.ss.ticks                                                                         |
    /// | 'd'    | write absolute value of days d                                                                                              |
    /// | 'D'    | write absolute value of days dd                                                                                              |
    /// | 'f'    | write duration d.h.mm.ss.ticks                                                                                              |
    /// | 'F'    | write duration d.hh.mm.ss.ticks                                                                                             |
    /// | 'g'    | write duration with optional ticks d.h.mm.ss.ticks                                                                          |
    /// | 'G'    | write duration with optional ticks d.hh.mm.ss.ticks                                                                         |
    /// | 'h'    | write absolute value of hours h                                                                                             |
    /// | 'H'    | write absolute value of hours hh                                                                                            |
    /// | 'l'    | write absolute value of milliseconds                                                                                        |
    /// | 'L'    | write absolute value of milliseconds fixed at 3 digits                                                                      |
    /// | 'm'    | write absolute value of minutes m                                                                                           |
    /// | 'M'    | write absolute value of minutes mm                                                                                          |
    /// | 'o'    | write optional minus sign                                                                                                   |
    /// | 'o'    | write minus or plus sign                                                                                                    |
    /// | 's'    | write absolute value of seconds s                                                                                           |
    /// | 'S'    | write absolute value of seconds ss                                                                                          |
    /// | 't'    | write absolute value of ticks                                                                                               |
    /// | 'T'    | write absolute value of ticks fixed at 7 digits                                                                             |
    [[nodiscard]] auto to_string(const xtd::string& format) const -> xtd::string;
    
    /// @brief Converts the value of the current xtd::time_span object to its equivalent string representation by using the specified format, and locale.
    /// @param format A single format specifier that indicates how to format the value of this xtd::time_span.
    /// @param culture An xtd::globalization::culture_info object that contains culture information.
    /// @return The string representation of the current xtd::time_span value in the format specified by the format parameter.
    /// @exception xtd::format_exception The format parameter is not recognized or is not supported.
    /// @remarks The format parameter can be any valid standard specifier for XTD::time_span values. If format is equal to xtd::string::empty_string (""), the return value of the current xtd::time_span object is formatted with the common format specifier ("c").
    /// @remarks The formatting codes for xtd::time_span::to_string (const xtd::string&) are listed below:
    /// | Format | Print                                                                                                                       |
    /// | ------ | --------------------------------------------------------------------------------------------------------------------------- |
    /// | 'c'    | write duration with optional ticks d.hh.mm.ss.ticks                                                                         |
    /// | 'd'    | write absolute value of days d                                                                                              |
    /// | 'D'    | write absolute value of days dd                                                                                              |
    /// | 'f'    | write duration d.h.mm.ss.ticks                                                                                              |
    /// | 'F'    | write duration d.hh.mm.ss.ticks                                                                                             |
    /// | 'g'    | write duration with optional ticks d.h.mm.ss.ticks                                                                          |
    /// | 'G'    | write duration with optional ticks d.hh.mm.ss.ticks                                                                         |
    /// | 'h'    | write absolute value of hours h                                                                                             |
    /// | 'H'    | write absolute value of hours hh                                                                                            |
    /// | 'l'    | write absolute value of milliseconds                                                                                        |
    /// | 'L'    | write absolute value of milliseconds fixed at 3 digits                                                                      |
    /// | 'm'    | write absolute value of minutes m                                                                                           |
    /// | 'M'    | write absolute value of minutes mm                                                                                          |
    /// | 'o'    | write optional minus sign                                                                                                   |
    /// | 'o'    | write minus or plus sign                                                                                                    |
    /// | 's'    | write absolute value of seconds s                                                                                           |
    /// | 'S'    | write absolute value of seconds ss                                                                                          |
    /// | 't'    | write absolute value of ticks                                                                                               |
    /// | 'T'    | write absolute value of ticks fixed at 7 digits                                                                             |
    [[nodiscard]] auto to_string(const xtd::string& format, const xtd::globalization::culture_info& culture) const -> xtd::string override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Returns a value that indicates whether two specified instances of xtd::time_span are equal.
    /// @param t1 The first time interval to compare.
    /// @param t2 The second time interval to compare.
    /// @return `true` if the values of t1 and t2 are equal; otherwise, `false`.
    [[nodiscard]] static auto equals(time_span t1, time_span t2) -> bool;
    
    /// @brief Returns a xtd::time_span that represents a specified number of days, where the specification is accurate to the nearest millisecond.
    /// @param value A number of days, accurate to the nearest millisecond.
    /// @return An object that represents value.
    /// @exception xtd::overflow_exception value is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>value is xtd::double_object::positive_infinity.<br>-or-<br>value is xtd::double_object::negative_infinity.
    /// @exception xtd::argument_exception value is equal to xtd::double_object::NaN.
    /// @par Examples
    /// The following example creates several xtd::time_span objects using the xtd::time_span::from_days method.
    /// @include time_span_from_days.cpp
    /// @remarks The value parameter is converted to milliseconds, which is converted to ticks, and that number of ticks is used to initialize the new xd::time_span. Therefore, value will only be considered accurate to the nearest millisecond. Note that, because of the loss of precision of the Double data type, this conversion can cause an xtd::overflow_exception for values that are near to but still in the range of either xd::time_span::min_value or xd::time_span::max_value. For example, this causes an xtd:overflow_exception in the following attempt to instantiate a xd::time_span object.
    /// ```cpp
    /// // The following throws an overflow_exception at runtime
    /// auto max_span = time_span::from_days(time_span::max_value.total_days());
    /// ```
    [[nodiscard]] static auto from_days(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of days, where the specification is accurate to the nearest millisecond.
    /// @param value A number of days, accurate to the nearest millisecond.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_days(std::chrono::days value) -> time_span;
    
    /// @brief Returns a xtd::time_span that represents a specified number of hours, where the specification is accurate to the nearest millisecond.
    /// @param value A number of hours, accurate to the nearest millisecond.
    /// @return An object that represents value.
    /// @exception xtd::overflow_exception value is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>value is xtd::double_object::positive_infinity.<br>-or-<br>value is xtd::double_object::negative_infinity.
    /// @exception xtd::argument_exception value is equal to xtd::double_object::NaN.
    /// @remarks The value parameter is converted to milliseconds, which is converted to ticks, and that number of ticks is used to initialize the new xtd::time_span. Therefore, value will only be considered accurate to the nearest millisecond. Note that, because of the loss of precision of the double data type, this conversion can generate an xtd::overflow_exception for values that are near to but still in the range of either xtd::time_span::min_value or xtd::time_span::max_value. For example, this causes an xtd::overflow_exception in the following attempt to instantiate a xtd::time_span object.
    /// ```cpp
    /// // The following throws an overflow_exception at runtime
    /// auto max_span = time_span::from_hours(time_span::max_value::total_hours());
    /// ```
    /// @par Examples
    /// The following example creates several xtd::time_span objects using the xtd::time_span::from_hours method.
    /// @include time_span_from_hours.cpp
    [[nodiscard]] static auto from_hours(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of hours, where the specification is accurate to the nearest millisecond.
    /// @param value A number of hours, accurate to the nearest millisecond.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_hours(std::chrono::hours value) -> time_span;
    
    /// @brief Returns a xtd::time_span that represents a specified number of microseconds.
    /// @param value A number of microseconds.
    /// @return An object that represents value.
    /// @exception xtd::overflow_exception value is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>value is xtd::double_object::positive_infinity.<br>-or-<br>value is xtd::double_object::negative_infinity.
    /// @exception xtd::argument_exception value is equal to xtd::double_object::NaN.
    [[nodiscard]] static auto from_microseconds(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of microseconds.
    /// @param value A number of microseconds.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_microseconds(std::chrono::microseconds value) -> time_span;
    
    /// @brief Returns a xtd::time_span that represents a specified number of milliseconds.
    /// @param value A number of milliseconds.
    /// @return An object that represents value.
    /// @exception xtd::overflow_exception value is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>value is xtd::double_object::positive_infinity.<br>-or-<br>value is xtd::double_object::negative_infinity.
    /// @exception xtd::argument_exception value is equal to xtd::double_object::NaN.
    /// @remarks The value parameter is converted to ticks, and that number of ticks is used to initialize the new xtd::time_span. Therefore, value will only be considered accurate to the nearest millisecond. Note that, because of the loss of precision of the Double data type, this conversion can generate an xtd::overflow_exception for values that are near to but still in the range of either xtd::time_span::min_value or xtd::time_span::max_value. For example, this causes an xtd::overflow_exception in the following attempt to instantiate a xtd::time_span object.
    /// ```cpp
    /// // The following throws an overflow_exception at runtime
    /// auto max_span = time_span::from_milliseconds(time_span::max_value::total_milliseconds);
    /// ```
    [[nodiscard]] static auto from_milliseconds(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of milliseconds.
    /// @param value A number of milliseconds.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_milliseconds(std::chrono::milliseconds value) -> time_span;
    
    /// @brief Returns a xtd::time_span that represents a specified number of minutes, where the specification is accurate to the nearest millisecond.
    /// @param value A number of minutes, accurate to the nearest millisecond.
    /// @return An object that represents value.
    /// @exception xtd::overflow_exception value is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>value is xtd::double_object::positive_infinity.<br>-or-<br>value is xtd::double_object::negative_infinity.
    /// @exception xtd::argument_exception value is equal to xtd::double_object::NaN.
    /// @remarks The value parameter is converted to milliseconds, which is converted to ticks, and that number of ticks is used to initialize the new xtd::time_span. Therefore, value will only be considered accurate to the nearest millisecond. Note that, because of the loss of precision of the Double data type, this conversion can generate an xtd::overflow_exception for values that are near to but still in the range of either xtd::time_span::min_value or xtd::time_span::max_value. For example, this causes an xtd::overflow_exception in the following attempt to instantiate a xtd::time_span object.
    /// ```cpp
    /// // The following throws an overflow_exception at runtime
    /// auto max_span = time_span::from_minutes(time_span::max_value::total_miminutes);
    /// ```
    [[nodiscard]] static auto from_minutes(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of minutes.
    /// @param value A number of minutes.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_minutes(std::chrono::minutes value) -> time_span;
    
    /// @brief Returns a xtd::time_span that represents a specified number of nanoseconds.
    /// @param value A number of nanoseconds.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_nanoseconds(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of nanoseconds.
    /// @param value A number of nanoseconds.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_nanoseconds(std::chrono::nanoseconds value) -> time_span;
    
    /// @brief Returns a xtd::time_spam that represents a specified number of seconds, where the specification is accurate to the nearest millisecond.
    /// @param value A number of minutes, accurate to the nearest second.
    /// @return An object that represents value.
    /// @exception xtd::overflow_exception value is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>value is xtd::double_object::positive_infinity.<br>-or-<br>value is xtd::double_object::negative_infinity.
    /// @exception xtd::argument_exception value is equal to xtd::double_object::NaN.
    /// @remarks The value parameter is converted to milliseconds, which is converted to ticks, and that number of ticks is used to initialize the new xtd::time_span. Therefore, value will only be considered accurate to the nearest millisecond. Note that, because of the loss of precision of the Double data type, this conversion can generate an xtd::overflow_exception for values that are near to but still in the range of either xtd::time_span::min_value or xtd::time_span::max_value. For example, this causes an xtd::overflow_exception in the following attempt to instantiate a xtd::time_span object.
    /// ```cpp
    /// // The following throws an overflow_exception at runtime
    /// auto max_span = time_span::from_seconds(time_span::max_value::total_seconds);
    /// ```
    [[nodiscard]] static auto from_seconds(double value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of seconds.
    /// @param value A number of seconds.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_seconds(std::chrono::seconds value) -> time_span;
    
    /// @brief Returns a xtd::time_spam that represents a specified time, where the specification is in units of ticks.
    /// @param value A number of ticks that represent a time.
    /// @return An object that represents value.
    [[nodiscard]] static auto from_ticks(int64 value) -> time_span;
    /// @brief Returns a xtd::time_span that represents a specified number of ticks.
    /// @param value A number of ticks.
    /// @return An object that represents value.
    /// @remarks This is a convenience method with the same behavior as the xtd::time_spam.xtd::time_spam (int64) constructor. A single tick represents one hundred nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond.
    [[nodiscard]] static auto from_ticks(xtd::ticks value) -> time_span;
    
    /// @brief Converts the string representation of a time interval to its xtd::time_span equivalent.
    /// @param value A string that specifies the time interval to convert.
    /// @return A time interval that corresponds to value.
    /// @exception xtd::format_exception value has an invalid format.
    /// @exception value represents a number that is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>At least one of the days, hours, minutes, or seconds components is outside its valid range.
    static auto parse(const string& value) -> time_span;
    
    /// @brief Converts the string representation of a time interval to its xtd::time_span equivalent and returns a value that indicates whether the conversion succeeded.
    /// @param value A string that specifies the time interval to convert.
    /// @param result When this method returns, contains an object that represents the time interval specified by value, or xtd::time_span::zero if the conversion failed.
    /// @return `true` if s was converted successfully; otherwise, `false`. This operation returns `false` if the value parameter is empty (""), has an invalid format, represents a time interval that is less than xtd::time_span::min_value or greater than xtd::time_span::max_value, or has at least one days, hours, minutes, or seconds component outside its valid range.
    [[nodiscard]] static auto try_parse(const string& value, time_span& result) -> bool;
    /// @}
    
  private:
    static constexpr int32 millis_per_second = 1000;
    static constexpr int32 millis_per_minute = millis_per_second * 60; //     60,000
    static constexpr int32 millis_per_hour = millis_per_minute * 60;   //  3,600,000
    static constexpr int32 millis_per_day = millis_per_hour * 24;      // 86,400,000
    
    static constexpr int32 parse_succeed = 0;
    static constexpr int32 parse_overflow = 1;
    static constexpr int32 parse_format = 2;
    
    [[nodiscard]] static auto interval(double value, int scale) -> time_span;
    [[nodiscard]] auto make_string_from_duration(bool constant) const -> xtd::string;
    [[nodiscard]] static auto try_parse_internal(const string& value, time_span& result) -> xtd::int32;
    
    int64 ticks_ = 0;
  };
  /// @}
  
  /// @brief Converts the string representation of a time interval to its xtd::time_span equivalent.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value A string that specifies the time interval to convert.
  /// @return A time interval that corresponds to value.
  /// @exception xtd::format_exception value has an invalid format.
  /// @exception value represents a number that is less than xtd::time_span::min_value or greater than xtd::time_span::max_value.<br>-or-<br>At least one of the days, hours, minutes, or seconds components is outside its valid range.
  template<>
  [[nodiscard]] inline auto parse<time_span>(const std::string& str) -> xtd::time_span {return time_span::parse(str);}
}

#include "literals/time_span.hpp"
