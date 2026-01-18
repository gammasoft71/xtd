#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__iformatable_formatter.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/iformatable.hpp"
#include "../../../include/xtd/object.hpp"
#include "../../../include/xtd/string.hpp"

auto __to_string_iformatable_to_string(const xtd::iformatable* obj, const std::string& format, const std::locale& loc) -> std::string {
  return obj->to_string(format, loc);
}

auto __to_string_object_to_string(const xtd::object* obj) -> std::string {
  return obj->to_string();
}
