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
    
    void test_method_(create_point_with_copy) {
      point p = {1, 2};
      assert::are_equal(point(1, 2), p);
      assert::are_not_equal(point::empty, p);
      assert::are_equal(1, p.x());
      assert::are_equal(2, p.y());
    }
    
    void test_method_(create_point_and_assign_it) {
      point p;
      p = {1, 2};
      assert::are_equal(point(1, 2), p);
      assert::are_not_equal(point::empty, p);
      assert::are_equal(1, p.x());
      assert::are_equal(2, p.y());
    }
    
    void test_method_(is_empty) {
      assert::is_true(point().is_empty());
      assert::is_false(point(1, 2).is_empty());
    }
    
    void test_method_(offset_point) {
      point p(1, 2);
      p.offset({3, 4});
      assert::are_equal(point(4, 6), p);
    }
    
    void test_method_(offset_x_y) {
      point p(1, 2);
      p.offset(3, 4);
      assert::are_equal(point(4, 6), p);
    }
    
    void test_method_(set_x) {
      point p;
      p.x(3);
      assert::are_equal(point(3, 0), p);
    }
    
    void test_method_(set_y) {
      point p;
      p.y(4);
      assert::are_equal(point(0, 4), p);
    }
    
    void test_method_(set_x_y) {
      point p;
      p.x(3);
      p.y(4);
      assert::are_equal(point(3, 4), p);
    }
    
    void test_method_(to_string) {
      point p(1, 2);
      assert::are_equal("{x=1, y=2}", p.to_string());
    }
  };
}
