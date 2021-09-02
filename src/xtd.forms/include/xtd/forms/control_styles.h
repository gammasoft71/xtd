/// @file
/// @brief Contains xtd::forms::control_styles enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the style and behavior of a control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags  attribute that allows a bitwise combination of its member values.
    /// @remarks Controls use this enumeration in various properties and methods to specify functionality. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit (or bits) and the bool value to set the bit(s) to. For example, the following line code would enable double-buffering.
    /// @code
    /// my_control.set_style(control_styles::user_paint | control_styles::all_painting_in_wm_paint | double_buffer, true);
    /// @endcode
    /// @remarks If the all_painting_in_wm_paint bit is set to true, the window message WM_ERASEBKGND is ignored, and both on_paint_background and on_paint methods are called directly from the window message WM_PAINT. This generally reduces flicker unless other controls send the window message WM_ERASEBKGND to the control. You might send the window message WM_ERASEBKGRND to achieve a pseudo-transparent effect similar to supports_transparent_back_color; for example, a tool_bar with flat appearance does this.
    /// @remarks To fully enable double-buffering, you can set the optimized_double_buffer and all_painting_in_wm_paint bits to true. However the preferred method for enabling double buffering, which yields the same result, is to set the double_buffered property for the control to true.
    /// @remarks If the supports_transparent_back_color bit is set to true, and the back_color is set to a color whose alpha component is less than 255, on_paint_background will simulate transparency by asking its parent control to paint the background. This is not true transparency.
    /// @note If there is another control between the control and its parent, the current control will not show the control in the middle.
    /// @remarks When the user_mouse bit is set to true, the following methods are still called: control::on_mouse_down, control::on_mouse_up, control::on_mouse_enter, control::on_mouse_move, control::on_mouse_hover, control::on_mouse_leave, and control::on_mouse_wheel.
    /// @remarks When the control is clicked, if the standard_click bit is set to true the control::on_click method is called and it raises the control::click event. When the control is double-clicked, and both the standard_click and standard_double_click bits are set to true, the click is passed on to the double_click event. Then the Control::on_double_click method is called and it raises the control::double_click event. However, the control can call on_click or on_double_click directly regardless of the standard_click and standard_double_click bit values. For more information on control click and double click behaviors, see the control::click and control::double_click topics.
    /// @remarks When the use_text_for_accessibility bit is set and there is a value in the control's text property, the value of that control's text property determines the control's default active accessibility name and shortcut key. Otherwise, the text of the preceding label control will be used instead. This style is set by default. Certain built-in control types, such as text_box and combo_box, reset this style so that the text property of those controls will not be used by active accessibility.
    enum class control_styles {
      /// @brief No control style..
      none = 0,
      /// @brief If true, the control is a container-like control.
      container_control = 0b1,
      /// @brief If true, the control paints itself rather than the operating system doing so. If false, the paint event is not raised. This style only applies to classes derived from control.
      user_paint = 0b10,
      /// @brief If true, the control is drawn opaque and the background is not painted.
      opaque = 0b100,
      /// @brief If true, the control is redrawn when it is resized.
      resize_redraw = 0b10000,
      /// @brief If true, the control has a fixed width when auto-scaled. For example, if a layout operation attempts to rescale the control to accommodate a new font, the control's width remains unchanged.
      fixed_width = 0b100000,
      /// @brief If true, the control has a fixed height when auto-scaled. For example, if a layout operation attempts to rescale the control to accommodate a new font, the control's height remains unchanged.
      fixed_height = 0b1000000,
      /// @brief If true, the control implements the standard click behavior.
      standard_click = 0b100000000,
      /// @brief If true, the control can receive focus.
      selectable = 0b1000000000,
      /// @brief If true, the control does its own mouse processing, and mouse events are not handled by the operating system.
      user_mouse = 0b10000000000,
      /// @brief If true, the control accepts a BackColor with an alpha component of less than 255 to simulate transparency. Transparency will be simulated only if the UserPaint bit is set to true and the parent control is derived from Control.
      supports_transparent_back_color = 0b100000000000,
      /// @brief If true, the control implements the standard double_click behavior. This style is ignored if the standard_click bit is not set to true.
      standard_double_click = 0b1000000000000,
      /// @brief If true, the control ignores the window message WM_ERASEBKGND to reduce flicker. This style should only be applied if the user_paint bit is set to true.
      all_painting_in_wm_paint = 0b10000000000000,
      /// @brief If true, the control keeps a copy of the text rather than getting it from the handle each time it is needed. This style defaults to false. This behavior improves performance, but makes it difficult to keep the text synchronized.
      cache_text = 0b100000000000000,
      /// @brief If true, the on_notify_message(message&) method is called for every message sent to the control's wnd_proc(message&). This style defaults to false. enable_notify_message does not work in partial trust.
      enable_notify_message = 0b1000000000000000,
      /// @brief If true, drawing is performed in a buffer, and after it completes, the result is output to the screen. Double-buffering prevents flicker caused by the redrawing of the control. If you set double_buffer to true, you should also set user_paint and all_painting_in_wm_paint to true.
      double_buffer = 0b10000000000000000,
      /// @brief If true, the control is first drawn to a buffer rather than directly to the screen, which can reduce flicker. If you set this property to true, you should also set the all_painting_in_wm_paint to true.
      optimized_double_buffer = 0b100000000000000000,
      /// @brief Specifies that the value of the control's text property, if set, determines the control's default active accessibility name and shortcut key.
      use_text_for_accessibility = 0b1000000000000000000,
    };

    /// @cond
    inline control_styles& operator +=(control_styles& lhs, control_styles rhs) {lhs = static_cast<control_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline control_styles& operator -=(control_styles& lhs, control_styles rhs) {lhs = static_cast<control_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline control_styles& operator &=(control_styles& lhs, control_styles rhs) {lhs = static_cast<control_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline control_styles& operator |=(control_styles& lhs, control_styles rhs) {lhs = static_cast<control_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline control_styles& operator ^=(control_styles& lhs, control_styles rhs) {lhs = static_cast<control_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline control_styles operator +(control_styles lhs, control_styles rhs) {return static_cast<control_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline control_styles operator -(control_styles lhs, control_styles rhs) {return static_cast<control_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline control_styles operator ~(control_styles rhs) {return static_cast<control_styles>(~static_cast<long long>(rhs));}
    inline control_styles operator &(control_styles lhs, control_styles rhs) {return static_cast<control_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline control_styles operator |(control_styles lhs, control_styles rhs) {return static_cast<control_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline control_styles operator ^(control_styles lhs, control_styles rhs) {return static_cast<control_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, control_styles value) {return os << to_string(value, {{control_styles::container_control, "container_control"}, {control_styles::user_paint, "user_paint"}, {control_styles::opaque, "opaque"}, {control_styles::resize_redraw, "resize_redraw"}, {control_styles::fixed_width, "fixed_width"}, {control_styles::fixed_height, "fixed_height"}, {control_styles::standard_click, "standard_click"}, {control_styles::selectable, "selectable"}, {control_styles::user_mouse, "user_mouse"}, {control_styles::supports_transparent_back_color, "supports_transparent_back_color"}, {control_styles::standard_double_click, "standard_double_click"}, {control_styles::all_painting_in_wm_paint, "all_painting_in_wm_paint"}, {control_styles::cache_text, "cache_text"}, {control_styles::enable_notify_message, "enable_notify_message"}, {control_styles::double_buffer, "double_buffer"}, {control_styles::optimized_double_buffer, "optimized_double_buffer"}, {control_styles::use_text_for_accessibility, "use_text_for_accessibility"}});}
    inline std::wostream& operator<<(std::wostream& os, control_styles value) {return os << to_string(value, {{control_styles::container_control, L"container_control"}, {control_styles::user_paint, L"user_paint"}, {control_styles::opaque, L"opaque"}, {control_styles::resize_redraw, L"resize_redraw"}, {control_styles::fixed_width, L"fixed_width"}, {control_styles::fixed_height, L"fixed_height"}, {control_styles::standard_click, L"standard_click"}, {control_styles::selectable, L"selectable"}, {control_styles::user_mouse, L"user_mouse"}, {control_styles::supports_transparent_back_color, L"supports_transparent_back_color"}, {control_styles::standard_double_click, L"standard_double_click"}, {control_styles::all_painting_in_wm_paint, L"all_painting_in_wm_paint"}, {control_styles::cache_text, L"cache_text"}, {control_styles::enable_notify_message, L"enable_notify_message"}, {control_styles::double_buffer, L"double_buffer"}, {control_styles::optimized_double_buffer, L"optimized_double_buffer"}, {control_styles::use_text_for_accessibility, L"use_text_for_accessibility"}});}
    /// @endcond
  }
}
