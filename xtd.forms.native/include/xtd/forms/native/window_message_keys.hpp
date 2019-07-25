#pragma once

#ifndef MK_LBUTTON
constexpr int MK_LBUTTON = 0x0001;
constexpr int MK_RBUTTON = 0x0002;
constexpr int MK_SHIFT = 0x0004;
constexpr int MK_CONTROL = 0x0008;
constexpr int MK_MBUTTON = 0x0010;
constexpr int MK_XBUTTON1 = 0x0020;
constexpr int MK_XBUTTON2 = 0x0040;
#endif

constexpr int VK_NONE = 0x000000;
constexpr int VK_LINE_FEED = 0x00000A;
constexpr int VK_PAGEUP = 0x000021;
constexpr int VK_PAGEDOWN = 0x000022;

constexpr int VK_0 = 0x000030;
constexpr int VK_1 = 0x000031;
constexpr int VK_2 = 0x000032;
constexpr int VK_3 = 0x000033;
constexpr int VK_4 = 0x000034;
constexpr int VK_5 = 0x000035;
constexpr int VK_6 = 0x000036;
constexpr int VK_7 = 0x000037;
constexpr int VK_8 = 0x000038;
constexpr int VK_9 = 0x000039;

constexpr int VK_A = 0x000041;
constexpr int VK_B = 0x000042;
constexpr int VK_C = 0x000043;
constexpr int VK_D = 0x000044;
constexpr int VK_E = 0x000045;
constexpr int VK_F = 0x000046;
constexpr int VK_G = 0x000047;
constexpr int VK_H = 0x000048;
constexpr int VK_I = 0x000049;
constexpr int VK_J = 0x00004A;
constexpr int VK_K = 0x00004B;
constexpr int VK_L = 0x00004C;
constexpr int VK_M = 0x00004D;
constexpr int VK_N = 0x00004E;
constexpr int VK_O = 0x00004F;
constexpr int VK_P = 0x000050;
constexpr int VK_Q = 0x000051;
constexpr int VK_R = 0x000052;
constexpr int VK_S = 0x000053;
constexpr int VK_T = 0x000054;
constexpr int VK_U = 0x000055;
constexpr int VK_V = 0x000056;
constexpr int VK_W = 0x000057;
constexpr int VK_X = 0x000058;
constexpr int VK_Y = 0x000059;
constexpr int VK_Z = 0x00005A;

constexpr int VK_COMMAND = 0x00000100;
constexpr int VK_LCOMMAND = 0x00000101;
constexpr int VK_RCOMMAND = 0x00000102;

constexpr int VK_SHIFT_MODIFIER = 0x00010000;
constexpr int VK_CONTROL_MODIFIER = 0x00020000;
constexpr int VK_ALT_MODIFIER = 0x00040000;
constexpr int VK_COMMAND_MODIFIER = 0x00080000;

#ifndef VK_LBUTTON
constexpr int VK_LBUTTON = 0x000001;
constexpr int VK_RBUTTON = 0x000002;
constexpr int VK_CANCEL = 0x000003;
constexpr int VK_MBUTTON = 0x000004;
constexpr int VK_XBUTTON1 = 0x000005;
constexpr int VK_XBUTTON2 = 0x000006;
// 0x000007 : reserved
constexpr int VK_BACK = 0x000008;
constexpr int VK_TAB = 0x000009;
// 0x00000A - 0x00000B : reserved
constexpr int VK_CLEAR = 0x00000C;
constexpr int VK_RETURN = 0x00000D;
// 0x00000E - 0x00000F : unassigned
constexpr int VK_SHIFT = 0x000010;
constexpr int VK_CONTROL = 0x000011;
constexpr int VK_MENU = 0x000012;
constexpr int VK_PAUSE = 0x000013;
constexpr int VK_CAPITAL = 0x000014;

constexpr int VK_KANA = 0x000015;
constexpr int VK_HANGEUL = 0x000015;
constexpr int VK_HANGUL = 0x000015;

// 0x000016 : unassigned
constexpr int VK_JUNJA = 0x000017;
constexpr int VK_FINAL = 0x000018;
constexpr int VK_HANJA = 0x000019;
constexpr int VK_KANJI = 0x000019;

