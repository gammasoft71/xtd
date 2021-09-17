#include <xtd/net/end_point.h>
#include <xtd/not_implemented_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class tend_point : public end_point {
  public:
    tend_point() : end_point(sockets::address_family::inter_network) {}
    tend_point(sockets::address_family address_family) : end_point(address_family) {}
  };
  
  class test_class_(test_end_point) {
  public:
    void test_method_(create_end_point_with_address_family_unknown) {
      tend_point ep(address_family::unknown);
      assert::are_equal(address_family::unknown, ep.address_family(), csf_);
      assert::are_equal("unknown", ep.to_string(), csf_);
    }
    
    void test_method_(create_end_point_with_address_family_unspecified) {
      tend_point ep(address_family::unspecified);
      assert::are_equal(address_family::unspecified, ep.address_family(), csf_);
      assert::are_equal("unspecified", ep.to_string(), csf_);
    }
    
    void test_method_(create_end_point_with_address_family_unix) {
      tend_point ep(address_family::unix);
      assert::are_equal(address_family::unix, ep.address_family(), csf_);
      assert::are_equal("unix", ep.to_string(), csf_);
    }

    void test_method_(create_end_point_with_address_family_inter_network) {
      tend_point ep(address_family::inter_network);
      assert::are_equal(address_family::inter_network, ep.address_family(), csf_);
      assert::are_equal("inter_network", ep.to_string(), csf_);
    }
    
    void test_method_(create_end_point_with_address_family_sna) {
      tend_point ep(address_family::sna);
      assert::are_equal(address_family::sna, ep.address_family(), csf_);
      assert::are_equal("sna", ep.to_string(), csf_);
    }
    
    void test_method_(create_end_point_with_address_family_dec_net) {
      tend_point ep(address_family::dec_net);
      assert::are_equal(address_family::dec_net, ep.address_family(), csf_);
      assert::are_equal("dec_net", ep.to_string(), csf_);
    }
    
    void test_method_(create_end_point_with_address_family_apple_talk) {
      tend_point ep(address_family::apple_talk);
      assert::are_equal(address_family::apple_talk, ep.address_family(), csf_);
      assert::are_equal("apple_talk", ep.to_string(), csf_);
    }

    void test_method_(create_end_point_with_address_family_inter_network_v6) {
      tend_point ep(address_family::inter_network_v6);
      assert::are_equal(address_family::inter_network_v6, ep.address_family(), csf_);
      assert::are_equal("inter_network_v6", ep.to_string(), csf_);
    }

    void test_method_(create_end_point_with_address_family_max) {
      tend_point ep(address_family::max);
      assert::are_equal(address_family::max, ep.address_family(), csf_);
      assert::are_equal("max", ep.to_string(), csf_);
    }
    
    void test_method_(end_point_create) {
      tend_point ep;
      assert::throws<not_implemented_exception>([&]{ep.create(socket_address(address_family::inter_network));}, csf_);
    }
    
    void test_method_(end_point_serialize) {
      tend_point ep;
      assert::throws<not_implemented_exception>([&]{ep.serialize();}, csf_);
    }
  };
}
