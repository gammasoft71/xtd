#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(format_wstring_duration_tests) {
    auto test_method_(format_with_default_argument) {
      assert::are_equal(L"1.02:03:32:024000500", format(L"{0}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_default_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"02:03:32", format(L"{0}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([] {string::format(L"{0G}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32});});
    }
    
    auto test_method_(format_with_left_alignment) {
      assert::are_equal(L"  02:03:32", string::format(L"{0,10}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal(L"  02:03:32", string::format(L"{0,+10}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_right_alignment) {
      assert::are_equal(L"02:03:32  ", string::format(L"{0, -10}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_left_alignment_to_zero) {
      assert::are_equal(L"02:03:32", string::format(L"{0,0}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_right_alignment_to_zero) {
      assert::are_equal(L"02:03:32", string::format(L"{0,-0}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([] {string::format(L"{0,a}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32});});
    }
    
    auto test_method_(format_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format(L"{0:e}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32});});
    }
    
    auto test_method_(format_with_constant_argument) {
      assert::are_equal(L"1.02:03:32:024000500", format(L"{0:c}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_constant_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"02:03:32", format(L"{0:c}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_days_argument) {
      assert::are_equal(L"1", format(L"{0:d}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_days_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"0", format(L"{0:d}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_days_argument) {
      assert::are_equal(L"01", format(L"{0:D}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_days_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"00", format(L"{0:D}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_full_argument) {
      #if !_WIN32 /// @todo Debug in Windows 32 bits...
      assert::are_equal(L"1.2:03:32:024000500", format(L"{0:f}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
      #endif
    }
    
    auto test_method_(format_with_alternative_full_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"0.2:03:32:000000000", format(L"{0:f}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_full_argument) {
      #if !_WIN32 /// @todo Debug in Windows 32 bits...
      assert::are_equal(L"1.02:03:32:024000500", format(L"{0:F}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
      #endif
    }
    
    auto test_method_(format_with_full_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"0.02:03:32:000000000", format(L"{0:F}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_genaral_argument) {
      assert::are_equal(L"1.2:03:32:024000500", format(L"{0:g}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_general_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"2:03:32", format(L"{0:g}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_genaral_argument) {
      assert::are_equal(L"1.02:03:32:024000500", format(L"{0:G}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_general_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"02:03:32", format(L"{0:G}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_hours_argument) {
      assert::are_equal(L"2", format(L"{0:h}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_hours_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"2", format(L"{0:h}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_hours_argument) {
      assert::are_equal(L"02", format(L"{0:H}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_hours_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"02", format(L"{0:H}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_minutes_argument) {
      assert::are_equal(L"3", format(L"{0:m}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_minutes_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"3", format(L"{0:m}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_minutes_argument) {
      assert::are_equal(L"03", format(L"{0:M}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_minutes_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"03", format(L"{0:M}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_nanoseconds_argument) {
      assert::are_equal(L"24000500", format(L"{0:n}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_nanoseconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"0", format(L"{0:n}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_nanoseconds_argument) {
      assert::are_equal(L"024000500", format(L"{0:N}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_nanoseconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"000000000", format(L"{0:N}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_alternative_seconds_argument) {
      assert::are_equal(L"2", format(L"{0:s}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {2} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_seconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"2", format(L"{0:s}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {2}));
    }
    
    auto test_method_(format_with_seconds_argument) {
      assert::are_equal(L"02", format(L"{0:S}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {2} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_seconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"02", format(L"{0:S}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {2}));
    }
    
    auto test_method_(format_with_alternative_ticks_argument) {
      assert::are_equal(L"240005", format(L"{0:t}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_alternative_ticks_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"0", format(L"{0:t}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
    
    auto test_method_(format_with_ticks_argument) {
      assert::are_equal(L"0240005", format(L"{0:T}", std::chrono::hours {26} + std::chrono::minutes {3} + std::chrono::seconds {32} + std::chrono::milliseconds {24} + std::chrono::nanoseconds {500}));
    }
    
    auto test_method_(format_with_ticks_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal(L"0000000", format(L"{0:T}", std::chrono::hours {2} + std::chrono::minutes {3} + std::chrono::seconds {32}));
    }
  };
}
