#include "../../../include/xtd/media/system_sounds.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/sounds>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::media;

auto system_sounds::asterisk() -> system_sound {
  return system_sound {ST_ICONASTERISK};
}

auto system_sounds::beep() -> system_sound {
  return system_sound {ST_BEEP};
}

auto system_sounds::exclamation() -> system_sound {
  return system_sound {ST_ICONEXCLAMATION};
}

auto system_sounds::hand() -> system_sound {
  return system_sound {ST_ICONHAND};
}

auto system_sounds::question() -> system_sound {
  return system_sound {ST_ICONQUESTION};
}
