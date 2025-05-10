#include <xtd/net/sockets/address_family>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(address_family_tests) {
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(address_family::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(address_family::unknown));
      assert::are_equal(address_family::unknown, enum_object<>::parse<address_family>("unknown"));
    }
    
    void test_method_(unspecified) {
      assert::are_equal(0, enum_object<>::to_int32(address_family::unspecified));
      assert::are_equal("unspecified", enum_object<>::to_string(address_family::unspecified));
      assert::are_equal(address_family::unspecified, enum_object<>::parse<address_family>("unspecified"));
    }
    
    void test_method_(unix) {
      assert::are_equal(1, enum_object<>::to_int32(address_family::unix));
      assert::are_equal("unix", enum_object<>::to_string(address_family::unix));
      assert::are_equal(address_family::unix, enum_object<>::parse<address_family>("unix"));
    }
    
    void test_method_(inter_network) {
      assert::are_equal(2, enum_object<>::to_int32(address_family::inter_network));
      assert::are_equal("inter_network", enum_object<>::to_string(address_family::inter_network));
      assert::are_equal(address_family::inter_network, enum_object<>::parse<address_family>("inter_network"));
    }
    
    void test_method_(imp_link) {
      assert::are_equal(3, enum_object<>::to_int32(address_family::imp_link));
      assert::are_equal("imp_link", enum_object<>::to_string(address_family::imp_link));
      assert::are_equal(address_family::imp_link, enum_object<>::parse<address_family>("imp_link"));
    }
    
    void test_method_(pup) {
      assert::are_equal(4, enum_object<>::to_int32(address_family::pup));
      assert::are_equal("pup", enum_object<>::to_string(address_family::pup));
      assert::are_equal(address_family::pup, enum_object<>::parse<address_family>("pup"));
    }
    
    void test_method_(chaos) {
      assert::are_equal(5, enum_object<>::to_int32(address_family::chaos));
      assert::are_equal("chaos", enum_object<>::to_string(address_family::chaos));
      assert::are_equal(address_family::chaos, enum_object<>::parse<address_family>("chaos"));
    }
    
    void test_method_(ns) {
      // Duplicate value with ipx
      assert::are_equal(6, enum_object<>::to_int32(address_family::ns));
      assert::are_equal("ipx", enum_object<>::to_string(address_family::ns));
      assert::are_equal(address_family::ns, enum_object<>::parse<address_family>("ipx"));
    }
    
    void test_method_(ipx) {
      assert::are_equal(6, enum_object<>::to_int32(address_family::ipx));
      assert::are_equal("ipx", enum_object<>::to_string(address_family::ipx));
      assert::are_equal(address_family::ipx, enum_object<>::parse<address_family>("ipx"));
    }
    
    void test_method_(iso) {
      assert::are_equal(7, enum_object<>::to_int32(address_family::iso));
      assert::are_equal("iso", enum_object<>::to_string(address_family::iso));
      assert::are_equal(address_family::iso, enum_object<>::parse<address_family>("iso"));
    }
    
    void test_method_(osi) {
      // Duplicate value with iso
      assert::are_equal(7, enum_object<>::to_int32(address_family::osi));
      assert::are_equal("iso", enum_object<>::to_string(address_family::osi));
      assert::are_equal(address_family::osi, enum_object<>::parse<address_family>("iso"));
    }
    
    void test_method_(ecma) {
      assert::are_equal(8, enum_object<>::to_int32(address_family::ecma));
      assert::are_equal("ecma", enum_object<>::to_string(address_family::ecma));
      assert::are_equal(address_family::ecma, enum_object<>::parse<address_family>("ecma"));
    }
    
    void test_method_(data_kit) {
      assert::are_equal(9, enum_object<>::to_int32(address_family::data_kit));
      assert::are_equal("data_kit", enum_object<>::to_string(address_family::data_kit));
      assert::are_equal(address_family::data_kit, enum_object<>::parse<address_family>("data_kit"));
    }
    
    void test_method_(ccitt) {
      assert::are_equal(10, enum_object<>::to_int32(address_family::ccitt));
      assert::are_equal("ccitt", enum_object<>::to_string(address_family::ccitt));
      assert::are_equal(address_family::ccitt, enum_object<>::parse<address_family>("ccitt"));
    }
    
    void test_method_(sna) {
      assert::are_equal(11, enum_object<>::to_int32(address_family::sna));
      assert::are_equal("sna", enum_object<>::to_string(address_family::sna));
      assert::are_equal(address_family::sna, enum_object<>::parse<address_family>("sna"));
    }
    
    void test_method_(dec_net) {
      assert::are_equal(12, enum_object<>::to_int32(address_family::dec_net));
      assert::are_equal("dec_net", enum_object<>::to_string(address_family::dec_net));
      assert::are_equal(address_family::dec_net, enum_object<>::parse<address_family>("dec_net"));
    }
    
    void test_method_(data_link) {
      assert::are_equal(13, enum_object<>::to_int32(address_family::data_link));
      assert::are_equal("data_link", enum_object<>::to_string(address_family::data_link));
      assert::are_equal(address_family::data_link, enum_object<>::parse<address_family>("data_link"));
    }
    
    void test_method_(lat) {
      assert::are_equal(14, enum_object<>::to_int32(address_family::lat));
      assert::are_equal("lat", enum_object<>::to_string(address_family::lat));
      assert::are_equal(address_family::lat, enum_object<>::parse<address_family>("lat"));
    }
    
    void test_method_(hyper_channel) {
      assert::are_equal(15, enum_object<>::to_int32(address_family::hyper_channel));
      assert::are_equal("hyper_channel", enum_object<>::to_string(address_family::hyper_channel));
      assert::are_equal(address_family::hyper_channel, enum_object<>::parse<address_family>("hyper_channel"));
    }
    
    void test_method_(apple_talk) {
      assert::are_equal(16, enum_object<>::to_int32(address_family::apple_talk));
      assert::are_equal("apple_talk", enum_object<>::to_string(address_family::apple_talk));
      assert::are_equal(address_family::apple_talk, enum_object<>::parse<address_family>("apple_talk"));
    }
    
    void test_method_(net_bios) {
      assert::are_equal(17, enum_object<>::to_int32(address_family::net_bios));
      assert::are_equal("net_bios", enum_object<>::to_string(address_family::net_bios));
      assert::are_equal(address_family::net_bios, enum_object<>::parse<address_family>("net_bios"));
    }
    
    void test_method_(voice_view) {
      assert::are_equal(18, enum_object<>::to_int32(address_family::voice_view));
      assert::are_equal("voice_view", enum_object<>::to_string(address_family::voice_view));
      assert::are_equal(address_family::voice_view, enum_object<>::parse<address_family>("voice_view"));
    }
    
    void test_method_(fire_fox) {
      assert::are_equal(19, enum_object<>::to_int32(address_family::fire_fox));
      assert::are_equal("fire_fox", enum_object<>::to_string(address_family::fire_fox));
      assert::are_equal(address_family::fire_fox, enum_object<>::parse<address_family>("fire_fox"));
    }
    
    void test_method_(banyan) {
      assert::are_equal(21, enum_object<>::to_int32(address_family::banyan));
      assert::are_equal("banyan", enum_object<>::to_string(address_family::banyan));
      assert::are_equal(address_family::banyan, enum_object<>::parse<address_family>("banyan"));
    }
    
    void test_method_(atm) {
      assert::are_equal(22, enum_object<>::to_int32(address_family::atm));
      assert::are_equal("atm", enum_object<>::to_string(address_family::atm));
      assert::are_equal(address_family::atm, enum_object<>::parse<address_family>("atm"));
    }
    
    void test_method_(inter_network_v6) {
      assert::are_equal(23, enum_object<>::to_int32(address_family::inter_network_v6));
      assert::are_equal("inter_network_v6", enum_object<>::to_string(address_family::inter_network_v6));
      assert::are_equal(address_family::inter_network_v6, enum_object<>::parse<address_family>("inter_network_v6"));
    }
    
    void test_method_(cluster) {
      assert::are_equal(24, enum_object<>::to_int32(address_family::cluster));
      assert::are_equal("cluster", enum_object<>::to_string(address_family::cluster));
      assert::are_equal(address_family::cluster, enum_object<>::parse<address_family>("cluster"));
    }
    
    void test_method_(ieee12844) {
      assert::are_equal(25, enum_object<>::to_int32(address_family::ieee12844));
      assert::are_equal("ieee12844", enum_object<>::to_string(address_family::ieee12844));
      assert::are_equal(address_family::ieee12844, enum_object<>::parse<address_family>("ieee12844"));
    }
    
    void test_method_(irda) {
      assert::are_equal(26, enum_object<>::to_int32(address_family::irda));
      assert::are_equal("irda", enum_object<>::to_string(address_family::irda));
      assert::are_equal(address_family::irda, enum_object<>::parse<address_family>("irda"));
    }
    
    void test_method_(network_designers) {
      assert::are_equal(28, enum_object<>::to_int32(address_family::network_designers));
      assert::are_equal("network_designers", enum_object<>::to_string(address_family::network_designers));
      assert::are_equal(address_family::network_designers, enum_object<>::parse<address_family>("network_designers"));
    }
    
    void test_method_(max) {
      assert::are_equal(29, enum_object<>::to_int32(address_family::max));
      assert::are_equal("max", enum_object<>::to_string(address_family::max));
      assert::are_equal(address_family::max, enum_object<>::parse<address_family>("max"));
    }
  };
}
