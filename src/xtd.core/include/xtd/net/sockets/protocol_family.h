/// @file
/// @brief Contains xtd::net::sockets::protocol_family enum.
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
      /// @brief Specifies the type of protocol that an instance of the xtd::net::sockets::socket class can use.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class protocol_family {
        /// @brief Unknown protocol.
        unknown = -1,
        /// @brief Unspecified protocol.
        unspecified = 0,
        /// @brief Unix local to host protocol.
        unix = 1,
        /// @brief IP version 4 protocol.
        inter_network = 2,
        /// @brief ARPANET IMP protocol.
        imp_link = 3,
        /// @brief PUP protocols.
        pup = 4,
        /// @brief MIT CHAOS protocols.
        chaos = 5,
        /// @brief Xerox NS protocols.
        ns = 6,
        /// @brief IPX or SPX protocol.
        ipx = 6,
        /// @brief ISO protocols.
        iso = 7,
        /// @brief OSI protocols.
        osi = 7,
        /// @brief European Computer Manufacturers Association (ECMA) protocol.
        ecma = 8,
        /// @brief Datakit protocols.
        data_kit = 9,
        /// @brief CCITT protocols, such as X.25.
        ccitt = 10,
        /// @brief IBM SNA protocol.
        sna = 11,
        /// @brief DECnet protocol.
        dec_net = 12,
        /// @brief Direct data-link interface protocol.
        data_link = 13,
        /// @brief LAT protocol.
        lat = 14,
        /// @brief NSC Hyperchannel protocol.
        hyper_channel = 15,
        /// @brief AppleTalk protocol.
        apple_talk = 16,
        /// @brief NetBios protocol.
        net_bios = 17,
        /// @brief VoiceView protocol.
        voice_view = 18,
        /// @brief FireFox protocol.
        fire_fox = 19,
        /// @brief Banyan protocol.
        banyan = 21,
        /// @brief Native ATM services protocol.
        atm = 22,
        /// @brief IP version 6 protocol.
        inter_network_v6 = 23,
        /// @brief Microsoft cluster products protocol.
        cluster = 24,
        /// @brief IEEE 1284.4 workgroup protocol.
        ieee12844 = 25,
        /// @brief IrDA protocol.
        irda = 26,
        /// @brief Network Designers OSI gateway-enabled protocol.
        network_designers = 28,
        /// @brief MAX protocol.
        max = 29,
      };

      inline std::ostream& operator<<(std::ostream& os, protocol_family value) {return os << to_string(value, {{protocol_family::unknown, "unknown"}, {protocol_family::unspecified, "unspecified"}, {protocol_family::unix, "unix"}, {protocol_family::inter_network, "inter_network"}, {protocol_family::imp_link, "imp_link"}, {protocol_family::pup, "pup"}, {protocol_family::chaos, "chaos"}, {protocol_family::ns, "ns"}, {protocol_family::ipx, "ipx"}, {protocol_family::iso, "iso"}, {protocol_family::osi, "osi"}, {protocol_family::ecma, "ecma"}, {protocol_family::data_kit, "data_kit"}, {protocol_family::ccitt, "ccitt"}, {protocol_family::sna, "sna"}, {protocol_family::dec_net, "dec_net"}, {protocol_family::data_link, "data_link"}, {protocol_family::lat, "lat"}, {protocol_family::hyper_channel, "hyper_channel"}, {protocol_family::apple_talk, "apple_talk"}, {protocol_family::net_bios, "net_bios"}, {protocol_family::voice_view, "voice_view"}, {protocol_family::fire_fox, "fire_fox"}, {protocol_family::banyan, "banyan"}, {protocol_family::atm, "atm"}, {protocol_family::inter_network_v6, "inter_network_v6"}, {protocol_family::cluster, "cluster"}, {protocol_family::ieee12844, "ieee12844"}, {protocol_family::irda, "irda"}, {protocol_family::network_designers, "network_designers"}, {protocol_family::max, "max"}});}
      inline std::wostream& operator<<(std::wostream& os, protocol_family value) {return os << to_string(value, {{protocol_family::unknown, L"unknown"}, {protocol_family::unspecified, L"unspecified"}, {protocol_family::unix, L"unix"}, {protocol_family::inter_network, L"inter_network"}, {protocol_family::imp_link, L"imp_link"}, {protocol_family::pup, L"pup"}, {protocol_family::chaos, L"chaos"}, {protocol_family::ns, L"ns"}, {protocol_family::ipx, L"ipx"}, {protocol_family::iso, L"iso"}, {protocol_family::osi, L"osi"}, {protocol_family::ecma, L"ecma"}, {protocol_family::data_kit, L"data_kit"}, {protocol_family::ccitt, L"ccitt"}, {protocol_family::sna, L"sna"}, {protocol_family::dec_net, L"dec_net"}, {protocol_family::data_link, L"data_link"}, {protocol_family::lat, L"lat"}, {protocol_family::hyper_channel, L"hyper_channel"}, {protocol_family::apple_talk, L"apple_talk"}, {protocol_family::net_bios, L"net_bios"}, {protocol_family::voice_view, L"voice_view"}, {protocol_family::fire_fox, L"fire_fox"}, {protocol_family::banyan, L"banyan"}, {protocol_family::atm, L"atm"}, {protocol_family::inter_network_v6, L"inter_network_v6"}, {protocol_family::cluster, L"cluster"}, {protocol_family::ieee12844, L"ieee12844"}, {protocol_family::irda, L"irda"}, {protocol_family::network_designers, L"network_designers"}, {protocol_family::max, L"max"}});}
    }
  }
}
