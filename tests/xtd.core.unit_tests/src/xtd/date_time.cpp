#include <sstream>
#include <xtd/date_time.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_date_time) {
    static std::tm make_tm(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
      std::tm date = {};
      date.tm_year = year - 1900;
      date.tm_mon = month - 1;
      date.tm_mday = day;
      date.tm_hour = hour;
      date.tm_min = minute;
      date.tm_sec = second;
      return date;
    }

  public:
    void test_method_(create_date_with_default_constructor) {
      date_time d;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(0), d.ticks(), csf_);
      //assert::are_equal("0-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_max_value) {
      date_time d = date_time::max_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(2534022971990000000LL) + ticks(621672202500000000LL), d.ticks(), csf_);
      //assert::are_equal("9999-12-31 23:59:59", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_min_value) {
      date_time d = date_time::min_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(0), d.ticks(), csf_);
      //assert::are_equal("0-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks) {
      date_time d(duration_cast<ticks>(seconds(42)));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(seconds(42)), d.ticks(), csf_);
      //assert::are_equal("0-01-01 00:00:42", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind) {
      date_time d(duration_cast<ticks>(minutes(24)), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(minutes(24)), d.ticks(), csf_);
      //assert::are_equal("0-01-01 00:24:00", d.to_string("u"), csf_);
    }

    void test_method_(create_date_now) {
      assert::are_equal(date_time_kind::unspecified, date_time::now().kind(), csf_);
      assert::is_not_zero(date_time::now().ticks().count(), csf_);
      assert::are_equal(system_clock::to_time_t(system_clock::now()), date_time::now().to_time_t(), csf_);
    }
    
    void test_method_(from_time_t) {
      struct tm tms = make_tm(1971, 1, 5, 21, 10, 30);
      date_time d = date_time::from_time_t(std::mktime(&tms));
      assert::are_equal(std::mktime(&tms), d.to_time_t(), csf_);
    }

  };
}
