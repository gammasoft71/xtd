#include <xtd/io/path.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_path) {
  public:
    void test_method_(alt_directory_separator_char) {
      assert::are_equal('/', path::alt_directory_separator_char());
    }

    void test_method_(change_extension) {
      auto file_name = "file.txt";
      assert::are_equal("file.bak", path::change_extension(file_name, ".bak"));
    }

    void test_method_(change_extension_without_point) {
      auto file_name = "file.txt";
      assert::are_equal("file.bak", path::change_extension(file_name, "bak"));
    }

    void test_method_(change_extension_with_strange_extension) {
      auto file_name = "file.txt";
      assert::are_equal("file.backup.bak", path::change_extension(file_name, ".backup.bak"));
    }

    void test_method_(change_extension_source_without_extension) {
      auto file_name = "file";
      assert::are_equal("file.bak", path::change_extension(file_name, ".bak"));
    }

    void test_method_(change_extension_with_empty_extension) {
      auto file_name = "file.com";
      assert::are_equal("file", path::change_extension(file_name, ""));
    }

    void test_method_(change_extension_with_only_point_extension) {
      auto file_name = "file.com";
      assert::are_equal("file.", path::change_extension(file_name, "."));
    }

    void test_method_(change_extension_without_source) {
      auto file_name = ".com";
      assert::are_equal(".bak", path::change_extension(file_name, ".bak"));
    }

    void test_method_(change_extension_wit_empty_source) {
      auto file_name = "";
      assert::are_equal(".bak", path::change_extension(file_name, ".bak"));
    }
    
    void test_method_(combine_two_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s , path::combine("path1", "path2"));
    }
    
    void test_method_(combine_three_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s + path::directory_separator_char() + "path3"_s, path::combine("path1", "path2", "path3"));
    }
    
    void test_method_(combine_four_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s + path::directory_separator_char() + "path3"_s + path::directory_separator_char() + "path4"_s, path::combine("path1", "path2", "path3", "path4"));
    }
    
    void test_method_(combine_n_paths) {
      assert::are_equal("path1"_s + path::directory_separator_char() + "path2"_s + path::directory_separator_char() + "path3"_s + path::directory_separator_char() + "path4"_s + path::directory_separator_char() + "path5"_s, path::combine({"path1", "path2", "path3", "path4", "path5"}));
    }

    void test_method_(directory_separator_char) {
#if defined(_WIN32)
      assert::are_equal('\\', path::directory_separator_char());
#else
      assert::are_equal('/', path::directory_separator_char());
#endif
    }
    
    void test_method_(get_directory_name) {
      assert::are_equal("path1/path2", path::get_directory_name("path1/path2/file.ext"));
    }

    void test_method_(get_directory_name_without_extension) {
      assert::are_equal("path1/path2", path::get_directory_name("path1/path2/file"));
    }
    
    void test_method_(get_directory_name_without_file) {
      assert::are_equal("path1/path2", path::get_directory_name("path1/path2/"));
    }
    
    void test_method_(get_directory_name_without_path) {
      assert::are_equal("", path::get_directory_name("file.ext"));
    }
    
    void test_method_(get_directory_name_without_path_and_without_extension) {
      assert::are_equal("", path::get_directory_name("file"));
    }
    
    void test_method_(get_directory_name_with_empty_source) {
      assert::are_equal("", path::get_directory_name(""));
    }
    
    void test_method_(get_extension) {
      assert::are_equal(".ext", path::get_extension("path1/path2/file.ext"));
    }
    
    void test_method_(get_extension_without_path) {
      assert::are_equal(".ext", path::get_extension("file.ext"));
    }

    void test_method_(get_extension_without_extension) {
      assert::are_equal("", path::get_extension("path1/path2/file"));
    }
    
    void test_method_(get_extension_without_file_name) {
      assert::are_equal(".ext", path::get_extension("path1/path2/.ext"));
    }
    
    void test_method_(get_extension_without_file) {
      assert::are_equal("", path::get_extension("path1/path2/"));
    }
    
    void test_method_(get_extension_with_empty_source) {
      assert::are_equal("", path::get_extension(""));
    }
  };
}
