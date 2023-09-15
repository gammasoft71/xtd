#include <xtd/net/sockets/socket_option_name>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(socket_option_name_tests) {
  public:
    void test_method_(debug) {
      assert::are_equal(1, enum_object<>::to_int32(socket_option_name::debug), csf_);
      assert::are_equal("debug", enum_object<>::to_string(socket_option_name::debug), csf_);
      assert::are_equal(socket_option_name::debug, enum_object<>::parse<socket_option_name>("debug"), csf_);
    }
    
    void test_method_(accept_connection) {
      assert::are_equal(2, enum_object<>::to_int32(socket_option_name::accept_connection), csf_);
      assert::are_equal("accept_connection", enum_object<>::to_string(socket_option_name::accept_connection), csf_);
      assert::are_equal(socket_option_name::accept_connection, enum_object<>::parse<socket_option_name>("accept_connection"), csf_);
    }
    
    void test_method_(reuse_address) {
      assert::are_equal(4, enum_object<>::to_int32(socket_option_name::reuse_address), csf_);
      assert::are_equal("reuse_address", enum_object<>::to_string(socket_option_name::reuse_address), csf_);
      assert::are_equal(socket_option_name::reuse_address, enum_object<>::parse<socket_option_name>("reuse_address"), csf_);
    }
    
    void test_method_(keep_alive) {
      assert::are_equal(8, enum_object<>::to_int32(socket_option_name::keep_alive), csf_);
      assert::are_equal("keep_alive", enum_object<>::to_string(socket_option_name::keep_alive), csf_);
      assert::are_equal(socket_option_name::keep_alive, enum_object<>::parse<socket_option_name>("keep_alive"), csf_);
    }
    
    void test_method_(dont_route) {
      assert::are_equal(16, enum_object<>::to_int32(socket_option_name::dont_route), csf_);
      assert::are_equal("dont_route", enum_object<>::to_string(socket_option_name::dont_route), csf_);
      assert::are_equal(socket_option_name::dont_route, enum_object<>::parse<socket_option_name>("dont_route"), csf_);
    }
    
    void test_method_(broadcast) {
      assert::are_equal(32, enum_object<>::to_int32(socket_option_name::broadcast), csf_);
      assert::are_equal("broadcast", enum_object<>::to_string(socket_option_name::broadcast), csf_);
      assert::are_equal(socket_option_name::broadcast, enum_object<>::parse<socket_option_name>("broadcast"), csf_);
    }
    
    void test_method_(use_loopback) {
      assert::are_equal(64, enum_object<>::to_int32(socket_option_name::use_loopback), csf_);
      assert::are_equal("use_loopback", enum_object<>::to_string(socket_option_name::use_loopback), csf_);
      assert::are_equal(socket_option_name::use_loopback, enum_object<>::parse<socket_option_name>("use_loopback"), csf_);
    }
    
    void test_method_(linger) {
      assert::are_equal(128, enum_object<>::to_int32(socket_option_name::linger), csf_);
      assert::are_equal("linger", enum_object<>::to_string(socket_option_name::linger), csf_);
      assert::are_equal(socket_option_name::linger, enum_object<>::parse<socket_option_name>("linger"), csf_);
    }
    
    void test_method_(out_of_band_inline) {
      assert::are_equal(256, enum_object<>::to_int32(socket_option_name::out_of_band_inline), csf_);
      assert::are_equal("out_of_band_inline", enum_object<>::to_string(socket_option_name::out_of_band_inline), csf_);
      assert::are_equal(socket_option_name::out_of_band_inline, enum_object<>::parse<socket_option_name>("out_of_band_inline"), csf_);
    }
    
    void test_method_(dont_linger) {
      assert::are_equal(-129, enum_object<>::to_int32(socket_option_name::dont_linger), csf_);
      assert::are_equal("dont_linger", enum_object<>::to_string(socket_option_name::dont_linger), csf_);
      assert::are_equal(socket_option_name::dont_linger, enum_object<>::parse<socket_option_name>("dont_linger"), csf_);
    }
    
    void test_method_(exclusive_address_use) {
      assert::are_equal(-5, enum_object<>::to_int32(socket_option_name::exclusive_address_use), csf_);
      assert::are_equal("exclusive_address_use", enum_object<>::to_string(socket_option_name::exclusive_address_use), csf_);
      assert::are_equal(socket_option_name::exclusive_address_use, enum_object<>::parse<socket_option_name>("exclusive_address_use"), csf_);
    }
    
    void test_method_(send_buffer) {
      assert::are_equal(4097, enum_object<>::to_int32(socket_option_name::send_buffer), csf_);
      assert::are_equal("send_buffer", enum_object<>::to_string(socket_option_name::send_buffer), csf_);
      assert::are_equal(socket_option_name::send_buffer, enum_object<>::parse<socket_option_name>("send_buffer"), csf_);
    }
    
    void test_method_(receive_buffer) {
      assert::are_equal(4098, enum_object<>::to_int32(socket_option_name::receive_buffer), csf_);
      assert::are_equal("receive_buffer", enum_object<>::to_string(socket_option_name::receive_buffer), csf_);
      assert::are_equal(socket_option_name::receive_buffer, enum_object<>::parse<socket_option_name>("receive_buffer"), csf_);
    }
    
    void test_method_(send_low_water) {
      assert::are_equal(4099, enum_object<>::to_int32(socket_option_name::send_low_water), csf_);
      assert::are_equal("send_low_water", enum_object<>::to_string(socket_option_name::send_low_water), csf_);
      assert::are_equal(socket_option_name::send_low_water, enum_object<>::parse<socket_option_name>("send_low_water"), csf_);
    }
    
    void test_method_(receive_low_water) {
      assert::are_equal(4100, enum_object<>::to_int32(socket_option_name::receive_low_water), csf_);
      assert::are_equal("receive_low_water", enum_object<>::to_string(socket_option_name::receive_low_water), csf_);
      assert::are_equal(socket_option_name::receive_low_water, enum_object<>::parse<socket_option_name>("receive_low_water"), csf_);
    }
    
    void test_method_(send_timeout) {
      assert::are_equal(4101, enum_object<>::to_int32(socket_option_name::send_timeout), csf_);
      assert::are_equal("send_timeout", enum_object<>::to_string(socket_option_name::send_timeout), csf_);
      assert::are_equal(socket_option_name::send_timeout, enum_object<>::parse<socket_option_name>("send_timeout"), csf_);
    }
    
    void test_method_(receive_timeout) {
      assert::are_equal(4102, enum_object<>::to_int32(socket_option_name::receive_timeout), csf_);
      assert::are_equal("receive_timeout", enum_object<>::to_string(socket_option_name::receive_timeout), csf_);
      assert::are_equal(socket_option_name::receive_timeout, enum_object<>::parse<socket_option_name>("receive_timeout"), csf_);
    }
    
    void test_method_(error) {
      assert::are_equal(4103, enum_object<>::to_int32(socket_option_name::error), csf_);
      assert::are_equal("error", enum_object<>::to_string(socket_option_name::error), csf_);
      assert::are_equal(socket_option_name::error, enum_object<>::parse<socket_option_name>("error"), csf_);
    }
    
    void test_method_(type) {
      assert::are_equal(4104, enum_object<>::to_int32(socket_option_name::type), csf_);
      assert::are_equal("type", enum_object<>::to_string(socket_option_name::type), csf_);
      assert::are_equal(socket_option_name::type, enum_object<>::parse<socket_option_name>("type"), csf_);
    }
    
    void test_method_(max_connections) {
      assert::are_equal(2147483647, enum_object<>::to_int32(socket_option_name::max_connections), csf_);
      assert::are_equal("max_connections", enum_object<>::to_string(socket_option_name::max_connections), csf_);
      assert::are_equal(socket_option_name::max_connections, enum_object<>::parse<socket_option_name>("max_connections"), csf_);
    }
    
    void test_method_(ip_options) {
      // Duplicate value with debug
      assert::are_equal(1, enum_object<>::to_int32(socket_option_name::ip_options), csf_);
      assert::are_equal("debug", enum_object<>::to_string(socket_option_name::ip_options), csf_);
      assert::are_equal(socket_option_name::ip_options, enum_object<>::parse<socket_option_name>("debug"), csf_);
    }
    
    void test_method_(header_included) {
      // Duplicate value with accept_connection
      assert::are_equal(2, enum_object<>::to_int32(socket_option_name::header_included), csf_);
      assert::are_equal("accept_connection", enum_object<>::to_string(socket_option_name::header_included), csf_);
      assert::are_equal(socket_option_name::header_included, enum_object<>::parse<socket_option_name>("accept_connection"), csf_);
    }
    
    void test_method_(type_of_service) {
      assert::are_equal(3, enum_object<>::to_int32(socket_option_name::type_of_service), csf_);
      assert::are_equal("type_of_service", enum_object<>::to_string(socket_option_name::type_of_service), csf_);
      assert::are_equal(socket_option_name::type_of_service, enum_object<>::parse<socket_option_name>("type_of_service"), csf_);
    }
    
    void test_method_(ip_time_to_live) {
      // Duplicate value with reuse_address
      assert::are_equal(4, enum_object<>::to_int32(socket_option_name::ip_time_to_live), csf_);
      assert::are_equal("reuse_address", enum_object<>::to_string(socket_option_name::ip_time_to_live), csf_);
      assert::are_equal(socket_option_name::ip_time_to_live, enum_object<>::parse<socket_option_name>("reuse_address"), csf_);
    }
    
    void test_method_(multicast_interface) {
      assert::are_equal(9, enum_object<>::to_int32(socket_option_name::multicast_interface), csf_);
      assert::are_equal("multicast_interface", enum_object<>::to_string(socket_option_name::multicast_interface), csf_);
      assert::are_equal(socket_option_name::multicast_interface, enum_object<>::parse<socket_option_name>("multicast_interface"), csf_);
    }
    
    void test_method_(multicast_time_to_live) {
      assert::are_equal(10, enum_object<>::to_int32(socket_option_name::multicast_time_to_live), csf_);
      assert::are_equal("multicast_time_to_live", enum_object<>::to_string(socket_option_name::multicast_time_to_live), csf_);
      assert::are_equal(socket_option_name::multicast_time_to_live, enum_object<>::parse<socket_option_name>("multicast_time_to_live"), csf_);
    }
    
    void test_method_(multicast_loopback) {
      assert::are_equal(11, enum_object<>::to_int32(socket_option_name::multicast_loopback), csf_);
      assert::are_equal("multicast_loopback", enum_object<>::to_string(socket_option_name::multicast_loopback), csf_);
      assert::are_equal(socket_option_name::multicast_loopback, enum_object<>::parse<socket_option_name>("multicast_loopback"), csf_);
    }
    
    void test_method_(add_membership) {
      assert::are_equal(12, enum_object<>::to_int32(socket_option_name::add_membership), csf_);
      assert::are_equal("add_membership", enum_object<>::to_string(socket_option_name::add_membership), csf_);
      assert::are_equal(socket_option_name::add_membership, enum_object<>::parse<socket_option_name>("add_membership"), csf_);
    }
    
    void test_method_(drop_membership) {
      assert::are_equal(13, enum_object<>::to_int32(socket_option_name::drop_membership), csf_);
      assert::are_equal("drop_membership", enum_object<>::to_string(socket_option_name::drop_membership), csf_);
      assert::are_equal(socket_option_name::drop_membership, enum_object<>::parse<socket_option_name>("drop_membership"), csf_);
    }
    
    void test_method_(block_source) {
      assert::are_equal(17, enum_object<>::to_int32(socket_option_name::block_source), csf_);
      assert::are_equal("block_source", enum_object<>::to_string(socket_option_name::block_source), csf_);
      assert::are_equal(socket_option_name::block_source, enum_object<>::parse<socket_option_name>("block_source"), csf_);
    }
    
    void test_method_(unblock_source) {
      assert::are_equal(18, enum_object<>::to_int32(socket_option_name::unblock_source), csf_);
      assert::are_equal("unblock_source", enum_object<>::to_string(socket_option_name::unblock_source), csf_);
      assert::are_equal(socket_option_name::unblock_source, enum_object<>::parse<socket_option_name>("unblock_source"), csf_);
    }
    
    void test_method_(packet_information) {
      assert::are_equal(19, enum_object<>::to_int32(socket_option_name::packet_information), csf_);
      assert::are_equal("packet_information", enum_object<>::to_string(socket_option_name::packet_information), csf_);
      assert::are_equal(socket_option_name::packet_information, enum_object<>::parse<socket_option_name>("packet_information"), csf_);
    }
    
    void test_method_(hop_limit) {
      assert::are_equal(21, enum_object<>::to_int32(socket_option_name::hop_limit), csf_);
      assert::are_equal("hop_limit", enum_object<>::to_string(socket_option_name::hop_limit), csf_);
      assert::are_equal(socket_option_name::hop_limit, enum_object<>::parse<socket_option_name>("hop_limit"), csf_);
    }
    
    void test_method_(ip_protection_level) {
      assert::are_equal(23, enum_object<>::to_int32(socket_option_name::ip_protection_level), csf_);
      assert::are_equal("ip_protection_level", enum_object<>::to_string(socket_option_name::ip_protection_level), csf_);
      assert::are_equal(socket_option_name::ip_protection_level, enum_object<>::parse<socket_option_name>("ip_protection_level"), csf_);
    }
    
    void test_method_(ip_v6_only) {
      assert::are_equal(27, enum_object<>::to_int32(socket_option_name::ip_v6_only), csf_);
      assert::are_equal("ip_v6_only", enum_object<>::to_string(socket_option_name::ip_v6_only), csf_);
      assert::are_equal(socket_option_name::ip_v6_only, enum_object<>::parse<socket_option_name>("ip_v6_only"), csf_);
    }
    
    void test_method_(no_delay) {
      // Duplicate value with debug
      assert::are_equal(1, enum_object<>::to_int32(socket_option_name::no_delay), csf_);
      assert::are_equal("debug", enum_object<>::to_string(socket_option_name::no_delay), csf_);
      assert::are_equal(socket_option_name::no_delay, enum_object<>::parse<socket_option_name>("debug"), csf_);
    }
    
    void test_method_(bsd_urgent) {
      // Duplicate value with accept_connection
      assert::are_equal(2, enum_object<>::to_int32(socket_option_name::bsd_urgent), csf_);
      assert::are_equal("accept_connection", enum_object<>::to_string(socket_option_name::bsd_urgent), csf_);
      assert::are_equal(socket_option_name::bsd_urgent, enum_object<>::parse<socket_option_name>("accept_connection"), csf_);
    }
    
    void test_method_(expedited) {
      // Duplicate value with accept_connection
      assert::are_equal(2, enum_object<>::to_int32(socket_option_name::expedited), csf_);
      assert::are_equal("accept_connection", enum_object<>::to_string(socket_option_name::expedited), csf_);
      assert::are_equal(socket_option_name::expedited, enum_object<>::parse<socket_option_name>("accept_connection"), csf_);
    }
    
    void test_method_(no_checksum) {
      // Duplicate value with debug
      assert::are_equal(1, enum_object<>::to_int32(socket_option_name::no_checksum), csf_);
      assert::are_equal("debug", enum_object<>::to_string(socket_option_name::no_checksum), csf_);
      assert::are_equal(socket_option_name::no_checksum, enum_object<>::parse<socket_option_name>("debug"), csf_);
    }
    
    void test_method_(checksum_coverage) {
      assert::are_equal(20, enum_object<>::to_int32(socket_option_name::checksum_coverage), csf_);
      assert::are_equal("checksum_coverage", enum_object<>::to_string(socket_option_name::checksum_coverage), csf_);
      assert::are_equal(socket_option_name::checksum_coverage, enum_object<>::parse<socket_option_name>("checksum_coverage"), csf_);
    }
    
    void test_method_(update_accept_context) {
      assert::are_equal(28683, enum_object<>::to_int32(socket_option_name::update_accept_context), csf_);
      assert::are_equal("update_accept_context", enum_object<>::to_string(socket_option_name::update_accept_context), csf_);
      assert::are_equal(socket_option_name::update_accept_context, enum_object<>::parse<socket_option_name>("update_accept_context"), csf_);
    }
    
    void test_method_(update_connect_context) {
      assert::are_equal(28688, enum_object<>::to_int32(socket_option_name::update_connect_context), csf_);
      assert::are_equal("update_connect_context", enum_object<>::to_string(socket_option_name::update_connect_context), csf_);
      assert::are_equal(socket_option_name::update_connect_context, enum_object<>::parse<socket_option_name>("update_connect_context"), csf_);
    }
  };
}
