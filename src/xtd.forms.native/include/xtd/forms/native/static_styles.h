/// @file
/// @brief Contains progress bar styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

// https://docs.microsoft.com/en-us/cpp/mfc/reference/styles-used-by-mfc

#ifndef SS_LEFT
/// @brief Designates a simple rectangle and displays the given text flush-left in the rectangle. The text is formatted before it is displayed. Words that would extend past the end of a line are automatically wrapped to the beginning of the next flush-left line.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_LEFT = 0x00000000;
/// @brief Designates a simple rectangle and displays the given text centered in the rectangle. The text is formatted before it is displayed. Words that would extend past the end of a line are automatically wrapped to the beginning of the next centered line.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_CENTER = 0x00000001;
/// @brief Designates a simple rectangle and displays the given text flush-right in the rectangle. The text is formatted before it is displayed. Words that would extend past the end of a line are automatically wrapped to the beginning of the next flush-right line.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_RIGHT = 0x00000002;
/// @brief Designates an icon displayed in the dialog box. The given text is the name of an icon (not a filename) defined elsewhere in the resource file. The nWidth and nHeight parameters are ignored; the icon automatically sizes itself.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_ICON = 0x00000003;
/// @brief Specifies a rectangle filled with the color used to draw window frames. The default is black.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_BLACKRECT = 0x00000004;
/// @brief Specifies a rectangle filled with the color used to fill the screen background. The default is gray.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_GRAYRECT = 0x00000005;
/// @brief Specifies a rectangle filled with the color used to fill the window background. The default is white.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_WHITERECT = 0x00000006;
/// @brief Specifies a box with a frame drawn with the same color as window frames. The default is black.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_BLACKFRAME = 0x00000007;
/// @brief Specifies a box with a frame drawn with the same color as the screen background (desktop). The default is gray.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_GRAYFRAME = 0x00000008;
/// @brief Specifies a box with a frame drawn with the same color as the window background. The default is white.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_WHITEFRAME = 0x00000009;
/// @brief Specifies a user-defined item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_USERITEM = 0x0000000A;
/// @brief Designates a simple rectangle and displays a single line of text flush-left in the rectangle. The line of text cannot be shortened or altered in any way. (The control's parent window or dialog box must not process the WM_CTLCOLOR message.)
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_SIMPLE = 0x0000000B;
/// @brief Designates a simple rectangle and displays the given text flush-left in the rectangle. Tabs are expanded, but words are not wrapped. Text that extends past the end of a line is clipped.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_LEFTNOWORDWRAP = 0x0000000C;
/// @brief Specifies that the owner of the static control is responsible for drawing the control. The owner window receives a WM_DRAWITEM message whenever the control needs to be drawn.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_OWNERDRAW = 0x0000000D;
/// @brief Specifies a bitmap is to be displayed in the static control. The given text is the name of a bitmap (not a filename) defined elsewhere in the resource file. The style ignores the nWidth and nHeight parameters; the control automatically sizes itself to accommodate the bitmap.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_BITMAP = 0x0000000E;
/// @brief Specifies an enhanced metafile is to be displayed in the static control. The given text is the name of a metafile. An enhanced metafile static control has a fixed size; the metafile is scaled to fit the static control's client area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_ENHMETAFILE = 0x0000000F;
/// @brief Draws the top and bottom edges of the static control using the EDGE_ETCHED edge style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_ETCHEDHORZ = 0x00000010;
/// @brief Draws the left and right edges of the static control using the EDGE_ETCHED edge style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_ETCHEDVERT = 0x00000011;
/// @brief Draws the frame of the static control using the EDGE_ETCHED edge style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_ETCHEDFRAME = 0x00000012;
/// @brief A composite style bit that results from using the OR operator on SS_* style bits. Can be used to mask out valid SS_* bits from a given bitmask. Note that this is out of date and does not correctly include all valid styles. Thus, you should not use this style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_TYPEMASK = 0x0000001F;
/// @brief Adjusts the bitmap to fit the size of the static control. For example, changing the locale can change the system font, and thus controls might be resized. If a static control had a bitmap, the bitmap would no longer fit the control. This style bit dictates automatic redimensioning of bitmaps to fit their controls.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_REALSIZECONTROL = 0x00000040;
/// @brief Unless this style is specified, Windows will interpret any ampersand (&) characters in the control's text to be accelerator prefix characters. In this case, the ampersand is removed and the next character in the string is underlined. If a static control is to contain text where this feature is not wanted, SS_NOPREFIX may be added. This static-control style may be included with any of the defined static controls. You can combine SS_NOPREFIX with other styles by using the bitwise OR operator. This is most often used when filenames or other strings that may contain an ampersand need to be displayed in a static control in a dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_NOPREFIX = 0x00000080; // Don't do "&" character translation
/// @brief Sends the parent window STN_CLICKED, STN_DBLCLK, STN_DISABLE, and STN_ENABLE notification messages when the user clicks or double-clicks the control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_NOTIFY = 0x00000100;
/// @brief Specifies that, if the bitmap or icon is smaller than the client area of the static control, the rest of the client area is filled with the color of the pixel in the top left corner of the bitmap or icon. If the static control contains a single line of text, the text is centered vertically in the client area of the control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_CENTERIMAGE = 0x00000200;
/// @brief Specifies that the lower right corner of a static control with the SS_BITMAP or SS_ICON style is to remain fixed when the control is resized. Only the top and left sides are adjusted to accommodate a new bitmap or icon.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_RIGHTJUST = 0x00000400;
/// @brief Prevents a static icon or bitmap control (that is, static controls that have the SS_ICON or SS_BITMAP style) from being resized as it is loaded or drawn. If the icon or bitmap is larger than the destination area, the image is clipped.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_REALSIZEIMAGE = 0x00000800;
/// @brief Draws a half-sunken border around a static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_SUNKEN = 0x00001000;
/// @brief The static control duplicates the text-displaying characteristics of a multiline edit control. Specifically, the average character width is calculated in the same manner as with an edit control, and the function does not display a partially visible last line.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_EDITCONTROL = 0x00002000;
/// @brief If the end of a string does not fit in the rectangle, it is truncated and ellipses are added. If a word that is not at the end of the string goes beyond the limits of the rectangle, it is truncated without ellipses. Using this style will force the control s text to be on one line with no word wrap. Compare with SS_PATHELLIPSIS and SS_WORDELLIPSIS.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_ENDELLIPSIS = 0x00004000;
/// @brief Replaces characters in the middle of the string with ellipses so that the result fits in the specified rectangle. If the string contains backslash () characters, SS_PATHELLIPSIS preserves as much as possible of the text after the last backslash. Using this style will force the control s text to be on one line with no word wrap. Compare with SS_ENDELLIPSIS and SS_WORDELLIPSIS.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_PATHELLIPSIS = 0x00008000;
/// @brief Truncates any word that does not fit in the rectangle and adds ellipses. Using this style will force the control s text to be on one line with no word wrap.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SS_WORDELLIPSIS = 0x0000C000;
/// @cond
constexpr size_t SS_ELLIPSISMASK = 0x0000C000;
/// @endcond
#endif
/// @brief Designates a simple rectangle and displays the given text flush-top in the rectangle.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_TOP = 0x00000000;
/// @brief Designates a simple rectangle and displays the given text vertical centered in the rectangle.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_VCENTER = 0x00010000;
/// @brief Designates a simple rectangle and displays the given text flush-bottom in the rectangle.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_BOTTOM = 0x00020000;
/// @brief Specifies a normal bitmap is to be displayed in the static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_BITMAP_NORMAL = 0x00000000;
/// @brief Specifies a stretched bitmap is to be displayed in the static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_BITMAP_STRETCH = 0x00040000;
/// @brief Specifies an auto-sized bitmap to be displayed in the static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_BITMAP_AUTOSIZE = 0x00080000;
/// @brief Specifies a centered bitmap is to be displayed in the static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_BITMAP_CENTER = 0x000C0000;
/// @brief Specifies a zoomed bitmap is to be displayed in the static control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ss
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SS_BITMAP_ZOOM = 0x00100000;
