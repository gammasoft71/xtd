#include <xtd/io/stream_writer.h>
#include <xtd/io/stream_reader.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_directory_info) {
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
    void test_method_(create_with_existing_path) {
      directory_assume::exists(test_path, csf_);
      assert::does_not_throw([]{directory_info di(test_path);}, csf_);
    }

    void test_method_(create_with_not_existing_path) {
      directory_assume::does_not_exist(path::combine(test_path, "directory"), csf_);
      assert::does_not_throw([]{directory_info di(path::combine(test_path, "directory"));}, csf_);
    }

    void test_method_(create_with_invalid_path) {
      assert::throws<argument_exception>([]{directory_info di(path::combine(test_path, "direc<tory"));}, csf_);
    }

    void test_method_(exists_with_existing_path) {
      directory_assume::exists(test_path, csf_);
      directory_info di(test_path);
      assert::is_true(di.exists());
    }

    void test_method_(exists_with_not_existing_path) {
      directory_assume::does_not_exist(path::combine(test_path, "directory"), csf_);
      directory_info di(path::combine(test_path, "directory"));
      assert::is_false(di.exists());
    }

    void test_method_(name) {
      directory_info di(path::combine(test_path, "directory"));
      assert::are_equal("directory", di.name(), csf_);
    }

  };

  const ustring test_directory_info::test_path = path::combine(path::get_temp_path(), "test_directory");
}
