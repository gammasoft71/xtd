/// @file
/// @brief Contains windows messages constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include <cstdint>

#ifndef WM_NULL
/// @brief Performs no operation. An application sends the WM_NULL message if it wants to post a message that the recipient window will ignore.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NULL = 0x0000;
/// @brief Sent when an application requests that a window be created by calling the CreateWindowEx or CreateWindow function. (The message is sent before the function returns.) The window procedure of the new window receives this message after the window is created, but before the window becomes visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CREATE = 0x0001;
/// @brief Sent when a window is being destroyed. It is sent to the window procedure of the window being destroyed after the window is removed from the screen.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DESTROY = 0x0002;
/// @brief Sent after a window has been moved.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOVE = 0x0003;
// not defined 0x0004
/// @brief Sent to a window after its size has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SIZE = 0x0005;
/// @brief Sent to both the window being activated and the window being deactivated. If the windows use the same input queue, the message is sent synchronously, first to the window procedure of the top-level window being deactivated, then to the window procedure of the top-level window being activated. If the windows use different input queues, the message is sent asynchronously, so the window is activated immediately.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ACTIVATE = 0x0006;
/// @brief Sent to a window after it has gained the keyboard focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETFOCUS = 0x0007;
/// @brief Sent to a window immediately before it loses the keyboard focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_KILLFOCUS = 0x0008;
// not defined 0x0009
/// @brief Sent when an application changes the enabled state of a window. It is sent to the window whose enabled state is changing. This message is sent before the EnableWindow function returns, but after the enabled state (WS_DISABLED style bit) of the window has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ENABLE = 0x000A;
/// @brief An application sends the WM_SETREDRAW message to a window to allow changes in that window to be redrawn or to prevent changes in that window from being redrawn.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETREDRAW = 0x000B;
/// @brief Sets the text of a window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETTEXT = 0x000C;
/// @brief Copies the text that corresponds to a window into a buffer provided by the caller.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETTEXT = 0x000D;
/// @brief Determines the length, in characters, of the text associated with a window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETTEXTLENGTH = 0x000E;
/// @brief The WM_PAINT message is sent when the system or another application makes a request to paint a portion of an application's window. The message is sent when the UpdateWindow or RedrawWindow function is called, or by the DispatchMessage function when the application obtains a WM_PAINT message by using the GetMessage or PeekMessage function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PAINT = 0x000F;
/// @brief Sent as a signal that a window or an application should terminate.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CLOSE = 0x0010;
/// @brief The WM_QUERYENDSESSION message is sent when the user chooses to end the session or when an application calls one of the system shutdown functions. If any application returns zero, the session is not ended. The system stops sending WM_QUERYENDSESSION messages as soon as one application returns zero.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUERYENDSESSION = 0x0011;
/// @brief Indicates a request to terminate an application, and is generated when the application calls the PostQuitMessage function. This message causes the GetMessage function to return zero.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUIT = 0x0012;
/// @brief Sent to an icon when the user requests that the window be restored to its previous size and position.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUERYOPEN = 0x0013;
/// @brief Sent when the window background must be erased (for example, when a window is resized). The message is sent to prepare an invalidated portion of a window for painting.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ERASEBKGND = 0x0014;
/// @brief The WM_SYSCOLORCHANGE message is sent to all top-level windows when a change is made to a system color setting.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYSCOLORCHANGE = 0x0015;
/// @brief The WM_ENDSESSION message is sent to an application after the system processes the results of the WM_QUERYENDSESSION message. The WM_ENDSESSION message informs the application whether the session is ending.The WM_ENDSESSION message is sent to an application after the system processes the results of the WM_QUERYENDSESSION message. The WM_ENDSESSION message informs the application whether the session is ending.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ENDSESSION = 0x0016;
// not defined 0x0017
/// @brief Sent to a window when the window is about to be hidden or shown.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SHOWWINDOW = 0x0018;
/// @brief The WM_CTLCOLOR message is used in 16-bit versions of Windows to change the color scheme of list boxes, the list boxes of combo boxes, message boxes, button controls, edit controls, static controls, and dialog boxes.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLOR = 0x0019;
/// @brief An application sends the WM_WININICHANGE message to all top-level windows after making a change to the WIN.INI file. The SystemParametersInfo function sends this message after an application uses the function to change a setting in WIN.INI.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_WININICHANGE = 0x001A;
/// @brief The WM_DEVMODECHANGE message is sent to all top-level windows whenever the user changes device-mode settings.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DEVMODECHANGE = 0x001B;
/// @brief Sent when a window belonging to a different application than the active window is about to be activated. The message is sent to the application whose window is being activated and to the application whose window is being deactivated.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ACTIVATEAPP = 0x001C;
/// @brief An application sends the WM_FONTCHANGE message to all top-level windows in the system after changing the pool of font resources.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_FONTCHANGE = 0x001D;
/// @brief A message that is sent whenever there is a change in the system time.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_TIMECHANGE = 0x001E;
/// @brief Sent to cancel certain modes, such as mouse capture. For example, the system sends this message to the active window when a dialog box or message box is displayed. Certain functions also send this message explicitly to the specified window regardless of whether it is the active window. For example, the EnableWindow function sends this message when disabling the specified window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CANCELMODE = 0x001F;
/// @brief Sent to a window if the mouse causes the cursor to move within a window and mouse input is not captured.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETCURSOR = 0x0020;
/// @brief Sent when the cursor is in an inactive window and the user presses a mouse button. The parent window receives this message only if the child window passes it to the DefWindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOUSEACTIVATE = 0x0021;
/// @brief Sent to a child window when the user clicks the window's title bar or when the window is activated, moved, or sized.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CHILDACTIVATE = 0x0022;
/// @brief Sent by a computer-based training (CBT) application to separate user-input messages from other messages sent through the WH_JOURNALPLAYBACK procedure.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUEUESYNC = 0x0023;
/// @brief Sent to a window when the size or position of the window is about to change. An application can use this message to override the window's default maximized size and position, or its default minimum or maximum tracking size.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETMINMAXINFO = 0x0024;
// not defined 0x0025
/// @brief The WM_PAINTICON message is sent to a minimized window when the icon is to be painted but only if the application is written for Windows 3.x. A window receives this message only if a class icon is defined for the window; otherwise, WM_PAINT is sent instead.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PAINTICON = 0x0026;
/// @brief An application sends the WM_ERASEBKGND message when the window background must be erased (for example, when a window is resized). The message is sent to prepare an invalidated portion of a window for painting.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ICONERASEBKGND = 0x0027;
/// @brief Sent to a dialog box procedure to set the keyboard focus to a different control in the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NEXTDLGCTL = 0x0028;
// not defined 0x0029
/// @brief The WM_SPOOLERSTATUS message is sent from Print Manager whenever a job is added to or removed from the Print Manager queue.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SPOOLERSTATUS = 0x002A;
/// @brief Sent to the parent window of an owner-drawn button, combo box, list box, or menu when a visual aspect of the button, combo box, list box, or menu has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DRAWITEM = 0x002B;
/// @brief Sent to the owner window of a combo box, list box, list-view control, or menu item when the control or menu is created.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MEASUREITEM = 0x002C;
/// @brief Sent to the owner of a list box or combo box when the list box or combo box is destroyed or when items are removed by the LB_DELETESTRING, LB_RESETCONTENT, CB_DELETESTRING, or CB_RESETCONTENT message. The system sends a WM_DELETEITEM message for each deleted item. The system sends the WM_DELETEITEM message for any deleted list box or combo box item with nonzero item data.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DELETEITEM = 0x002D;
/// @brief Sent by a list box with the LBS_WANTKEYBOARDINPUT style to its owner in response to a WM_KEYDOWN message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_VKEYTOITEM = 0x002E;
/// @brief Sent by a list box with the LBS_WANTKEYBOARDINPUT style to its owner in response to a WM_CHAR message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CHARTOITEM = 0x002F;
/// @brief Sets the font that a control is to use when drawing text.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETFONT = 0x0030;
/// @brief Retrieves the font with which the control is currently drawing its text.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETFONT = 0x0031;
/// @brief Sent to a window to associate a hot key with the window. When the user presses the hot key, the system activates the window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETHOTKEY = 0x0032;
/// @brief Sent to determine the hot key associated with a window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETHOTKEY = 0x0033;
// not defined 0x0034 - 0x0036
/// @brief Sent to a minimized (iconic) window. The window is about to be dragged by the user but does not have an icon defined for its class. An application can return a handle to an icon or cursor. The system displays this cursor or icon while the user drags the icon.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUERYDRAGICON = 0x0037;
/// @brief Sent to determine the relative position of a new item in the sorted list of an owner-drawn combo box or list box. Whenever the application adds a new item, the system sends this message to the owner of a combo box or list box created with the CBS_SORT or LBS_SORT style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_COMPAREITEM = 0x0039;
/// @brief Sent by both Microsoft Active Accessibility and Microsoft UI Automation to obtain information about an accessible object contained in a server application.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETOBJECT = 0x003D;
/// @brief Sent to all top-level windows when the system detects more than 12.5 percent of system time over a 30- to 60-second interval is being spent compacting memory. This indicates that system memory is low.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_COMPACTING = 0x0041;
/// @cond
constexpr int32_t WM_COMMNOTIFY = 0x0044;
/// @endcond
/// @brief Sent to a window whose size, position, or place in the Z order is about to change as a result of a call to the SetWindowPos function or another window-management function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_WINDOWPOSCHANGING = 0x0046;
/// @brief Sent to a window whose size, position, or place in the Z order has changed as a result of a call to the SetWindowPos function or another window-management function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_WINDOWPOSCHANGED = 0x0047;
/// @brief Notifies applications that the system, typically a battery-powered personal computer, is about to enter a suspended mode.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POWER = 0x0048;
/// @brief An application sends the WM_COPYDATA message to pass data to another application.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_COPYDATA = 0x004A;
/// @brief Posted to an application when a user cancels the application's journaling activities. The message is posted with a NULL window handle.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CANCELJOURNAL = 0x004B;
// not defined 0x004C - 0x004D
/// @brief Sent by a common control to its parent window when an event has occurred or the control requires some information.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NOTIFY = 0x004E;
// not defined 0x004F
/// @brief Posted to the window with the focus when the user chooses a new input language, either with the hotkey (specified in the Keyboard control panel application) or from the indicator on the system taskbar. An application can accept the change by passing the message to the DefWindowProc function or reject the change (and prevent it from taking place) by returning immediately.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INPUTLANGCHANGEREQUEST = 0x0050;
/// @brief Sent to the topmost affected window after an application's input language has been changed. You should make any application-specific settings and pass the message to the DefWindowProc function, which passes the message to all first-level child windows. These child windows can pass the message to DefWindowProc to have it pass the message to their child windows, and so on.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INPUTLANGCHANGE = 0x0051;
/// @brief Sent to an application that has initiated a training card with Windows Help. The message informs the application when the user clicks an authorable button. An application initiates a training card by specifying the HELP_TCARD command in a call to the WinHelp function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_TCARD = 0x0052;
/// @brief Indicates that the user pressed the F1 key. If a menu is active when F1 is pressed, WM_HELP is sent to the window associated with the menu; otherwise, WM_HELP is sent to the window that has the keyboard focus. If no window has the keyboard focus, WM_HELP is sent to the currently active window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_HELP = 0x0053;
/// @brief Sent to all windows after the user has logged on or off. When the user logs on or off, the system updates the user-specific settings. The system sends this message immediately after updating the settings.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_USERCHANGED = 0x0054;
/// @brief Determines if a window accepts ANSI or Unicode structures in the WM_NOTIFY notification message. WM_NOTIFYFORMAT messages are sent from a common control to its parent window and from the parent window to the common control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NOTIFYFORMAT = 0x0055;
// not defined 0x0056 - 0x007A
/// @brief Notifies a window that the user desires a context menu to appear. The user may have clicked the right mouse button (right-clicked) in the window, pressed Shift+F10 or pressed the applications key (context menu key) available on some keyboards.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CONTEXTMENU = 0x007B;
/// @brief Sent to a window when the SetWindowLong function is about to change one or more of the window's styles.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_STYLECHANGING = 0x007C;
/// @brief Sent to a window after the SetWindowLong function has changed one or more of the window's styles.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_STYLECHANGED = 0x007D;
/// @brief The WM_DISPLAYCHANGE message is sent to all windows when the display resolution has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DISPLAYCHANGE = 0x007E;
/// @brief Sent to a window to retrieve a handle to the large or small icon associated with a window. The system displays the large icon in the ALT+TAB dialog, and the small icon in the window caption.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETICON = 0x007F;
/// @brief Associates a new large or small icon with a window. The system displays the large icon in the ALT+TAB dialog box, and the small icon in the window caption.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SETICON = 0x0080;
/// @brief Sent prior to the WM_CREATE message when a window is first created.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCCREATE = 0x0081;
/// @brief Notifies a window that its nonclient area is being destroyed. The DestroyWindow function sends the WM_NCDESTROY message to the window following the WM_DESTROY message.WM_DESTROY is used to free the allocated memory object associated with the window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCDESTROY = 0x0082;
/// @brief Sent when the size and position of a window's client area must be calculated. By processing this message, an application can control the content of the window's client area when the size or position of the window changes.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCCALCSIZE = 0x0083;
/// @brief Sent to a window in order to determine what part of the window corresponds to a particular screen coordinate. This can happen, for example, when the cursor moves, when a mouse button is pressed or released, or in response to a call to a function such as WindowFromPoint. If the mouse is not captured, the message is sent to the window beneath the cursor. Otherwise, the message is sent to the window that has captured the mouse.Sent to a window in order to determine what part of the window corresponds to a particular screen coordinate. This can happen, for example, when the cursor moves, when a mouse button is pressed or released, or in response to a call to a function such as WindowFromPoint. If the mouse is not captured, the message is sent to the window beneath the cursor. Otherwise, the message is sent to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCHITTEST = 0x0084;
/// @brief The WM_NCPAINT message is sent to a window when its frame must be painted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCPAINT = 0x0085;
/// @brief Sent to a window when its nonclient area needs to be changed to indicate an active or inactive state.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCACTIVATE = 0x0086;
/// @brief Sent to the window procedure associated with a control. By default, the system handles all keyboard input to the control; the system interprets certain types of keyboard input as dialog box navigation keys. To override this default behavior, the control can respond to the WM_GETDLGCODE message to indicate the types of input it wants to process itself.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETDLGCODE = 0x0087;
/// @brief The WM_SYNCPAINT message is used to synchronize painting while avoiding linking independent GUI threads.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYNCPAINT = 0x0088;
// not defined 0x0089 - 0x000F
/// @brief Posted to a window when the cursor is moved within the nonclient area of the window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCMOUSEMOVE = 0x00A0;
/// @brief Posted when the user presses the left mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCLBUTTONDOWN = 0x00A1;
/// @brief Posted when the user releases the left mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCLBUTTONUP = 0x00A2;
/// @brief Posted when the user double-clicks the left mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCLBUTTONDBLCLK = 0x00A3;
/// @brief Posted when the user presses the right mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCRBUTTONDOWN = 0x00A4;
/// @brief Posted when the user releases the right mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCRBUTTONUP = 0x00A5;
/// @brief Posted when the user double-clicks the right mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCRBUTTONDBLCLK = 0x00A6;
/// @brief Posted when the user presses the middle mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCMBUTTONDOWN = 0x00A7;
/// @brief Posted when the user releases the middle mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCMBUTTONUP = 0x00A8;
/// @brief Posted when the user double-clicks the middle mouse button while the cursor is within the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCMBUTTONDBLCLK = 0x00A9;
// not defined 0x00AA
/// @brief Posted when the user presses the first or second X button while the cursor is in the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCXBUTTONDOWN = 0x00AB;
/// @brief Posted when the user releases the first or second X button while the cursor is in the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCXBUTTONUP = 0x00AC;
/// @brief Posted when the user double-clicks the first or second X button while the cursor is in the nonclient area of a window. This message is posted to the window that contains the cursor. If a window has captured the mouse, this message is not posted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCXBUTTONDBLCLK = 0x00AD;
/// @brief Sent to the window that registered to receive raw input.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INPUT_DEVICE_CHANGE = 0x00FE;
/// @brief Sent to the window that is getting raw input.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INPUT = 0x00FF;
/// @brief Posted to the window with the keyboard focus when a nonsystem key is pressed. A nonsystem key is a key that is pressed when the ALT key is not pressed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_KEYDOWN = 0x0100;
/// @brief Posted to the window with the keyboard focus when a nonsystem key is released. A nonsystem key is a key that is pressed when the ALT key is not pressed, or a keyboard key that is pressed when a window has the keyboard focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_KEYUP = 0x0101;
/// @brief Posted to the window with the keyboard focus when a WM_KEYDOWN message is translated by the TranslateMessage function. The WM_CHAR message contains the character code of the key that was pressed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CHAR = 0x0102;
/// @brief Posted to the window with the keyboard focus when a WM_KEYUP message is translated by the TranslateMessage function. WM_DEADCHAR specifies a character code generated by a dead key. A dead key is a key that generates a character, such as the umlaut (double-dot), that is combined with another character to form a composite character. For example, the umlaut-O character ( ) is generated by typing the dead key for the umlaut character, and then typing the O key.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DEADCHAR = 0x0103;
/// @brief Posted to the window with the keyboard focus when the user presses the F10 key (which activates the menu bar) or holds down the ALT key and then presses another key. It also occurs when no window currently has the keyboard focus; in this case, the WM_SYSKEYDOWN message is sent to the active window. The window that receives the message can distinguish between these two contexts by checking the context code in the lParam parameter.Posted to the window with the keyboard focus when the user presses the F10 key (which activates the menu bar) or holds down the ALT key and then presses another key. It also occurs when no window currently has the keyboard focus; in this case, the WM_SYSKEYDOWN message is sent to the active window. The window that receives the message can distinguish between these two contexts by checking the context code in the lParam parameter.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYSKEYDOWN = 0x0104;
/// @brief Posted to the window with the keyboard focus when the user releases a key that was pressed while the ALT key was held down. It also occurs when no window currently has the keyboard focus; in this case, the WM_SYSKEYUP message is sent to the active window. The window that receives the message can distinguish between these two contexts by checking the context code in the lParam parameter.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYSKEYUP = 0x0105;
/// @brief Posted to the window with the keyboard focus when a WM_SYSKEYDOWN message is translated by the TranslateMessage function. It specifies the character code of a system character key that is, a character key that is pressed while the ALT key is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYSCHAR = 0x0106;
/// @brief Sent to the window with the keyboard focus when a WM_SYSKEYDOWN message is translated by the TranslateMessage function. WM_SYSDEADCHAR specifies the character code of a system dead key that is, a dead key that is pressed while holding down the ALT key.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYSDEADCHAR = 0x0107;
//constexpr int32_t WM_KEYLAST = 0x0108;
//constexpr int32_t WM_UNICHAR = 0x0109;
/// @brief Keyboard message filter value.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_KEYLAST = 0x0109;
// not defined 0x010B - 0x010C
/// @brief Sent immediately before the IME generates the composition string as a result of a keystroke. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_STARTCOMPOSITION = 0x010D;
/// @brief Sent to an application when the IME ends composition. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_ENDCOMPOSITION = 0x010E;
/// @brief Sent to the dialog box procedure immediately before a dialog box is displayed. Dialog box procedures typically use this message to initialize controls and carry out any other initialization tasks that affect the appearance of the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INITDIALOG = 0x0110;
/// @brief Sent when the user selects a command item from a menu, when a control sends a notification message to its parent window, or when an accelerator keystroke is translated.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_COMMAND = 0x0111;
/// @brief A window receives this message when the user chooses a command from the Window menu (formerly known as the system or control menu) or when the user chooses the maximize button, minimize button, restore button, or close button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SYSCOMMAND = 0x0112;
/// @brief Posted to the installing thread's message queue when a timer expires. The message is posted by the GetMessage or PeekMessage function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_TIMER = 0x0113;
/// @brief The WM_HSCROLL message is sent to a window when a scroll event occurs in the window's standard horizontal scroll bar. This message is also sent to the owner of a horizontal scroll bar control when a scroll event occurs in the control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_HSCROLL = 0x0114;
/// @brief The WM_VSCROLL message is sent to a window when a scroll event occurs in the window's standard vertical scroll bar. This message is also sent to the owner of a vertical scroll bar control when a scroll event occurs in the control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_VSCROLL = 0x0115;
/// @brief Sent when a menu is about to become active. It occurs when the user clicks an item on the menu bar or presses a menu key. This allows the application to modify the menu before it is displayed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INITMENU = 0x0116;
/// @brief Sent when a drop-down menu or submenu is about to become active. This allows an application to modify the menu before it is displayed, without changing the entire menu.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_INITMENUPOPUP = 0x0117;
// not defined 0x0118
/// @brief Passes information about a gesture.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GESTURE = 0x0119;
/// @brief Gives you a chance to set the gesture configuration.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GESTURENOTIFY = 0x011A;
// not defined 0x011B - 0x011E
/// @brief Sent to a menu's owner window when the user selects a menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MENUSELECT = 0x011F;
/// @brief Sent when a menu is active and the user presses a key that does not correspond to any mnemonic or accelerator key. This message is sent to the window that owns the menu.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MENUCHAR = 0x0120;
/// @brief Sent to the owner window of a modal dialog box or menu that is entering an idle state. A modal dialog box or menu enters an idle state when no messages are waiting in its queue after it has processed one or more previous messages.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ENTERIDLE = 0x0121;
/// @brief Sent when the user releases the right mouse button while the cursor is on a menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MENURBUTTONUP = 0x0122;
/// @brief Sent to the owner of a drag-and-drop menu when the user drags a menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MENUDRAG = 0x0123;
/// @brief Sent to the owner of a drag-and-drop menu when the mouse cursor enters a menu item or moves from the center of the item to the top or bottom of the item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MENUGETOBJECT = 0x0124;
/// @brief Sent when a drop-down menu or submenu has been destroyed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_UNINITMENUPOPUP = 0x0125;
/// @brief Sent when the user makes a selection from a menu.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MENUCOMMAND = 0x0126;
/// @brief An application sends the WM_CHANGEUISTATE message to indicate that the UI state should be changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CHANGEUISTATE = 0x0127;
/// @brief An application sends the WM_UPDATEUISTATE message to change the UI state for the specified window and all its child windows.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_UPDATEUISTATE = 0x0128;
/// @brief An application sends the WM_QUERYUISTATE message to retrieve the UI state for a window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUERYUISTATE = 0x0129;
// not defined 0x0130 - 0x0131
/// @brief The WM_CTLCOLORMSGBOX message is sent to the owner window of a message box before Windows draws the message box. By responding to this message, the owner window can set the text and background colors of the message box by using the given display device context handle
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLORMSGBOX = 0x0132;
/// @brief An edit control that is not read-only or disabled sends the WM_CTLCOLOREDIT message to its parent window when the control is about to be drawn. By responding to this message, the parent window can use the specified device context handle to set the text and background colors of the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLOREDIT = 0x0133;
/// @brief Sent to the parent window of a list box before the system draws the list box. By responding to this message, the parent window can set the text and background colors of the list box by using the specified display device context handle.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLORLISTBOX = 0x0134;
/// @brief The WM_CTLCOLORBTN message is sent to the parent window of a button before drawing the button. The parent window can change the button's text and background colors. However, only owner-drawn buttons respond to the parent window processing this message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLORBTN = 0x0135;
/// @brief Sent to a dialog box before the system draws the dialog box. By responding to this message, the dialog box can set its text and background colors using the specified display device context handle.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLORDLG = 0x0136;
/// @brief The WM_CTLCOLORSCROLLBAR message is sent to the parent window of a scroll bar control when the control is about to be drawn. By responding to this message, the parent window can use the display context handle to set the background color of the scroll bar control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLORSCROLLBAR = 0x0137;
/// @brief A static control, or an edit control that is read-only or disabled, sends the WM_CTLCOLORSTATIC message to its parent window when the control is about to be drawn. By responding to this message, the parent window can use the specified device context handle to set the text foreground and background colors of the static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CTLCOLORSTATIC = 0x0138;
// not defined 0x0139 - 01E0
/// @brief Retrieves the menu handle for the current window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETHMENU = 0x01E1;
// not defined 0x01E2 - 0x019F
/// @brief Posted to a window when the cursor moves. If the mouse is not captured, the message is posted to the window that contains the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOUSEMOVE = 0x0200;
/// @brief Posted when the user presses the left mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_LBUTTONDOWN = 0x0201;
/// @brief Posted when the user releases the left mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_LBUTTONUP = 0x0202;
/// @brief Posted when the user double-clicks the left mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_LBUTTONDBLCLK = 0x0203;
/// @brief Posted when the user presses the right mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_RBUTTONDOWN = 0x0204;
/// @brief Posted when the user releases the right mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_RBUTTONUP = 0x0205;
/// @brief Posted when the user double-clicks the right mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_RBUTTONDBLCLK = 0x0206;
/// @brief Posted when the user presses the middle mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MBUTTONDOWN = 0x0207;
/// @brief Posted when the user releases the middle mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MBUTTONUP = 0x0208;
/// @brief Posted when the user double-clicks the middle mouse button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MBUTTONDBLCLK = 0x0209;
/// @brief Sent to the focus window when the mouse wheel is rotated. The DefWindowProc function propagates the message to the window's parent. There should be no internal forwarding of the message, since DefWindowProc propagates it up the parent chain until it finds a window that processes it.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOUSEWHEEL = 0x020A;
/// @brief Posted when the user presses the first or second X button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_XBUTTONDOWN = 0x020B;
/// @brief Posted when the user releases the first or second X button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_XBUTTONUP = 0x020C;
/// @brief Posted when the user double-clicks the first or second X button while the cursor is in the client area of a window. If the mouse is not captured, the message is posted to the window beneath the cursor. Otherwise, the message is posted to the window that has captured the mouse.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_XBUTTONDBLCLK = 0x020D;
/// @brief Sent to the active window when the mouse's horizontal scroll wheel is tilted or rotated. The DefWindowProc function propagates the message to the window's parent. There should be no internal forwarding of the message, since DefWindowProc propagates it up the parent chain until it finds a window that processes it.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOUSEHWHEEL = 0x020E;
// not defined 0x020F
/// @brief Sent to the parent of a child window when the child window is created or destroyed, or when the user clicks a mouse button while the cursor is over the child window. When the child window is being created, the system sends WM_PARENTNOTIFY just before the CreateWindow or CreateWindowEx function that creates the window returns. When the child window is being destroyed, the system sends the message before any processing to destroy the window takes place.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PARENTNOTIFY = 0x0210;
/// @brief Notifies an application's main window procedure that a menu modal loop has been entered.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ENTERMENULOOP = 0x0211;
/// @brief Notifies an application's main window procedure that a menu modal loop has been exited.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_EXITMENULOOP = 0x0212;
/// @brief Sent to an application when the right or left arrow key is used to switch between the menu bar and the system menu.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NEXTMENU = 0x0213;
/// @brief Sent to a window that the user is resizing. By processing this message, an application can monitor the size and position of the drag rectangle and, if needed, change its size or position.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SIZING = 0x0214;
/// @brief Sent to the window that is losing the mouse capture.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CAPTURECHANGED = 0x0215;
/// @brief Sent to a window that the user is moving. By processing this message, an application can monitor the position of the drag rectangle and, if needed, change its position.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOVING = 0x0216;
// not defined 0x0217
/// @brief Notifies applications that a power-management event has occurred.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POWERBROADCAST = 0x0218;
/// @brief Notifies an application of a change to the hardware configuration of a device or the computer.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DEVICECHANGE = 0x0219;
/// @brief An application sends the WM_MDICREATE message to a multiple-document interface (MDI) client window to create an MDI child window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDICREATE = 0x0220;
/// @brief An application sends the WM_MDIDESTROY message to a multiple-document interface (MDI) client window to close an MDI child window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIDESTROY = 0x0221;
/// @brief An application sends the WM_MDIACTIVATE message to a multiple-document interface (MDI) client window to instruct the client window to activate a different MDI child window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIACTIVATE = 0x0222;
/// @brief An application sends the WM_MDIRESTORE message to a multiple-document interface (MDI) client window to restore an MDI child window from maximized or minimized size.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIRESTORE = 0x0223;
/// @brief An application sends the WM_MDINEXT message to a multiple-document interface (MDI) client window to activate the next or previous child window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDINEXT = 0x0224;
/// @brief An application sends the WM_MDIMAXIMIZE message to a multiple-document interface (MDI) client window to maximize an MDI child window. The system resizes the child window to make its client area fill the client window. The system places the child window's window menu icon in the rightmost position of the frame window's menu bar, and places the child window's restore icon in the leftmost position. The system also appends the title bar text of the child window to that of the frame window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIMAXIMIZE = 0x0225;
/// @brief An application sends the WM_MDITILE message to a multiple-document interface (MDI) client window to arrange all of its MDI child windows in a tile format.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDITILE = 0x0226;
/// @brief An application sends the WM_MDICASCADE message to a multiple-document interface (MDI) client window to arrange all its child windows in a cascade format.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDICASCADE = 0x0227;
/// @brief An application sends the WM_MDIICONARRANGE message to a multiple-document interface (MDI) client window to arrange all minimized MDI child windows. It does not affect child windows that are not minimized.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIICONARRANGE = 0x0228;
/// @brief An application sends the WM_MDIGETACTIVE message to a multiple-document interface (MDI) client window to retrieve the handle to the active MDI child window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIGETACTIVE = 0x0229;
/// @brief An application sends the WM_MDISETMENU message to a multiple-document interface (MDI) client window to replace the entire menu of an MDI frame window, to replace the window menu of the frame window, or both.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDISETMENU = 0x0230;
/// @brief Sent one time to a window after it enters the moving or sizing modal loop. The window enters the moving or sizing modal loop when the user clicks the window's title bar or sizing border, or when the window passes the WM_SYSCOMMAND message to the DefWindowProc function and the wParam parameter of the message specifies the SC_MOVE or SC_SIZE value. The operation is complete when DefWindowProc returns.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ENTERSIZEMOVE = 0x0231;
/// @brief Sent one time to a window, after it has exited the moving or sizing modal loop. The window enters the moving or sizing modal loop when the user clicks the window's title bar or sizing border, or when the window passes the WM_SYSCOMMAND message to the DefWindowProc function and the wParam parameter of the message specifies the SC_MOVE or SC_SIZE value. The operation is complete when DefWindowProc returns.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_EXITSIZEMOVE = 0x0232;
/// @brief Sent when the user drops a file on the window of an application that has registered itself as a recipient of dropped files.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DROPFILES = 0x0233;
/// @brief An application sends the WM_MDIREFRESHMENU message to a multiple-document interface (MDI) client window to refresh the window menu of the MDI frame window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MDIREFRESHMENU = 0x0234;
// not defined 0x0235 - 0x0237
/// @brief Sent to a window when there is a change in the settings of a monitor that has a digitizer attached to it. This message contains information regarding the scaling of the display mode.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERDEVICECHANGE = 0x0238;
/// @brief Sent to a window when a pointer device is detected within range of an input digitizer. This message contains information regarding the device and its proximity.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERDEVICEINRANGE = 0x0239;
/// @brief Sent to a window when a pointer device has departed the range of an input digitizer. This message contains information regarding the device and its proximity.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERDEVICEOUTOFRANGE = 0x023A;
/// @brief Notifies the window when one or more touch points, such as a finger or pen, touches a touch-sensitive digitizer surface.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_TOUCH = 0x0240;
/// @brief Posted to provide an update on a pointer that made contact over the non-client area of a window or when a hovering uncaptured contact moves over the non-client area of a window. While the pointer is hovering, the message targets whichever window the pointer happens to be over. While the pointer is in contact with the surface, the pointer is implicitly captured to the window over which the pointer made contact and that window continues to receive input for the pointer until it breaks contact.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCPOINTERUPDATE = 0x0241;
/// @brief Posted when a pointer makes contact over the non-client area of a window. The message targets the window over which the pointer makes contact. The pointer is implicitly captured to the window so that the window continues to receive input for the pointer until it breaks contact.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCPOINTERDOWN = 0x0242;
/// @brief Posted when a pointer that made contact over the non-client area of a window breaks contact. The message targets the window over which the pointer makes contact and the pointer is, at that point, implicitly captured to the window so that the window continues to receive input for the pointer until it breaks contact, including the WM_NCPOINTERUP notification.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCPOINTERUP = 0x0243;
/// @brief Posted to provide an update on a pointer that made contact over the client area of a window or on a hovering uncaptured pointer over the client area of a window. While the pointer is hovering, the message targets whichever window the pointer happens to be over. While the pointer is in contact with the surface, the pointer is implicitly captured to the window over which the pointer made contact and that window continues to receive input for the pointer until it breaks contact.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERUPDATE = 0x0245;
/// @brief Posted when a pointer makes contact over the client area of a window. This input message targets the window over which the pointer makes contact, and the pointer is implicitly captured to the window so that the window continues to receive input for the pointer until it breaks contact.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERDOWN = 0x0246;
/// @brief Posted when a pointer that made contact over the client area of a window breaks contact. This input message targets the window over which the pointer makes contact and the pointer is, at that point, implicitly captured to the window so that the window continues to receive input messages including the WM_POINTERUP notification for the pointer until it breaks contact.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERUP = 0x0247;
/// @brief Sent to a window when a new pointer enters detection range over the window (hover) or when an existing pointer moves within the boundaries of the window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERENTER = 0x0249;
/// @brief Sent to a window when a pointer leaves detection range over the window (hover) or when a pointer moves outside the boundaries of the window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERLEAVE = 0x024A;
/// @brief Sent to an inactive window when a primary pointer generates a WM_POINTERDOWN over the window. As long as the message remains unhandled, it travels up the parent window chain until it is reaches the top-level window. Applications can respond to this message to specify whether they wish to be activated.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERACTIVATE = 0x024B;
/// @brief Sent to a window that is losing capture of an input pointer.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERCAPTURECHANGED = 0x024C;
/// @brief Sent to a window on a touch down in order to determine the most probable touch target.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_TOUCHHITTESTING = 0x024D;
/// @brief Posted to the window with foreground keyboard focus when a scroll wheel is rotated.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERWHEEL = 0x024E;
/// @brief Posted to the window with foreground keyboard focus when a horizontal scroll wheel is rotated.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERHWHEEL = 0x024F;
/// @brief Sent by an application to direct the IME window to carry out the requested command. The application uses this message to control the IME window that it has created. To send this message, the application calls the SendMessage function with the following parameters.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_POINTERHITTEST = 0x0250;
// not defined 0x0251 - 0x0280
/// @brief Sent to an application when a window is activated. A window receives this message through its WindowProc function.v
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_SETCONTEXT = 0x0281;
/// @brief Sent to an application to notify it of changes to the IME window. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_NOTIFY = 0x0282;
/// @brief Sent by an application to direct the IME window to carry out the requested command. The application uses this message to control the IME window that it has created. To send this message, the application calls the SendMessage function with the following parameters.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_CONTROL = 0x0283;
/// @brief Sent to an application when the IME window finds no space to extend the area for the composition window. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_COMPOSITIONFULL = 0x0284;
/// @brief Sent to an application when the operating system is about to change the current IME. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_SELECT = 0x0285;
/// @brief Sent to an application when the IME gets a character of the conversion result. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_CHAR = 0x0286;
// not defined 0x0287
/// @brief Sent to an application to provide commands and request information. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_REQUEST = 0x0288;
// not defined 0x0289
/// @brief Sent to an application by the IME to notify the application of a key press and to keep message order. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_KEYDOWN = 0x0290;
/// @brief Sent to an application by the IME to notify the application of a key release and to keep message order. A window receives this message through its WindowProc function.Sent to an application by the IME to notify the application of a key release and to keep message order. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_IME_KEYUP = 0x0291;
// not defined 0x0292 - 0x02A0
/// @brief Posted to a window when the cursor hovers over the client area of the window for the period of time specified in a prior call to TrackMouseEvent.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOUSEHOVER = 0x02A1;
/// @brief Posted to a window when the cursor leaves the client area of the window specified in a prior call to TrackMouseEvent.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_MOUSELEAVE = 0x2A3;
// not defined 0x02A4 - 0x02A9
/// @brief Posted to a window when the cursor hovers over the nonclient area of the window for the period of time specified in a prior call to TrackMouseEvent.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCMOUSEHOVER = 0x02A0;
/// @brief Posted to a window when the cursor leaves the nonclient area of the window specified in a prior call to TrackMouseEvent.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_NCMOUSELEAVE = 0x02A2;
// not defined 0x02A3 - 0x02B0
/// @brief Notifies applications of changes in session state.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_WTSSESSION_CHANGE = 0x02B1;
// not defined 0x02B2 - 0x02BF
/// @cond
constexpr int32_t WM_TABLET_FIRST = 0x02C0;
// not defined 0x02C1 - 0x02DE
constexpr int32_t WM_TABLET_LAST = 0x02DF;
/// @endcond
/// @brief Sent when the effective dots per inch (dpi) for a window has changed. The DPI is the scale factor for a window. There are multiple events that can cause the DPI to change. The following list indicates the possible causes for the change in DPI.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DPICHANGED = 0x02E0;
// not defined 0x02E1 - 0x029F
/// @brief An application sends a WM_CUT message to an edit control or combo box to delete (cut) the current selection, if any, in the edit control and copy the deleted text to the clipboard in CF_TEXT format.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CUT = 0x0300;
/// @brief An application sends the WM_COPY message to an edit control or combo box to copy the current selection to the clipboard in CF_TEXT format.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_COPY = 0x0301;
/// @brief An application sends a WM_PASTE message to an edit control or combo box to copy the current content of the clipboard to the edit control at the current caret position. Data is inserted only if the clipboard contains data in CF_TEXT format.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PASTE = 0x0302;
/// @brief An application sends a WM_CLEAR message to an edit control or combo box to delete (clear) the current selection, if any, from the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CLEAR = 0x0303;
/// @brief An application sends a WM_UNDO message to an edit control to undo the last operation. When this message is sent to an edit control, the previously deleted text is restored or the previously added text is deleted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_UNDO = 0x0304;
/// @brief Sent to the clipboard owner if it has delayed rendering a specific clipboard format and if an application has requested data in that format. The clipboard owner must render data in the specified format and place it on the clipboard by calling the SetClipboardData function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_RENDERFORMAT = 0x0305;
/// @brief Sent to the clipboard owner before it is destroyed, if the clipboard owner has delayed rendering one or more clipboard formats. For the content of the clipboard to remain available to other applications, the clipboard owner must render data in all the formats it is capable of generating, and place the data on the clipboard by calling the SetClipboardData function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_RENDERALLFORMATS = 0x0306;
/// @brief Sent to the clipboard owner when a call to the EmptyClipboard function empties the clipboard.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DESTROYCLIPBOARD = 0x0307;
/// @brief Sent to the first window in the clipboard viewer chain when the content of the clipboard changes. This enables a clipboard viewer window to display the new content of the clipboard.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DRAWCLIPBOARD = 0x0308;
/// @brief Sent to the clipboard owner by a clipboard viewer window when the clipboard contains data in the CF_OWNERDISPLAY format and the clipboard viewer's client area needs repainting.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PAINTCLIPBOARD = 0x0309;
/// @brief Sent to the clipboard owner by a clipboard viewer window when the clipboard contains data in the CF_OWNERDISPLAY format and an event occurs in the clipboard viewer's vertical scroll bar. The owner should scroll the clipboard image and update the scroll bar values.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_VSCROLLCLIPBOARD = 0x030A;
/// @brief Sent to the clipboard owner by a clipboard viewer window when the clipboard contains data in the CF_OWNERDISPLAY format and the clipboard viewer's client area has changed size.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_SIZECLIPBOARD = 0x030B;
/// @brief Sent to the clipboard owner by a clipboard viewer window to request the name of a CF_OWNERDISPLAY clipboard format.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_ASKCBFORMATNAME = 0x030C;
/// @brief Sent to the first window in the clipboard viewer chain when a window is being removed from the chain.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CHANGECBCHAIN = 0x030D;
/// @brief Sent to the clipboard owner by a clipboard viewer window. This occurs when the clipboard contains data in the CF_OWNERDISPLAY format and an event occurs in the clipboard viewer's horizontal scroll bar. The owner should scroll the clipboard image and update the scroll bar values.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_HSCROLLCLIPBOARD = 0x030E;
/// @brief The WM_QUERYNEWPALETTE message informs a window that it is about to receive the keyboard focus, giving the window the opportunity to realize its logical palette when it receives the focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_QUERYNEWPALETTE = 0x030F;
/// @brief The WM_PALETTEISCHANGING message informs applications that an application is going to realize its logical palette.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PALETTEISCHANGING = 0x0310;
/// @brief The WM_PALETTECHANGED message is sent to all top-level and overlapped windows after the window with the keyboard focus has realized its logical palette, thereby changing the system palette. This message enables a window that uses a color palette but does not have the keyboard focus to realize its logical palette and update its client area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PALETTECHANGED = 0x0311;
/// @brief Posted when the user presses a hot key registered by the RegisterHotKey function. The message is placed at the top of the message queue associated with the thread that registered the hot key.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_HOTKEY = 0x0312;
// not defined 0x0313 - 0x0316
/// @brief The WM_PRINT message is sent to a window to request that it draw itself in the specified device context, most commonly in a printer device context.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PRINT = 0x0317;
/// @brief The WM_PRINTCLIENT message is sent to a window to request that it draw its client area in the specified device context, most commonly in a printer device context.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_PRINTCLIENT = 0x0318;
/// @brief Notifies a window that the user generated an application command event, for example, by clicking an application command button using the mouse or typing an application command key on the keyboard.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_APPCOMMAND = 0x0319;
/// @brief Broadcast to every window following a theme change event. Examples of theme change events are the activation of a theme, the deactivation of a theme, or a transition from one theme to another.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_THEMECHANGED = 0x031A;
// not defined 0x031B - 0x031C
/// @brief Sent when the contents of the clipboard have changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_CLIPBOARDUPDATE = 0x031D;
/// @brief Informs all top-level windows that Desktop Window Manager (DWM) composition has been enabled or disabled.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DWMCOMPOSITIONCHANGED = 0x031E;
/// @brief Sent when the non-client area rendering policy has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DWMNCRENDERINGCHANGED = 0x031F;
/// @brief Informs all top-level windows that the colorization color has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DWMCOLORIZATIONCOLORCHANGED = 0x0320;
/// @brief Sent when a Desktop Window Manager (DWM) composed window is maximized.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DWMWINDOWMAXIMIZEDCHANGE = 0x0321;
/// @brief Instructs a window to provide a static bitmap to use as a thumbnail representation of that window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DWMSENDICONICTHUMBNAIL = 0x0323;
/// @brief Instructs a window to provide a static bitmap to use as a live preview (also known as a Peek preview) of that window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326;
// not defined 0x0327 - 0x033E
/// @brief Sent to request extended title bar information. A window receives this message through its WindowProc function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_GETTITLEBARINFOEX = 0x033F;
// not defined 0x0340 - 0x0357
/// @cond
constexpr int32_t WM_HANDHELDFIRST = 0x0358;
constexpr int32_t WM_HANDHELDLAST = 0x035F;
constexpr int32_t WM_AFXFIRST = 0x0360;
constexpr int32_t WM_AFXLAST = 0x037F;
constexpr int32_t WM_PENWINFIRST = 0x0380;
// not defined 0x0381 - 0x038E
constexpr int32_t WM_PENWINLAST = 0x038F;
/// @endcond
// not defined 0x0390 - 0x039F

// NOTE: All Message Numbers below 0x0400 are RESERVED.
// Private Window Messages Start Here:
/// @brief Used to define private messages for use by private window classes, usually of the form WM_USER+x, where x is an integer value.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
constexpr int32_t WM_USER = 0x0400;
// Private Window Messages Stop Here : 0x7FFF;

// NOTE: Messages available for use by applications.
/// @brief Used to define private messages, usually of the form WM_APP+x, where x is an integer value.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native wm
/// @remarks This value can be contained in the xtd::forms::message::msg property.
/// @remarks For more info see https://docs.microsoft.com .
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
