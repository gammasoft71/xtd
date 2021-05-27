/// @file
/// @brief Contains xtd::forms::vertical_control_layout_style class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control_layout_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    class vertical_control_layout_style : public control_layout_style {
    public:
      /// @brief Initialises a new instance of vertical control layout style class.
      vertical_control_layout_style() = default;
      
      /// @brief Gets the height value for a control.
      /// @return The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      float height() const {return height_;}
      /// @brief Sets the height value for a control.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      void height(float height) {height_ = height;}
      
    private:
      float height_ = 0;
    };
  }
}
