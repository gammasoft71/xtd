/// @file
/// @brief Contains xtd::tunit::assert_exception class.
#pragma once
#include <stdexcept>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    class assert_error : public std::exception {
    public:
      assert_error(const std::string& message) : message_(message) {}
      assert_error(const char* message) : message_(message) {}

      /// @cond
      assert_error(const assert_error&) = default;
      assert_error& operator=(const assert_error&) = default;
      /// @endcond

      const char* what() const noexcept {return this->message_.c_str();}
      
    private:
      std::string message_;
    };
  }
}
