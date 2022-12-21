#pragma once
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif

#include <cstddef>
// TODO: Documentation

// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/ns-shellapi-notifyicondataa

#if !defined(NIIF_INFO)

// An information icon.
constexpr size_t NIIF_INFO = 0x00000001;

// A warning icon.
constexpr size_t NIIF_WARNING = 0x00000002;

// An error icon.
constexpr size_t NIIF_ERROR = 0x00000003;


#endif
