/// @file
/// @brief Contains xtd::tunit::assert_error exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <stdexcept>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Exception thow when an assertion failed.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit exceptions
    class assert_error : public std::exception {
    public:
      /// @brief Create a new instance of assert_error class.
      /// @param message Message string associate to the error.
      explicit assert_error(const xtd::ustring& message) : message_(message) {}

      /// @brief Create a new instance of assert_error class.
      /// @param message Message string associate to the error.
      explicit assert_error(const char* message) : message_(message) {}

      /// @cond
      assert_error(const assert_error&) = default;
      assert_error& operator=(const assert_error&) = default;
      /// @endcond

      /// @brief Returns a string that represents the current assert_error.
      /// @return string A string that represents the current assert_error.
      const char* what() const noexcept {return message_.c_str();}
      
    private:
      xtd::ustring message_;
    };
  }
}
