#pragma once
#ifdef HAVE_UNISTD_H // needed for _POSIX_VERSION (see https://www.gnu.org/software/autoconf/manual/autoconf-2.64/html_node/Particular-Headers.html#index-g_t_005fPOSIX_005fVERSION-585)
#  include <unistd.h>
#endif

#if defined(_WIN32)
#  define __platform_name__ "Microsoft Windows"
#elif defined(__APPLE__)
#  include <TargetConditionals.h>
#  if TARGET_OS_WIN32 != 0
#    define __platform_name__ "WIN32 API"
#  elif TARGET_OS_WINDOWS != 0
#    define __platform_name__ "Windows"
#  elif TARGET_OS_UNIX != 0
#    define __platform_name__ "Unix"
#  elif TARGET_OS_LINUX != 0
#    define __platform_name__ "Linux"
#  elif TARGET_OS_MAC != 0
#    if TARGET_OS_OSX != 0
#      define __platform_name__ "macOS"
#    elif TARGET_OS_IPHONE != 0
#      if TARGET_OS_IOS
#        define __platform_name__ "iOS"
#      elif TARGET_OS_TV != 0
#        define __platform_name__ "tvOS"
#      elif TARGET_OS_WATCH != 0
#        define __platform_name__ "watchOS"
#      elif TARGET_OS_BRIDGE != 0
#        define __platform_name__ "Bridge device"
#      elif TARGET_OS_MACCATALYST != 0
#        define __platform_name__ "Catalyst macOS"
#      else
#        error "Unknown iPhone platform"
#      endif
#    elif TARGET_OS_DRIVERKIT != 0
#      define __platform_name__ "macOS, iOS, tvOS, or watchOS"
#    elif TARGET_IPHONE_SIMULATOR != 0
#      define __platform_name__ "iPhone Simulator"
#    else
#      error "Unknown Apple platform"
#    endif
#  else
#    error "Unknown target"
#  endif
#elif defined(__ANDROID__)
#  define __platform_name__ "Android"
#elif defined(__linux__)
#  define __platform_name__ "Linux"
#elif defined(__unix__)
#  define __platform_name__ "Unix"
#elif defined(_POSIX_VERSION)
#  define __platform_name__ "Posix"
#else
#  error "Unknown platform"
#endif
