#pragma once
#include <cstddef>

constexpr size_t VK_NONE = 0x000000;
constexpr size_t VK_LINE_FEED = 0x00000A;
constexpr size_t VK_PAGEUP = 0x000021;
constexpr size_t VK_PAGEDOWN = 0x000022;

constexpr size_t VK_0 = 0x000030;
constexpr size_t VK_1 = 0x000031;
constexpr size_t VK_2 = 0x000032;
constexpr size_t VK_3 = 0x000033;
constexpr size_t VK_4 = 0x000034;
constexpr size_t VK_5 = 0x000035;
constexpr size_t VK_6 = 0x000036;
constexpr size_t VK_7 = 0x000037;
constexpr size_t VK_8 = 0x000038;
constexpr size_t VK_9 = 0x000039;

constexpr size_t VK_A = 0x000041;
constexpr size_t VK_B = 0x000042;
constexpr size_t VK_C = 0x000043;
constexpr size_t VK_D = 0x000044;
constexpr size_t VK_E = 0x000045;
constexpr size_t VK_F = 0x000046;
constexpr size_t VK_G = 0x000047;
constexpr size_t VK_H = 0x000048;
constexpr size_t VK_I = 0x000049;
constexpr size_t VK_J = 0x00004A;
constexpr size_t VK_K = 0x00004B;
constexpr size_t VK_L = 0x00004C;
constexpr size_t VK_M = 0x00004D;
constexpr size_t VK_N = 0x00004E;
constexpr size_t VK_O = 0x00004F;
constexpr size_t VK_P = 0x000050;
constexpr size_t VK_Q = 0x000051;
constexpr size_t VK_R = 0x000052;
constexpr size_t VK_S = 0x000053;
constexpr size_t VK_T = 0x000054;
constexpr size_t VK_U = 0x000055;
constexpr size_t VK_V = 0x000056;
constexpr size_t VK_W = 0x000057;
constexpr size_t VK_X = 0x000058;
constexpr size_t VK_Y = 0x000059;
constexpr size_t VK_Z = 0x00005A;

constexpr size_t VK_COMMAND = 0x00000100;
constexpr size_t VK_LCOMMAND = 0x00000101;
constexpr size_t VK_RCOMMAND = 0x00000102;

constexpr size_t VK_SHIFT_MODIFIER = 0x00010000;
constexpr size_t VK_CONTROL_MODIFIER = 0x00020000;
constexpr size_t VK_ALT_MODIFIER = 0x00040000;
constexpr size_t VK_COMMAND_MODIFIER = 0x00080000;
constexpr size_t VK_META_MODIFIER = 0x00100000;

#ifndef VK_LBUTTON
constexpr size_t VK_LBUTTON = 0x000001;
constexpr size_t VK_RBUTTON = 0x000002;
constexpr size_t VK_CANCEL = 0x000003;
constexpr size_t VK_MBUTTON = 0x000004;
constexpr size_t VK_XBUTTON1 = 0x000005;
constexpr size_t VK_XBUTTON2 = 0x000006;
// 0x000007 : reserved
constexpr size_t VK_BACK = 0x000008;
constexpr size_t VK_TAB = 0x000009;
// 0x00000A - 0x00000B : reserved
constexpr size_t VK_CLEAR = 0x00000C;
constexpr size_t VK_RETURN = 0x00000D;
// 0x00000E - 0x00000F : unassigned
constexpr size_t VK_SHIFT = 0x000010;
constexpr size_t VK_CONTROL = 0x000011;
constexpr size_t VK_MENU = 0x000012;
constexpr size_t VK_PAUSE = 0x000013;
constexpr size_t VK_CAPITAL = 0x000014;

constexpr size_t VK_KANA = 0x000015;
constexpr size_t VK_HANGEUL = 0x000015;
constexpr size_t VK_HANGUL = 0x000015;

// 0x000016 : unassigned
constexpr size_t VK_JUNJA = 0x000017;
constexpr size_t VK_FINAL = 0x000018;
constexpr size_t VK_HANJA = 0x000019;
constexpr size_t VK_KANJI = 0x000019;

// 0x00001A : unassigned

constexpr size_t VK_ESCAPE = 0x00001B;

