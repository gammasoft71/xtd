#pragma once

#include <cstdint>

#ifndef WM_NULL
constexpr int WM_NULL = 0x0000;
constexpr int WM_CREATE = 0x0001;
constexpr int WM_DESTROY = 0x0002;
constexpr int WM_MOVE = 0x0003;
// not defined 0x0004
constexpr int WM_SIZE = 0x0005;
constexpr int WM_ACTIVATE = 0x0006;
constexpr int WM_SETFOCUS = 0x0007;
constexpr int WM_KILLFOCUS = 0x0008;
// not defined 0x0009
constexpr int WM_ENABLE = 0x000A;
constexpr int WM_SETREDRAW = 0x000B;
constexpr int WM_SETTEXT = 0x000C;
constexpr int WM_GETTEXT = 0x000D;
constexpr int WM_GETTEXTLENGTH = 0x000E;
constexpr int WM_PAINT = 0x000F;
constexpr int WM_CLOSE = 0x0010;
constexpr int WM_QUERYENDSESSION = 0x0011;
constexpr int WM_QUIT = 0x0012;
constexpr int WM_QUERYOPEN = 0x0013;
constexpr int WM_ERASEBKGND = 0x0014;
constexpr int WM_SYSCOLORCHANGE = 0x0015;
constexpr int WM_ENDSESSION = 0x0016;
// not defined 0x0017
constexpr int WM_SHOWWINDOW = 0x0018;
constexpr int WM_CTLCOLOR = 0x0019;
constexpr int WM_WININICHANGE = 0x001A;
constexpr int WM_DEVMODECHANGE = 0x001B;
constexpr int WM_ACTIVATEAPP = 0x001C;
constexpr int WM_FONTCHANGE = 0x001D;
constexpr int WM_TIMECHANGE = 0x001E;
constexpr int WM_CANCELMODE = 0x001F;
constexpr int WM_SETCURSOR = 0x0020;
constexpr int WM_MOUSEACTIVATE = 0x0021;
constexpr int WM_CHILDACTIVATE = 0x0022;
constexpr int WM_QUEUESYNC = 0x0023;
constexpr int WM_GETMINMAXINFO = 0x0024;
// not defined 0x0025
constexpr int WM_PAINTICON = 0x0026;
constexpr int WM_ICONERASEBKGND = 0x0027;
constexpr int WM_NEXTDLGCTL = 0x0028;
// not defined 0x0029
constexpr int WM_SPOOLERSTATUS = 0x002A;
constexpr int WM_DRAWITEM = 0x002B;
constexpr int WM_MEASUREITEM = 0x002C;
constexpr int WM_DELETEITEM = 0x002D;
constexpr int WM_VKEYTOITEM = 0x002E;
constexpr int WM_CHARTOITEM = 0x002F;
constexpr int WM_SETFONT = 0x0030;
constexpr int WM_GETFONT = 0x0031;
constexpr int WM_SETHOTKEY = 0x0032;
constexpr int WM_GETHOTKEY = 0x0033;
// not defined 0x0034 - 0x0036
constexpr int WM_QUERYDRAGICON = 0x0037;
constexpr int WM_COMPAREITEM = 0x0039;
constexpr int WM_GETOBJECT = 0x003D;
constexpr int WM_COMPACTING = 0x0041;
constexpr int WM_COMMNOTIFY = 0x0044;
constexpr int WM_WINDOWPOSCHANGING = 0x0046;
constexpr int WM_WINDOWPOSCHANGED = 0x0047;
constexpr int WM_POWER = 0x0048;
constexpr int WM_COPYDATA = 0x004A;
constexpr int WM_CANCELJOURNAL = 0x004B;
// not defined 0x004C - 0x004D
constexpr int WM_NOTIFY = 0x004E;
// not defined 0x004F
constexpr int WM_INPUTLANGCHANGEREQUEST = 0x0050;
constexpr int WM_INPUTLANGCHANGE = 0x0051;
constexpr int WM_TCARD = 0x0052;
constexpr int WM_HELP = 0x0053;
constexpr int WM_USERCHANGED = 0x0054;
constexpr int WM_NOTIFYFORMAT = 0x0055;
// not defined 0x0056 - 0x007A
constexpr int WM_CONTEXTMENU = 0x007B;
constexpr int WM_STYLECHANGING = 0x007C;
constexpr int WM_STYLECHANGED = 0x007D;
constexpr int WM_DISPLAYCHANGE = 0x007E;
constexpr int WM_GETICON = 0x007F;
constexpr int WM_SETICON = 0x0080;
constexpr int WM_NCCREATE = 0x0081;
constexpr int WM_NCDESTROY = 0x0082;
constexpr int WM_NCCALCSIZE = 0x0083;
constexpr int WM_NCHITTEST = 0x0084;
constexpr int WM_NCPAINT = 0x0085;
constexpr int WM_NCACTIVATE = 0x0086;
constexpr int WM_GETDLGCODE = 0x0087;
constexpr int WM_SYNCPAINT = 0x0088;
// not defined 0x0089 - 0x000F
constexpr int WM_NCMOUSEMOVE = 0x00A0;
constexpr int WM_NCLBUTTONDOWN = 0x00A1;
constexpr int WM_NCLBUTTONUP = 0x00A2;
constexpr int WM_NCLBUTTONDBLCLK = 0x00A3;
constexpr int WM_NCRBUTTONDOWN = 0x00A4;
constexpr int WM_NCRBUTTONUP = 0x00A5;
constexpr int WM_NCRBUTTONDBLCLK = 0x00A6;
constexpr int WM_NCMBUTTONDOWN = 0x00A7;
constexpr int WM_NCMBUTTONUP = 0x00A8;
constexpr int WM_NCMBUTTONDBLCLK = 0x00A9;
// not defined 0x00AA
constexpr int WM_NCXBUTTONDOWN = 0x00AB;
constexpr int WM_NCXBUTTONUP = 0x00AC;
constexpr int WM_NCXBUTTONDBLCLK = 0x00AD;
constexpr int WM_INPUT_DEVICE_CHANGE = 0x00FE;
constexpr int WM_INPUT = 0x00FF;
constexpr int WM_KEYDOWN = 0x0100;
constexpr int WM_KEYUP = 0x0101;
constexpr int WM_CHAR = 0x0102;
constexpr int WM_DEADCHAR = 0x0103;
constexpr int WM_SYSKEYDOWN = 0x0104;
constexpr int WM_SYSKEYUP = 0x0105;
constexpr int WM_SYSCHAR = 0x0106;
constexpr int WM_SYSDEADCHAR = 0x0107;
//constexpr int WM_KEYLAST = 0x0108;
//constexpr int WM_UNICHAR = 0x0109;
constexpr int WM_KEYLAST = 0x0109;
// not defined 0x010B - 0x010C
constexpr int WM_IME_STARTCOMPOSITION = 0x010D;
constexpr int WM_IME_ENDCOMPOSITION = 0x010E;
constexpr int WM_INITDIALOG = 0x0110;
constexpr int WM_COMMAND = 0x0111;
constexpr int WM_SYSCOMMAND = 0x0112;
constexpr int WM_TIMER = 0x0113;
constexpr int WM_HSCROLL = 0x0114;
constexpr int WM_VSCROLL = 0x0115;
constexpr int WM_INITMENU = 0x0116;
constexpr int WM_INITMENUPOPUP = 0x0117;
// not defined 0x0118
constexpr int WM_GESTURE = 0x0119;
constexpr int WM_GESTURENOTIFY = 0x011A;
// not defined 0x011B - 0x011E
constexpr int WM_MENUSELECT = 0x011F;
constexpr int WM_MENUCHAR = 0x0120;
constexpr int WM_ENTERIDLE = 0x0121;
constexpr int WM_MENURBUTTONUP = 0x0122;
constexpr int WM_MENUDRAG = 0x0123;
constexpr int WM_MENUGETOBJECT = 0x0124;
constexpr int WM_UNINITMENUPOPUP = 0x0125;
constexpr int WM_MENUCOMMAND = 0x0126;
constexpr int WM_CHANGEUISTATE = 0x0127;
constexpr int WM_UPDATEUISTATE = 0x0128;
constexpr int WM_QUERYUISTATE = 0x0129;
// not defined 0x0130 - 0x0131
constexpr int WM_CTLCOLORMSGBOX = 0x0132;
constexpr int WM_CTLCOLOREDIT = 0x0133;
constexpr int WM_CTLCOLORLISTBOX = 0x0134;
constexpr int WM_CTLCOLORBTN = 0x0135;
constexpr int WM_CTLCOLORDLG = 0x0136;
constexpr int WM_CTLCOLORSCROLLBAR = 0x0137;
constexpr int WM_CTLCOLORSTATIC = 0x0138;
// not defined 0x0139 - 01E0
constexpr int MN_GETHMENU = 0x01E1;
// not defined 0x01E2 - 0x019F
constexpr int WM_MOUSEMOVE = 0x0200;
constexpr int WM_LBUTTONDOWN = 0x0201;
constexpr int WM_LBUTTONUP = 0x0202;
constexpr int WM_LBUTTONDBLCLK = 0x0203;
constexpr int WM_RBUTTONDOWN = 0x0204;
constexpr int WM_RBUTTONUP = 0x0205;
constexpr int WM_RBUTTONDBLCLK = 0x0206;
constexpr int WM_MBUTTONDOWN = 0x0207;
constexpr int WM_MBUTTONUP = 0x0208;
constexpr int WM_MBUTTONDBLCLK = 0x0209;
constexpr int WM_MOUSEWHEEL = 0x020A;
constexpr int WM_XBUTTONDOWN = 0x020B;
constexpr int WM_XBUTTONUP = 0x020C;
constexpr int WM_XBUTTONDBLCLK = 0x020D;
constexpr int WM_MOUSEHWHEEL = 0x020E;
// not defined 0x020F
constexpr int WM_PARENTNOTIFY = 0x0210;
constexpr int WM_ENTERMENULOOP = 0x0211;
constexpr int WM_EXITMENULOOP = 0x0212;
constexpr int WM_NEXTMENU = 0x0213;
constexpr int WM_SIZING = 0x0214;
constexpr int WM_CAPTURECHANGED = 0x0215;
constexpr int WM_MOVING = 0x0216;
// not defined 0x0217
constexpr int WM_POWERBROADCAST = 0x0218;
constexpr int WM_DEVICECHANGE = 0x0219;
constexpr int WM_MDICREATE = 0x0220;
constexpr int WM_MDIDESTROY = 0x0221;
constexpr int WM_MDIACTIVATE = 0x0222;
constexpr int WM_MDIRESTORE = 0x0223;
constexpr int WM_MDINEXT = 0x0224;
constexpr int WM_MDIMAXIMIZE = 0x0225;
constexpr int WM_MDITILE = 0x0226;
constexpr int WM_MDICASCADE = 0x0227;
constexpr int WM_MDIICONARRANGE = 0x0228;
constexpr int WM_MDIGETACTIVE = 0x0229;
constexpr int WM_MDISETMENU = 0x0230;
constexpr int WM_ENTERSIZEMOVE = 0x0231;
constexpr int WM_EXITSIZEMOVE = 0x0232;
constexpr int WM_DROPFILES = 0x0233;
constexpr int WM_MDIREFRESHMENU = 0x0234;
// not defined 0x0235 - 0x0237
constexpr int WM_POINTERDEVICECHANGE = 0x0238;
constexpr int WM_POINTERDEVICEINRANGE = 0x0239;
constexpr int WM_POINTERDEVICEOUTOFRANGE = 0x023A;
constexpr int WM_TOUCH = 0x0240;
constexpr int WM_NCPOINTERUPDATE = 0x0241;
constexpr int WM_NCPOINTERDOWN = 0x0242;
constexpr int WM_NCPOINTERUP = 0x0243;
constexpr int WM_POINTERUPDATE = 0x0245;
constexpr int WM_POINTERDOWN = 0x0246;
constexpr int WM_POINTERUP = 0x0247;
constexpr int WM_POINTERENTER = 0x0249;
constexpr int WM_POINTERLEAVE = 0x024A;
constexpr int WM_POINTERACTIVATE = 0x024B;
constexpr int WM_POINTERCAPTURECHANGED = 0x024C;
constexpr int WM_TOUCHHITTESTING = 0x024D;
constexpr int WM_POINTERWHEEL = 0x024E;
constexpr int WM_POINTERHWHEEL = 0x024F;
constexpr int DM_POINTERHITTEST = 0x0250;
// not defined 0x0251 - 0x0280
constexpr int WM_IME_SETCONTEXT = 0x0281;
constexpr int WM_IME_NOTIFY = 0x0282;
constexpr int WM_IME_CONTROL = 0x0283;
constexpr int WM_IME_COMPOSITIONFULL = 0x0284;
constexpr int WM_IME_SELECT = 0x0285;
constexpr int WM_IME_CHAR = 0x0286;
// not defined 0x0287
constexpr int WM_IME_REQUEST = 0x0288;
// not defined 0x0289
constexpr int WM_IME_KEYDOWN = 0x0290;
constexpr int WM_IME_KEYUP = 0x0291;
// not defined 0x0292 - 0x02A0
constexpr int WM_MOUSEHOVER = 0x02A1;
constexpr int WM_MOUSELEAVE = 0x2A3;
// not defined 0x02A4 - 0x02A9
constexpr int WM_NCMOUSEHOVER = 0x02A0;
constexpr int WM_NCMOUSELEAVE = 0x02A2;
// not defined 0x02A3 - 0x02B0
constexpr int WM_WTSSESSION_CHANGE = 0x02B1;
// not defined 0x02B2 - 0x02BF
constexpr int WM_TABLET_FIRST = 0x02C0;
// not defined 0x02C1 - 0x02DE
constexpr int WM_TABLET_LAST = 0x02DF;
constexpr int WM_DPICHANGED = 0x02E0;
// not defined 0x02E1 - 0x029F
constexpr int WM_CUT = 0x0300;
constexpr int WM_COPY = 0x0301;
constexpr int WM_PASTE = 0x0302;
constexpr int WM_CLEAR = 0x0303;
constexpr int WM_UNDO = 0x0304;
constexpr int WM_RENDERFORMAT = 0x0305;
constexpr int WM_RENDERALLFORMATS = 0x0306;
constexpr int WM_DESTROYCLIPBOARD = 0x0307;
constexpr int WM_DRAWCLIPBOARD = 0x0308;
constexpr int WM_PAINTCLIPBOARD = 0x0309;
constexpr int WM_VSCROLLCLIPBOARD = 0x030A;
constexpr int WM_SIZECLIPBOARD = 0x030B;
constexpr int WM_ASKCBFORMATNAME = 0x030C;
constexpr int WM_CHANGECBCHAIN = 0x030D;
constexpr int WM_HSCROLLCLIPBOARD = 0x030E;
constexpr int WM_QUERYNEWPALETTE = 0x030F;
constexpr int WM_PALETTEISCHANGING = 0x0310;
constexpr int WM_PALETTECHANGED = 0x0311;
constexpr int WM_HOTKEY = 0x0312;
// not defined 0x0313 - 0x0316
constexpr int WM_PRINT = 0x0317;
constexpr int WM_PRINTCLIENT = 0x0318;
constexpr int WM_APPCOMMAND = 0x0319;
constexpr int WM_THEMECHANGED = 0x031A;
// not defined 0x031B - 0x031C
constexpr int WM_CLIPBOARDUPDATE = 0x031D;
constexpr int WM_DWMCOMPOSITIONCHANGED = 0x031E;
constexpr int WM_DWMNCRENDERINGCHANGED = 0x031F;
constexpr int WM_DWMCOLORIZATIONCOLORCHANGED = 0x0320;
constexpr int WM_DWMWINDOWMAXIMIZEDCHANGE = 0x0321;
constexpr int WM_DWMSENDICONICTHUMBNAIL = 0x0323;
constexpr int WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326;
// not defined 0x0327 - 0x033E
constexpr int WM_GETTITLEBARINFOEX = 0x033F;
// not defined 0x0340 - 0x0357
constexpr int WM_HANDHELDFIRST = 0x0358;
// not defined 0x0359 - 0x035E
constexpr int WM_HANDHELDLAST = 0x035F;
constexpr int WM_AFXFIRST = 0x0360;
// not defined 0x0361 - 0x037E
constexpr int WM_AFXLAST = 0x037F;
constexpr int WM_PENWINFIRST = 0x0380;
// not defined 0x0381 - 0x038E
constexpr int WM_PENWINLAST = 0x038F;
// not defined 0x0390 - 0x039F

