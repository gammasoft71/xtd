#include <xtd/net/sockets/protocol_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(protocol_type_tests) {
    auto test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(protocol_type::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(protocol_type::unknown));
      assert::are_equal(protocol_type::unknown, enum_object<>::parse<protocol_type>("unknown"));
    }
    
    auto test_method_(ip_v6_hop_by_hop_options) {
      // Duplicate value with ip
      assert::are_equal(0, enum_object<>::to_int32(protocol_type::ip_v6_hop_by_hop_options));
      assert::are_equal("ip", enum_object<>::to_string(protocol_type::ip_v6_hop_by_hop_options));
      assert::are_equal(protocol_type::ip_v6_hop_by_hop_options, enum_object<>::parse<protocol_type>("ip"));
    }
    
    auto test_method_(unspecified) {
      // Duplicate value with ip
      assert::are_equal(0, enum_object<>::to_int32(protocol_type::unspecified));
      assert::are_equal("ip", enum_object<>::to_string(protocol_type::unspecified));
      assert::are_equal(protocol_type::unspecified, enum_object<>::parse<protocol_type>("ip"));
    }
    
    auto test_method_(ip) {
      assert::are_equal(0, enum_object<>::to_int32(protocol_type::ip));
      assert::are_equal("ip", enum_object<>::to_string(protocol_type::ip));
      assert::are_equal(protocol_type::ip, enum_object<>::parse<protocol_type>("ip"));
    }
    
    auto test_method_(icmp) {
      assert::are_equal(1, enum_object<>::to_int32(protocol_type::icmp));
      assert::are_equal("icmp", enum_object<>::to_string(protocol_type::icmp));
      assert::are_equal(protocol_type::icmp, enum_object<>::parse<protocol_type>("icmp"));
    }
    
    auto test_method_(igmp) {
      assert::are_equal(2, enum_object<>::to_int32(protocol_type::igmp));
      assert::are_equal("igmp", enum_object<>::to_string(protocol_type::igmp));
      assert::are_equal(protocol_type::igmp, enum_object<>::parse<protocol_type>("igmp"));
    }
    
    auto test_method_(ggp) {
      assert::are_equal(3, enum_object<>::to_int32(protocol_type::ggp));
      assert::are_equal("ggp", enum_object<>::to_string(protocol_type::ggp));
      assert::are_equal(protocol_type::ggp, enum_object<>::parse<protocol_type>("ggp"));
    }
    
    auto test_method_(ip_v4) {
      assert::are_equal(4, enum_object<>::to_int32(protocol_type::ip_v4));
      assert::are_equal("ip_v4", enum_object<>::to_string(protocol_type::ip_v4));
      assert::are_equal(protocol_type::ip_v4, enum_object<>::parse<protocol_type>("ip_v4"));
    }
    
    auto test_method_(tcp) {
      assert::are_equal(6, enum_object<>::to_int32(protocol_type::tcp));
      assert::are_equal("tcp", enum_object<>::to_string(protocol_type::tcp));
      assert::are_equal(protocol_type::tcp, enum_object<>::parse<protocol_type>("tcp"));
    }
    
    auto test_method_(pup) {
      assert::are_equal(12, enum_object<>::to_int32(protocol_type::pup));
      assert::are_equal("pup", enum_object<>::to_string(protocol_type::pup));
      assert::are_equal(protocol_type::pup, enum_object<>::parse<protocol_type>("pup"));
    }
    
    auto test_method_(udp) {
      assert::are_equal(17, enum_object<>::to_int32(protocol_type::udp));
      assert::are_equal("udp", enum_object<>::to_string(protocol_type::udp));
      assert::are_equal(protocol_type::udp, enum_object<>::parse<protocol_type>("udp"));
    }
    
    auto test_method_(idp) {
      assert::are_equal(22, enum_object<>::to_int32(protocol_type::idp));
      assert::are_equal("idp", enum_object<>::to_string(protocol_type::idp));
      assert::are_equal(protocol_type::idp, enum_object<>::parse<protocol_type>("idp"));
    }
    
    auto test_method_(ip_v6) {
      assert::are_equal(41, enum_object<>::to_int32(protocol_type::ip_v6));
      assert::are_equal("ip_v6", enum_object<>::to_string(protocol_type::ip_v6));
      assert::are_equal(protocol_type::ip_v6, enum_object<>::parse<protocol_type>("ip_v6"));
    }
    
    auto test_method_(ip_v6_routing_header) {
      assert::are_equal(43, enum_object<>::to_int32(protocol_type::ip_v6_routing_header));
      assert::are_equal("ip_v6_routing_header", enum_object<>::to_string(protocol_type::ip_v6_routing_header));
      assert::are_equal(protocol_type::ip_v6_routing_header, enum_object<>::parse<protocol_type>("ip_v6_routing_header"));
    }
    
    auto test_method_(ip_v6_fragment_header) {
      assert::are_equal(44, enum_object<>::to_int32(protocol_type::ip_v6_fragment_header));
      assert::are_equal("ip_v6_fragment_header", enum_object<>::to_string(protocol_type::ip_v6_fragment_header));
      assert::are_equal(protocol_type::ip_v6_fragment_header, enum_object<>::parse<protocol_type>("ip_v6_fragment_header"));
    }
    
    auto test_method_(ip_sec_encapsulating_security_payload) {
      assert::are_equal(50, enum_object<>::to_int32(protocol_type::ip_sec_encapsulating_security_payload));
      assert::are_equal("ip_sec_encapsulating_security_payload", enum_object<>::to_string(protocol_type::ip_sec_encapsulating_security_payload));
      assert::are_equal(protocol_type::ip_sec_encapsulating_security_payload, enum_object<>::parse<protocol_type>("ip_sec_encapsulating_security_payload"));
    }
    
    auto test_method_(ip_sec_authentication_header) {
      assert::are_equal(51, enum_object<>::to_int32(protocol_type::ip_sec_authentication_header));
      assert::are_equal("ip_sec_authentication_header", enum_object<>::to_string(protocol_type::ip_sec_authentication_header));
      assert::are_equal(protocol_type::ip_sec_authentication_header, enum_object<>::parse<protocol_type>("ip_sec_authentication_header"));
    }
    
    auto test_method_(icmp_v6) {
      assert::are_equal(58, enum_object<>::to_int32(protocol_type::icmp_v6));
      assert::are_equal("icmp_v6", enum_object<>::to_string(protocol_type::icmp_v6));
      assert::are_equal(protocol_type::icmp_v6, enum_object<>::parse<protocol_type>("icmp_v6"));
    }
    
    auto test_method_(ip_v6_no_next_header) {
      assert::are_equal(59, enum_object<>::to_int32(protocol_type::ip_v6_no_next_header));
      assert::are_equal("ip_v6_no_next_header", enum_object<>::to_string(protocol_type::ip_v6_no_next_header));
      assert::are_equal(protocol_type::ip_v6_no_next_header, enum_object<>::parse<protocol_type>("ip_v6_no_next_header"));
    }
    
    auto test_method_(ip_v6_destination_options) {
      assert::are_equal(60, enum_object<>::to_int32(protocol_type::ip_v6_destination_options));
      assert::are_equal("ip_v6_destination_options", enum_object<>::to_string(protocol_type::ip_v6_destination_options));
      assert::are_equal(protocol_type::ip_v6_destination_options, enum_object<>::parse<protocol_type>("ip_v6_destination_options"));
    }
    
    auto test_method_(nd) {
      assert::are_equal(77, enum_object<>::to_int32(protocol_type::nd));
      assert::are_equal("nd", enum_object<>::to_string(protocol_type::nd));
      assert::are_equal(protocol_type::nd, enum_object<>::parse<protocol_type>("nd"));
    }
    
    auto test_method_(raw) {
      assert::are_equal(255, enum_object<>::to_int32(protocol_type::raw));
      assert::are_equal("raw", enum_object<>::to_string(protocol_type::raw));
      assert::are_equal(protocol_type::raw, enum_object<>::parse<protocol_type>("raw"));
    }
    
    auto test_method_(ipx) {
      assert::are_equal(1000, enum_object<>::to_int32(protocol_type::ipx));
      assert::are_equal("ipx", enum_object<>::to_string(protocol_type::ipx));
      assert::are_equal(protocol_type::ipx, enum_object<>::parse<protocol_type>("ipx"));
    }
    
    auto test_method_(spx) {
      assert::are_equal(1256, enum_object<>::to_int32(protocol_type::spx));
      assert::are_equal("spx", enum_object<>::to_string(protocol_type::spx));
      assert::are_equal(protocol_type::spx, enum_object<>::parse<protocol_type>("spx"));
    }
    
    auto test_method_(spx_2) {
      assert::are_equal(1257, enum_object<>::to_int32(protocol_type::spx_2));
      assert::are_equal("spx_2", enum_object<>::to_string(protocol_type::spx_2));
      assert::are_equal(protocol_type::spx_2, enum_object<>::parse<protocol_type>("spx_2"));
    }
  };
}
