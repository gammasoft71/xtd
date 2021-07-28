/// @file
/// @brief Contains xtd::tunit::ignore_error exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include <stdexcept>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Exception thow when ignore.
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit exceptions
    class ignore_error : public std::exception {
    public:
      /// @brief Create a new instance of ignore_error class.
      /// @param message Message string associate to the error.
      explicit ignore_error(const xtd::ustring& message) : message_(message) {}

      /// @brief Create a new instance of ignore_error class.
      /// @param message Message string associate to the error.
      explicit ignore_error(const char* message) : message_(message) {}

      /// @cond
      ignore_error(const ignore_error&) = default;
      ignore_error& operator=(const ignore_error&) = default;
      /// @endcond

      /// @brief Returns a string that represents the current ignore_error.
      /// @return string A string that represents the current ignore_error.
      const char* what() const noexcept {return message_.c_str();}
      
    private:
      std::string message_;
    };
  }
}
