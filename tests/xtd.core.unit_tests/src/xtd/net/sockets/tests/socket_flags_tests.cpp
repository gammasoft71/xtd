#include <xtd/net/sockets/socket_flags>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(socket_flags_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(socket_flags::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(socket_flags::none), csf_);
      assert::are_equal(socket_flags::none, enum_object<>::parse<socket_flags>("none"), csf_);
    }
    
    void test_method_(out_of_band) {
      assert::are_equal(1, enum_object<>::to_int32(socket_flags::out_of_band), csf_);
      assert::are_equal("out_of_band", enum_object<>::to_string(socket_flags::out_of_band), csf_);
      assert::are_equal(socket_flags::out_of_band, enum_object<>::parse<socket_flags>("out_of_band"), csf_);
    }
    
    void test_method_(peek) {
      assert::are_equal(2, enum_object<>::to_int32(socket_flags::peek), csf_);
      assert::are_equal("peek", enum_object<>::to_string(socket_flags::peek), csf_);
      assert::are_equal(socket_flags::peek, enum_object<>::parse<socket_flags>("peek"), csf_);
    }
    
    void test_method_(dont_route) {
      assert::are_equal(4, enum_object<>::to_int32(socket_flags::dont_route), csf_);
      assert::are_equal("dont_route", enum_object<>::to_string(socket_flags::dont_route), csf_);
      assert::are_equal(socket_flags::dont_route, enum_object<>::parse<socket_flags>("dont_route"), csf_);
    }
    
    void test_method_(max_io_vector_length) {
      assert::are_equal(16, enum_object<>::to_int32(socket_flags::max_io_vector_length), csf_);
      assert::are_equal("max_io_vector_length", enum_object<>::to_string(socket_flags::max_io_vector_length), csf_);
      assert::are_equal(socket_flags::max_io_vector_length, enum_object<>::parse<socket_flags>("max_io_vector_length"), csf_);
    }
    
    void test_method_(truncated) {
      assert::are_equal(256, enum_object<>::to_int32(socket_flags::truncated), csf_);
      assert::are_equal("truncated", enum_object<>::to_string(socket_flags::truncated), csf_);
      assert::are_equal(socket_flags::truncated, enum_object<>::parse<socket_flags>("truncated"), csf_);
    }
    
    void test_method_(control_data_truncated) {
      assert::are_equal(512, enum_object<>::to_int32(socket_flags::control_data_truncated), csf_);
      assert::are_equal("control_data_truncated", enum_object<>::to_string(socket_flags::control_data_truncated), csf_);
      assert::are_equal(socket_flags::control_data_truncated, enum_object<>::parse<socket_flags>("control_data_truncated"), csf_);
    }
    
    void test_method_(broadcast) {
      assert::are_equal(1024, enum_object<>::to_int32(socket_flags::broadcast), csf_);
      assert::are_equal("broadcast", enum_object<>::to_string(socket_flags::broadcast), csf_);
      assert::are_equal(socket_flags::broadcast, enum_object<>::parse<socket_flags>("broadcast"), csf_);
    }
    
    void test_method_(multicast) {
      assert::are_equal(2048, enum_object<>::to_int32(socket_flags::multicast), csf_);
      assert::are_equal("multicast", enum_object<>::to_string(socket_flags::multicast), csf_);
      assert::are_equal(socket_flags::multicast, enum_object<>::parse<socket_flags>("multicast"), csf_);
    }
    
    void test_method_(partial) {
      assert::are_equal(32768, enum_object<>::to_int32(socket_flags::partial), csf_);
      assert::are_equal("partial", enum_object<>::to_string(socket_flags::partial), csf_);
      assert::are_equal(socket_flags::partial, enum_object<>::parse<socket_flags>("partial"), csf_);
    }
  };
}
