#include <xtd/io/directory>
#include <xtd/io/path_too_long_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/directory_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(directory_tests) {
    inline static const ustring test_path = path::combine(path::get_temp_path(), "test_directory");
    static void test_initialize_(test_initialize) {
      if (directory::exists(test_path)) directory::remove(test_path, true);
      directory::create_directory(test_path);
      directory_assume::exists(test_path, csf_);
    }
    
    static void test_cleanup_(test_cleanup) {
      directory::remove(test_path, true);
      directory_assume::does_not_exist(test_path, csf_);
    }
    
  public:
    void test_method_(create_directory) {
      directory_assume::does_not_exist(path::combine(test_path, "directory"), csf_);
      directory::create_directory(path::combine(test_path, "directory"));
      directory_assert::exists(path::combine(test_path, "directory"), csf_);
    }
    
    void test_method_(create_directory_with_an_existing_directtory) {
      directory_assume::does_not_exist(path::combine(test_path, "directory"), csf_);
      directory::create_directory(path::combine(test_path, "directory"));
      directory_assert::exists(path::combine(test_path, "directory"), csf_);
      directory::create_directory(path::combine(test_path, "directory"));
      directory_assert::exists(path::combine(test_path, "directory"), csf_);
    }
    
    void test_method_(create_directory_with_three_directories) {
      directory_assume::does_not_exist(path::combine(test_path, "directory1", "directory2", "directory3"), csf_);
      directory::create_directory(path::combine(test_path, "directory1", "directory2", "directory3"));
      directory_assert::exists(path::combine(test_path, "directory1", "directory2", "directory3"), csf_);
    }
    
    void test_method_(create_directory_with_empty_path) {
      assert::throws<argument_exception>([] {directory::create_directory("");}, csf_);
    }
    
    void test_method_(create_directory_with_path_that_contains_spaces) {
      assert::throws<argument_exception>([] {directory::create_directory("   ");}, csf_);
    }
    
    void test_method_(create_directory_with_path_that_contains_invalid_characters) {
      assert::throws<argument_exception>([] {directory::create_directory("direct<ory1");}, csf_);
    }
    
    void test_method_(create_directory_with_path_too_long) {
      // Windows :
      //   https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=cmd
      //   #define MAX_PATH 260
      // macOS :
      //   #define PATH_MAX 1024 /* max bytes in pathname */
      //   #define NAME_MAX  255 /* max bytes in a file name */
      // Linux :
      //   #define PATH_MAX 4096 /* # chars in a path name including nul */
      //   #define NAME_MAX  255 /* max bytes in a file name */
      assert::throws<path_too_long_exception>([] {directory::create_directory("directory"_s + ustring(260, '1'));}, csf_);
    }
  };
}