// 0x00001A : unassigned

constexpr int VK_ESCAPE = 0x00001B;

constexpr int VK_CONVERT = 0x00001C;
constexpr int VK_NONCONVERT = 0x00001D;
constexpr int VK_ACCEPT = 0x00001E;
constexpr int VK_MODECHANGE = 0x00001F;

constexpr int VK_SPACE = 0x000020;
constexpr int VK_PRIOR = 0x000021;
constexpr int VK_NEXT = 0x000022;
constexpr int VK_END = 0x000023;
constexpr int VK_HOME = 0x000024;
constexpr int VK_LEFT = 0x000025;
constexpr int VK_UP = 0x000026;
constexpr int VK_RIGHT = 0x000027;
constexpr int VK_DOWN = 0x000028;
constexpr int VK_SELECT = 0x000029;
constexpr int VK_PRINT = 0x00002A;
constexpr int VK_EXECUTE = 0x00002B;
constexpr int VK_SNAPSHOT = 0x00002C;
constexpr int VK_INSERT = 0x00002D;
constexpr int VK_DELETE = 0x00002E;
constexpr int VK_HELP = 0x00002F;

// VK_0 - VK_9 are the same as ASCII '0' - '9' (0x000030 - 0x000039)
// 0x00003A - 0x000040 : unassigned
// VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x000041 - 0x00005A)

constexpr int VK_LWIN = 0x00005B;
constexpr int VK_RWIN = 0x00005C;
constexpr int VK_APPS = 0x00005D;

// 0x00005E : reserved

constexpr int VK_SLEEP = 0x00005F;

constexpr int VK_NUMPAD0 = 0x000060;
constexpr int VK_NUMPAD1 = 0x000061;
constexpr int VK_NUMPAD2 = 0x000062;
constexpr int VK_NUMPAD3 = 0x000063;
constexpr int VK_NUMPAD4 = 0x000064;
constexpr int VK_NUMPAD5 = 0x000065;
constexpr int VK_NUMPAD6 = 0x000066;
constexpr int VK_NUMPAD7 = 0x000067;
constexpr int VK_NUMPAD8 = 0x000068;
constexpr int VK_NUMPAD9 = 0x000069;
constexpr int VK_MULTIPLY = 0x00006A;
constexpr int VK_ADD = 0x00006B;
constexpr int VK_SEPARATOR = 0x00006C;
constexpr int VK_SUBTRACT = 0x00006D;
constexpr int VK_DECIMAL = 0x00006E;
constexpr int VK_DIVIDE =  0x00006F;
constexpr int VK_F1 = 0x000070;
constexpr int VK_F2 = 0x000071;
constexpr int VK_F3 = 0x000072;
constexpr int VK_F4 = 0x000073;
constexpr int VK_F5 = 0x000074;
constexpr int VK_F6 = 0x000075;
constexpr int VK_F7 = 0x000076;
constexpr int VK_F8 = 0x000077;
constexpr int VK_F9 = 0x000078;
constexpr int VK_F10 = 0x000079;
constexpr int VK_F11 = 0x00007A;
constexpr int VK_F12 = 0x00007B;
constexpr int VK_F13 = 0x00007C;
constexpr int VK_F14 = 0x00007D;
constexpr int VK_F15 = 0x00007E;
constexpr int VK_F16 = 0x00007F;
constexpr int VK_F17 = 0x000080;
constexpr int VK_F18 = 0x000081;
constexpr int VK_F19 = 0x000082;
constexpr int VK_F20 = 0x000083;
constexpr int VK_F21 = 0x000084;
constexpr int VK_F22 = 0x000085;
constexpr int VK_F23 = 0x000086;
constexpr int VK_F24 = 0x000087;

// 0x000088 - 0x00008F : UI navigation

constexpr int VK_NAVIGATION_VIEW = 0x000088; // reserved
constexpr int VK_NAVIGATION_MENU = 0x000089; // reserved
constexpr int VK_NAVIGATION_UP = 0x00008A; // reserved
constexpr int VK_NAVIGATION_DOWN = 0x00008B; // reserved
constexpr int VK_NAVIGATION_LEFT = 0x00008C; // reserved
constexpr int VK_NAVIGATION_RIGHT = 0x00008D; // reserved
constexpr int VK_NAVIGATION_ACCEPT = 0x00008E; // reserved
constexpr int VK_NAVIGATION_CANCEL = 0x00008F; // reserved

