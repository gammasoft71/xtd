#include <xtd/time_span>
#include <xtd/divided_by_zero_exception>
#include <xtd/int64_object>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(time_span_tests) {
    void test_method_(nanoseconds_per_tick) {
      assert::are_equal(100ll, time_span::nanoseconds_per_tick, csf_);
    }
    
    void test_method_(ticks_per_microsecond) {
      assert::are_equal(10ll, time_span::ticks_per_microsecond, csf_);
    }
    
    void test_method_(ticks_per_millisecond) {
      assert::are_equal(time_span::ticks_per_microsecond * 1'000, time_span::ticks_per_millisecond, csf_);
      assert::are_equal(10'000ll, time_span::ticks_per_millisecond, csf_);
    }

    void test_method_(ticks_per_second) {
      assert::are_equal(time_span::ticks_per_millisecond * 1'000, time_span::ticks_per_second, csf_);
      assert::are_equal(10'000'000ll, time_span::ticks_per_second, csf_);
    }

    void test_method_(ticks_per_minute) {
      assert::are_equal(time_span::ticks_per_second * 60, time_span::ticks_per_minute, csf_);
      assert::are_equal(600'000'000ll, time_span::ticks_per_minute, csf_);
    }
    
    void test_method_(ticks_per_hour) {
      assert::are_equal(time_span::ticks_per_minute * 60, time_span::ticks_per_hour, csf_);
      assert::are_equal(36'000'000'000ll, time_span::ticks_per_hour, csf_);
    }

    void test_method_(ticks_per_day) {
      assert::are_equal(time_span::ticks_per_hour * 24, time_span::ticks_per_day, csf_);
      assert::are_equal(864'000'000'000ll, time_span::ticks_per_day, csf_);
    }
    
    void test_method_(max_value) {
      assert::are_equal(int64_object::max_value, time_span::max_value.ticks(), csf_);
    }

    void test_method_(min_value) {
      assert::are_equal(int64_object::min_value, time_span::min_value.ticks(), csf_);
    }

    void test_method_(zero) {
      assert::is_zero(time_span::zero, csf_);
    }

    void test_method_(default_ctor) {
      assert::is_zero(time_span {}, csf_);
    }
    
    void test_method_(ctor_with_ticks) {
      assert::are_equal(42ll, time_span {42}.ticks(), csf_);
      assert::are_equal(-42ll, time_span {-42}.ticks(), csf_);
      assert::are_equal(int64_object::max_value, time_span {int64_object::max_value}.ticks(), csf_);
      assert::are_equal(int64_object::min_value, time_span {int64_object::min_value}.ticks(), csf_);
    }

    void test_method_(ctor_with_ticks_duration) {
      assert::are_equal(42ll, time_span {xtd::ticks {42}}.ticks(), csf_);
      assert::are_equal(-42ll, time_span {xtd::ticks {-42}}.ticks(), csf_);
    }
    
    void test_method_(ctor_with_hours_minutes_seconds) {
      assert::are_equal(37'230'000'000ll, time_span {1, 2, 3}.ticks(), csf_);
      assert::are_equal(37'830'000'000ll, time_span {1, 2, 63}.ticks(), csf_);
      assert::are_equal(73'230'000'000ll, time_span {1, 62, 3}.ticks(), csf_);
      assert::are_equal(901'230'000'000ll, time_span {25, 2, 3}.ticks(), csf_);
      assert::are_equal(-109'210'000'000ll, time_span {-3, -2, -1}.ticks(), csf_);
      assert::are_equal(-106'790'000'000ll, time_span {-3, 2, 1}.ticks(), csf_);
      assert::are_equal(time_span {-2, -57, -59}, time_span {-3, 2, 1}, csf_);
    }
    
    void test_method_(ctor_with_days_hours_minutes_seconds) {
      assert::are_equal(20'773'230'000'000ll, time_span {24, 1, 2, 3}.ticks(), csf_);
    }
    
    void test_method_(ctor_with_days_hours_minutes_seconds_milliseconds) {
      assert::are_equal(20'773'230'720'000ll, time_span {24, 1, 2, 3, 72}.ticks(), csf_);
    }
    
    void test_method_(ctor_with_days_hours_minutes_seconds_milliseconds_microseconds) {
      assert::are_equal(20'773'230'720'420ll, time_span {24, 1, 2, 3, 72, 42}.ticks(), csf_);
    }
    
    void test_method_(ctor_with_days_hours_minutes_seconds_milliseconds_microseconds_nanoseconds) {
      assert::are_equal(20'773'230'720'428ll, time_span {24, 1, 2, 3, 72, 42, 840}.ticks(), csf_);
    }

    void test_method_(copy_ctor) {
      time_span ts {42};
      assert::are_equal(42ll, time_span {ts}.ticks(), csf_);
      assert::are_equal(ts, time_span {ts}, csf_);
    }
    
    void test_method_(ctor_with_microseconds_duration) {
      assert::are_equal(420ll, time_span {chrono::microseconds {42}}.ticks(), csf_);
      assert::are_equal(-420ll, time_span {chrono::microseconds {-42}}.ticks(), csf_);
    }

    void test_method_(ctor_with_milliseconds_duration) {
      assert::are_equal(420'000ll, time_span {chrono::milliseconds {42}}.ticks(), csf_);
      assert::are_equal(-420'000ll, time_span {chrono::milliseconds {-42}}.ticks(), csf_);
    }

    void test_method_(ctor_with_seconds_duration) {
      assert::are_equal(420'000'000ll, time_span {chrono::seconds {42}}.ticks(), csf_);
      assert::are_equal(-420'000'000ll, time_span {chrono::seconds {-42}}.ticks(), csf_);
    }

    void test_method_(ctor_with_minutes_duration) {
      assert::are_equal(25'200'000'000ll, time_span {chrono::minutes {42}}.ticks(), csf_);
      assert::are_equal(-25'200'000'000ll, time_span {chrono::minutes {-42}}.ticks(), csf_);
    }

    void test_method_(ctor_with_hours_duration) {
      assert::are_equal(1'512'000'000'000ll, time_span {chrono::hours {42}}.ticks(), csf_);
      assert::are_equal(-1'512'000'000'000ll, time_span {chrono::hours {-42}}.ticks(), csf_);
    }

    void test_method_(ctor_with_days_duration) {
      assert::are_equal(36'288'000'000'000ll, time_span {chrono::days {42}}.ticks(), csf_);
      assert::are_equal(-36'288'000'000'000ll, time_span {chrono::days {-42}}.ticks(), csf_);
    }

    void test_method_(operator_divide) {
      assert::are_equal(21.0, (time_span {42} / time_span {2}), csf_);
      assert::are_equal(-21.0, (time_span {42} / time_span {-2}), csf_);
      assert::are_equal(21, (time_span {42} / 2.0).ticks(), csf_);
      assert::are_equal(-21, (time_span {42} / -2.0).ticks(), csf_);
    }
    
    void test_method_(operator_divide_by_zero_exception) {
      assert::throws<divided_by_zero_exception>([]{time_span {42} / time_span {0};}, csf_);
      assert::throws<divided_by_zero_exception>([]{time_span {42} / .0;}, csf_);
    }
    
    void test_method_(operator_minus) {
      assert::are_equal(18, (time_span {42} - time_span {24}).ticks(), csf_);
      assert::are_equal(66, (time_span {42} - time_span {-24}).ticks(), csf_);
      assert::are_equal(-66, (time_span {-42} - time_span {24}).ticks(), csf_);
      assert::are_equal(-18, (time_span {-42} - time_span {-24}).ticks(), csf_);
    }
    
    void test_method_(operator_minus_equal) {
      auto ts = time_span {42};
      ts -= time_span {24};
      assert::are_equal(18, ts.ticks(), csf_);
    }
    
    void test_method_(operator_multiply) {
      assert::are_equal(84, (time_span {42} * time_span {2}), csf_);
      assert::are_equal(-84, (time_span {42} * time_span {-2}), csf_);
      assert::are_equal(84, (time_span {42} * 2.0).ticks(), csf_);
      assert::are_equal(-84, (time_span {42} * -2.0).ticks(), csf_);
    }
    
    void test_method_(operator_plus) {
      assert::are_equal(66, (time_span {42} + time_span {24}).ticks(), csf_);
      assert::are_equal(18, (time_span {42} + time_span {-24}).ticks(), csf_);
      assert::are_equal(-18, (time_span {-42} + time_span {24}).ticks(), csf_);
      assert::are_equal(-66, (time_span {-42} + time_span {-24}).ticks(), csf_);
    }
    
    void test_method_(operator_plus_equal) {
      auto ts = time_span {42};
      ts += time_span {24};
      assert::are_equal(66, ts.ticks(), csf_);
    }
    
    void test_method_(operator_post_decrement) {
      auto ts = time_span {42};
      assert::are_equal(42, (ts--).ticks(), csf_);
      assert::are_equal(41, ts.ticks(), csf_);
    }
    
    void test_method_(operator_post_increment) {
      auto ts = time_span {42};
      assert::are_equal(42, (ts++).ticks(), csf_);
      assert::are_equal(43, ts.ticks(), csf_);
    }
    
    void test_method_(operator_pre_decrement) {
      auto ts = time_span {42};
      assert::are_equal(41, (--ts).ticks(), csf_);
    }
    
    void test_method_(operator_pre_increment) {
      auto ts = time_span {42};
      assert::are_equal(43, (++ts).ticks(), csf_);
    }
    
    void test_method_(operator_unary_minus) {
      assert::are_equal(-42, -time_span {42}.ticks(), csf_);
      assert::are_equal(42, -time_span {-42}.ticks(), csf_);
    }
    
    void test_method_(operator_unary_plus) {
      assert::are_equal(42, +time_span {42}.ticks(), csf_);
      assert::are_equal(-42, +time_span {-42}.ticks(), csf_);
    }
    
    void test_method_(days) {
      assert::is_zero(time_span {}.days(), csf_);
      assert::is_zero(time_span {1, 2, 3}.days(), csf_);
      assert::are_equal(1, time_span {1, 2, 3, 4}.days(), csf_);
    }
    
    void test_method_(hours) {
      assert::is_zero(time_span {}.hours(), csf_);
      assert::are_equal(1, time_span {1, 2, 3}.hours(), csf_);
    }
    
    void test_method_(microseconds) {
      assert::is_zero(time_span {}.microseconds(), csf_);
      assert::are_equal(6, time_span {1, 2, 3, 4, 5, 6}.microseconds(), csf_);
    }
    
    void test_method_(milliseconds) {
      assert::is_zero(time_span {}.milliseconds(), csf_);
      assert::are_equal(5, time_span {1, 2, 3, 4, 5}.milliseconds(), csf_);
    }

    void test_method_(minutes) {
      assert::is_zero(time_span {}.minutes(), csf_);
      assert::are_equal(2, time_span {1, 2, 3}.minutes(), csf_);
    }
    
    void test_method_(nanoseconds) {
      assert::is_zero(time_span {}.nanoseconds(), csf_);
      assert::is_zero(time_span {1, 2, 3, 4, 5, 6, 7}.nanoseconds(), csf_);
      assert::are_equal(700, time_span {1, 2, 3, 4, 5, 6, 789}.nanoseconds(), csf_);
    }

    void test_method_(seconds) {
      assert::is_zero(time_span {}.seconds(), csf_);
      assert::are_equal(3, time_span {1, 2, 3}.seconds(), csf_);
    }

    void test_method_(ticks) {
      assert::is_zero(time_span {}.ticks(), csf_);
      assert::are_equal(37'230'000'000ll, time_span {1, 2, 3}.ticks(), csf_);
    }

    void test_method_(ticks_duration) {
      assert::is_zero(time_span {}.ticks(), csf_);
      assert::are_equal(xtd::ticks {37'230'000'000ll}, time_span {1, 2, 3}.ticks_duration(), csf_);
    }

    void test_method_(total_days) {
      assert::is_zero(time_span {}.total_days(), csf_);
      assert::are_equal(0.0430903, time_span {1, 2, 3}.total_days(), 0.0000001, csf_);
      assert::are_equal(1.08546, time_span {1, 2, 3, 4}.total_days(), 0.00001, csf_);
    }

    void test_method_(total_days_duration) {
      assert::is_zero(time_span {}.total_days_duration(), csf_);
      assert::are_equal(chrono::days {0}, time_span {1, 2, 3}.total_days_duration(), csf_);
      assert::are_equal(chrono::days {1}, time_span {1, 2, 3, 4}.total_days_duration(), csf_);
    }

    void test_method_(total_hours) {
      assert::is_zero(time_span {}.total_hours(), csf_);
      assert::are_equal(1.03417, time_span {1, 2, 3}.total_hours(), 0.00001, csf_);
    }

    void test_method_(total_hours_duration) {
      assert::is_zero(time_span {}.total_hours_duration(), csf_);
      assert::are_equal(chrono::hours {1}, time_span {1, 2, 3}.total_hours_duration(), csf_);
    }

    void test_method_(total_microseconds) {
      assert::is_zero(time_span {}.total_microseconds(), csf_);
      assert::are_equal(9.3784e+10, time_span {1, 2, 3, 4, 5, 6}.total_microseconds(), 0.0001e+10, csf_);
    }

    void test_method_(total_microseconds_duration) {
      assert::is_zero(time_span {}.total_microseconds_duration(), csf_);
      assert::are_equal(chrono::microseconds {93784005006}, time_span {1, 2, 3, 4, 5, 6}.total_microseconds_duration(), csf_);
    }

    void test_method_(total_milliseconds) {
      assert::is_zero(time_span {}.total_milliseconds(), csf_);
      assert::are_equal(9.3784e+07, time_span {1, 2, 3, 4, 5}.total_milliseconds(), 0.0001e+07, csf_);
    }

    void test_method_(total_milliseconds_duration) {
      assert::is_zero(time_span {}.total_milliseconds_duration(), csf_);
      assert::are_equal(chrono::milliseconds {93784005}, time_span {1, 2, 3, 4, 5}.total_milliseconds_duration(), csf_);
    }

    void test_method_(total_minutes) {
      assert::is_zero(time_span {}.total_minutes(), csf_);
      assert::are_equal(62.05, time_span {1, 2, 3}.total_minutes(), csf_);
    }

    void test_method_(total_minutes_duration) {
      assert::is_zero(time_span {}.total_minutes_duration(), csf_);
      assert::are_equal(chrono::minutes {62}, time_span {1, 2, 3}.total_minutes_duration(), csf_);
    }

    void test_method_(total_nanoseconds) {
      assert::is_zero(time_span {}.total_nanoseconds(), csf_);
      assert::are_equal(9.3784e+13, time_span {1, 2, 3, 4, 5, 6, 789}.total_nanoseconds(), 0.0001e+13, csf_);
    }

    void test_method_(total_nanoseconds_duration) {
      assert::is_zero(time_span {}.total_nanoseconds_duration(), csf_);
      assert::are_equal(chrono::nanoseconds {93784005006700}, time_span {1, 2, 3, 4, 5, 6, 789}.total_nanoseconds_duration(), csf_);
    }

    void test_method_(total_seconds) {
      assert::is_zero(time_span {}.total_seconds(), csf_);
      assert::are_equal(3723.0, time_span {1, 2, 3}.total_seconds(), csf_);
    }

    void test_method_(total_seconds_duration) {
      assert::is_zero(time_span {}.total_seconds_duration(), csf_);
      assert::are_equal(chrono::seconds {3723}, time_span {1, 2, 3}.total_seconds_duration(), csf_);
    }

    void test_method_(add) {
      assert::are_equal(66, time_span {42}.add(time_span {24}).ticks(), csf_);
      assert::are_equal(18, time_span {42}.add(time_span {-24}).ticks(), csf_);
      assert::are_equal(-18, time_span {-42}.add(time_span {24}).ticks(), csf_);
      assert::are_equal(-66, time_span {-42}.add(time_span {-24}).ticks(), csf_);
    }
    
    void test_method_(compare_to) {
      auto ts1 = time_span::from_days(1.5);
      auto ts2 = time_span::from_hours(1.5);
      auto ts3 = time_span::from_hours(-1.5);
      
      assert::are_equal(1, ts1.compare_to(ts2), csf_);
      assert::are_equal(0, ts1.compare_to(ts1), csf_);
      assert::are_equal(-1, ts3.compare_to(ts2), csf_);
    }

    void test_method_(divide) {
      assert::are_equal(21.0, time_span {42}.divide(time_span {2}), csf_);
      assert::are_equal(-21.0, time_span {42}.divide(time_span {-2}), csf_);
      assert::are_equal(21, time_span {42}.divide(2.0).ticks(), csf_);
      assert::are_equal(-21, time_span {42}.divide(-2.0).ticks(), csf_);
    }
    
    void test_method_(divide_by_zero_exception) {
      assert::throws<divided_by_zero_exception>([]{time_span {42}.divide(time_span {0});}, csf_);
      assert::throws<divided_by_zero_exception>([]{time_span {42}.divide(.0);}, csf_);
    }
    
    void test_method_(duration) {
      assert::are_equal(42, time_span {42}.duration().ticks(), csf_);
      assert::are_equal(42, time_span {-42}.duration().ticks(), csf_);
    }
    
    void test_method_(equals) {
      assert::is_true(time_span {42}.equals(time_span {42}), csf_);
      assert::is_false(time_span {42}.equals(time_span {-42}), csf_);
    }
    
    void test_method_(equals_static) {
      assert::is_true(time_span::equals(time_span {42}, time_span {42}), csf_);
      assert::is_false(time_span::equals(time_span {42}, time_span {-42}), csf_);
    }

    void test_method_(from_days) {
      assert::are_equal(36'288'000'000'000ll, time_span::from_days(42.0).ticks(), csf_);
      assert::are_equal(-36'288'000'000'000ll, time_span::from_days(-42.0).ticks(), csf_);
      assert::are_equal(1'296'000'000'000ll, time_span::from_days(1.5).ticks(), csf_);
      assert::are_equal(38'188'800'000'000ll, time_span::from_days(44.2).ticks(), csf_);
    }

    void test_method_(from_days_duration) {
      assert::are_equal(36'288'000'000'000ll, time_span::from_days(chrono::days {42}).ticks(), csf_);
      assert::are_equal(-36'288'000'000'000ll, time_span::from_days(chrono::days {-42}).ticks(), csf_);
    }

    void test_method_(from_hours) {
      assert::are_equal(1'512'000'000'000ll, time_span::from_hours(42.0).ticks(), csf_);
      assert::are_equal(-1'512'000'000'000ll, time_span::from_hours(-42.0).ticks(), csf_);
      assert::are_equal(54'000'000'000ll, time_span::from_hours(1.5).ticks(), csf_);
      assert::are_equal(802'800'000'000ll, time_span::from_hours(22.3).ticks(), csf_);
    }
    
    void test_method_(from_hours_duration) {
      assert::are_equal(1'512'000'000'000ll, time_span::from_hours(chrono::hours {42}).ticks(), csf_);
      assert::are_equal(-1'512'000'000'000ll, time_span::from_hours(chrono::hours {-42}).ticks(), csf_);
    }
    
    void test_method_(from_microseconds) {
      assert::are_equal(420ll, time_span::from_microseconds(42.0).ticks(), csf_);
      assert::are_equal(-420ll, time_span::from_microseconds(-42.0).ticks(), csf_);
    }
    
    void test_method_(from_microseconds_duration) {
      assert::are_equal(420ll, time_span::from_microseconds(chrono::microseconds {42}).ticks(), csf_);
      assert::are_equal(-420ll, time_span::from_microseconds(chrono::microseconds {-42}).ticks(), csf_);
    }

    void test_method_(from_milliseconds) {
      assert::are_equal(420'000ll, time_span::from_milliseconds(42.0).ticks(), csf_);
      assert::are_equal(-420'000ll, time_span::from_milliseconds(-42.0).ticks(), csf_);
      assert::are_equal(2'570'000ll, time_span::from_milliseconds(256.7).ticks(), csf_);
      assert::are_equal(2'560'000ll, time_span::from_milliseconds(static_cast<int64>(256.7)).ticks(), csf_);
      assert::are_equal(290'000ll, time_span::from_milliseconds((29.0 / 100.0) * 100).ticks(), csf_);
      assert::are_equal(280'000ll, time_span::from_milliseconds(static_cast<int64>((29.0 / 100.0) * 100)).ticks(), csf_);
      assert::are_equal(-10'000ll, time_span::from_milliseconds(-1).ticks(), csf_);
    }
    
    void test_method_(from_milliseconds_duration) {
      assert::are_equal(420'000ll, time_span::from_milliseconds(chrono::milliseconds {42}).ticks(), csf_);
      assert::are_equal(-420'000ll, time_span::from_milliseconds(chrono::milliseconds {-42}).ticks(), csf_);
    }

    void test_method_(from_minutes) {
      assert::are_equal(25'200'000'000ll, time_span::from_minutes(42.0).ticks(), csf_);
      assert::are_equal(-25'200'000'000ll, time_span::from_minutes(-42.0).ticks(), csf_);
      assert::are_equal(458'070'000'000ll, time_span::from_minutes(763.45).ticks(), csf_);
    }
    
    void test_method_(from_minutes_duration) {
      assert::are_equal(25'200'000'000ll, time_span::from_minutes(chrono::minutes {42}).ticks(), csf_);
      assert::are_equal(-25'200'000'000ll, time_span::from_minutes(chrono::minutes {-42}).ticks(), csf_);
    }

    void test_method_(from_nanoseconds) {
      assert::is_zero(time_span::from_nanoseconds(42.0).ticks(), csf_);
      assert::are_equal(4ll, time_span::from_nanoseconds(420.0).ticks(), csf_);
      assert::are_equal(-4ll, time_span::from_nanoseconds(-420.0).ticks(), csf_);
      assert::are_equal(2ll, time_span::from_nanoseconds(256.7).ticks(), csf_);
      assert::are_equal(2ll, time_span::from_nanoseconds(static_cast<int64>(256.7)).ticks(), csf_);
      assert::are_equal(2ll, time_span::from_nanoseconds((290.0 / 100.0) * 100).ticks(), csf_);
      assert::are_equal(2ll, time_span::from_nanoseconds(static_cast<int64>((290.0 / 100.0) * 100)).ticks(), csf_);
      assert::are_equal(-1ll, time_span::from_nanoseconds(-100).ticks(), csf_);
    }

    void test_method_(from_nanoseconds_duration) {
      assert::are_equal(4ll, time_span::from_nanoseconds(chrono::nanoseconds {420}).ticks(), csf_);
      assert::are_equal(-4ll, time_span::from_nanoseconds(chrono::nanoseconds {-420}).ticks(), csf_);
    }

    void test_method_(from_seconds) {
      assert::are_equal(420'000'000ll, time_span::from_seconds(42.0).ticks(), csf_);
      assert::are_equal(-420'000'000ll, time_span::from_seconds(-42.0).ticks(), csf_);
      assert::are_equal(35'000'000ll, time_span::from_seconds(3.5).ticks(), csf_);
    }
    
    void test_method_(from_seconds_duration) {
      assert::are_equal(420'000'000ll, time_span::from_seconds(chrono::seconds {42}).ticks(), csf_);
      assert::are_equal(-420'000'000ll, time_span::from_seconds(chrono::seconds {-42}).ticks(), csf_);
    }

    void test_method_(from_ticks) {
      assert::are_equal(42ll, time_span::from_ticks(42).ticks(), csf_);
      assert::are_equal(-42ll, time_span::from_ticks(-42).ticks(), csf_);
      assert::are_equal(678'434'567'745'603ll, time_span::from_ticks(678434567745603LL).ticks(), csf_);
    }
    
    void test_method_(from_ticks_duration) {
      assert::are_equal(42ll, time_span::from_ticks(xtd::ticks {42}).ticks(), csf_);
      assert::are_equal(-42ll, time_span::from_ticks(xtd::ticks {-42}).ticks(), csf_);
    }

    void test_method_(multiply) {
      assert::are_equal(84, time_span {42}.multiply(time_span {2}), csf_);
      assert::are_equal(-84, time_span {42}.multiply(time_span {-2}), csf_);
      assert::are_equal(84, time_span {42}.multiply(2.0).ticks(), csf_);
      assert::are_equal(-84, time_span {42}.multiply(-2.0).ticks(), csf_);
    }

    void test_method_(negate) {
      assert::are_equal(-42, time_span {42}.negate().ticks(), csf_);
      assert::are_equal(42, time_span {-42}.negate().ticks(), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal("6.00:00:00", time_span::parse("6").to_string(), csf_);
      assert::are_equal("06:12:00", time_span::parse("6:12").to_string(), csf_);
      assert::are_equal("06:12:14", time_span::parse("6:12:14").to_string(), csf_);
      assert::are_equal("06:12:14", time_span::parse("06:12:14").to_string(), csf_);
      assert::are_equal("6.12:14:45", time_span::parse("6:12:14:45").to_string(), csf_);
      assert::are_equal("6.12:14:45", time_span::parse("06.12:14:45").to_string(), csf_);
      assert::are_equal("6.12:14:45.3440000", time_span::parse("6.12:14:45.3440000").to_string(), csf_);
      assert::are_equal("-6.12:14:45.3440000", time_span::parse("-6.12:14:45.3440000").to_string(), csf_);
    }
    
    void test_method_(parse_with_overflow_exception) {
      assert::throws<overflow_exception>([] {time_span::parse("25:12:00");}, csf_);
      assert::throws<overflow_exception>([] {time_span::parse("6:61:00");}, csf_);
      assert::throws<overflow_exception>([] {time_span::parse("6:00:61");}, csf_);
    }
    
    void test_method_(parse_with_format_exception) {
      assert::throws<format_exception>([] {time_span::parse("6.12:14:45.344");}, csf_);
      assert::throws<format_exception>([] {time_span::parse("6.12:14:45.344000");}, csf_);
      assert::throws<format_exception>([] {time_span::parse("6.12:14:45.34400000");}, csf_);
      assert::throws<format_exception>([] {time_span::parse("6.2:12:14:45.3440000");}, csf_);
    }
    
    void test_method_(subtract) {
      assert::are_equal(18, time_span {42}.subtract(time_span {24}).ticks(), csf_);
      assert::are_equal(66, time_span {42}.subtract(time_span {-24}).ticks(), csf_);
      assert::are_equal(-66, time_span {-42}.subtract(time_span {24}).ticks(), csf_);
      assert::are_equal(-18, time_span {-42}.subtract(time_span {-24}).ticks(), csf_);
    }
    
    void test_method_(to_string) {
      assert::are_equal("00:00:00", time_span::zero.to_string(), csf_);
      assert::are_equal("-14.00:00:00", time_span {-14, 0, 0, 0, 0}.to_string(), csf_);
      assert::are_equal("01:02:03", time_span {1, 2, 3}.to_string(), csf_);
      assert::are_equal("00:00:00.2500000", time_span {0, 0, 0, 0, 250}.to_string(), csf_);
      assert::are_equal("99.23:59:59.9990000", time_span {99, 23, 59, 59, 999}.to_string(), csf_);
      assert::are_equal("03:00:00", time_span {3, 0, 0}.to_string(), csf_);
      assert::are_equal("00:00:00.0250000", time_span {0, 0, 0, 0, 25}.to_string(), csf_);
      assert::are_equal("00:00:00.0000023", time_span {23}.to_string(), csf_);
      assert::are_equal("5.01:45:23.3896842", time_span {4383233896842}.to_string(), csf_);
      assert::are_equal("-10675199.02:48:05.4775808", time_span::min_value.to_string(), csf_);
      assert::are_equal("10675199.02:48:05.4775807", time_span::max_value.to_string(), csf_);
    }
    
    void test_method_(to_string_with_format_c) {
      assert::are_equal("03:38:45", time_span {3, 38, 45}.to_string("c"), csf_);
      assert::are_equal("17:38:45", time_span {17, 38, 45}.to_string("c"), csf_);
      assert::are_equal("5.17:38:45.0230420", time_span {5, 17, 38, 45, 23, 42}.to_string("c"), csf_);
      assert::are_equal("5.08:38:45.0230420", time_span {5, 8, 38, 45, 23, 42}.to_string("c"), csf_);
      assert::are_equal("15.08:38:45.0230420", time_span {15, 8, 38, 45, 23, 42}.to_string("c"), csf_);
      assert::are_equal("-03:38:45", time_span {-3, -38, -45}.to_string("c"), csf_);
    }
    
    void test_method_(to_string_with_format_d) {
      assert::are_equal("0", time_span {0, 3, 38, 45, 23, 42}.to_string("d"), csf_);
      assert::are_equal("4", time_span {4, 3, 38, 45, 23, 42}.to_string("d"), csf_);
      assert::are_equal("15", time_span {15, 3, 38, 45, 23, 42}.to_string("d"), csf_);
      assert::are_equal("4", time_span {-4, -3, -38, -45, -23, -42}.to_string("d"), csf_);
    }
    
    void test_method_(to_string_with_format_D) {
      assert::are_equal("00", time_span {0, 3, 38, 45, 23, 42}.to_string("D"), csf_);
      assert::are_equal("04", time_span {4, 3, 38, 45, 23, 42}.to_string("D"), csf_);
      assert::are_equal("15", time_span {15, 3, 38, 45, 23, 42}.to_string("D"), csf_);
      assert::are_equal("04", time_span {-4, -3, -38, -45, -23, -42}.to_string("D"), csf_);
    }
    
    void test_method_(to_string_with_format_f) {
      assert::are_equal("0.3:38:45.0000000", time_span {3, 38, 45}.to_string("f"), csf_);
      assert::are_equal("0.3:38:45.0230420", time_span {0, 3, 38, 45, 23, 42}.to_string("f"), csf_);
      assert::are_equal("4.3:38:45.0230420", time_span {4, 3, 38, 45, 23, 42}.to_string("f"), csf_);
      assert::are_equal("15.3:38:45.0230420", time_span {15, 3, 38, 45, 23, 42}.to_string("f"), csf_);
      assert::are_equal("-0.3:38:45.0000000", time_span {-3, -38, -45}.to_string("f"), csf_);
    }
    
    void test_method_(to_string_with_format_F) {
      assert::are_equal("0.03:38:45.0000000", time_span {3, 38, 45}.to_string("F"), csf_);
      assert::are_equal("0.03:38:45.0230420", time_span {0, 3, 38, 45, 23, 42}.to_string("F"), csf_);
      assert::are_equal("4.03:38:45.0230420", time_span {4, 3, 38, 45, 23, 42}.to_string("F"), csf_);
      assert::are_equal("15.03:38:45.0230420", time_span {15, 3, 38, 45, 23, 42}.to_string("F"), csf_);
      assert::are_equal("-0.03:38:45.0000000", time_span {-3, -38, -45}.to_string("F"), csf_);
    }
    
    void test_method_(to_string_with_format_g) {
      assert::are_equal("3:38:45", time_span {3, 38, 45}.to_string("g"), csf_);
      assert::are_equal("17:38:45", time_span {17, 38, 45}.to_string("g"), csf_);
      assert::are_equal("5.17:38:45.0230420", time_span {5, 17, 38, 45, 23, 42}.to_string("g"), csf_);
      assert::are_equal("5.8:38:45.0230420", time_span {5, 8, 38, 45, 23, 42}.to_string("g"), csf_);
      assert::are_equal("15.8:38:45.0230420", time_span {15, 8, 38, 45, 23, 42}.to_string("g"), csf_);
      assert::are_equal("-3:38:45", time_span {-3, -38, -45}.to_string("g"), csf_);
    }
    
    void test_method_(to_string_with_format_G) {
      assert::are_equal("03:38:45", time_span {3, 38, 45}.to_string("G"), csf_);
      assert::are_equal("17:38:45", time_span {17, 38, 45}.to_string("G"), csf_);
      assert::are_equal("5.17:38:45.0230420", time_span {5, 17, 38, 45, 23, 42}.to_string("G"), csf_);
      assert::are_equal("5.08:38:45.0230420", time_span {5, 8, 38, 45, 23, 42}.to_string("G"), csf_);
      assert::are_equal("15.08:38:45.0230420", time_span {15, 8, 38, 45, 23, 42}.to_string("G"), csf_);
      assert::are_equal("-03:38:45", time_span {-3, -38, -45}.to_string("G"), csf_);
    }
    
    void test_method_(to_string_with_format_h) {
      assert::are_equal("3", time_span {3, 38, 45}.to_string("h"), csf_);
      assert::are_equal("15", time_span {15, 38, 45}.to_string("h"), csf_);
      assert::are_equal("3", time_span {-3, -38, -45}.to_string("h"), csf_);
    }
    
    void test_method_(to_string_with_format_H) {
      assert::are_equal("03", time_span {3, 38, 45}.to_string("H"), csf_);
      assert::are_equal("15", time_span {15, 38, 45}.to_string("H"), csf_);
      assert::are_equal("03", time_span {-3, -38, -45}.to_string("H"), csf_);
    }
    
    void test_method_(to_string_with_format_l) {
      assert::are_equal("23", time_span {0, 3, 38, 45, 23}.to_string("l"), csf_);
      assert::are_equal("23", time_span {0, -3, -38, -45, -23}.to_string("l"), csf_);
    }
    
    void test_method_(to_string_with_format_L) {
      assert::are_equal("023", time_span {0, 3, 38, 45, 23}.to_string("L"), csf_);
      assert::are_equal("023", time_span {0, -3, -38, -45, -23}.to_string("L"), csf_);
    }
    
    void test_method_(to_string_with_format_m) {
      assert::are_equal("8", time_span {0, 3, 8, 45, 23}.to_string("m"), csf_);
      assert::are_equal("8", time_span {0, -3, -8, -45, -23}.to_string("m"), csf_);
    }
    
    void test_method_(to_string_with_format_M) {
      assert::are_equal("08", time_span {0, 3, 8, 45, 23}.to_string("M"), csf_);
      assert::are_equal("08", time_span {0, -3, -8, -45, -23}.to_string("M"), csf_);
    }
    
    void test_method_(to_string_with_format_o) {
      assert::is_empty(time_span {3, 38, 45}.to_string("o"), csf_);
      assert::are_equal("-", time_span {-3, -38, -45}.to_string("o"), csf_);
    }
    
    void test_method_(to_string_with_format_O) {
      assert::are_equal("+", time_span {3, 38, 45}.to_string("O"), csf_);
      assert::are_equal("-", time_span {-3, -38, -45}.to_string("O"), csf_);
    }
    
    void test_method_(to_string_with_format_s) {
      assert::are_equal("5", time_span {3, 38, 5}.to_string("s"), csf_);
      assert::are_equal("5", time_span {-3, -38, -5}.to_string("s"), csf_);
    }
    
    void test_method_(to_string_with_format_S) {
      assert::are_equal("05", time_span {3, 38, 5}.to_string("S"), csf_);
      assert::are_equal("05", time_span {-3, -38, -5}.to_string("S"), csf_);
    }
    
    void test_method_(to_string_with_format_t) {
      assert::are_equal("23", time_span {23}.to_string("t"), csf_);
      assert::are_equal("23", time_span {-23}.to_string("t"), csf_);
    }
    
    void test_method_(to_string_with_format_T) {
      assert::are_equal("0000023", time_span {23}.to_string("T"), csf_);
      assert::are_equal("0000023", time_span {-23}.to_string("T"), csf_);
    }
    
    void test_method_(try_parse) {
      auto ts = time_span::zero;
      assert::is_true(time_span::try_parse("6", ts), csf_);
      assert::are_equal("6.00:00:00", ts.to_string(), csf_);

      assert::is_true(time_span::try_parse("6:12", ts), csf_);
      assert::are_equal("06:12:00", ts.to_string(), csf_);

      assert::is_true(time_span::try_parse("6:12:14", ts), csf_);
      assert::are_equal("06:12:14", ts.to_string(), csf_);
      
      assert::is_true(time_span::try_parse("06:12:14", ts), csf_);
      assert::are_equal("06:12:14", ts.to_string(), csf_);
      
      assert::is_true(time_span::try_parse("6:12:14:45", ts), csf_);
      assert::are_equal("6.12:14:45", ts.to_string(), csf_);
      
      assert::is_true(time_span::try_parse("06.12:14:45", ts), csf_);
      assert::are_equal("6.12:14:45", ts.to_string(), csf_);
      
      assert::is_true(time_span::try_parse("6.12:14:45.3440000", ts), csf_);
      assert::are_equal("6.12:14:45.3440000", ts.to_string(), csf_);
      
      assert::is_true(time_span::try_parse("-6.12:14:45.3440000", ts), csf_);
      assert::are_equal("-6.12:14:45.3440000", ts.to_string(), csf_);

      ts = time_span::zero;

      assert::is_false(time_span::try_parse("25:12:00", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);

      assert::is_false(time_span::try_parse("6:61:00", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);
      
      assert::is_false(time_span::try_parse("6:00:61", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);
      
      assert::is_false(time_span::try_parse("6.12:14:45.344", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);
      
      assert::is_false(time_span::try_parse("6.12:14:45.344000", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);
      
      assert::is_false(time_span::try_parse("6.12:14:45.34400000", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);
      
      assert::is_false(time_span::try_parse("6.2:12:14:45.3440000", ts), csf_);
      assert::are_equal("00:00:00", ts.to_string(), csf_);      
    }
  };
}
