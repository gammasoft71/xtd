/// @file
/// @brief Contains xtd::forms::scrollable_control control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "system_information.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Defines a base class for controls that support auto-scrolling behavior.
    /// @par Header
    /// @code #include <xtd/forms/scrollable_control> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ scrollable_control : public control {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @return true if the container enables auto-scrolling; otherwise, false. The default value is false.
      virtual bool auto_scroll() const noexcept;
      /// @brief Sets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @param auto_scroll true if the container enables auto-scrolling; otherwise, false. The default value is false.
      /// @return Current scrollable_control instance.
      virtual scrollable_control& auto_scroll(bool auto_scroll);
      
      /// @brief Gets the size of the auto-scroll margin.
      /// @return A size that represents the height and width of the auto-scroll margin in pixels.
      drawing::size auto_scroll_margin() const noexcept;
      /// @brief Sets the size of the auto-scroll margin.
      /// @param value A size that represents the height and width of the auto-scroll margin in pixels.
      /// @return Current scrollable_control instance.
      scrollable_control& auto_scroll_margin(const drawing::size& value);
      
      /// @brief Gets the rectangle that represents the virtual display area of the control.
      /// @return A rectangle that represents the display area of the control.
      drawing::rectangle display_rectangle() const noexcept override;
      
      /// @brief Gets a value indicating whether the horizontal scroll bar is visible.
      /// @return true if the horizontal scroll bar is visible; otherwise, false.
      virtual bool h_scroll() const noexcept;
      /// @brief Sets a value indicating whether the horizontal scroll bar is visible.
      /// @param hscrooll true if the horizontal scroll bar is visible; otherwise, false.
      /// @return Current scrollable_control instance.
      virtual scrollable_control& h_scroll(bool h_scroll);
      
      /// @brief Gets a value indicating whether the vertical scroll bar is visible.
      /// @return true if the vertical scroll bar is visible; otherwise, false.
      virtual bool v_scroll() const noexcept;
      /// @brief Sets a value indicating whether the vertical scroll bar is visible.
      /// @param vscroll true if the vertical scroll bar is visible; otherwise, false.
      /// @return Current scrollable_control instance.
      virtual scrollable_control& v_scroll(bool v_scroll);
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initialize a new instance of scrollable_control class.
      scrollable_control();
      /// @}
      
      /// @name Protected Properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      void on_layout(const event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
