#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <direct.h>
#include <shlobj.h>
#include <windows.h>
#include <Lmcons.h>

using namespace xtd::native;

#undef min
#undef max

std::vector<uint8_t> guid::new_guid() {
  UUID guid {};
  UuidCreate(&guid);
  return {reinterpret_cast<uint8_t*>(&guid), reinterpret_cast<uint8_t*>(&guid) + 16};
}
