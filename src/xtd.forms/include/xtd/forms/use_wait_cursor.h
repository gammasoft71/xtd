/// @file
/// @brief Contains xtd::forms::use_wait_cursor class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/object.h>
#include "application.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Creates a wait_cursor_class.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks Displays a wai cursor as long as the object instance is not destroyed.
    /// @par Examples
    /// The following code example demonstrate the use of use_wait_cursor class.
    /// @include use_wait_cursor.cpp
    /// @par Windows
    /// @image html use_wait_cursor_w.png
    /// <br>
    /// @image html use_wait_cursor_wd.png
    /// @par macOS
    /// @image html use_wait_cursor_m.png
    /// <br>
    /// @image html use_wait_cursor_md.png
    /// @par Gnome
    /// @image html use_wait_cursor_g.png
    /// <br>
    /// @image html use_wait_cursor_gd.png
    class use_wait_cursor : public object {
    public:
      /// @brief Initializes a new instance of use_wait_cursor class.
      /// @remarks The xtd::forms::application::use_wait_cursor(true) is called in the constructor and xtd::forms::application::use_wait_cursor(false) is called in the destructor.
      use_wait_cursor() {xtd::forms::application::use_wait_cursor(true);}
      /// @cond
      ~use_wait_cursor() {xtd::forms::application::use_wait_cursor(false);}
      /// @endcond
    };
  }
}
