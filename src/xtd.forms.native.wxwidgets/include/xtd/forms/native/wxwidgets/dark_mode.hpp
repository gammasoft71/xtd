#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types>

bool allow_dark_mode_for_window(xtd::intptr hWnd);
void init_dark_mode(xtd::int32 enableDarkMode);
void refresh_title_bar_theme_color(xtd::intptr hWnd);
