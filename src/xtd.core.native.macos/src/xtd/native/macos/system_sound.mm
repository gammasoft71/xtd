#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/sounds>
#include <xtd/native/system_sound>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <string>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>

using namespace std;
using namespace xtd::native;

void system_sound::play(uint_least32_t sound) {
  if (sound == ST_BEEP || sound == ST_OK) NSBeep();
  else @autoreleasepool {
    static auto sounds = map<uint_least32_t, string> {{ST_ICONERROR, "Funk"}, {ST_ICONQUESTION, "Purr"}, {ST_ICONWARNING, "Hero"}, {ST_ICONASTERISK, "Glass"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:sounds[sound].c_str()]] play];
  }
}
