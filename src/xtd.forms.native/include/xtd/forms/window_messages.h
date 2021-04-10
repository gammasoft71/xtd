/// @file
/// @brief Contains windows message constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include <cstdint>

#ifndef WM_NULL
/// @brief Performs no operation. An application sends the WM_NULL message if it wants to post a message that the recipient window will ignore.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_NULL = 0x0000;
/// @brief Sent when an application requests that a window be created by calling the CreateWindowEx or CreateWindow function. (The message is sent before the function returns.) The window procedure of the new window receives this message after the window is created, but before the window becomes visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_CREATE = 0x0001;
/// @brief Sent when a window is being destroyed. It is sent to the window procedure of the window being destroyed after the window is removed from the screen.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_DESTROY = 0x0002;
/// @brief Sent after a window has been moved.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_MOVE = 0x0003;
// not defined 0x0004
/// @brief Sent to a window after its size has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_SIZE = 0x0005;
/// @brief Sent to both the window being activated and the window being deactivated. If the windows use the same input queue, the message is sent synchronously, first to the window procedure of the top-level window being deactivated, then to the window procedure of the top-level window being activated. If the windows use different input queues, the message is sent asynchronously, so the window is activated immediately.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_ACTIVATE = 0x0006;
/// @brief Sent to a window after it has gained the keyboard focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_SETFOCUS = 0x0007;
/// @brief Sent to a window immediately before it loses the keyboard focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_KILLFOCUS = 0x0008;
// not defined 0x0009
/// @brief Sent when an application changes the enabled state of a window. It is sent to the window whose enabled state is changing. This message is sent before the EnableWindow function returns, but after the enabled state (WS_DISABLED style bit) of the window has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_ENABLE = 0x000A;
/// @brief An application sends the WM_SETREDRAW message to a window to allow changes in that window to be redrawn or to prevent changes in that window from being redrawn.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_SETREDRAW = 0x000B;
/// @brief Sets the text of a window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_SETTEXT = 0x000C;
/// @brief Copies the text that corresponds to a window into a buffer provided by the caller.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_GETTEXT = 0x000D;
/// @brief Determines the length, in characters, of the text associated with a window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_GETTEXTLENGTH = 0x000E;
/// @brief The WM_PAINT message is sent when the system or another application makes a request to paint a portion of an application's window. The message is sent when the UpdateWindow or RedrawWindow function is called, or by the DispatchMessage function when the application obtains a WM_PAINT message by using the GetMessage or PeekMessage function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_PAINT = 0x000F;
/// @brief Sent as a signal that a window or an application should terminate.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_CLOSE = 0x0010;
/// @brief The WM_QUERYENDSESSION message is sent when the user chooses to end the session or when an application calls one of the system shutdown functions. If any application returns zero, the session is not ended. The system stops sending WM_QUERYENDSESSION messages as soon as one application returns zero.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_QUERYENDSESSION = 0x0011;
/// @brief Indicates a request to terminate an application, and is generated when the application calls the PostQuitMessage function. This message causes the GetMessage function to return zero.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_QUIT = 0x0012;
/// @brief Sent to an icon when the user requests that the window be restored to its previous size and position.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_QUERYOPEN = 0x0013;
/// @brief Sent when the window background must be erased (for example, when a window is resized). The message is sent to prepare an invalidated portion of a window for painting.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_ERASEBKGND = 0x0014;
/// @brief The WM_SYSCOLORCHANGE message is sent to all top-level windows when a change is made to a system color setting.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_SYSCOLORCHANGE = 0x0015;
/// @brief The WM_ENDSESSION message is sent to an application after the system processes the results of the WM_QUERYENDSESSION message. The WM_ENDSESSION message informs the application whether the session is ending.The WM_ENDSESSION message is sent to an application after the system processes the results of the WM_QUERYENDSESSION message. The WM_ENDSESSION message informs the application whether the session is ending.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_ENDSESSION = 0x0016;
// not defined 0x0017
/// @brief Sent to a window when the window is about to be hidden or shown.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native message_ids
/// @remarks This value can be containded in the xtd::forms::message::msg property.
constexpr int32_t WM_SHOWWINDOW = 0x0018;
constexpr int32_t WM_CTLCOLOR = 0x0019;
constexpr int32_t WM_WININICHANGE = 0x001A;
constexpr int32_t WM_DEVMODECHANGE = 0x001B;
constexpr int32_t WM_ACTIVATEAPP = 0x001C;
constexpr int32_t WM_FONTCHANGE = 0x001D;
constexpr int32_t WM_TIMECHANGE = 0x001E;
constexpr int32_t WM_CANCELMODE = 0x001F;
constexpr int32_t WM_SETCURSOR = 0x0020;
constexpr int32_t WM_MOUSEACTIVATE = 0x0021;
constexpr int32_t WM_CHILDACTIVATE = 0x0022;
constexpr int32_t WM_QUEUESYNC = 0x0023;
constexpr int32_t WM_GETMINMAXINFO = 0x0024;
// not defined 0x0025
constexpr int32_t WM_PAINTICON = 0x0026;
constexpr int32_t WM_ICONERASEBKGND = 0x0027;
constexpr int32_t WM_NEXTDLGCTL = 0x0028;
// not defined 0x0029
constexpr int32_t WM_SPOOLERSTATUS = 0x002A;
constexpr int32_t WM_DRAWITEM = 0x002B;
constexpr int32_t WM_MEASUREITEM = 0x002C;
constexpr int32_t WM_DELETEITEM = 0x002D;
constexpr int32_t WM_VKEYTOITEM = 0x002E;
constexpr int32_t WM_CHARTOITEM = 0x002F;
constexpr int32_t WM_SETFONT = 0x0030;
constexpr int32_t WM_GETFONT = 0x0031;
constexpr int32_t WM_SETHOTKEY = 0x0032;
constexpr int32_t WM_GETHOTKEY = 0x0033;
// not defined 0x0034 - 0x0036
constexpr int32_t WM_QUERYDRAGICON = 0x0037;
constexpr int32_t WM_COMPAREITEM = 0x0039;
constexpr int32_t WM_GETOBJECT = 0x003D;
constexpr int32_t WM_COMPACTING = 0x0041;
constexpr int32_t WM_COMMNOTIFY = 0x0044;
constexpr int32_t WM_WINDOWPOSCHANGING = 0x0046;
constexpr int32_t WM_WINDOWPOSCHANGED = 0x0047;
constexpr int32_t WM_POWER = 0x0048;
constexpr int32_t WM_COPYDATA = 0x004A;
constexpr int32_t WM_CANCELJOURNAL = 0x004B;
// not defined 0x004C - 0x004D
constexpr int32_t WM_NOTIFY = 0x004E;
// not defined 0x004F
constexpr int32_t WM_INPUTLANGCHANGEREQUEST = 0x0050;
constexpr int32_t WM_INPUTLANGCHANGE = 0x0051;
constexpr int32_t WM_TCARD = 0x0052;
constexpr int32_t WM_HELP = 0x0053;
constexpr int32_t WM_USERCHANGED = 0x0054;
constexpr int32_t WM_NOTIFYFORMAT = 0x0055;
// not defined 0x0056 - 0x007A
constexpr int32_t WM_CONTEXTMENU = 0x007B;
constexpr int32_t WM_STYLECHANGING = 0x007C;
constexpr int32_t WM_STYLECHANGED = 0x007D;
constexpr int32_t WM_DISPLAYCHANGE = 0x007E;
constexpr int32_t WM_GETICON = 0x007F;
constexpr int32_t WM_SETICON = 0x0080;
constexpr int32_t WM_NCCREATE = 0x0081;
constexpr int32_t WM_NCDESTROY = 0x0082;
constexpr int32_t WM_NCCALCSIZE = 0x0083;
constexpr int32_t WM_NCHITTEST = 0x0084;
constexpr int32_t WM_NCPAINT = 0x0085;
constexpr int32_t WM_NCACTIVATE = 0x0086;
constexpr int32_t WM_GETDLGCODE = 0x0087;
constexpr int32_t WM_SYNCPAINT = 0x0088;
// not defined 0x0089 - 0x000F
constexpr int32_t WM_NCMOUSEMOVE = 0x00A0;
constexpr int32_t WM_NCLBUTTONDOWN = 0x00A1;
constexpr int32_t WM_NCLBUTTONUP = 0x00A2;
constexpr int32_t WM_NCLBUTTONDBLCLK = 0x00A3;
constexpr int32_t WM_NCRBUTTONDOWN = 0x00A4;
constexpr int32_t WM_NCRBUTTONUP = 0x00A5;
constexpr int32_t WM_NCRBUTTONDBLCLK = 0x00A6;
constexpr int32_t WM_NCMBUTTONDOWN = 0x00A7;
constexpr int32_t WM_NCMBUTTONUP = 0x00A8;
constexpr int32_t WM_NCMBUTTONDBLCLK = 0x00A9;
// not defined 0x00AA
constexpr int32_t WM_NCXBUTTONDOWN = 0x00AB;
constexpr int32_t WM_NCXBUTTONUP = 0x00AC;
constexpr int32_t WM_NCXBUTTONDBLCLK = 0x00AD;
constexpr int32_t WM_INPUT_DEVICE_CHANGE = 0x00FE;
constexpr int32_t WM_INPUT = 0x00FF;
constexpr int32_t WM_KEYDOWN = 0x0100;
constexpr int32_t WM_KEYUP = 0x0101;
constexpr int32_t WM_CHAR = 0x0102;
constexpr int32_t WM_DEADCHAR = 0x0103;
constexpr int32_t WM_SYSKEYDOWN = 0x0104;
constexpr int32_t WM_SYSKEYUP = 0x0105;
constexpr int32_t WM_SYSCHAR = 0x0106;
constexpr int32_t WM_SYSDEADCHAR = 0x0107;
//constexpr int32_t WM_KEYLAST = 0x0108;
//constexpr int32_t WM_UNICHAR = 0x0109;
constexpr int32_t WM_KEYLAST = 0x0109;
// not defined 0x010B - 0x010C
constexpr int32_t WM_IME_STARTCOMPOSITION = 0x010D;
constexpr int32_t WM_IME_ENDCOMPOSITION = 0x010E;
constexpr int32_t WM_INITDIALOG = 0x0110;
constexpr int32_t WM_COMMAND = 0x0111;
constexpr int32_t WM_SYSCOMMAND = 0x0112;
constexpr int32_t WM_TIMER = 0x0113;
constexpr int32_t WM_HSCROLL = 0x0114;
constexpr int32_t WM_VSCROLL = 0x0115;
constexpr int32_t WM_INITMENU = 0x0116;
constexpr int32_t WM_INITMENUPOPUP = 0x0117;
// not defined 0x0118
constexpr int32_t WM_GESTURE = 0x0119;
constexpr int32_t WM_GESTURENOTIFY = 0x011A;
// not defined 0x011B - 0x011E
constexpr int32_t WM_MENUSELECT = 0x011F;
constexpr int32_t WM_MENUCHAR = 0x0120;
constexpr int32_t WM_ENTERIDLE = 0x0121;
constexpr int32_t WM_MENURBUTTONUP = 0x0122;
constexpr int32_t WM_MENUDRAG = 0x0123;
constexpr int32_t WM_MENUGETOBJECT = 0x0124;
constexpr int32_t WM_UNINITMENUPOPUP = 0x0125;
constexpr int32_t WM_MENUCOMMAND = 0x0126;
constexpr int32_t WM_CHANGEUISTATE = 0x0127;
constexpr int32_t WM_UPDATEUISTATE = 0x0128;
constexpr int32_t WM_QUERYUISTATE = 0x0129;
// not defined 0x0130 - 0x0131
constexpr int32_t WM_CTLCOLORMSGBOX = 0x0132;
constexpr int32_t WM_CTLCOLOREDIT = 0x0133;
constexpr int32_t WM_CTLCOLORLISTBOX = 0x0134;
constexpr int32_t WM_CTLCOLORBTN = 0x0135;
constexpr int32_t WM_CTLCOLORDLG = 0x0136;
constexpr int32_t WM_CTLCOLORSCROLLBAR = 0x0137;
constexpr int32_t WM_CTLCOLORSTATIC = 0x0138;
// not defined 0x0139 - 01E0
constexpr int32_t MN_GETHMENU = 0x01E1;
// not defined 0x01E2 - 0x019F
constexpr int32_t WM_MOUSEMOVE = 0x0200;
constexpr int32_t WM_LBUTTONDOWN = 0x0201;
constexpr int32_t WM_LBUTTONUP = 0x0202;
constexpr int32_t WM_LBUTTONDBLCLK = 0x0203;
constexpr int32_t WM_RBUTTONDOWN = 0x0204;
constexpr int32_t WM_RBUTTONUP = 0x0205;
constexpr int32_t WM_RBUTTONDBLCLK = 0x0206;
constexpr int32_t WM_MBUTTONDOWN = 0x0207;
constexpr int32_t WM_MBUTTONUP = 0x0208;
constexpr int32_t WM_MBUTTONDBLCLK = 0x0209;
constexpr int32_t WM_MOUSEWHEEL = 0x020A;
constexpr int32_t WM_XBUTTONDOWN = 0x020B;
constexpr int32_t WM_XBUTTONUP = 0x020C;
constexpr int32_t WM_XBUTTONDBLCLK = 0x020D;
constexpr int32_t WM_MOUSEHWHEEL = 0x020E;
// not defined 0x020F
constexpr int32_t WM_PARENTNOTIFY = 0x0210;
constexpr int32_t WM_ENTERMENULOOP = 0x0211;
constexpr int32_t WM_EXITMENULOOP = 0x0212;
constexpr int32_t WM_NEXTMENU = 0x0213;
constexpr int32_t WM_SIZING = 0x0214;
constexpr int32_t WM_CAPTURECHANGED = 0x0215;
constexpr int32_t WM_MOVING = 0x0216;
// not defined 0x0217
constexpr int32_t WM_POWERBROADCAST = 0x0218;
constexpr int32_t WM_DEVICECHANGE = 0x0219;
constexpr int32_t WM_MDICREATE = 0x0220;
constexpr int32_t WM_MDIDESTROY = 0x0221;
constexpr int32_t WM_MDIACTIVATE = 0x0222;
constexpr int32_t WM_MDIRESTORE = 0x0223;
constexpr int32_t WM_MDINEXT = 0x0224;
constexpr int32_t WM_MDIMAXIMIZE = 0x0225;
constexpr int32_t WM_MDITILE = 0x0226;
constexpr int32_t WM_MDICASCADE = 0x0227;
constexpr int32_t WM_MDIICONARRANGE = 0x0228;
constexpr int32_t WM_MDIGETACTIVE = 0x0229;
constexpr int32_t WM_MDISETMENU = 0x0230;
constexpr int32_t WM_ENTERSIZEMOVE = 0x0231;
constexpr int32_t WM_EXITSIZEMOVE = 0x0232;
constexpr int32_t WM_DROPFILES = 0x0233;
constexpr int32_t WM_MDIREFRESHMENU = 0x0234;
// not defined 0x0235 - 0x0237
constexpr int32_t WM_POINTERDEVICECHANGE = 0x0238;
constexpr int32_t WM_POINTERDEVICEINRANGE = 0x0239;
constexpr int32_t WM_POINTERDEVICEOUTOFRANGE = 0x023A;
constexpr int32_t WM_TOUCH = 0x0240;
constexpr int32_t WM_NCPOINTERUPDATE = 0x0241;
constexpr int32_t WM_NCPOINTERDOWN = 0x0242;
constexpr int32_t WM_NCPOINTERUP = 0x0243;
constexpr int32_t WM_POINTERUPDATE = 0x0245;
constexpr int32_t WM_POINTERDOWN = 0x0246;
constexpr int32_t WM_POINTERUP = 0x0247;
constexpr int32_t WM_POINTERENTER = 0x0249;
constexpr int32_t WM_POINTERLEAVE = 0x024A;
constexpr int32_t WM_POINTERACTIVATE = 0x024B;
constexpr int32_t WM_POINTERCAPTURECHANGED = 0x024C;
constexpr int32_t WM_TOUCHHITTESTING = 0x024D;
constexpr int32_t WM_POINTERWHEEL = 0x024E;
constexpr int32_t WM_POINTERHWHEEL = 0x024F;
constexpr int32_t DM_POINTERHITTEST = 0x0250;
// not defined 0x0251 - 0x0280
constexpr int32_t WM_IME_SETCONTEXT = 0x0281;
constexpr int32_t WM_IME_NOTIFY = 0x0282;
constexpr int32_t WM_IME_CONTROL = 0x0283;
constexpr int32_t WM_IME_COMPOSITIONFULL = 0x0284;
constexpr int32_t WM_IME_SELECT = 0x0285;
constexpr int32_t WM_IME_CHAR = 0x0286;
// not defined 0x0287
constexpr int32_t WM_IME_REQUEST = 0x0288;
// not defined 0x0289
constexpr int32_t WM_IME_KEYDOWN = 0x0290;
constexpr int32_t WM_IME_KEYUP = 0x0291;
// not defined 0x0292 - 0x02A0
constexpr int32_t WM_MOUSEHOVER = 0x02A1;
constexpr int32_t WM_MOUSELEAVE = 0x2A3;
// not defined 0x02A4 - 0x02A9
constexpr int32_t WM_NCMOUSEHOVER = 0x02A0;
constexpr int32_t WM_NCMOUSELEAVE = 0x02A2;
// not defined 0x02A3 - 0x02B0
constexpr int32_t WM_WTSSESSION_CHANGE = 0x02B1;
// not defined 0x02B2 - 0x02BF
constexpr int32_t WM_TABLET_FIRST = 0x02C0;
// not defined 0x02C1 - 0x02DE
constexpr int32_t WM_TABLET_LAST = 0x02DF;
constexpr int32_t WM_DPICHANGED = 0x02E0;
// not defined 0x02E1 - 0x029F
constexpr int32_t WM_CUT = 0x0300;
constexpr int32_t WM_COPY = 0x0301;
constexpr int32_t WM_PASTE = 0x0302;
constexpr int32_t WM_CLEAR = 0x0303;
constexpr int32_t WM_UNDO = 0x0304;
constexpr int32_t WM_RENDERFORMAT = 0x0305;
constexpr int32_t WM_RENDERALLFORMATS = 0x0306;
constexpr int32_t WM_DESTROYCLIPBOARD = 0x0307;
constexpr int32_t WM_DRAWCLIPBOARD = 0x0308;
constexpr int32_t WM_PAINTCLIPBOARD = 0x0309;
constexpr int32_t WM_VSCROLLCLIPBOARD = 0x030A;
constexpr int32_t WM_SIZECLIPBOARD = 0x030B;
constexpr int32_t WM_ASKCBFORMATNAME = 0x030C;
constexpr int32_t WM_CHANGECBCHAIN = 0x030D;
constexpr int32_t WM_HSCROLLCLIPBOARD = 0x030E;
constexpr int32_t WM_QUERYNEWPALETTE = 0x030F;
constexpr int32_t WM_PALETTEISCHANGING = 0x0310;
constexpr int32_t WM_PALETTECHANGED = 0x0311;
constexpr int32_t WM_HOTKEY = 0x0312;
// not defined 0x0313 - 0x0316
constexpr int32_t WM_PRINT = 0x0317;
constexpr int32_t WM_PRINTCLIENT = 0x0318;
constexpr int32_t WM_APPCOMMAND = 0x0319;
constexpr int32_t WM_THEMECHANGED = 0x031A;
// not defined 0x031B - 0x031C
constexpr int32_t WM_CLIPBOARDUPDATE = 0x031D;
constexpr int32_t WM_DWMCOMPOSITIONCHANGED = 0x031E;
constexpr int32_t WM_DWMNCRENDERINGCHANGED = 0x031F;
constexpr int32_t WM_DWMCOLORIZATIONCOLORCHANGED = 0x0320;
constexpr int32_t WM_DWMWINDOWMAXIMIZEDCHANGE = 0x0321;
constexpr int32_t WM_DWMSENDICONICTHUMBNAIL = 0x0323;
constexpr int32_t WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326;
// not defined 0x0327 - 0x033E
constexpr int32_t WM_GETTITLEBARINFOEX = 0x033F;
// not defined 0x0340 - 0x0357
constexpr int32_t WM_HANDHELDFIRST = 0x0358;
// not defined 0x0359 - 0x035E
constexpr int32_t WM_HANDHELDLAST = 0x035F;
constexpr int32_t WM_AFXFIRST = 0x0360;
// not defined 0x0361 - 0x037E
constexpr int32_t WM_AFXLAST = 0x037F;
constexpr int32_t WM_PENWINFIRST = 0x0380;
// not defined 0x0381 - 0x038E
constexpr int32_t WM_PENWINLAST = 0x038F;
// not defined 0x0390 - 0x039F

