/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  class format final {
  public:
    template<typename ... Args>
    format(const std::string& format, Args&& ... args) : value_(console::format(format, args...)) {}

    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const format& fmt) {return os << fmt.value_;}
    /// @endcond

  private:
    std::string value_;
  };
}
