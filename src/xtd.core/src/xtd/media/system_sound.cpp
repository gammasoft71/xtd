#include "../../../include/xtd/media/system_sound.hpp"
#include "../../../include/xtd/is.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/system_sound>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::media;

system_sound::system_sound(uint32 type) : type_(type) {
}

void system_sound::play() const {
  native::system_sound::play(type_);
}

