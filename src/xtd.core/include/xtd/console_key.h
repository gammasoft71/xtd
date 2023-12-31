/// @file
/// @brief Contains xtd::console_key enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the standard keys on a console.
  /// @par Header
  /// @code #include <xtd/console_key> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see Console
  enum class console_key {
    /// @brief The BACKSPACE key.
    backspace = 8,
    /// @brief The TAB key.
    tab = 9,
    /// @brief The CLEAR key.
    clear = 12,
    /// @brief The ENTER key.
    enter = 13,
    /// @brief The PAUSE key.
    pause = 19,
    /// @brief The CapsLock key.
    caps_lock = 20,
    /// @brief The ESC (ESCAPE) key.
    escape = 27,
    /// @brief The SPACEBAR key.
    spacebar = 32,
    /// @brief The PAGE UP key.
    page_up = 33,
    /// @brief The PAGE DOWN key.
    page_down = 34,
    /// @brief The END key.
    end = 35,
    /// @brief The HOME key.
    home = 36,
    /// @brief The LEFT ARROW key.
    left_arrow = 37,
    /// @brief The UP ARROW key.
    up_arrow = 38,
    /// @brief The RIGHT ARROW key.
    right_arrow = 39,
    /// @brief The DOWN ARROW key.
    down_arrow = 40,
    /// @brief The SELECT key.
    select = 41,
    /// @brief The PRINT key.
    print = 42,
    /// @brief The EXECUTE key.
    execute = 43,
    /// @brief The PRINT SCREEN key.
    print_screen = 44,
    /// @brief The INS (INSERT) key.
    insert = 45,
    /// @brief The DEL (DELETE) key.
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
    left_windows = 91,
    /// @brief The right Windows logo key (Microsoft Natural Keyboard).
    right_windows = 92,
    /// @brief The Application key (Microsoft Natural Keyboard).
    applications = 93,
    /// @brief The Computer Sleep key.
    sleep = 95,
    /// @brief The 0 key on the numeric keypad.
    num_pad_0 = 96,
    /// @brief The 1 key on the numeric keypad.
    num_pad_1 = 97,
    /// @brief The 2 key on the numeric keypad.
    num_pad_2 = 98,
    /// @brief The 3 key on the numeric keypad.
    num_pad_3 = 99,
    /// @brief The 4 key on the numeric keypad.
    num_pad_4 = 100,
    /// @brief The 5 key on the numeric keypad.
    num_pad_5 = 101,
    /// @brief The 6 key on the numeric keypad.
    num_pad_6 = 102,
    /// @brief The 7 key on the numeric keypad.
    num_pad_7 = 103,
    /// @brief The 8 key on the numeric keypad.
    num_pad_8 = 104,
    /// @brief The 9 key on the numeric keypad.
    num_pad_9 = 105,
    /// @brief The Multiply key.
    multiply = 106,
    /// @brief The Add key.
    add = 107,
    /// @brief The Separator key.
    separator = 108,
    /// @brief The Subtract key.
    subtract = 109,
    /// @brief The Decimal key.
    decimal = 110,
    /// @brief The Divide key.
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
    /// @brief The Browser Back key (Windows 2000 or later).
    browser_back = 166,
    /// @brief The Browser Forward key (Windows 2000 or later).
    browser_forward = 167,
    /// @brief The Browser Refresh key (Windows 2000 or later).
    browser_refresh = 168,
    /// @brief The Browser Stop key (Windows 2000 or later).
    browser_stop = 169,
    /// @brief The Browser Search key (Windows 2000 or later).
    browser_search = 170,
    /// @brief The Browser Favorite key (Windows 2000 or later).
    browser_favorites = 171,
    /// @brief The Browser Home key (Windows 2000 or later).
    browser_home = 172,
    /// @brief The Volume Mute key (Microsoft Natural Keyboard, Windows 2000 or later).
    volume_mute = 173,
    /// @brief The Volume Down key (Microsoft Natural Keyboard, Windows 2000 or later).
    volume_down = 174,
    /// @brief The Volume Up key (Microsoft Natural Keyboard, Windows 2000 or later).
    volume_up = 175,
    /// @brief The Media Next Track key (Microsoft Natural Keyboard, Windows 2000 or later).
    media_next = 176,
    /// @brief The Media Previous Track key (Microsoft Natural Keyboard, Windows 2000 or later).
    media_previous = 177,
    /// @brief The Media Stop key (Microsoft Natural Keyboard, Windows 2000 or later).
    media_stop = 178,
    /// @brief The Media Play/Pause key (Microsoft Natural Keyboard, Windows 2000 or later).
    media_play = 179,
    /// @brief The Start Mail key (Microsoft Natural Keyboard, Windows 2000 or later).
    launch_mail = 180,
    /// @brief The Select Media key (Microsoft Natural Keyboard, Windows 2000 or later).
    launch_media_select = 181,
    /// @brief The Start Application 1 key (Microsoft Natural Keyboard, Windows 2000 or later).
    launch_app1 = 182,
    /// @brief The Start Application 2 key (Microsoft Natural Keyboard, Windows 2000 or later).
    launch_app2 = 183,
    /// @brief The OEM 1 key (OEM specific).
    oem1 = 186,
    /// @brief The OEM Plus key on any country/region keyboard (Windows 2000 or later).
    oem_plus = 187,
    /// @brief The OEM Comma key on any country/region keyboard (Windows 2000 or later).
    oem_comma = 188,
    /// @brief The OEM Minus key on any country/region keyboard (Windows 2000 or later).
    oem_minus = 189,
    /// @brief The OEM Period key on any country/region keyboard (Windows 2000 or later).
    oem_period = 190,
    /// @brief The OEM 2 key (OEM specific).
    oem2 = 191,
    /// @brief The OEM " key (OEM specific).
    oem3 = 192,
    /// @brief The OEM 4 key (OEM specific).
    oem4 = 219,
    /// @brief The OEM 5 key (OEM specific).
    oem5 = 220,
    /// @brief The OEM 6 key (OEM specific).
    oem6 = 221,
    /// @brief The OEM 7 key (OEM specific).
    oem7 = 222,
    /// @brief The OEM 8 key (OEM specific).
    oem8 = 223,
    /// @brief The OEM 102 key (OEM specific).
    oem102 = 226,
    /// @brief The IME PROCESS key.
    process = 229,
    /// @brief The PACKET key (used to pass Unicode characters with keystrokes).
    packet = 231,
    /// @brief The ATTN key.
    attention = 246,
    /// @brief The CRSEL (CURSOR SELECT) key.
    cr_sel = 247,
    /// @brief The EXSEL (EXTEND SELECTION) key.
    ex_sel = 248,
    /// @brief The ERASE EOF key.
    erase_end_of_file = 249,
    /// @brief The Play key.
    play = 250,
    /// @brief The ZOOM key.
    zoom = 251,
    /// @brief A constant reserved for future use.
    no_name = 252,
    /// @brief The PA1 key.
    pa1 = 253,
    /// @brief The CLEAR key (OEM specific).
    oem_clear = 254
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::console_key> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::console_key> {{xtd::console_key::backspace, "backspace"}, {xtd::console_key::tab, "tab"}, {xtd::console_key::clear, "clear"}, {xtd::console_key::enter, "enter"}, {xtd::console_key::pause, "pause"}, {xtd::console_key::escape, "escape"}, {xtd::console_key::spacebar, "spacebar"}, {xtd::console_key::page_up, "page_up"}, {xtd::console_key::page_down, "page_down"}, {xtd::console_key::end, "end"}, {xtd::console_key::home, "home"}, {xtd::console_key::left_arrow, "left_arrow"}, {xtd::console_key::up_arrow, "up_arrow"}, {xtd::console_key::right_arrow, "right_arrow"}, {xtd::console_key::down_arrow, "down_arrow"}, {xtd::console_key::select, "select"}, {xtd::console_key::print, "print"}, {xtd::console_key::execute, "execute"}, {xtd::console_key::print_screen, "print_screen"}, {xtd::console_key::insert, "insert"}, {xtd::console_key::del, "del"}, {xtd::console_key::help, "help"}, {xtd::console_key::d0, "d0"}, {xtd::console_key::d1, "d1"}, {xtd::console_key::d2, "d2"}, {xtd::console_key::d3, "d3"}, {xtd::console_key::d4, "d4"}, {xtd::console_key::d5, "d5"}, {xtd::console_key::d6, "d6"}, {xtd::console_key::d7, "d7"}, {xtd::console_key::d8, "d8"}, {xtd::console_key::d9, "d9"}, {xtd::console_key::a, "a"}, {xtd::console_key::b, "b"}, {xtd::console_key::c, "c"}, {xtd::console_key::d, "d"}, {xtd::console_key::e, "e"}, {xtd::console_key::f, "f"}, {xtd::console_key::g, "g"}, {xtd::console_key::h, "h"}, {xtd::console_key::i, "i"}, {xtd::console_key::j, "j"}, {xtd::console_key::k, "k"}, {xtd::console_key::l, "l"}, {xtd::console_key::m, "m"}, {xtd::console_key::n, "n"}, {xtd::console_key::o, "o"}, {xtd::console_key::p, "p"}, {xtd::console_key::q, "q"}, {xtd::console_key::r, "r"}, {xtd::console_key::s, "s"}, {xtd::console_key::t, "t"}, {xtd::console_key::u, "u"}, {xtd::console_key::v, "v"}, {xtd::console_key::w, "w"}, {xtd::console_key::x, "x"}, {xtd::console_key::y, "y"}, {xtd::console_key::z, "z"}, {xtd::console_key::left_windows, "left_windows"}, {xtd::console_key::right_windows, "right_windows"}, {xtd::console_key::applications, "applications"}, {xtd::console_key::sleep, "sleep"}, {xtd::console_key::num_pad_0, "num_pad_0"}, {xtd::console_key::num_pad_1, "num_pad_1"}, {xtd::console_key::num_pad_2, "num_pad_2"}, {xtd::console_key::num_pad_3, "num_pad_3"}, {xtd::console_key::num_pad_4, "num_pad_4"}, {xtd::console_key::num_pad_5, "num_pad_5"}, {xtd::console_key::num_pad_6, "num_pad_6"}, {xtd::console_key::num_pad_7, "num_pad_7"}, {xtd::console_key::num_pad_8, "num_pad_8"}, {xtd::console_key::num_pad_9, "num_pad_9"}, {xtd::console_key::multiply, "multiply"}, {xtd::console_key::add, "add"}, {xtd::console_key::separator, "separator"}, {xtd::console_key::subtract, "subtract"}, {xtd::console_key::decimal, "decimal"}, {xtd::console_key::divide, "divide"}, {xtd::console_key::f1, "f1"}, {xtd::console_key::f2, "f2"}, {xtd::console_key::f3, "f3"}, {xtd::console_key::f4, "f4"}, {xtd::console_key::f5, "f5"}, {xtd::console_key::f6, "f6"}, {xtd::console_key::f7, "f7"}, {xtd::console_key::f8, "f8"}, {xtd::console_key::f9, "f9"}, {xtd::console_key::f10, "f10"}, {xtd::console_key::f11, "f11"}, {xtd::console_key::f12, "f12"}, {xtd::console_key::f13, "f13"}, {xtd::console_key::f14, "f14"}, {xtd::console_key::f15, "f15"}, {xtd::console_key::f16, "f16"}, {xtd::console_key::f17, "f17"}, {xtd::console_key::f18, "f18"}, {xtd::console_key::f19, "f19"}, {xtd::console_key::f20, "f20"}, {xtd::console_key::f21, "f21"}, {xtd::console_key::f22, "f22"}, {xtd::console_key::f23, "f23"}, {xtd::console_key::f24, "f24"}, {xtd::console_key::browser_back, "browser_back"}, {xtd::console_key::browser_forward, "browser_forward"}, {xtd::console_key::browser_refresh, "browser_refresh"}, {xtd::console_key::browser_stop, "browser_stop"}, {xtd::console_key::browser_search, "browser_search"}, {xtd::console_key::browser_favorites, "browser_favorites"}, {xtd::console_key::browser_home, "browser_home"}, {xtd::console_key::volume_mute, "volume_mute"}, {xtd::console_key::volume_down, "volume_down"}, {xtd::console_key::volume_up, "volume_up"}, {xtd::console_key::media_next, "media_next"}, {xtd::console_key::media_previous, "media_previous"}, {xtd::console_key::media_stop, "media_stop"}, {xtd::console_key::media_play, "media_play"}, {xtd::console_key::launch_mail, "launch_mail"}, {xtd::console_key::launch_media_select, "launch_media_select"}, {xtd::console_key::launch_app1, "launch_app1"}, {xtd::console_key::launch_app2, "launch_app2"}, {xtd::console_key::oem1, "oem1"}, {xtd::console_key::oem_plus, "oem_plus"}, {xtd::console_key::oem_comma, "oem_comma"}, {xtd::console_key::oem_minus, "oem_minus"}, {xtd::console_key::oem_period, "oem_period"}, {xtd::console_key::oem2, "oem2"}, {xtd::console_key::oem3, "oem3"}, {xtd::console_key::oem4, "oem4"}, {xtd::console_key::oem5, "oem5"}, {xtd::console_key::oem6, "oem6"}, {xtd::console_key::oem7, "oem7"}, {xtd::console_key::oem8, "oem8"}, {xtd::console_key::oem102, "oem102"}, {xtd::console_key::process, "process"}, {xtd::console_key::packet, "packet"}, {xtd::console_key::attention, "attention"}, {xtd::console_key::cr_sel, "cr_sel"}, {xtd::console_key::ex_sel, "ex_sel"}, {xtd::console_key::erase_end_of_file, "erase_end_of_file"}, {xtd::console_key::play, "play"}, {xtd::console_key::zoom, "zoom"}, {xtd::console_key::no_name, "no_name"}, {xtd::console_key::pa1, "pa1"}, {xtd::console_key::oem_clear, "oem_clear"}};}
};
/// @endcond

