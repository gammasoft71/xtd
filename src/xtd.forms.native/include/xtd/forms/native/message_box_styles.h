/// @file
/// @brief Contains message box styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef MB_OK
/// @brief The message box contains one push button: OK. This is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_OK = 0x00000000L;
/// @brief The message box contains two push buttons: OK and Cancel.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_OKCANCEL = 0x00000001L;
/// @brief The message box contains three push buttons: Abort, Retry, and Ignore.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ABORTRETRYIGNORE = 0x00000002L;
/// @brief The message box contains three push buttons: Yes, No, and Cancel.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_YESNOCANCEL = 0x00000003L;
/// @brief The message box contains two push buttons: Yes and No.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @warning Internal use only
/// @brief
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_YESNO = 0x00000004L;
/// @brief The message box contains two push buttons: Retry and Cancel.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_RETRYCANCEL = 0x00000005L;

/// @brief A stop-sign icon appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONSTOP = 0x00000010L;
/// @brief A stop-sign icon appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONERROR = 0x00000010L;
/// @brief A stop-sign icon appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONHAND = 0x00000010L;
/// @brief A question-mark icon appears in the message box. The question-mark message icon is no longer recommended because it does not clearly represent a specific type of message and because the phrasing of a message as a question could apply to any message type. In addition, users can confuse the message symbol question mark with Help information. Therefore, do not use this question mark message symbol in your message boxes. The system continues to support its inclusion only for backward compatibility.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONQUESTION = 0x00000020L;
/// @brief An exclamation-point icon appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONEXCLAMATION = 0x00000030L;
/// @brief An exclamation-point icon appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONWARNING = 0x00000030L;
/// @brief An icon consisting of a lowercase letter i in a circle appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONINFORMATION = 0x00000040L;
/// @brief An icon consisting of a lowercase letter i in a circle appears in the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_ICONASTERISK = 0x00000040L;

/// @brief The first button is the default button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_DEFBUTTON1 = 0x00000000L;
/// @brief The second button is the default button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_DEFBUTTON2 = 0x00000100L;
/// @brief The third button is the default button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_DEFBUTTON3 = 0x00000200L;
/// @brief The fourth button is the default button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_DEFBUTTON4 = 0x00000300L;

/// @brief The user must respond to the message box before continuing work in the window identified by the hWnd parameter. However, the user can move to the windows of other threads and work in those windows.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_APPLMODAL = 0x00000000L;
/// @brief Same as MB_APPLMODAL except that the message box has the WS_EX_TOPMOST style. Use system-modal message boxes to notify the user of serious, potentially damaging errors that require immediate attention (for example, running out of memory). This flag has no effect on the user's ability to interact with windows other than those associated with hWnd.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_SYSTEMMODAL = 0x00001000L;
/// @brief Same as MB_APPLMODAL except that all the top-level windows belonging to the current thread are disabled if the hWnd parameter is NULL. Use this flag when the calling application or library does not have a window handle available but still needs to prevent input to other windows in the calling thread without suspending other threads.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_TASKMODAL = 0x00002000L;

/// @brief Adds a Help button to the message box. When the user clicks the Help button or presses F1, the system sends a WM_HELP message to the owner.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_HELP = 0x00004000L;

/// @brief Same as desktop of the interactive window station. For more information, see Window Stations.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_DEFAULT_DESKTOP_ONLY = 0x00020000L;
/// @brief The text is right-justified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_RIGHT = 0x00080000L;
/// @brief Displays message and caption text using right-to-left reading order on Hebrew and Arabic systems.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_RTLREADING = 0x00100000L;
/// @brief The message box becomes the foreground window. Internally, the system calls the SetForegroundWindow function for the message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_SETFOREGROUND = 0x00010000L;
/// @brief The message box is created with the WS_EX_TOPMOST window style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_TOPMOST = 0x00040000L;
/// @brief The caller is a service notifying the user of an event. The function displays a message box on the current active desktop, even if there is no user logged on to the computer.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MB_SERVICE_NOTIFICATION = 0x00200000L;

#endif
