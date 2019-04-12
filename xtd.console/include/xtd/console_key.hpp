/// @file
/// @brief Contains xtd::console_key enum.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the standard keys on a console.
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

template<typename Char>
std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, xtd::console_key ck) {
  switch (ck) {
    case xtd::console_key::backspace: os << std::basic_string<Char> {'b', 'a', 'c', 'k', 's', 'p', 'a', 'c', 'e'}; break;
    case xtd::console_key::tab: os << std::basic_string<Char> {'t', 'a', 'b'}; break;
    case xtd::console_key::clear: os << std::basic_string<Char> {'c', 'l', 'e', 'a', 'r'}; break;
    case xtd::console_key::enter: os << std::basic_string<Char> {'e', 'n', 't', 'e', 'r'}; break;
    case xtd::console_key::pause: os << std::basic_string<Char> {'p', 'a', 'u', 's', 'e'}; break;
    case xtd::console_key::escape: os << std::basic_string<Char> {'e', 's', 'c', 'a', 'p', 'e'}; break;
    case xtd::console_key::spacebar: os << std::basic_string<Char> {'s', 'p', 'a', 'c', 'e', 'b', 'a', 'r'}; break;
    case xtd::console_key::page_up: os << std::basic_string<Char> {'p', 'a', 'g', 'e', '_', 'u', 'p'}; break;
    case xtd::console_key::page_down: os << std::basic_string<Char> {'p', 'a', 'g', 'e', '_', 'd', 'o', 'w', 'n'}; break;
    case xtd::console_key::end: os << std::basic_string<Char> {'e', 'n', 'd'}; break;
    case xtd::console_key::home: os << std::basic_string<Char> {'h', 'o', 'm', 'e'}; break;
    case xtd::console_key::left_arrow: os << std::basic_string<Char> {'l', 'e', 'f', 't', '_', 'a', 'r', 'r', 'o', 'w'}; break;
    case xtd::console_key::up_arrow: os << std::basic_string<Char> {'u', 'p', '_', 'a', 'r', 'r', 'o', 'w'}; break;
    case xtd::console_key::right_arrow: os << std::basic_string<Char> {'r', 'i', 'g', 'h', 't', '_', 'a', 'r', 'r', 'o', 'w'}; break;
    case xtd::console_key::down_arrow: os << std::basic_string<Char> {'d', 'o', 'w', 'n', '_', 'a', 'r', 'r', 'o', 'w'}; break;
    case xtd::console_key::select: os << std::basic_string<Char> {'s', 'e', 'l', 'e', 'c', 't'}; break;
    case xtd::console_key::print: os << std::basic_string<Char> {'p', 'r', 'i', 'n', 't'}; break;
    case xtd::console_key::execute: os << std::basic_string<Char> {'e', 'x', 'e', 'c', 'u', 't', 'e'}; break;
    case xtd::console_key::print_screen: os << std::basic_string<Char> {'p', 'r', 'i', 'n', 't', '_', 's', 'c', 'r', 'e', 'e', 'n'}; break;
    case xtd::console_key::insert: os << std::basic_string<Char> {'i', 'n', 's', 'e', 'r', 't'}; break;
    case xtd::console_key::del: os << std::basic_string<Char> {'d', 'e', 'l'}; break;
    case xtd::console_key::help: os << std::basic_string<Char> {'h', 'e', 'l', 'p'}; break;
    case xtd::console_key::d0: os << std::basic_string<Char> {'d', '0'}; break;
    case xtd::console_key::d1: os << std::basic_string<Char> {'d', '1'}; break;
    case xtd::console_key::d2: os << std::basic_string<Char> {'d', '2'}; break;
    case xtd::console_key::d3: os << std::basic_string<Char> {'d', '3'}; break;
    case xtd::console_key::d4: os << std::basic_string<Char> {'d', '4'}; break;
    case xtd::console_key::d5: os << std::basic_string<Char> {'d', '5'}; break;
    case xtd::console_key::d6: os << std::basic_string<Char> {'d', '6'}; break;
    case xtd::console_key::d7: os << std::basic_string<Char> {'d', '7'}; break;
    case xtd::console_key::d8: os << std::basic_string<Char> {'d', '8'}; break;
    case xtd::console_key::d9: os << std::basic_string<Char> {'d', '9'}; break;
    case xtd::console_key::a: os << std::basic_string<Char> {'a'}; break;
    case xtd::console_key::b: os << std::basic_string<Char> {'b'}; break;
    case xtd::console_key::c: os << std::basic_string<Char> {'c'}; break;
    case xtd::console_key::d: os << std::basic_string<Char> {'d'}; break;
    case xtd::console_key::e: os << std::basic_string<Char> {'e'}; break;
    case xtd::console_key::f: os << std::basic_string<Char> {'f'}; break;
    case xtd::console_key::g: os << std::basic_string<Char> {'g'}; break;
    case xtd::console_key::h: os << std::basic_string<Char> {'h'}; break;
    case xtd::console_key::i: os << std::basic_string<Char> {'i'}; break;
    case xtd::console_key::j: os << std::basic_string<Char> {'j'}; break;
    case xtd::console_key::k: os << std::basic_string<Char> {'k'}; break;
    case xtd::console_key::l: os << std::basic_string<Char> {'l'}; break;
    case xtd::console_key::m: os << std::basic_string<Char> {'m'}; break;
    case xtd::console_key::n: os << std::basic_string<Char> {'n'}; break;
    case xtd::console_key::o: os << std::basic_string<Char> {'o'}; break;
    case xtd::console_key::p: os << std::basic_string<Char> {'p'}; break;
    case xtd::console_key::q: os << std::basic_string<Char> {'q'}; break;
    case xtd::console_key::r: os << std::basic_string<Char> {'r'}; break;
    case xtd::console_key::s: os << std::basic_string<Char> {'s'}; break;
    case xtd::console_key::t: os << std::basic_string<Char> {'t'}; break;
    case xtd::console_key::u: os << std::basic_string<Char> {'u'}; break;
    case xtd::console_key::v: os << std::basic_string<Char> {'v'}; break;
    case xtd::console_key::w: os << std::basic_string<Char> {'w'}; break;
    case xtd::console_key::x: os << std::basic_string<Char> {'x'}; break;
    case xtd::console_key::y: os << std::basic_string<Char> {'y'}; break;
    case xtd::console_key::z: os << std::basic_string<Char> {'z'}; break;
    case xtd::console_key::left_windows: os << std::basic_string<Char> {'l', 'e', 'f', 't', '_', 'w', 'i', 'n', 'd', 'o', 'w', 's'}; break;
    case xtd::console_key::right_windows: os << std::basic_string<Char> {'r', 'i', 'g', 'h', 't', '_', 'w', 'i', 'n', 'd', 'o', 'w', 's'}; break;
    case xtd::console_key::applications: os << std::basic_string<Char> {'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', 's'}; break;
    case xtd::console_key::sleep: os << std::basic_string<Char> {'s', 'l', 'e', 'e', 'p'}; break;
    case xtd::console_key::num_pad_0: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '0'}; break;
    case xtd::console_key::num_pad_1: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '1'}; break;
    case xtd::console_key::num_pad_2: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '2'}; break;
    case xtd::console_key::num_pad_3: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '3'}; break;
    case xtd::console_key::num_pad_4: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '4'}; break;
    case xtd::console_key::num_pad_5: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '5'}; break;
    case xtd::console_key::num_pad_6: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '6'}; break;
    case xtd::console_key::num_pad_7: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '7'}; break;
    case xtd::console_key::num_pad_8: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '8'}; break;
    case xtd::console_key::num_pad_9: os << std::basic_string<Char> {'n', 'u', 'm', '_', 'p', 'a', 'd', '_', '9'}; break;
    case xtd::console_key::multiply: os << std::basic_string<Char> {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'}; break;
    case xtd::console_key::add: os << std::basic_string<Char> {'a', 'd', 'd'}; break;
    case xtd::console_key::separator: os << std::basic_string<Char> {'s', 'e', 'p', 'a', 'r', 'a', 't', 'o', 'r'}; break;
    case xtd::console_key::subtract: os << std::basic_string<Char> {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'}; break;
    case xtd::console_key::decimal: os << std::basic_string<Char> {'d', 'e', 'c', 'i', 'm', 'a', 'l'}; break;
    case xtd::console_key::divide: os << std::basic_string<Char> {'d', 'i', 'v', 'i', 'd', 'e'}; break;
    case xtd::console_key::f1: os << std::basic_string<Char> {'f', '1'}; break;
    case xtd::console_key::f2: os << std::basic_string<Char> {'f', '2'}; break;
    case xtd::console_key::f3: os << std::basic_string<Char> {'f', '3'}; break;
    case xtd::console_key::f4: os << std::basic_string<Char> {'f', '4'}; break;
    case xtd::console_key::f5: os << std::basic_string<Char> {'f', '5'}; break;
    case xtd::console_key::f6: os << std::basic_string<Char> {'f', '6'}; break;
    case xtd::console_key::f7: os << std::basic_string<Char> {'f', '7'}; break;
    case xtd::console_key::f8: os << std::basic_string<Char> {'f', '8'}; break;
    case xtd::console_key::f9: os << std::basic_string<Char> {'f', '9'}; break;
    case xtd::console_key::f10: os << std::basic_string<Char> {'f', '1', '0'}; break;
    case xtd::console_key::f11: os << std::basic_string<Char> {'f', '1', '1'}; break;
    case xtd::console_key::f12: os << std::basic_string<Char> {'f', '1', '2'}; break;
    case xtd::console_key::f13: os << std::basic_string<Char> {'f', '1', '3'}; break;
    case xtd::console_key::f14: os << std::basic_string<Char> {'f', '1', '4'}; break;
    case xtd::console_key::f15: os << std::basic_string<Char> {'f', '1', '5'}; break;
    case xtd::console_key::f16: os << std::basic_string<Char> {'f', '1', '6'}; break;
    case xtd::console_key::f17: os << std::basic_string<Char> {'f', '1', '7'}; break;
    case xtd::console_key::f18: os << std::basic_string<Char> {'f', '1', '8'}; break;
    case xtd::console_key::f19: os << std::basic_string<Char> {'f', '1', '9'}; break;
    case xtd::console_key::f20: os << std::basic_string<Char> {'f', '2', '0'}; break;
    case xtd::console_key::f21: os << std::basic_string<Char> {'f', '2', '1'}; break;
    case xtd::console_key::f22: os << std::basic_string<Char> {'f', '2', '2'}; break;
    case xtd::console_key::f23: os << std::basic_string<Char> {'f', '2', '3'}; break;
    case xtd::console_key::f24: os << std::basic_string<Char> {'f', '2', '4'}; break;
    case xtd::console_key::browser_back: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 'b', 'a', 'c', 'k'}; break;
    case xtd::console_key::browser_forward: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 'f', 'o', 'r', 'w', 'a', 'r', 'd'}; break;
    case xtd::console_key::browser_refresh: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 'r', 'e', 'f', 'r', 'e', 's', 'h'}; break;
    case xtd::console_key::browser_stop: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 's', 't', 'o', 'p'}; break;
    case xtd::console_key::browser_search: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 's', 'e', 'a', 'r', 'c', 'h'}; break;
    case xtd::console_key::browser_favorites: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 'f', 'a', 'v', 'o', 'r', 'i', 't', 'e', 's'}; break;
    case xtd::console_key::browser_home: os << std::basic_string<Char> {'b', 'r', 'o', 'w', 's', 'e', 'r', '_', 'h', 'o', 'm', 'e'}; break;
    case xtd::console_key::volume_mute: os << std::basic_string<Char> {'v', 'o', 'l', 'u', 'm', 'e', '_', 'm', 'u', 't', 'e'}; break;
    case xtd::console_key::volume_down: os << std::basic_string<Char> {'v', 'o', 'l', 'u', 'm', 'e', '_', 'd', 'o', 'w', 'n'}; break;
    case xtd::console_key::volume_up: os << std::basic_string<Char> {'v', 'o', 'l', 'u', 'm', 'e', '_', 'u', 'p'}; break;
    case xtd::console_key::media_next: os << std::basic_string<Char> {'m', 'e', 'd', 'i', 'a', '_', 'n', 'e', 'x', 't'}; break;
    case xtd::console_key::media_previous: os << std::basic_string<Char> {'m', 'e', 'd', 'i', 'a', '_', 'p', 'r', 'e', 'v', 'i', 'o', 'u', 's'}; break;
    case xtd::console_key::media_stop: os << std::basic_string<Char> {'m', 'e', 'd', 'i', 'a', '_', 's', 't', 'o', 'p'}; break;
    case xtd::console_key::media_play: os << std::basic_string<Char> {'m', 'e', 'd', 'i', 'a', '_', 'p', 'l', 'a', 'y'}; break;
    case xtd::console_key::launch_mail: os << std::basic_string<Char> {'l', 'a', 'u', 'n', 'c', 'h', '_', 'm', 'a', 'i', 'l'}; break;
    case xtd::console_key::launch_media_select: os << std::basic_string<Char> {'l', 'a', 'u', 'n', 'c', 'h', '_', 'm', 'e', 'd', 'i', 'a', '_', 's', 'e', 'l', 'e', 'c', 't'}; break;
    case xtd::console_key::launch_app1: os << std::basic_string<Char> {'l', 'a', 'u', 'n', 'c', 'h', '_', 'a', 'p', 'p', '1'}; break;
    case xtd::console_key::launch_app2: os << std::basic_string<Char> {'l', 'a', 'u', 'n', 'c', 'h', '_', 'a', 'p', 'p', '2'}; break;
    case xtd::console_key::oem1: os << std::basic_string<Char> {'o', 'e', 'm', '1'}; break;
    case xtd::console_key::oem_plus: os << std::basic_string<Char> {'o', 'e', 'm', '_', 'p', 'l', 'u', 's'}; break;
    case xtd::console_key::oem_comma: os << std::basic_string<Char> {'o', 'e', 'm', '_', 'c', 'o', 'm', 'm', 'a'}; break;
    case xtd::console_key::oem_minus: os << std::basic_string<Char> {'o', 'e', 'm', '_', 'm', 'i', 'n', 'u', 's'}; break;
    case xtd::console_key::oem_period: os << std::basic_string<Char> {'o', 'e', 'm', '_', 'p', 'e', 'r', 'i', 'o', 'd'}; break;
    case xtd::console_key::oem2: os << std::basic_string<Char> {'o', 'e', 'm', '2'}; break;
    case xtd::console_key::oem3: os << std::basic_string<Char> {'o', 'e', 'm', '3'}; break;
    case xtd::console_key::oem4: os << std::basic_string<Char> {'o', 'e', 'm', '4'}; break;
    case xtd::console_key::oem5: os << std::basic_string<Char> {'o', 'e', 'm', '5'}; break;
    case xtd::console_key::oem6: os << std::basic_string<Char> {'o', 'e', 'm', '6'}; break;
    case xtd::console_key::oem7: os << std::basic_string<Char> {'o', 'e', 'm', '7'}; break;
    case xtd::console_key::oem8: os << std::basic_string<Char> {'o', 'e', 'm', '8'}; break;
    case xtd::console_key::oem102: os << std::basic_string<Char> {'o', 'e', 'm', '1', '0', '2'}; break;
    case xtd::console_key::process: os << std::basic_string<Char> {'p', 'r', 'o', 'c', 'e', 's', 's'}; break;
    case xtd::console_key::packet: os << std::basic_string<Char> {'p', 'a', 'c', 'k', 'e', 't'}; break;
    case xtd::console_key::attention: os << std::basic_string<Char> {'a', 't', 't', 'e', 'n', 't', 'i', 'o', 'n'}; break;
    case xtd::console_key::cr_sel: os << std::basic_string<Char> {'c', 'r', '_', 's', 'e', 'l'}; break;
    case xtd::console_key::ex_sel: os << std::basic_string<Char> {'e', 'x', '_', 's', 'e', 'l'}; break;
    case xtd::console_key::erase_end_of_file: os << std::basic_string<Char> {'e', 'r', 'a', 's', 'e', '_', 'e', 'n', 'd', '_', 'o', 'f', '_', 'f', 'i', 'l', 'e'}; break;
    case xtd::console_key::play: os << std::basic_string<Char> {'p', 'l', 'a', 'y'}; break;
    case xtd::console_key::zoom: os << std::basic_string<Char> {'z', 'o', 'o', 'm'}; break;
    case xtd::console_key::no_name: os << std::basic_string<Char> {'n', 'o', '_', 'n', 'a', 'm', 'e'}; break;
    case xtd::console_key::pa1: os << std::basic_string<Char> {'p', 'a', '1'}; break;
    case xtd::console_key::oem_clear: os << std::basic_string<Char> {'o', 'e', 'm', '_', 'c', 'l', 'e', 'a', 'r'}; break;
      
    default: os << static_cast<int>(ck); break;
  }
  return os;
}
