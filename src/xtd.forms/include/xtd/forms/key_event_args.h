/// @file
/// @brief Contains xtd::forms::key_event_args event args.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_args.h>
#include "keys.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the key_down or key_up event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks A key_event_args, which specifies the key the user pressed and whether any modifier keys (CMD, CTRL, ALT, and SHIFT) were pressed at the same time, is passed with each key_down or key_up event.
    /// @remarks The key_down event occurs when the user presses any key. The key_up event occurs when the user releases the key. Duplicate key_down events occur each time the key repeats, if the key is held down, but only one key_up event is generated when the user releases the key.
    /// @remarks The key_press event also occurs when a key is pressed. A key_press_event_args is passed with each key_press event, and specifies the character that was composed as a result of each key press.
    class key_event_args : public event_args {
    public:
      /// @brief Initializes a new instance of the key_event_args class.
      key_event_args() = default;
      /// @brief Initializes a new instance of the key_event_args class.
      /// @param key_data A xtd::forms::keys representing the key that was pressed, combined with any modifier flags that indicate which CMD, CTRL, SHIFT, and ALT keys were pressed at the same time. Possible values are obtained by applying the bitwise OR (|) operator to constants from the Keys enumeration.
      key_event_args(xtd::forms::keys key_data) : key_data_(key_data) {}
      /// @cond
      key_event_args(const xtd::forms::key_event_args& key_event_args) = default;
      key_event_args& operator=(const xtd::forms::key_event_args& key_event_args) = default;
      /// @endcond

      /// @brief Gets a value indicating whether the ALT key was pressed.
      /// @return true if the ALT key was pressed; otherwise, false.
      bool alt() const {return (key_data_ & xtd::forms::keys::alt) == keys::alt;}
      
      /// @brief Gets a value indicating whether the CMD key was pressed.
      /// @return true if the CMD key was pressed; otherwise, false.
      bool command() const {return (key_data_ & xtd::forms::keys::command) == keys::command;}
      
      /// @brief Gets a value indicating whether the CTRL key was pressed.
      /// @return true if the CTRL key was pressed; otherwise, false.
      bool control() const {return (key_data_ & xtd::forms::keys::control) == keys::control;}
      
      /// @brief Gets a value indicating whether the event was handled.
      /// @return true to bypass the control's default handling; otherwise, false to also pass the event along to the default control handler.
      /// @remarks handled is implemented differently by different controls within xtd.forms. For controls like text_box which subclass native Win32 controls, it is interpreted to mean that the key message should not be passed to the underlying native control. If you set handled to true on a text_box, that control will not pass the key press events to the underlying Win32 text box control, but it will still display the characters that the user typed.
      bool handled() const {return handled_;}
      /// @brief Sets a value indicating whether the event was handled.
      /// @param handled true to bypass the control's default handling; otherwise, false to also pass the event along to the default control handler.
      /// @remarks handled is implemented differently by different controls within xtd.forms. For controls like text_box which subclass native Win32 controls, it is interpreted to mean that the key message should not be passed to the underlying native control. If you set handled to true on a text_box, that control will not pass the key press events to the underlying Win32 text box control, but it will still display the characters that the user typed.
      void handled(bool handled) {handled_ = handled;}
      
      /// @brief Gets the keyboard code for a key_down or key_up event.
      /// @return A xtd::forms::keys value that is the key code for the event.
      keys key_code() const {return key_data_ & xtd::forms::keys::key_code;}
 
      /// @brief Gets the key data for a key_down or key_up event.
      /// @return A xtd::forms::keys representing the key code for the key that was pressed, combined with modifier flags that indicate which combination of CMD, CTRL, SHIFT, and ALT keys was pressed at the same time.
      /// @remarks You can use constants from Keys to extract information from the key_data property. Use the bitwise AND operator to compare data returned by key_data with constants in Keys to obtain information about which keys the user pressed. To determine whether a specific modifier key was pressed, use the command, control, shift, and alt properties.
      keys key_data() const {return key_data_;}
      
      /// @brief Gets the keyboard value for a key_down or key_up event.
      /// @return The integer representation of the key_code property.
      int key_value() const {return static_cast<int>(key_data_) & 0xFFFF;}

      /// @brief Gets the modifier flags for a key_down or key_up event. The flags indicate which combination of CMD, CTRL, SHIFT, and ALT keys was pressed.
      /// @return A xtd::forms::keys value representing one or more modifier flags.
      keys modifiers() const {return key_data_ & xtd::forms::keys::modifiers;}
      
      /// @brief Gets a value indicating whether the SHIFT key was pressed.
      /// @return true if the SHIFT key was pressed; otherwise, false.
      bool shift() const {return (key_data_ & xtd::forms::keys::shift) == keys::shift;}
      
      /// @brief Gets a value indicating whether the key event should be passed on to the underlying control.
      /// @return true if the key event should not be sent to the control; otherwise, false.
      /// @remarks You can assign true to this property in an event handler such as key_down in order to prevent user input.
      /// @remarks Setting suppress_key_press to true also sets handled to true.
      bool suppress_key_press() const {return suppress_key_press_;}
      /// @brief Sets a value indicating whether the key event should be passed on to the underlying control.
      /// @param suppress_key_press true if the key event should not be sent to the control; otherwise, false.
      /// @remarks You can assign true to this property in an event handler such as key_down in order to prevent user input.
      /// @remarks Setting suppress_key_press to true also sets handled to true.
      void suppress_key_press(bool suppress_key_press) {
        suppress_key_press_ = suppress_key_press;
        if (suppress_key_press) handled(true);
      }
      
    private:
      xtd::forms::keys key_data_;
      bool handled_ = false;
      bool suppress_key_press_ = false;
    };
  }
}
