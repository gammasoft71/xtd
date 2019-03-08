/// @file
/// @brief Contains__join__items functions.
#pragma once
#include "default_insert_basic_ostream_operator.hpp"
#include <sstream>
#include <string>

/// @cond
template<typename TCollection>
std::string __join__items(const TCollection& collection) {
  std::stringstream ss;
  bool first = true;
  for (const auto& item : collection) {
    if (!first) ss << ", ";
    ss << __to_string(item);
    first = false;
  }
  return ss.str();
}

template<>
inline std::string __join__items<std::string>(const std::string& collection) {
  std::stringstream ss;
  bool first = true;
  for (const char& item : collection) {
    if (!first) ss << ", ";
    ss << '\'' << item << '\'';
    first = false;
  }
  return ss.str();
}
/// @endcond
