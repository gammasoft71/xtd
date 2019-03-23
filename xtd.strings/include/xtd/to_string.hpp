/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include "__format.hpp"
#include "istring.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"

#include <algorithm>
#include <iomanip>
#include <locale>
#include <sstream>
#include "strings.hpp"

template<typename Value>
std::string __format_to_string(const std::string& fmt, Value value) {return xtd::strings::formatf(xtd::strings::concat('%', fmt), value);}

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  inline std::string to_string(int value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(int value) {return to_string(value, "d");}

  inline std::string to_string(unsigned int value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(unsigned int value) {return to_string(value, "u");}

  inline std::string to_string(long value, const std::string& fmt) {return strings::formatf(fmt, value);}
  inline std::string to_string(long value) {return to_string(value, "ld");}

  inline std::string to_string(unsigned long value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(unsigned long value) {return to_string(value, "lu");}

  inline std::string to_string(long long value, const std::string& fmt) {return strings::formatf(fmt, value);}
  inline std::string to_string(long long value) {return to_string(value, "lld");}

  inline std::string to_string(unsigned long long value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(unsigned long long value) {return to_string(value, "llu");}

  inline std::string to_string(float value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(float value) {return to_string(value, ".2f");}

  inline std::string to_string(double value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(double value) {return to_string(value, ".2f");}

  inline std::string to_string(long double value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(long double value) {return to_string(value, ".2f");}

  inline std::string to_string(const std::string& value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(const std::string& value) {return to_string(value, "");}

  inline std::string to_string(const xtd::istring& value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(const xtd::istring& value) {return to_string(value, "s");}

  inline std::string to_string(const char* value, const std::string& fmt) {return __format_to_string(fmt, value);}
  inline std::string to_string(const char* value) {return to_string(value, "s");}

  template<typename Value>
  inline std::string to_string(Value value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
  }

  template<typename Value>
  inline std::string to_string(const Value& value, const std::string& fmt) {
    //static_assert(false, "to_string speciailisation not found");
    throw std::invalid_argument("to_string speciailisation not found");
    return xtd::strings::empty();
  }
}
