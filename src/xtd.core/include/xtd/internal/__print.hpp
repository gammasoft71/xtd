/// @file
/// @brief Contains __xtd_print_with_file_write__ and __xtd_print_with_ostream_write__ methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdio>
#include <ostream>
#include "../io/io_exception.hpp"
#include "../null_pointer_exception.hpp"

/// @cond
void __xtd_print_with_file_write__(FILE* file, const std::string& s) {
  if (!file) throw xtd::null_pointer_exception {};
  if (fwrite(s.c_str(), 1, s.length(), file) != s.length()) {
    auto exception = xtd::io::io_exception {};
    exception.h_result(errno);
    throw exception;
  }
}

void __xtd_print_with_ostream_write__(std::ostream& os, const std::string& s) {
  if (!os.good()) throw xtd::io::io_exception {};
  os.write(s.c_str(), s.length());
}
/// @endcond
