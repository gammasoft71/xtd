/// @file
/// @brief Contains xtd::net::sockets::address_family enum.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../enum.h"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Specifies the addressing scheme that an instance of the xtd::net::sockets::socket class can use.
      /// @code
      /// enum class address_family
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/address_family> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class address_family {
        /// @brief Unknown address family.
        unknown = -1,
        /// @brief Unspecified address family.
        unspecified = 0,
        /// @brief Unix local to host address.
        unix = 1,
        /// @brief Address for IP version 4.
        inter_network = 2,
        /// @brief ARPANET IMP address.
        imp_link = 3,
        /// @brief Address for PUP protocols.
        pup = 4,
        /// @brief Address for MIT CHAOS protocols.
        chaos = 5,
        /// @brief Address for Xerox NS protocols.
        ns = 6,
        /// @brief IPX or SPX address.
        ipx = 6,
        /// @brief Address for ISO protocols.
        iso = 7,
        /// @brief Address for OSI protocols.
        osi = 7,
        /// @brief European Computer Manufacturers Association (ECMA) address.
        ecma = 8,
        /// @brief Address for Datakit protocols.
        data_kit = 9,
        /// @brief Addresses for CCITT protocols, such as X.25.
        ccitt = 10,
        /// @brief IBM SNA address.
        sna = 11,
        /// @brief DECnet address.
        dec_net = 12,
        /// @brief Direct data-link interface address.
        data_link = 13,
        /// @brief LAT address.
        lat = 14,
        /// @brief NSC Hyperchannel address.
        hyper_channel = 15,
        /// @brief AppleTalk address.
        apple_talk = 16,
        /// @brief NetBios address.
        net_bios = 17,
        /// @brief VoiceView address.
        voice_view = 18,
        /// @brief FireFox address.
        fire_fox = 19,
        /// @brief Banyan address.
        banyan = 21,
        /// @brief Native ATM services address.
        atm = 22,
        /// @brief Address for IP version 6.
        inter_network_v6 = 23,
        /// @brief Address for Microsoft cluster products.
        cluster = 24,
        /// @brief IEEE 1284.4 workgroup address.
        ieee12844 = 25,
        /// @brief IrDA address.
        irda = 26,
        /// @brief Address for Network Designers OSI gateway-enabled protocols.
        network_designers = 28,
        /// @brief MAX address.
        max = 29,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::address_family> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::address_family> {{xtd::net::sockets::address_family::unknown, "unknown"}, {xtd::net::sockets::address_family::unspecified, "unspecified"}, {xtd::net::sockets::address_family::unix, "unix"}, {xtd::net::sockets::address_family::inter_network, "inter_network"}, {xtd::net::sockets::address_family::imp_link, "imp_link"}, {xtd::net::sockets::address_family::pup, "pup"}, {xtd::net::sockets::address_family::chaos, "chaos"}, /*{xtd::net::sockets::address_family::ns, "ns"},*/ {xtd::net::sockets::address_family::ipx, "ipx"}, {xtd::net::sockets::address_family::iso, "iso"}, /*{xtd::net::sockets::address_family::osi, "osi"},*/ {xtd::net::sockets::address_family::ecma, "ecma"}, {xtd::net::sockets::address_family::data_kit, "data_kit"}, {xtd::net::sockets::address_family::ccitt, "ccitt"}, {xtd::net::sockets::address_family::sna, "sna"}, {xtd::net::sockets::address_family::dec_net, "dec_net"}, {xtd::net::sockets::address_family::data_link, "data_link"}, {xtd::net::sockets::address_family::lat, "lat"}, {xtd::net::sockets::address_family::hyper_channel, "hyper_channel"}, {xtd::net::sockets::address_family::apple_talk, "apple_talk"}, {xtd::net::sockets::address_family::net_bios, "net_bios"}, {xtd::net::sockets::address_family::voice_view, "voice_view"}, {xtd::net::sockets::address_family::fire_fox, "fire_fox"}, {xtd::net::sockets::address_family::banyan, "banyan"}, {xtd::net::sockets::address_family::atm, "atm"}, {xtd::net::sockets::address_family::inter_network_v6, "inter_network_v6"}, {xtd::net::sockets::address_family::cluster, "cluster"}, {xtd::net::sockets::address_family::ieee12844, "ieee12844"}, {xtd::net::sockets::address_family::irda, "irda"}, {xtd::net::sockets::address_family::network_designers, "network_designers"}, {xtd::net::sockets::address_family::max, "max"}};}
};
/// @endcond
