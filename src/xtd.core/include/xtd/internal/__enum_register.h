/// @file
/// @brief Contains __enum_register__ class.
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

/// @cond
template<typename enum_t>
struct __enum_object__;
template<typename enum_t = std::nullptr_t>
class __enum_register__ {
public:
  __enum_register__() = default;
  explicit __enum_register__(const xtd::ustring& enum_definition) {
    enum_definition_ = enum_definition;
  }
  
  const xtd::ustring& enum_definition() {
    return enum_definition_;
  }
  
  explicit operator auto() const {
    xtd::enum_collection<enum_t> entries;
    if (enum_definition_.empty()) return entries;
    int64_t current_value = 0;
    if (enum_definition_.index_of('{') == enum_definition_.npos || enum_definition_.index_of('}') == enum_definition_.npos) throw xtd::format_exception("Not a valid enum declaration", csf_);
    for (auto entry : enum_definition_.substring(enum_definition_.index_of('{')).replace('{', ' ').replace('}', ' ').trim().split({','})) {
      auto key_value = entry.trim().split({'='});
      if (key_value.size() < 1 || key_value.size() > 2 || (key_value.size() == 2 && xtd::ustring::is_empty(key_value[1])))
        throw xtd::format_exception("Not a valid enum declaration", csf_);
      int64_t value = current_value;
      if (key_value.size() == 2) {
        if (!xtd::try_parse<int64_t>(key_value[1].trim(), value) && xtd::try_parse<int64_t>(key_value[1].trim(), value, xtd::number_styles::hex_number) && xtd::try_parse<int64_t>(key_value[1].trim(), value, xtd::number_styles::binary_number) && xtd::try_parse<int64_t>(key_value[1].trim(), value, xtd::number_styles::octal_number)) {
          auto iterator = std::find_if(entries.begin(), entries.end(), [&](auto item)->bool {return item.second == key_value[1].trim();});
          if (iterator != entries.end()) value = static_cast<int64_t>(iterator->first);
          
          /// @todo Add parse arithmetic operation...
          throw xtd::format_exception("Not a valid enum declaration", csf_);
        }
      }
      current_value = value;
      entries.push_back({static_cast<enum_t>(value), key_value[0].trim()});
      current_value++;
    }
    
    return entries;
  }
  
private:
  template<typename enum_type>
  friend struct __enum_object__;
  inline static xtd::ustring enum_definition_;
};
/// @endcond
