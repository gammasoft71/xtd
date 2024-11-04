#include <xtd/xtd>

using namespace xtd;

/*
errno_t socket_error_to_errno(xtd::net::sockets::socket_error error) noexcept {
  using namespace xtd::net::sockets;
  switch (error) {
    case socket_error::sock_error : return -1;
    case socket_error::success : return 0;
    case socket_error::operation_aborted : return ECONNABORTED;
    case socket_error::io_pending : return static_cast<int>(error);
    case socket_error::interrupted : return EINTR;
    case socket_error::access_denied : return EACCES;
    case socket_error::fault : return EFAULT;
    case socket_error::invalid_argument : return EINVAL;
    case socket_error::too_many_open_sockets : return EMFILE;
    case socket_error::would_block : return EAGAIN;
    case socket_error::in_progress : return EINPROGRESS;
    case socket_error::already_in_progress : return EALREADY;
    case socket_error::not_socket : return ENOTSOCK;
    case socket_error::destination_address_required : return EDESTADDRREQ;
    case socket_error::message_size : return EMSGSIZE;
    case socket_error::protocol_type : return EPROTOTYPE;
    case socket_error::protocol_option : return ENOPROTOOPT;
    case socket_error::protocol_not_supported : return EPROTONOSUPPORT;
    case socket_error::socket_not_supported : return ENOTSUP; // ESOCKTNOSUPPORT;
    case socket_error::operation_not_supported : return ENOTSUP;
    case socket_error::protocol_family_not_supported : return ENOTSUP; // EPFNOSUPPORT;
    case socket_error::address_family_not_supported : return EAFNOSUPPORT;
    case socket_error::address_already_in_use : return EADDRINUSE;
    case socket_error::address_not_available : return EADDRNOTAVAIL;
    case socket_error::network_down : return ENETDOWN;
    case socket_error::network_unreachable : return ENETUNREACH;
    case socket_error::network_reset : return ENETRESET;
    case socket_error::connection_aborted : return ECONNABORTED;
    case socket_error::connection_reset : return ECONNRESET;
    case socket_error::no_buffer_space_available : return ENOBUFS;
    case socket_error::is_connected : return EISCONN;
    case socket_error::not_connected : return ENOTCONN;
    case socket_error::shutdown : return static_cast<int>(error); // ESHUTDOWN;
    case socket_error::timed_out : return ETIMEDOUT;
    case socket_error::connection_refused : return ECONNREFUSED;
    case socket_error::host_down : return static_cast<int>(error); // EHOSTDOWN;
    case socket_error::host_unreachable : return EHOSTUNREACH;
    case socket_error::process_limit : return static_cast<int>(error); // EPROCLIM;
    case socket_error::system_not_ready : return static_cast<int>(error);
    case socket_error::version_not_supported : return static_cast<int>(error); // ERPCMISMATCH;
    case socket_error::not_initialized : return static_cast<int>(error);
    case socket_error::disconnecting : return static_cast<int>(error);
    case socket_error::type_not_found : return static_cast<int>(error);
    case socket_error::host_not_found : return static_cast<int>(error);
    case socket_error::try_again : return static_cast<int>(error);
    case socket_error::no_recovery : return static_cast<int>(error);
    case socket_error::no_data : return static_cast<int>(error);
    default: return static_cast<int>(error);
  }
}

string errno_to_string(errno_t error) noexcept {
  if (error == 0) return "The operation completed successfully";
  auto previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
  auto result = string {std::strerror(error)};
  std::locale::global(previous_locale);
  return result;
}
 */

