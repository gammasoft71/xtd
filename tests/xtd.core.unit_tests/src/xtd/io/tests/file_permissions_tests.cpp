#include <xtd/io/file_permissions>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(file_permissions_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(file_permissions::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(file_permissions::none), csf_);
      assert::are_equal(file_permissions::none, enum_object<>::parse<file_permissions>("none"), csf_);
    }
    
    void test_method_(owner_read) {
      assert::are_equal(256, enum_object<>::to_int32(file_permissions::owner_read), csf_);
      assert::are_equal("owner_read", enum_object<>::to_string(file_permissions::owner_read), csf_);
      assert::are_equal(file_permissions::owner_read, enum_object<>::parse<file_permissions>("owner_read"), csf_);
    }
    
    void test_method_(owner_write) {
      assert::are_equal(128, enum_object<>::to_int32(file_permissions::owner_write), csf_);
      assert::are_equal("owner_write", enum_object<>::to_string(file_permissions::owner_write), csf_);
      assert::are_equal(file_permissions::owner_write, enum_object<>::parse<file_permissions>("owner_write"), csf_);
    }
    
    void test_method_(owner_execute) {
      assert::are_equal(64, enum_object<>::to_int32(file_permissions::owner_execute), csf_);
      assert::are_equal("owner_execute", enum_object<>::to_string(file_permissions::owner_execute), csf_);
      assert::are_equal(file_permissions::owner_execute, enum_object<>::parse<file_permissions>("owner_execute"), csf_);
    }
    
    void test_method_(group_read) {
      assert::are_equal(32, enum_object<>::to_int32(file_permissions::group_read), csf_);
      assert::are_equal("group_read", enum_object<>::to_string(file_permissions::group_read), csf_);
      assert::are_equal(file_permissions::group_read, enum_object<>::parse<file_permissions>("group_read"), csf_);
    }
    
    void test_method_(group_write) {
      assert::are_equal(16, enum_object<>::to_int32(file_permissions::group_write), csf_);
      assert::are_equal("group_write", enum_object<>::to_string(file_permissions::group_write), csf_);
      assert::are_equal(file_permissions::group_write, enum_object<>::parse<file_permissions>("group_write"), csf_);
    }
    
    void test_method_(group_execute) {
      assert::are_equal(8, enum_object<>::to_int32(file_permissions::group_execute), csf_);
      assert::are_equal("group_execute", enum_object<>::to_string(file_permissions::group_execute), csf_);
      assert::are_equal(file_permissions::group_execute, enum_object<>::parse<file_permissions>("group_execute"), csf_);
    }
    
    void test_method_(others_read) {
      assert::are_equal(4, enum_object<>::to_int32(file_permissions::others_read), csf_);
      assert::are_equal("others_read", enum_object<>::to_string(file_permissions::others_read), csf_);
      assert::are_equal(file_permissions::others_read, enum_object<>::parse<file_permissions>("others_read"), csf_);
    }
    
    void test_method_(others_write) {
      assert::are_equal(2, enum_object<>::to_int32(file_permissions::others_write), csf_);
      assert::are_equal("others_write", enum_object<>::to_string(file_permissions::others_write), csf_);
      assert::are_equal(file_permissions::others_write, enum_object<>::parse<file_permissions>("others_write"), csf_);
    }
    
    void test_method_(others_execute) {
      assert::are_equal(1, enum_object<>::to_int32(file_permissions::others_execute), csf_);
      assert::are_equal("others_execute", enum_object<>::to_string(file_permissions::others_execute), csf_);
      assert::are_equal(file_permissions::others_execute, enum_object<>::parse<file_permissions>("others_execute"), csf_);
    }
    
    void test_method_(set_uid) {
      assert::are_equal(2048, enum_object<>::to_int32(file_permissions::set_uid), csf_);
      assert::are_equal("set_uid", enum_object<>::to_string(file_permissions::set_uid), csf_);
      assert::are_equal(file_permissions::set_uid, enum_object<>::parse<file_permissions>("set_uid"), csf_);
    }
    
    void test_method_(set_gid) {
      assert::are_equal(1024, enum_object<>::to_int32(file_permissions::set_gid), csf_);
      assert::are_equal("set_gid", enum_object<>::to_string(file_permissions::set_gid), csf_);
      assert::are_equal(file_permissions::set_gid, enum_object<>::parse<file_permissions>("set_gid"), csf_);
    }
    
    void test_method_(sticky_bit) {
      assert::are_equal(512, enum_object<>::to_int32(file_permissions::sticky_bit), csf_);
      assert::are_equal("sticky_bit", enum_object<>::to_string(file_permissions::sticky_bit), csf_);
      assert::are_equal(file_permissions::sticky_bit, enum_object<>::parse<file_permissions>("sticky_bit"), csf_);
    }
    
    void test_method_(unknown) {
      assert::are_equal(4095, enum_object<>::to_int32(file_permissions::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(file_permissions::unknown), csf_);
      assert::are_equal(file_permissions::unknown, enum_object<>::parse<file_permissions>("unknown"), csf_);
    }
  };
}
