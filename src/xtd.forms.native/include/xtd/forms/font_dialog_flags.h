/// @file
/// @brief Contains font dialog flags constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

#if !defined(CF_SCREENFONTS)
/// @brief Causes the dialog box to list only the screen fonts supported by the system.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_SCREENFONTS = 0x00000001;
/// @brief Causes the dialog box to list only the fonts supported by the printer associated with the device context or information context identified by the hDC member. It also causes the font type description label to appear at the bottom of the Font dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_PRINTERFONTS = 0x00000002;
/// @brief Causes the dialog box to list the available printer and screen fonts. The hDC member is a handle to the device context or information context associated with the printer. This flag is a combination of the CF_SCREENFONTS and CF_PRINTERFONTS flags.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_BOTH = (CF_SCREENFONTS | CF_PRINTERFONTS);
/// @brief Causes the dialog box to display the Help button. The hwndOwner member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the Help button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_SHOWHELP = 0x00000004L;
/// @brief Enables the hook procedure specified in the lpfnHook member of this structure.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_ENABLEHOOK = 0x00000008L;
/// @brief Indicates that the hInstance and lpTemplateName members specify a dialog box template to use in place of the default template.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_ENABLETEMPLATE = 0x00000010L;
/// @brief Indicates that the hInstance member identifies a data block that contains a preloaded dialog box template. The system ignores the lpTemplateName member if this flag is specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_ENABLETEMPLATEHANDLE = 0x00000020L;
/// @brief ChooseFont should use the structure pointed to by the lpLogFont member to initialize the dialog box controls.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_INITTOLOGFONTSTRUCT = 0x00000040L;
/// @brief The lpszStyle member is a pointer to a buffer that contains style data that ChooseFont should use to initialize the Font Style combo box. When the user closes the dialog box, ChooseFont copies style data for the user's selection to this buffer.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_USESTYLE = 0x00000080L;
/// @brief Causes the dialog box to display the controls that allow the user to specify strikeout, underline, and text color options. If this flag is set, you can use the rgbColors member to specify the initial text color. You can use the lfStrikeOut and lfUnderline members of the structure pointed to by lpLogFont to specify the initial settings of the strikeout and underline check boxes. ChooseFont can use these members to return the user's selections.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_EFFECTS = 0x00000100L;
/// @brief Causes the dialog box to display the Apply button. You should provide a hook procedure to process WM_COMMAND messages for the Apply button. The hook procedure can send the WM_CHOOSEFONT_GETLOGFONT message to the dialog box to retrieve the address of the structure that contains the current selections for the font.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_APPLY = 0x00000200L;
/// @brief This flag is obsolete. To limit font selections to all scripts except those that use the OEM or Symbol character sets, use CF_SCRIPTSONLY. To get the original CF_ANSIONLY behavior, use CF_SELECTSCRIPT and specify ANSI_CHARSET in the lfCharSet member of the LOGFONT structure pointed to by lpLogFont.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_ANSIONLY = 0x00000400L;
/// @brief ChooseFont should allow selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set. This supersedes the CF_ANSIONLY value.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_SCRIPTSONLY = CF_ANSIONLY;
/// @brief ChooseFont should not allow vector font selections.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOVECTORFONTS = 0x00000800L;
/// @brief Same as the CF_NOVECTORFONTS flag.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOOEMFONTS = CF_NOVECTORFONTS;
/// @brief ChooseFont should not display or allow selection of font simulations.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOSIMULATIONS = 0x00001000L;
/// @brief ChooseFont should select only font sizes within the range specified by the nSizeMin and nSizeMax members.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_LIMITSIZE = 0x00002000L;
/// @brief ChooseFont should enumerate and allow selection of only fixed-pitch fonts.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_FIXEDPITCHONLY = 0x00004000L;
/// @brief ChooseFont should allow only the selection of fonts available on both the printer and the display. If this flag is specified, the CF_SCREENSHOTS and CF_PRINTERFONTS, or CF_BOTH flags should also be specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_WYSIWYG = 0x00008000L; // must also have CF_SCREENFONTS & CF_PRINTERFONTS
/// @brief ChooseFont should indicate an error condition if the user attempts to select a font or style that is not listed in the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_FORCEFONTEXIST = 0x00010000L;
/// @brief Specifies that ChooseFont should allow only the selection of scalable fonts. Scalable fonts include vector fonts, scalable printer fonts, TrueType fonts, and fonts scaled by other technologies.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_SCALABLEONLY = 0x00020000L;
/// @brief ChooseFont should only enumerate and allow the selection of TrueType fonts.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_TTONLY = 0x00040000L;
/// @brief When using a LOGFONT structure to initialize the dialog box controls, use this flag to prevent the dialog box from displaying an initial selection for the font name combo box. This is useful when there is no single font name that applies to the text selection.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOFACESEL = 0x00080000L;
/// @brief When using a LOGFONT structure to initialize the dialog box controls, use this flag to prevent the dialog box from displaying an initial selection for the Font Style combo box. This is useful when there is no single font style that applies to the text selection.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOSTYLESEL = 0x00100000L;
/// @brief When using a structure to initialize the dialog box controls, use this flag to prevent the dialog box from displaying an initial selection for the Font Size combo box. This is useful when there is no single font size that applies to the text selection.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOSIZESEL = 0x00200000L;
/// @brief When specified on input, only fonts with the character set identified in the lfCharSet member of the LOGFONT structure are displayed. The user will not be allowed to change the character set specified in the Scripts combo box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_SELECTSCRIPT = 0x00400000L;
/// @brief Disables the Script combo box. When this flag is set, the lfCharSet member of the LOGFONT structure is set to DEFAULT_CHARSET when ChooseFont returns. This flag is used only to initialize the dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOSCRIPTSEL = 0x00800000L;
/// @brief Causes the Font dialog box to list only horizontally oriented fonts.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_NOVERTFONTS = 0x01000000L;
/// @brief ChooseFont should additionally display fonts that are set to Hide in Fonts Control Panel.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t CF_INACTIVEFONTS = 0x02000000L;
#endif
