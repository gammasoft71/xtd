#include <xtd/console.h>
#include <xtd/io/file.h>
#include <xtd/io/path.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_tests) {
  public:
    void test_method_(error) {
      assert::are_equal(std::cerr.rdbuf(), console::error.rdbuf(), csf_);
      assert::is_false(console::is_error_redirected(), csf_);
    }
    
    void test_method_(in) {
      assert::are_equal(std::cin.rdbuf(), console::in.rdbuf(), csf_);
      assert::is_false(console::is_input_redirected(), csf_);
    }
    
    void test_method_(out) {
      assert::are_equal(std::cout.rdbuf(), console::out.rdbuf(), csf_);
      assert::is_false(console::is_output_redirected(), csf_);
    }
    
    void test_method_(background_color) {
      auto background_color = console::background_color();
      console::background_color(console_color::blue);
      assert::are_equal(console_color::blue, console::background_color(), csf_);
      console::background_color(background_color);
      assert::are_equal(background_color, console::background_color(), csf_);
    }
    
    void test_method_(background_color_with_invalid_value) {
      assert::throws<argument_exception>([]{console::background_color(static_cast<console_color>(16));}, csf_);
    }

    void test_method_(buffer_height) {
      auto buffer_height = console::buffer_height();
      console::buffer_height(500);
      assert::are_equal(500, console::buffer_height(), csf_);
      console::buffer_height(buffer_height);
      assert::are_equal(buffer_height, console::buffer_height(), csf_);
    }
    
    void test_method_(buffer_height_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([]{console::buffer_height(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{console::buffer_height(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{console::buffer_height(int16_object::max_value);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{console::buffer_height(as<int32>(int16_object::max_value) + 1);}, csf_);
    }
    
    void test_method_(buffer_width) {
      auto buffer_width = console::buffer_width();
      console::buffer_width(500);
      assert::are_equal(500, console::buffer_width(), csf_);
      console::buffer_width(buffer_width);
      assert::are_equal(buffer_width, console::buffer_width(), csf_);
    }
    
    void test_method_(buffer_width_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([]{console::buffer_width(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{console::buffer_width(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{console::buffer_width(int16_object::max_value);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{console::buffer_width(as<int32>(int16_object::max_value) + 1);}, csf_);
    }

    void test_method_(caps_lock) {
      // Remarks if caps lock is set on by user, the folloowing test will be false.
      assert::is_false(console::caps_lock(), csf_);
    }

    void test_method_(foreground_color) {
      auto foreground_color = console::foreground_color();
      console::foreground_color(console_color::yellow);
      assert::are_equal(console_color::yellow, console::foreground_color(), csf_);
      console::foreground_color(foreground_color);
      assert::are_equal(foreground_color, console::foreground_color(), csf_);
    }
    
    void test_method_(foreground_color_with_invalid_value) {
      assert::throws<argument_exception>([]{console::foreground_color(static_cast<console_color>(16));}, csf_);
    }

    void test_method_(redirect_error) {
      auto ep = path::combine(path::get_temp_path(), "xtd_test_error.txt");
      auto es = xtd::io::file::open_write(ep);
      console::set_error(es);
      assert::are_not_equal(std::cerr.rdbuf(), console::error.rdbuf(), csf_);
      assert::is_true(console::is_error_redirected(), csf_);
      es.close();
      console::set_error(console::open_standard_error());
      assert::is_false(console::is_error_redirected(), csf_);
      file::remove(ep);
    }
    
    void test_method_(redirect_in) {
      auto ip = path::combine(path::get_temp_path(), "xtd_test_in.txt");
      file::write_all_lines(ip, {""});
      auto is = xtd::io::file::open_read(ip);
      console::set_in(is);
      assert::are_not_equal(std::cin.rdbuf(), console::in.rdbuf(), csf_);
      assert::is_true(console::is_input_redirected(), csf_);
      is.close();
      console::set_in(console::open_standard_input());
      assert::is_false(console::is_input_redirected(), csf_);
      file::remove(ip);
    }
    
    void test_method_(redirect_out) {
      auto op = path::combine(path::get_temp_path(), "xtd_test_out.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      assert::are_not_equal(std::cout.rdbuf(), console::out.rdbuf(), csf_);
      assert::is_true(console::is_output_redirected(), csf_);
      os.close();
      console::set_out(console::open_standard_output());
      assert::is_false(console::is_output_redirected(), csf_);
      file::remove(op);
    }
    
    void test_method_(set_cursor_position) {
      auto cursor_left = console::cursor_left();
      auto cursor_top = console::cursor_top();
      console::set_cursor_position(20, 10);
      assert::are_equal(20, console::cursor_left(), csf_);
      assert::are_equal(10, console::cursor_top(), csf_);
      console::set_cursor_position(cursor_left, cursor_top);
      assert::are_equal(cursor_left, console::cursor_left(), csf_);
      assert::are_equal(cursor_top, console::cursor_top(), csf_);
    }

    void test_method_(write) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write("Item1");
      console::write("Item2");
      console::write("Item3");
      os.close();
      assert::are_equal("Item1Item2Item3", file::read_all_text(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_literal_strings) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write("Item1");
      console::write(u8"Item2");
      console::write(u"Item3");
      console::write(U"Item4");
      console::write(L"Item5");
      os.close();
      assert::are_equal("Item1Item2Item3Item4Item5", file::read_all_text(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_strings) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write("Item1"s);
      console::write(u8"Item2"s);
      console::write(u"Item3"s);
      console::write(U"Item4"s);
      console::write(L"Item5"s);
      console::write("Item6"_s);
      os.close();
      assert::are_equal("Item1Item2Item3Item4Item5Item6", file::read_all_text(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_some_objects) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write(3_h + 42_min + 35_s);
      console::write(guid("3fcf73d9-6c77-4bd1-a030-1e1fad500a47"));
      console::write({1, 2, 3});
      os.close();
      assert::are_equal("03:42:353fcf73d9-6c77-4bd1-a030-1e1fad500a47[1, 2, 3]", file::read_all_text(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_with_format) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      auto i = 1;
      console::write("Item{}", i++);
      console::write("Item{}", i++);
      console::write("Item{}", i++);
      os.close();
      assert::are_equal("Item1Item2Item3", file::read_all_text(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_line) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write_line("Item1");
      console::write_line("Item2");
      console::write_line("Item3");
      os.close();
      collection_assert::are_equal({"Item1", "Item2", "Item3"}, file::read_all_lines(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_line_literal_strings) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write_line("Item1");
      console::write_line(u8"Item2");
      console::write_line(u"Item3");
      console::write_line(U"Item4");
      console::write_line(L"Item5");
      os.close();
      collection_assert::are_equal({"Item1", "Item2", "Item3", "Item4", "Item5"}, file::read_all_lines(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_line_strings) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write_line("Item1"s);
      console::write_line(u8"Item2"s);
      console::write_line(u"Item3"s);
      console::write_line(U"Item4"s);
      console::write_line(L"Item5"s);
      console::write_line(L"Item6"_s);
      os.close();
      collection_assert::are_equal({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6"}, file::read_all_lines(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_line_some_objects) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      console::write_line(3_h + 42_min + 35_s);
      console::write_line(guid("3fcf73d9-6c77-4bd1-a030-1e1fad500a47"));
      console::write_line({1, 2, 3});
      os.close();
      collection_assert::are_equal({"03:42:35", "3fcf73d9-6c77-4bd1-a030-1e1fad500a47", "[1, 2, 3]"}, file::read_all_lines(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }

    void test_method_(write_line_with_format) {
      auto op = path::combine(path::get_temp_path(), "xtd_console_test.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      auto i = 1;
      console::write_line("Item{}", i++);
      console::write_line("Item{}", i++);
      console::write_line("Item{}", i++);
      os.close();
      collection_assert::are_equal({"Item1", "Item2", "Item3"}, file::read_all_lines(op), csf_);
      file::remove(op);
      console::set_out(console::open_standard_output());
    }
  };
}

