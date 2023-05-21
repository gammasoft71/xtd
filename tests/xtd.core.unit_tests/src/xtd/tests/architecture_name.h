#pragma once
#if defined(__amd64__)
#  define __architecture_name__ "x86_64"
#elif defined(__arm__)
#  define __architecture_name__ "arm"
#elif defined(__aarch64__)
#  define __architecture_name__ "arm64"
#elif defined(__i386__)
#  define __architecture_name__ "x86"
#elif defined(__ia64__)
#  define __architecture_name__ "x86_64"
#else
#  define __architecture_name__ "unknown"
#endif
