/// @file
/// @brief Contains __xtd_debugbreak definition.
#pragma once
/// @cond
#define __XTD_STD_INTERNAL__
#include "__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

#if defined(__xtd__cpp_lib_source_location)
#include <source_location>
using __xtd_source_location__ = std::source_location;
#else
#include <cstdint>

#define __XTD_FILE__ __FILE__
#define __XTD_LINE__ __LINE__
#define __XTD_FUNC__ "<unknown>" // __func__
#define __XTD_COLUMN__ 0

class __xtd_source_location__ {
public:
  const char* file_name() const noexcept {return data_.file;}
  uint32_t line() const noexcept {return data_.line;}
  const char* function_name() const noexcept {return data_.func;}
  uint32_t column() const noexcept {return data_.column;}
  
  static __xtd_source_location__ current(const char* file = __XTD_FILE__, uint32_t line = __XTD_LINE__, const char* func = __XTD_FUNC__, uint32_t column = __XTD_COLUMN__) noexcept {
    auto csl = __xtd_source_location__ {};
    csl.data_ = {file, line, func, column};
    return csl;
  }
  
private:
  struct data {
    const char* file;
    uint32_t line;
    const char* func;
    uint32_t column;
  } data_;
};

#undef __XTD_FILE__
#undef __XTD_LINE__
#undef __XTD_FUNC__
#undef __XTD_COLUMN__
#endif
/// @endcond
