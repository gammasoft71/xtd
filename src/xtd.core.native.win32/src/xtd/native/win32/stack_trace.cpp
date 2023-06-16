#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd::native;

stack_trace::frames stack_trace::get_frames(size_t skip_frames, size_t max_frames) {
  return {};
}
