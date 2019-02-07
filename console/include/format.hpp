/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  class format final {
  public:
    template<typename ... Args>
    format(const std::string& format, Args&& ... args) : value_(console::format(format, args...)) {}

    /// @cond
    friend std::ostream& operator <<(std::ostream& os, const format& fmt) {return os << fmt.value_;}
    /// @endcond

  private:
    std::string value_;
  };
}
