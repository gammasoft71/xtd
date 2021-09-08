#include <xtd/ticks.h>
#include <xtd/xtd.tunit>

using namespace std::chrono;
using namespace std::literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {  
  class test_class_(test_ticks) {
  public:
    void test_method_(create_ticks_0) {
      ticks t(0);
      assert::are_equal(0, t.count(), csf_);
    }

    void test_method_(create_ticks_1000) {
      ticks t(1000);
      assert::are_equal(1000, t.count(), csf_);
    }

    void test_method_(cast_ticks_to_nanoseconds) {
      ticks t(42);
      assert::are_equal(4200ns, duration_cast<nanoseconds>(t), csf_);
    }

    void test_method_(cast_ticks_to_milliseconds) {
      ticks t(423567);
      assert::are_equal(42ms, duration_cast<milliseconds>(t), csf_);
    }
  };
}
