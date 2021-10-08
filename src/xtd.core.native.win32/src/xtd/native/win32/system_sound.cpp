#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/system_sound.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace xtd::native;

#undef max
#undef min

void system_sound::play(uint32_t sound) {
  MessageBeep(sound);
}
