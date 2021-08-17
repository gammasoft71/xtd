/// @file
/// @brief Contains socket API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <string>
#include <vector>

/// @cond
class __using_socket__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace net {
    class socket_address;
    namespace sockets {
      class socket;
    }
  }
  // @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains translator native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ socket final {
      friend __using_socket__;
      friend xtd::net::socket_address;
      friend xtd::net::sockets::socket;
    protected:
      /// @brief Gets the native address family value corresponding to xtd address family.
      /// @return The native address family value corresponding to xtd address family (see address_family_constants.h).
      /// @warning Internal use only
      static int32_t address_family_to_native(int32_t address_family);
      /// @brief Gets the xtd address family value corresponding to native address family.
      /// @return The xtd address family value corresponding to native address family (see address_family_constants.h).
      /// @warning Internal use only
      static int32_t native_to_address_family(int32_t address_family);
      /// @brief Accepts a connection on a socket.
      /// @param handle The socket handle.
      /// @param socket_address A byte array socket address is a result parameter that is filled in with the address of the connecting entity, as known to the communications layer.
      /// @return The new socket handle created.
      /// @warning Internal use only
      static intptr_t accept(intptr_t handle, std::vector<uint8_t>& socket_address);
      /// @brief Binds a name to a socket.
      /// @param handle The socket handle.
      /// @param socket_address A byte array socket address to bind.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t bind(intptr_t handle, const std::vector<uint8_t>& socket_address);
      /// @brief Cleanup the socket library.
      /// @warning Internal use only
      static void cleanup();
      /// @brief Initiates a connection on a socket.
      /// @param handle The socket handle.
      /// @param socket_address A byte array socket address to connect.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t connect(intptr_t handle, const std::vector<uint8_t>& socket_address);
      /// @brief Creates an endpoint for communication.
      /// @param address_family One of address family values (see address_family_constants.h).
      /// @param socket_type One of socket type values (see socket_type_constants.h).
      /// @param protocol_type One of protocol type values (see protocol_type_constants.h).
      /// @return The new socket handle created.
      /// @warning Internal use only
      static intptr_t create(int32_t address_family, int32_t socket_type, int32_t protocol_type);
      /// @brief Destroys the socket.
      /// @param handle The socket handle.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t destroy(intptr_t handle);
      /// @brief Gets the amount of data that has been received from the network and is available to be read.
      /// @param handle The socket handle.
      /// @return The number of bytes of data received from the network and available to be read.
      /// @remarks Return -1 if error.
      /// @warning Internal use only
      static size_t get_available(intptr_t handle);
      /// @brief Gets last error.
      /// @return One of socket error value (see socket_error_constants.h).
      /// @warning Internal use only
      static int32_t get_last_error();
      /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 4 (IPv4).
      /// @return bool true if the operating system and network adaptors support the IPv4 protocol; otherwise, false.
      /// @warning Internal use only
      static bool get_os_supports_ip_v4() noexcept;
      /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 6 (IPv6).
      /// @return bool true if the operating system and network adaptors support the IPv6 protocol; otherwise, false.
      /// @warning Internal use only
      static bool get_os_supports_ip_v6() noexcept;
      /// @brief Gets options on socket.
      /// @param handle The socket handle.
      /// @param socket_option_level The platform-defined option level.
      /// @param socket_option_name The platform-defined option name.
      /// @param option The option is a result paramter of that is filled with the option value.
      /// @param option_length The option size will contains the size of option value.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t get_raw_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, void* option, size_t& option_length);
      /// @brief Gets options on socket.
      /// @param handle The socket handle.
      /// @param socket_option_level One of socket option level values (see socket_option_level_constants.h).
      /// @param socket_option_name One of socket option name values (see socket_option_name_constants.h).
      /// @param option The option is a result paramter of that is filled with the option value.
      /// @param option_length The option size will contains the size of option value.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t get_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, void* option, size_t& option_length);
      /// @brief Gets linger option on socket.
      /// @param handle The socket handle.
      /// @param enabled Indicates whether to linger after the socket is closed..
      /// @param linger_time The amount of time to remain connected after calling the socket close method if data remains to be sent.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t get_socket_linger_option(intptr_t handle, bool& enabled, uint32_t& linger_time);
      /// @brief Gets multicast option on socket.
      /// @param handle The socket handle.
      /// @param socket_option_name One of socket option name values (see socket_option_name_constants.h).
      /// @param multicast_address The local IP address associated with a multicast group.
      /// @param interface_index The interface index that is associated with a multicast group.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t get_socket_multicast_option(intptr_t handle, int32_t socket_option_name, uint32_t& multicast_address, uint32_t& interface_index);
      /// @brief Gets IP v6 multicast option on socket.
      /// @param handle The socket handle.
      /// @param socket_option_name One of socket option name values (see socket_option_name_constants.h).
      /// @param multicast_address The local IP address associated with a multicast group.
      /// @param interface_index The interface index that is associated with a multicast group.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t get_socket_ip_v6_multicast_option(intptr_t handle, int32_t socket_option_name, std::vector<uint8_t>& multicast_address, uint32_t& interface_index);
      /// @brief Sets low-level operating modes for the Socket using the IOControlCode enumeration to specify control codes.
      /// @param handle The socket handle.
      /// @param io_control A io control code value that specifies the control code of the operation to perform (see io_control_code_constants.h).
      /// @param option_in_value An array of type byte that contains the input data required by the operation.
      /// @param option_out_value An array of type byte that contains the output data returned by the operation.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t io_control(intptr_t handle, int32_t io_control, std::vector<uint8_t>& option_in_value, std::vector<uint8_t>& option_out_value);
      /// @brief Llistens for connections on a socket.
      /// @param handle The socket handle.
      /// @param backlog The maximum length for the queue of pending connections.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t listen(intptr_t handle, int32_t backlog);
      /// @brief Synchronous I/O multiplexing
      /// @param handle The socket handle.
      /// @param microseconds Timeout in microseconds.
      /// @param mode One of select mode value (see select_mode_constants.h).
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t poll(intptr_t handle, int32_t microseconds, int32_t mode);
      /// @brief Receives a message from a socket.
      /// @param handle The socket handle.
      /// @param buffer An array of type byte that is the storage location for the received data.
      /// @param offset The location in buffer to store the received data.
      /// @param size The number of bytes to receive.
      /// @param flags A bitwise combination of the socket flags values. (see socket_flags_constants.h)
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t receive(intptr_t handle, std::vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags);
      /// @brief Receives a message from a socket.
      /// @param handle The socket handle.
      /// @param buffer An array of type byte that is the storage location for the received data.
      /// @param offset The location in buffer to store the received data.
      /// @param size The number of bytes to receive.
      /// @param flags A bitwise combination of the socket flags values. (see socket_flags_constants.h)
      /// @param socket_address A byte array socket address to receive from.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t receive_from(intptr_t handle, std::vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags, std::vector<uint8_t>& socket_address);
      /// @brief Determines the status of one or more sockets.
      /// @param check_read An IList of Socket instances to check for readability.
      /// @param check_write An IList of Socket instances to check for writability.
      /// @param check_error An IList of Socket instances to check for errors.
      /// @param microseconds The time-out value, in microseconds. A -1 value indicates an infinite time-out.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t select(std::vector<intptr_t>& check_read, std::vector<intptr_t>& check_write, std::vector<intptr_t>& check_error, int32_t microseconds);
      /// @brief send a message from a socket.
      /// @param buffer An array of type Byte that contains the data to be sent.
      /// @param offset TThe position in the data buffer at which to begin sending data.
      /// @param size The number of bytes to send.
      /// @param flags A bitwise combination of the socket flags values. (see socket_flags_constants.h)
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t send(intptr_t handle, const std::vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags);
      /// @brief send a message from a socket.
      /// @param handle The socket handle.
      /// @param buffer An array of type Byte that contains the data to be sent.
      /// @param offset TThe position in the data buffer at which to begin sending data.
      /// @param size The number of bytes to send.
      /// @param flags A bitwise combination of the socket flags values. (see socket_flags_constants.h)
      /// @param socket_address A byte array socket address to send to.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t send_to(intptr_t handle, const std::vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags, const std::vector<uint8_t>& socket_address);
      /// @brief Sets a value that indicates whether the socket is in blocking mode.
      /// @param handle The socket handle.
      /// @param blocking bool true if the Socket will block; otherwise, false. The default is true
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t set_blocking(intptr_t handle, bool blocking);
      /// @brief Sets options on socket.
      /// @param handle The socket handle.
      /// @param socket_option_level The platform-defined option name.
      /// @param socket_option_name The value to which the option should be set.
      /// @param option Contains the option value.
      /// @param option_length Contains the option value size.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t set_raw_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, const void* option, size_t option_length);
      /// @brief Sets options on socket.
      /// @param handle The socket handle.
      /// @param socket_option_level One of socket option level values (see socket_option_level_constants.h).
      /// @param socket_option_name One of socket option name values (see socket_option_name_constants.h).
      /// @param option Contains the option value.
      /// @param option_length Contains the option value size.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t set_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, const void* option, size_t option_length);
      /// @brief Sets linger option on socket.
      /// @param handle The socket handle.
      /// @param enabled Indicates whether to linger after the socket is closed..
      /// @param linger_time The amount of time to remain connected after calling the socket close method if data remains to be sent.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t set_socket_linger_option(intptr_t handle, bool enabled, uint32_t linger_time);
      /// @brief Sets multicast option on socket.
      /// @param handle The socket handle.
      /// @param socket_option_name One of socket option name values (see socket_option_name_constants.h).
      /// @param multicast_address The local IP address associated with a multicast group.
      /// @param interface_index The interface index that is associated with a multicast group.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t set_socket_multicast_option(intptr_t handle, int32_t socket_option_name, uint32_t multicast_address, uint32_t interface_index);
      /// @brief Sets IP v6 multicast option on socket.
      /// @param handle The socket handle.
      /// @param socket_option_name One of socket option name values (see socket_option_name_constants.h).
      /// @param multicast_address The local IP address associated with a multicast group.
      /// @param interface_index The interface index that is associated with a multicast group.
      /// @param linger_time The amount of time to remain connected after calling the socket close method if data remains to be sent.
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t set_socket_ip_v6_multicast_option(intptr_t handle, int32_t socket_option_name, const std::vector<uint8_t>& multicast_address, uint32_t interface_index);
      /// @brief Shut down part of a full-duplex connection.
      /// @param handle The socket handle.
      /// @param how One of socket shutdown values (see socket_shutdown_constants.h).
      /// @return Zero (0) if succeed; otherwise on error.
      /// @warning Internal use only
      static int32_t shutdown(intptr_t handle, int32_t how);
      /// @brief Startup the socket library.
      /// @warning Internal use only
      static void startup();
    };
  }
}
