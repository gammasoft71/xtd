#include <xtd/drawing/size.h>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_size) {
  public:
    void test_method_(create_empty_size) {
      size s;
      assert::are_equal(size(0, 0), s, csf_);
      assert::are_equal(size::empty, s, csf_);
      assert::are_equal(0, s.width(), csf_);
      assert::are_equal(0, s.height(), csf_);
    }
    
    void test_method_(create_size_with_values) {
      size s(1, 2);
      assert::are_equal(size(1, 2), s, csf_);
      assert::are_not_equal(size::empty, s, csf_);
      assert::are_equal(1, s.width(), csf_);
      assert::are_equal(2, s.height(), csf_);
    }
    
    void test_method_(create_size_with_copy) {
      size s = {1, 2};
      assert::are_equal(size(1, 2), s, csf_);
      assert::are_not_equal(size::empty, s, csf_);
      assert::are_equal(1, s.width(), csf_);
      assert::are_equal(2, s.height(), csf_);
    }
    
    void test_method_(create_size_and_assign_it) {
      size s;
      s = {1, 2};
      assert::are_equal(size(1, 2), s, csf_);
      assert::are_not_equal(size::empty, s, csf_);
      assert::are_equal(1, s.width(), csf_);
      assert::are_equal(2, s.height(), csf_);
    }
    
    void test_method_(is_empty) {
      assert::is_true(size().is_empty(), csf_);
      assert::is_false(size(1, 2).is_empty(), csf_);
    }
    
    void test_method_(set_width) {
      size s;
      s.width(3);
      assert::are_equal(size(3, 0), s, csf_);
    }
    
    void test_method_(set_height) {
      size s;
      s.height(4);
      assert::are_equal(size(0, 4), s, csf_);
    }
    
    void test_method_(set_width_height) {
      size s;
      s.width(3);
      s.height(4);
      assert::are_equal(size(3, 4), s, csf_);
    }
    
    void test_method_(to_string) {
      size s(1, 2);
      assert::are_equal("{width=1, height=2}", s.to_string(), csf_);
    }
  };
}
