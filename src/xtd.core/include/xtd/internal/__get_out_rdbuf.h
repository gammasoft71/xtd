/// @file
/// @brief Contains __get_out_rdbuf method.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <iostream>

/// @cond
template<class char_t>
inline std::basic_streambuf<char_t>* __get_out_rdbuf() {return nullptr;}

template<>
inline std::basic_streambuf<char>* __get_out_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cout.rdbuf();
  return rdbuf;
}

template<>
inline std::basic_streambuf<wchar_t>* __get_out_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcout.rdbuf();
  return rdbuf;
}
/// @endcond
