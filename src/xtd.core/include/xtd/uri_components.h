/// @file
/// @brief Contains xtd::uri_components enum.
#pragma once

#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief This enumeration has a Flags attribute that allows a bitwise combination of its member values.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks This enumeration is used to identify the parts of a xtd::uri. This enumeration is used with the xtd::uri::get_components method.
  enum class uri_components {
    /// @brief None data.
    none = 0x00000000,
    /// @brief The xtd::uri::scheme data.
    scheme = 0x00000001,
    /// @brief The xtd::uri::user_info data.
    user_info = 0x00000002,
    /// @brief The xtd::uri::host data.
    host = 0x00000004,
    /// @brief The xtd::uri::port data.
    port = 0x000000008,
    /// @brief The xtd::uri::local_path data.
    path = 0x00000010,
    /// @brief The xtd::uri::query data.
    query = 0x00000020,
    /// @brief The xtd::uri::fragment data.
    fragment = 0x00000040,
    /// @brief The xtd::uri::port data. If no port data is in the xtd::uri and a default port has been assigned to the xtd::uri::scheme, the default port is returned. If there is no default port, -1 is returned.
    strong_port = 0x00000080,
    /// @brief Specifies that the delimiter should be included.
    keep_delimiter = 0x40000000,
    /// @brief The xtd::uri::host and xtd::uri::port data. If no port data is in the Uri and a default port has been assigned to the xtd::uri::scheme, the default port is returned. If there is no default port, -1 is returned.
    host_and_port = 0x00000084,
    /// @brief The xtd::uri::user_info, host, and port data. If no port data is in the Uri and a default port has been assigned to the scheme, the default port is returned. If there is no default port, -1 is returned.
    strong_authority = 0x00000086,
    /// @brief The xtd::uri::scheme, xtd::uri::user_info, xtd::uri::host, port, xtd::uri::local_path, xtd::uri::query, and xtd::uri::fragment data.
    absolute_uri = 0x0000007F,
    /// @brief The xtd::uri::local_path and xtd::uri::query data. Also see xtd::uri::path_and_query.
    path_and_query = 0x00000030,
    /// @brief The xtd::uri::scheme, xtd::uri::host, xtd::uri::port, xtd::uri::local_path, and xtd::uri::query data.
    http_request_url = 0x0000003D,
    /// @brief The xtd::uri::scheme, xtd::uri::host, and xtd::uri::port data.
    scheme_and_server = 0x0000000D,
    /// @brief The complete xtd::uri context that is needed for xtd::uri Serializers. The context includes the IPv6 scope.
    serialization_info_string = 0x08000000 //0x80000000
  };
  
  /// @cond
  inline xtd::uri_components& operator^=(xtd::uri_components& lhs, xtd::uri_components rhs) {lhs = static_cast<xtd::uri_components>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
  inline xtd::uri_components& operator&=(xtd::uri_components& lhs, xtd::uri_components rhs) {lhs = static_cast<xtd::uri_components>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
  inline xtd::uri_components& operator|=(xtd::uri_components& lhs, xtd::uri_components rhs) {lhs = static_cast<xtd::uri_components>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
  inline xtd::uri_components& operator+=(xtd::uri_components& lhs, xtd::uri_components rhs) {lhs = static_cast<xtd::uri_components>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
  inline xtd::uri_components& operator-=(xtd::uri_components& lhs, xtd::uri_components rhs) {lhs = static_cast<xtd::uri_components>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
  inline xtd::uri_components operator^(xtd::uri_components lhs, xtd::uri_components rhs) {return static_cast<xtd::uri_components>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
  inline xtd::uri_components operator&(xtd::uri_components lhs, xtd::uri_components rhs) {return static_cast<xtd::uri_components>(static_cast<int>(lhs) & static_cast<int>(rhs));}
  inline xtd::uri_components operator|(xtd::uri_components lhs, xtd::uri_components rhs) {return static_cast<xtd::uri_components>(static_cast<int>(lhs) | static_cast<int>(rhs));}
  inline xtd::uri_components operator+(xtd::uri_components lhs, xtd::uri_components rhs) {return static_cast<xtd::uri_components>(static_cast<int>(lhs) + static_cast<int>(rhs));}
  inline xtd::uri_components operator-(xtd::uri_components lhs, xtd::uri_components rhs) {return static_cast<xtd::uri_components>(static_cast<int>(lhs) - static_cast<int>(rhs));}
  inline xtd::uri_components operator~(xtd::uri_components lhs) {return static_cast<xtd::uri_components>(~static_cast<int>(lhs));}
  inline std::ostream& operator<<(std::ostream& os, const uri_components value) {return os << to_string(value, {{uri_components::none, "none"}, {uri_components::scheme, "scheme"}, {uri_components::user_info, "user_info"}, {uri_components::host, "host"}, {uri_components::port, "port"}, {uri_components::path, "path"}, {uri_components::query, "query"}, {uri_components::fragment, "fragment"}, {uri_components::strong_port, "strong_port"}, {uri_components::keep_delimiter, "keep_delimiter"}, {uri_components::host_and_port, "host_and_port"}, {uri_components::strong_authority, "strong_authority"}, {uri_components::absolute_uri, "absolute_uri"}, {uri_components::path_and_query, "path_and_query"}, {uri_components::http_request_url, "http_request_url"}, {uri_components::scheme_and_server, "scheme_and_server"}, {uri_components::serialization_info_string, "serialization_info_string"}});}
  inline std::wostream& operator<<(std::wostream& os, const uri_components value) {return os << to_string(value, {{uri_components::none, L"none"}, {uri_components::scheme, L"scheme"}, {uri_components::user_info, L"user_info"}, {uri_components::host, L"host"}, {uri_components::port, L"port"}, {uri_components::path, L"path"}, {uri_components::query, L"query"}, {uri_components::fragment, L"fragment"}, {uri_components::strong_port, L"strong_port"}, {uri_components::keep_delimiter, L"keep_delimiter"}, {uri_components::host_and_port, L"host_and_port"}, {uri_components::strong_authority, L"strong_authority"}, {uri_components::absolute_uri, L"absolute_uri"}, {uri_components::path_and_query, L"path_and_query"}, {uri_components::http_request_url, L"http_request_url"}, {uri_components::scheme_and_server, L"scheme_and_server"}, {uri_components::serialization_info_string, L"serialization_info_string"}});}
  /// @endcond
}
