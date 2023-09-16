#include <xtd/net/sockets/io_control_code>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(io_control_code_tests) {
  public:
    void test_method_(enable_circular_queuing) {
      assert::are_equal(671088642ul, enum_object<>::to_uint64(io_control_code::enable_circular_queuing), csf_);
      assert::are_equal("enable_circular_queuing", enum_object<>::to_string(io_control_code::enable_circular_queuing), csf_);
      assert::are_equal(io_control_code::enable_circular_queuing, enum_object<>::parse<io_control_code>("enable_circular_queuing"), csf_);
    }
    
    void test_method_(flush) {
      assert::are_equal(671088644ul, enum_object<>::to_uint64(io_control_code::flush), csf_);
      assert::are_equal("flush", enum_object<>::to_string(io_control_code::flush), csf_);
      assert::are_equal(io_control_code::flush, enum_object<>::parse<io_control_code>("flush"), csf_);
    }
    
    void test_method_(address_list_change) {
      assert::are_equal(671088663ul, enum_object<>::to_uint64(io_control_code::address_list_change), csf_);
      assert::are_equal("address_list_change", enum_object<>::to_string(io_control_code::address_list_change), csf_);
      assert::are_equal(io_control_code::address_list_change, enum_object<>::parse<io_control_code>("address_list_change"), csf_);
    }
    
    void test_method_(data_to_read) {
      assert::are_equal(1074030207ul, enum_object<>::to_uint64(io_control_code::data_to_read), csf_);
      assert::are_equal("data_to_read", enum_object<>::to_string(io_control_code::data_to_read), csf_);
      assert::are_equal(io_control_code::data_to_read, enum_object<>::parse<io_control_code>("data_to_read"), csf_);
    }
    
    void test_method_(oob_data_read) {
      assert::are_equal(1074033415ul, enum_object<>::to_uint64(io_control_code::oob_data_read), csf_);
      assert::are_equal("oob_data_read", enum_object<>::to_string(io_control_code::oob_data_read), csf_);
      assert::are_equal(io_control_code::oob_data_read, enum_object<>::parse<io_control_code>("oob_data_read"), csf_);
    }
    
    void test_method_(get_broadcast_address) {
      assert::are_equal(1207959557ul, enum_object<>::to_uint64(io_control_code::get_broadcast_address), csf_);
      assert::are_equal("get_broadcast_address", enum_object<>::to_string(io_control_code::get_broadcast_address), csf_);
      assert::are_equal(io_control_code::get_broadcast_address, enum_object<>::parse<io_control_code>("get_broadcast_address"), csf_);
    }
    
    void test_method_(address_list_query) {
      assert::are_equal(1207959574ul, enum_object<>::to_uint64(io_control_code::address_list_query), csf_);
      assert::are_equal("address_list_query", enum_object<>::to_string(io_control_code::address_list_query), csf_);
      assert::are_equal(io_control_code::address_list_query, enum_object<>::parse<io_control_code>("address_list_query"), csf_);
    }
    
    void test_method_(query_target_pnp_handle) {
      assert::are_equal(1207959576ul, enum_object<>::to_uint64(io_control_code::query_target_pnp_handle), csf_);
      assert::are_equal("query_target_pnp_handle", enum_object<>::to_string(io_control_code::query_target_pnp_handle), csf_);
      assert::are_equal(io_control_code::query_target_pnp_handle, enum_object<>::parse<io_control_code>("query_target_pnp_handle"), csf_);
    }
    
    void test_method_(async_io) {
      assert::are_equal(2147772029ul, enum_object<>::to_uint64(io_control_code::async_io), csf_);
      assert::are_equal("async_io", enum_object<>::to_string(io_control_code::async_io), csf_);
      assert::are_equal(io_control_code::async_io, enum_object<>::parse<io_control_code>("async_io"), csf_);
    }
    
    void test_method_(non_blocking_io) {
      assert::are_equal(2147772030ul, enum_object<>::to_uint64(io_control_code::non_blocking_io), csf_);
      assert::are_equal("non_blocking_io", enum_object<>::to_string(io_control_code::non_blocking_io), csf_);
      assert::are_equal(io_control_code::non_blocking_io, enum_object<>::parse<io_control_code>("non_blocking_io"), csf_);
    }
    
    void test_method_(associate_handle) {
      assert::are_equal(2281701377ul, enum_object<>::to_uint64(io_control_code::associate_handle), csf_);
      assert::are_equal("associate_handle", enum_object<>::to_string(io_control_code::associate_handle), csf_);
      assert::are_equal(io_control_code::associate_handle, enum_object<>::parse<io_control_code>("associate_handle"), csf_);
    }
    
    void test_method_(multipoint_loopback) {
      assert::are_equal(2281701385ul, enum_object<>::to_uint64(io_control_code::multipoint_loopback), csf_);
      assert::are_equal("multipoint_loopback", enum_object<>::to_string(io_control_code::multipoint_loopback), csf_);
      assert::are_equal(io_control_code::multipoint_loopback, enum_object<>::parse<io_control_code>("multipoint_loopback"), csf_);
    }
    
    void test_method_(multicast_scope) {
      assert::are_equal(2281701386ul, enum_object<>::to_uint64(io_control_code::multicast_scope), csf_);
      assert::are_equal("multicast_scope", enum_object<>::to_string(io_control_code::multicast_scope), csf_);
      assert::are_equal(io_control_code::multicast_scope, enum_object<>::parse<io_control_code>("multicast_scope"), csf_);
    }
    
    void test_method_(set_qos) {
      assert::are_equal(2281701387ul, enum_object<>::to_uint64(io_control_code::set_qos), csf_);
      assert::are_equal("set_qos", enum_object<>::to_string(io_control_code::set_qos), csf_);
      assert::are_equal(io_control_code::set_qos, enum_object<>::parse<io_control_code>("set_qos"), csf_);
    }
    
    void test_method_(set_group_qos) {
      assert::are_equal(2281701388ul, enum_object<>::to_uint64(io_control_code::set_group_qos), csf_);
      assert::are_equal("set_group_qos", enum_object<>::to_string(io_control_code::set_group_qos), csf_);
      assert::are_equal(io_control_code::set_group_qos, enum_object<>::parse<io_control_code>("set_group_qos"), csf_);
    }
    
    void test_method_(routing_interface_change) {
      assert::are_equal(2281701397ul, enum_object<>::to_uint64(io_control_code::routing_interface_change), csf_);
      assert::are_equal("routing_interface_change", enum_object<>::to_string(io_control_code::routing_interface_change), csf_);
      assert::are_equal(io_control_code::routing_interface_change, enum_object<>::parse<io_control_code>("routing_interface_change"), csf_);
    }
    
    void test_method_(namespace_change) {
      assert::are_equal(2281701401ul, enum_object<>::to_uint64(io_control_code::namespace_change), csf_);
      assert::are_equal("namespace_change", enum_object<>::to_string(io_control_code::namespace_change), csf_);
      assert::are_equal(io_control_code::namespace_change, enum_object<>::parse<io_control_code>("namespace_change"), csf_);
    }
    
    void test_method_(receive_all) {
      assert::are_equal(2550136833ul, enum_object<>::to_uint64(io_control_code::receive_all), csf_);
      assert::are_equal("receive_all", enum_object<>::to_string(io_control_code::receive_all), csf_);
      assert::are_equal(io_control_code::receive_all, enum_object<>::parse<io_control_code>("receive_all"), csf_);
    }
    
    void test_method_(receive_all_multicast) {
      assert::are_equal(2550136834ul, enum_object<>::to_uint64(io_control_code::receive_all_multicast), csf_);
      assert::are_equal("receive_all_multicast", enum_object<>::to_string(io_control_code::receive_all_multicast), csf_);
      assert::are_equal(io_control_code::receive_all_multicast, enum_object<>::parse<io_control_code>("receive_all_multicast"), csf_);
    }
    
    void test_method_(receive_all_igmp_multicast) {
      assert::are_equal(2550136835ul, enum_object<>::to_uint64(io_control_code::receive_all_igmp_multicast), csf_);
      assert::are_equal("receive_all_igmp_multicast", enum_object<>::to_string(io_control_code::receive_all_igmp_multicast), csf_);
      assert::are_equal(io_control_code::receive_all_igmp_multicast, enum_object<>::parse<io_control_code>("receive_all_igmp_multicast"), csf_);
    }
    
    void test_method_(keep_alive_values) {
      assert::are_equal(2550136836ul, enum_object<>::to_uint64(io_control_code::keep_alive_values), csf_);
      assert::are_equal("keep_alive_values", enum_object<>::to_string(io_control_code::keep_alive_values), csf_);
      assert::are_equal(io_control_code::keep_alive_values, enum_object<>::parse<io_control_code>("keep_alive_values"), csf_);
    }
    
    void test_method_(absorb_router_alert) {
      assert::are_equal(2550136837ul, enum_object<>::to_uint64(io_control_code::absorb_router_alert), csf_);
      assert::are_equal("absorb_router_alert", enum_object<>::to_string(io_control_code::absorb_router_alert), csf_);
      assert::are_equal(io_control_code::absorb_router_alert, enum_object<>::parse<io_control_code>("absorb_router_alert"), csf_);
    }
    
    void test_method_(unicast_interface) {
      assert::are_equal(2550136838ul, enum_object<>::to_uint64(io_control_code::unicast_interface), csf_);
      assert::are_equal("unicast_interface", enum_object<>::to_string(io_control_code::unicast_interface), csf_);
      assert::are_equal(io_control_code::unicast_interface, enum_object<>::parse<io_control_code>("unicast_interface"), csf_);
    }
    
    void test_method_(limit_broadcasts) {
      assert::are_equal(2550136839ul, enum_object<>::to_uint64(io_control_code::limit_broadcasts), csf_);
      assert::are_equal("limit_broadcasts", enum_object<>::to_string(io_control_code::limit_broadcasts), csf_);
      assert::are_equal(io_control_code::limit_broadcasts, enum_object<>::parse<io_control_code>("limit_broadcasts"), csf_);
    }
    
    void test_method_(bind_to_interface) {
      assert::are_equal(2550136840ul, enum_object<>::to_uint64(io_control_code::bind_to_interface), csf_);
      assert::are_equal("bind_to_interface", enum_object<>::to_string(io_control_code::bind_to_interface), csf_);
      assert::are_equal(io_control_code::bind_to_interface, enum_object<>::parse<io_control_code>("bind_to_interface"), csf_);
    }
    
    void test_method_(multicast_interface) {
      assert::are_equal(2550136841ul, enum_object<>::to_uint64(io_control_code::multicast_interface), csf_);
      assert::are_equal("multicast_interface", enum_object<>::to_string(io_control_code::multicast_interface), csf_);
      assert::are_equal(io_control_code::multicast_interface, enum_object<>::parse<io_control_code>("multicast_interface"), csf_);
    }
    
    void test_method_(add_multicast_group_on_interface) {
      assert::are_equal(2550136842ul, enum_object<>::to_uint64(io_control_code::add_multicast_group_on_interface), csf_);
      assert::are_equal("add_multicast_group_on_interface", enum_object<>::to_string(io_control_code::add_multicast_group_on_interface), csf_);
      assert::are_equal(io_control_code::add_multicast_group_on_interface, enum_object<>::parse<io_control_code>("add_multicast_group_on_interface"), csf_);
    }
    
    void test_method_(delete_multicast_group_from_interface) {
      assert::are_equal(2550136843ul, enum_object<>::to_uint64(io_control_code::delete_multicast_group_from_interface), csf_);
      assert::are_equal("delete_multicast_group_from_interface", enum_object<>::to_string(io_control_code::delete_multicast_group_from_interface), csf_);
      assert::are_equal(io_control_code::delete_multicast_group_from_interface, enum_object<>::parse<io_control_code>("delete_multicast_group_from_interface"), csf_);
    }
    
    void test_method_(get_extension_function_pointer) {
      assert::are_equal(3355443206ul, enum_object<>::to_uint64(io_control_code::get_extension_function_pointer), csf_);
      assert::are_equal("get_extension_function_pointer", enum_object<>::to_string(io_control_code::get_extension_function_pointer), csf_);
      assert::are_equal(io_control_code::get_extension_function_pointer, enum_object<>::parse<io_control_code>("get_extension_function_pointer"), csf_);
    }
    
    void test_method_(get_qos) {
      assert::are_equal(3355443207ul, enum_object<>::to_uint64(io_control_code::get_qos), csf_);
      assert::are_equal("get_qos", enum_object<>::to_string(io_control_code::get_qos), csf_);
      assert::are_equal(io_control_code::get_qos, enum_object<>::parse<io_control_code>("get_qos"), csf_);
    }
    
    void test_method_(get_group_qos) {
      assert::are_equal(3355443208ul, enum_object<>::to_uint64(io_control_code::get_group_qos), csf_);
      assert::are_equal("get_group_qos", enum_object<>::to_string(io_control_code::get_group_qos), csf_);
      assert::are_equal(io_control_code::get_group_qos, enum_object<>::parse<io_control_code>("get_group_qos"), csf_);
    }
    
    void test_method_(translate_handle) {
      assert::are_equal(3355443213ul, enum_object<>::to_uint64(io_control_code::translate_handle), csf_);
      assert::are_equal("translate_handle", enum_object<>::to_string(io_control_code::translate_handle), csf_);
      assert::are_equal(io_control_code::translate_handle, enum_object<>::parse<io_control_code>("translate_handle"), csf_);
    }
    
    void test_method_(routing_interface_query) {
      assert::are_equal(3355443220ul, enum_object<>::to_uint64(io_control_code::routing_interface_query), csf_);
      assert::are_equal("routing_interface_query", enum_object<>::to_string(io_control_code::routing_interface_query), csf_);
      assert::are_equal(io_control_code::routing_interface_query, enum_object<>::parse<io_control_code>("routing_interface_query"), csf_);
    }
    
    void test_method_(address_list_sort) {
      assert::are_equal(3355443225ul, enum_object<>::to_uint64(io_control_code::address_list_sort), csf_);
      assert::are_equal("address_list_sort", enum_object<>::to_string(io_control_code::address_list_sort), csf_);
      assert::are_equal(io_control_code::address_list_sort, enum_object<>::parse<io_control_code>("address_list_sort"), csf_);
    }
  };
}
