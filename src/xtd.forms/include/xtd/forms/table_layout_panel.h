/// @file
/// @brief Contains xtd::forms::table_layout_panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of fixed aligned controls.
    /// @par Header
    /// @code #include <xtd/forms/table_layout_panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @remarks Exactly the same as xtd::forms::panel container.
    /// @par Examples
    /// The following code example demonstrates the use of table_layout_panel container.
    /// @include table_layout_panel.cpp
    class table_layout_panel : public panel {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of fixed layout panel class.
      table_layout_panel() = default;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create();
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::table_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::table_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::table_layout_panel.
      /// @param name The name of the xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const control& parent);
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::table_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::table_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::table_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::table_layout_panel with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::table_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::table_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::table_layout_panel.
      /// @param name The name of the xtd::forms::table_layout_panel.
      /// @return New xtd::forms::table_layout_panel created.
      static table_layout_panel create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void on_layout(const xtd::event_args& e) override;
      /// @}
    };
  }
}