// NOTE: All Message Numbers below 0x0400 are RESERVED.
// Private Window Messages Start Here:
constexpr int32_t WM_USER = 0x0400;
// Private Window Messages Stop Here : 0x7FFF;

// NOTE: Messages available for use by applications.
constexpr int32_t WM_APP = 0x8000;

constexpr size_t WA_INACTIVE = 0;
constexpr size_t WA_ACTIVE = 1;
constexpr size_t WA_CLICKACTIVE = 2;

constexpr size_t BN_CLICKED = 0;
constexpr size_t BN_PAINT = 1;
constexpr size_t BN_HILITE = 2;
constexpr size_t BN_UNHILITE = 3;
constexpr size_t BN_DISABLE = 4;
constexpr size_t BN_DOUBLECLICKED = 5;
constexpr size_t BN_PUSHED = BN_HILITE;
constexpr size_t BN_UNPUSHED = BN_UNHILITE;
constexpr size_t BN_DBLCLK = BN_DOUBLECLICKED;
constexpr size_t BN_SETFOCUS = 6;
constexpr size_t BN_KILLFOCUS = 7;


constexpr size_t EN_SETFOCUS = 0x0100;
constexpr size_t EN_KILLFOCUS = 0x0200;
constexpr size_t EN_CHANGE = 0x0300;
constexpr size_t EN_UPDATE = 0x0400;
constexpr size_t EN_ERRSPACE = 0x0500;
constexpr size_t EN_MAXTEXT = 0x0501;
constexpr size_t EN_HSCROLL = 0x0601;
constexpr size_t EN_VSCROLL = 0x0602;
constexpr size_t EN_ALIGN_LTR_EC = 0x0700;
constexpr size_t EN_ALIGN_RTL_EC = 0x0701;
constexpr size_t EN_BEFORE_PASTE = 0x0800;
constexpr size_t EN_AFTER_PASTE = 0x0801;

