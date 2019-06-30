#include <xtd/drawing>
#include <xtd/tunit>

using namespace std;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_point) {
  public:
    void test_method_(create_empty_point) {
      point p;
      assert::are_equal(point(0, 0), p);
      assert::are_equal(point::empty, p);
      assert::are_equal(0, p.x());
      assert::are_equal(0, p.y());
    }
    
    void test_method_(create_point_with_values) {
      point p(1, 2);
      assert::are_equal(point(1, 2), p);
      assert::are_not_equal(point::empty, p);
      assert::are_equal(1, p.x());
      assert::are_equal(2, p.y());
    }
  };
}
