/// @file
/// @brief Contains xtd::forms::splitter_panel container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class split_container;
  /// @endcond
  
    /// @brief Creates a panel that is associated with a split_container.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @remarks The constructor for this object is not public, so you cannot explicitly create a splitter_panel object.
    /// @remarks The splitter_panel is a member of its associated split_container rather than being a member of the underlying form. At design time, the splitter_panel is accessible through the panel1 or panel2 properties of split_container.
    class splitter_panel : public panel {
      friend class split_container;
    protected:
      /// @brief Initializes a new instance of splitter_panel.
      splitter_panel() = default;
    };
  }
}
