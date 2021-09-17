/// @file
/// @brief Contains xtd::tunit::abort_error exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include <stdexcept>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Exception thow when abort.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit exceptions
    class abort_error : public std::exception {
    public:
      /// @brief Create a new instance of abort_error class.
      /// @param message Message string associate to the error.
      explicit abort_error(const xtd::ustring& message) : message_(message) {}

      /// @brief Create a new instance of abort_error class.
      /// @param message Message string associate to the error.
      explicit abort_error(const char* message) : message_(message) {}

      /// @cond
      abort_error(const abort_error&) = default;
      abort_error& operator=(const abort_error&) = default;
      /// @endcond

      /// @brief Returns a string that represents the current abort_error.
      /// @return string A string that represents the current abort_error.
      const char* what() const noexcept {return message_.c_str();}
      
    private:
      xtd::ustring message_;
    };
  }
}
