/// @file
/// @brief Contains xtd::net::sockets::address_family enum.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../ustring.h"

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

      inline std::ostream& operator<<(std::ostream& os, address_family value) {return os << to_string(value, {{address_family::unknown, "unknown"}, {address_family::unspecified, "unspecified"}, {address_family::unix, "unix"}, {address_family::inter_network, "inter_network"}, {address_family::imp_link, "imp_link"}, {address_family::pup, "pup"}, {address_family::chaos, "chaos"}, {address_family::ns, "ns"}, {address_family::ipx, "ipx"}, {address_family::iso, "iso"}, {address_family::osi, "osi"}, {address_family::ecma, "ecma"}, {address_family::data_kit, "data_kit"}, {address_family::ccitt, "ccitt"}, {address_family::sna, "sna"}, {address_family::dec_net, "dec_net"}, {address_family::data_link, "data_link"}, {address_family::lat, "lat"}, {address_family::hyper_channel, "hyper_channel"}, {address_family::apple_talk, "apple_talk"}, {address_family::net_bios, "net_bios"}, {address_family::voice_view, "voice_view"}, {address_family::fire_fox, "fire_fox"}, {address_family::banyan, "banyan"}, {address_family::atm, "atm"}, {address_family::inter_network_v6, "inter_network_v6"}, {address_family::cluster, "cluster"}, {address_family::ieee12844, "ieee12844"}, {address_family::irda, "irda"}, {address_family::network_designers, "network_designers"}, {address_family::max, "max"}});}
      inline std::wostream& operator<<(std::wostream& os, address_family value) {return os << to_string(value, {{address_family::unknown, L"unknown"}, {address_family::unspecified, L"unspecified"}, {address_family::unix, L"unix"}, {address_family::inter_network, L"inter_network"}, {address_family::imp_link, L"imp_link"}, {address_family::pup, L"pup"}, {address_family::chaos, L"chaos"}, {address_family::ns, L"ns"}, {address_family::ipx, L"ipx"}, {address_family::iso, L"iso"}, {address_family::osi, L"osi"}, {address_family::ecma, L"ecma"}, {address_family::data_kit, L"data_kit"}, {address_family::ccitt, L"ccitt"}, {address_family::sna, L"sna"}, {address_family::dec_net, L"dec_net"}, {address_family::data_link, L"data_link"}, {address_family::lat, L"lat"}, {address_family::hyper_channel, L"hyper_channel"}, {address_family::apple_talk, L"apple_talk"}, {address_family::net_bios, L"net_bios"}, {address_family::voice_view, L"voice_view"}, {address_family::fire_fox, L"fire_fox"}, {address_family::banyan, L"banyan"}, {address_family::atm, L"atm"}, {address_family::inter_network_v6, L"inter_network_v6"}, {address_family::cluster, L"cluster"}, {address_family::ieee12844, L"ieee12844"}, {address_family::irda, L"irda"}, {address_family::network_designers, L"network_designers"}, {address_family::max, L"max"}});}
    }
  }
}
