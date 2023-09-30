/// @file
/// @brief Contains xtd::forms::properties::resources class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../control.h"
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
      /// @name Methods
      
      /// @{
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& cursor_arrow();
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& cursor_no_move_2d();
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& gammasoft();
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd();
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd_console();
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd_forms();
      /// @}
    };
  }
}
