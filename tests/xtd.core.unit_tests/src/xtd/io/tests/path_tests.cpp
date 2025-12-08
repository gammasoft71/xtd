#include <xtd/io/path>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(path_tests) {
    auto test_method_(alt_directory_separator_char) {
      assert::are_equal('/', path::alt_directory_separator_char());
    }
    
    auto test_method_(change_extension) {
      auto file_name = "file.txt";
      assert::are_equal("file.bak", path::change_extension(file_name, ".bak"));
    }
    
    auto test_method_(change_extension_without_point) {
      auto file_name = "file.txt";
      assert::are_equal("file.bak", path::change_extension(file_name, "bak"));
    }
    
    auto test_method_(change_extension_with_strange_extension) {
      auto file_name = "file.txt";
      assert::are_equal("file.backup.bak", path::change_extension(file_name, ".backup.bak"));
    }
    
    auto test_method_(change_extension_source_without_extension) {
      auto file_name = "file";
      assert::are_equal("file.bak", path::change_extension(file_name, ".bak"));
    }
    
    auto test_method_(change_extension_with_empty_extension) {
      auto file_name = "file.com";
      assert::are_equal("file", path::change_extension(file_name, ""));
    }
    
    auto test_method_(change_extension_with_only_point_extension) {
      auto file_name = "file.com";
      assert::are_equal("file.", path::change_extension(file_name, "."));
    }
    
    auto test_method_(change_extension_without_source) {
      auto file_name = ".com";
      assert::are_equal(".bak", path::change_extension(file_name, ".bak"));
    }
    
    auto test_method_(change_extension_wit_empty_source) {
      auto file_name = "";
      assert::are_equal(".bak", path::change_extension(file_name, ".bak"));
    }
    
    auto test_method_(combine_two_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s, path::combine("path1", "path2"));
    }
    
    auto test_method_(combine_three_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s + path::directory_separator_char() + "path3"_s, path::combine("path1", "path2", "path3"));
    }
    
    auto test_method_(combine_four_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s + path::directory_separator_char() + "path3"_s + path::directory_separator_char() + "path4"_s, path::combine("path1", "path2", "path3", "path4"));
    }
    
    auto test_method_(combine_n_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s + path::directory_separator_char() + "path3"_s + path::directory_separator_char() + "path4"_s + path::directory_separator_char() + "path5"_s, path::combine({"path1", "path2", "path3", "path4", "path5"}));
    }
    
    auto test_method_(directory_separator_char) {
      #if defined(_WIN32)
      assert::are_equal('\\', path::directory_separator_char());
      #else
      assert::are_equal('/', path::directory_separator_char());
      #endif
    }
    
    auto test_method_(get_directory_name) {
      assert::are_equal("path1/path2", path::get_directory_name("path1/path2/file.ext"));
    }
    
    auto test_method_(get_directory_name_without_extension) {
      assert::are_equal("path1/path2", path::get_directory_name("path1/path2/file"));
    }
    
    auto test_method_(get_directory_name_without_file) {
      assert::are_equal("path1/path2", path::get_directory_name("path1/path2/"));
    }
    
    auto test_method_(get_directory_name_without_path) {
      assert::is_empty(path::get_directory_name("file.ext"));
    }
    
    auto test_method_(get_directory_name_without_path_and_without_extension) {
      assert::is_empty(path::get_directory_name("file"));
    }
    
    auto test_method_(get_directory_name_with_empty_source) {
      assert::is_empty(path::get_directory_name(""));
    }
    
    auto test_method_(get_extension) {
      assert::are_equal(".ext", path::get_extension("path1/path2/file.ext"));
    }
    
    auto test_method_(get_extension_without_path) {
      assert::are_equal(".ext", path::get_extension("file.ext"));
    }
    
    auto test_method_(get_extension_without_extension) {
      assert::is_empty(path::get_extension("path1/path2/file"));
    }
    
    auto test_method_(get_extension_without_file_name) {
      assert::are_equal(".ext", path::get_extension("path1/path2/.ext"));
    }
    
    auto test_method_(get_extension_without_file) {
      assert::is_empty(path::get_extension("path1/path2/"));
    }
    
    auto test_method_(get_extension_with_empty_source) {
      assert::is_empty(path::get_extension(""));
    }
    
    // Remove following tests as they do not work on Github actions...
    /*
    auto test_method_(get_full_path) {
      string path = "xtd_test_file.txt";
      console::write_line(path::get_full_path(path));
      assert::are_equal(path::combine(directory::get_current_directory(), path), path::get_full_path(path));
    }
    
    auto test_method_(get_full_path_recursive) {
      string file = "xtd_test_file.txt";
      string path = path::combine("dir1", "dir2", file);
      assert::are_equal(path::combine(directory::get_current_directory(), "dir1", "dir2", file), path::get_full_path(path));
    }
    
    auto test_method_(get_full_path_with_temp) {
      string file = "xtd_test_file.txt";
      string path = path::combine(path::get_temp_path(), file);
      assert::are_equal(path::combine(path::get_temp_path(), file), path::get_full_path(path));
    }
    
    auto test_method_(get_full_path_recursive_with_temp) {
      string file = "xtd_test_file.txt";
      string path = path::combine(path::get_temp_path(), "dir1", "dir2", file);
      assert::are_equal(path::combine(path::get_temp_path(), "dir1", "dir2", file), path::get_full_path(path));
    }
     */
  };
}
