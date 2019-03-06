/// @file
/// @brief Contains__join__items functions.
#pragma once
#include <sstream>
#include <string>

/// @cond
namespace std {
  inline const std::string& to_string(const std::string& s) {return s;}
}

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
