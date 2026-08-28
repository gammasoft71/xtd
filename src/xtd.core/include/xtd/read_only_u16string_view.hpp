/// @file
/// @brief Contains xtd::read_only_u16string_view alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "basic_read_only_string_view.hpp"
#include "char16.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an object that can refer to a constant contiguous sequence of char_t with the first element of the sequence at position zero.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  using read_only_u16string_view = xtd::basic_read_only_string_view<xtd::char16>;
}
