/// @file
/// @brief Contains xtd::security::secure_string class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the underlying structure of the common language runtime security system, including base classes for permissions.
  namespace security {
    /// @brief Represents text that should be kept confidential, such as by deleting it from computer memory when no longer needed. This class cannot be inherited.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core security
    class secure_string : public xtd::object {
    public:
      /// @brief Initializes a new instance of the xtd::security::secure_string class.
      secure_string() = default;

      /// @brief This API supports the product infrastructure and is not intended to be used directly from your code. Initializes a new instance of the SecureString class from a subarray of System.Char objects.
      /// @param value A pointer to an array of char.
      /// @param length The number of elements of value to include in the new instance.
      /// @remarks This constructor initializes the new SecureString object to the number of characters in value specified by length; the value of the instance is then encrypted.
      secure_string(const char value[], size_t length);

      /// @cond
      secure_string(secure_string&&) = default;
      secure_string(const secure_string&) = default;
      secure_string& operator=(const secure_string&) = default;
      bool empty() const noexcept;
      /// @endcond

      /// @brief Gets underlying ripted data.
      /// @return The underlying cripted data.
      intptr_t data() const noexcept;
      
      /// @brief Gets underlying cripted data size.
      /// @return The underlying cripted data size.
      size_t size() const noexcept;
      
      /// @brief Gets decripted data.
      /// @brief A encrypted byte array.
      /// @warning This is a more convenient but less secure alternative to using xtd::security::secure_string::data.
      std::string to_unsecure_string() const noexcept;
      
    private:
      std::vector<byte_t> data_;
    };
  }
}
