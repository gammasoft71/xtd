/// @file
/// @brief Contains __xtd_print_with_file_write__ and __xtd_print_with_ostream_write__ methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdio>
#include <ostream>
#include "../io/io_exception.hpp"
#include "../environment.hpp"
#include "../null_pointer_exception.hpp"

/// @cond
inline auto __xtd_print_with_file_write__(bool new_line, FILE* file, xtd::string&& s) -> void {
  if (!file) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  if (new_line) s += xtd::environment::new_line();
  if (fwrite(s.chars().c_str(), 1, s.length(), file) != s.length())
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
}

inline auto __xtd_print_with_ostream_write__(bool new_line, std::ostream& os, xtd::string&& s) -> void {
  if (!os.good()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
  if (new_line) s += xtd::environment::new_line();
  os.write(s.chars().c_str(), s.length());
}
/// @endcond
