#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__iformatable_formatter.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/object.h"
#include "../../../include/xtd/string.h"

std::string __to_string_object_to_string(const xtd::object* obj) {
  return obj->to_string();
}

std::string __to_string_istringable_to_string(const xtd::istringable* obj) {
  return obj->to_string();
}
