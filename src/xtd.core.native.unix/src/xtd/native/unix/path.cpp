#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <unistd.h>
#include <sys/param.h>

using namespace xtd::native;

std::string path::get_temp_path() {
  auto tmp_path = getenv("TMPDIR");
  return tmp_path ? tmp_path : "/tmp/";
}
