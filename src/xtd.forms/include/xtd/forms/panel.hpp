/// @file
/// @brief Contains xtd::forms::panel container.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.hpp"
#include "border_style.hpp"
#include "scrollable_control.hpp"
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of controls.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/panel>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// |       | Windows                               | macOS                                 | Gnome                                 |
    /// | ----- | ------------------------------------- | ------------------------------------- | ------------------------------------- |
    /// | Light |  @image html containers_panel_w.png   |  @image html containers_panel_m.png   |  @image html containers_panel_g.png   |
    /// | Dark  |  @image html containers_panel_wd.png  |  @image html containers_panel_md.png  |  @image html containers_panel_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of panel container.
    /// @include panel.cpp
    class forms_export_ panel : public xtd::forms::scrollable_control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of panel class.
      panel();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the mode by which the panel automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      [[nodiscard]] virtual auto auto_size_mode() const noexcept -> xtd::forms::auto_size_mode;
      /// @brief Sets the mode by which the panel automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current panel instance.
      virtual auto auto_size_mode(xtd::forms::auto_size_mode value) -> panel&;
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      [[nodiscard]] virtual auto border_sides() const noexcept -> xtd::forms::border_sides;
      /// @brief Sets the border sides for the control.
      /// @param value A bitwise combination of the border_sides values. The default is border_style::all.
      virtual auto border_sides(xtd::forms::border_sides value) -> panel&;
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      [[nodiscard]] virtual auto border_style() const noexcept -> xtd::forms::border_style;
      /// @brief Sets the border style for the control.
      /// @param value One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(xtd::forms::border_style value) -> panel&;
      /// @brief Resets the border style for the control.
      /// @param xtd::null.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(xtd::null_ptr) -> panel&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create() -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @param name The name of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> panel;
      /// @brief A factory to create an xtd::forms::panel with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @param name The name of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> panel;
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protetced methods
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      auto on_layout(const xtd::event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
