/// @file
/// @brief Contains Switch::System::ConsoleKey enum.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access console.
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
    left_Windows = 91,
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
    numPad_8 = 104,
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
