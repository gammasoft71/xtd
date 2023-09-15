#include <xtd/net/sockets/transmit_file_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(transmit_file_options_tests) {
  public:
    void test_method_(use_default_worker_thread) {
      assert::are_equal(0, enum_object<>::to_int32(transmit_file_options::use_default_worker_thread), csf_);
      assert::are_equal("use_default_worker_thread", enum_object<>::to_string(transmit_file_options::use_default_worker_thread), csf_);
      assert::are_equal(transmit_file_options::use_default_worker_thread, enum_object<>::parse<transmit_file_options>("use_default_worker_thread"), csf_);
    }
    
    void test_method_(disconnect) {
      assert::are_equal(1, enum_object<>::to_int32(transmit_file_options::disconnect), csf_);
      assert::are_equal("disconnect", enum_object<>::to_string(transmit_file_options::disconnect), csf_);
      assert::are_equal(transmit_file_options::disconnect, enum_object<>::parse<transmit_file_options>("disconnect"), csf_);
    }
    
    void test_method_(reuse_socket) {
      assert::are_equal(2, enum_object<>::to_int32(transmit_file_options::reuse_socket), csf_);
      assert::are_equal("reuse_socket", enum_object<>::to_string(transmit_file_options::reuse_socket), csf_);
      assert::are_equal(transmit_file_options::reuse_socket, enum_object<>::parse<transmit_file_options>("reuse_socket"), csf_);
    }
    
    void test_method_(write_behind) {
      assert::are_equal(4, enum_object<>::to_int32(transmit_file_options::write_behind), csf_);
      assert::are_equal("write_behind", enum_object<>::to_string(transmit_file_options::write_behind), csf_);
      assert::are_equal(transmit_file_options::write_behind, enum_object<>::parse<transmit_file_options>("write_behind"), csf_);
    }
    
    void test_method_(use_system_thread) {
      assert::are_equal(8, enum_object<>::to_int32(transmit_file_options::use_system_thread), csf_);
      assert::are_equal("use_system_thread", enum_object<>::to_string(transmit_file_options::use_system_thread), csf_);
      assert::are_equal(transmit_file_options::use_system_thread, enum_object<>::parse<transmit_file_options>("use_system_thread"), csf_);
    }
    
    void test_method_(use_kernel_apc) {
      assert::are_equal(32, enum_object<>::to_int32(transmit_file_options::use_kernel_apc), csf_);
      assert::are_equal("use_kernel_apc", enum_object<>::to_string(transmit_file_options::use_kernel_apc), csf_);
      assert::are_equal(transmit_file_options::use_kernel_apc, enum_object<>::parse<transmit_file_options>("use_kernel_apc"), csf_);
    }
  };
}