constexpr size_t VK_CONVERT = 0x00001C;
constexpr size_t VK_NONCONVERT = 0x00001D;
constexpr size_t VK_ACCEPT = 0x00001E;
constexpr size_t VK_MODECHANGE = 0x00001F;

constexpr size_t VK_SPACE = 0x000020;
constexpr size_t VK_PRIOR = 0x000021;
constexpr size_t VK_NEXT = 0x000022;
constexpr size_t VK_END = 0x000023;
constexpr size_t VK_HOME = 0x000024;
constexpr size_t VK_LEFT = 0x000025;
constexpr size_t VK_UP = 0x000026;
constexpr size_t VK_RIGHT = 0x000027;
constexpr size_t VK_DOWN = 0x000028;
constexpr size_t VK_SELECT = 0x000029;
constexpr size_t VK_PRINT = 0x00002A;
constexpr size_t VK_EXECUTE = 0x00002B;
constexpr size_t VK_SNAPSHOT = 0x00002C;
constexpr size_t VK_INSERT = 0x00002D;
constexpr size_t VK_DELETE = 0x00002E;
constexpr size_t VK_HELP = 0x00002F;

// VK_0 - VK_9 are the same as ASCII '0' - '9' (0x000030 - 0x000039)
// 0x00003A - 0x000040 : unassigned
// VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x000041 - 0x00005A)

constexpr size_t VK_LWIN = 0x00005B;
constexpr size_t VK_RWIN = 0x00005C;
constexpr size_t VK_APPS = 0x00005D;

// 0x00005E : reserved

constexpr size_t VK_SLEEP = 0x00005F;

constexpr size_t VK_NUMPAD0 = 0x000060;
constexpr size_t VK_NUMPAD1 = 0x000061;
constexpr size_t VK_NUMPAD2 = 0x000062;
constexpr size_t VK_NUMPAD3 = 0x000063;
constexpr size_t VK_NUMPAD4 = 0x000064;
constexpr size_t VK_NUMPAD5 = 0x000065;
constexpr size_t VK_NUMPAD6 = 0x000066;
constexpr size_t VK_NUMPAD7 = 0x000067;
constexpr size_t VK_NUMPAD8 = 0x000068;
constexpr size_t VK_NUMPAD9 = 0x000069;
constexpr size_t VK_MULTIPLY = 0x00006A;
constexpr size_t VK_ADD = 0x00006B;
constexpr size_t VK_SEPARATOR = 0x00006C;
constexpr size_t VK_SUBTRACT = 0x00006D;
constexpr size_t VK_DECIMAL = 0x00006E;
constexpr size_t VK_DIVIDE =  0x00006F;
constexpr size_t VK_F1 = 0x000070;
constexpr size_t VK_F2 = 0x000071;
constexpr size_t VK_F3 = 0x000072;
constexpr size_t VK_F4 = 0x000073;
constexpr size_t VK_F5 = 0x000074;
constexpr size_t VK_F6 = 0x000075;
constexpr size_t VK_F7 = 0x000076;
constexpr size_t VK_F8 = 0x000077;
constexpr size_t VK_F9 = 0x000078;
constexpr size_t VK_F10 = 0x000079;
constexpr size_t VK_F11 = 0x00007A;
constexpr size_t VK_F12 = 0x00007B;
constexpr size_t VK_F13 = 0x00007C;
constexpr size_t VK_F14 = 0x00007D;
constexpr size_t VK_F15 = 0x00007E;
constexpr size_t VK_F16 = 0x00007F;
constexpr size_t VK_F17 = 0x000080;
constexpr size_t VK_F18 = 0x000081;
constexpr size_t VK_F19 = 0x000082;
constexpr size_t VK_F20 = 0x000083;
constexpr size_t VK_F21 = 0x000084;
constexpr size_t VK_F22 = 0x000085;
constexpr size_t VK_F23 = 0x000086;
constexpr size_t VK_F24 = 0x000087;

// 0x000088 - 0x00008F : UI navigation

constexpr size_t VK_NAVIGATION_VIEW = 0x000088; // reserved
constexpr size_t VK_NAVIGATION_MENU = 0x000089; // reserved
constexpr size_t VK_NAVIGATION_UP = 0x00008A; // reserved
constexpr size_t VK_NAVIGATION_DOWN = 0x00008B; // reserved
constexpr size_t VK_NAVIGATION_LEFT = 0x00008C; // reserved
constexpr size_t VK_NAVIGATION_RIGHT = 0x00008D; // reserved
constexpr size_t VK_NAVIGATION_ACCEPT = 0x00008E; // reserved
constexpr size_t VK_NAVIGATION_CANCEL = 0x00008F; // reserved

