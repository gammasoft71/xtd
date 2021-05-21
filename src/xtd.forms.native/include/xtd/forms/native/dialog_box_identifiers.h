/// @file
/// @brief Contains dialog box identifiers constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

/// @brief No button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDNONE = 0;
#ifndef IDOK
/// @brief The OK button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDOK = 1;
/// @brief The Cancel button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDCANCEL = 2;
/// @brief The Abort button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDABORT = 3;
/// @brief The Retry button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDRETRY = 4;
/// @brief The Ignore button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDIGNORE = 5;
/// @brief The Yes button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDYES = 6;
/// @brief The No button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDNO = 7;
/// @brief The Close button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDCLOSE = 8;
/// @brief The Help button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDHELP = 9;
/// @brief The Try button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDTRYAGAIN = 10;
/// @brief The Continue button was selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDCONTINUE = 11;
#endif

#ifndef IDTIMEOUT
/// @brief The bWait parameter was TRUE and the time-out interval elapsed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native id
/// @warning Internal use only
constexpr size_t IDTIMEOUT = 32000;
#endif
