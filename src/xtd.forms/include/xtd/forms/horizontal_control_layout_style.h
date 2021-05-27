/// @file
/// @brief Contains xtd::forms::horizontal_control_layout_style class.
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
    /// @ingroup xtd_forms
    class horizontal_control_layout_style : public control_layout_style {
    public:
      /// @brief Initialises a new instance of horizontal control layout style class.
      horizontal_control_layout_style() = default;
      
      /// @brief Gets the width value for a control.
      /// @return The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      float width() const {return width_;}
      /// @brief Sets the width value for a control.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      void width(float width) {width_ = width;}

    private:
      float width_ = 0;
    };
  }
}
