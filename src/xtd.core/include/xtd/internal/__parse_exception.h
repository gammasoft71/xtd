/// @file
/// @brief Contains throw parse exception methods.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <string>

/// @cond
void __throw_parse_formatt_exception(const std::string& message);
void __throw_parse_index_out_of_range_exception();
/// @endcond
