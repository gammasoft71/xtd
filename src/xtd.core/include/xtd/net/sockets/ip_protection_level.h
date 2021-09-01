/// @file
/// @brief Contains xtd::net::sockets::ip_protection_level enum.
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
      /// @brief A value that enables restriction of an IPv6 socket to a specified scope, such as addresses with the same link local or site local prefix.
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks This option enables applications to place access restrictions on IPv6 sockets. Such restrictions enable an application running on a private LAN to simply and robustly harden itself against external attacks. This socket option widens or narrows the scope of a listening socket, enabling unrestricted access from public and private users when appropriate, or restricting access only to the same site, as required.
      enum class ip_protection_level {
        /// @brief The IP protection level is unspecified. On Windows 7 and Windows Server 2008 R2, the default value for the IP Protection level on a socket is unspecified.
        unspecified = -1,
        /// @brief The IP protection level is unrestricted. This value would be used by applications designed to operate across the Internet, including applications taking advantage of IPv6 NAT traversal capabilities built into Windows (Teredo, for example). These applications may bypass IPv4 firewalls, so applications must be hardened against Internet attacks directed at the opened port. On Windows Server 2008 R2 and Windows Vista, the default value for the IP Protection level on a socket is unrestricted.
        unrestricted = 10,
        /// @brief The IP protection level is edge restricted. This value would be used by applications designed to operate across the Internet. This setting does not allow Network Address Translation (NAT) traversal using the Windows Teredo implementation. These applications may bypass IPv4 firewalls, so applications must be hardened against Internet attacks directed at the opened port. On Windows Server 2003 and Windows XP, the default value for the IP Protection level on a socket is edge restricted.
        edge_restricted = 20,
        /// @brief The IP protection level is restricted. This value would be used by intranet applications that do not implement Internet scenarios. These applications are generally not tested or hardened against Internet-style attacks. This setting will limit the received traffic to link-local only.
        restricted = 30
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, ip_protection_level value) {return os << to_string(value, {{ip_protection_level::unspecified, "unspecified"}, {ip_protection_level::unrestricted, "unrestricted"}, {ip_protection_level::edge_restricted, "edge_restricted"}, {ip_protection_level::restricted, "restricted"}});}
      inline std::wostream& operator<<(std::wostream& os, ip_protection_level value) {return os << to_string(value, {{ip_protection_level::unspecified, L"unspecified"}, {ip_protection_level::unrestricted, L"unrestricted"}, {ip_protection_level::edge_restricted, L"edge_restricted"}, {ip_protection_level::restricted, L"restricted"}});}
      /// @endcond
    }
  }
}
