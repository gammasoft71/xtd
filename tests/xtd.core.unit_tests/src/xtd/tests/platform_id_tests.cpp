#include <xtd/platform_id>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(platform_id_tests) {
  public:
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(platform_id::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(platform_id::unknown), csf_);
      assert::are_equal(platform_id::unknown, enum_object<>::parse<platform_id>("unknown"), csf_);
    }
    
    void test_method_(win32s) {
      assert::are_equal(0, enum_object<>::to_int32(platform_id::win32s), csf_);
      assert::are_equal("win32s", enum_object<>::to_string(platform_id::win32s), csf_);
      assert::are_equal(platform_id::win32s, enum_object<>::parse<platform_id>("win32s"), csf_);
    }
    
    void test_method_(win32_windows) {
      assert::are_equal(1, enum_object<>::to_int32(platform_id::win32_windows), csf_);
      assert::are_equal("win32_windows", enum_object<>::to_string(platform_id::win32_windows), csf_);
      assert::are_equal(platform_id::win32_windows, enum_object<>::parse<platform_id>("win32_windows"), csf_);
    }
    
    void test_method_(win32_nt) {
      assert::are_equal(2, enum_object<>::to_int32(platform_id::win32_nt), csf_);
      assert::are_equal("win32_nt", enum_object<>::to_string(platform_id::win32_nt), csf_);
      assert::are_equal(platform_id::win32_nt, enum_object<>::parse<platform_id>("win32_nt"), csf_);
    }
    
    void test_method_(win_ce) {
      assert::are_equal(3, enum_object<>::to_int32(platform_id::win_ce), csf_);
      assert::are_equal("win_ce", enum_object<>::to_string(platform_id::win_ce), csf_);
      assert::are_equal(platform_id::win_ce, enum_object<>::parse<platform_id>("win_ce"), csf_);
    }
    
    void test_method_(unix) {
      assert::are_equal(4, enum_object<>::to_int32(platform_id::unix), csf_);
      assert::are_equal("unix", enum_object<>::to_string(platform_id::unix), csf_);
      assert::are_equal(platform_id::unix, enum_object<>::parse<platform_id>("unix"), csf_);
    }
    
    void test_method_(xbox) {
      assert::are_equal(5, enum_object<>::to_int32(platform_id::xbox), csf_);
      assert::are_equal("xbox", enum_object<>::to_string(platform_id::xbox), csf_);
      assert::are_equal(platform_id::xbox, enum_object<>::parse<platform_id>("xbox"), csf_);
    }
    
    void test_method_(macos) {
      assert::are_equal(6, enum_object<>::to_int32(platform_id::macos), csf_);
      assert::are_equal("macos", enum_object<>::to_string(platform_id::macos), csf_);
      assert::are_equal(platform_id::macos, enum_object<>::parse<platform_id>("macos"), csf_);
    }
    
    void test_method_(ios) {
      assert::are_equal(7, enum_object<>::to_int32(platform_id::ios), csf_);
      assert::are_equal("ios", enum_object<>::to_string(platform_id::ios), csf_);
      assert::are_equal(platform_id::ios, enum_object<>::parse<platform_id>("ios"), csf_);
    }
    
    void test_method_(android) {
      assert::are_equal(8, enum_object<>::to_int32(platform_id::android), csf_);
      assert::are_equal("android", enum_object<>::to_string(platform_id::android), csf_);
      assert::are_equal(platform_id::android, enum_object<>::parse<platform_id>("android"), csf_);
    }
    
    void test_method_(linux) {
      assert::are_equal(9, enum_object<>::to_int32(platform_id::linux), csf_);
      assert::are_equal("linux", enum_object<>::to_string(platform_id::linux), csf_);
      assert::are_equal(platform_id::linux, enum_object<>::parse<platform_id>("linux"), csf_);
    }
    
    void test_method_(tvos) {
      assert::are_equal(10, enum_object<>::to_int32(platform_id::tvos), csf_);
      assert::are_equal("tvos", enum_object<>::to_string(platform_id::tvos), csf_);
      assert::are_equal(platform_id::tvos, enum_object<>::parse<platform_id>("tvos"), csf_);
    }
    
    void test_method_(watchos) {
      assert::are_equal(11, enum_object<>::to_int32(platform_id::watchos), csf_);
      assert::are_equal("watchos", enum_object<>::to_string(platform_id::watchos), csf_);
      assert::are_equal(platform_id::watchos, enum_object<>::parse<platform_id>("watchos"), csf_);
    }
    
    void test_method_(other) {
      assert::are_equal(12, enum_object<>::to_int32(platform_id::other), csf_);
      assert::are_equal("other", enum_object<>::to_string(platform_id::other), csf_);
      assert::are_equal(platform_id::other, enum_object<>::parse<platform_id>("other"), csf_);
    }
  };
}
