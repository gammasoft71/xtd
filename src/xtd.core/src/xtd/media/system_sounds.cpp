#include "../../../include/xtd/media/system_sounds.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/sounds.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::media;

system_sound system_sounds::asterisk() {
  return system_sound(ST_ICONASTERISK);
}

system_sound system_sounds::beep() {
  return system_sound(ST_BEEP);
}

system_sound system_sounds::exclamation() {
  return system_sound(ST_ICONEXCLAMATION);
}

system_sound system_sounds::hand() {
  return system_sound(ST_ICONHAND);
}

system_sound system_sounds::question() {
  return system_sound(ST_ICONQUESTION);
}
