/// @file
/// @brief Contains xtd::forms::context_menu menu.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "menu.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a shortcut menu.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    class forms_export_ context_menu : public menu {
    public:
      /// @brief Initialoize context_menu class.
      context_menu();
      
      /// @cond
      ~context_menu();
      /// @endcond
      
    protected:
      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;
    };
  }
}
