/// @file
/// @brief Contains __enum_definition_to_enum_collection__ method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#pragma once
#include "../format_exception.h"
#include "../types.h"
#include "../ustring.h"
#include "../enum_collection.h"

/// @cond
template<typename enum_t>
xtd::enum_collection<enum_t> __enum_definition_to_enum_collection__(const xtd::ustring& enum_definition) {
  xtd::enum_collection<enum_t> entries;
  #if !defined(__XTD_DO_NOT_USE_ENUMERATION_INTROSPECTION__)
  for (size_t num_state = 0; num_state < __enumeration_introspection::num_states<enum_t>; ++num_state)
    entries.emplace_back(static_cast<enum_t>(__enumeration_introspection::enum_values<enum_t>[num_state]), __enumeration_introspection::enum_names<enum_t>[num_state]);
  #else
  using namespace xtd;
  if (enum_definition.empty()) return entries;
  xtd::int64 current_value = 0;
  for (auto entry : enum_definition.split({','})) {
    auto key_value = entry.trim().split({'='});
    if (key_value.size() < 1 || key_value.size() > 2 || (key_value.size() == 2 && xtd::ustring::is_empty(key_value[1])))
      throw xtd::format_exception("Not a valid enum declaration"_t, csf_);
    xtd::int64 value = current_value;
    if (key_value.size() == 2) {
      if (!xtd::try_parse<xtd::int64>(key_value[1].trim(), value, xtd::number_styles::number) && xtd::try_parse<xtd::int64>(key_value[1].trim(), value, xtd::number_styles::hex_number) && xtd::try_parse<xtd::int64>(key_value[1].trim(), value, xtd::number_styles::binary_number) && xtd::try_parse<xtd::int64>(key_value[1].trim(), value, xtd::number_styles::octal_number)) {
        auto iterator = std::find_if(entries.begin(), entries.end(), [&](auto item)->bool {return item.second == key_value[1].trim();});
        if (iterator != entries.end()) value = static_cast<xtd::int64>(iterator->first);
    
        /// @todo Add parse arithmetic operation...
        throw xtd::format_exception("Not a valid enum declaration"_t, csf_);
      }
    }
    current_value = value;
    entries.emplace_back(static_cast<enum_t>(value), key_value[0].trim());
    current_value++;
  }
  #endif
  return entries;
}
/// @endcond
