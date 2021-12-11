/// @file
/// @brief Contains xtd::forms::tool_bar_separator container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "tool_bar_item.h"
#include <xtd/event.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a toolbar button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class tool_bar_separator : public tool_bar_item {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_separator class.
      tool_bar_separator() = default;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Generates a click event for the xtd::forms::tool_bar_item.
      void perform_click() override;
      /// @}
      
    protected:
    };
  }
}