constexpr int VK_NUMLOCK = 0x000090;
constexpr int VK_SCROLL = 0x000091;

// NEC PC-9800 kbd definitions
constexpr int VK_OEM_NEC_EQUAL = 0x000092; // '=' key on numpad

// Fujitsu/OASYS kbd definitions
constexpr int VK_OEM_FJ_JISHO = 0x000092; // 'Dictionary' key
constexpr int VK_OEM_FJ_MASSHOU = 0x000093; // 'Unregister word' key
constexpr int VK_OEM_FJ_TOUROKU = 0x000094; // 'Register word' key
constexpr int VK_OEM_FJ_LOYA = 0x000095; // 'Left OYAYUBI' key
constexpr int VK_OEM_FJ_ROYA = 0x000096; // 'Right OYAYUBI' key

// 0x000097 - 0x00009F : unassigned

// VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
// Used only as parameters to GetAsyncKeyState() and GetKeyState().
// No other API or message will distinguish left and right keys in this way.
constexpr int VK_LSHIFT = 0x0000A0;
constexpr int VK_RSHIFT = 0x0000A1;
constexpr int VK_LCONTROL = 0x0000A2;
constexpr int VK_RCONTROL = 0x0000A3;
constexpr int VK_LMENU = 0x0000A4;
constexpr int VK_RMENU = 0x0000A5;

constexpr int VK_BROWSER_BACK = 0x0000A6;
constexpr int VK_BROWSER_FORWARD = 0x0000A7;
constexpr int VK_BROWSER_REFRESH = 0x0000A8;
constexpr int VK_BROWSER_STOP = 0x0000A9;
constexpr int VK_BROWSER_SEARCH = 0x0000AA;
constexpr int VK_BROWSER_FAVORITES = 0x0000AB;
constexpr int VK_BROWSER_HOME = 0x0000AC;

constexpr int VK_VOLUME_MUTE = 0x0000AD;
constexpr int VK_VOLUME_DOWN = 0x0000AE;
constexpr int VK_VOLUME_UP = 0x0000AF;
constexpr int VK_MEDIA_NEXT_TRACK = 0x0000B0;
constexpr int VK_MEDIA_PREV_TRACK = 0x0000B1;
constexpr int VK_MEDIA_STOP = 0x0000B2;
constexpr int VK_MEDIA_PLAY_PAUSE = 0x0000B3;
constexpr int VK_LAUNCH_MAIL = 0x0000B4;
constexpr int VK_LAUNCH_MEDIA_SELECT = 0x0000B5;
constexpr int VK_LAUNCH_APP1 = 0x0000B6;
constexpr int VK_LAUNCH_APP2 = 0x0000B7;

// 0x0000B8 - 0x0000B9 : reserved

constexpr int VK_OEM_1 = 0x0000BA; // ';:' for US
constexpr int VK_OEM_PLUS = 0x0000BB; // '+' any country
constexpr int VK_OEM_COMMA = 0x0000BC; // ',' any country
constexpr int VK_OEM_MINUS = 0x0000BD; // '-' any country
constexpr int VK_OEM_PERIOD = 0x0000BE; // '.' any country
constexpr int VK_OEM_2 = 0x0000BF; // '/?' for US
constexpr int VK_OEM_3 = 0x0000C0; // '`~' for US

// 0x0000C1 - 0x0000C2 : reserved

// 0x0000C3 - 0x0000DA : Gamepad input

