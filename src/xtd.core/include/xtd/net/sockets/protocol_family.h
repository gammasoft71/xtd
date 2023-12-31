/// @file
/// @brief Contains xtd::net::sockets::protocol_family enum.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
      /// @brief Specifies the type of protocol that an instance of the xtd::net::sockets::socket class can use.
      /// @code
      /// enum class protocol_family
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/protocol_family> @endcode
      /// @par Namespace
      /// xtd::net::sockets
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
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::protocol_family> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::protocol_family> {{xtd::net::sockets::protocol_family::unknown, "unknown"}, {xtd::net::sockets::protocol_family::unspecified, "unspecified"}, {xtd::net::sockets::protocol_family::unix, "unix"}, {xtd::net::sockets::protocol_family::inter_network, "inter_network"}, {xtd::net::sockets::protocol_family::imp_link, "imp_link"}, {xtd::net::sockets::protocol_family::pup, "pup"}, {xtd::net::sockets::protocol_family::chaos, "chaos"}, {xtd::net::sockets::protocol_family::ipx, "ipx"}, {xtd::net::sockets::protocol_family::iso, "iso"}, {xtd::net::sockets::protocol_family::ecma, "ecma"}, {xtd::net::sockets::protocol_family::data_kit, "data_kit"}, {xtd::net::sockets::protocol_family::ccitt, "ccitt"}, {xtd::net::sockets::protocol_family::sna, "sna"}, {xtd::net::sockets::protocol_family::dec_net, "dec_net"}, {xtd::net::sockets::protocol_family::data_link, "data_link"}, {xtd::net::sockets::protocol_family::lat, "lat"}, {xtd::net::sockets::protocol_family::hyper_channel, "hyper_channel"}, {xtd::net::sockets::protocol_family::apple_talk, "apple_talk"}, {xtd::net::sockets::protocol_family::net_bios, "net_bios"}, {xtd::net::sockets::protocol_family::voice_view, "voice_view"}, {xtd::net::sockets::protocol_family::fire_fox, "fire_fox"}, {xtd::net::sockets::protocol_family::banyan, "banyan"}, {xtd::net::sockets::protocol_family::atm, "atm"}, {xtd::net::sockets::protocol_family::inter_network_v6, "inter_network_v6"}, {xtd::net::sockets::protocol_family::cluster, "cluster"}, {xtd::net::sockets::protocol_family::ieee12844, "ieee12844"}, {xtd::net::sockets::protocol_family::irda, "irda"}, {xtd::net::sockets::protocol_family::network_designers, "network_designers"}, {xtd::net::sockets::protocol_family::max, "max"}};}
};
/// @endcond
