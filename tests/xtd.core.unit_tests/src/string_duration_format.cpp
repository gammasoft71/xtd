#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::chrono_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_string_duration_format) {
  public:
    void test_method_(format_with_default_argument) {
      assert::are_equal("1.02:03:32:024000500", xtd::ustring::format("{0}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_default_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("02:03:32", xtd::ustring::format("{0}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([]{ustring::format("{0G}", 2h + 3min + 32s);});
    }
    
    void test_method_(format_with_left_alignment) {
      assert::are_equal("  02:03:32", ustring::format("{0,10}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal("  02:03:32", ustring::format("{0,+10}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_right_alignment) {
      assert::are_equal("02:03:32  ", ustring::format("{0, -10}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_left_alignment_to_zero) {
      assert::are_equal("02:03:32", ustring::format("{0,0}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_right_alignment_to_zero) {
      assert::are_equal("02:03:32", ustring::format("{0,-0}", 2h + 3min + 32s), csf_);
    }
 
    void test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([]{ustring::format("{0,a}",2h + 3min + 32s);}, csf_);
    }

    void test_method_(format_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format("{0:e}", 2h + 3min + 32s);}, csf_);
    }

    void test_method_(format_with_constant_argument) {
      assert::are_equal("1.02:03:32:024000500", xtd::ustring::format("{0:c}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_constant_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("02:03:32", xtd::ustring::format("{0:c}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_days_argument) {
      assert::are_equal("1", xtd::ustring::format("{0:d}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_alternative_days_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("0", xtd::ustring::format("{0:d}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_days_argument) {
      assert::are_equal("01", xtd::ustring::format("{0:D}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_days_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("00", xtd::ustring::format("{0:D}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_full_argument) {
#if !_WIN32 /// @todo Debug in Windows 32 bits...
      assert::are_equal("1:2:03:32:024000500", xtd::ustring::format("{0:f}", 26h + 3min + 32s + 24ms + 500ns), csf_);
#endif
    }
    
    void test_method_(format_with_alternative_full_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("0:2:03:32:000000000", xtd::ustring::format("{0:f}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_full_argument) {
#if !_WIN32 /// @todo Debug in Windows 32 bits...
      assert::are_equal("1:02:03:32:024000500", xtd::ustring::format("{0:F}", 26h + 3min + 32s + 24ms + 500ns), csf_);
#endif
    }
    
    void test_method_(format_with_full_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("0:02:03:32:000000000", xtd::ustring::format("{0:F}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_genaral_argument) {
      assert::are_equal("1.2:03:32:024000500", xtd::ustring::format("{0:g}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_alternative_general_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("2:03:32", xtd::ustring::format("{0:g}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_genaral_argument) {
      assert::are_equal("1.02:03:32:024000500", xtd::ustring::format("{0:G}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_general_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("02:03:32", xtd::ustring::format("{0:G}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_hours_argument) {
      assert::are_equal("2", xtd::ustring::format("{0:h}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_alternative_hours_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("2", xtd::ustring::format("{0:h}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_hours_argument) {
      assert::are_equal("02", xtd::ustring::format("{0:H}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_hours_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("02", xtd::ustring::format("{0:H}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_minutes_argument) {
      assert::are_equal("3", xtd::ustring::format("{0:m}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_alternative_minutes_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("3", xtd::ustring::format("{0:m}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_minutes_argument) {
      assert::are_equal("03", xtd::ustring::format("{0:M}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_minutes_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("03", xtd::ustring::format("{0:M}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_nanoseconds_argument) {
      assert::are_equal("24000500", xtd::ustring::format("{0:n}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_alternative_nanoseconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("0", xtd::ustring::format("{0:n}", 2h + 3min + 32s), csf_);
    }
    
    void test_method_(format_with_nanoseconds_argument) {
      assert::are_equal("024000500", xtd::ustring::format("{0:N}", 26h + 3min + 32s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_nanoseconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("000000000", xtd::ustring::format("{0:N}", 2h + 3min + 32s), csf_);
    }

    void test_method_(format_with_alternative_seconds_argument) {
      assert::are_equal("2", xtd::ustring::format("{0:s}", 26h + 3min + 2s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_alternative_seconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("2", xtd::ustring::format("{0:s}", 2h + 3min + 2s), csf_);
    }
    
    void test_method_(format_with_seconds_argument) {
      assert::are_equal("02", xtd::ustring::format("{0:S}", 26h + 3min + 2s + 24ms + 500ns), csf_);
    }
    
    void test_method_(format_with_seconds_argument_without_days_milliseconds_and_nanoseconds) {
      assert::are_equal("02", xtd::ustring::format("{0:S}", 2h + 3min + 2s), csf_);
    }
  };
}