constexpr size_t VK_NUMLOCK = 0x000090;
constexpr size_t VK_SCROLL = 0x000091;

// NEC PC-9800 kbd definitions
constexpr size_t VK_OEM_NEC_EQUAL = 0x000092; // '=' key on numpad

// Fujitsu/OASYS kbd definitions
constexpr size_t VK_OEM_FJ_JISHO = 0x000092; // 'Dictionary' key
constexpr size_t VK_OEM_FJ_MASSHOU = 0x000093; // 'Unregister word' key
constexpr size_t VK_OEM_FJ_TOUROKU = 0x000094; // 'Register word' key
constexpr size_t VK_OEM_FJ_LOYA = 0x000095; // 'Left OYAYUBI' key
constexpr size_t VK_OEM_FJ_ROYA = 0x000096; // 'Right OYAYUBI' key

// 0x000097 - 0x00009F : unassigned

// VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
// Used only as parameters to GetAsyncKeyState() and GetKeyState().
// No other API or message will distinguish left and right keys in this way.
constexpr size_t VK_LSHIFT = 0x0000A0;
constexpr size_t VK_RSHIFT = 0x0000A1;
constexpr size_t VK_LCONTROL = 0x0000A2;
constexpr size_t VK_RCONTROL = 0x0000A3;
constexpr size_t VK_LMENU = 0x0000A4;
constexpr size_t VK_RMENU = 0x0000A5;

constexpr size_t VK_BROWSER_BACK = 0x0000A6;
constexpr size_t VK_BROWSER_FORWARD = 0x0000A7;
constexpr size_t VK_BROWSER_REFRESH = 0x0000A8;
constexpr size_t VK_BROWSER_STOP = 0x0000A9;
constexpr size_t VK_BROWSER_SEARCH = 0x0000AA;
constexpr size_t VK_BROWSER_FAVORITES = 0x0000AB;
constexpr size_t VK_BROWSER_HOME = 0x0000AC;

constexpr size_t VK_VOLUME_MUTE = 0x0000AD;
constexpr size_t VK_VOLUME_DOWN = 0x0000AE;
constexpr size_t VK_VOLUME_UP = 0x0000AF;
constexpr size_t VK_MEDIA_NEXT_TRACK = 0x0000B0;
constexpr size_t VK_MEDIA_PREV_TRACK = 0x0000B1;
constexpr size_t VK_MEDIA_STOP = 0x0000B2;
constexpr size_t VK_MEDIA_PLAY_PAUSE = 0x0000B3;
constexpr size_t VK_LAUNCH_MAIL = 0x0000B4;
constexpr size_t VK_LAUNCH_MEDIA_SELECT = 0x0000B5;
constexpr size_t VK_LAUNCH_APP1 = 0x0000B6;
constexpr size_t VK_LAUNCH_APP2 = 0x0000B7;

// 0x0000B8 - 0x0000B9 : reserved

constexpr size_t VK_OEM_1 = 0x0000BA; // ';:' for US
constexpr size_t VK_OEM_PLUS = 0x0000BB; // '+' any country
constexpr size_t VK_OEM_COMMA = 0x0000BC; // ',' any country
constexpr size_t VK_OEM_MINUS = 0x0000BD; // '-' any country
constexpr size_t VK_OEM_PERIOD = 0x0000BE; // '.' any country
constexpr size_t VK_OEM_2 = 0x0000BF; // '/?' for US
constexpr size_t VK_OEM_3 = 0x0000C0; // '`~' for US

// 0x0000C1 - 0x0000C2 : reserved

// 0x0000C3 - 0x0000DA : Gamepad input

