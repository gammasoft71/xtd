/// @file
/// @brief Contains #abstract_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "abstract_object.hpp"

/// @brief This keyword is used to represents an abstract class.
/// @par Header
/// ```cpp
/// #include <xtd/abstract>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// ```cpp
/// class foo abstract_ {
/// public:
///   virtual xtd::string to_string() = 0;
/// };
/// ```
/// @remarks This keyword has no other use than to tag a class to abstract.
#define abstract_ \
  : public xtd::abstract_object
