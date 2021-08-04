/// @file
/// @brief Contains xtd::console_key enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the standard keys on a console.
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

  /// @cond
  inline std::ostream& operator<<(std::ostream& os, xtd::console_key value) {return os << to_string(value, {{console_key::backspace, "backspace"}, {console_key::tab, "tab"}, {console_key::clear, "clear"}, {console_key::enter, "enter"}, {console_key::pause, "pause"}, {console_key::escape, "escape"}, {console_key::spacebar, "spacebar"}, {console_key::page_up, "page_up"}, {console_key::page_down, "page_down"}, {console_key::end, "end"}, {console_key::home, "home"}, {console_key::left_arrow, "left_arrow"}, {console_key::up_arrow, "up_arrow"}, {console_key::right_arrow, "right_arrow"}, {console_key::down_arrow, "down_arrow"}, {console_key::select, "select"}, {console_key::print, "print"}, {console_key::execute, "execute"}, {console_key::print_screen, "print_screen"}, {console_key::insert, "insert"}, {console_key::del, "del"}, {console_key::help, "help"}, {console_key::d0, "d0"}, {console_key::d1, "d1"}, {console_key::d2, "d2"}, {console_key::d3, "d3"}, {console_key::d4, "d4"}, {console_key::d5, "d5"}, {console_key::d6, "d6"}, {console_key::d7, "d7"}, {console_key::d8, "d8"}, {console_key::d9, "d9"}, {console_key::a, "a"}, {console_key::b, "b"}, {console_key::c, "c"}, {console_key::d, "d"}, {console_key::e, "e"}, {console_key::f, "f"}, {console_key::g, "g"}, {console_key::h, "h"}, {console_key::i, "i"}, {console_key::j, "j"}, {console_key::k, "k"}, {console_key::l, "l"}, {console_key::m, "m"}, {console_key::n, "n"}, {console_key::o, "o"}, {console_key::p, "p"}, {console_key::q, "q"}, {console_key::r, "r"}, {console_key::s, "s"}, {console_key::t, "t"}, {console_key::u, "u"}, {console_key::v, "v"}, {console_key::w, "w"}, {console_key::x, "x"}, {console_key::y, "y"}, {console_key::z, "z"}, {console_key::left_windows, "left_windows"}, {console_key::right_windows, "right_windows"}, {console_key::applications, "applications"}, {console_key::sleep, "sleep"}, {console_key::num_pad_0, "num_pad_0"}, {console_key::num_pad_1, "num_pad_1"}, {console_key::num_pad_2, "num_pad_2"}, {console_key::num_pad_3, "num_pad_3"}, {console_key::num_pad_4, "num_pad_4"}, {console_key::num_pad_5, "num_pad_5"}, {console_key::num_pad_6, "num_pad_6"}, {console_key::num_pad_7, "num_pad_7"}, {console_key::num_pad_8, "num_pad_8"}, {console_key::num_pad_9, "num_pad_9"}, {console_key::multiply, "multiply"}, {console_key::add, "add"}, {console_key::separator, "separator"}, {console_key::subtract, "subtract"}, {console_key::decimal, "decimal"}, {console_key::divide, "divide"}, {console_key::f1, "f1"}, {console_key::f2, "f2"}, {console_key::f3, "f3"}, {console_key::f4, "f4"}, {console_key::f5, "f5"}, {console_key::f6, "f6"}, {console_key::f7, "f7"}, {console_key::f8, "f8"}, {console_key::f9, "f9"}, {console_key::f10, "f10"}, {console_key::f11, "f11"}, {console_key::f12, "f12"}, {console_key::f13, "f13"}, {console_key::f14, "f14"}, {console_key::f15, "f15"}, {console_key::f16, "f16"}, {console_key::f17, "f17"}, {console_key::f18, "f18"}, {console_key::f19, "f19"}, {console_key::f20, "f20"}, {console_key::f21, "f21"}, {console_key::f22, "f22"}, {console_key::f23, "f23"}, {console_key::f24, "f24"}, {console_key::browser_back, "browser_back"}, {console_key::browser_forward, "browser_forward"}, {console_key::browser_refresh, "browser_refresh"}, {console_key::browser_stop, "browser_stop"}, {console_key::browser_search, "browser_search"}, {console_key::browser_favorites, "browser_favorites"}, {console_key::browser_home, "browser_home"}, {console_key::volume_mute, "volume_mute"}, {console_key::volume_down, "volume_down"}, {console_key::volume_up, "volume_up"}, {console_key::media_next, "media_next"}, {console_key::media_previous, "media_previous"}, {console_key::media_stop, "media_stop"}, {console_key::media_play, "media_play"}, {console_key::launch_mail, "launch_mail"}, {console_key::launch_media_select, "launch_media_select"}, {console_key::launch_app1, "launch_app1"}, {console_key::launch_app2, "launch_app2"}, {console_key::oem1, "oem1"}, {console_key::oem_plus, "oem_plus"}, {console_key::oem_comma, "oem_comma"}, {console_key::oem_minus, "oem_minus"}, {console_key::oem_period, "oem_period"}, {console_key::oem2, "oem2"}, {console_key::oem3, "oem3"}, {console_key::oem4, "oem4"}, {console_key::oem5, "oem5"}, {console_key::oem6, "oem6"}, {console_key::oem7, "oem7"}, {console_key::oem8, "oem8"}, {console_key::oem102, "oem102"}, {console_key::process, "process"}, {console_key::packet, "packet"}, {console_key::attention, "attention"}, {console_key::cr_sel, "cr_sel"}, {console_key::ex_sel, "ex_sel"}, {console_key::erase_end_of_file, "erase_end_of_file"}, {console_key::play, "play"}, {console_key::zoom, "zoom"}, {console_key::no_name, "no_name"}, {console_key::pa1, "pa1"}, {console_key::oem_clear, "oem_clear"}});}
  inline std::wostream& operator<<(std::wostream& os, xtd::console_key value) {return os << to_string(value, {{console_key::backspace, L"backspace"}, {console_key::tab, L"tab"}, {console_key::clear, L"clear"}, {console_key::enter, L"enter"}, {console_key::pause, L"pause"}, {console_key::escape, L"escape"}, {console_key::spacebar, L"spacebar"}, {console_key::page_up, L"page_up"}, {console_key::page_down, L"page_down"}, {console_key::end, L"end"}, {console_key::home, L"home"}, {console_key::left_arrow, L"left_arrow"}, {console_key::up_arrow, L"up_arrow"}, {console_key::right_arrow, L"right_arrow"}, {console_key::down_arrow, L"down_arrow"}, {console_key::select, L"select"}, {console_key::print, L"print"}, {console_key::execute, L"execute"}, {console_key::print_screen, L"print_screen"}, {console_key::insert, L"insert"}, {console_key::del, L"del"}, {console_key::help, L"help"}, {console_key::d0, L"d0"}, {console_key::d1, L"d1"}, {console_key::d2, L"d2"}, {console_key::d3, L"d3"}, {console_key::d4, L"d4"}, {console_key::d5, L"d5"}, {console_key::d6, L"d6"}, {console_key::d7, L"d7"}, {console_key::d8, L"d8"}, {console_key::d9, L"d9"}, {console_key::a, L"a"}, {console_key::b, L"b"}, {console_key::c, L"c"}, {console_key::d, L"d"}, {console_key::e, L"e"}, {console_key::f, L"f"}, {console_key::g, L"g"}, {console_key::h, L"h"}, {console_key::i, L"i"}, {console_key::j, L"j"}, {console_key::k, L"k"}, {console_key::l, L"l"}, {console_key::m, L"m"}, {console_key::n, L"n"}, {console_key::o, L"o"}, {console_key::p, L"p"}, {console_key::q, L"q"}, {console_key::r, L"r"}, {console_key::s, L"s"}, {console_key::t, L"t"}, {console_key::u, L"u"}, {console_key::v, L"v"}, {console_key::w, L"w"}, {console_key::x, L"x"}, {console_key::y, L"y"}, {console_key::z, L"z"}, {console_key::left_windows, L"left_windows"}, {console_key::right_windows, L"right_windows"}, {console_key::applications, L"applications"}, {console_key::sleep, L"sleep"}, {console_key::num_pad_0, L"num_pad_0"}, {console_key::num_pad_1, L"num_pad_1"}, {console_key::num_pad_2, L"num_pad_2"}, {console_key::num_pad_3, L"num_pad_3"}, {console_key::num_pad_4, L"num_pad_4"}, {console_key::num_pad_5, L"num_pad_5"}, {console_key::num_pad_6, L"num_pad_6"}, {console_key::num_pad_7, L"num_pad_7"}, {console_key::num_pad_8, L"num_pad_8"}, {console_key::num_pad_9, L"num_pad_9"}, {console_key::multiply, L"multiply"}, {console_key::add, L"add"}, {console_key::separator, L"separator"}, {console_key::subtract, L"subtract"}, {console_key::decimal, L"decimal"}, {console_key::divide, L"divide"}, {console_key::f1, L"f1"}, {console_key::f2, L"f2"}, {console_key::f3, L"f3"}, {console_key::f4, L"f4"}, {console_key::f5, L"f5"}, {console_key::f6, L"f6"}, {console_key::f7, L"f7"}, {console_key::f8, L"f8"}, {console_key::f9, L"f9"}, {console_key::f10, L"f10"}, {console_key::f11, L"f11"}, {console_key::f12, L"f12"}, {console_key::f13, L"f13"}, {console_key::f14, L"f14"}, {console_key::f15, L"f15"}, {console_key::f16, L"f16"}, {console_key::f17, L"f17"}, {console_key::f18, L"f18"}, {console_key::f19, L"f19"}, {console_key::f20, L"f20"}, {console_key::f21, L"f21"}, {console_key::f22, L"f22"}, {console_key::f23, L"f23"}, {console_key::f24, L"f24"}, {console_key::browser_back, L"browser_back"}, {console_key::browser_forward, L"browser_forward"}, {console_key::browser_refresh, L"browser_refresh"}, {console_key::browser_stop, L"browser_stop"}, {console_key::browser_search, L"browser_search"}, {console_key::browser_favorites, L"browser_favorites"}, {console_key::browser_home, L"browser_home"}, {console_key::volume_mute, L"volume_mute"}, {console_key::volume_down, L"volume_down"}, {console_key::volume_up, L"volume_up"}, {console_key::media_next, L"media_next"}, {console_key::media_previous, L"media_previous"}, {console_key::media_stop, L"media_stop"}, {console_key::media_play, L"media_play"}, {console_key::launch_mail, L"launch_mail"}, {console_key::launch_media_select, L"launch_media_select"}, {console_key::launch_app1, L"launch_app1"}, {console_key::launch_app2, L"launch_app2"}, {console_key::oem1, L"oem1"}, {console_key::oem_plus, L"oem_plus"}, {console_key::oem_comma, L"oem_comma"}, {console_key::oem_minus, L"oem_minus"}, {console_key::oem_period, L"oem_period"}, {console_key::oem2, L"oem2"}, {console_key::oem3, L"oem3"}, {console_key::oem4, L"oem4"}, {console_key::oem5, L"oem5"}, {console_key::oem6, L"oem6"}, {console_key::oem7, L"oem7"}, {console_key::oem8, L"oem8"}, {console_key::oem102, L"oem102"}, {console_key::process, L"process"}, {console_key::packet, L"packet"}, {console_key::attention, L"attention"}, {console_key::cr_sel, L"cr_sel"}, {console_key::ex_sel, L"ex_sel"}, {console_key::erase_end_of_file, L"erase_end_of_file"}, {console_key::play, L"play"}, {console_key::zoom, L"zoom"}, {console_key::no_name, L"no_name"}, {console_key::pa1, L"pa1"}, {console_key::oem_clear, L"oem_clear"}});}
  /// @endcond
}
