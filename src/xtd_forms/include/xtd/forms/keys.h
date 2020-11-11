/// @file
/// @brief Contains keys enum.
#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  /// @brief The xtd::windows::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
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
    /// void text_box1_key_down(const control& sender, key_event_args& e) {
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
    /// void text_box1_key_press(const control& sender, key_press_event_args& e) {
    ///   // Check for the flag being set in the key_down event.
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
      /// @brief The RETURN key.
      ret = 0x0000000D,
      /// @brief The ENTER key.
      enter = 0x0000000D,
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
      /// @breif The IME Hanguel mode key. (maintained for compatibility; use HangulMode)
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
      prior = 0x00000021,
      /// @brief The PAGE DOWN key.
      page_down = 0x00000022,
      /// @brief The PAGE DOWN key.
      next = 0x00000022,
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
      snapshot = 0x0000002C,
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
      /// @brief The OEM 1 key.
      oem1 = 0x000000BA,
      /// @brief The OEM Semicolon key on a US standard keyboard.
      oem_semicolon = 0x000000BA,
      /// @brief The OEM plus key on any country/region keyboard.
      oem_plus = 0x000000BB,
      /// @brief The OEM comma key on any country/region keyboard.
      oem_comma = 0x000000BC,
      /// @brief The OEM minus key on any country/region keyboard.
      oem_minus = 0x000000BD,
      /// @brief The OEM period key on any country/region keyboard.
      oem_period = 0x000000BE,
      /// @brief The OEM 2 key.
      oem2 = 0x000000BF,
      /// @brief The OEM question mark key on a US standard keyboard.
      oem_question = 0x000000BF,
      /// @brief The OEM 3 key.
      oem3 = 0x000000C0,
      /// @brief The OEM tilde key on a US standard keyboard.
      oem_tilde = 0x000000C1,
      /// @brief The OEM 4 key.
      oem4 = 0x000000DB,
      /// @brief The OEM open bracket key on a US standard keyboard.
      oem_open_brackets = 0x000000DB,
      /// @brief The OEM 5 key.
      oem5 = 0x000000DC,
      /// @brief The OEM pipe key on a US standard keyboard.
      oem_pipe = 0x000000DC,
      /// @brief The OEM 6 key.
      oem6 = 0x000000DD,
      /// @brief The OEM close bracket key on a US standard keyboard.
      oem_close_brackets = 0x000000DD,
      /// @brief The OEM 7 key.
      oem7 = 0x000000DE,
      /// @brief The OEM singled/double quote key on a US standard keyboard.
      oem_quotes = 0x000000DE,
      /// @brief The OEM 8 key.
      oem8 = 0x000000DF,
      /// @brief The OEM 102 key.
      oem102 = 0x000000DF,
      /// @brief The OEM angle bracket or backslash key on the RT 102 key keyboard.
      oem_backslash = 0x000000DF,
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
      /// @brief The right CMD key.
      function_key = 0x00000104,
      /// @brief The SHIFt modifier key.
      shift = 0x00010000,
      /// @brief The CTRL modifier key.
      control = 0x00020000,
      /// @brief The ALT modifier key.
      alt = 0x00040000,
      /// @brief The CMD modifier key.
      command = 0x00080000,
      /// @brief The METTA modifier key.
      meta = 0x00100000,
      /// @brief The FUNCTION modifier key.
      function = 0x00200000,
      /// @brief The bitmask to extract a key code from a key value.
      key_code = 0x0000FFFF,
      /// @brief The bitmask to extract modifiers from a key value.
      modifiers = 0xFFFF0000,
    };
    
    /// @cond
    inline keys& operator +=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline keys& operator -=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline keys& operator &=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline keys& operator |=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline keys& operator ^=(keys& lhs, keys rhs) {lhs = static_cast<keys>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline keys operator +(keys lhs, keys rhs) {return static_cast<keys>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline keys operator -(keys lhs, keys rhs) {return static_cast<keys>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline keys operator ~(keys rhs) {return static_cast<keys>(~static_cast<long long>(rhs));}
    inline keys operator &(keys lhs, keys rhs) {return static_cast<keys>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline keys operator |(keys lhs, keys rhs) {return static_cast<keys>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline keys operator ^(keys lhs, keys rhs) {return static_cast<keys>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
  inline std::ostream& operator<<(std::ostream& os, keys value) {return os << xtd::to_string(value, {{keys::none, "none"}, {keys::lbutton, "lbutton"}, {keys::rbutton, "rbutton"}, {keys::cancel, "cancel"}, {keys::mbutton, "none"}, {keys::xbutton1, "xbutton1"}, {keys::xbutton2, "xbutton2"}, {keys::back, "back"}, {keys::tab, "tab"}, {keys::line_feed, "line_feed"}, {keys::clear, "clear"}, /*{keys::ret, "ret"},*/ {keys::enter, "enter"}, {keys::shift_key, "shift_key"}, {keys::control_key, "control_key"}, {keys::menu, "menu"}, {keys::pause, "pause"}, {keys::caps_lock, "caps_lock"}, /*{System::Windows::Forms::Keys::capital, "capital"},*/ {keys::kana_mode, "kana_mode"}, /*{keys::hanguel_mode, "hanguel_mode"}, {keys::hangul_mode, "hangul_mode"},*/ {keys::junja_mode, "junja_mode"}, {keys::final_mode, "final_mode"}, {keys::kanji_mode, "kanji_mode"}, /*{keys::Hhnja_mode, "hanja_mode"},*/ {keys::escape, "escape"}, {keys::ime_convert, "ime_convert"}, {keys::ime_nonconvert, "ime_nonconvert"}, {keys::ime_mode_change, "ime_mode_change"}, {keys::space, "space"}, {keys::page_up, "page_up"}, /*{keys::prior, "prior"},*/ {keys::page_down, "page_down"}, /*{keys::next, "Nnxt"},*/ {keys::end, "end"}, {keys::home, "home"}, {keys::left, "left"}, {keys::up, "up"}, {keys::right, "right"}, {keys::down, "down"}, {keys::select, "select"}, {keys::print, "print"}, {keys::execute, "execute"}, {keys::print_screen, "print_screen"}, /*{keys::snapshot, "snapshot"},*/ {keys::insert, "insert"}, {keys::del, "del"}, {keys::help, "help"}, {keys::d0, "d0"}, {keys::d1, "d1"}, {keys::d2, "d2"}, {keys::d3, "d3"}, {keys::d4, "d4"}, {keys::d5, "d5"}, {keys::d6, "d6"}, {keys::d7, "d7"}, {keys::d8, "d8"}, {keys::d9, "d9"}, {keys::a, "a"}, {keys::b, "b"}, {keys::c, "c"}, {keys::d, "d"}, {keys::e, "e"}, {keys::f, "f"}, {keys::g, "g"}, {keys::h, "h"}, {keys::i, "i"}, {keys::j, "j"}, {keys::k, "k"}, {keys::l, "l"}, {keys::m, "m"}, {keys::n, "n"}, {keys::o, "o"}, {keys::p, "p"}, {keys::q, "q"}, {keys::r, "r"}, {keys::s, "s"}, {keys::t, "t"}, {keys::u, "u"}, {keys::v, "v"}, {keys::w, "w"}, {keys::x, "x"}, {keys::y, "y"}, {keys::z, "z"}, {keys::lwin, "lwin"}, {keys::rwin, "rwin"}, {keys::apps, "apps"}, {keys::num_pad0, "num_pad0"}, {keys::num_pad1, "num_pad1"}, {keys::num_pad2, "num_pad2"}, {keys::num_pad3, "num_pad3"}, {keys::num_pad4, "num_pad4"}, {keys::num_pad5, "num_pad5"}, {keys::num_pad6, "num_pad6"}, {keys::num_pad7, "num_pad7"}, {keys::num_pad8, "num_pad8"}, {keys::num_pad9, "bum_pad9"}, {keys::multiply, "multiply"}, {keys::add, "add"}, {keys::separator, "separator"}, {keys::subtract, "subtract"}, {keys::decimal, "decimal"}, {keys::divide, "divide"}, {keys::f1, "f1"}, {keys::f2, "f2"}, {keys::f3, "f3"}, {keys::f4, "f4"}, {keys::f5, "f5"}, {keys::f6, "f6"}, {keys::f7, "f7"}, {keys::f8, "f8"}, {keys::f9, "f9"}, {keys::f10, "f10"}, {keys::f11, "f11"}, {keys::f12, "f12"}, {keys::f13, "f13"}, {keys::f14, "f14"}, {keys::f15, "f15"}, {keys::f16, "f16"}, {keys::f17, "f17"}, {keys::f18, "f18"}, {keys::f19, "f19"}, {keys::f20, "f20"}, {keys::f21, "f21"}, {keys::f22, "f22"}, {keys::f23, "f23"}, {keys::f24, "f24"}, {keys::num_lock, "num_lock"}, {keys::scroll, "scroll"}, {keys::lshift_key, "lshift_key"}, {keys::rshift_key, "rshift_key"}, {keys::lcontrol_key, "lcontrol_key"}, {keys::rcontrol_key, "rcontrol_key"}, {keys::lmenu, "lmenu"}, {keys::rmenu, "rmenu"}, {keys::browser_back, "browser_back"}, {keys::browser_favorites, "browser_favorites"}, {keys::browser_forward, "browser_forward"}, {keys::browser_home, "browser_home"}, {keys::browser_refresh, "browser_refresh"}, {keys::browser_search, "browser_search"}, {keys::browser_stop, "browser_stop"}, {keys::volume_down, "volume_down"}, {keys::volume_mute, "volume_mute"}, {keys::volume_up, "volume_up"}, {keys::media_next_track, "media_next_track"}, {keys::media_play_pause, "media_play_pause"}, {keys::media_previous_track, "media_previous_track"}, {keys::media_stop, "media_stop"}, {keys::launch_mail, "launch_mail"}, {keys::select_media, "select_media"}, {keys::launch_application1, "launch_application1"}, {keys::launch_application2, "launch_application2"}, {keys::oem_plus, "oem_plus"}, {keys::oem_comma, "oem_comma"}, {keys::oem_minus, "oem_minus"}, {keys::oem_period, "oem_period"}, {keys::oem_question, "oem_question"}, {keys::oem_tilde, "oem_tilde"}, {keys::oem_open_brackets, "oem_open_brackets"}, {keys::oem_pipe, "oem_pipe"}, {keys::oem_close_brackets, "oem_close_brackets"}, {keys::oem_quotes, "oem_quotes"}, {keys::oem8, "oem8"}, {keys::oem_backslash, "oem_backslash"}, {keys::process_key, "process_key"}, {keys::attn, "attn"}, {keys::crsel, "crsel"}, {keys::exsel, "exsel"}, {keys::erase_eof, "erase_eof"}, {keys::play, "play"}, {keys::zoom, "zoom"}, {keys::no_name, "no_name"}, {keys::pa1, "pa1"}, {keys::oem_clear, "oem_clear"}, {keys::key_code, "key_code"}, {keys::shift, "shift"}, {keys::control, "control"}, {keys::alt, "alt"}, {keys::command, "command"}, {keys::meta, "meta"}, {keys::function, "function"}, {keys::modifiers, "modifiers"}, {keys::ime_accept, "ime_accept"}, {keys::oem1, "oem1"}, /*{keys::oem102, "oem102"}, {keys::oem2, "oem2"}, {keys::oem3, "oem3"}, {keys::oem4, "oem4"}, {keys::oem5, "oem5"}, {keys::oem6, "oem6"}, {keys::oem7, "oem7"},*/ {keys::packet, "packet"}, {keys::sleep, "sleep"}, {keys::command_key, "command_key"}, {keys::lcommand_key, "lcommand_key"}, {keys::rcommand_key, "rcommand_key"}, {keys::function_key, "function_key"}});}
  inline std::wostream& operator<<(std::wostream& os, keys value) {return os << xtd::to_string(value, {{keys::none, L"none"}, {keys::lbutton, L"lbutton"}, {keys::rbutton, L"rbutton"}, {keys::cancel, L"cancel"}, {keys::mbutton, L"none"}, {keys::xbutton1, L"xbutton1"}, {keys::xbutton2, L"xbutton2"}, {keys::back, L"back"}, {keys::tab, L"tab"}, {keys::line_feed, L"line_feed"}, {keys::clear, L"clear"}, {keys::ret, L"ret"}, /*{keys::enter, L"enter"},*/ {keys::shift_key, L"shift_key"}, {keys::control_key, L"control_key"}, {keys::menu, L"menu"}, {keys::pause, L"pause"}, {keys::caps_lock, L"caps_lock"}, /*{System::Windows::Forms::Keys::capital, L"capital"},*/ {keys::kana_mode, L"kana_mode"}, /*{keys::hanguel_mode, L"hanguel_mode"}, {keys::hangul_mode, L"hangul_mode"},*/ {keys::junja_mode, L"junja_mode"}, {keys::final_mode, L"final_mode"}, {keys::kanji_mode, L"kanji_mode"}, /*{keys::Hhnja_mode, L"hanja_mode"},*/ {keys::escape, L"escape"}, {keys::ime_convert, L"ime_convert"}, {keys::ime_nonconvert, L"ime_nonconvert"}, {keys::ime_mode_change, L"ime_mode_change"}, {keys::space, L"space"}, {keys::page_up, L"page_up"}, /*{keys::prior, L"prior"},*/ {keys::page_down, L"page_down"}, /*{keys::next, L"Nnxt"},*/ {keys::end, L"end"}, {keys::home, L"home"}, {keys::left, L"left"}, {keys::up, L"up"}, {keys::right, L"right"}, {keys::down, L"down"}, {keys::select, L"select"}, {keys::print, L"print"}, {keys::execute, L"execute"}, {keys::print_screen, L"print_screen"}, /*{keys::snapshot, L"snapshot"},*/ {keys::insert, L"insert"}, {keys::del, L"del"}, {keys::help, L"help"}, {keys::d0, L"d0"}, {keys::d1, L"d1"}, {keys::d2, L"d2"}, {keys::d3, L"d3"}, {keys::d4, L"d4"}, {keys::d5, L"d5"}, {keys::d6, L"d6"}, {keys::d7, L"d7"}, {keys::d8, L"d8"}, {keys::d9, L"d9"}, {keys::a, L"a"}, {keys::b, L"b"}, {keys::c, L"c"}, {keys::d, L"d"}, {keys::e, L"e"}, {keys::f, L"f"}, {keys::g, L"g"}, {keys::h, L"h"}, {keys::i, L"i"}, {keys::j, L"j"}, {keys::k, L"k"}, {keys::l, L"l"}, {keys::m, L"m"}, {keys::n, L"n"}, {keys::o, L"o"}, {keys::p, L"p"}, {keys::q, L"q"}, {keys::r, L"r"}, {keys::s, L"s"}, {keys::t, L"t"}, {keys::u, L"u"}, {keys::v, L"v"}, {keys::w, L"w"}, {keys::x, L"x"}, {keys::y, L"y"}, {keys::z, L"z"}, {keys::lwin, L"lwin"}, {keys::rwin, L"rwin"}, {keys::apps, L"apps"}, {keys::num_pad0, L"num_pad0"}, {keys::num_pad1, L"num_pad1"}, {keys::num_pad2, L"num_pad2"}, {keys::num_pad3, L"num_pad3"}, {keys::num_pad4, L"num_pad4"}, {keys::num_pad5, L"num_pad5"}, {keys::num_pad6, L"num_pad6"}, {keys::num_pad7, L"num_pad7"}, {keys::num_pad8, L"num_pad8"}, {keys::num_pad9, L"bum_pad9"}, {keys::multiply, L"multiply"}, {keys::add, L"add"}, {keys::separator, L"separator"}, {keys::subtract, L"subtract"}, {keys::decimal, L"decimal"}, {keys::divide, L"divide"}, {keys::f1, L"f1"}, {keys::f2, L"f2"}, {keys::f3, L"f3"}, {keys::f4, L"f4"}, {keys::f5, L"f5"}, {keys::f6, L"f6"}, {keys::f7, L"f7"}, {keys::f8, L"f8"}, {keys::f9, L"f9"}, {keys::f10, L"f10"}, {keys::f11, L"f11"}, {keys::f12, L"f12"}, {keys::f13, L"f13"}, {keys::f14, L"f14"}, {keys::f15, L"f15"}, {keys::f16, L"f16"}, {keys::f17, L"f17"}, {keys::f18, L"f18"}, {keys::f19, L"f19"}, {keys::f20, L"f20"}, {keys::f21, L"f21"}, {keys::f22, L"f22"}, {keys::f23, L"f23"}, {keys::f24, L"f24"}, {keys::num_lock, L"num_lock"}, {keys::scroll, L"scroll"}, {keys::lshift_key, L"lshift_key"}, {keys::rshift_key, L"rshift_key"}, {keys::lcontrol_key, L"lcontrol_key"}, {keys::rcontrol_key, L"rcontrol_key"}, {keys::lmenu, L"lmenu"}, {keys::rmenu, L"rmenu"}, {keys::browser_back, L"browser_back"}, {keys::browser_favorites, L"browser_favorites"}, {keys::browser_forward, L"browser_forward"}, {keys::browser_home, L"browser_home"}, {keys::browser_refresh, L"browser_refresh"}, {keys::browser_search, L"browser_search"}, {keys::browser_stop, L"browser_stop"}, {keys::volume_down, L"volume_down"}, {keys::volume_mute, L"volume_mute"}, {keys::volume_up, L"volume_up"}, {keys::media_next_track, L"media_next_track"}, {keys::media_play_pause, L"media_play_pause"}, {keys::media_previous_track, L"media_previous_track"}, {keys::media_stop, L"media_stop"}, {keys::launch_mail, L"launch_mail"}, {keys::select_media, L"select_media"}, {keys::launch_application1, L"launch_application1"}, {keys::launch_application2, L"launch_application2"}, {keys::oem_plus, L"oem_plus"}, {keys::oem_comma, L"oem_comma"}, {keys::oem_minus, L"oem_minus"}, {keys::oem_period, L"oem_period"}, {keys::oem_question, L"oem_question"}, {keys::oem_tilde, L"oem_tilde"}, {keys::oem_open_brackets, L"oem_open_brackets"}, {keys::oem_pipe, L"oem_pipe"}, {keys::oem_close_brackets, L"oem_close_brackets"}, {keys::oem_quotes, L"oem_quotes"}, {keys::oem8, L"oem8"}, {keys::oem_backslash, L"oem_backslash"}, {keys::process_key, L"process_key"}, {keys::attn, L"attn"}, {keys::crsel, L"crsel"}, {keys::exsel, L"exsel"}, {keys::erase_eof, L"erase_eof"}, {keys::play, L"play"}, {keys::zoom, L"zoom"}, {keys::no_name, L"no_name"}, {keys::pa1, L"pa1"}, {keys::oem_clear, L"oem_clear"}, {keys::key_code, L"key_code"}, {keys::shift, L"shift"}, {keys::control, L"control"}, {keys::alt, L"alt"}, {keys::command, L"command"}, {keys::meta, L"meta"}, {keys::function, L"function"}, {keys::modifiers, L"modifiers"}, {keys::ime_accept, L"ime_accept"}, {keys::oem1, L"oem1"}, /*{keys::oem102, L"oem102"}, {keys::oem2, L"oem2"}, {keys::oem3, L"oem3"}, {keys::oem4, L"oem4"}, {keys::oem5, L"oem5"}, {keys::oem6, L"oem6"}, {keys::oem7, L"oem7"},*/ {keys::packet, L"packet"}, {keys::sleep, L"sleep"}, {keys::command_key, L"command_key"}, {keys::lcommand_key, L"lcommand_key"}, {keys::rcommand_key, L"rcommand_key"}, {keys::function_key, L"function_key"}});}
    /// @endcond
  }
}
