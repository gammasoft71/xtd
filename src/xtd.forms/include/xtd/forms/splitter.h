/// @file
/// @brief Contains xtd::forms::splitter control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "splitter_style.h"
#include <xtd/argument_exception>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a splitter control that enables the user to resize docked controls.
    /// @par Header
    /// @code #include <xtd/forms/splitter> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of splitter control.
    /// @include splitter.cpp
    class forms_export_ splitter : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the splitter class.
      splitter();
      /// @}
      
      /// @name Properties
      
      /// @{
      using xtd::forms::control::dock;
      /// @brief Sets or sets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @param dock One of the dock_style values. The default is none.
      /// @return Current control.
      /// @remarks Use the dock property to define how a control is automatically resized as its parent control is resized. For example, setting dock to dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the dock property in a derived class, use the base class's dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the dock property; you can override only one if needed.
      control& dock(dock_style dock) override;
      
      /// @brief Gets the minimum distance that must remain between the splitter control and the container edge that the control is docked to.
      /// @return The minimum distance, in pixels, between the splitter control and the container edge that the control is docked to. The default is 25.
      virtual int32 min_size() const noexcept;
      /// @brief Sets the minimum distance that must remain between the splitter control and the container edge that the control is docked to.
      /// @param min_size The minimum distance, in pixels, between the splitter control and the container edge that the control is docked to. The default is 25.
      /// @return Current splitter instance.
      virtual splitter& min_size(int32 min_size);
      
      /// @brief Gets the style of the splitter.
      /// @return One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      virtual xtd::forms::splitter_style splitter_style() const noexcept;
      /// @brief Sets the style of the splitter.
      /// @param splitter_style One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      /// @return Current splitter instance.
      virtual splitter& splitter_style(xtd::forms::splitter_style splitter_style);
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create();
      /// @brief A factory to create an xtd::forms::splitter with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::splitter with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::splitter with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter.
      /// @param name The name of the xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::splitter with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const control& parent);
      /// @brief A factory to create an xtd::forms::splitter with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::splitter.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::splitter with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::splitter.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::splitter with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::splitter.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter.
      /// @param name The name of the xtd::forms::splitter.
      /// @return New xtd::forms::splitter created.
      static splitter create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::cursor default_cursor() const noexcept override;
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      void on_mouse_down(const mouse_event_args& e) override;
      void on_mouse_move(const mouse_event_args& e) override;
      void on_mouse_up(const mouse_event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
