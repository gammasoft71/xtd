#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#include <xtd/native/path.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <dirent.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/stat.h>
#import <Foundation/Foundation.h>

using namespace std;
using namespace xtd::native;

#if __APPLE__
int32_t directory::get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time) {
  NSFileManager *fm = [NSFileManager defaultManager];
  creation_time = std::chrono::system_clock::from_time_t([[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileCreationDate] timeIntervalSince1970]);
  last_access_time = std::chrono::system_clock::from_time_t([[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileModificationDate] timeIntervalSince1970]);
  last_write_time = std::chrono::system_clock::from_time_t([[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileModificationDate] timeIntervalSince1970]);
  return 0;
}
#endif
