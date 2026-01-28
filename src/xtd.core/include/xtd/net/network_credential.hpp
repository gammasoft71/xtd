/// @file
/// @brief Contains xtd::net::network_credential class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../security/secure_string.hpp"
#include "../core_export.hpp"
#include "../object.hpp"
#include "../types.hpp"
#include "../string.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides credentials for password-based authentication schemes such as basic, digest, NTLM, and Kerberos authentication.
    /// @par Header
    /// ```cpp
    /// #include <xtd/net/network_credential>
    /// ```
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ network_credential : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::net::network_credential class.
      network_credential() = default;
      /// @brief Initializes a new instance of the xtd::net::network_credential class with the specified user name and password.
      network_credential(const xtd::string& user_name, const xtd::security::secure_string& password);
      /// @brief Initializes a new instance of the xtd::net::network_credential class with the specified user name and password.
      network_credential(const xtd::string& user_name, const xtd::string& password);
      /// @brief Initializes a new instance of the xtd::net::network_credential class with the specified user name, password and domain.
      network_credential(const xtd::string& user_name, const xtd::security::secure_string& password, const xtd::string& domain);
      /// @brief Initializes a new instance of the xtd::net::network_credential class with the specified user name, password and domain.
      network_credential(const xtd::string& user_name, const xtd::string& password, const xtd::string& domain);
      /// @}
      
      /// @cond
      network_credential(network_credential&& network_credential) = default;
      network_credential(const network_credential& network_credential) = default;
      auto operator =(network_credential&&) -> network_credential& = default;
      auto operator =(const network_credential&) -> network_credential& = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the domain or computer name that verifies the credentials.
      /// @return The name of the domain associated with the credentials.
      /// @remarks The xtd::net::network_credential::domain property specifies the domain or realm to which the user name belongs. Typically, this is the host computer name where the application runs or the user domain for the currently logged in user.
      [[nodiscard]] auto domain() const noexcept -> const xtd::string&;
      /// @brief Sets the domain or computer name that verifies the credentials.
      /// @param value The name of the domain associated with the credentials.
      /// @remarks The xtd::net::network_credential::domain property specifies the domain or realm to which the user name belongs. Typically, this is the host computer name where the application runs or the user domain for the currently logged in user.
      auto domain(const xtd::string& value) noexcept -> network_credential&;
      
      /// @brief Gets the password for the user name associated with the credentials.
      /// @return The password associated with the credentials. If this xtd::net::network_credential instance was initialized with the password parameter set to empty (""), then the xtd::net::network_credential::password property will return an empty string.
      [[nodiscard]] auto password() const noexcept -> xtd::string;
      /// @brief Sets the password for the user name associated with the credentials.
      /// @param value The password associated with the credentials. If this xtd::net::network_credential instance was initialized with the password parameter set to empty (""), then the xtd::net::network_credential::password property will return an empty string.
      auto password(const xtd::string& value) noexcept -> network_credential&;
      
      /// @brief Gets the password as a xtd::security::secure_string instance.
      /// @return The password for the user name associated with the credentials.
      [[nodiscard]] auto secure_password() const noexcept -> const xtd::security::secure_string&;
      /// @brief Sets the password as a xtd::security::secure_string instance.
      /// @param value The password for the user name associated with the credentials.
      auto secure_password(const xtd::security::secure_string& value) noexcept -> network_credential&;
      
      /// @brief Gets the user name associated with the credentials.
      /// @return The user name associated with the credentials.
      [[nodiscard]] auto user_name() const noexcept -> const xtd::string&;
      /// @brief Sets the user name associated with the credentials.
      /// @param value The user name associated with the credentials.
      auto user_name(const xtd::string& value) noexcept -> network_credential&;
      /// @}
      
    private:
      xtd::string user_name_;
      xtd::security::secure_string password_;
      xtd::string domain_;
    };
  }
}
