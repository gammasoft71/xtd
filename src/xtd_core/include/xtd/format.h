/// @file
/// @brief Contains xtd::format class.
#pragma once
#include <iostream>
#include "strings.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent format output manipulator class.
  /// @see xtd::strings::format(const std::basic_string<char_t>& format, args_t&& ... args) method.
  class format final {
  public:
    template<typename char_t, typename ... args_t>
    format(const std::basic_string<char_t>& format, args_t&& ... args) : value_(strings::format(format, std::forward<args_t>(args)...)) {}
    
    template<typename char_t, typename ... args_t>
    format(const char_t* format, args_t&& ... args) : value_(strings::format(format, std::forward<args_t>(args)...)) {}
    
    /// @cond
    template<typename char_t>
    friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const format& fmt) {return os << fmt.value_;}
    /// @endcond

  private:
    std::string value_;
  };
}
