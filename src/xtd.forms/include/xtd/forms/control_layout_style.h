/// @file
/// @brief Contains xtd::forms::control_layout_style class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "size_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class control_layout_style {
    protected:
      /// @brief Initialises a new instance of control layout style class.
      control_layout_style() = default;
      
      xtd::forms::size_type size_type() const {return size_type_;}
      void size_type(xtd::forms::size_type size_type) {size_type_ = size_type;}

    private:
      xtd::forms::size_type size_type_ = xtd::forms::size_type::auto_size;
    };
  }
}
