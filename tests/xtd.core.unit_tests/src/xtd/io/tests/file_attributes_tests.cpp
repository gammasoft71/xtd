#include <xtd/io/file_attributes>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(file_attributes_tests) {
    void test_method_(read_only) {
      assert::are_equal(1, enum_object<>::to_int32(file_attributes::read_only));
      assert::are_equal("read_only", enum_object<>::to_string(file_attributes::read_only));
      assert::are_equal(file_attributes::read_only, enum_object<>::parse<file_attributes>("read_only"));
    }
    
    void test_method_(hidden) {
      assert::are_equal(2, enum_object<>::to_int32(file_attributes::hidden));
      assert::are_equal("hidden", enum_object<>::to_string(file_attributes::hidden));
      assert::are_equal(file_attributes::hidden, enum_object<>::parse<file_attributes>("hidden"));
    }
    
    void test_method_(system) {
      assert::are_equal(4, enum_object<>::to_int32(file_attributes::system));
      assert::are_equal("system", enum_object<>::to_string(file_attributes::system));
      assert::are_equal(file_attributes::system, enum_object<>::parse<file_attributes>("system"));
    }
    
    void test_method_(directory) {
      assert::are_equal(16, enum_object<>::to_int32(file_attributes::directory));
      assert::are_equal("directory", enum_object<>::to_string(file_attributes::directory));
      assert::are_equal(file_attributes::directory, enum_object<>::parse<file_attributes>("directory"));
    }
    
    void test_method_(archive) {
      assert::are_equal(32, enum_object<>::to_int32(file_attributes::archive));
      assert::are_equal("archive", enum_object<>::to_string(file_attributes::archive));
      assert::are_equal(file_attributes::archive, enum_object<>::parse<file_attributes>("archive"));
    }
    
    void test_method_(device) {
      assert::are_equal(64, enum_object<>::to_int32(file_attributes::device));
      assert::are_equal("device", enum_object<>::to_string(file_attributes::device));
      assert::are_equal(file_attributes::device, enum_object<>::parse<file_attributes>("device"));
    }
    
    void test_method_(normal) {
      assert::are_equal(128, enum_object<>::to_int32(file_attributes::normal));
      assert::are_equal("normal", enum_object<>::to_string(file_attributes::normal));
      assert::are_equal(file_attributes::normal, enum_object<>::parse<file_attributes>("normal"));
    }
    
    void test_method_(temporary) {
      assert::are_equal(256, enum_object<>::to_int32(file_attributes::temporary));
      assert::are_equal("temporary", enum_object<>::to_string(file_attributes::temporary));
      assert::are_equal(file_attributes::temporary, enum_object<>::parse<file_attributes>("temporary"));
    }
    
    void test_method_(sparse_file) {
      assert::are_equal(512, enum_object<>::to_int32(file_attributes::sparse_file));
      assert::are_equal("sparse_file", enum_object<>::to_string(file_attributes::sparse_file));
      assert::are_equal(file_attributes::sparse_file, enum_object<>::parse<file_attributes>("sparse_file"));
    }
    
    void test_method_(reparse_point) {
      assert::are_equal(1024, enum_object<>::to_int32(file_attributes::reparse_point));
      assert::are_equal("reparse_point", enum_object<>::to_string(file_attributes::reparse_point));
      assert::are_equal(file_attributes::reparse_point, enum_object<>::parse<file_attributes>("reparse_point"));
    }
    
    void test_method_(compressed) {
      assert::are_equal(2048, enum_object<>::to_int32(file_attributes::compressed));
      assert::are_equal("compressed", enum_object<>::to_string(file_attributes::compressed));
      assert::are_equal(file_attributes::compressed, enum_object<>::parse<file_attributes>("compressed"));
    }
    
    void test_method_(offline) {
      assert::are_equal(4096, enum_object<>::to_int32(file_attributes::offline));
      assert::are_equal("offline", enum_object<>::to_string(file_attributes::offline));
      assert::are_equal(file_attributes::offline, enum_object<>::parse<file_attributes>("offline"));
    }
    
    void test_method_(not_content_indexed) {
      assert::are_equal(8192, enum_object<>::to_int32(file_attributes::not_content_indexed));
      assert::are_equal("not_content_indexed", enum_object<>::to_string(file_attributes::not_content_indexed));
      assert::are_equal(file_attributes::not_content_indexed, enum_object<>::parse<file_attributes>("not_content_indexed"));
    }
    
    void test_method_(encrypted) {
      assert::are_equal(16384, enum_object<>::to_int32(file_attributes::encrypted));
      assert::are_equal("encrypted", enum_object<>::to_string(file_attributes::encrypted));
      assert::are_equal(file_attributes::encrypted, enum_object<>::parse<file_attributes>("encrypted"));
    }
  };
}
