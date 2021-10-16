#if defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/sounds.h>
#include <xtd/native/system_sound.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <string>
#include <TargetConditionals.h>

#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
#import <Cocoa/Cocoa.h>
#endif

using namespace std;
using namespace xtd::native;

void system_sound::play(uint32_t sound) {
#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
  if (sound == ST_BEEP || sound == ST_OK)
    NSBeep();
  else {
    static map<uint32_t, string> sounds = {{ST_ICONERROR, "Funk"}, {ST_ICONQUESTION, "Purr"}, {ST_ICONWARNING, "Hero"}, {ST_ICONASTERISK, "Glass"}};
    @autoreleasepool {
      [[NSSound soundNamed:[NSString stringWithUTF8String:sounds[sound].c_str()]] play];
    }
  }
#else
  /// @todo iOS : Find how to play sound...
#endif
}
#endif
