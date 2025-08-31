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
// Fallback implementation for std::source_location for compatibility reasons.
//
// Although std::source_location is part of C++20 and supported in recent compiler versions,
// the support on Apple platforms (Xcode/Clang) is still incomplete or inconsistent,
// especially on versions prior to Xcode 15.4.
//
// This fallback uses compiler builtins (__builtin_FILE, __builtin_LINE, etc.) to
// provide similar functionality without relying on std::source_location.
//
// We keep this fallback to ensure compatibility with older toolchains and to avoid
// breaking CI or user builds when newer Xcode versions are not available.
//
// Once support for std::source_location becomes reliable across all supported
// Xcode versions, this fallback can be removed.
//
// See: https://developer.apple.com/forums/thread/713513 for related discussion.
//
#include <cstdint>
#include <memory>

class __xtd_source_location__ {
public:
  const char* file_name() const noexcept {return data_->file;}
  std::uint32_t line() const noexcept {return data_->line;}
  const char* function_name() const noexcept {return data_->func;}
  std::uint32_t column() const noexcept {return data_->column;}
  
  static __xtd_source_location__ current(const char* file = __builtin_FILE(), std::uint32_t line = __builtin_LINE(), const char* func = __builtin_FUNCTION(), std::uint32_t column = __builtin_COLUMN()) noexcept {
    auto csl = __xtd_source_location__ {};
    *csl.data_ = {file, line, func, column};
    return csl;
  }
  
private:
  struct data {
    const char* file;
    std::uint32_t line;
    const char* func;
    std::uint32_t column;
  };
  std::shared_ptr<data> data_ = std::make_shared<data>();
};
#endif
/// @endcond
