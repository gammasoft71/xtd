#if !defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/system_sound.h>
#include <xtd/native/sounds.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <string>
#include <gsound.h>

using namespace std;
using namespace xtd::native;

void system_sound::play(uint32_t sound) {
  static map<uint32_t, string> sounds = {{ST_BEEP, "bell-window-system"}, {ST_ICONERROR, "dialog-error"}, {ST_ICONQUESTION, "dialog-question"}, {ST_ICONWARNING, "dialog-warning"}, {ST_ICONINFORMATION, "dialog-information"}, {ST_OK, "bell-window-system"}};
  static GSoundContext* gsound_context = gsound_context_new(nullptr, nullptr);
  gsound_context_play_simple(gsound_context, nullptr, nullptr, GSOUND_ATTR_EVENT_ID, sounds[sound].c_str(), nullptr);
}
#endif
