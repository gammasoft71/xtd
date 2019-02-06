#pragma once
#if defined(WIN32)
#  if defined(CONSOLE_EXPORT)
#    define console_export_ __declspec(dllexport)
#  else
#    define console_export_ __declspec(dllimport)
#  endif
#else
#  if defined(CONSOLE_EXPORT)
#    define console_export_ __attribute__((visibility ("default")))
#  else
#    define console_export_
#  endif
#endif
