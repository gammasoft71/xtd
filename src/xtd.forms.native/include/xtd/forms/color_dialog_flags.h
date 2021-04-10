/// @file
/// @brief Contains arranged color dialog flags constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

#if !defined(CC_RGBINIT)
/// @brief Causes the dialog box to use the color specified in the rgbResult member as the initial color selection.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_RGBINIT = 0x00000001;
/// @brief Causes the dialog box to display the additional controls that allow the user to create custom colors. If this flag is not set, the user must click the Define Custom Color button to display the custom color controls.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_FULLOPEN = 0x00000002;
/// @brief Disables the Define Custom Color button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_PREVENTFULLOPEN = 0x00000004;
/// @brief Causes the dialog box to display the Help button. The hwndOwner member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the Help button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_SHOWHELP = 0x00000008;
/// @brief Enables the hook procedure specified in the lpfnHook member of this structure. This flag is used only to initialize the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_ENABLEHOOK = 0x00000010;
/// @brief The hInstance and lpTemplateName members specify a dialog box template to use in place of the default template. This flag is used only to initialize the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_ENABLETEMPLATE = 0x00000020;
/// @brief The hInstance member identifies a data block that contains a preloaded dialog box template. The system ignores the lpTemplateName member if this flag is specified. This flag is used only to initialize the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_ENABLETEMPLATEHANDLE = 0x00000040;
/// @brief Causes the dialog box to display only solid colors in the set of basic colors.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_SOLIDCOLOR = 0x00000080;
/// @brief Causes the dialog box to display all available colors in the set of basic colors.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_ANYCOLOR = 0x00000100;
#endif
/// @brief Causes the dialog box to display alpha colors in the set of basic colors.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CC_ALPHACOLOR = 0x00000200;
