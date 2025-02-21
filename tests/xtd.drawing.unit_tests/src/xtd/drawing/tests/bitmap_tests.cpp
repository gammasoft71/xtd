#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include <xtd/argument_exception>
#include <xtd/environment>
//#include <xtd/print>
//#include <xtd/println>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(bitmap_tests) {
    static bitmap create_image() {
      auto bmp = bitmap {3, 2};
      bmp.set_pixel(0, 0, color::red);
      bmp.set_pixel(1, 0, color::lime);
      bmp.set_pixel(2, 0, color::blue);
      bmp.set_pixel(0, 1, color::aqua);
      bmp.set_pixel(1, 1, color::fuchsia);
      bmp.set_pixel(2, 1, color::yellow);
      
      /*for (auto y = 0; y < bmp.height(); ++y) {
        for (auto x = 0; x < bmp.width(); ++x)
          print("0x{:X8}  ", bmp.get_pixel(x, y).to_argb());
        println();
      }*/
      
      return bmp;
    }
    
    void test_method_(empty) {
      auto bmp = bitmap::empty;
      
      assert::is_zero(bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_zero(bmp.handle());
      assert::is_zero(bmp.height());
      assert::is_zero(bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {.0, .0}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::undefined, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format {}, bmp.raw_format());
      assert::are_equal(size {0, 0}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::is_zero(bmp.vertical_resolution());
      assert::is_zero(bmp.width());
    }
    
    void test_method_(create_from_image) {
      auto bmp = bitmap {create_image()};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }
    
    void test_method_(create_from_image_and_size_greather_than_image) {
      auto bmp = bitmap {create_image(), {4, 3}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(3, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {4., 3.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {4, 3}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(4, bmp.width());
      
      assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFE6B8C33, bmp.get_pixel(1, 0).to_argb());
      assert::are_equal(0xFE338C6B, bmp.get_pixel(2, 0).to_argb());
      assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(0, 1).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(1, 1).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(2, 1).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(3, 1).to_argb());
      assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
      assert::are_equal(0xFE9473CC, bmp.get_pixel(1, 2).to_argb());
      assert::are_equal(0xFECC7394, bmp.get_pixel(2, 2).to_argb());
      assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
    }
    
    void test_method_(create_from_image_and_size_less_than_image) {
      auto bmp = bitmap {create_image(), {2, 1}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(1, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {2., 1.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {2, 1}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(2, bmp.width());
      
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(1, 0).to_argb());
    }
    
    void test_method_(create_from_image_and_size_same_than_image) {
      auto bmp = bitmap {create_image(), {3, 2}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_image_and_size_with_invalid_height) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image(), {1, 0}};});
    }

    void test_method_(create_from_image_and_size_with_invalid_width) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image(), {0, 1}};});
    }
    
    void test_method_(create_from_image_width_and_height_greather_than_image) {
      auto bmp = bitmap {create_image(), 4, 3};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(3, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {4., 3.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {4, 3}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(4, bmp.width());
      
      assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFE6B8C33, bmp.get_pixel(1, 0).to_argb());
      assert::are_equal(0xFE338C6B, bmp.get_pixel(2, 0).to_argb());
      assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(0, 1).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(1, 1).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(2, 1).to_argb());
      assert::are_equal(0xFE808080, bmp.get_pixel(3, 1).to_argb());
      assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
      assert::are_equal(0xFE9473CC, bmp.get_pixel(1, 2).to_argb());
      assert::are_equal(0xFECC7394, bmp.get_pixel(2, 2).to_argb());
      assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
    }
    
    void test_method_(create_from_image_width_and_height_less_than_image) {
      auto bmp = bitmap {create_image(), {2, 1}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(1, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {2., 1.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {2, 1}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(2, bmp.width());
      
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(1, 0).to_argb());
    }
    
    void test_method_(create_from_image_width_and_height_same_than_image) {
      auto bmp = bitmap {create_image(), 3, 2};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_image_width_and_invalid_height) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image(), 1, 0};});
    }
    
    void test_method_(create_from_image_invalid_width_and_height) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image(), 0, 1};});
    }

    void test_method_(create_with_with_and_heght) {
      auto bmp = bitmap {3, 2};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3, 2}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution());
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::transparent, bmp.get_pixel(0, 0));
      assert::are_equal(color::transparent, bmp.get_pixel(1, 0));
      assert::are_equal(color::transparent, bmp.get_pixel(2, 0));
      assert::are_equal(color::transparent, bmp.get_pixel(0, 1));
      assert::are_equal(color::transparent, bmp.get_pixel(1, 1));
      assert::are_equal(color::transparent, bmp.get_pixel(2, 1));
    }

    void test_method_(create_with_invalid_width_and_heght) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {0, 200};});
    }
    
    void test_method_(create_with_with_and_invalid_heght) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {320, 0};});
    }

    void test_method_(create_with_invalid_width_and_ivalid_heght) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {0, 0};});
    }

    void test_method_(create_from_file_bmp) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.bmp")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(72.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(72.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_jpg) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.jpg")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(72.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::jpeg(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(72.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(0xFFF3060C, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFF00FB00, bmp.get_pixel(1, 0).to_argb());
      assert::are_equal(0xFF0800F3, bmp.get_pixel(2, 0).to_argb());
      assert::are_equal(0xFF00FCF8, bmp.get_pixel(0, 1).to_argb());
      assert::are_equal(0xFFFF05FF, bmp.get_pixel(1, 1).to_argb());
      assert::are_equal(0xFFFFFB0C, bmp.get_pixel(2, 1).to_argb());
    }

    void test_method_(create_from_file_png) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.png")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(72.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::png(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(72.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }
  };
}
