#include <xtd/drawing/imaging/image_flags>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::imaging;
using namespace xtd::tunit;

namespace xtd::drawing::imaging::tests {
  class test_class_(image_flags_tests) {
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(image_flags::none));
      assert::are_equal("none", enum_object<>::to_string(image_flags::none));
      assert::are_equal(image_flags::none, enum_object<>::parse<image_flags>("none"));
    }
    
    auto test_method_(scalable) {
      assert::are_equal(1, enum_object<>::to_int32(image_flags::scalable));
      assert::are_equal("scalable", enum_object<>::to_string(image_flags::scalable));
      assert::are_equal(image_flags::scalable, enum_object<>::parse<image_flags>("scalable"));
    }
    
    auto test_method_(has_alpha) {
      assert::are_equal(2, enum_object<>::to_int32(image_flags::has_alpha));
      assert::are_equal("has_alpha", enum_object<>::to_string(image_flags::has_alpha));
      assert::are_equal(image_flags::has_alpha, enum_object<>::parse<image_flags>("has_alpha"));
    }
    
    auto test_method_(has_translucent) {
      assert::are_equal(4, enum_object<>::to_int32(image_flags::has_translucent));
      assert::are_equal("has_translucent", enum_object<>::to_string(image_flags::has_translucent));
      assert::are_equal(image_flags::has_translucent, enum_object<>::parse<image_flags>("has_translucent"));
    }
    
    auto test_method_(partially_scalable) {
      assert::are_equal(8, enum_object<>::to_int32(image_flags::partially_scalable));
      assert::are_equal("partially_scalable", enum_object<>::to_string(image_flags::partially_scalable));
      assert::are_equal(image_flags::partially_scalable, enum_object<>::parse<image_flags>("partially_scalable"));
    }
    
    auto test_method_(color_space_rgb) {
      assert::are_equal(16, enum_object<>::to_int32(image_flags::color_space_rgb));
      assert::are_equal("color_space_rgb", enum_object<>::to_string(image_flags::color_space_rgb));
      assert::are_equal(image_flags::color_space_rgb, enum_object<>::parse<image_flags>("color_space_rgb"));
    }
    
    auto test_method_(color_space_cmyk) {
      assert::are_equal(32, enum_object<>::to_int32(image_flags::color_space_cmyk));
      assert::are_equal("color_space_cmyk", enum_object<>::to_string(image_flags::color_space_cmyk));
      assert::are_equal(image_flags::color_space_cmyk, enum_object<>::parse<image_flags>("color_space_cmyk"));
    }
    
    auto test_method_(color_space_gray) {
      assert::are_equal(64, enum_object<>::to_int32(image_flags::color_space_gray));
      assert::are_equal("color_space_gray", enum_object<>::to_string(image_flags::color_space_gray));
      assert::are_equal(image_flags::color_space_gray, enum_object<>::parse<image_flags>("color_space_gray"));
    }
    
    auto test_method_(color_space_ycbcr) {
      assert::are_equal(128, enum_object<>::to_int32(image_flags::color_space_ycbcr));
      assert::are_equal("color_space_ycbcr", enum_object<>::to_string(image_flags::color_space_ycbcr));
      assert::are_equal(image_flags::color_space_ycbcr, enum_object<>::parse<image_flags>("color_space_ycbcr"));
    }
    
    auto test_method_(color_space_ycck) {
      assert::are_equal(256, enum_object<>::to_int32(image_flags::color_space_ycck));
      assert::are_equal("color_space_ycck", enum_object<>::to_string(image_flags::color_space_ycck));
      assert::are_equal(image_flags::color_space_ycck, enum_object<>::parse<image_flags>("color_space_ycck"));
    }
    
    auto test_method_(has_real_dpi) {
      assert::are_equal(4096, enum_object<>::to_int32(image_flags::has_real_dpi));
      assert::are_equal("has_real_dpi", enum_object<>::to_string(image_flags::has_real_dpi));
      assert::are_equal(image_flags::has_real_dpi, enum_object<>::parse<image_flags>("has_real_dpi"));
    }
    
    auto test_method_(has_real_pixel_size) {
      assert::are_equal(8192, enum_object<>::to_int32(image_flags::has_real_pixel_size));
      assert::are_equal("has_real_pixel_size", enum_object<>::to_string(image_flags::has_real_pixel_size));
      assert::are_equal(image_flags::has_real_pixel_size, enum_object<>::parse<image_flags>("has_real_pixel_size"));
    }
    
    auto test_method_(read_only) {
      assert::are_equal(65536, enum_object<>::to_int32(image_flags::read_only));
      assert::are_equal("read_only", enum_object<>::to_string(image_flags::read_only));
      assert::are_equal(image_flags::read_only, enum_object<>::parse<image_flags>("read_only"));
    }
    
    auto test_method_(caching) {
      assert::are_equal(131072, enum_object<>::to_int32(image_flags::caching));
      assert::are_equal("caching", enum_object<>::to_string(image_flags::caching));
      assert::are_equal(image_flags::caching, enum_object<>::parse<image_flags>("caching"));
    }
  };
}
