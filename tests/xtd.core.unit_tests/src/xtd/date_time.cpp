#include <sstream>
#include <xtd/date_time.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_date_time) {
  public:
    void test_method_(create_date_with_default_constructor) {
      date_time d;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(0), d.ticks(), csf_);
      assert::are_equal("0-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_max_value) {
      date_time d = date_time::max_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(2534022971990000000LL) + ticks(621672202500000000LL), d.ticks(), csf_);
      assert::are_equal("9999-12-31 23:59:59", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_min_value) {
      date_time d = date_time::min_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(0), d.ticks(), csf_);
      assert::are_equal("0-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_from_ticks) {
      date_time d(duration_cast<ticks>(seconds(42)));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(seconds(42)), d.ticks(), csf_);
      assert::are_equal("0-01-01 00:00:42", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_now) {
      assert::are_equal(date_time_kind::unspecified, date_time::now().kind(), csf_);
      assert::is_not_zero(date_time::now().ticks().count(), csf_);
      assert::are_equal(system_clock::to_time_t(system_clock::now()), date_time::now().to_time_t(), csf_);
    }

  };
}