// NOTE: All Message Numbers below 0x0400 are RESERVED.
// Private Window Messages Start Here:
constexpr int WM_USER = 0x0400;
// Private Window Messages Stop Here : 0x7FFF;

constexpr int WM_REFLECT = WM_USER + 0x1C00;

// NOTE: Messages available for use by applications.
constexpr int WM_APP = 0x8000;


constexpr int BN_CLICKED = 0;
constexpr int BN_PAINT = 1;
constexpr int BN_HILITE = 2;
constexpr int BN_UNHILITE = 3;
constexpr int BN_DISABLE = 4;
constexpr int BN_DOUBLECLICKED = 5;
constexpr int BN_PUSHED = BN_HILITE;
constexpr int BN_UNPUSHED = BN_UNHILITE;
constexpr int BN_DBLCLK = BN_DOUBLECLICKED;
constexpr int BN_SETFOCUS = 6;
constexpr int BN_KILLFOCUS = 7;


constexpr int EN_SETFOCUS = 0x0100;
constexpr int EN_KILLFOCUS = 0x0200;
constexpr int EN_CHANGE = 0x0300;
constexpr int EN_UPDATE = 0x0400;
constexpr int EN_ERRSPACE = 0x0500;
constexpr int EN_MAXTEXT = 0x0501;
constexpr int EN_HSCROLL = 0x0601;
constexpr int EN_VSCROLL = 0x0602;
constexpr int EN_ALIGN_LTR_EC = 0x0700;
constexpr int EN_ALIGN_RTL_EC = 0x0701;
constexpr int EN_BEFORE_PASTE = 0x0800;
constexpr int EN_AFTER_PASTE = 0x0801;


inline short HIBYTE(short word) {
  return (unsigned char)((word >> 8) & 0xFF);
}

inline unsigned short HIBYTE(unsigned short word) {
  return (unsigned char)((word >> 8) & 0xFF);
}

inline int HIWORD(intptr_t dWord) {
  return short((dWord >> 16) & 0xFFFF);
}

inline short LOBYTE(short word) {
  return (unsigned char)(word & 0xFF);
}

inline unsigned short LOBYTE(unsigned short word) {
  return (unsigned char)(word & 0xFF);
}

inline int LOWORD(intptr_t dWord) {
  return short(dWord & 0xFFFF);
}

#endif

constexpr int WM_MOUSEENTER = WM_USER + 0x0001;

intptr_t send_message(intptr_t hwnd, int msg, intptr_t wParam, intptr_t lParam);