template<typename type1_t, typename type2_t>
uint16_t MAKEWORD(type1_t a, type2_t b) {
  return static_cast<uint16_t>((static_cast<uint16_t>((static_cast<uint32_t>(a)) & 0xff)) | (static_cast<uint16_t>(static_cast<uint16_t>((static_cast<uint32_t>(b)) & 0xff))) << 8);
}

template<typename type1_t, typename type2_t>
uint32_t MAKELONG(type1_t a, type2_t b) {
  return static_cast<uint32_t>((static_cast<uint16_t>((static_cast<uint32_t>(a)) & 0xffff)) | (static_cast<uint32_t>(static_cast<uint16_t>((static_cast<uint32_t>(b)) & 0xffff))) << 16);
}

template<typename type_t>
inline uint16_t LOWORD(type_t value) {
  return static_cast<uint16_t>(static_cast<uint32_t>(value) & 0xFFFF);
}

template<typename type_t>
inline uint16_t HIWORD(type_t value) {
  return static_cast<uint16_t>((static_cast<uint32_t>(value) >> 16) & 0xFFFF);
}

template<typename type_t>
inline uint16_t LOBYTE(type_t value) {
  return static_cast<uint8_t>(static_cast<uint32_t>(value) & 0xFF);
}

template<typename type_t>
inline uint8_t HIBYTE(type_t value) {
  return static_cast<uint8_t>((static_cast<uint32_t>(value) >> 8) & 0xFF);
}

#endif

constexpr int32_t WM_REFLECT = WM_USER + 0x1C00;

constexpr int32_t UDN_DELTAPOS = -722;

constexpr int32_t WM_MOUSEENTER = WM_USER + 0x0001;

intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam);
