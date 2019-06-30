#include <xtd/drawing>
#include <xtd/tunit>

using namespace std;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_point) {
  public:
    void test_method_(create_empty_point) {
      point point;
      assert::are_equal({0, 0}, point);
      assert::are_equal(0, point.x());
      assert::are_equal(0, point.y());
    }
  };
}
