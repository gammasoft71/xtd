/// @file
/// @brief Contains C++ exceptions check.
#pragma once

/// @cond
#if !defined(__cpp_exceptions)
#  if defined(_MSC_VER)
#    error "xtd requires C++ exceptions support. Please enable exceptions in your compiler (do not use /EHs-c-)."
#  else
#    error "xtd requires C++ exceptions support. Please enable exceptions in your compiler (do not use -fno-exceptions)."
#  endif
#endif
/// @endcond
