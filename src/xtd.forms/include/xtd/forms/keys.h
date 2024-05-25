/// @file
/// @brief Contains xtd::forms::keys enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies key codes and modifiers.
    /// @par Header
    /// @code #include <xtd/forms/keys> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The keys class contains constants for processing keyboard input. The members of the keys enumeration consist of a key code and a set of modifiers combined into a single integer value. In the Win32 application programming interface (API) a key value has two halves, with the high-order bits containing the key code (which is the same as a Windows virtual key code), and the low-order bits representing key modifiers such as the SHIFT, CONTROL, and ALT keys.
    /// @warning Do not use the values in this enumeration for combined bitwise operations. The values in the enumeration are not mutually exclusive.
    /// @note This enumeration provides no way to test whether the CAPS LOCK or NUM LOCK keys are currently activated. You can use one of the following techniques to determine if these keys are activated:
    /// * Call the IsKeyLocked method of the Control class.
    /// * For finer control, use the Win32 API functions GetKeyState, GetAsyncKeyState, or GetKeyboardState defined in user32.dll, to do this. For more information about calling native functions, see Consuming Unmanaged DLL Functions.
    /// @remarks The following table shows the key code values represented by two enumerated values, representing both the general original equipment manufacturer (OEM) keys and the more specific U.S.-keyboard associations.
    /// | Hexadecimal value | U.S. keyboard      | General OEM |
    /// | ----------------- | ------------------ | ----------- |
    /// | BA                | oem_semicolon      | oem1        |
    /// | BF                | oem_question       | oem2        |
    /// | C0                | oem_tilde          | oem3        |
    /// | DB                | oem_open_brackets  | oem4        |
    /// | DC                | oem_pipe           | oem5        |
    /// | DD                | oem_close_brackets | oem6        |
    /// | DE                | oem_quotes         | oem7        |
    /// | E2                | oem_backslash      | oem102      |
    /// @remarks On Apple platforms, references to xtd::forms::keys::control_key and xtd::forms::keys::control correspond to the `command` keys on the Macintosh keyboard, and references to xtd::forms::keys::lwin, xtd::forms::keys::rwin and xtd::forms::keys::meta correspond to the `control` keys. In effect, developers can use the same shortcut descriptions across all platforms, and their applications will automatically work as expected on Apple platforms.
    /// @par Examples
    /// The following code example uses the KeyDown event to determine the type of character entered into the control.
    /// @code
    /// // bool flag used to determine when a character other than a number is entered.
    /// bool non_number_entered = false;
    ///
    /// // Handle the KeyDown event to determine the type of character entered into the control.
    /// void text_box1_key_down(object& sender, key_event_args& e) {
    ///   // Initialize the flag to false.
    ///   non_number_entered = false;
    ///
    ///   // Determine whether the keystroke is a number from the top of the keyboard.
    ///   if (e.key_code() < keys::d0 || e.key_code() > keys::d9) {
    ///     // Determine whether the keystroke is a number from the keypad.
    ///     if (e.key_code() < keys::num_pad0 || e.key_code() > keys::num_pad9) {
    ///       // Determine whether the keystroke is a backspace.
    ///       if(e.key_code() != keys::back) {
    ///         // A non-numerical keystroke was pressed.
    ///         // Set the flag to true and evaluate in xtd::forms::control::key_press event.
    ///         non_number_entered = true;
    ///       }
    ///     }
    ///   }
    ///   //If shift key was pressed, it's not a number.
    ///   if (control::modifier_keys() == keys::Shift) {
    ///     non_number_entered = true;
    ///   }
    /// }
    ///
    /// // This event occurs after the KeyDown event and can be used to prevent
    /// // characters from entering the control.
    /// void text_box1_key_press(object& sender, xtd::forms::key_press_event_args& e) {
    ///   // Check for the flag being set in the xtd::forms::control::key_down event.
    ///   if (non_number_entered == true) {
    ///     // Stop the character from being entered into the control since it is non-numerical.
    ///     e.handled(true);
    ///   }
    /// }
    /// @endcode
    enum class keys : long long {
      /// @brief No key pressed.
      none = 0x00000000,
      /// @brief The left mouse button.
      lbutton = 0x00000001,
      /// @brief The right mouse button.
      rbutton = 0x00000002,
      /// @brief The CANCEL key.
      cancel = 0x00000003,
      /// @brief The middle mouse button (three-button mouse).
      mbutton = 0x00000004,
      /// @brief The first x mouse button (five-button mouse).
      xbutton1 = 0x00000005,
      /// @brief The second x mouse button (five-button mouse).
      xbutton2 = 0x00000006,
      /// @brief The BACK key.
      back = 0x00000008,
      /// @brief The TAB key.
      tab = 0x00000009,
      /// @brief The LINEFEED key.
      line_feed = 0x0000000A,
      /// @brief The CLEAR key.
      clear = 0x0000000C,
      /// @brief The ENTER key.
      enter = 0x0000000D,
      /// @brief The RETURN key.
      ret = enter,
      /// @brief The SHIFT key.
      shift_key = 0x00000010,
      /// @brief The CTRL key.
      control_key = 0x00000011,
      /// @brief The ALT key.
      menu = 0x00000012,
      /// @brief The PAUSE key.
      pause = 0x00000013,
      /// @brief The CAPS LOCK key.
      caps_lock = 0x00000014,
      /// @brief The CAPS LOCK key.
      capital = 0x00000014,
      /// @brief The IME Kana mode key.
      kana_mode = 0x00000015,
      /// @brief The IME Hanguel mode key. (maintained for compatibility; use HangulMode)
      hanguel_mode = 0x00000015,
      /// @brief The IME Hangul mode key.
      hangul_mode = 0x00000015,
      /// @brief The IME Junja mode key.
      junja_mode = 0x00000017,
      /// @brief The IME Final mode key.
      final_mode = 0x00000018,
      /// @brief The IME Kanji mode key.
      kanji_mode = 0x00000019,
      /// @brief The IME Hanja mode key.
      hanja_mode = 0x00000019,
      /// @brief The ESC key.
      escape = 0x0000001B,
      /// @brief The IME convert key.
      ime_convert = 0x0000001C,
      /// @brief The IME nonconvert key.
      ime_nonconvert = 0x0000001D,
      /// @brief The IME accept key.
      ime_accept = 0x0000001E,
      /// @brief The IME mode change key.
      ime_mode_change = 0x0000001F,
      /// @brief The SPACEBAR key.
      space = 0x00000020,
      /// @brief The PAGE UP key.
      page_up = 0x00000021,
      /// @brief The PAGE UP key.
      prior = page_up,
      /// @brief The PAGE DOWN key.
      page_down = 0x00000022,
      /// @brief The PAGE DOWN key.
      next = page_down,
      /// @brief The END key.
      end = 0x00000023,
      /// @brief The HOME key.
      home = 0x00000024,
      /// @brief The LEFT key.
      left = 0x00000025,
      /// @brief The UP key.
      up = 0x00000026,
      /// @brief The RIGHT key.
      right = 0x00000027,
      /// @brief The DOWN key.
      down = 0x00000028,
      /// @brief The SELECT key.
      select = 0x00000029,
      /// @brief The PRINT key.
      print = 0x0000002A,
      /// @brief The EXECUTE key.
      execute = 0x0000002B,
      /// @brief The PRINT SCREEN key.
      print_screen = 0x0000002C,
      /// @brief The PRINT SCREEN key.
      snapshot = print_screen,
      /// @brief The INSERT key.
      insert = 0x0000002D,
      /// @brief The DEL key.
      del = 0x0000002E,
      /// @brief The HELP key.
      help = 0x0000002F,
      /// @brief The 0 key.
      d0 = 0x00000030,
      /// @brief The 1 key.
      d1 = 0x00000031,
      /// @brief The 2 key.
      d2 = 0x00000032,
      /// @brief The 3 key.
      d3 = 0x00000033,
      /// @brief The 4 key.
      d4 = 0x00000034,
      /// @brief The 5 key.
      d5 = 0x00000035,
      /// @brief The 6 key.
      d6 = 0x00000036,
      /// @brief The 7 key.
      d7 = 0x00000037,
      /// @brief The 8 key.
      d8 = 0x00000038,
      /// @brief The 9 key.
      d9 = 0x00000039,
      /// @brief The A key.
      a = 0x00000041,
      /// @brief The B key.
      b = 0x00000042,
      /// @brief The C key.
      c = 0x00000043,
      /// @brief The D key.
      d = 0x00000044,
      /// @brief The E key.
      e = 0x00000045,
      /// @brief The F key.
      f = 0x00000046,
      /// @brief The G key.
      g = 0x00000047,
      /// @brief The H key.
      h = 0x00000048,
      /// @brief The I key.
      i = 0x00000049,
      /// @brief The J key.
      j = 0x0000004A,
      /// @brief The K key.
      k = 0x0000004B,
      /// @brief The L key.
      l = 0x0000004C,
      /// @brief The M key.
      m = 0x0000004D,
      /// @brief The N key.
      n = 0x0000004E,
      /// @brief The O key.
      o = 0x0000004F,
      /// @brief The P key.
      p = 0x00000050,
      /// @brief The Q key.
      q = 0x00000051,
      /// @brief The R key.
      r = 0x00000052,
      /// @brief The S key.
      s = 0x00000053,
      /// @brief The T key.
      t = 0x00000054,
      /// @brief The U key.
      u = 0x00000055,
      /// @brief The V key.
      v = 0x00000056,
      /// @brief The W key.
      w = 0x00000057,
      /// @brief The X key.
      x = 0x00000058,
      /// @brief The Y key.
      y = 0x00000059,
      /// @brief The Z key.
      z = 0x0000005A,
      /// @brief The left Windows logo key (Microsoft Natural Keyboard).
      lwin = 0x0000005B,
      /// @brief The right Windows logo key (Microsoft Natural Keyboard).
      rwin = 0x0000005C,
      /// @brief The application key (Microsoft Natural Keyboard).
      apps = 0x0000005D,
      /// @brief The computer sleep key.
      sleep = 0x0000005F,
      /// @brief The 0 key on the numeric keypad.
      num_pad0 = 0x00000060,
      /// @brief The 1 key on the numeric keypad.
      num_pad1 = 0x00000061,
      /// @brief The 2 key on the numeric keypad.
      num_pad2 = 0x00000062,
      /// @brief The 3 key on the numeric keypad.
      num_pad3 = 0x00000063,
      /// @brief The 4 key on the numeric keypad.
      num_pad4 = 0x00000064,
      /// @brief The 5 key on the numeric keypad.
      num_pad5 = 0x00000065,
      /// @brief The 6 key on the numeric keypad.
      num_pad6 = 0x00000066,
      /// @brief The 7 key on the numeric keypad.
      num_pad7 = 0x00000067,
      /// @brief The 8 key on the numeric keypad.
      num_pad8 = 0x00000068,
      /// @brief The 9 key on the numeric keypad.
      num_pad9 = 0x00000069,
      /// @brief The multiply key.
      multiply = 0x0000006A,
      /// @brief The add key.
      add = 0x0000006B,
      /// @brief The separator key.
      separator = 0x0000006C,
      /// @brief The subtract key.
      subtract = 0x0000006D,
      /// @brief The decimal key.
      decimal = 0x0000006E,
      /// @brief The divide key.
      divide = 0x0000006F,
      /// @brief The F1 key.
      f1 = 0x00000070,
      /// @brief The F2 key.
      f2 = 0x00000071,
      /// @brief The F3 key.
      f3 = 0x00000072,
      /// @brief The F4 key.
      f4 = 0x00000073,
      /// @brief The F5 key.
      f5 = 0x00000074,
      /// @brief The F6 key.
      f6 = 0x00000075,
      /// @brief The F7 key.
      f7 = 0x00000076,
      /// @brief The F8 key.
      f8 = 0x00000077,
      /// @brief The F9 key.
      f9 = 0x00000078,
      /// @brief The F10 key.
      f10 = 0x00000079,
      /// @brief The F11 key.
      f11 = 0x0000007A,
      /// @brief The F12 key.
      f12 = 0x0000007B,
      /// @brief The F13 key.
      f13 = 0x0000007C,
      /// @brief The F14 key.
      f14 = 0x0000007D,
      /// @brief The F15 key.
      f15 = 0x0000007E,
      /// @brief The F16 key.
      f16 = 0x0000007F,
      /// @brief The F17 key.
      f17 = 0x00000080,
      /// @brief The F18 key.
      f18 = 0x00000081,
      /// @brief The F19 key.
      f19 = 0x00000082,
      /// @brief The F20 key.
      f20 = 0x00000083,
      /// @brief The F21 key.
      f21 = 0x00000084,
      /// @brief The F22 key.
      f22 = 0x00000085,
      /// @brief The F23 key.
      f23 = 0x00000086,
      /// @brief The F24 key.
      f24 = 0x00000087,
      /// @brief The NUM LOCK key.
      num_lock = 0x00000090,
      /// @brief The SCROLL LOCK key.
      scroll = 0x00000091,
      /// @brief The left SHIFT key.
      lshift_key = 0x000000A0,
      /// @brief The right SHIFT key.
      rshift_key = 0x000000A1,
      /// @brief The left CTRL key.
      lcontrol_key = 0x000000A2,
      /// @brief The right CTRL key.
      rcontrol_key = 0x000000A3,
      /// @brief The left ALT key.
      lmenu = 0x000000A4,
      /// @brief The right ALT key.
      rmenu = 0x000000A5,
      /// @brief The browser back key.
      browser_back = 0x000000A6,
      /// @brief The browser forward key.
      browser_forward = 0x000000A7,
      /// @brief The browser refresh key.
      browser_refresh = 0x000000A8,
      /// @brief The browser stop key.
      browser_stop = 0x000000A9,
      /// @brief The browser search key.
      browser_search = 0x000000AA,
      /// @brief The browser favorites key.
      browser_favorites = 0x000000AB,
      /// @brief The browser home key.
      browser_home = 0x000000AC,
      /// @brief The volume mute key.
      volume_mute = 0x000000AD,
      /// @brief The volume down key.
      volume_down = 0x000000AE,
      /// @brief The volume up key.
      volume_up = 0x000000AF,
      /// @brief The media next track key.
      media_next_track = 0x000000B0,
      /// @brief The media previous track key.
      media_previous_track = 0x000000B1,
      /// @brief The media stop key.
      media_stop = 0x000000B2,
      /// @brief The media play pause key.
      media_play_pause = 0x000000B3,
      /// @brief The launch mail key.
      launch_mail = 0x000000B4,
      /// @brief The select media key.
      select_media = 0x000000B5,
      /// @brief The start application one key.
      launch_application1 = 0x000000B6,
      /// @brief The start application two key.
      launch_application2 = 0x000000B7,
      /// @brief The OEM Semicolon key on a US standard keyboard.
      oem_semicolon = 0x000000BA,
      /// @brief The OEM 1 key.
      oem1 = oem_semicolon,
      /// @brief The OEM plus key on any country/region keyboard.
      oem_plus = 0x000000BB,
      /// @brief The OEM comma key on any country/region keyboard.
      oem_comma = 0x000000BC,
      /// @brief The OEM minus key on any country/region keyboard.
      oem_minus = 0x000000BD,
      /// @brief The OEM period key on any country/region keyboard.
      oem_period = 0x000000BE,
      /// @brief The OEM question mark key on a US standard keyboard.
      oem_question = 0x000000BF,
      /// @brief The OEM 2 key.
      oem2 = oem_question,
      /// @brief The OEM tilde key on a US standard keyboard.
      oem_tilde = 0x000000C0,
      /// @brief The OEM 3 key.
      oem3 = oem_tilde,
      /// @brief The OEM open bracket key on a US standard keyboard.
      oem_open_brackets = 0x000000DB,
      /// @brief The OEM 4 key.
      oem4 = oem_open_brackets,
      /// @brief The OEM pipe key on a US standard keyboard.
      oem_pipe = 0x000000DC,
      /// @brief The OEM 5 key.
      oem5 = oem_pipe,
      /// @brief The OEM close bracket key on a US standard keyboard.
      oem_close_brackets = 0x000000DD,
      /// @brief The OEM 6 key.
      oem6 = oem_close_brackets,
      /// @brief The OEM singled/double quote key on a US standard keyboard.
      oem_quotes = 0x000000DE,
      /// @brief The OEM 7 key.
      oem7 = oem_quotes,
      /// @brief The OEM 8 key.
      oem8 = 0x000000DF,
      /// @brief The OEM angle bracket or backslash key on the RT 102 key keyboard.
      oem_backslash = 0x000000E2,
      /// @brief The OEM 102 key.
      oem102 = oem_backslash,
      /// @brief The PROCESS KEY key.
      process_key = 0x000000E5,
      /// @brief Used to pass Unicode characters as if they were keystrokes. The Packet key value is the low word of a 32-bit virtual-key value used for non-keyboard input methods.
      packet = 0x000000E7,
      /// @brief The ATTN key.
      attn = 0x000000F6,
      /// @brief The CRSEL key.
      crsel = 0x000000F7,
      /// @brief The EXSEL key.
      exsel = 0x000000F8,
      /// @brief The ERASE EOF key.
      erase_eof = 0x000000F9,
      /// @brief The PLAY key.
      play = 0x000000FA,
      /// @brief The ZOOM key.
      zoom = 0x000000FB,
      /// @brief A constant reserved for future use.
      no_name = 0x000000FC,
      /// @brief The PA1 key.
      pa1 = 0x000000FD,
      /// @brief The CLEAR key.
      oem_clear = 0x000000FE,
      /// @brief The CMD key.
      command_key = 0x00000100,
      /// @brief The left CMD key.
      lcommand_key = 0x00000101,
      /// @brief The right CMD key.
      rcommand_key = 0x00000102,
      /// @brief The FUNCTION key.
      function_key = 0x00000104,
      /// @brief The SHIFt modifier key.
      shift = 0x00010000,
      /// @brief The CTRL modifier key.
      /// @remarks On macOS, the xtd::forms::keys::control modifier value corresponds to the `command` keys on the keyboard, and the xtd::forms::keys::meta modifier value corresponds to the `control` keys.
      control = 0x00020000,
      /// @brief The CMD modifier key.
      /// @remarks The Apple keyboard xtd::forms::keys::command modifier key corresponding to the xtd::forms::keys::control modifier key.
      command = control,
      /// @brief The ALT modifier key.
      alt = 0x00040000,
      /// @brief The OPT modifier key.
      /// @remarks The Apple keyboard xtd::forms::keys::option modifier key corresponding to the xtd::forms::keys::alt modifier key.
      option = alt,
      /// @brief The METTA modifier key.
      /// @remarks OnWindows and Linux, the xtd::Forms::keys::meta modifier value corresponds to the Windows Left or Right keys.
      /// @remarks On macOS, the xtd::forms::keys::control modifier value corresponds to the `command` keys on the keyboard, and the xtd::forms::keys::meta modifier value corresponds to the `control` keys.
      meta = 0x00080000,
      /// @brief The FUNCTION modifier key.
      function = 0x00100000,
      /// @brief The bitmask to extract a key code from a key value.
      key_code = 0x0000FFFF,
      /// @brief The bitmask to extract modifiers from a key value.
      modifiers = 0xFFFF0000,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, keys);

