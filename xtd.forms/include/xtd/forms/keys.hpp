/// @file
/// @brief Contains keys enum.
#pragma once
#include <iostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies key codes and modifiers.
    /// @remarks The keys class contains constants for processing keyboard input. The members of the keys enumeration consist of a key code and a set of modifiers combined into a single integer value. In the Win32 application programming interface (API) a key value has two halves, with the high-order bits containing the key code (which is the same as a Windows virtual key code), and the low-order bits representing key modifiers such as the SHIFT, CONTROL, and ALT keys.
    /// @warning Do not use the values in this enumeration for combined bitwise operations. The values in the enumeration are not mutually exclusive.
    /// @note This enumeration provides no way to test whether the CAPS LOCK or NUM LOCK keys are currently activated. You can use one of the following techniques to determine if these keys are activated:
    /// * Call the IsKeyLocked method of the Control class.
    /// * For finer control, use the Win32 API functions GetKeyState, GetAsyncKeyState, or GetKeyboardState defined in user32.dll, to do this. For more information about calling native functions, see Consuming Unmanaged DLL Functions.
    /// @remarks The following table shows the key code values represented by two enumerated values, representing both the general original equipment manufacturer (OEM) keys and the more specific U.S.-keyboard associations.
    /// | Hexadecimal value | U.S. keyboard      | General OEM |
    /// |-------------------|--------------------|-------------|
    /// | BA                | oem_semicolon      | oem1        |
    /// | BF                | oem_question       | oem2        |
    /// | C0                | oem_tilde          | oem3        |
    /// | DB                | oem_open_brackets  | oem4        |
    /// | DC                | oem_pipe           | oem5        |
    /// | DD                | oem_close_brackets | oem6        |
    /// | DE                | oem_quotes         | oem7        |
    /// | E2                | oem_backslash      | oem102      |
    /// @par Examples
    /// The following code example uses the KeyDown event to determine the type of character entered into the control.
    /// @code
    /// // bool flag used to determine when a character other than a number is entered.
    /// bool non_number_entered = false;
    ///
    /// // Handle the KeyDown event to determine the type of character entered into the control.
    /// void text_box1_key_down(const control& sender, const key_event_args& e) {
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
    ///         // Set the flag to true and evaluate in key_press event.
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
    /// void text_box1_key_press(const control& sender, const key_press_event_args& e) {
    ///   // Check for the flag being set in the key_down event.
    ///   if (non_number_entered == true) {
    ///     // Stop the character from being entered into the control since it is non-numerical.
    ///     e.handled(true);
    ///   }
    /// }
    /// @endcode
    enum class keys {
      /// @brief No key pressed.
      none = 0,
      /// @brief The left mouse button.
      lbutton = 1,
      /// @brief The right mouse button.
      rbutton = 2,
      /// @brief The CANCEL key.
      cancel = 3,
      /// @brief The middle mouse button (three-button mouse).
      mbutton = 4,
      /// @brief The first x mouse button (five-button mouse).
      xbutton1 = 5,
      /// @brief The second x mouse button (five-button mouse).
      xbutton2 = 6,
      /// @brief The BACK key.
      back = 8,
      /// @brief The TAB key.
      tab = 9,
      /// @brief The LINEFEED key.
      line_feed = 10,
      /// @brief The CLEAR key.
      clear = 12,
      /// @brief The RETURN key.
      ret = 13,
      /// @brief The ENTER key.
      enter = 13,
      /// @brief The SHIFT key.
      shift_key = 16,
      /// @brief The CTRL key.
      control_key = 17,
      /// @brief The ALT key.
      menu = 18,
      /// @brief The PAUSE key.
      pause = 19,
      /// @brief The CAPS LOCK key.
      caps_lock = 20,
      /// @brief The CAPS LOCK key.
      capital = 20,
      /// @brief The IME Kana mode key.
      kana_mode = 21,
      /// @breif The IME Hanguel mode key. (maintained for compatibility; use HangulMode)
      hanguel_mode = 21,
      /// @brief The IME Hangul mode key.
      hangul_mode = 21,
      /// @brief The IME Junja mode key.
      junja_mode = 23,
      /// @brief The IME Final mode key.
      final_mode = 24,
      /// @brief The IME Kanji mode key.
      kanji_mode = 25,
      /// @brief The IME Hanja mode key.
      hanja_mode = 25,
      /// @brief The ESC key.
      escape = 27,
      /// @brief The IME convert key.
      ime_convert = 28,
      /// @brief The IME nonconvert key.
      ime_nonconvert = 29,
      /// @brief The IME accept key.
      ime_aceept = 30,
      /// @brief The IME mode change key.
      ime_mode_change = 31,
      /// @brief The SPACEBAR key.
      space = 32,
      /// @brief The PAGE UP key.
      page_up = 33,
      /// @brief The PAGE UP key.
      prior = 33,
      /// @brief The PAGE DOWN key.
      page_down = 34,
      /// @brief The PAGE DOWN key.
      next = 34,
      /// @brief The END key.
      end = 35,
      /// @brief The HOME key.
      home = 36,
      /// @brief The LEFT key.
      left = 37,
      /// @brief The UP key.
      up = 38,
      /// @brief The RIGHT key.
      right = 39,
      /// @brief The DOWN key.
      down = 40,
      /// @brief The SELECT key.
      select = 41,
      /// @brief The PRINT key.
      print = 42,
      /// @brief The EXECUTE key.
      execute = 43,
      /// @brief The PRINT SCREEN key.
      print_screen = 44,
      /// @brief The PRINT SCREEN key.
      snapshot = 44,
      /// @brief The INSERT key.
      insert = 45,
      /// @brief The DEL key.
      del = 46,
      /// @brief The HELP key.
      help = 47,
      /// @brief The 0 key.
      d0 = 48,
      /// @brief The 1 key.
      d1 = 49,
      /// @brief The 2 key.
      d2 = 50,
      /// @brief The 3 key.
      d3 = 51,
      /// @brief The 4 key.
      d4 = 52,
      /// @brief The 5 key.
      d5 = 53,
      /// @brief The 6 key.
      d6 = 54,
      /// @brief The 7 key.
      d7 = 55,
      /// @brief The 8 key.
      d8 = 56,
      /// @brief The 9 key.
      d9 = 57,
      /// @brief The A key.
      a = 65,
      /// @brief The B key.
      b = 66,
      /// @brief The C key.
      c = 67,
      /// @brief The D key.
      d = 68,
      /// @brief The E key.
      e = 69,
      /// @brief The F key.
      f = 70,
      /// @brief The G key.
      g = 71,
      /// @brief The H key.
      h = 72,
      /// @brief The I key.
      i = 73,
      /// @brief The J key.
      j = 74,
      /// @brief The K key.
      k = 75,
      /// @brief The L key.
      l = 76,
      /// @brief The M key.
      m = 77,
      /// @brief The N key.
      n = 78,
      /// @brief The O key.
      o = 79,
      /// @brief The P key.
      p = 80,
      /// @brief The Q key.
      q = 81,
      /// @brief The R key.
      r = 82,
      /// @brief The S key.
      s = 83,
      /// @brief The T key.
      t = 84,
      /// @brief The U key.
      u = 85,
      /// @brief The V key.
      v = 86,
      /// @brief The W key.
      w = 87,
      /// @brief The X key.
      x = 88,
      /// @brief The Y key.
      y = 89,
      /// @brief The Z key.
      z = 90,
      /// @brief The left Windows logo key (Microsoft Natural Keyboard).
      lwin = 91,
      /// @brief The right Windows logo key (Microsoft Natural Keyboard).
      rwin = 92,
      /// @brief The application key (Microsoft Natural Keyboard).
      apps = 93,
      /// @brief The 0 key on the numeric keypad.
      num_pad0 = 96,
      /// @brief The 1 key on the numeric keypad.
      num_pad1 = 97,
      /// @brief The 2 key on the numeric keypad.
      num_pad2 = 98,
      /// @brief The 3 key on the numeric keypad.
      num_pad3 = 99,
      /// @brief The 4 key on the numeric keypad.
      num_pad4 = 100,
      /// @brief The 5 key on the numeric keypad.
      num_pad5 = 101,
      /// @brief The 6 key on the numeric keypad.
      num_pad6 = 102,
      /// @brief The 7 key on the numeric keypad.
      num_pad7 = 103,
      /// @brief The 8 key on the numeric keypad.
      num_pad8 = 104,
      /// @brief The 9 key on the numeric keypad.
      num_pad9 = 105,
      /// @brief The multiply key.
      multiply = 106,
      /// @brief The add key.
      add = 107,
      /// @brief The separator key.
      separator = 108,
      /// @brief The subtract key.
      subtract = 109,
      /// @brief The decimal key.
      decimal = 110,
      /// @brief The divide key.
      divide = 111,
      /// @brief The F1 key.
      f1 = 112,
      /// @brief The F2 key.
      f2 = 113,
      /// @brief The F3 key.
      f3 = 114,
      /// @brief The F4 key.
      f4 = 115,
      /// @brief The F5 key.
      f5 = 116,
      /// @brief The F6 key.
      f6 = 117,
      /// @brief The F7 key.
      f7 = 118,
      /// @brief The F8 key.
      f8 = 119,
      /// @brief The F9 key.
      f9 = 120,
      /// @brief The F10 key.
      f10 = 121,
      /// @brief The F11 key.
      f11 = 122,
      /// @brief The F12 key.
      f12 = 123,
      /// @brief The F13 key.
      f13 = 124,
      /// @brief The F14 key.
      f14 = 125,
      /// @brief The F15 key.
      f15 = 126,
      /// @brief The F16 key.
      f16 = 127,
      /// @brief The F17 key.
      f17 = 128,
      /// @brief The F18 key.
      f18 = 129,
      /// @brief The F19 key.
      f19 = 130,
      /// @brief The F20 key.
      f20 = 131,
      /// @brief The F21 key.
      f21 = 132,
      /// @brief The F22 key.
      f22 = 133,
      /// @brief The F23 key.
      f23 = 134,
      /// @brief The F24 key.
      f24 = 135,
      /// @brief The NUM LOCK key.
      num_lock = 144,
      /// @brief The SCROLL LOCK key.
      scroll = 145,
      /// @brief The left SHIFT key.
      lshift_key = 160,
      /// @brief The right SHIFT key.
      rshift_key = 161,
      /// @brief The left CTRL key.
      lcontrol_key = 162,
      /// @brief The right CTRL key.
      rcontrol_key = 163,
      /// @brief The left ALT key.
      lmenu = 164,
      /// @brief The right ALT key.
      rmenu = 165,
      /// @brief The browser back key.
      browser_back = 166,
      /// @brief The browser forward key.
      browser_forward = 167,
      /// @brief The browser refresh key.
      browser_refresh = 168,
      /// @brief The browser stop key.
      browser_stop = 169,
      /// @brief The browser search key.
      browser_search = 170,
      /// @brief The browser favorites key.
      browser_favorites = 171,
      /// @brief The browser home key.
      browser_home = 172,
      /// @brief The volume mute key.
      volume_mute = 173,
      /// @brief The volume down key.
      volume_down = 174,
      /// @brief The volume up key.
      volume_up = 175,
      /// @brief The media next track key.
      media_next_track = 176,
      /// @brief The media previous track key.
      media_previous_track = 177,
      /// @brief The media stop key.
      media_stop = 178,
      /// @brief The media play pause key.
      media_play_pause = 179,
      /// @brief The launch mail key.
      launch_mail = 180,
      /// @brief The select media key.
      select_media = 181,
      /// @brief The start application one key.
      launch_application1 = 182,
      /// @brief The start application two key.
      launch_application2 = 183,
      /// @brief The OEM Semicolon key on a US standard keyboard.
      oem_semicolon = 186,
      /// @brief The OEM plus key on any country/region keyboard.
      oem_plus = 187,
      /// @brief The OEM comma key on any country/region keyboard.
      oem_comma = 188,
      /// @brief The OEM minus key on any country/region keyboard.
      oem_minus = 189,
      /// @brief The OEM period key on any country/region keyboard.
      oem_period = 190,
      /// @brief The OEM question mark key on a US standard keyboard.
      oem_question = 191,
      /// @brief The OEM tilde key on a US standard keyboard.
      oem_tilde = 192,
      /// @brief The OEM open bracket key on a US standard keyboard.
      oem_open_brackets = 219,
      /// @brief The OEM pipe key on a US standard keyboard.
      oem_pipe = 220,
      /// @brief The OEM close bracket key on a US standard keyboard.
      oem_close_brackets = 221,
      /// @brief The OEM singled/double quote key on a US standard keyboard.
      oem_quotes = 222,
      /// @brief The OEM 8 key.
      oem8 = 223,
      /// @brief The OEM angle bracket or backslash key on the RT 102 key keyboard.
      oem_backslash = 226,
      /// @brief The PROCESS KEY key.
      process_key = 229,
      /// @brief The ATTN key.
      attn = 246,
      /// @brief The CRSEL key.
      crsel = 247,
      /// @brief The EXSEL key.
      exsel = 248,
      /// @brief The ERASE EOF key.
      erase_eof = 249,
      /// @brief The PLAY key.
      play = 250,
      /// @brief The ZOOM key.
      zoom = 251,
      /// @brief A constant reserved for future use.
      no_name = 252,
      /// @brief The PA1 key.
      pa1 = 253,
      /// @brief The CLEAR key.
      oem_clear = 254,
      /// @brief The bitmask to extract a key code from a key value.
      key_code = 65535,
      /// @brief The SHIFt modifier key.
      shift = 65536,
      /// @brief The CTRL modifier key.
      control = 131072,
      /// @brief The ALT modifier key.
      alt = 262144,
      /// @brief The CMD modifier key.
      command = 524288,
      /// @brief The bitmask to extract modifiers from a key value.
      modifiers = -65536,
      /// @brief The IME accept key.
      ime_accept = 30,
      /// @brief The OEM 1 key.
      oem1 = 186,
      /// @brief The OEM 102 key.
      oem102 = 226,
      /// @brief The OEM 2 key.
      oem2 = 191,
      /// @brief The OEM 3 key.
      oem3 = 192,
      /// @brief The OEM 4 key.
      oem4 = 219,
      /// @brief The OEM 5 key.
      oem5 = 220,
      /// @brief The OEM 6 key.
      oem6 = 221,
      /// @brief The OEM 7 key.
      oem7 = 222,
      /// @brief Used to pass Unicode characters as if they were keystrokes. The Packet key value is the low word of a 32-bit virtual-key value used for non-keyboard input methods.
      packet = 231,
      /// @brief The computer sleep key.
      sleep = 95,
      /// @brief The CMD key.
      command_key = 255,
      /// @brief The left CMD key.
      lcommand_key = 256,
      /// @brief The right CMD key.
      rcommand_key = 257,
    };
    
    /// @cond
    inline keys& operator +=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline keys& operator -=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline keys& operator &=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline keys& operator |=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline keys& operator ^=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline keys operator +(keys lhs, keys rhs) {return static_cast<keys>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline keys operator -(keys lhs, keys rhs) {return static_cast<keys>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline keys operator ~(keys rhs) {return static_cast<keys>(~static_cast<int>(rhs));}
    inline keys operator &(keys lhs, keys rhs) {return static_cast<keys>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline keys operator |(keys lhs, keys rhs) {return static_cast<keys>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline keys operator ^(keys lhs, keys rhs) {return static_cast<keys>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}

    inline std::ostream& operator<<(std::ostream& os, keys value) {
      std::string result;
      switch (value & keys::key_code) {
        case keys::none: result = "none"; break;
        case keys::lbutton: result = "lbutton"; break;
        case keys::rbutton: result = "rbutton"; break;
        case keys::cancel: result = "cancel"; break;
        case keys::mbutton: result = "none"; break;
        case keys::xbutton1: result = "xbutton1"; break;
        case keys::xbutton2: result = "xbutton2"; break;
        case keys::back: result = "back"; break;
        case keys::tab: result = "tab"; break;
        case keys::line_feed: result = "line_feed"; break;
        case keys::clear: result = "clear"; break;
        case keys::ret: result = "ret"; break;
        /*case keys::enter: result = "enter"; break;*/
        case keys::shift_key: result = "shift_key"; break;
        case keys::control_key: result = "control_key"; break;
        case keys::menu: result = "menu"; break;
        case keys::pause: result = "pause"; break;
        case keys::caps_lock: result = "caps_lock"; break;
        /*{System::Windows::Forms::Keys::capital: result = "capital"; break;*/
        case keys::kana_mode: result = "kana_mode"; break;
        /*case keys::hanguel_mode: result = "hanguel_mode"; break;*/
        /*case keys::hangul_mode: result = "hangul_mode"; break;*/
        case keys::junja_mode: result = "junja_mode"; break;
        case keys::final_mode: result = "final_mode"; break;
        case keys::kanji_mode: result = "kanji_mode"; break;
        /*case keys::Hhnja_mode: result = "hanja_mode"; break;*/
        case keys::escape: result = "escape"; break;
        case keys::ime_convert: result = "ime_convert"; break;
        case keys::ime_nonconvert: result = "ime_nonconvert"; break;
        case keys::ime_mode_change: result = "ime_mode_change"; break;
        case keys::space: result = "space"; break;
        case keys::page_up: result = "page_up"; break;
        /*case keys::prior: result = "prior"; break;*/
        case keys::page_down: result = "page_down"; break;
        /*case keys::next: result = "Nnxt"; break;*/
        case keys::end: result = "end"; break;
        case keys::home: result = "home"; break;
        case keys::left: result = "left"; break;
        case keys::up: result = "up"; break;
        case keys::right: result = "right"; break;
        case keys::down: result = "down"; break;
        case keys::select: result = "select"; break;
        case keys::print: result = "print"; break;
        case keys::execute: result = "execute"; break;
        case keys::print_screen: result = "print_screen"; break;
        /*case keys::snapshot: result = "snapshot"; break;*/
        case keys::insert: result = "insert"; break;
        case keys::del: result = "del"; break;
        case keys::help: result = "help"; break;
        case keys::d0: result = "d0"; break;
        case keys::d1: result = "d1"; break;
        case keys::d2: result = "d2"; break;
        case keys::d3: result = "d3"; break;
        case keys::d4: result = "d4"; break;
        case keys::d5: result = "d5"; break;
        case keys::d6: result = "d6"; break;
        case keys::d7: result = "d7"; break;
        case keys::d8: result = "d8"; break;
        case keys::d9: result = "d9"; break;
        case keys::a: result = "a"; break;
        case keys::b: result = "b"; break;
        case keys::c: result = "c"; break;
        case keys::d: result = "d"; break;
        case keys::e: result = "e"; break;
        case keys::f: result = "f"; break;
        case keys::g: result = "g"; break;
        case keys::h: result = "h"; break;
        case keys::i: result = "i"; break;
        case keys::j: result = "j"; break;
        case keys::k: result = "k"; break;
        case keys::l: result = "l"; break;
        case keys::m: result = "m"; break;
        case keys::n: result = "n"; break;
        case keys::o: result = "o"; break;
        case keys::p: result = "p"; break;
        case keys::q: result = "q"; break;
        case keys::r: result = "r"; break;
        case keys::s: result = "s"; break;
        case keys::t: result = "t"; break;
        case keys::u: result = "u"; break;
        case keys::v: result = "v"; break;
        case keys::w: result = "w"; break;
        case keys::x: result = "x"; break;
        case keys::y: result = "y"; break;
        case keys::z: result = "z"; break;
        case keys::lwin: result = "lwin"; break;
        case keys::rwin: result = "rwin"; break;
        case keys::apps: result = "apps"; break;
        case keys::num_pad0: result = "num_pad0"; break;
        case keys::num_pad1: result = "num_pad1"; break;
        case keys::num_pad2: result = "num_pad2"; break;
        case keys::num_pad3: result = "num_pad3"; break;
        case keys::num_pad4: result = "num_pad4"; break;
        case keys::num_pad5: result = "num_pad5"; break;
        case keys::num_pad6: result = "num_pad6"; break;
        case keys::num_pad7: result = "num_pad7"; break;
        case keys::num_pad8: result = "num_pad8"; break;
        case keys::num_pad9: result = "bum_pad9"; break;
        case keys::multiply: result = "multiply"; break;
        case keys::add: result = "add"; break;
        case keys::separator: result = "separator"; break;
        case keys::subtract: result = "subtract"; break;
        case keys::decimal: result = "decimal"; break;
        case keys::divide: result = "divide"; break;
        case keys::f1: result = "f1"; break;
        case keys::f2: result = "f2"; break;
        case keys::f3: result = "f3"; break;
        case keys::f4: result = "f4"; break;
        case keys::f5: result = "f5"; break;
        case keys::f6: result = "f6"; break;
        case keys::f7: result = "f7"; break;
        case keys::f8: result = "f8"; break;
        case keys::f9: result = "f9"; break;
        case keys::f10: result = "f10"; break;
        case keys::f11: result = "f11"; break;
        case keys::f12: result = "f12"; break;
        case keys::f13: result = "f13"; break;
        case keys::f14: result = "f14"; break;
        case keys::f15: result = "f15"; break;
        case keys::f16: result = "f16"; break;
        case keys::f17: result = "f17"; break;
        case keys::f18: result = "f18"; break;
        case keys::f19: result = "f19"; break;
        case keys::f20: result = "f20"; break;
        case keys::f21: result = "f21"; break;
        case keys::f22: result = "f22"; break;
        case keys::f23: result = "f23"; break;
        case keys::f24: result = "f24"; break;
        case keys::num_lock: result = "num_lock"; break;
        case keys::scroll: result = "scroll"; break;
        case keys::lshift_key: result = "lshift_key"; break;
        case keys::rshift_key: result = "rshift_key"; break;
        case keys::lcontrol_key: result = "lcontrol_key"; break;
        case keys::rcontrol_key: result = "rcontrol_key"; break;
        case keys::lmenu: result = "lmenu"; break;
        case keys::rmenu: result = "rmenu"; break;
        case keys::browser_back: result = "browser_back"; break;
        case keys::browser_favorites: result = "browser_favorites"; break;
        case keys::browser_forward: result = "browser_forward"; break;
        case keys::browser_home: result = "browser_home"; break;
        case keys::browser_refresh: result = "browser_refresh"; break;
        case keys::browser_search: result = "browser_search"; break;
        case keys::browser_stop: result = "browser_stop"; break;
        case keys::volume_down: result = "volume_down"; break;
        case keys::volume_mute: result = "volume_mute"; break;
        case keys::volume_up: result = "volume_up"; break;
        case keys::media_next_track: result = "media_next_track"; break;
        case keys::media_play_pause: result = "media_play_pause"; break;
        case keys::media_previous_track: result = "media_previous_track"; break;
        case keys::media_stop: result = "media_stop"; break;
        case keys::launch_mail: result = "launch_mail"; break;
        case keys::select_media: result = "select_media"; break;
        case keys::launch_application1: result = "launch_application1"; break;
        case keys::launch_application2: result = "launch_application2"; break;
        case keys::oem_plus: result = "oem_plus"; break;
        case keys::oem_comma: result = "oem_comma"; break;
        case keys::oem_minus: result = "oem_minus"; break;
        case keys::oem_period: result = "oem_period"; break;
        case keys::oem_question: result = "oem_question"; break;
        case keys::oem_tilde: result = "oem_tilde"; break;
        case keys::oem_open_brackets: result = "oem_open_brackets"; break;
        case keys::oem_pipe: result = "oem_pipe"; break;
        case keys::oem_close_brackets: result = "oem_close_brackets"; break;
        case keys::oem_quotes: result = "oem_quotes"; break;
        case keys::oem8: result = "oem8"; break;
        case keys::oem_backslash: result = "oem_backslash"; break;
        case keys::process_key: result = "process_key"; break;
        case keys::attn: result = "attn"; break;
        case keys::crsel: result = "crsel"; break;
        case keys::exsel: result = "exsel"; break;
        case keys::erase_eof: result = "erase_eof"; break;
        case keys::play: result = "play"; break;
        case keys::zoom: result = "zoom"; break;
        case keys::no_name: result = "no_name"; break;
        case keys::pa1: result = "pa1"; break;
        case keys::oem_clear: result = "oem_clear"; break;
        case keys::key_code: result = "key_code"; break;
        case keys::modifiers: result = "modifiers"; break;
        case keys::ime_accept: result = "ime_accept"; break;
        case keys::oem1: result = "oem1"; break;
        /*case keys::oem102: result = "oem102"; break;*/
        /*case keys::oem2: result = "oem2"; break;*/
        /*case keys::oem3: result = "oem3"; break;*/
        /*case keys::oem4: result = "oem4"; break;*/
        /*case keys::oem5: result = "oem5"; break;*/
        /*case keys::oem6: result = "oem6"; break;*/
        /*case keys::oem7: result = "oem7"; break;*/
        case keys::packet: result = "packet"; break;
        case keys::sleep: result = "sleep"; break;
        case keys::command_key: result = "command_key"; break;
        case keys::lcommand_key: result = "lcommand_key"; break;
        case keys::rcommand_key: result = "rcommand_key"; break;
        default: result = std::to_string(static_cast<int>(value)); break;
      }

      if ((value & keys::shift) == keys::shift) {
        if (result == "none") result = "";
        if (result != "") result += ", ";
        result += "shift";
      }
      if ((value & keys::control) == keys::control) {
        if (result == "none") result = "";
        if (result != "") result += ", ";
        result += "control";
      }
      if ((value & keys::alt) == keys::alt) {
        if (result == "none") result = "";
        if (result != "") result += ", ";
        result += "alt";
      }
      if ((value & keys::command) == keys::command) {
        if (result == "none") result = "";
        if (result != "") result += ", ";
        result += "command";
      }
      
      return os << result;
    }
    /// @endcond
  }
}
