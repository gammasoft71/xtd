/// @file
/// @brief Contains xtd::forms::flow_layout_panel container.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "panel.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of fixed aligned controls.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/flow_layout_panel>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @remarks Exactly the same as xtd::forms::panel container.
    /// @par Examples
    /// The following code example demonstrates the use of flow_layout_panel container.
    /// @include flow_layout_panel.cpp
    class flow_layout_panel : public panel {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of fixed layout panel class.
      flow_layout_panel() = default;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create();
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::flow_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::flow_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::flow_layout_panel.
      /// @param name The name of the xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const control& parent);
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::flow_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::flow_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::flow_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::flow_layout_panel with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::flow_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::flow_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::flow_layout_panel.
      /// @param name The name of the xtd::forms::flow_layout_panel.
      /// @return New xtd::forms::flow_layout_panel created.
      static flow_layout_panel create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      xtd::uptr<xtd::object> clone() const override;
      
      void on_layout(const xtd::event_args& e) override;
      /// @}
    };
  }
}
