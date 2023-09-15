#include <xtd/net/sockets/socket_error>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(socket_error_tests) {
  public:
    void test_method_(sock_error) {
      assert::are_equal(-1, enum_object<>::to_int32(socket_error::sock_error), csf_);
      assert::are_equal("sock_error", enum_object<>::to_string(socket_error::sock_error), csf_);
      assert::are_equal(socket_error::sock_error, enum_object<>::parse<socket_error>("sock_error"), csf_);
    }
    
    void test_method_(success) {
      assert::are_equal(0, enum_object<>::to_int32(socket_error::success), csf_);
      assert::are_equal("success", enum_object<>::to_string(socket_error::success), csf_);
      assert::are_equal(socket_error::success, enum_object<>::parse<socket_error>("success"), csf_);
    }
    
    void test_method_(operation_aborted) {
      assert::are_equal(995, enum_object<>::to_int32(socket_error::operation_aborted), csf_);
      assert::are_equal("operation_aborted", enum_object<>::to_string(socket_error::operation_aborted), csf_);
      assert::are_equal(socket_error::operation_aborted, enum_object<>::parse<socket_error>("operation_aborted"), csf_);
    }
    
    void test_method_(io_pending) {
      assert::are_equal(997, enum_object<>::to_int32(socket_error::io_pending), csf_);
      assert::are_equal("io_pending", enum_object<>::to_string(socket_error::io_pending), csf_);
      assert::are_equal(socket_error::io_pending, enum_object<>::parse<socket_error>("io_pending"), csf_);
    }
    
    void test_method_(interrupted) {
      assert::are_equal(10004, enum_object<>::to_int32(socket_error::interrupted), csf_);
      assert::are_equal("interrupted", enum_object<>::to_string(socket_error::interrupted), csf_);
      assert::are_equal(socket_error::interrupted, enum_object<>::parse<socket_error>("interrupted"), csf_);
    }
    
    void test_method_(access_denied) {
      assert::are_equal(10013, enum_object<>::to_int32(socket_error::access_denied), csf_);
      assert::are_equal("access_denied", enum_object<>::to_string(socket_error::access_denied), csf_);
      assert::are_equal(socket_error::access_denied, enum_object<>::parse<socket_error>("access_denied"), csf_);
    }
    
    void test_method_(fault) {
      assert::are_equal(10014, enum_object<>::to_int32(socket_error::fault), csf_);
      assert::are_equal("fault", enum_object<>::to_string(socket_error::fault), csf_);
      assert::are_equal(socket_error::fault, enum_object<>::parse<socket_error>("fault"), csf_);
    }
    
    void test_method_(invalid_argument) {
      assert::are_equal(10022, enum_object<>::to_int32(socket_error::invalid_argument), csf_);
      assert::are_equal("invalid_argument", enum_object<>::to_string(socket_error::invalid_argument), csf_);
      assert::are_equal(socket_error::invalid_argument, enum_object<>::parse<socket_error>("invalid_argument"), csf_);
    }
    
    void test_method_(too_many_open_sockets) {
      assert::are_equal(10024, enum_object<>::to_int32(socket_error::too_many_open_sockets), csf_);
      assert::are_equal("too_many_open_sockets", enum_object<>::to_string(socket_error::too_many_open_sockets), csf_);
      assert::are_equal(socket_error::too_many_open_sockets, enum_object<>::parse<socket_error>("too_many_open_sockets"), csf_);
    }
    
    void test_method_(would_block) {
      assert::are_equal(10035, enum_object<>::to_int32(socket_error::would_block), csf_);
      assert::are_equal("would_block", enum_object<>::to_string(socket_error::would_block), csf_);
      assert::are_equal(socket_error::would_block, enum_object<>::parse<socket_error>("would_block"), csf_);
    }
    
    void test_method_(in_progress) {
      assert::are_equal(10036, enum_object<>::to_int32(socket_error::in_progress), csf_);
      assert::are_equal("in_progress", enum_object<>::to_string(socket_error::in_progress), csf_);
      assert::are_equal(socket_error::in_progress, enum_object<>::parse<socket_error>("in_progress"), csf_);
    }
    
    void test_method_(already_in_progress) {
      assert::are_equal(10037, enum_object<>::to_int32(socket_error::already_in_progress), csf_);
      assert::are_equal("already_in_progress", enum_object<>::to_string(socket_error::already_in_progress), csf_);
      assert::are_equal(socket_error::already_in_progress, enum_object<>::parse<socket_error>("already_in_progress"), csf_);
    }
    
    void test_method_(not_socket) {
      assert::are_equal(10038, enum_object<>::to_int32(socket_error::not_socket), csf_);
      assert::are_equal("not_socket", enum_object<>::to_string(socket_error::not_socket), csf_);
      assert::are_equal(socket_error::not_socket, enum_object<>::parse<socket_error>("not_socket"), csf_);
    }
    
    void test_method_(destination_address_required) {
      assert::are_equal(10039, enum_object<>::to_int32(socket_error::destination_address_required), csf_);
      assert::are_equal("destination_address_required", enum_object<>::to_string(socket_error::destination_address_required), csf_);
      assert::are_equal(socket_error::destination_address_required, enum_object<>::parse<socket_error>("destination_address_required"), csf_);
    }
    
    void test_method_(message_size) {
      assert::are_equal(10040, enum_object<>::to_int32(socket_error::message_size), csf_);
      assert::are_equal("message_size", enum_object<>::to_string(socket_error::message_size), csf_);
      assert::are_equal(socket_error::message_size, enum_object<>::parse<socket_error>("message_size"), csf_);
    }
    
    void test_method_(protocol_type) {
      assert::are_equal(10041, enum_object<>::to_int32(socket_error::protocol_type), csf_);
      assert::are_equal("protocol_type", enum_object<>::to_string(socket_error::protocol_type), csf_);
      assert::are_equal(socket_error::protocol_type, enum_object<>::parse<socket_error>("protocol_type"), csf_);
    }
    
    void test_method_(protocol_option) {
      assert::are_equal(10042, enum_object<>::to_int32(socket_error::protocol_option), csf_);
      assert::are_equal("protocol_option", enum_object<>::to_string(socket_error::protocol_option), csf_);
      assert::are_equal(socket_error::protocol_option, enum_object<>::parse<socket_error>("protocol_option"), csf_);
    }
    
    void test_method_(protocol_not_supported) {
      assert::are_equal(10043, enum_object<>::to_int32(socket_error::protocol_not_supported), csf_);
      assert::are_equal("protocol_not_supported", enum_object<>::to_string(socket_error::protocol_not_supported), csf_);
      assert::are_equal(socket_error::protocol_not_supported, enum_object<>::parse<socket_error>("protocol_not_supported"), csf_);
    }
    
    void test_method_(socket_not_supported) {
      assert::are_equal(10044, enum_object<>::to_int32(socket_error::socket_not_supported), csf_);
      assert::are_equal("socket_not_supported", enum_object<>::to_string(socket_error::socket_not_supported), csf_);
      assert::are_equal(socket_error::socket_not_supported, enum_object<>::parse<socket_error>("socket_not_supported"), csf_);
    }
    
    void test_method_(operation_not_supported) {
      assert::are_equal(10045, enum_object<>::to_int32(socket_error::operation_not_supported), csf_);
      assert::are_equal("operation_not_supported", enum_object<>::to_string(socket_error::operation_not_supported), csf_);
      assert::are_equal(socket_error::operation_not_supported, enum_object<>::parse<socket_error>("operation_not_supported"), csf_);
    }
    
    void test_method_(protocol_family_not_supported) {
      assert::are_equal(10046, enum_object<>::to_int32(socket_error::protocol_family_not_supported), csf_);
      assert::are_equal("protocol_family_not_supported", enum_object<>::to_string(socket_error::protocol_family_not_supported), csf_);
      assert::are_equal(socket_error::protocol_family_not_supported, enum_object<>::parse<socket_error>("protocol_family_not_supported"), csf_);
    }
    
    void test_method_(address_family_not_supported) {
      assert::are_equal(10047, enum_object<>::to_int32(socket_error::address_family_not_supported), csf_);
      assert::are_equal("address_family_not_supported", enum_object<>::to_string(socket_error::address_family_not_supported), csf_);
      assert::are_equal(socket_error::address_family_not_supported, enum_object<>::parse<socket_error>("address_family_not_supported"), csf_);
    }
    
    void test_method_(address_already_in_use) {
      assert::are_equal(10048, enum_object<>::to_int32(socket_error::address_already_in_use), csf_);
      assert::are_equal("address_already_in_use", enum_object<>::to_string(socket_error::address_already_in_use), csf_);
      assert::are_equal(socket_error::address_already_in_use, enum_object<>::parse<socket_error>("address_already_in_use"), csf_);
    }
    
    void test_method_(address_not_available) {
      assert::are_equal(10049, enum_object<>::to_int32(socket_error::address_not_available), csf_);
      assert::are_equal("address_not_available", enum_object<>::to_string(socket_error::address_not_available), csf_);
      assert::are_equal(socket_error::address_not_available, enum_object<>::parse<socket_error>("address_not_available"), csf_);
    }
    
    void test_method_(network_down) {
      assert::are_equal(10050, enum_object<>::to_int32(socket_error::network_down), csf_);
      assert::are_equal("network_down", enum_object<>::to_string(socket_error::network_down), csf_);
      assert::are_equal(socket_error::network_down, enum_object<>::parse<socket_error>("network_down"), csf_);
    }
    
    void test_method_(network_unreachable) {
      assert::are_equal(10051, enum_object<>::to_int32(socket_error::network_unreachable), csf_);
      assert::are_equal("network_unreachable", enum_object<>::to_string(socket_error::network_unreachable), csf_);
      assert::are_equal(socket_error::network_unreachable, enum_object<>::parse<socket_error>("network_unreachable"), csf_);
    }
    
    void test_method_(network_reset) {
      assert::are_equal(10052, enum_object<>::to_int32(socket_error::network_reset), csf_);
      assert::are_equal("network_reset", enum_object<>::to_string(socket_error::network_reset), csf_);
      assert::are_equal(socket_error::network_reset, enum_object<>::parse<socket_error>("network_reset"), csf_);
    }
    
    void test_method_(connection_aborted) {
      assert::are_equal(10053, enum_object<>::to_int32(socket_error::connection_aborted), csf_);
      assert::are_equal("connection_aborted", enum_object<>::to_string(socket_error::connection_aborted), csf_);
      assert::are_equal(socket_error::connection_aborted, enum_object<>::parse<socket_error>("connection_aborted"), csf_);
    }
    
    void test_method_(connection_reset) {
      assert::are_equal(10054, enum_object<>::to_int32(socket_error::connection_reset), csf_);
      assert::are_equal("connection_reset", enum_object<>::to_string(socket_error::connection_reset), csf_);
      assert::are_equal(socket_error::connection_reset, enum_object<>::parse<socket_error>("connection_reset"), csf_);
    }
    
    void test_method_(no_buffer_space_available) {
      assert::are_equal(10055, enum_object<>::to_int32(socket_error::no_buffer_space_available), csf_);
      assert::are_equal("no_buffer_space_available", enum_object<>::to_string(socket_error::no_buffer_space_available), csf_);
      assert::are_equal(socket_error::no_buffer_space_available, enum_object<>::parse<socket_error>("no_buffer_space_available"), csf_);
    }
    
    void test_method_(is_connected) {
      assert::are_equal(10056, enum_object<>::to_int32(socket_error::is_connected), csf_);
      assert::are_equal("is_connected", enum_object<>::to_string(socket_error::is_connected), csf_);
      assert::are_equal(socket_error::is_connected, enum_object<>::parse<socket_error>("is_connected"), csf_);
    }
    
    void test_method_(not_connected) {
      assert::are_equal(10057, enum_object<>::to_int32(socket_error::not_connected), csf_);
      assert::are_equal("not_connected", enum_object<>::to_string(socket_error::not_connected), csf_);
      assert::are_equal(socket_error::not_connected, enum_object<>::parse<socket_error>("not_connected"), csf_);
    }
    
    void test_method_(shutdown) {
      assert::are_equal(10058, enum_object<>::to_int32(socket_error::shutdown), csf_);
      assert::are_equal("shutdown", enum_object<>::to_string(socket_error::shutdown), csf_);
      assert::are_equal(socket_error::shutdown, enum_object<>::parse<socket_error>("shutdown"), csf_);
    }
    
    void test_method_(timed_out) {
      assert::are_equal(10060, enum_object<>::to_int32(socket_error::timed_out), csf_);
      assert::are_equal("timed_out", enum_object<>::to_string(socket_error::timed_out), csf_);
      assert::are_equal(socket_error::timed_out, enum_object<>::parse<socket_error>("timed_out"), csf_);
    }
    
    void test_method_(connection_refused) {
      assert::are_equal(10061, enum_object<>::to_int32(socket_error::connection_refused), csf_);
      assert::are_equal("connection_refused", enum_object<>::to_string(socket_error::connection_refused), csf_);
      assert::are_equal(socket_error::connection_refused, enum_object<>::parse<socket_error>("connection_refused"), csf_);
    }
    
    void test_method_(host_down) {
      assert::are_equal(10064, enum_object<>::to_int32(socket_error::host_down), csf_);
      assert::are_equal("host_down", enum_object<>::to_string(socket_error::host_down), csf_);
      assert::are_equal(socket_error::host_down, enum_object<>::parse<socket_error>("host_down"), csf_);
    }
    
    void test_method_(host_unreachable) {
      assert::are_equal(10065, enum_object<>::to_int32(socket_error::host_unreachable), csf_);
      assert::are_equal("host_unreachable", enum_object<>::to_string(socket_error::host_unreachable), csf_);
      assert::are_equal(socket_error::host_unreachable, enum_object<>::parse<socket_error>("host_unreachable"), csf_);
    }
    
    void test_method_(process_limit) {
      assert::are_equal(10067, enum_object<>::to_int32(socket_error::process_limit), csf_);
      assert::are_equal("process_limit", enum_object<>::to_string(socket_error::process_limit), csf_);
      assert::are_equal(socket_error::process_limit, enum_object<>::parse<socket_error>("process_limit"), csf_);
    }
    
    void test_method_(system_not_ready) {
      assert::are_equal(10091, enum_object<>::to_int32(socket_error::system_not_ready), csf_);
      assert::are_equal("system_not_ready", enum_object<>::to_string(socket_error::system_not_ready), csf_);
      assert::are_equal(socket_error::system_not_ready, enum_object<>::parse<socket_error>("system_not_ready"), csf_);
    }
    
    void test_method_(version_not_supported) {
      assert::are_equal(10092, enum_object<>::to_int32(socket_error::version_not_supported), csf_);
      assert::are_equal("version_not_supported", enum_object<>::to_string(socket_error::version_not_supported), csf_);
      assert::are_equal(socket_error::version_not_supported, enum_object<>::parse<socket_error>("version_not_supported"), csf_);
    }
    
    void test_method_(not_initialized) {
      assert::are_equal(10093, enum_object<>::to_int32(socket_error::not_initialized), csf_);
      assert::are_equal("not_initialized", enum_object<>::to_string(socket_error::not_initialized), csf_);
      assert::are_equal(socket_error::not_initialized, enum_object<>::parse<socket_error>("not_initialized"), csf_);
    }
    
    void test_method_(disconnecting) {
      assert::are_equal(10101, enum_object<>::to_int32(socket_error::disconnecting), csf_);
      assert::are_equal("disconnecting", enum_object<>::to_string(socket_error::disconnecting), csf_);
      assert::are_equal(socket_error::disconnecting, enum_object<>::parse<socket_error>("disconnecting"), csf_);
    }
    
    void test_method_(type_not_found) {
      assert::are_equal(10109, enum_object<>::to_int32(socket_error::type_not_found), csf_);
      assert::are_equal("type_not_found", enum_object<>::to_string(socket_error::type_not_found), csf_);
      assert::are_equal(socket_error::type_not_found, enum_object<>::parse<socket_error>("type_not_found"), csf_);
    }
    
    void test_method_(host_not_found) {
      assert::are_equal(11001, enum_object<>::to_int32(socket_error::host_not_found), csf_);
      assert::are_equal("host_not_found", enum_object<>::to_string(socket_error::host_not_found), csf_);
      assert::are_equal(socket_error::host_not_found, enum_object<>::parse<socket_error>("host_not_found"), csf_);
    }
    
    void test_method_(try_again) {
      assert::are_equal(11002, enum_object<>::to_int32(socket_error::try_again), csf_);
      assert::are_equal("try_again", enum_object<>::to_string(socket_error::try_again), csf_);
      assert::are_equal(socket_error::try_again, enum_object<>::parse<socket_error>("try_again"), csf_);
    }
    
    void test_method_(no_recovery) {
      assert::are_equal(11003, enum_object<>::to_int32(socket_error::no_recovery), csf_);
      assert::are_equal("no_recovery", enum_object<>::to_string(socket_error::no_recovery), csf_);
      assert::are_equal(socket_error::no_recovery, enum_object<>::parse<socket_error>("no_recovery"), csf_);
    }
    
    void test_method_(no_data) {
      assert::are_equal(11004, enum_object<>::to_int32(socket_error::no_data), csf_);
      assert::are_equal("no_data", enum_object<>::to_string(socket_error::no_data), csf_);
      assert::are_equal(socket_error::no_data, enum_object<>::parse<socket_error>("no_data"), csf_);
    }
  };
}
