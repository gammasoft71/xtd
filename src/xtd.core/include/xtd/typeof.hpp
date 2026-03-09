/// @file
/// @brief Contains #typeof_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "type_of.hpp"

/// @brief Used to obtain the type object of a specified type or object.
/// @return THe xtd::type_object that represent the type or the object.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// ```cpp
/// // Get the type object of a type :
/// xtd::type_object type1 = typeof_<int>();
///
/// int i = 42;
/// // Get the type object of an object :
/// xtd::type_object type2 = typeof_(i);
/// ```
/// @remarks The typeof_ operator cannot be overloaded.
#define typeof_ \
xtd::type_of
