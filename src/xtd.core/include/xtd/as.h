/// @file
/// @brief Contains xtd::as method.
#pragma once
#include "any.h"
#include "invalid_cast_exception.h"
#include "types.h"
#include <memory>
#define __XTD_CORE_INTERNAL__
#include "internal/__as_enum.h"
#include "internal/__as_generic.h"
#undef __XTD_CORE_INTERNAL__
#include "convert.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_bool.h"
#include "internal/__as_byte.h"
#include "internal/__as_char.h"
#include "internal/__as_char8.h"
#include "internal/__as_char16.h"
#include "internal/__as_char32.h"
#include "internal/__as_decimal.h"
#include "internal/__as_double.h"
#include "internal/__as_float.h"
#include "internal/__as_int16.h"
#include "internal/__as_int32.h"
#include "internal/__as_int64.h"
#include "internal/__as_sbyte.h"
#include "internal/__as_slong.h"
#include "internal/__as_string.h"
#include "internal/__as_uint16.h"
#include "internal/__as_uint32.h"
#include "internal/__as_uint64.h"
#include "internal/__as_ulong.h"
#include "internal/__as_wchar.h"
#undef __XTD_CORE_INTERNAL__
#include "convert_pointer.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_pointer.h"
#undef __XTD_CORE_INTERNAL__
#include "convert_string.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_std_string.h"
#undef __XTD_CORE_INTERNAL__
#include "any_object.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_any_object.h"
#undef __XTD_CORE_INTERNAL__

/// @cond
template<typename new_type_t, typename current_type_t>
new_type_t* __convert_value__(current_type_t* value) {
  return xtd::as<new_type_t>(value);
}
/// @endcond
