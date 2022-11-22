/// @file
/// @brief Contains __enum_object__ class.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#pragma once

#include "../format_exception.h"
#include "../ustring.h"
#include "../enum_collection.h"
#include "../unused.h"
#include "__enum_register.h"

/// @cond
template<typename enum_t>
struct __enum_object__ {
  __enum_object__(const xtd::ustring& enum_definition) {
    __enum_register__<enum_t> enum_register {enum_definition};
    unused_(enum_register);
  }
};
/// @endcond
