#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
#include <numeric>
#include <random>
#include <uuid/uuid.h>

using namespace xtd::native;

std::vector<uint_least8_t> guid::new_guid() {
  auto guid = std::vector<uint_least8_t>(16);
  uuid_generate(guid.data());
  return guid;
}
