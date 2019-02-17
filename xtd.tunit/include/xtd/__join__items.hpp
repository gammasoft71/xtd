/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include <sstream>
#include <string>

/// @cond

template<typename TCollection>
std::string __join__items(const TCollection& collection) {
  std::stringstream ss;
  bool first = true;
  for (const auto& item : collection) {
    if (!first) ss << ", ";
    ss << std::to_string(item);
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
