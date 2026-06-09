/// @file
/// @brief Contains xtd::forms::scrollable_control control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "system_information.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Defines a base class for controls that support auto-scrolling behavior.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/scrollable_control>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ scrollable_control : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @return `true` if the container enables auto-scrolling; otherwise, `false`. The default value is `false`.
      [[nodiscard]] virtual auto auto_scroll() const noexcept -> bool;
      /// @brief Sets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @param value `true` if the container enables auto-scrolling; otherwise, `false`. The default value is `false`.
      /// @return Current scrollable_control instance.
      virtual auto auto_scroll(bool value) -> scrollable_control&;
      
      /// @brief Gets the size of the auto-scroll margin.
      /// @return A size that represents the height and width of the auto-scroll margin in pixels.
      [[nodiscard]] auto auto_scroll_margin() const noexcept -> xtd::drawing::size;
      /// @brief Sets the size of the auto-scroll margin.
      /// @param value A size that represents the height and width of the auto-scroll margin in pixels.
      /// @return Current scrollable_control instance.
      auto auto_scroll_margin(const xtd::drawing::size& value) -> scrollable_control&;
      
      /// @brief Gets the rectangle that represents the virtual display area of the control.
      /// @return A rectangle that represents the display area of the control.
      [[nodiscard]] auto display_rectangle() const noexcept -> xtd::drawing::rectangle override;
      
      /// @brief Gets a value indicating whether the horizontal scroll bar is visible.
      /// @return `true` if the horizontal scroll bar is visible; otherwise, `false`.
      [[nodiscard]] virtual auto h_scroll() const noexcept -> bool;
      /// @brief Sets a value indicating whether the horizontal scroll bar is visible.
      /// @param value `true` if the horizontal scroll bar is visible; otherwise, `false`.
      /// @return Current scrollable_control instance.
      virtual auto h_scroll(bool value) -> scrollable_control&;
      
      /// @brief Gets a value indicating whether the vertical scroll bar is visible.
      /// @return `true` if the vertical scroll bar is visible; otherwise, `false`.
      [[nodiscard]] virtual auto v_scroll() const noexcept -> bool;
      /// @brief Sets a value indicating whether the vertical scroll bar is visible.
      /// @param value `true` if the vertical scroll bar is visible; otherwise, `false`.
      /// @return Current scrollable_control instance.
      virtual auto v_scroll(bool value) -> scrollable_control&;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initialize a new instance of scrollable_control class.
      scrollable_control();
      /// @}
      
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      auto on_layout(const event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
