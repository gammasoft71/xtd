/// @file
/// @brief Contains xtd::forms::key_press_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_args>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::control::key_press event.
    /// @par Header
    /// @code #include <xtd/forms/key_press_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks A xtd::forms::key_press_event_args specifies the character that is composed when the user presses a key. For example, when the user presses SHIFT + K, the key_char property returns an uppercase K.
    /// @remarks A xtd::forms::control::key_press event occurs when the user presses a key. Two events that are closely related to the xtd::forms::control::key_press event are xtd::forms::control::key_up and xtd::forms::control::key_down. The xtd::forms::control::key_down event precedes each xtd::forms::control::key_press event when the user presses a key, and a xtd::forms::control::key_up event occurs when the user releases a key. When the user holds down a key, duplicate xtd::forms::control::key_down and xtd::forms::control::key_press events occur each time the character repeats. One xtd::forms::control::key_up event is generated upon release.
    /// @remarks With each xtd::forms::control::key_press event, a xtd::forms::key_press_event_args is passed. A key_event_args is passed with each xtd::forms::control::key_down and xtd::forms::control::key_up event. A key_event_args specifies whether any modifier keys (CMD, CTRL, SHIFT, or ALT) were pressed along with another key. (This modifier information can also be obtained through the modifier_keys property of the control class.)
    /// @remarks Set handled to true to cancel the xtd::forms::control::key_press event. This keeps the control from processing the key press.
    /// @note Some controls will process certain key strokes on xtd::forms::control::key_down. For example, rich_text_box processes the Enter key before xtd::forms::control::key_press is called. In such cases, you cannot cancel the xtd::forms::control::key_press event, and must cancel the key stroke from xtd::forms::control::key_down instead.
    class key_press_event_args : public event_args {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the KeyPressEventArgs class.
      /// @remarks Use the control::modifier_keys property to get the current state of the modifier keys.
      key_press_event_args() = default;
      /// @brief Initializes a new instance of the KeyPressEventArgs class.
      /// @param key_char The ASCII character corresponding to the key the user pressed.
      /// @remarks Use the control::modifier_keys property to get the current state of the modifier keys.
      explicit key_press_event_args(char32 key_char) : key_char_(key_char) {}
      /// @}
      
      /// @cond
      key_press_event_args(const key_press_event_args& key_press_event_args) = default;
      key_press_event_args& operator =(const key_press_event_args& key_press_event_args) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the xtd::forms::control::key_press event was handled.
      /// @return true if the event is handled; otherwise, false.
      /// @remarks If the event is not handled, it will be sent to the operating system for default processing. Set handled to true to cancel the xtd::forms::control::key_press event.
      bool handled() const noexcept {return handled_;}
      /// @brief Sets a value indicating whether the xtd::forms::control::key_press event was handled.
      /// @param handled true if the event is handled; otherwise, false.
      /// @remarks If the event is not handled, it will be sent to the operating system for default processing. Set handled to true to cancel the xtd::forms::control::key_press event.
      void handled(bool handled) {handled_ = handled;}
      
      /// @brief Gets the character corresponding to the key pressed.
      /// @return The ASCII character that is composed. For example, if the user presses SHIFT + K, this property returns an uppercase K.
      /// @remarks Use the key_char property to sample keystrokes at run time and to modify keystrokes under special run-time circumstances. For example, you can use key_char to disable non-numeric keypresses when the user enters a ZIP code, change all alphabetical keypresses to uppercase in a data entry field, or monitor the keyboard or other key input device for specific key combinations.
      /// @remarks You can get or set the following keys:
      /// * a-z, A-Z.
      /// * CTRL.
      /// * Punctuation marks.
      /// * Number keys, both across the top of the keyboard and on the numeric keypad.
      /// * ENTER.
      /// @remarks You cannot get or set the following keys:
      /// * The TAB key
      /// * INSERT and DELETE.
      /// * HOME.
      /// * END.
      /// * PAGE UP and PAGE DOWN.
      /// * F1-F2.
      /// * CMD and ALT.
      /// * Arrow keys.
      /// @note For information about how to detect any of the non-character keys mentioned above, see the key_event_args class.
      char32 key_char() const noexcept {return key_char_;}
      /// @brief Sets the character corresponding to the key pressed.
      /// @param key_char The ASCII character that is composed. For example, if the user presses SHIFT + K, this property returns an uppercase K.
      /// @remarks Use the key_char property to sample keystrokes at run time and to modify keystrokes under special run-time circumstances. For example, you can use key_char to disable non-numeric keypresses when the user enters a ZIP code, change all alphabetical keypresses to uppercase in a data entry field, or monitor the keyboard or other key input device for specific key combinations.
      /// @remarks You can get or set the following keys:
      /// * a-z, A-Z.
      /// * CTRL.
      /// * Punctuation marks.
      /// * Number keys, both across the top of the keyboard and on the numeric keypad.
      /// * ENTER.
      /// @remarks You cannot get or set the following keys:
      /// * The TAB key
      /// * INSERT and DELETE.
      /// * HOME.
      /// * END.
      /// * PAGE UP and PAGE DOWN.
      /// * F1-F2.
      /// * CMD and ALT.
      /// * Arrow keys.
      /// @note For information about how to detect any of the non-character keys mentioned above, see the key_event_args class.
      void key_char(char32 key_char) {key_char_ = key_char;}
      /// @}
      
    private:
      char32 key_char_;
      bool handled_ = false;
    };
  }
}
