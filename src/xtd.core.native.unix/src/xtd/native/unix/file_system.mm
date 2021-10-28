#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <Foundation/Foundation.h>

using namespace std;
using namespace xtd::native;

#if __APPLE__
int32_t file_system::get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time) {
  NSFileManager *fm = [NSFileManager defaultManager];
  creation_time = std::chrono::system_clock::from_time_t([[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileCreationDate] timeIntervalSince1970]);
  last_access_time = std::chrono::system_clock::from_time_t([[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileModificationDate] timeIntervalSince1970]);
  last_write_time = std::chrono::system_clock::from_time_t([[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileModificationDate] timeIntervalSince1970]);
  return 0;
}
#endif
