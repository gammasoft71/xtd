#include <xtd/net/sockets/protocol_family>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(protocol_family_tests) {
  public:
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(protocol_family::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(protocol_family::unknown), csf_);
      assert::are_equal(protocol_family::unknown, enum_object<>::parse<protocol_family>("unknown"), csf_);
    }
    
    void test_method_(unspecified) {
      assert::are_equal(0, enum_object<>::to_int32(protocol_family::unspecified), csf_);
      assert::are_equal("unspecified", enum_object<>::to_string(protocol_family::unspecified), csf_);
      assert::are_equal(protocol_family::unspecified, enum_object<>::parse<protocol_family>("unspecified"), csf_);
    }
    
    void test_method_(unix) {
      assert::are_equal(1, enum_object<>::to_int32(protocol_family::unix), csf_);
      assert::are_equal("unix", enum_object<>::to_string(protocol_family::unix), csf_);
      assert::are_equal(protocol_family::unix, enum_object<>::parse<protocol_family>("unix"), csf_);
    }
    
    void test_method_(inter_network) {
      assert::are_equal(2, enum_object<>::to_int32(protocol_family::inter_network), csf_);
      assert::are_equal("inter_network", enum_object<>::to_string(protocol_family::inter_network), csf_);
      assert::are_equal(protocol_family::inter_network, enum_object<>::parse<protocol_family>("inter_network"), csf_);
    }
    
    void test_method_(imp_link) {
      assert::are_equal(3, enum_object<>::to_int32(protocol_family::imp_link), csf_);
      assert::are_equal("imp_link", enum_object<>::to_string(protocol_family::imp_link), csf_);
      assert::are_equal(protocol_family::imp_link, enum_object<>::parse<protocol_family>("imp_link"), csf_);
    }
    
    void test_method_(pup) {
      assert::are_equal(4, enum_object<>::to_int32(protocol_family::pup), csf_);
      assert::are_equal("pup", enum_object<>::to_string(protocol_family::pup), csf_);
      assert::are_equal(protocol_family::pup, enum_object<>::parse<protocol_family>("pup"), csf_);
    }
    
    void test_method_(chaos) {
      assert::are_equal(5, enum_object<>::to_int32(protocol_family::chaos), csf_);
      assert::are_equal("chaos", enum_object<>::to_string(protocol_family::chaos), csf_);
      assert::are_equal(protocol_family::chaos, enum_object<>::parse<protocol_family>("chaos"), csf_);
    }
    
    void test_method_(ns) {
      // Duplicate value with ipx
      assert::are_equal(6, enum_object<>::to_int32(protocol_family::ns), csf_);
      assert::are_equal("ipx", enum_object<>::to_string(protocol_family::ns), csf_);
      assert::are_equal(protocol_family::ns, enum_object<>::parse<protocol_family>("ipx"), csf_);
    }
    
    void test_method_(ipx) {
      assert::are_equal(6, enum_object<>::to_int32(protocol_family::ipx), csf_);
      assert::are_equal("ipx", enum_object<>::to_string(protocol_family::ipx), csf_);
      assert::are_equal(protocol_family::ipx, enum_object<>::parse<protocol_family>("ipx"), csf_);
    }
    
    void test_method_(iso) {
      assert::are_equal(7, enum_object<>::to_int32(protocol_family::iso), csf_);
      assert::are_equal("iso", enum_object<>::to_string(protocol_family::iso), csf_);
      assert::are_equal(protocol_family::iso, enum_object<>::parse<protocol_family>("iso"), csf_);
    }
    
    void test_method_(osi) {
      // Duplicate value with iso
      assert::are_equal(7, enum_object<>::to_int32(protocol_family::osi), csf_);
      assert::are_equal("iso", enum_object<>::to_string(protocol_family::osi), csf_);
      assert::are_equal(protocol_family::osi, enum_object<>::parse<protocol_family>("iso"), csf_);
    }
    
    void test_method_(ecma) {
      assert::are_equal(8, enum_object<>::to_int32(protocol_family::ecma), csf_);
      assert::are_equal("ecma", enum_object<>::to_string(protocol_family::ecma), csf_);
      assert::are_equal(protocol_family::ecma, enum_object<>::parse<protocol_family>("ecma"), csf_);
    }
    
    void test_method_(data_kit) {
      assert::are_equal(9, enum_object<>::to_int32(protocol_family::data_kit), csf_);
      assert::are_equal("data_kit", enum_object<>::to_string(protocol_family::data_kit), csf_);
      assert::are_equal(protocol_family::data_kit, enum_object<>::parse<protocol_family>("data_kit"), csf_);
    }
    
    void test_method_(ccitt) {
      assert::are_equal(10, enum_object<>::to_int32(protocol_family::ccitt), csf_);
      assert::are_equal("ccitt", enum_object<>::to_string(protocol_family::ccitt), csf_);
      assert::are_equal(protocol_family::ccitt, enum_object<>::parse<protocol_family>("ccitt"), csf_);
    }
    
    void test_method_(sna) {
      assert::are_equal(11, enum_object<>::to_int32(protocol_family::sna), csf_);
      assert::are_equal("sna", enum_object<>::to_string(protocol_family::sna), csf_);
      assert::are_equal(protocol_family::sna, enum_object<>::parse<protocol_family>("sna"), csf_);
    }
    
    void test_method_(dec_net) {
      assert::are_equal(12, enum_object<>::to_int32(protocol_family::dec_net), csf_);
      assert::are_equal("dec_net", enum_object<>::to_string(protocol_family::dec_net), csf_);
      assert::are_equal(protocol_family::dec_net, enum_object<>::parse<protocol_family>("dec_net"), csf_);
    }
    
    void test_method_(data_link) {
      assert::are_equal(13, enum_object<>::to_int32(protocol_family::data_link), csf_);
      assert::are_equal("data_link", enum_object<>::to_string(protocol_family::data_link), csf_);
      assert::are_equal(protocol_family::data_link, enum_object<>::parse<protocol_family>("data_link"), csf_);
    }
    
    void test_method_(lat) {
      assert::are_equal(14, enum_object<>::to_int32(protocol_family::lat), csf_);
      assert::are_equal("lat", enum_object<>::to_string(protocol_family::lat), csf_);
      assert::are_equal(protocol_family::lat, enum_object<>::parse<protocol_family>("lat"), csf_);
    }
    
    void test_method_(hyper_channel) {
      assert::are_equal(15, enum_object<>::to_int32(protocol_family::hyper_channel), csf_);
      assert::are_equal("hyper_channel", enum_object<>::to_string(protocol_family::hyper_channel), csf_);
      assert::are_equal(protocol_family::hyper_channel, enum_object<>::parse<protocol_family>("hyper_channel"), csf_);
    }
    
    void test_method_(apple_talk) {
      assert::are_equal(16, enum_object<>::to_int32(protocol_family::apple_talk), csf_);
      assert::are_equal("apple_talk", enum_object<>::to_string(protocol_family::apple_talk), csf_);
      assert::are_equal(protocol_family::apple_talk, enum_object<>::parse<protocol_family>("apple_talk"), csf_);
    }
    
    void test_method_(net_bios) {
      assert::are_equal(17, enum_object<>::to_int32(protocol_family::net_bios), csf_);
      assert::are_equal("net_bios", enum_object<>::to_string(protocol_family::net_bios), csf_);
      assert::are_equal(protocol_family::net_bios, enum_object<>::parse<protocol_family>("net_bios"), csf_);
    }
    
    void test_method_(voice_view) {
      assert::are_equal(18, enum_object<>::to_int32(protocol_family::voice_view), csf_);
      assert::are_equal("voice_view", enum_object<>::to_string(protocol_family::voice_view), csf_);
      assert::are_equal(protocol_family::voice_view, enum_object<>::parse<protocol_family>("voice_view"), csf_);
    }
    
    void test_method_(fire_fox) {
      assert::are_equal(19, enum_object<>::to_int32(protocol_family::fire_fox), csf_);
      assert::are_equal("fire_fox", enum_object<>::to_string(protocol_family::fire_fox), csf_);
      assert::are_equal(protocol_family::fire_fox, enum_object<>::parse<protocol_family>("fire_fox"), csf_);
    }
    
    void test_method_(banyan) {
      assert::are_equal(21, enum_object<>::to_int32(protocol_family::banyan), csf_);
      assert::are_equal("banyan", enum_object<>::to_string(protocol_family::banyan), csf_);
      assert::are_equal(protocol_family::banyan, enum_object<>::parse<protocol_family>("banyan"), csf_);
    }
    
    void test_method_(atm) {
      assert::are_equal(22, enum_object<>::to_int32(protocol_family::atm), csf_);
      assert::are_equal("atm", enum_object<>::to_string(protocol_family::atm), csf_);
      assert::are_equal(protocol_family::atm, enum_object<>::parse<protocol_family>("atm"), csf_);
    }
    
    void test_method_(inter_network_v6) {
      assert::are_equal(23, enum_object<>::to_int32(protocol_family::inter_network_v6), csf_);
      assert::are_equal("inter_network_v6", enum_object<>::to_string(protocol_family::inter_network_v6), csf_);
      assert::are_equal(protocol_family::inter_network_v6, enum_object<>::parse<protocol_family>("inter_network_v6"), csf_);
    }
    
    void test_method_(cluster) {
      assert::are_equal(24, enum_object<>::to_int32(protocol_family::cluster), csf_);
      assert::are_equal("cluster", enum_object<>::to_string(protocol_family::cluster), csf_);
      assert::are_equal(protocol_family::cluster, enum_object<>::parse<protocol_family>("cluster"), csf_);
    }
    
    void test_method_(ieee12844) {
      assert::are_equal(25, enum_object<>::to_int32(protocol_family::ieee12844), csf_);
      assert::are_equal("ieee12844", enum_object<>::to_string(protocol_family::ieee12844), csf_);
      assert::are_equal(protocol_family::ieee12844, enum_object<>::parse<protocol_family>("ieee12844"), csf_);
    }
    
    void test_method_(irda) {
      assert::are_equal(26, enum_object<>::to_int32(protocol_family::irda), csf_);
      assert::are_equal("irda", enum_object<>::to_string(protocol_family::irda), csf_);
      assert::are_equal(protocol_family::irda, enum_object<>::parse<protocol_family>("irda"), csf_);
    }
    
    void test_method_(network_designers) {
      assert::are_equal(28, enum_object<>::to_int32(protocol_family::network_designers), csf_);
      assert::are_equal("network_designers", enum_object<>::to_string(protocol_family::network_designers), csf_);
      assert::are_equal(protocol_family::network_designers, enum_object<>::parse<protocol_family>("network_designers"), csf_);
    }
    
    void test_method_(max) {
      assert::are_equal(29, enum_object<>::to_int32(protocol_family::max), csf_);
      assert::are_equal("max", enum_object<>::to_string(protocol_family::max), csf_);
      assert::are_equal(protocol_family::max, enum_object<>::parse<protocol_family>("max"), csf_);
    }
  };
}
