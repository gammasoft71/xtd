#include <xtd/console.h>
#include <xtd/int16_object.h>
#include <xtd/io/file.h>
#include <xtd/io/path.h>
#include <xtd/tunit/assert.h>
#include <xtd/tunit/collection_assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>

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
      assert::throws<argument_exception>([] {console::background_color(as<console_color>(16));}, csf_);
    }
    
    void test_method_(buffer_height) {
      auto buffer_height = console::buffer_height();
      console::buffer_height(500);
      assert::are_equal(500, console::buffer_height(), csf_);
      console::buffer_height(buffer_height);
      assert::are_equal(buffer_height, console::buffer_height(), csf_);
    }
    
    void test_method_(buffer_height_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::buffer_height(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::buffer_height(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::buffer_height(int16_object::max_value);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::buffer_height(as<int32>(int16_object::max_value) + 1);}, csf_);
    }
    
    void test_method_(buffer_width) {
      auto buffer_width = console::buffer_width();
      console::buffer_width(500);
      assert::are_equal(500, console::buffer_width(), csf_);
      console::buffer_width(buffer_width);
      assert::are_equal(buffer_width, console::buffer_width(), csf_);
    }
    
    void test_method_(buffer_width_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::buffer_width(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::buffer_width(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::buffer_width(int16_object::max_value);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::buffer_width(as<int32>(int16_object::max_value) + 1);}, csf_);
    }
    
    void test_method_(caps_lock) {
      // Remarks if caps lock is set on by user, the following test will be false.
      assert::is_false(console::caps_lock(), csf_);
    }
    
    void test_method_(cursor_left) {
      auto cursor_left = console::cursor_left();
      console::cursor_left(20);
      assert::are_equal(20, console::cursor_left(), csf_);
      console::cursor_left(cursor_left);
      assert::are_equal(cursor_left, console::cursor_left(), csf_);
    }
    
    void test_method_(cursor_left_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::cursor_left(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::cursor_left(console::buffer_width());}, csf_);
    }
    
    void test_method_(cursor_size) {
      auto cursor_size = console::cursor_size();
      console::cursor_size(10);
      assert::are_equal(10, console::cursor_size(), csf_);
      console::cursor_size(cursor_size);
      assert::are_equal(cursor_size, console::cursor_size(), csf_);
    }
    
    void test_method_(cursor_size_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::cursor_size(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::cursor_size(101);}, csf_);
    }
    
    void test_method_(cursor_top) {
      auto cursor_top = console::cursor_top();
      console::cursor_top(10);
      assert::are_equal(10, console::cursor_top(), csf_);
      console::cursor_top(cursor_top);
      assert::are_equal(cursor_top, console::cursor_top(), csf_);
    }
    
    void test_method_(cursor_top_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::cursor_top(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::cursor_top(console::buffer_height());}, csf_);
    }
    
    void test_method_(cursor_visible) {
      auto cursor_visible = console::cursor_visible();
      console::cursor_visible(false);
      assert::is_false(console::cursor_visible(), csf_);
      console::cursor_visible(true);
      assert::is_true(console::cursor_visible(), csf_);
      console::cursor_visible(cursor_visible);
      assert::are_equal(cursor_visible, console::cursor_visible(), csf_);
    }
    
    void test_method_(foreground_color) {
      auto foreground_color = console::foreground_color();
      console::foreground_color(console_color::yellow);
      assert::are_equal(console_color::yellow, console::foreground_color(), csf_);
      console::foreground_color(foreground_color);
      assert::are_equal(foreground_color, console::foreground_color(), csf_);
    }
    
    void test_method_(foreground_color_with_invalid_value) {
      assert::throws<argument_exception>([] {console::foreground_color(as<console_color>(16));}, csf_);
    }
    
    void test_method_(input_code_page) {
      auto input_code_page = console::input_code_page();
      console::input_code_page(850);
      assert::are_equal(850, console::input_code_page(), csf_);
      console::input_code_page(input_code_page);
      assert::are_equal(input_code_page, console::input_code_page(), csf_);
    }
    
    void test_method_(is_error_redirected) {
      assert::is_false(console::is_error_redirected(), csf_);
      auto ep = path::combine(path::get_temp_path(), "xtd_test_error.txt");
      auto es = xtd::io::file::open_write(ep);
      console::set_error(es);
      assert::is_true(console::is_error_redirected(), csf_);
      es.close();
      console::set_error(console::open_standard_error());
      assert::is_false(console::is_error_redirected(), csf_);
      file::remove(ep);
    }
    
    void test_method_(is_input_redirected) {
      assert::is_false(console::is_input_redirected(), csf_);
      auto ip = path::combine(path::get_temp_path(), "xtd_test_in.txt");
      file::write_all_lines(ip, {""});
      auto is = xtd::io::file::open_read(ip);
      console::set_in(is);
      assert::is_true(console::is_input_redirected(), csf_);
      is.close();
      console::set_in(console::open_standard_input());
      assert::is_false(console::is_input_redirected(), csf_);
      file::remove(ip);
    }
    
    void test_method_(is_output_redirected) {
      assert::is_false(console::is_output_redirected(), csf_);
      auto op = path::combine(path::get_temp_path(), "xtd_test_out.txt");
      auto os = xtd::io::file::open_write(op);
      console::set_out(os);
      assert::is_true(console::is_output_redirected(), csf_);
      os.close();
      console::set_out(console::open_standard_output());
      assert::is_false(console::is_output_redirected(), csf_);
      file::remove(op);
    }
    
    void test_method_(larget_wxindoow_height) {
      assert::is_not_zero(console::largest_window_height());
    }
    
    void test_method_(largest_window_width) {
      assert::is_not_zero(console::largest_window_width());
    }
    
    void test_method_(number_lock) {
      // Remarks if number lock is set off by user, the following test will be false.
      // assert::is_true(console::number_lock(), csf_);
    }
    
    void test_method_(output_code_page) {
      auto output_code_page = console::output_code_page();
      console::output_code_page(850);
      assert::are_equal(850, console::output_code_page(), csf_);
      console::output_code_page(output_code_page);
      assert::are_equal(output_code_page, console::output_code_page(), csf_);
    }
    
    void test_method_(title) {
      auto title = console::title();
      console::title("xtd test console title");
      assert::are_equal("xtd test console title", console::title(), csf_);
      console::title(title);
      assert::are_equal(title, console::title(), csf_);
    }
    
    void test_method_(treat_control_c_as_input) {
      auto treat_control_c_as_input = console::treat_control_c_as_input();
      console::treat_control_c_as_input(false);
      assert::is_false(console::treat_control_c_as_input(), csf_);
      console::treat_control_c_as_input(true);
      assert::is_true(console::treat_control_c_as_input(), csf_);
      console::treat_control_c_as_input(treat_control_c_as_input);
      assert::are_equal(treat_control_c_as_input, console::treat_control_c_as_input(), csf_);
    }
    
    void test_method_(window_height) {
      if (environment::os_version().is_windows() && !console::is_output_redirected()) assert::ignore("Ignore \"window_height\" test because it modify the console output", csf_);
      auto window_height = console::window_height();
      console::window_height(40);
      // During a unit test on CI, there is not always a graphical OS, only a console mode OS. So you can't change the height of the console window.
      //assert::are_equal(40, console::window_height(), csf_);
      console::window_height(window_height);
      assert::are_equal(window_height, console::window_height(), csf_);
    }
    
    void test_method_(window_height_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::window_height(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_height(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_height(int16_object::max_value);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_height(as<int32>(int16_object::max_value) + 1);}, csf_);
    }
    
    void test_method_(window_left) {
      if (environment::os_version().is_windows() && !console::is_output_redirected()) assert::ignore("Ignore \"window_left\" test because it modify the console output", csf_);
      auto window_left = console::window_left();
      console::window_left(5);
      // During a unit test on CI, there is not always a graphical OS, only a console mode OS. So you can't change the left of the console window.
      //assert::are_equal(5, console::window_left(), csf_);
      console::window_left(window_left);
      assert::are_equal(window_left, console::window_left(), csf_);
    }
    
    void test_method_(window_left_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::window_left(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_left(console::buffer_width());}, csf_);
    }
    
    void test_method_(window_top) {
      if (environment::os_version().is_windows() && !console::is_output_redirected()) assert::ignore("Ignore \"window_top\" test because it modify the console output", csf_);
      auto window_top = console::window_top();
      console::window_top(5);
      // During a unit test on CI, there is not always a graphical OS, only a console mode OS. So you can't change the top of the console window.
      // assert::are_equal(5, console::window_top(), csf_);
      console::window_top(window_top);
      assert::are_equal(window_top, console::window_top(), csf_);
    }
    
    void test_method_(window_top_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::window_top(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_top(console::buffer_width());}, csf_);
    }
    
    void test_method_(window_width) {
      if (environment::os_version().is_windows() && !console::is_output_redirected()) assert::ignore("Ignore \"window_width\" test because it modify the console output", csf_);
      auto window_width = console::window_width();
      console::window_width(100);
      // During a unit test on CI, there is not always a graphical OS, only a console mode OS. So you can't change the width of the console window.
      //assert::are_equal(100, console::window_width(), csf_);
      console::window_width(window_width);
      assert::are_equal(window_width, console::window_width(), csf_);
    }
    
    void test_method_(window_width_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::window_width(0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_width(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_width(int16_object::max_value);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::window_width(as<int32>(int16_object::max_value) + 1);}, csf_);
    }
    
    void test_method_(get_cursor_position) {
      auto [cursor_left, cursor_top] = console::get_cursor_position();
      console::cursor_left(20);
      console::cursor_top(10);
      assert::are_equal(make_pair(20, 10), console::get_cursor_position(), csf_);
      console::set_cursor_position(cursor_left, cursor_top);
      assert::are_equal(make_pair(cursor_left, cursor_top), console::get_cursor_position(), csf_);
    }
    
    void test_method_(open_standard_error) {
      assert::are_equal(std::cerr.rdbuf(), console::open_standard_error().rdbuf(), csf_);
    }
    
    void test_method_(open_standard_input) {
      assert::are_equal(std::cin.rdbuf(), console::open_standard_input().rdbuf(), csf_);
    }
    
    void test_method_(open_standard_output) {
      assert::are_equal(std::cout.rdbuf(), console::open_standard_output().rdbuf(), csf_);
    }
    
    void test_method_(read_line) {
      auto ip = path::combine(path::get_temp_path(), "xtd_test_in.txt");
      file::write_all_lines(ip, {"line 1", "line 2", "line 3"});
      auto is = xtd::io::file::open_read(ip);
      console::set_in(is);
      
      assert::are_equal("line 1", console::read_line(), csf_);
      assert::are_equal("line 2", console::read_line(), csf_);
      assert::are_equal("line 3", console::read_line(), csf_);
      
      is.close();
      console::set_in(console::open_standard_input());
      file::remove(ip);
    }
    
    void test_method_(read_key) {
      // Can not be tested by unit test.
      //assert::are_equal(console_key_info('a', console_key::a, false, false, false), console::read_key(), csf_);
      //assert::are_equal(console_key_info('a', console_key::a, false, false, false), console::read_key(true), csf_);
    }
    
    void test_method_(reset_color) {
      auto background_color = console::background_color();
      auto foreground_color = console::foreground_color();
      console::background_color(console_color::blue);
      console::foreground_color(console_color::yellow);
      console::reset_color();
      assert::are_equal(background_color, console::background_color(), csf_);
      assert::are_equal(foreground_color, console::foreground_color(), csf_);
    }
    
    void test_method_(set_cursor_position) {
      auto [cursor_left, cursor_top] = console::get_cursor_position();
      console::set_cursor_position(20, 10);
      assert::are_equal(20, console::cursor_left(), csf_);
      assert::are_equal(10, console::cursor_top(), csf_);
      console::set_cursor_position(cursor_left, cursor_top);
      assert::are_equal(cursor_left, console::cursor_left(), csf_);
      assert::are_equal(cursor_top, console::cursor_top(), csf_);
    }
    
    void test_method_(set_cursor_position_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::set_cursor_position(-1, 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_cursor_position(console::buffer_width(), 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_cursor_position(0, -1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_cursor_position(0, console::buffer_height());}, csf_);
    }
    
    void test_method_(set_error) {
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
    
    void test_method_(set_in) {
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
    
    void test_method_(set_out) {
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
    
    void test_method_(set_window_position) {
      if (!console::is_output_redirected()) assert::ignore("Ignore \"set_window_position\" test because it modify the console output", csf_);
      auto window_left = console::window_left();
      auto window_top = console::window_top();
      console::set_window_position(20, 10);
      // During a unit test on CI, there is not always a graphical OS, only a console mode OS. So you can't change the positioon of the console window.
      //assert::are_equal(20, console::window_left(), csf_);
      //assert::are_equal(10, console::window_top(), csf_);
      console::set_window_position(window_left, window_top);
      assert::are_equal(window_left, console::window_left(), csf_);
      assert::are_equal(window_top, console::window_top(), csf_);
    }
    
    void test_method_(set_window_position_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::set_window_position(-1, 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_position(console::buffer_width(), 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_position(0, -1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_position(0, console::buffer_height());}, csf_);
    }
    
    void test_method_(set_window_size) {
      if (!console::is_output_redirected()) assert::ignore("Ignore \"set_window_position\" test because it modify the console output", csf_);
      auto window_width = console::window_width();
      auto window_height = console::window_height();
      console::set_window_size(20, 10);
      // During a unit test on CI, there is not always a graphical OS, only a console mode OS. So you can't change the size of the console window.
      //assert::are_equal(20, console::window_width(), csf_);
      //assert::are_equal(10, console::window_height(), csf_);
      console::set_window_size(window_width, window_height);
      assert::are_equal(window_width, console::window_width(), csf_);
      assert::are_equal(window_height, console::window_height(), csf_);
    }
    
    void test_method_(set_window_size_with_invalid_values) {
      assert::throws<argument_out_of_range_exception>([] {console::set_window_size(0, 10);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_size(-1, 10);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_size(int16_object::max_value, 10);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_size(10, 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_size(10, -1);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {console::set_window_size(10, int16_object::max_value);}, csf_);
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
