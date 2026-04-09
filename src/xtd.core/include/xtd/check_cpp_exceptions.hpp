/// @file
/// @brief Contains C++ exceptions check.
#pragma once

/// @cond
#if !defined(__cpp_exceptions)
#  error "xtd requires C++ exceptions support. Please enable exceptions in your compiler (do not use -fno-exceptions)."
#endif
/// @endcond
