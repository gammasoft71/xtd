#include <xtd/io/stream_writer.h>
#include <xtd/io/stream_reader.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_directory) {
    static const ustring test_path;
    void test_initialize_(test_initialize) {
      if (directory::exists(test_path)) directory::remove(test_path, true);
      directory::create_directory(test_path);
      directory_assume::exists(test_path, csf_);
    }
    
    void test_cleanup_(test_cleanup) {
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
      assert::throws<argument_exception>([]{directory::create_directory("");}, csf_);
    }
    
    void test_method_(create_directory_with_path_with_spaces) {
      assert::throws<argument_exception>([]{directory::create_directory("   ");}, csf_);
    }
  };

  const ustring test_directory::test_path = path::combine(path::get_temp_path(), "test_directory");
}
