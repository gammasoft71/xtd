#include <xtd/drawing/imaging/pixel_format>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::imaging;
using namespace xtd::tunit;

namespace xtd::drawing::imaging::tests {
  class test_class_(pixel_format_tests) {
    void test_method_(undefined) {
      assert::are_equal(0, enum_object<>::to_int32(pixel_format::undefined), csf_);
      assert::are_equal("undefined", enum_object<>::to_string(pixel_format::undefined), csf_);
      assert::are_equal(pixel_format::undefined, enum_object<>::parse<pixel_format>("undefined"), csf_);
    }
    
    void test_method_(max) {
      assert::are_equal(15, enum_object<>::to_int32(pixel_format::max), csf_);
      assert::are_equal("max", enum_object<>::to_string(pixel_format::max), csf_);
      assert::are_equal(pixel_format::max, enum_object<>::parse<pixel_format>("max"), csf_);
    }
    
    void test_method_(indexed) {
      assert::are_equal(65536, enum_object<>::to_int32(pixel_format::indexed), csf_);
      assert::are_equal("indexed", enum_object<>::to_string(pixel_format::indexed), csf_);
      assert::are_equal(pixel_format::indexed, enum_object<>::parse<pixel_format>("indexed"), csf_);
    }
    
    void test_method_(gdi) {
      assert::are_equal(131072, enum_object<>::to_int32(pixel_format::gdi), csf_);
      assert::are_equal("gdi", enum_object<>::to_string(pixel_format::gdi), csf_);
      assert::are_equal(pixel_format::gdi, enum_object<>::parse<pixel_format>("gdi"), csf_);
    }
    
    void test_method_(format_16bpp_rgb555) {
      assert::are_equal(135173, enum_object<>::to_int32(pixel_format::format_16bpp_rgb555), csf_);
      assert::are_equal("format_16bpp_rgb555", enum_object<>::to_string(pixel_format::format_16bpp_rgb555), csf_);
      assert::are_equal(pixel_format::format_16bpp_rgb555, enum_object<>::parse<pixel_format>("format_16bpp_rgb555"), csf_);
    }
    
    void test_method_(format_16bpp_rgb565) {
      assert::are_equal(135174, enum_object<>::to_int32(pixel_format::format_16bpp_rgb565), csf_);
      assert::are_equal("format_16bpp_rgb565", enum_object<>::to_string(pixel_format::format_16bpp_rgb565), csf_);
      assert::are_equal(pixel_format::format_16bpp_rgb565, enum_object<>::parse<pixel_format>("format_16bpp_rgb565"), csf_);
    }
    
    void test_method_(format_24bpp_rgb) {
      assert::are_equal(137224, enum_object<>::to_int32(pixel_format::format_24bpp_rgb), csf_);
      assert::are_equal("format_24bpp_rgb", enum_object<>::to_string(pixel_format::format_24bpp_rgb), csf_);
      assert::are_equal(pixel_format::format_24bpp_rgb, enum_object<>::parse<pixel_format>("format_24bpp_rgb"), csf_);
    }
    
    void test_method_(format_32bpp_rgb) {
      assert::are_equal(139273, enum_object<>::to_int32(pixel_format::format_32bpp_rgb), csf_);
      assert::are_equal("format_32bpp_rgb", enum_object<>::to_string(pixel_format::format_32bpp_rgb), csf_);
      assert::are_equal(pixel_format::format_32bpp_rgb, enum_object<>::parse<pixel_format>("format_32bpp_rgb"), csf_);
    }
    
    void test_method_(format_1bpp_indexed) {
      assert::are_equal(196865, enum_object<>::to_int32(pixel_format::format_1bpp_indexed), csf_);
      assert::are_equal("format_1bpp_indexed", enum_object<>::to_string(pixel_format::format_1bpp_indexed), csf_);
      assert::are_equal(pixel_format::format_1bpp_indexed, enum_object<>::parse<pixel_format>("format_1bpp_indexed"), csf_);
    }
    
    void test_method_(format_4bpp_indexed) {
      assert::are_equal(197634, enum_object<>::to_int32(pixel_format::format_4bpp_indexed), csf_);
      assert::are_equal("format_4bpp_indexed", enum_object<>::to_string(pixel_format::format_4bpp_indexed), csf_);
      assert::are_equal(pixel_format::format_4bpp_indexed, enum_object<>::parse<pixel_format>("format_4bpp_indexed"), csf_);
    }
    
    void test_method_(format_8bpp_indexed) {
      assert::are_equal(198659, enum_object<>::to_int32(pixel_format::format_8bpp_indexed), csf_);
      assert::are_equal("format_8bpp_indexed", enum_object<>::to_string(pixel_format::format_8bpp_indexed), csf_);
      assert::are_equal(pixel_format::format_8bpp_indexed, enum_object<>::parse<pixel_format>("format_8bpp_indexed"), csf_);
    }
    
