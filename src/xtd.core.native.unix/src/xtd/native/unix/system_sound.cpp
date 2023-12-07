#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/system_sound>
#include <xtd/native/sounds>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <string>
#if defined(__XTD_USE_GSOUND__)
#include <gsound.h>
#endif

using namespace std;
using namespace xtd::native;

void system_sound::play(uint_least32_t sound) {
#if defined(__XTD_USE_GSOUND__)
  static map<uint_least32_t, string> sounds = {{ST_BEEP, "bell-window-system"}, {ST_ICONERROR, "dialog-error"}, {ST_ICONQUESTION, "dialog-question"}, {ST_ICONWARNING, "dialog-warning"}, {ST_ICONINFORMATION, "dialog-information"}, {ST_OK, "bell-window-system"}};
  static GSoundContext* gsound_context = gsound_context_new(nullptr, nullptr);
  gsound_context_play_simple(gsound_context, nullptr, nullptr, GSOUND_ATTR_EVENT_ID, sounds[sound].c_str(), nullptr);
#endif
}
