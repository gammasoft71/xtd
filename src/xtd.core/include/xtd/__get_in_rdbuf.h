/// @file
/// @brief Contains __get_in_rdbuf method.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <iostream>

/// @cond
template<class char_t>
inline std::basic_streambuf<char_t>* __get_in_rdbuf() {return nullptr;}

template<>
inline std::basic_streambuf<char>* __get_in_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cin.rdbuf();
  return rdbuf;
}

template<>
inline std::basic_streambuf<wchar_t>* __get_in_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcin.rdbuf();
  return rdbuf;
}
/// @endcond
