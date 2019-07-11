/// @file
/// @brief Contains xtd::format class.
#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent format output manipulator class.
  /// @see xtd::basic_console<Char>::format(const std::basic_string<Char>& format, Args&& ... args) method.
  class format final {
  public:
    template<typename Char, typename ... Args>
    format(const std::basic_string<Char>& format, Args&& ... args) : value_(strings::format(format, std::forward<Args>(args)...)) {}
    
    template<typename Char, typename ... Args>
    format(const Char* format, Args&& ... args) : value_(strings::format(format, std::forward<Args>(args)...)) {}
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const format& fmt) {return os << fmt.value_;}
    /// @endcond

  private:
    std::string value_;
  };
}
