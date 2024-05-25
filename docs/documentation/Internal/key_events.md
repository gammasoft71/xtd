# Key events

## xtd keys

| Windows Physical Key | Linux Physical Key | macOS Physical Key | Windows Virtual Key      | Linux Virtual Key              | macOS Virtual Key             | xtd Key (xtd::forms::keys)                | Virtual Modifier Key                  | xtd Modifier Key (xtd::forms::keys) |
| -------------------- | ------------------ | ------------------ | ------------------------ | ------------------------------ | ----------------------------- | ----------------------------------------- | ------------------------------------- | ----------------------------------- |
| Shift Left           | Shift Left         | Shift Left         | VK_SHIFT    (0x00000010) | GDK_KEY_Shift_L   (0x0000FFE1) | kVK_Shift        (0x00000038) | shift_key                    (0x00000010) | VK_SHIFT_MODIFIER        (0x00010000) | shift                  (0x00010000) |
| Control Left         | Control Left       | Command Left       | VK_CONTROL  (0x00000011) | GDK_KEY_Control_L (0x0000FFE3) | kVK_Command      (0x00000037) | control_key/command_key      (0x00000011) | VK_CONTROL_MODIFIER      (0x00020000) | control/command        (0x00020000) |
| Alt Left             | Alt Left           | Option Left        | VK_MENU     (0x00000012) | GDK_KEY_Alt_L     (0x0000FFE9) | kVK_Option       (0x0000003A) | menu/option_key              (0x00000012) | VK_ALT_MODIFIER          (0x00040000) | alt/option             (0x00040000) |
| Windows Left         | Windows Left       | Control Left       | VK_LWIN     (0x0000005B) | GDK_KEY_Super_L   (0x0000FFEB) | kVK_Control      (0x0000003B) | lwin                         (0x0000005B) | VK_META_MODIFIER         (0x00100000) | meta                   (0x00100000) |
| Shift Right          | Shift Right        | Shift Right        | VK_SHIFT    (0x00000010) | GDK_KEY_Shift_R   (0x0000FFE2) | kVK_RightShift   (0x0000003C) | shift_key                    (0x00000010) | VK_SHIFT_MODIFIER        (0x00010000) | shift                  (0x00010000) |
| Control Right        | Control Right      | Command Right      | VK_CONTROL  (0x00000011) | GDK_KEY_Control_R (0x0000FFE4) | kVK_RightCommand (0x00000036) | control_key/command_key      (0x00000011) | VK_CONTROL_MODIFIER      (0x00020000) | control/command        (0x00020000) |
| Alt Right            | Alt Right          | Option Right       | VK_CONTROL + VK_MENU     | GDK_KEY_Alt_R     (0x0000FFEA) | kVK_RightOption  (0x0000003D) | control_key/command_key + menu/option_key | VK_CONTROL_MODIFIER + VK_ALT_MODIFIER | control/command + alt/option        |
| Windows Right        | Windows Right      | Control Right      | VK_RWIN     (0x0000005C) | GDK_KEY_Super_R   (0x0000FFEC) | kVK_RightControl (0x0000003E) | rwin                         (0x0000005C) | VK_META_MODIFIER         (0x00100000) | meta                   (0x00100000) |

## Remarks

* Windows Virual key codes : Winuser.h
* Linux Virual key codes : gdkkeysyms.h
* macOS Virual key codes : Events.h
* Alt Right on Linux seems to be : 0x0000FE03

## To do

* Remove `VK_COMMAND_MODIFIER` key.
* Set xtd::forms::keys::command = xtd::forms::keys::control.
* When convert key to virtual keys, on macOS platform swap meta and control keys :
  * Windows Left => VK_CONTROL
  * Windows Right => VK_CONTROL
  * Control Left => VK_LWIN
  * Control Right => VK_RWIN
* Fix workarounds on macOS and Linux platforms in control_handler key down and key up events.

## wxWidgets keys

| Windows Physical Key | Linux Physical Key | macOS Physical Key | Windows Raw Key        | Linux Raw Key | macOS Raw Key | wxWidgets - Windows Key press | wxWidgets - macOS Key press | wxWidgets - Linux Key press | wxWidgets - Windows Modifier | wxWidgets - macOS Modifier | wxWidgets - Linux Modifier |
| -------------------- | ------------------ | ------------------ | ---------------------- | ------------- | ------------- | ----------------------------- | --------------------------- | --------------------------- | ---------------------------- | -------------------------- | -------------------------- |
| Shift Left           | Shift Left         | Shift Left         | 0x00000010             | 0x0000FFE1    | 0x00000038    | WXK_SHIFT                     | WXK_SHIFT                   | WXK_SHIFT                   | Shift                        | Shift                      | Shift                      |
| Control Left         | Control Left       | Control Left       | 0x00000011             | 0x0000FFE3    | 0x0000003B    | WXK_COMMAND                   | WXK_RAW_CONTROL             | WXK_COMMAND                 | Control                      | Control                    | Control                    |
| Alt Left             | Alt Left           | Option Left        | 0x00000012             | 0x0000FFE9    | 0x0000003A    | WXK_ALT                       | WXK_ALT                     | WXK_ALT                     | Alt                          | Alt                        | Alt                        |
| Windows Left         | Windows Left       | Command Left       | 0x0000005B             | 0x0000FFEB    | 0x00000037    | WXK_WINDOWS_LEFT              | WXK_COMMAND                 | WXK_COMMAND                 | None                         | Command                    | Command                    |
| Shift Right          | Shift Right        | Shift Right        | 0x00000010             | 0x0000FFE2    | 0x0000003C    | WXK_SHIFT                     | WXK_SHIFT                   | WXK_SHIFT                   | Shift                        | Shift                      | Shift                      |
| Control Right        | Control Right      | Control Right      | 0x00000011             | 0x0000FFE4    | 0x0000003E    | WXK_COMMAND                   | WXK_RAW_CONTROL             | WXK_COMMAND                 | Control                      | Control                    | Control                    |
| Alt Right            | Alt Right          | Option Right       | 0x00000011, 0x00000012 | 0x0000FFEA    | 0x0000003D    | WXK_COMMAND, WXK_ALT          | WXK_ALT                     | WXK_NONE                    | Control, Alt                 | Alt                        | None (OnUp : Control, Alt) |
| Windows Right        | Windows Right      | Command Right      | 0x0000005C             | 0x0000FFEC    | 0x00000036    | WXK_WINDOWS_RIGHT             | WXK_COMMAND                 | WXK_ALT                     | None                         | Command                    | Meta                       |

## Remarks

* Option / Alt right on Windows send `VK_CONTROL` left followed by `VK_MENU` left keys and `Control` + `Alt` modifiers (`AltGr` modifier ?)...
