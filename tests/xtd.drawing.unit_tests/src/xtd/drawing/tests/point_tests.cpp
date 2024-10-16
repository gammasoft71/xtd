#include <xtd/drawing/point>
#include <xtd/drawing/size>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(point_tests) {
    void test_method_(create_empty_point) {
      point p;
      assert::are_equal(point(0, 0), p);
      assert::are_equal(point::empty, p);
      assert::are_equal(0, p.x());
      assert::are_equal(0, p.y());
    }
    
    void test_method_(create_point_from_pair_of_integer) {
      point p(1, 2);
      assert::are_equal(point(1, 2), p);
      assert::are_not_equal(point::empty, p);
      assert::are_equal(1, p.x());
      assert::are_equal(2, p.y());
    }
    
    void test_method_(create_point_from_integer) {
      point p(0x00020001);
      assert::are_equal(point(1, 2), p);
      assert::are_not_equal(point::empty, p);
      assert::are_equal(1, p.x());
      assert::are_equal(2, p.y());
    }
    
    void test_method_(create_point_from_point) {
      point p = {1, 2};
      assert::are_equal(point(1, 2), p);
      assert::are_not_equal(point::empty, p);
      assert::are_equal(1, p.x());
      assert::are_equal(2, p.y());
    }
    
    void test_method_(create_point_from_size) {
      point p(size(1, 2));
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
    
    void test_method_(add_size) {
      assert::are_equal(point(4, 6), point::add({1, 2}, size {3, 4}));
    }
    
    void test_method_(operator_plus_size) {
      assert::are_equal(point(4, 6), point(1, 2) + size(3, 4));
    }
    
    void test_method_(operator_plus_equal_size) {
      point p(1, 2);
      p += size(3, 4);
      assert::are_equal(point(4, 6), p);
    }
    
    void test_method_(subtract_size) {
      assert::are_equal(point(2, 3), point::subtract({3, 5}, size {1, 2}));
    }
    
    void test_method_(operator_minus_size) {
      assert::are_equal(point(2, 3), point(3, 5) - size(1, 2));
    }
    
    void test_method_(operator_minus_equal_size) {
      point p(3, 5);
      p -= size(1, 2);
      assert::are_equal(point(2, 3), p);
    }
    
    void test_method_(to_string) {
      point p(1, 2);
      assert::are_equal("{x=1, y=2}", p.to_string());
    }
  };
}
