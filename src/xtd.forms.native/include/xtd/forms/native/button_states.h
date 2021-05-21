/// @file
/// @brief Contains button states flags constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef BST_UNCHECKED
/// @brief Sets the button state to cleared.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t BST_UNCHECKED = 0x0000;
/// @brief Sets the button state to checked.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t BST_CHECKED = 0x0001;
/// @brief Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the BS_3STATE or BS_AUTO3STATE style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t BST_INDETERMINATE = 0x0002;
/// @brief The button is being shown in the pushed state.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @warning Internal use only
/// @brief
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t BST_PUSHED = 0x0004;
/// @brief The button has the keyboard focus.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t BST_FOCUS = 0x0008;

/// @brief he button is in the drop-down state. Applies only if the button has the TBSTYLE_DROPDOWN style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bst
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t BST_DROPDOWNPUSHED = 0x0400;
#endif
