/// @file
/// @brief Contains progress dialog flags constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

#if !defined(PROGDLG_NORMAL)
/// @brief Normal progress dialog box behavior.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_NORMAL = 0x00000000;
/// @brief The progress dialog box will be modal to the window specified by hwndParent. By default, a progress dialog box is modeless.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_MODAL = 0x00000001;
/// @brief Automatically estimate the remaining time and display the estimate on line 3. If this flag is set, IProgressDialog::SetLine can be used only to display text on lines 1 and 2.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_AUTOTIME = 0x00000002;
/// @brief Do not show the "time remaining" text.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_NOTIME = 0x00000004;
/// @brief Do not display a minimize button on the dialog box's caption bar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_NOMINIMIZE = 0x00000008;
/// @brief Do not display a progress bar. Typically, an application can quantitatively determine how much of the operation remains and periodically pass that value to IProgressDialog::SetProgress. The progress dialog box uses this information to update its progress bar. This flag is typically set when the calling application must wait for an operation to finish, but does not have any quantitative information it can use to update the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_NOPROGRESSBAR = 0x00000010;
/// @brief Sets the progress bar to marquee mode. This causes the progress bar to scroll horizontally, similar to a marquee display. Use this when you wish to indicate that progress is being made, but the time required for the operation is unknown.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_MARQUEEPROGRESS = 0x00000020;
/// @brief Do not display a cancel button. The operation cannot be canceled. Use this only when absolutely necessary.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PROGDLG_NOCANCEL = 0x00000040;
#endif
/// @brief Do not shows "Skip" button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t PROGDLG_NOSKIP = 0x00000080;
/// @brief Increasing the size of a smooth.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t PROGDLG_SMOOTH = 0x00000100;
/// @brief Increasing the size of a reverse smooth.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t PROGDLG_SMOOTH_REVERSE = 0x00000200;
/// @brief Shows the "elapsed time" text.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t PROGDLG_ELAPSEDTIME = 0x00000400;
/// @brief Shows the "estimated time" text.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native progdlg
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t PROGDLG_ESTIMATEDTIME = 0x00000800;
