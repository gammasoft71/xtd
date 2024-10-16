#include <xtd/net/sockets/socket_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(socket_type_tests) {
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(socket_type::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(socket_type::unknown));
      assert::are_equal(socket_type::unknown, enum_object<>::parse<socket_type>("unknown"));
    }
    
    void test_method_(stream) {
      assert::are_equal(1, enum_object<>::to_int32(socket_type::stream));
      assert::are_equal("stream", enum_object<>::to_string(socket_type::stream));
      assert::are_equal(socket_type::stream, enum_object<>::parse<socket_type>("stream"));
    }
    
    void test_method_(dgram) {
      assert::are_equal(2, enum_object<>::to_int32(socket_type::dgram));
      assert::are_equal("dgram", enum_object<>::to_string(socket_type::dgram));
      assert::are_equal(socket_type::dgram, enum_object<>::parse<socket_type>("dgram"));
    }
    
    void test_method_(raw) {
      assert::are_equal(3, enum_object<>::to_int32(socket_type::raw));
      assert::are_equal("raw", enum_object<>::to_string(socket_type::raw));
      assert::are_equal(socket_type::raw, enum_object<>::parse<socket_type>("raw"));
    }
    
    void test_method_(rdm) {
      assert::are_equal(4, enum_object<>::to_int32(socket_type::rdm));
      assert::are_equal("rdm", enum_object<>::to_string(socket_type::rdm));
      assert::are_equal(socket_type::rdm, enum_object<>::parse<socket_type>("rdm"));
    }
    
    void test_method_(seqpacket) {
      assert::are_equal(5, enum_object<>::to_int32(socket_type::seqpacket));
      assert::are_equal("seqpacket", enum_object<>::to_string(socket_type::seqpacket));
      assert::are_equal(socket_type::seqpacket, enum_object<>::parse<socket_type>("seqpacket"));
    }
  };
}
