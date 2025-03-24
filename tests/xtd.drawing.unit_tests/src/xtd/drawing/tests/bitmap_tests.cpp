#include "../../../../properties/resources.hpp"
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include <xtd/collections/generic/list>
#include <xtd/argument_exception>
#include <xtd/environment>
//#include <xtd/print>
//#include <xtd/println>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(bitmap_tests) {
    static bitmap create_image(const drawing::size& size) {
      if (size.height < 0 || size.height > 4) throw argument_exception {};
      if (size.width < 0 || size.width > 4) throw argument_exception {};
      auto [w, h] = size;
      auto bmp = bitmap {w, h};
      
      if (w >= 1 && h >= 1) bmp.set_pixel(0, 0, color::red);
      if (w >= 2 && h >= 1) bmp.set_pixel(1, 0, color::lime);
      if (w >= 3 && h >= 1) bmp.set_pixel(2, 0, color::blue);
      if (w >= 4 && h >= 1) bmp.set_pixel(3, 0, color::white);
      if (w >= 1 && h >= 2) bmp.set_pixel(0, 1, color::aqua);
      if (w >= 2 && h >= 2) bmp.set_pixel(1, 1, color::fuchsia);
      if (w >= 3 && h >= 2) bmp.set_pixel(2, 1, color::yellow);
      if (w >= 4 && h >= 2) bmp.set_pixel(3, 1, color::silver);
      if (w >= 1 && h >= 3) bmp.set_pixel(0, 2, color::dark_red);
      if (w >= 2 && h >= 3) bmp.set_pixel(1, 2, color::green);
      if (w >= 3 && h >= 3) bmp.set_pixel(2, 2, color::navy);
      if (w >= 4 && h >= 3) bmp.set_pixel(3, 2, color::gray);
      if (w >= 1 && h >= 4) bmp.set_pixel(0, 3, color::teal);
      if (w >= 2 && h >= 4) bmp.set_pixel(1, 3, color::purple);
      if (w >= 3 && h >= 4) bmp.set_pixel(2, 3, color::olive);
      if (w >= 4 && h >= 4) bmp.set_pixel(3, 3, color::black);
      
      /*println("bitmap {} x {} : ", bmp.width(), bmp.height());
      for (auto y = 0; y < bmp.height(); ++y) {
        for (auto x = 0; x < bmp.width(); ++x)
          print("  0x{:X8}", bmp.get_pixel(x, y).to_argb());
        println();
      }*/

      return bmp;
    }

    void to_ppm(const string& filename, const bitmap& bitmap, const color& transparent_color = color::transparent) {
      auto lines = list<string> {};
      lines.add("P3");
      lines.add("# Ppm.ppm");
      lines.add(string::format("{} {}", bitmap.width(), bitmap.height()));
      lines.add("255");
      lines.add("");
      for (auto y = 0; y < bitmap.height(); y++) {
        for (auto x = 0; x < bitmap.width(); x++)
          if (bitmap.get_pixel(x, y).a() == 0) lines.add(string::format("{, 3} {, 3} {, 3}", transparent_color.r(), transparent_color.g(), transparent_color.b()));
          else lines.add(string::format("{, 3} {, 3} {, 3}", bitmap.get_pixel(x, y).r(), bitmap.get_pixel(x, y).g(), bitmap.get_pixel(x, y).b()));
        lines.add("");
      }
      file::write_all_lines(string(filename), lines);
    }
    
    void to_ppm(const string& filename, const color& transparent_color = color::transparent) {
      to_ppm(path::combine(path::get_directory_name(filename), string::format("{}{}", path::get_file_name_without_extension(filename), ".ppm")), bitmap(filename), transparent_color);
    }
    
    void test_method_(empty) {
      auto bmp = bitmap::empty;
      
      assert::is_zero(bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_zero(bmp.handle());
      assert::is_zero(bmp.height());
      assert::is_zero(bmp.horizontal_resolution());
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
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
      auto bmp = bitmap {create_image({3, 2})};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }
    
    void test_method_(create_from_image_and_size_greather_than_image) {
      auto bmp = bitmap {create_image({3, 2}), {4, 3}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(3, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {4., 3.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {4, 3}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(4, bmp.width());
      
      if (environment::os_version().is_linux()) {
        assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
        assert::are_equal(0xFE6B8B33, bmp.get_pixel(1, 0).to_argb());
        assert::are_equal(0xFE338B6B, bmp.get_pixel(2, 0).to_argb());
        assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(0, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(1, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(2, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(3, 1).to_argb());
        assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
        assert::are_equal(0xFE9373CB, bmp.get_pixel(1, 2).to_argb());
        assert::are_equal(0xFECB7393, bmp.get_pixel(2, 2).to_argb());
        assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
        assert::are_equal(0xFE6B8B33, bmp.get_pixel(1, 0).to_argb());
        assert::are_equal(0xFE338B6B, bmp.get_pixel(2, 0).to_argb());
        assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(0, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(1, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(2, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(3, 1).to_argb());
        assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
        assert::are_equal(0xFE9373CB, bmp.get_pixel(1, 2).to_argb());
        assert::are_equal(0xFECB7393, bmp.get_pixel(2, 2).to_argb());
        assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
        assert::are_equal(0xFE6B8B33, bmp.get_pixel(1, 0).to_argb());
        assert::are_equal(0xFE338B6B, bmp.get_pixel(2, 0).to_argb());
        assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(0, 1).to_argb());
        assert::are_equal(0xFF7F7F7F, bmp.get_pixel(1, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(2, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(3, 1).to_argb());
        assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
        assert::are_equal(0xFE9373CB, bmp.get_pixel(1, 2).to_argb());
        assert::are_equal(0xFECB7393, bmp.get_pixel(2, 2).to_argb());
        assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
      }
    }
    
    void test_method_(create_from_image_and_size_less_than_image) {
      auto bmp = bitmap {create_image({3, 2}), {2, 1}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(1, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {2., 1.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {2, 1}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(2, bmp.width());
      
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(1, 0).to_argb());
    }
    
    void test_method_(create_from_image_and_size_same_than_image) {
      auto bmp = bitmap {create_image({3, 2}), {3, 2}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_image_and_size_with_invalid_height) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image({3, 2}), {1, 0}};});
    }

    void test_method_(create_from_image_and_size_with_invalid_width) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image({3, 2}), {0, 1}};});
    }
    
    void test_method_(create_from_image_width_and_height_greather_than_image) {
      auto bmp = bitmap {create_image({3, 2}), 4, 3};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(3, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {4., 3.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {4, 3}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(4, bmp.width());
      
      if (environment::os_version().is_linux()) {
        assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
        assert::are_equal(0xFE6B8B33, bmp.get_pixel(1, 0).to_argb());
        assert::are_equal(0xFE338B6B, bmp.get_pixel(2, 0).to_argb());
        assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(0, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(1, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(2, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(3, 1).to_argb());
        assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
        assert::are_equal(0xFE9373CB, bmp.get_pixel(1, 2).to_argb());
        assert::are_equal(0xFECB7393, bmp.get_pixel(2, 2).to_argb());
        assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
        assert::are_equal(0xFE6B8B33, bmp.get_pixel(1, 0).to_argb());
        assert::are_equal(0xFE338B6B, bmp.get_pixel(2, 0).to_argb());
        assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(0, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(1, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(2, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(3, 1).to_argb());
        assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
        assert::are_equal(0xFE9373CB, bmp.get_pixel(1, 2).to_argb());
        assert::are_equal(0xFECB7393, bmp.get_pixel(2, 2).to_argb());
        assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(0xFFB8472A, bmp.get_pixel(0, 0).to_argb());
        assert::are_equal(0xFE6B8B33, bmp.get_pixel(1, 0).to_argb());
        assert::are_equal(0xFE338B6B, bmp.get_pixel(2, 0).to_argb());
        assert::are_equal(0xFF2A47B8, bmp.get_pixel(3, 0).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(0, 1).to_argb());
        assert::are_equal(0xFF7F7F7F, bmp.get_pixel(1, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(2, 1).to_argb());
        assert::are_equal(0xFE7F7F7F, bmp.get_pixel(3, 1).to_argb());
        assert::are_equal(0xFF47B8D4, bmp.get_pixel(0, 2).to_argb());
        assert::are_equal(0xFE9373CB, bmp.get_pixel(1, 2).to_argb());
        assert::are_equal(0xFECB7393, bmp.get_pixel(2, 2).to_argb());
        assert::are_equal(0xFFD4B847, bmp.get_pixel(3, 2).to_argb());
      }
    }
    
    void test_method_(create_from_image_width_and_height_less_than_image) {
      auto bmp = bitmap {create_image({3, 2}), {2, 1}};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(1, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {2., 1.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {2, 1}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(2, bmp.width());
      
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(0, 0).to_argb());
      assert::are_equal(0xFF7F7F7F, bmp.get_pixel(1, 0).to_argb());
    }
    
    void test_method_(create_from_image_width_and_height_same_than_image) {
      auto bmp = bitmap {create_image({3, 2}), 3, 2};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_image_width_and_invalid_height) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image({3, 2}), 1, 0};});
    }
    
    void test_method_(create_from_image_invalid_width_and_height) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {create_image({3, 2}), 0, 1};});
    }

    void test_method_(create_from_file_bmp) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.bmp")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_gif) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.gif")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("6aedbd6d-3fb5-418a-83a6-7f45229dc872")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::gif(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_exif) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.exif")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::exif(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
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
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::jpeg(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_pcx) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.pcx")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::pcx(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_png) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.png")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::png(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_pnm) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.pnm")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::pnm(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_ppm) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.ppm")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::pnm(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_tga) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.tga")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::tga(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_tiff) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.tiff")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::tiff(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_xbm) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.xbm")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::xbm(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::black, bmp.get_pixel(0, 0));
      assert::are_equal(color::white, bmp.get_pixel(1, 0));
      assert::are_equal(color::black, bmp.get_pixel(2, 0));
      assert::are_equal(color::white, bmp.get_pixel(0, 1));
      assert::are_equal(color::black, bmp.get_pixel(1, 1));
      assert::are_equal(color::white, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_file_xpm) {
      auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.xpm")};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      //assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::are_equivalent({color::red, color::lime, color::blue, color::white, color::aqua, color::fuchsia, color::yellow, color::silver, color::maroon, color::green, color::navy, color::gray, color::teal, color::purple, color::olive, color::black}, bmp.palette().entries());
      assert::are_equal(1, bmp.palette().flags());
      assert::are_equal(size_f {3., 2.}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::xpm(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      //assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
      assert::are_equal(3, bmp.width());
      
      assert::are_equal(color::red, bmp.get_pixel(0, 0));
      assert::are_equal(color::lime, bmp.get_pixel(1, 0));
      assert::are_equal(color::blue, bmp.get_pixel(2, 0));
      assert::are_equal(color::aqua, bmp.get_pixel(0, 1));
      assert::are_equal(color::fuchsia, bmp.get_pixel(1, 1));
      assert::are_equal(color::yellow, bmp.get_pixel(2, 1));
    }

    void test_method_(create_from_unsupported_format_file) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_3_2.xcf")};});
    }
    
    void test_method_(create_from_non_existent_file) {
      assert::throws<argument_exception>([] {auto bmp = bitmap {path::combine(environment::get_folder_path(environment::special_folder::application_resources), "bitmap_not_existent_file.any")};});
    }

    void test_method_(create_with_with_and_heght) {
      auto bmp = bitmap {3, 2};
      
      assert::are_equal(2, bmp.flags());
      collection_assert::are_equal({guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483")}, bmp.frame_dimentions_list());
      assert::is_not_zero(bmp.handle());
      assert::are_equal(2, bmp.height());
      assert::are_equal(96.0f, bmp.horizontal_resolution(), 1.0f);
      collection_assert::is_empty(bmp.palette().entries());
      assert::is_zero(bmp.palette().flags());
      assert::are_equal(size_f {3, 2}, bmp.physical_dimension());
      assert::are_equal(imaging::pixel_format::format_32bpp_argb, bmp.pixel_format());
      collection_assert::is_empty(bmp.property_id_list());
      collection_assert::is_empty(bmp.property_items());
      assert::are_equal(imaging::image_format::memory_bmp(), bmp.raw_format());
      assert::are_equal(size {3, 2}, bmp.size());
      assert::is_false(bmp.tag().has_value());
      assert::are_equal(96.0f, bmp.vertical_resolution(), 1.0f);
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
  };
}
