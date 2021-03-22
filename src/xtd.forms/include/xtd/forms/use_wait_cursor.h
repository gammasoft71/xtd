/// @file
/// @brief Contains xtd::forms::use_wait_cursor class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "application.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class use_wait_cursor {
    public:
      use_wait_cursor() {xtd::forms::application::use_wait_cursor(true);}
      ~use_wait_cursor() {xtd::forms::application::use_wait_cursor(false);}
    };
  }
}
