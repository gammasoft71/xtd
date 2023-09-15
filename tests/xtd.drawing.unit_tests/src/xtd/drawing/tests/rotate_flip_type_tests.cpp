#include <xtd/drawing/rotate_flip_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(rotate_flip_type_tests) {
  public:
    void test_method_(rotate_none_flip_none) {
      assert::are_equal(0, enum_object<>::to_int32(rotate_flip_type::rotate_none_flip_none), csf_);
      assert::are_equal("rotate_none_flip_none", enum_object<>::to_string(rotate_flip_type::rotate_none_flip_none), csf_);
      assert::are_equal(rotate_flip_type::rotate_none_flip_none, enum_object<>::parse<rotate_flip_type>("rotate_none_flip_none"), csf_);
    }
    
    void test_method_(rotate_90_flip_none) {
      assert::are_equal(1, enum_object<>::to_int32(rotate_flip_type::rotate_90_flip_none), csf_);
      assert::are_equal("rotate_90_flip_none", enum_object<>::to_string(rotate_flip_type::rotate_90_flip_none), csf_);
      assert::are_equal(rotate_flip_type::rotate_90_flip_none, enum_object<>::parse<rotate_flip_type>("rotate_90_flip_none"), csf_);
    }
    
    void test_method_(rotate_180_flip_none) {
      assert::are_equal(2, enum_object<>::to_int32(rotate_flip_type::rotate_180_flip_none), csf_);
      assert::are_equal("rotate_180_flip_none", enum_object<>::to_string(rotate_flip_type::rotate_180_flip_none), csf_);
      assert::are_equal(rotate_flip_type::rotate_180_flip_none, enum_object<>::parse<rotate_flip_type>("rotate_180_flip_none"), csf_);
    }
    
    void test_method_(rotate_270_flip_none) {
      assert::are_equal(3, enum_object<>::to_int32(rotate_flip_type::rotate_270_flip_none), csf_);
      assert::are_equal("rotate_270_flip_none", enum_object<>::to_string(rotate_flip_type::rotate_270_flip_none), csf_);
      assert::are_equal(rotate_flip_type::rotate_270_flip_none, enum_object<>::parse<rotate_flip_type>("rotate_270_flip_none"), csf_);
    }
    
    void test_method_(rotate_none_flip_x) {
      assert::are_equal(4, enum_object<>::to_int32(rotate_flip_type::rotate_none_flip_x), csf_);
      assert::are_equal("rotate_none_flip_x", enum_object<>::to_string(rotate_flip_type::rotate_none_flip_x), csf_);
      assert::are_equal(rotate_flip_type::rotate_none_flip_x, enum_object<>::parse<rotate_flip_type>("rotate_none_flip_x"), csf_);
    }
    
    void test_method_(rotate_90_flip_x) {
      assert::are_equal(5, enum_object<>::to_int32(rotate_flip_type::rotate_90_flip_x), csf_);
      assert::are_equal("rotate_90_flip_x", enum_object<>::to_string(rotate_flip_type::rotate_90_flip_x), csf_);
      assert::are_equal(rotate_flip_type::rotate_90_flip_x, enum_object<>::parse<rotate_flip_type>("rotate_90_flip_x"), csf_);
    }
    
    void test_method_(rotate_180_flip_x) {
      assert::are_equal(6, enum_object<>::to_int32(rotate_flip_type::rotate_180_flip_x), csf_);
      assert::are_equal("rotate_180_flip_x", enum_object<>::to_string(rotate_flip_type::rotate_180_flip_x), csf_);
      assert::are_equal(rotate_flip_type::rotate_180_flip_x, enum_object<>::parse<rotate_flip_type>("rotate_180_flip_x"), csf_);
    }
    
    void test_method_(rotate_270_flip_x) {
      assert::are_equal(7, enum_object<>::to_int32(rotate_flip_type::rotate_270_flip_x), csf_);
      assert::are_equal("rotate_270_flip_x", enum_object<>::to_string(rotate_flip_type::rotate_270_flip_x), csf_);
      assert::are_equal(rotate_flip_type::rotate_270_flip_x, enum_object<>::parse<rotate_flip_type>("rotate_270_flip_x"), csf_);
    }
  };
}
