/// @file
/// @brief Contains xtd::forms::properties::resources class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../control.hpp"
#include <xtd/drawing/bitmap>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms::properties {
    /// @brief A strongly-typed resource class, for looking up localized strings, etc.
    /// @par Namespace
    /// xtd::forms::properties
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class resources final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      [[nodiscard]] static auto cursor_arrow() -> const xtd::drawing::bitmap&;
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      [[nodiscard]] static auto cursor_no_move_2d() -> const xtd::drawing::bitmap&;
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      [[nodiscard]] static auto gammasoft() -> const xtd::drawing::bitmap&;
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      [[nodiscard]] static auto xtd() -> const xtd::drawing::bitmap&;
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      [[nodiscard]] static auto xtd_console() -> const xtd::drawing::bitmap&;
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      [[nodiscard]] static auto xtd_forms() -> const xtd::drawing::bitmap&;
      /// @}
    };
  }
}
