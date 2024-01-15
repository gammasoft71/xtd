#include <xtd/net/sockets/select_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(select_mode_tests) {
    void test_method_(select_read) {
      assert::are_equal(0, enum_object<>::to_int32(select_mode::select_read), csf_);
      assert::are_equal("select_read", enum_object<>::to_string(select_mode::select_read), csf_);
      assert::are_equal(select_mode::select_read, enum_object<>::parse<select_mode>("select_read"), csf_);
    }
    
    void test_method_(select_write) {
      assert::are_equal(1, enum_object<>::to_int32(select_mode::select_write), csf_);
      assert::are_equal("select_write", enum_object<>::to_string(select_mode::select_write), csf_);
      assert::are_equal(select_mode::select_write, enum_object<>::parse<select_mode>("select_write"), csf_);
    }
    
    void test_method_(select_error) {
      assert::are_equal(2, enum_object<>::to_int32(select_mode::select_error), csf_);
      assert::are_equal("select_error", enum_object<>::to_string(select_mode::select_error), csf_);
      assert::are_equal(select_mode::select_error, enum_object<>::parse<select_mode>("select_error"), csf_);
    }
  };
}
