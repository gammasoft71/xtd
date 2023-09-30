#include "../../../include/xtd/media/system_sound.h"
#include "../../../include/xtd/is.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/system_sound>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::media;

system_sound::system_sound(uint32 type) : type_(type) {
}

bool system_sound::equals(const system_sound& sound) const noexcept {
  return type_ == sound.type_;
}

void system_sound::play() const {
  native::system_sound::play(type_);
}

