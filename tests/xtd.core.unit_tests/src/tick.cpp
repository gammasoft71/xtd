#include <xtd/tick.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {  
  class test_class_(test_tick) {
  public:
    void test_method_(tick_denominator) {
      assert::are_equal_(10000000LL, tick::den);
    }
    
    void test_method_(tick_numerator) {
      assert::are_equal_(1LL, tick::num);
    }
  };
}
