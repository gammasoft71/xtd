/// @file
/// @brief Contains xtd::forms::container_control class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "scrollable_control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides focus-management functionality for controls that can function as a container for other controls.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/container_control>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks A container_control represents a control that can function as a container for other controls and provides focus management. Controls that inherit from this class can track the active control they contain, even when the focus moves somewhere within a different container.
    /// @remarks container_control objects provide a logical boundary for contained controls. The container control can capture the TAB key press and move focus to the next control in the collection.
    /// @note The container control does not receive focus; the focus is always set to the first child control in the collection of contained controls.
    /// @remarks You do not typically inherit directly from the container_control class. form, user_control, and up_down_base classes inherit from container_control.
    class forms_export_ container_control : public scrollable_control {
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the active control on the container control.
      /// @return The control that is currently active on the container_control.
      std::optional<control_ref> active_control() const noexcept;
      /// @brief Sets the active control on the container control.
      /// @param active_control The control that is currently active on the container_control.
      void active_control(const control& active_control);
      /// @brief Resets the active control on the container control.
      /// @param nullptr.
      void active_control(std::nullptr_t);
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the container_control class.
      container_control();
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      /// @}
      
      /// @cond
      std::optional<control_ref> active_control_;
      /// @endcond
    };
  }
}
