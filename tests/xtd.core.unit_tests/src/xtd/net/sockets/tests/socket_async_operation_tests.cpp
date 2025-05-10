#include <xtd/net/sockets/socket_async_operation>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(socket_async_operation_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(socket_async_operation::none));
      assert::are_equal("none", enum_object<>::to_string(socket_async_operation::none));
      assert::are_equal(socket_async_operation::none, enum_object<>::parse<socket_async_operation>("none"));
    }
    
    void test_method_(accept) {
      assert::are_equal(1, enum_object<>::to_int32(socket_async_operation::accept));
      assert::are_equal("accept", enum_object<>::to_string(socket_async_operation::accept));
      assert::are_equal(socket_async_operation::accept, enum_object<>::parse<socket_async_operation>("accept"));
    }
    
    void test_method_(connect) {
      assert::are_equal(2, enum_object<>::to_int32(socket_async_operation::connect));
      assert::are_equal("connect", enum_object<>::to_string(socket_async_operation::connect));
      assert::are_equal(socket_async_operation::connect, enum_object<>::parse<socket_async_operation>("connect"));
    }
    
    void test_method_(disconnect) {
      assert::are_equal(3, enum_object<>::to_int32(socket_async_operation::disconnect));
      assert::are_equal("disconnect", enum_object<>::to_string(socket_async_operation::disconnect));
      assert::are_equal(socket_async_operation::disconnect, enum_object<>::parse<socket_async_operation>("disconnect"));
    }
    
    void test_method_(receive) {
      assert::are_equal(4, enum_object<>::to_int32(socket_async_operation::receive));
      assert::are_equal("receive", enum_object<>::to_string(socket_async_operation::receive));
      assert::are_equal(socket_async_operation::receive, enum_object<>::parse<socket_async_operation>("receive"));
    }
    
    void test_method_(receive_from) {
      assert::are_equal(5, enum_object<>::to_int32(socket_async_operation::receive_from));
      assert::are_equal("receive_from", enum_object<>::to_string(socket_async_operation::receive_from));
      assert::are_equal(socket_async_operation::receive_from, enum_object<>::parse<socket_async_operation>("receive_from"));
    }
    
    void test_method_(receive_message_from) {
      assert::are_equal(6, enum_object<>::to_int32(socket_async_operation::receive_message_from));
      assert::are_equal("receive_message_from", enum_object<>::to_string(socket_async_operation::receive_message_from));
      assert::are_equal(socket_async_operation::receive_message_from, enum_object<>::parse<socket_async_operation>("receive_message_from"));
    }
    
    void test_method_(send) {
      assert::are_equal(7, enum_object<>::to_int32(socket_async_operation::send));
      assert::are_equal("send", enum_object<>::to_string(socket_async_operation::send));
      assert::are_equal(socket_async_operation::send, enum_object<>::parse<socket_async_operation>("send"));
    }
    
    void test_method_(send_packets) {
      assert::are_equal(8, enum_object<>::to_int32(socket_async_operation::send_packets));
      assert::are_equal("send_packets", enum_object<>::to_string(socket_async_operation::send_packets));
      assert::are_equal(socket_async_operation::send_packets, enum_object<>::parse<socket_async_operation>("send_packets"));
    }
    
    void test_method_(send_to) {
      assert::are_equal(9, enum_object<>::to_int32(socket_async_operation::send_to));
      assert::are_equal("send_to", enum_object<>::to_string(socket_async_operation::send_to));
      assert::are_equal(socket_async_operation::send_to, enum_object<>::parse<socket_async_operation>("send_to"));
    }
  };
}
