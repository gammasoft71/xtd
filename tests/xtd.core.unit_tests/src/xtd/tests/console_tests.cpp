#include <xtd/console.h>
#include <xtd/io/file.h>
#include <xtd/io/path.h>
#include <xtd/xtd.tunit>

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
    
    void test_method_(get_background_color) {
      assert::are_equal(console_color::black, console::background_color(), csf_);
    }
    
    void test_method_(get_foreground_color) {
      assert::are_equal(console_color::white, console::foreground_color(), csf_);
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
    
    void test_method_(set_background_color_blue_and_reset) {
      console::background_color(console_color::blue);
      assert::are_equal(console_color::blue, console::background_color(), csf_);
      console::reset_color();
      assert::are_equal(console_color::black, console::background_color(), csf_);
    }
    
    void test_method_(set_foreground_color_yellow_and_reset) {
      console::foreground_color(console_color::yellow);
      assert::are_equal(console_color::yellow, console::foreground_color(), csf_);
      console::reset_color();
      assert::are_equal(console_color::white, console::foreground_color(), csf_);
    }

    void test_method_(write) {
      auto op = path::combine(path::get_temp_path(), "xtd_test_write.txt");
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
    
    void test_method_(write_with_format) {
      auto op = path::combine(path::get_temp_path(), "xtd_test_write.txt");
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
      auto op = path::combine(path::get_temp_path(), "xtd_test_write.txt");
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

    void test_method_(write_line_with_format) {
      auto op = path::combine(path::get_temp_path(), "xtd_test_write.txt");
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