string socket_error_to_string(xtd::net::sockets::socket_error error) noexcept {
  using namespace xtd::net::sockets;
  
  auto socket_error_to_errno = [](socket_error error) {
    switch (error) {
      case socket_error::sock_error : return -1;
      case socket_error::success : return 0;
      case socket_error::operation_aborted : return ECONNABORTED;
      case socket_error::io_pending : return static_cast<int>(error);
      case socket_error::interrupted : return EINTR;
      case socket_error::access_denied : return EACCES;
      case socket_error::fault : return EFAULT;
      case socket_error::invalid_argument : return EINVAL;
      case socket_error::too_many_open_sockets : return EMFILE;
      case socket_error::would_block : return EAGAIN;
      case socket_error::in_progress : return EINPROGRESS;
      case socket_error::already_in_progress : return EALREADY;
      case socket_error::not_socket : return ENOTSOCK;
      case socket_error::destination_address_required : return EDESTADDRREQ;
      case socket_error::message_size : return EMSGSIZE;
      case socket_error::protocol_type : return EPROTOTYPE;
      case socket_error::protocol_option : return ENOPROTOOPT;
      case socket_error::protocol_not_supported : return EPROTONOSUPPORT;
      case socket_error::socket_not_supported : return ENOTSUP; // ESOCKTNOSUPPORT;
      case socket_error::operation_not_supported : return ENOTSUP;
      case socket_error::protocol_family_not_supported : return ENOTSUP; // EPFNOSUPPORT;
      case socket_error::address_family_not_supported : return EAFNOSUPPORT;
      case socket_error::address_already_in_use : return EADDRINUSE;
      case socket_error::address_not_available : return EADDRNOTAVAIL;
      case socket_error::network_down : return ENETDOWN;
      case socket_error::network_unreachable : return ENETUNREACH;
      case socket_error::network_reset : return ENETRESET;
      case socket_error::connection_aborted : return ECONNABORTED;
      case socket_error::connection_reset : return ECONNRESET;
      case socket_error::no_buffer_space_available : return ENOBUFS;
      case socket_error::is_connected : return EISCONN;
      case socket_error::not_connected : return ENOTCONN;
      case socket_error::shutdown : return static_cast<int>(error); // ESHUTDOWN;
      case socket_error::timed_out : return ETIMEDOUT;
      case socket_error::connection_refused : return ECONNREFUSED;
      case socket_error::host_down : return static_cast<int>(error); // EHOSTDOWN;
      case socket_error::host_unreachable : return EHOSTUNREACH;
      case socket_error::process_limit : return static_cast<int>(error); // EPROCLIM;
      case socket_error::system_not_ready : return static_cast<int>(error);
      case socket_error::version_not_supported : return static_cast<int>(error); // ERPCMISMATCH;
      case socket_error::not_initialized : return static_cast<int>(error);
      case socket_error::disconnecting : return static_cast<int>(error);
      case socket_error::type_not_found : return static_cast<int>(error);
      case socket_error::host_not_found : return static_cast<int>(error);
      case socket_error::try_again : return static_cast<int>(error);
      case socket_error::no_recovery : return static_cast<int>(error);
      case socket_error::no_data : return static_cast<int>(error);
      default: return static_cast<int>(error);
    }
  };
  
  auto errno_to_string = [](errno_t error) {
    if (error == 0) return string {"The operation completed successfully"};
    auto previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
    auto result = string {std::strerror(error)};
    std::locale::global(previous_locale);
    return result;
  };

  return errno_to_string(socket_error_to_errno(error));
}

string errno_to_string(errno_t error) noexcept {
  if (error == 0) return "The operation completed successfully";
  auto previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
  auto result = string {std::strerror(error)};
  std::locale::global(previous_locale);
  return result;
}

/*
string error_to_string(int errnum) {
  auto result = string {};
  auto messageBuffer = LPSTR {nullptr};
  auto size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS, null, errnum, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPSTR>(&messageBuffer), 0, null);
  if (messageBuffer == null) result = string::format("Unknown error (0x{:x})", errnum);
  else {
    result = string {messageBuffer, size}.replace("\n", "");
    LocalFree(messageBuffer);
  }
  
  return result;
}
 */

auto main(int argc, char* argv[]) -> int {
  //console::write_line("Hello, World!");
  
  //for (auto errnum = 0; errnum <= 110; ++errnum)
  //  console::write_line("{:d3} - {}", errnum, errno_to_string(errnum));
  for (auto error : enum_object<>::get_values<xtd::net::sockets::socket_error>())
    console::write_line("{} - {}", error, socket_error_to_string(error));
  console::write_line("{} - {}", ESOCKTNOSUPPORT, errno_to_string(ESOCKTNOSUPPORT));
  /*
  try {
    throw exception {};
  } catch(const exception& e) {
    console::write_line("type              = {}", e.get_type());
    console::write_line("help_link         = {}", e.help_link());
    console::write_line("h_result          = 0x{0:X8} ({0})", static_cast<uint>(e.h_result()));
    console::write_line("inner_exception   = {}", e.inner_exception());
    console::write_line("message           = {}", e.message());
    console::write_line("source            = {}", e.source());
    console::write_line("stack_trace       = {}", e.stack_trace());
  }
   */
}

// This code can produces the following output:
//
// Hello, World!
