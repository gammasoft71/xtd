#include <xtd/forms/style_sheets/image_value.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_image_data) {
  public:
    void test_method_(create_with_default_constructor) {
      image_value i;
      assert::are_equal(image_type::none, i.image_type(), csf_);
      assert::is_empty(i.url(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::black, color::black}, i.colors(), csf_);
      assert::are_equal(180, i.angle(), csf_);
    }

    void test_method_(create_with_specified_url) {
      image_value i("arrow.png");
      assert::are_equal(image_type::url, i.image_type(), csf_);
      assert::are_equal("arrow.png", i.url(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::black, color::black}, i.colors(), csf_);
      assert::are_equal(180, i.angle(), csf_);
    }
    
    void test_method_(create_with_specified_colors) {
      image_value i({color::blue, color::white});
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::is_empty(i.url(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
      assert::are_equal(180, i.angle(), csf_);
    }
    
    void test_method_(create_with_specified_image_type_linear_gradient_and_colors) {
      image_value i(image_type::linear_gradient, {color::blue, color::white});
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::is_empty(i.url(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
      assert::are_equal(180, i.angle(), csf_);
    }

    void test_method_(create_with_specified_image_type_linear_gradient_and_one_color) {
      assert::throws<argument_exception>([]{image_value i(image_type::linear_gradient, {color::blue});}, csf_);
    }
    
    void test_method_(create_with_specified_image_type_radial_gradient_and_colors) {
      assert::throws<not_supported_exception>([]{image_value i(image_type::radial_gradient, {color::blue, color::white});}, csf_);
    }
    
    void test_method_(create_with_specified_image_type_conic_gradient_and_colors) {
      assert::throws<not_supported_exception>([]{image_value i(image_type::conic_gradient, {color::blue, color::white});}, csf_);
    }
    
    void test_method_(create_with_specified_image_type_linear_gradient_colors_and_angle) {
      image_value i(image_type::linear_gradient, {color::blue, color::white}, 270);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::is_empty(i.url(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
      assert::are_equal(270, i.angle(), csf_);
    }
    
    void test_method_(create_with_specified_image_type_linear_gradient_one_color_and_angle) {
      assert::throws<argument_exception>([]{image_value i(image_type::linear_gradient, {color::blue}, 270);}, csf_);
    }
    
    void test_method_(create_with_specified_image_type_radial_gradient_colors_and_angle) {
      assert::throws<not_supported_exception>([]{image_value i(image_type::radial_gradient, {color::blue, color::white}, 270);}, csf_);
    }
    
    void test_method_(create_with_specified_image_type_conic_gradient_colors_and_angle) {
      assert::throws<not_supported_exception>([]{image_value i(image_type::conic_gradient, {color::blue, color::white}, 270);}, csf_);
    }
    
    void test_method_(try_parse_with_linear_gradient_with_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(180, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }
    
    void test_method_(try_parse_with_linear_gradient_with_to_top_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to top, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(0, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }
    
    void test_method_(try_parse_with_linear_gradient_with_to_top_right_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to top right, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(45, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }
    
    void test_method_(try_parse_with_linear_gradient_with_to_right_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to right, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(90, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_to_bottom_right_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to bottom right, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(135, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }
    
    void test_method_(try_parse_with_linear_gradient_with_to_bottom_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to bottom, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(180, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_to_bottom_left_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to bottom left, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(225, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }
    
    void test_method_(try_parse_with_linear_gradient_with_to_left_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to left, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(270, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_to_top_left_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to top left, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(315, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_angle_and_named_colors) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(126deg, blue, white)", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(126, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_rgb_color) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(rgb(42, 24, 12), rgb(84, 128, 16))", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(180, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(42, 24, 12), color::from_argb(84, 128, 16)}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_angle_rgb_color) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(24deg, rgb(42, 24, 12), rgb(84, 128, 16))", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(24, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(42, 24, 12), color::from_argb(84, 128, 16)}, i.colors(), csf_);
    }

    void test_method_(try_parse_with_linear_gradient_with_to_left_rgb_color) {
      image_value i;
      assert::is_true(image_value::try_parse("linear-gradient(to left, rgb(42, 24, 12), rgb(84, 128, 16))", i), csf_);
      assert::are_equal(image_type::linear_gradient, i.image_type(), csf_);
      assert::are_equal(270, i.angle(), csf_);
      assert::are_equal(2U, i.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(42, 24, 12), color::from_argb(84, 128, 16)}, i.colors(), csf_);
    }

    void test_method_(to_css_color_data_with_linear_gradient) {
      assert::are_equal("linear-gradient(white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}).to_css());
    }
    
    void test_method_(to_css_color_data_with_linear_gradient_and_angle_0) {
      assert::are_equal("linear-gradient(to top, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 0).to_css());
    }
    
    void test_method_(to_css_color_data_with_linear_gradient_and_angle_45) {
      assert::are_equal("linear-gradient(to top right, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 45).to_css());
    }
    
    void test_method_(to_css_color_data_with_linear_gradient_and_angle_90) {
      assert::are_equal("linear-gradient(to right, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 90).to_css());
    }
    
    void test_method_(to_css_color_data_with_linear_gradient_and_angle_135) {
      assert::are_equal("linear-gradient(to bottom right, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 135).to_css());
    }

    void test_method_(to_css_color_data_with_linear_gradient_and_angle_180) {
      assert::are_equal("linear-gradient(white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 180).to_css());
    }

    void test_method_(to_css_color_data_with_linear_gradient_and_angle_225) {
      assert::are_equal("linear-gradient(to bottom left, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 225).to_css());
    }

    void test_method_(to_css_color_data_with_linear_gradient_and_angle_270) {
      assert::are_equal("linear-gradient(to left, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 270).to_css());
    }

    void test_method_(to_css_color_data_with_linear_gradient_and_angle_315) {
      assert::are_equal("linear-gradient(to top left, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 315).to_css());
    }

    void test_method_(to_css_color_data_with_linear_gradient_and_angle_65) {
      assert::are_equal("linear-gradient(65deg, white, darkblue)", image_value(image_type::linear_gradient, {color::white, color::dark_blue}, 65).to_css());
    }
  };
}
