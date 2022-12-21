/// @file
/// @brief Contains internal char8_t type.
#pragma once
/// @cond
#if !defined(__XTD_CORE_CHAR8_T_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <iostream>
#include <string>

/// @cond
#if !defined(__cpp_lib_char8_t)
class char8_t {
public:
  char8_t() {}
  char8_t(char value) : value_(value) {}
  char8_t(const char8_t&) = default;
  char8_t(char8_t&&) = default;
  
  operator char() const {return value_;}
  bool operator ==(char8_t c) const {return value_ == c.value_;}
  bool operator !=(char8_t c) const {return value_ != c.value_;}
  bool operator <(char8_t c) const {return value_ < c.value_;}
  bool operator >(char8_t c) const {return value_ > c.value_;}
  bool operator <=(char8_t c) const {return value_ <= c.value_;}
  bool operator >=(char8_t c) const {return value_ >= c.value_;}
  
  char8_t operator +(char8_t c) const {return char8_t(value_ + c.value_);}
  char8_t operator -(char8_t c) const {return char8_t(value_ - c.value_);}
  char8_t& operator =(char8_t c) {value_ = c.value_; return *this;}
  char8_t& operator ++() {value_ += 1; return *this;}
  char8_t operator ++(int) {char8_t result(*this); ++(*this); return result;}
  char8_t& operator --() {value_ -= 1; return *this;}
  char8_t operator --(int) {char8_t result(*this); --(*this); return result;}
  
  bool operator ==(char c) const {return value_ == c;}
  bool operator !=(char c) const {return value_ != c;}
  bool operator <(char c) const {return value_ < c;}
  bool operator >(char c) const {return value_ > c;}
  bool operator <=(char c) const {return value_ <= c;}
  bool operator >=(char c) const {return value_ >= c;}
  
  friend std::ostream& operator <<(std::ostream& os, const char8_t& c) noexcept {return os << std::to_string(static_cast<int>(c.value_));}
  
private:
  char value_ = 0;
};

namespace std {
  using u8string = basic_string<char8_t>;
}
#endif
/// @endcond
