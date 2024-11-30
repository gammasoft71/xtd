#include "../../include/xtd/iformatable.hpp"
#include "../../include/xtd/string.hpp"

using namespace xtd;

std::string iformatable::__opague_internal_formatable__(intptr format, intptr loc, intptr, intptr) const {
  return to_string(*reinterpret_cast<const std::string*>(format), *reinterpret_cast<const std::locale*>(loc));
}
