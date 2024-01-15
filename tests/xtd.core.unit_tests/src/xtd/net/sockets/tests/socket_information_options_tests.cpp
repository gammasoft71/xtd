#include <xtd/net/sockets/socket_information_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(socket_information_options_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(socket_information_options::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(socket_information_options::none), csf_);
      assert::are_equal(socket_information_options::none, enum_object<>::parse<socket_information_options>("none"), csf_);
    }
    
    void test_method_(non_blocking) {
      assert::are_equal(1, enum_object<>::to_int32(socket_information_options::non_blocking), csf_);
      assert::are_equal("non_blocking", enum_object<>::to_string(socket_information_options::non_blocking), csf_);
      assert::are_equal(socket_information_options::non_blocking, enum_object<>::parse<socket_information_options>("non_blocking"), csf_);
    }
    
    void test_method_(connected) {
      assert::are_equal(2, enum_object<>::to_int32(socket_information_options::connected), csf_);
      assert::are_equal("connected", enum_object<>::to_string(socket_information_options::connected), csf_);
      assert::are_equal(socket_information_options::connected, enum_object<>::parse<socket_information_options>("connected"), csf_);
    }
    
    void test_method_(listening) {
      assert::are_equal(4, enum_object<>::to_int32(socket_information_options::listening), csf_);
      assert::are_equal("listening", enum_object<>::to_string(socket_information_options::listening), csf_);
      assert::are_equal(socket_information_options::listening, enum_object<>::parse<socket_information_options>("listening"), csf_);
    }
    
    void test_method_(use_only_overlapped_io) {
      assert::are_equal(8, enum_object<>::to_int32(socket_information_options::use_only_overlapped_io), csf_);
      assert::are_equal("use_only_overlapped_io", enum_object<>::to_string(socket_information_options::use_only_overlapped_io), csf_);
      assert::are_equal(socket_information_options::use_only_overlapped_io, enum_object<>::parse<socket_information_options>("use_only_overlapped_io"), csf_);
    }
  };
}
