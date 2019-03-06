#include <xtd/io>
#include <xtd/tunit>

using namespace std;
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
  };
}
