#include <xtd/io/file_access>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(file_access_tests) {
    void test_method_(read) {
      assert::are_equal(1, enum_object<>::to_int32(file_access::read), csf_);
      assert::are_equal("read", enum_object<>::to_string(file_access::read), csf_);
      assert::are_equal(file_access::read, enum_object<>::parse<file_access>("read"), csf_);
    }
    
    void test_method_(write) {
      assert::are_equal(2, enum_object<>::to_int32(file_access::write), csf_);
      assert::are_equal("write", enum_object<>::to_string(file_access::write), csf_);
      assert::are_equal(file_access::write, enum_object<>::parse<file_access>("write"), csf_);
    }
    
    void test_method_(read_write) {
      assert::are_equal(3, enum_object<>::to_int32(file_access::read_write), csf_);
      assert::are_equal("read_write", enum_object<>::to_string(file_access::read_write), csf_);
      assert::are_equal(file_access::read_write, enum_object<>::parse<file_access>("read_write"), csf_);
    }
  };
}

