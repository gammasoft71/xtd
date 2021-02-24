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
      assert::are_equal_(0, t.count());
    }

    void test_method_(create_ticks_1000) {
      ticks t(1000);
      assert::are_equal_(1000, t.count());
    }

    void test_method_(cast_ticks_to_nanoseconds) {
      ticks t(42);
      assert::are_equal_(4200ns, duration_cast<nanoseconds>(t));
    }

    void test_method_(cast_ticks_to_milliseconds) {
      ticks t(423567);
      assert::are_equal_(42ms, duration_cast<milliseconds>(t));
    }
  };
}
