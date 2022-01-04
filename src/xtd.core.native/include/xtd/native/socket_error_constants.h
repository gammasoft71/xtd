/// @file
/// @brief Contains socket error constants.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @internal
/// @brief An unspecified error occurred
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_SOCKET_ERROR = -1;

/// @internal
/// @brief Operation successful
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_SUCCESS = 0;

/// @internal
/// @brief The overlapped operation was aborted due to the closure of the socket
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_OPERATION_ABORTED = 995;

/// @internal
/// @brief The application has initiated an overlapped operation that cannot be completed immediately
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_IO_PENDING = 997;

/// @internal
/// @brief A blocking call was canceled
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_INTERRUPTED = 10004;

/// @internal
/// @brief Access denied
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_ACCESS_DENIED = 10013;

/// @internal
/// @brief Invalid pointer address
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_FAULT = 10014;

/// @internal
/// @brief Invalid argument
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_INVALID_ARGUMENT = 10022;

/// @internal
/// @brief Too many sockets opened
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_TOO_MANY_OPEN_SOCKETS = 10024;

/// @internal
/// @brief An operation on a nonblocking socket cannot be completed immediately
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_WOULD_BLOCK = 10035;

/// @internal
/// @brief A blocking operation is in progress
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_IN_PROGRESS = 10036;

/// @internal
/// @brief The nonblocking socket has an operation in progress
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_ALREADY_IN_PROGRESS = 10037;

/// @internal
/// @brief Operation attempted on a non-socket object
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NOT_SOCKET = 10038;

/// @internal
/// @brief Required destination missing
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_DESTINATION_ADDRESS_REQUIRED = 10039;

/// @internal
/// @brief Datagram message is too long
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_MESSAGE_SIZE = 10040;

/// @internal
/// @brief The protocol type is incorrect
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_PROTOCOL_TYPE = 10041;

/// @internal
/// @brief An unknown, invalid, or unsupported option or level was used
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_PROTOCOL_OPTION = 10042;

/// @internal
/// @brief The protocol is not implemented or has not been configured
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_PROTOCOL_NOT_SUPPORTED = 10043;

/// @internal
/// @brief  The support for the specified socket type does not exist in this address family
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_SOCKET_NOT_SUPPORTED = 10044;

/// @internal
/// @brief The address family is not supported by the protocol family
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_OPERATION_NOT_SUPPORTED = 10045;

/// @internal
/// @brief The protocol family is not implemented or has not been configured
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_PROTOCOL_FAMILY_NOT_SUPPORTED = 10046;

/// @internal
/// @brief The address family specified is not supported. This error is returned if the IPv6 address family was specified and the IPv6 stack is not installed on the local machine. This error is returned if the IPv4 address family was specified and the IPv4 stack is not installed on the local machine.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED = 10047;

/// @internal
/// @brief Only one use of an address is normally permitted
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_ADDRESS_ALREADY_IN_USE = 10048;

/// @internal
/// @brief The selected IP address is not valid in this context
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_ADDRESS_NOT_AVAILABLE = 10049;

/// @internal
/// @brief The network is not available
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NETWORK_DOWN = 10050;

/// @internal
/// @brief No route to the remote host exists
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NETWORK_UNREACHABLE = 10051;

/// @internal
/// @brief The application tried to set "keep alive" on a connection that timed out
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NETWORK_RESET = 10052;

/// @internal
/// @brief Connection aborted
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_CONNECTION_ABORTED = 10053;

/// @internal
/// @brief Connection reset by the remote peer
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_CONNECTION_RESET = 10054;

/// @internal
/// @brief No free buffer space available
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NO_BUFFER_SPACE_AVAILABLE = 10055;

/// @internal
/// @brief Already connected
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_IS_CONNECTED = 10056;

/// @internal
/// @brief The socket is not connected
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NOT_CONNECTED = 10057;

/// @internal
/// @brief A request to send or receive data was disallowed because the socket is closed
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_SHUTDOWN = 10058;

/// @internal
/// @brief The connection attempt timed out, or the connected host has failed to respond
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_TIMED_OUT = 10060;

/// @internal
/// @brief The remote host is actively refusing a connection
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_CONNECTION_REFUSED = 10061;

/// @internal
/// @brief The operation failed because the remote host is down
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_HOST_DOWN = 10064;

/// @internal
/// @brief There is no network route to the specified host
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_HOST_UNREACHABLE = 10065;

/// @internal
/// @brief Too many processes are using the underlying socket provider
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_PROCESS_LIMIT = 10067;

/// @internal
/// @brief The network subsystem is unavailable
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_SYSTEM_NOT_READY = 10091;

/// @internal
/// @brief The version of the underlying socket provider is out of range
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_VERSION_NOT_SUPPORTED = 10092;

/// @internal
/// @brief The underlying socket provider has not been initialized
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NOT_INITIALIZED = 10093;

/// @internal
/// @brief A graceful shutdown is in progress
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_DISCONNECTING = 10101;

/// @internal
/// @brief The specified class was not found
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_TYPE_NOT_FOUND = 10109;

/// @internal
/// @brief No such host is known. The name is not an official host name or alias.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_HOST_NOT_FOUND = 10001;

/// @internal
/// @brief The name of the host could not be resolved. Try again later.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_TRY_AGAIN = 10002;

/// @internal
/// @brief The error is unrecoverable or the requested database cannot be located.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NOT_RECOVERY = 10003;

/// @internal
/// @brief The requested name or IP address was not found on the name server.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_error
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_ERROR_NO_DATA = 10004;
