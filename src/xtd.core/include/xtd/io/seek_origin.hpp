/// @file
/// @brief Contains xtd::io::seek_origin enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enum.hpp"
#include <ios>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Specifies the position in a stream to use for seeking.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class seek_origin {
      /// @brief Specifies the beginning of a stream.
      begin = std::ios_base::beg,
      /// @brief Specifies the current position within a stream.
      current = std::ios_base::cur,
      /// @brief Specifies the end of a stream.
      end = std::ios_base::end,
    };
  }
}


/// @cond
template<> struct xtd::enum_register<xtd::io::seek_origin> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::io::seek_origin> {{xtd::io::seek_origin::begin, L"begin"}, {xtd::io::seek_origin::current, L"current"}, {xtd::io::seek_origin::end, L"end"}};}
};
/// @endcond
