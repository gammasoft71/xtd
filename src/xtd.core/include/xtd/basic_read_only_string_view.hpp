/// @file
/// @brief Contains xtd::basic_read_only_string_view alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <string_view>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an object that can refer to a constant contiguous sequence of char_t with the first element of the sequence at position zero.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  template<typename char_t, typename traits_t = std::char_traits<char_t>>
  using basic_read_only_string_view = std::basic_string_view<char_t, traits_t>;
}
