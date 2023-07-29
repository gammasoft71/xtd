#include <algorithm>
#include <numeric>
#include <random>
#include <uuid/uuid.h>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

std::vector<uint8_t> guid::new_guid() {
  std::vector<uint8_t> guid(16);
  uuid_generate(guid.data());
  return guid;
}