constexpr int VK_GAMEPAD_A = 0x0000C3; // reserved
constexpr int VK_GAMEPAD_B = 0x0000C4; // reserved
constexpr int VK_GAMEPAD_X = 0x0000C5; // reserved
constexpr int VK_GAMEPAD_Y = 0x0000C6; // reserved
constexpr int VK_GAMEPAD_RIGHT_SHOULDER = 0x0000C7; // reserved
constexpr int VK_GAMEPAD_LEFT_SHOULDER = 0x0000C8; // reserved
constexpr int VK_GAMEPAD_LEFT_TRIGGER = 0x0000C9; // reserved
constexpr int VK_GAMEPAD_RIGHT_TRIGGER = 0x0000CA; // reserved
constexpr int VK_GAMEPAD_DPAD_UP = 0x0000CB; // reserved
constexpr int VK_GAMEPAD_DPAD_DOWN = 0x0000CC; // reserved
constexpr int VK_GAMEPAD_DPAD_LEFT = 0x0000CD; // reserved
constexpr int VK_GAMEPAD_DPAD_RIGHT = 0x0000CE; // reserved
constexpr int VK_GAMEPAD_MENU = 0x0000CF; // reserved
constexpr int VK_GAMEPAD_VIEW = 0x0000D0; // reserved
constexpr int VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON = 0x0000D1; // reserved
constexpr int VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON = 0x0000D2; // reserved
constexpr int VK_GAMEPAD_LEFT_THUMBSTICK_UP = 0x0000D3; // reserved
constexpr int VK_GAMEPAD_LEFT_THUMBSTICK_DOWN = 0x0000D4; // reserved
constexpr int VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT = 0x0000D5; // reserved
constexpr int VK_GAMEPAD_LEFT_THUMBSTICK_LEFT = 0x0000D6; // reserved
constexpr int VK_GAMEPAD_RIGHT_THUMBSTICK_UP = 0x0000D7; // reserved
constexpr int VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN = 0x0000D8; // reserved
constexpr int VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT = 0x0000D9; // reserved
constexpr int VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT = 0x0000DA; // reserved

constexpr int VK_OEM_4 = 0x0000DB; //  '[{' for US
constexpr int VK_OEM_5 = 0x0000DC; //  '\|' for US
constexpr int VK_OEM_6 = 0x0000DD; //  ']}' for US
constexpr int VK_OEM_7 = 0x0000DE; //  ''"' for US
constexpr int VK_OEM_8 = 0x0000DF;

// 0x0000E0 : reserved

// Various extended or enhanced keyboards
constexpr int VK_OEM_AX = 0x0000E1; //  'AX' key on Japanese AX kbd
constexpr int VK_OEM_102 = 0x0000E2; //  "<>" or "\|" on RT 102-key kbd.
constexpr int VK_ICO_HELP = 0x0000E3; //  Help key on ICO
constexpr int VK_ICO_00 = 0x0000E4; //  00 key on ICO

constexpr int VK_PROCESSKEY = 0x0000E5;

constexpr int VK_ICO_CLEAR = 0x0000E6;

constexpr int VK_PACKET = 0x0000E7;

// 0x0000E8 : unassigned

// Nokia/Ericsson definitions
constexpr int VK_OEM_RESET = 0x0000E9;
constexpr int VK_OEM_JUMP = 0x0000EA;
constexpr int VK_OEM_PA1 = 0x0000EB;
constexpr int VK_OEM_PA2 = 0x0000EC;
constexpr int VK_OEM_PA3 = 0x0000ED;
constexpr int VK_OEM_WSCTRL = 0x0000EE;
constexpr int VK_OEM_CUSEL = 0x0000EF;
constexpr int VK_OEM_ATTN = 0x0000F0;
constexpr int VK_OEM_FINISH = 0x0000F1;
constexpr int VK_OEM_COPY = 0x0000F2;
constexpr int VK_OEM_AUTO = 0x0000F3;
constexpr int VK_OEM_ENLW = 0x0000F4;
constexpr int VK_OEM_BACKTAB = 0x0000F5;

constexpr int VK_ATTN = 0x0000F6;
constexpr int VK_CRSEL = 0x0000F7;
constexpr int VK_EXSEL = 0x0000F8;
constexpr int VK_EREOF = 0x0000F9;
constexpr int VK_PLAY = 0x0000FA;
constexpr int VK_ZOOM = 0x0000FB;
constexpr int VK_NONAME = 0x0000FC;
constexpr int VK_PA1 = 0x0000FD;
constexpr int VK_OEM_CLEAR = 0x0000FE;
// 0x0000FF : reserved

#endif
