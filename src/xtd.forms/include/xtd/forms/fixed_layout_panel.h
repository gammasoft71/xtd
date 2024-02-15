/// @file
/// @brief Contains xtd::forms::fixed_layout_panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of fixed aligned controls.
    /// @par Header
    /// @code #include <xtd/forms/fixed_layout_panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @remarks Exactly the same as xtd::forms::panel container.
    /// @par Examples
    /// The following code example demonstrates the use of fixed_layout_panel container.
    /// @include fixed_layout_panel.cpp
    class forms_export_ fixed_layout_panel : public panel {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of fixed layout panel class.
      fixed_layout_panel() = default;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::fixed_layout_panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::fixed_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::fixed_layout_panel.
      /// @param name The name of the xtd::forms::fixed_layout_panel.
      /// @return New xtd::forms::fixed_layout_panel created.
      static fixed_layout_panel create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::fixed_layout_panel with specified parent, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::fixed_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::fixed_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::fixed_layout_panel.
      /// @param name The name of the xtd::forms::fixed_layout_panel.
      /// @return New xtd::forms::fixed_layout_panel created.
      static fixed_layout_panel create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void on_layout(const xtd::event_args& e) override;
      /// @}
    };
  }
}