template<> struct xtd::enum_register<xtd::forms::keys> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::keys> {{xtd::forms::keys::none, "none"}, {xtd::forms::keys::lbutton, "lbutton"}, {xtd::forms::keys::rbutton, "rbutton"}, {xtd::forms::keys::cancel, "cancel"}, {xtd::forms::keys::mbutton, "mbutton"}, {xtd::forms::keys::xbutton1, "xbutton1"}, {xtd::forms::keys::xbutton2, "xbutton2"}, {xtd::forms::keys::back, "back"}, {xtd::forms::keys::tab, "tab"}, {xtd::forms::keys::line_feed, "line_feed"}, {xtd::forms::keys::clear, "clear"}, /*{xtd::forms::keys::ret, "ret"},*/ {xtd::forms::keys::enter, "enter"}, {xtd::forms::keys::shift_key, "shift_key"}, {xtd::forms::keys::control_key, "control_key"}, {xtd::forms::keys::menu, "menu"}, {xtd::forms::keys::pause, "pause"}, {xtd::forms::keys::caps_lock, "caps_lock"}, /*{xtd::forms::keys::capital, "capital"},*/ {xtd::forms::keys::kana_mode, "kana_mode"}, /*{xtd::forms::keys::hanguel_mode, "hanguel_mode"}, {xtd::forms::keys::hangul_mode, "hangul_mode"},*/ {xtd::forms::keys::junja_mode, "junja_mode"}, {xtd::forms::keys::final_mode, "final_mode"}, {xtd::forms::keys::kanji_mode, "kanji_mode"}, /*{xtd::forms::keys::Hhnja_mode, "hanja_mode"},*/ {xtd::forms::keys::escape, "escape"}, {xtd::forms::keys::ime_convert, "ime_convert"}, {xtd::forms::keys::ime_nonconvert, "ime_nonconvert"}, {xtd::forms::keys::ime_mode_change, "ime_mode_change"}, {xtd::forms::keys::space, "space"}, {xtd::forms::keys::page_up, "page_up"}, /*{xtd::forms::keys::prior, "prior"},*/ {xtd::forms::keys::page_down, "page_down"}, /*{xtd::forms::keys::next, "Nnxt"},*/ {xtd::forms::keys::end, "end"}, {xtd::forms::keys::home, "home"}, {xtd::forms::keys::left, "left"}, {xtd::forms::keys::up, "up"}, {xtd::forms::keys::right, "right"}, {xtd::forms::keys::down, "down"}, {xtd::forms::keys::select, "select"}, {xtd::forms::keys::print, "print"}, {xtd::forms::keys::execute, "execute"}, {xtd::forms::keys::print_screen, "print_screen"}, /*{xtd::forms::keys::snapshot, "snapshot"},*/ {xtd::forms::keys::insert, "insert"}, {xtd::forms::keys::del, "del"}, {xtd::forms::keys::help, "help"}, {xtd::forms::keys::d0, "d0"}, {xtd::forms::keys::d1, "d1"}, {xtd::forms::keys::d2, "d2"}, {xtd::forms::keys::d3, "d3"}, {xtd::forms::keys::d4, "d4"}, {xtd::forms::keys::d5, "d5"}, {xtd::forms::keys::d6, "d6"}, {xtd::forms::keys::d7, "d7"}, {xtd::forms::keys::d8, "d8"}, {xtd::forms::keys::d9, "d9"}, {xtd::forms::keys::a, "a"}, {xtd::forms::keys::b, "b"}, {xtd::forms::keys::c, "c"}, {xtd::forms::keys::d, "d"}, {xtd::forms::keys::e, "e"}, {xtd::forms::keys::f, "f"}, {xtd::forms::keys::g, "g"}, {xtd::forms::keys::h, "h"}, {xtd::forms::keys::i, "i"}, {xtd::forms::keys::j, "j"}, {xtd::forms::keys::k, "k"}, {xtd::forms::keys::l, "l"}, {xtd::forms::keys::m, "m"}, {xtd::forms::keys::n, "n"}, {xtd::forms::keys::o, "o"}, {xtd::forms::keys::p, "p"}, {xtd::forms::keys::q, "q"}, {xtd::forms::keys::r, "r"}, {xtd::forms::keys::s, "s"}, {xtd::forms::keys::t, "t"}, {xtd::forms::keys::u, "u"}, {xtd::forms::keys::v, "v"}, {xtd::forms::keys::w, "w"}, {xtd::forms::keys::x, "x"}, {xtd::forms::keys::y, "y"}, {xtd::forms::keys::z, "z"}, {xtd::forms::keys::lwin, "lwin"}, {xtd::forms::keys::rwin, "rwin"}, {xtd::forms::keys::apps, "apps"}, {xtd::forms::keys::num_pad0, "num_pad0"}, {xtd::forms::keys::num_pad1, "num_pad1"}, {xtd::forms::keys::num_pad2, "num_pad2"}, {xtd::forms::keys::num_pad3, "num_pad3"}, {xtd::forms::keys::num_pad4, "num_pad4"}, {xtd::forms::keys::num_pad5, "num_pad5"}, {xtd::forms::keys::num_pad6, "num_pad6"}, {xtd::forms::keys::num_pad7, "num_pad7"}, {xtd::forms::keys::num_pad8, "num_pad8"}, {xtd::forms::keys::num_pad9, "num_pad9"}, {xtd::forms::keys::multiply, "multiply"}, {xtd::forms::keys::add, "add"}, {xtd::forms::keys::separator, "separator"}, {xtd::forms::keys::subtract, "subtract"}, {xtd::forms::keys::decimal, "decimal"}, {xtd::forms::keys::divide, "divide"}, {xtd::forms::keys::f1, "f1"}, {xtd::forms::keys::f2, "f2"}, {xtd::forms::keys::f3, "f3"}, {xtd::forms::keys::f4, "f4"}, {xtd::forms::keys::f5, "f5"}, {xtd::forms::keys::f6, "f6"}, {xtd::forms::keys::f7, "f7"}, {xtd::forms::keys::f8, "f8"}, {xtd::forms::keys::f9, "f9"}, {xtd::forms::keys::f10, "f10"}, {xtd::forms::keys::f11, "f11"}, {xtd::forms::keys::f12, "f12"}, {xtd::forms::keys::f13, "f13"}, {xtd::forms::keys::f14, "f14"}, {xtd::forms::keys::f15, "f15"}, {xtd::forms::keys::f16, "f16"}, {xtd::forms::keys::f17, "f17"}, {xtd::forms::keys::f18, "f18"}, {xtd::forms::keys::f19, "f19"}, {xtd::forms::keys::f20, "f20"}, {xtd::forms::keys::f21, "f21"}, {xtd::forms::keys::f22, "f22"}, {xtd::forms::keys::f23, "f23"}, {xtd::forms::keys::f24, "f24"}, {xtd::forms::keys::num_lock, "num_lock"}, {xtd::forms::keys::scroll, "scroll"}, {xtd::forms::keys::lshift_key, "lshift_key"}, {xtd::forms::keys::rshift_key, "rshift_key"}, {xtd::forms::keys::lcontrol_key, "lcontrol_key"}, {xtd::forms::keys::rcontrol_key, "rcontrol_key"}, {xtd::forms::keys::lmenu, "lmenu"}, {xtd::forms::keys::rmenu, "rmenu"}, {xtd::forms::keys::browser_back, "browser_back"}, {xtd::forms::keys::browser_favorites, "browser_favorites"}, {xtd::forms::keys::browser_forward, "browser_forward"}, {xtd::forms::keys::browser_refresh, "browser_refresh"}, {xtd::forms::keys::browser_search, "browser_search"}, {xtd::forms::keys::browser_stop, "browser_stop"}, {xtd::forms::keys::browser_home, "browser_home"}, {xtd::forms::keys::volume_mute, "volume_mute"}, {xtd::forms::keys::volume_down, "volume_down"}, {xtd::forms::keys::volume_up, "volume_up"}, {xtd::forms::keys::media_next_track, "media_next_track"}, {xtd::forms::keys::media_play_pause, "media_play_pause"}, {xtd::forms::keys::media_previous_track, "media_previous_track"}, {xtd::forms::keys::media_stop, "media_stop"}, {xtd::forms::keys::launch_mail, "launch_mail"}, {xtd::forms::keys::select_media, "select_media"}, {xtd::forms::keys::launch_application1, "launch_application1"}, {xtd::forms::keys::launch_application2, "launch_application2"}, {xtd::forms::keys::oem_plus, "oem_plus"}, {xtd::forms::keys::oem_comma, "oem_comma"}, {xtd::forms::keys::oem_minus, "oem_minus"}, {xtd::forms::keys::oem_period, "oem_period"}, {xtd::forms::keys::oem_question, "oem_question"}, {xtd::forms::keys::oem_tilde, "oem_tilde"}, {xtd::forms::keys::oem_open_brackets, "oem_open_brackets"}, {xtd::forms::keys::oem_pipe, "oem_pipe"}, {xtd::forms::keys::oem_close_brackets, "oem_close_brackets"}, {xtd::forms::keys::oem_quotes, "oem_quotes"}, {xtd::forms::keys::oem8, "oem8"}, {xtd::forms::keys::oem_backslash, "oem_backslash"}, {xtd::forms::keys::process_key, "process_key"}, {xtd::forms::keys::attn, "attn"}, {xtd::forms::keys::crsel, "crsel"}, {xtd::forms::keys::exsel, "exsel"}, {xtd::forms::keys::erase_eof, "erase_eof"}, {xtd::forms::keys::play, "play"}, {xtd::forms::keys::zoom, "zoom"}, {xtd::forms::keys::no_name, "no_name"}, {xtd::forms::keys::pa1, "pa1"}, {xtd::forms::keys::oem_clear, "oem_clear"}, {xtd::forms::keys::key_code, "key_code"}, {xtd::forms::keys::shift, "shift"}, {xtd::forms::keys::control, "control"}, {xtd::forms::keys::alt, "alt"}, {xtd::forms::keys::meta, "meta"}, {xtd::forms::keys::function, "function"}, {xtd::forms::keys::modifiers, "modifiers"}, {xtd::forms::keys::ime_accept, "ime_accept"}, {xtd::forms::keys::oem1, "oem1"}, /*{xtd::forms::keys::oem102, "oem102"}, {xtd::forms::keys::oem2, "oem2"}, {xtd::forms::keys::oem3, "oem3"}, {xtd::forms::keys::oem4, "oem4"}, {xtd::forms::keys::oem5, "oem5"}, {xtd::forms::keys::oem6, "oem6"}, {xtd::forms::keys::oem7, "oem7"},*/ {xtd::forms::keys::packet, "packet"}, {xtd::forms::keys::sleep, "sleep"}, {xtd::forms::keys::command_key, "command_key"}, {xtd::forms::keys::lcommand_key, "lcommand_key"}, {xtd::forms::keys::rcommand_key, "rcommand_key"}, {xtd::forms::keys::function_key, "function_key"}};}
};
/// @endcond
