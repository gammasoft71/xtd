/// @file
/// @brief Contains xtd::security::secure_string class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../string.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the underlying structure of the security system, including base classes for permissions.
  namespace security {
    /// @brief Represents text that should be kept confidential, such as by deleting it from computer memory when no longer needed. This class cannot be inherited.
    /// @par Header
    /// ```cpp
    /// #include <xtd/security/secure_string>
    /// ```
    /// @par Namespace
    /// xtd::security
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core security
    class secure_string final : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::security::secure_string class.
      secure_string() = default;
      
      /// @brief This API supports the product infrastructure and is not intended to be used directly from your code. Initializes a new instance of the xtd::security::secure_string class from a subarray of System.Char objects.
      /// @param value A pointer to an array of char.
      /// @param length The number of elements of value to include in the new instance.
      /// @remarks This constructor initializes the new xtd::security::secure_string object to the number of characters in value specified by length; the value of the instance is then encrypted.
      secure_string(const char value[], size_t length);
      /// @}
      
      /// @cond
      secure_string(secure_string&&) = default;
      secure_string(const secure_string&) = default;
      secure_string& operator =(const secure_string&) = default;
      bool empty() const noexcept;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets underlying encrypted data.
      /// @return The underlying encrypted data.
      intptr data() const noexcept;
      
      /// @brief Gets underlying encrypted data size.
      /// @return The underlying encrypted data size.
      size_t size() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Gets decrypted data.
      /// @brief A encrypted byte array.
      /// @warning This is a more convenient but less secure alternative to using xtd::security::secure_string::data.
      std::string to_unsecure_string() const noexcept;
      /// @}
      
    private:
      std::vector<xtd::byte> data_;
    };
  }
}