    void test_method_(alpha) {
      assert::are_equal(262144, enum_object<>::to_int32(pixel_format::alpha), csf_);
      assert::are_equal("alpha", enum_object<>::to_string(pixel_format::alpha), csf_);
      assert::are_equal(pixel_format::alpha, enum_object<>::parse<pixel_format>("alpha"), csf_);
    }
    
    void test_method_(format_16bpp_argb1555) {
      assert::are_equal(397319, enum_object<>::to_int32(pixel_format::format_16bpp_argb1555), csf_);
      assert::are_equal("format_16bpp_argb1555", enum_object<>::to_string(pixel_format::format_16bpp_argb1555), csf_);
      assert::are_equal(pixel_format::format_16bpp_argb1555, enum_object<>::parse<pixel_format>("format_16bpp_argb1555"), csf_);
    }
    
    void test_method_(palpha) {
      assert::are_equal(524288, enum_object<>::to_int32(pixel_format::palpha), csf_);
      assert::are_equal("palpha", enum_object<>::to_string(pixel_format::palpha), csf_);
      assert::are_equal(pixel_format::palpha, enum_object<>::parse<pixel_format>("palpha"), csf_);
    }
    
    void test_method_(format_32bpp_pargb) {
      assert::are_equal(925707, enum_object<>::to_int32(pixel_format::format_32bpp_pargb), csf_);
      assert::are_equal("format_32bpp_pargb", enum_object<>::to_string(pixel_format::format_32bpp_pargb), csf_);
      assert::are_equal(pixel_format::format_32bpp_pargb, enum_object<>::parse<pixel_format>("format_32bpp_pargb"), csf_);
    }
    
    void test_method_(extended) {
      assert::are_equal(1048576, enum_object<>::to_int32(pixel_format::extended), csf_);
      assert::are_equal("extended", enum_object<>::to_string(pixel_format::extended), csf_);
      assert::are_equal(pixel_format::extended, enum_object<>::parse<pixel_format>("extended"), csf_);
    }
    
    void test_method_(format_16bpp_gray_scale) {
      assert::are_equal(1052676, enum_object<>::to_int32(pixel_format::format_16bpp_gray_scale), csf_);
      assert::are_equal("format_16bpp_gray_scale", enum_object<>::to_string(pixel_format::format_16bpp_gray_scale), csf_);
      assert::are_equal(pixel_format::format_16bpp_gray_scale, enum_object<>::parse<pixel_format>("format_16bpp_gray_scale"), csf_);
    }
    
    void test_method_(format_48bpp_rgb) {
      assert::are_equal(1060876, enum_object<>::to_int32(pixel_format::format_48bpp_rgb), csf_);
      assert::are_equal("format_48bpp_rgb", enum_object<>::to_string(pixel_format::format_48bpp_rgb), csf_);
      assert::are_equal(pixel_format::format_48bpp_rgb, enum_object<>::parse<pixel_format>("format_48bpp_rgb"), csf_);
    }
    
    void test_method_(format_64bpp_pargb) {
      assert::are_equal(1851406, enum_object<>::to_int32(pixel_format::format_64bpp_pargb), csf_);
      assert::are_equal("format_64bpp_pargb", enum_object<>::to_string(pixel_format::format_64bpp_pargb), csf_);
      assert::are_equal(pixel_format::format_64bpp_pargb, enum_object<>::parse<pixel_format>("format_64bpp_pargb"), csf_);
    }
    
    void test_method_(canonical) {
      assert::are_equal(2097152, enum_object<>::to_int32(pixel_format::canonical), csf_);
      assert::are_equal("canonical", enum_object<>::to_string(pixel_format::canonical), csf_);
      assert::are_equal(pixel_format::canonical, enum_object<>::parse<pixel_format>("canonical"), csf_);
    }
    
    void test_method_(format_32bpp_argb) {
      assert::are_equal(2498570, enum_object<>::to_int32(pixel_format::format_32bpp_argb), csf_);
      assert::are_equal("format_32bpp_argb", enum_object<>::to_string(pixel_format::format_32bpp_argb), csf_);
      assert::are_equal(pixel_format::format_32bpp_argb, enum_object<>::parse<pixel_format>("format_32bpp_argb"), csf_);
    }
    
    void test_method_(format_64bpp_argb) {
      assert::are_equal(3424269, enum_object<>::to_int32(pixel_format::format_64bpp_argb), csf_);
      assert::are_equal("format_64bpp_argb", enum_object<>::to_string(pixel_format::format_64bpp_argb), csf_);
      assert::are_equal(pixel_format::format_64bpp_argb, enum_object<>::parse<pixel_format>("format_64bpp_argb"), csf_);
    }
  };
}