constexpr size_t VK_GAMEPAD_A = 0x0000C3; // reserved
constexpr size_t VK_GAMEPAD_B = 0x0000C4; // reserved
constexpr size_t VK_GAMEPAD_X = 0x0000C5; // reserved
constexpr size_t VK_GAMEPAD_Y = 0x0000C6; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_SHOULDER = 0x0000C7; // reserved
constexpr size_t VK_GAMEPAD_LEFT_SHOULDER = 0x0000C8; // reserved
constexpr size_t VK_GAMEPAD_LEFT_TRIGGER = 0x0000C9; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_TRIGGER = 0x0000CA; // reserved
constexpr size_t VK_GAMEPAD_DPAD_UP = 0x0000CB; // reserved
constexpr size_t VK_GAMEPAD_DPAD_DOWN = 0x0000CC; // reserved
constexpr size_t VK_GAMEPAD_DPAD_LEFT = 0x0000CD; // reserved
constexpr size_t VK_GAMEPAD_DPAD_RIGHT = 0x0000CE; // reserved
constexpr size_t VK_GAMEPAD_MENU = 0x0000CF; // reserved
constexpr size_t VK_GAMEPAD_VIEW = 0x0000D0; // reserved
constexpr size_t VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON = 0x0000D1; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON = 0x0000D2; // reserved
constexpr size_t VK_GAMEPAD_LEFT_THUMBSTICK_UP = 0x0000D3; // reserved
constexpr size_t VK_GAMEPAD_LEFT_THUMBSTICK_DOWN = 0x0000D4; // reserved
constexpr size_t VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT = 0x0000D5; // reserved
constexpr size_t VK_GAMEPAD_LEFT_THUMBSTICK_LEFT = 0x0000D6; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_THUMBSTICK_UP = 0x0000D7; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN = 0x0000D8; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT = 0x0000D9; // reserved
constexpr size_t VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT = 0x0000DA; // reserved

constexpr size_t VK_OEM_4 = 0x0000DB; //  '[{' for US
constexpr size_t VK_OEM_5 = 0x0000DC; //  '\|' for US
constexpr size_t VK_OEM_6 = 0x0000DD; //  ']}' for US
constexpr size_t VK_OEM_7 = 0x0000DE; //  ''"' for US
constexpr size_t VK_OEM_8 = 0x0000DF;

// 0x0000E0 : reserved

// Various extended or enhanced keyboards
constexpr size_t VK_OEM_AX = 0x0000E1; //  'AX' key on Japanese AX kbd
constexpr size_t VK_OEM_102 = 0x0000E2; //  "<>" or "\|" on RT 102-key kbd.
constexpr size_t VK_ICO_HELP = 0x0000E3; //  Help key on ICO
constexpr size_t VK_ICO_00 = 0x0000E4; //  00 key on ICO

constexpr size_t VK_PROCESSKEY = 0x0000E5;

constexpr size_t VK_ICO_CLEAR = 0x0000E6;

constexpr size_t VK_PACKET = 0x0000E7;

// 0x0000E8 : unassigned

// Nokia/Ericsson definitions
constexpr size_t VK_OEM_RESET = 0x0000E9;
constexpr size_t VK_OEM_JUMP = 0x0000EA;
constexpr size_t VK_OEM_PA1 = 0x0000EB;
constexpr size_t VK_OEM_PA2 = 0x0000EC;
constexpr size_t VK_OEM_PA3 = 0x0000ED;
constexpr size_t VK_OEM_WSCTRL = 0x0000EE;
constexpr size_t VK_OEM_CUSEL = 0x0000EF;
constexpr size_t VK_OEM_ATTN = 0x0000F0;
constexpr size_t VK_OEM_FINISH = 0x0000F1;
constexpr size_t VK_OEM_COPY = 0x0000F2;
constexpr size_t VK_OEM_AUTO = 0x0000F3;
constexpr size_t VK_OEM_ENLW = 0x0000F4;
constexpr size_t VK_OEM_BACKTAB = 0x0000F5;

constexpr size_t VK_ATTN = 0x0000F6;
constexpr size_t VK_CRSEL = 0x0000F7;
constexpr size_t VK_EXSEL = 0x0000F8;
constexpr size_t VK_EREOF = 0x0000F9;
constexpr size_t VK_PLAY = 0x0000FA;
constexpr size_t VK_ZOOM = 0x0000FB;
constexpr size_t VK_NONAME = 0x0000FC;
constexpr size_t VK_PA1 = 0x0000FD;
constexpr size_t VK_OEM_CLEAR = 0x0000FE;
// 0x0000FF : reserved

#endif
