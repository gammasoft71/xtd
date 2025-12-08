#include <xtd/drawing/copy_pixel_operation>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(copy_pixel_operation_tests) {
    auto test_method_(blackness) {
      assert::are_equal(66, enum_object<>::to_int32(copy_pixel_operation::blackness));
      assert::are_equal("blackness", enum_object<>::to_string(copy_pixel_operation::blackness));
      assert::are_equal(copy_pixel_operation::blackness, enum_object<>::parse<copy_pixel_operation>("blackness"));
    }
    
    auto test_method_(capture_blt) {
      assert::are_equal(1073741824, enum_object<>::to_int32(copy_pixel_operation::capture_blt));
      assert::are_equal("capture_blt", enum_object<>::to_string(copy_pixel_operation::capture_blt));
      assert::are_equal(copy_pixel_operation::capture_blt, enum_object<>::parse<copy_pixel_operation>("capture_blt"));
    }
    
    auto test_method_(destination_invert) {
      assert::are_equal(5570569, enum_object<>::to_int32(copy_pixel_operation::destination_invert));
      assert::are_equal("destination_invert", enum_object<>::to_string(copy_pixel_operation::destination_invert));
      assert::are_equal(copy_pixel_operation::destination_invert, enum_object<>::parse<copy_pixel_operation>("destination_invert"));
    }
    
    auto test_method_(merge_copy) {
      assert::are_equal(12583114, enum_object<>::to_int32(copy_pixel_operation::merge_copy));
      assert::are_equal("merge_copy", enum_object<>::to_string(copy_pixel_operation::merge_copy));
      assert::are_equal(copy_pixel_operation::merge_copy, enum_object<>::parse<copy_pixel_operation>("merge_copy"));
    }
    
    auto test_method_(merge_paint) {
      assert::are_equal(12255782, enum_object<>::to_int32(copy_pixel_operation::merge_paint));
      assert::are_equal("merge_paint", enum_object<>::to_string(copy_pixel_operation::merge_paint));
      assert::are_equal(copy_pixel_operation::merge_paint, enum_object<>::parse<copy_pixel_operation>("merge_paint"));
    }
    
    auto test_method_(no_mirror_bitmap) {
      assert::are_equal(-2147483648, enum_object<>::to_int32(copy_pixel_operation::no_mirror_bitmap));
      assert::are_equal("no_mirror_bitmap", enum_object<>::to_string(copy_pixel_operation::no_mirror_bitmap));
      assert::are_equal(copy_pixel_operation::no_mirror_bitmap, enum_object<>::parse<copy_pixel_operation>("no_mirror_bitmap"));
    }
    
    auto test_method_(not_source_copy) {
      assert::are_equal(3342344, enum_object<>::to_int32(copy_pixel_operation::not_source_copy));
      assert::are_equal("not_source_copy", enum_object<>::to_string(copy_pixel_operation::not_source_copy));
      assert::are_equal(copy_pixel_operation::not_source_copy, enum_object<>::parse<copy_pixel_operation>("not_source_copy"));
    }
    
    auto test_method_(not_source_erase) {
      assert::are_equal(1114278, enum_object<>::to_int32(copy_pixel_operation::not_source_erase));
      assert::are_equal("not_source_erase", enum_object<>::to_string(copy_pixel_operation::not_source_erase));
      assert::are_equal(copy_pixel_operation::not_source_erase, enum_object<>::parse<copy_pixel_operation>("not_source_erase"));
    }
    
    auto test_method_(pat_copy) {
      assert::are_equal(15728673, enum_object<>::to_int32(copy_pixel_operation::pat_copy));
      assert::are_equal("pat_copy", enum_object<>::to_string(copy_pixel_operation::pat_copy));
      assert::are_equal(copy_pixel_operation::pat_copy, enum_object<>::parse<copy_pixel_operation>("pat_copy"));
    }
    
    auto test_method_(pat_invert) {
      assert::are_equal(5898313, enum_object<>::to_int32(copy_pixel_operation::pat_invert));
      assert::are_equal("pat_invert", enum_object<>::to_string(copy_pixel_operation::pat_invert));
      assert::are_equal(copy_pixel_operation::pat_invert, enum_object<>::parse<copy_pixel_operation>("pat_invert"));
    }
    
    auto test_method_(pat_paint) {
      assert::are_equal(16452105, enum_object<>::to_int32(copy_pixel_operation::pat_paint));
      assert::are_equal("pat_paint", enum_object<>::to_string(copy_pixel_operation::pat_paint));
      assert::are_equal(copy_pixel_operation::pat_paint, enum_object<>::parse<copy_pixel_operation>("pat_paint"));
    }
    
    auto test_method_(source_and) {
      assert::are_equal(8913094, enum_object<>::to_int32(copy_pixel_operation::source_and));
      assert::are_equal("source_and", enum_object<>::to_string(copy_pixel_operation::source_and));
      assert::are_equal(copy_pixel_operation::source_and, enum_object<>::parse<copy_pixel_operation>("source_and"));
    }
    
    auto test_method_(source_copy) {
      assert::are_equal(13369376, enum_object<>::to_int32(copy_pixel_operation::source_copy));
      assert::are_equal("source_copy", enum_object<>::to_string(copy_pixel_operation::source_copy));
      assert::are_equal(copy_pixel_operation::source_copy, enum_object<>::parse<copy_pixel_operation>("source_copy"));
    }
    
    auto test_method_(source_erase) {
      assert::are_equal(4457256, enum_object<>::to_int32(copy_pixel_operation::source_erase));
      assert::are_equal("source_erase", enum_object<>::to_string(copy_pixel_operation::source_erase));
      assert::are_equal(copy_pixel_operation::source_erase, enum_object<>::parse<copy_pixel_operation>("source_erase"));
    }
    
    auto test_method_(source_invert) {
      assert::are_equal(6684742, enum_object<>::to_int32(copy_pixel_operation::source_invert));
      assert::are_equal("source_invert", enum_object<>::to_string(copy_pixel_operation::source_invert));
      assert::are_equal(copy_pixel_operation::source_invert, enum_object<>::parse<copy_pixel_operation>("source_invert"));
    }
    
    auto test_method_(source_paint) {
      assert::are_equal(15597702, enum_object<>::to_int32(copy_pixel_operation::source_paint));
      assert::are_equal("source_paint", enum_object<>::to_string(copy_pixel_operation::source_paint));
      assert::are_equal(copy_pixel_operation::source_paint, enum_object<>::parse<copy_pixel_operation>("source_paint"));
    }
    
    auto test_method_(whiteness) {
      assert::are_equal(16711778, enum_object<>::to_int32(copy_pixel_operation::whiteness));
      assert::are_equal("whiteness", enum_object<>::to_string(copy_pixel_operation::whiteness));
      assert::are_equal(copy_pixel_operation::whiteness, enum_object<>::parse<copy_pixel_operation>("whiteness"));
    }
  };
}
