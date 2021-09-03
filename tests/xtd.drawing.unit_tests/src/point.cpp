#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_point) {
  public:
    void test_method_(create_empty_point) {
      point p;
      assert::are_equal(point(0, 0), p, csf_);
      assert::are_equal(point::empty, p, csf_);
      assert::are_equal(0, p.x(), csf_);
      assert::are_equal(0, p.y(), csf_);
    }
    
    void test_method_(create_point_from_pair_of_integer) {
      point p(1, 2);
      assert::are_equal(point(1, 2), p, csf_);
      assert::are_not_equal(point::empty, p, csf_);
      assert::are_equal(1, p.x(), csf_);
      assert::are_equal(2, p.y(), csf_);
    }
    
    void test_method_(create_point_from_integer) {
      point p(0x00020001);
      assert::are_equal(point(1, 2), p, csf_);
      assert::are_not_equal(point::empty, p, csf_);
      assert::are_equal(1, p.x(), csf_);
      assert::are_equal(2, p.y(), csf_);
    }

    void test_method_(create_point_from_point) {
      point p = {1, 2};
      assert::are_equal(point(1, 2), p, csf_);
      assert::are_not_equal(point::empty, p, csf_);
      assert::are_equal(1, p.x(), csf_);
      assert::are_equal(2, p.y(), csf_);
    }

    void test_method_(create_point_from_size) {
      point p(size(1, 2));
      assert::are_equal(point(1, 2), p, csf_);
      assert::are_not_equal(point::empty, p, csf_);
      assert::are_equal(1, p.x(), csf_);
      assert::are_equal(2, p.y(), csf_);
    }

    void test_method_(create_point_and_assign_it) {
      point p;
      p = {1, 2};
      assert::are_equal(point(1, 2), p, csf_);
      assert::are_not_equal(point::empty, p, csf_);
      assert::are_equal(1, p.x(), csf_);
      assert::are_equal(2, p.y(), csf_);
    }
    
    void test_method_(is_empty) {
      assert::is_true(point().is_empty(), csf_);
      assert::is_false(point(1, 2).is_empty(), csf_);
    }
    
    void test_method_(offset_point) {
      point p(1, 2);
      p.offset({3, 4});
      assert::are_equal(point(4, 6), p, csf_);
    }
    
    void test_method_(offset_x_y) {
      point p(1, 2);
      p.offset(3, 4);
      assert::are_equal(point(4, 6), p, csf_);
    }
    
    void test_method_(set_x) {
      point p;
      p.x(3);
      assert::are_equal(point(3, 0), p, csf_);
    }
    
    void test_method_(set_y) {
      point p;
      p.y(4);
      assert::are_equal(point(0, 4), p, csf_);
    }
    
    void test_method_(set_x_y) {
      point p;
      p.x(3);
      p.y(4);
      assert::are_equal(point(3, 4), p, csf_);
    }
    
    void test_method_(add_size) {
      assert::are_equal(point(4, 6), point::add({1, 2}, size {3, 4}), csf_);
    }
    
    void test_method_(operator_plus_size) {
      assert::are_equal(point(4, 6), point(1, 2) + size(3, 4), csf_);
    }
    
    void test_method_(operator_plus_equal_size) {
      point p(1, 2);
      p += size(3, 4);
      assert::are_equal(point(4, 6), p, csf_);
    }

    void test_method_(subtract_size) {
      assert::are_equal(point(2, 3), point::subtract({3, 5}, size {1, 2}), csf_);
    }
    
    void test_method_(operator_minus_size) {
      assert::are_equal(point(2, 3), point(3, 5) - size(1, 2), csf_);
    }
    
    void test_method_(operator_minus_equal_size) {
      point p(3, 5);
      p -= size(1, 2);
      assert::are_equal(point(2, 3), p, csf_);
    }

    void test_method_(to_string) {
      point p(1, 2);
      assert::are_equal("{x=1, y=2}", p.to_string(), csf_);
    }
  };
}
