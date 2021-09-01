/// @file
/// @brief Contains xtd::net::sockets::linger_option class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../core_export.h"
#include "../../object.h"
#include "../../types.h"
#include "../../ustring.h"
#include "../ip_address.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Specifies whether a xtd::net::sockets::socket will remain connected after a call to the xtd::net::sockets::socket::close or xtd::net::sockets::tcp_client::close methods and the length of time it will remain connected, if data remains to be sent.
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks There may still be data available in the outgoing network buffer after an application calls the xtd::net::sockets::socket or xtd::net::sockets::tcp_client method. If you want to specify the amount of time that the xtd::net::sockets::socket will attempt to transmit unsent data after closing, create a xtd::net::sockets::linger_option with the enable parameter set to true, and the seconds parameter set to the desired amount of time. The seconds parameter is used to indicate how long you would like the xtd::net::sockets::socket to remain connected before timing out. If you do not want the xtd::net::sockets::socket to stay connected for any length of time after closing, create a xtd::net::sockets::linger_option instance with the enable parameter set to true and the seconds parameter set to zero. In this case, the xtd::net::sockets::socket will close immediately and any unsent data will be lost. Once created, pass the xtd::net::sockets::linger_option to the xtd::net::sockets::socket::set_socket_option method. If you are sending and receiving data with a xtd::net::sockets::tcp_client, then set the xtd::net::sockets::llinger_option instance in the xtd::net::sockets::tcp_client::linger_state property.
      /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a xtd::net::sockets::socket when the xtd::net::sockets::socket::linger_state property is not set and for a xtd::net::sockets::tcp_client when the xtd::net::sockets::tcp_client::linger_state property is not set.
      class core_export_ linger_option : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::linger_option class.
        linger_option() = default;
        /// @brief Initializes a new version of the xtd::net::sockets::linger_option class for the specified IP multicast group.
        /// @param enabled true to remain connected after the Socket.Close method is called; otherwise, false.
        /// @param linger_time The number of seconds to remain connected after the Socket.Close method is called.
        /// @remarks There may still be data available in the outgoing network buffer after you close the Socket. Use the enable parameter to specify whether you would like the Socket to continue transmitting unsent data after the close method is called. Use the seconds parameter to indicate how long you would like the Socket to attempt transferring unsent data before timing out. If you specify true for the enable parameter and 0 for the seconds parameter, the Socket will attempt to send data until there is no data left in the outgoing network buffer. If you specify false for the enable parameter, the Socket will close immediately and any unsent data will be lost.
        /// @remarks The following table describes the behavior on the xtd::net::sockets::socket::close and xtd::net::sockets::tcp_client::close methods based on the possible values of the enable and seconds parameters when an xtd::net::sockets::linger_option instance is created and set in the xtd::net::sockets::socket::linger_state or xtd::net::sockets::socketxtd::net::sockets::tcp_client::linger_state property.
        /// | enable                              | seconds                                    | Behavior                                                                                                                          |
        /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
        /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        linger_option(bool enabled, uint32_t linger_time);

        /// @cond
        linger_option(linger_option&& linger_option) = default;
        linger_option(const linger_option& linger_option) = default;
        linger_option& operator=(const linger_option&) = default;
        friend std::ostream& operator <<(std::ostream& os, const linger_option& mo) noexcept {return os << mo.to_string();}
        /// @endcond
        
        /// @brief Gets a value that indicates whether to linger after the xtd::net::sockets::socket is closed.
        /// @return true if the xtd::net::sockets::socket should linger after xtd::net::sockets::socket::close is called; otherwise, false.
        /// @remarks You can use the xtd::net::sockets::linger_option::enabled property to determine whether the xtd::net::sockets::socket will linger after closing. Change this value to true or false and pass the altered xtd::net::sockets::linger_option to the xtd::net::sockets::socket::set_socket_option method or set the xtd::net::sockets::socket::linger_state or xtd::net::sockets::tcp_cllient::linger_state property to disable or enable lingering.
        /// @remarks The following table describes the behavior on the xtd::net::sockets::socket::close and xtd::net::sockets::tcp_client::close methods based on the possible values of the enable and seconds parameters when an xtd::net::sockets::linger_option instance is created and set in the xtd::net::sockets::socket::linger_state or xtd::net::sockets::socketxtd::net::sockets::tcp_client::linger_state property.
        /// | enable                              | seconds                                    | Behavior                                                                                                                          |
        /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
        /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        bool enabled() const noexcept;
        /// @brief Sets a value that indicates whether to linger after the xtd::net::sockets::socket is closed.
        /// @param value true if the xtd::net::sockets::socket should linger after xtd::net::sockets::socket::close is called; otherwise, false.
        /// @remarks You can use the xtd::net::sockets::linger_option::enabled property to determine whether the xtd::net::sockets::socket will linger after closing. Change this value to true or false and pass the altered xtd::net::sockets::linger_option to the xtd::net::sockets::socket::set_socket_option method or set the xtd::net::sockets::socket::linger_state or xtd::net::sockets::tcp_cllient::linger_state property to disable or enable lingering.
        /// @remarks The following table describes the behavior on the xtd::net::sockets::socket::close and xtd::net::sockets::tcp_client::close methods based on the possible values of the enable and seconds parameters when an xtd::net::sockets::linger_option instance is created and set in the xtd::net::sockets::socket::linger_state or xtd::net::sockets::socketxtd::net::sockets::tcp_client::linger_state property.
        /// | enable                              | seconds                                    | Behavior                                                                                                                          |
        /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
        /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        linger_option& enabled(bool value) noexcept;

        /// @brief Gets the amount of time to remain connected after calling the xtd::net::sockets::socket::close method if data remains to be sent.
        /// @return The amount of time, in seconds, to remain connected after calling xtd::net::sockets::socket::close.
        /// @remarks Use this value if you want to determine how long a closed xtd::net::sockets::socket will attempt to transfer unsent data before timing out. You can also set this value to the desired time-out period, in seconds.
        /// @remarks If the xtd::net::sockets::linger_option::enabled property is true, and you set xtd::net::sockets::linger_option::linger_time to 0, the xtd::net::sockets::socket discards any pending data to send in the outgoing network buffer. If you change this value, you must pass the altered xtd::net::sockets::linger_option instance to the xtd::net::sockets::socket::set_socket_option method or set the xtd::net::sockets::socket::linger_state or xtd::net::sockets::tcp_client::linger_state property.
        /// @remarks The following table describes the behavior on the xtd::net::sockets::socket::close and xtd::net::sockets::tcp_client::close methods based on the possible values of the enable and seconds parameters when an xtd::net::sockets::linger_option instance is created and set in the xtd::net::sockets::socket::linger_state or xtd::net::sockets::socketxtd::net::sockets::tcp_client::linger_state property.
        /// | enable                              | seconds                                    | Behavior                                                                                                                          |
        /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
        /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        uint32_t linger_time() const noexcept;
        /// @brief Sets the amount of time to remain connected after calling the xtd::net::sockets::socket::close method if data remains to be sent.
        /// @param value The amount of time, in seconds, to remain connected after calling xtd::net::sockets::socket::close.
        /// @remarks Use this value if you want to determine how long a closed xtd::net::sockets::socket will attempt to transfer unsent data before timing out. You can also set this value to the desired time-out period, in seconds.
        /// @remarks If the xtd::net::sockets::linger_option::enabled property is true, and you set xtd::net::sockets::linger_option::linger_time to 0, the xtd::net::sockets::socket discards any pending data to send in the outgoing network buffer. If you change this value, you must pass the altered xtd::net::sockets::linger_option instance to the xtd::net::sockets::socket::set_socket_option method or set the xtd::net::sockets::socket::linger_state or xtd::net::sockets::tcp_client::linger_state property.
        /// @remarks The following table describes the behavior on the xtd::net::sockets::socket::close and xtd::net::sockets::tcp_client::close methods based on the possible values of the enable and seconds parameters when an xtd::net::sockets::linger_option instance is created and set in the xtd::net::sockets::socket::linger_state or xtd::net::sockets::socketxtd::net::sockets::tcp_client::linger_state property.
        /// | enable                              | seconds                                    | Behavior                                                                                                                          |
        /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
        /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        linger_option& linger_time(uint32_t value) noexcept;

      private:
        bool enabledd_ = false;
        uint32_t linger_time_ = 0;
      };
    }
  }
}
