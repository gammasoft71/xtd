/// @file
/// @brief Contains C++ RTTI check.
#pragma once

/// @cond
#if !defined(__GXX_RTTI) && !defined(_CPPRTTI)
#  if defined(_MSC_VER)
#    error "xtd requires RTTI support. Please enable RTTI (do not use /GR-)."
#  else
#    error "xtd requires RTTI support. Please enable RTTI (do not use -fno-rtti)."
#  endif
#endif
/// @endcond
