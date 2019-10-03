#pragma once

#include <cstdint>

#if !defined(CC_RGBINIT)
constexpr size_t CC_RGBINIT = 0x00000001;
constexpr size_t CC_FULLOPEN = 0x00000002;
constexpr size_t CC_PREVENTFULLOPEN = 0x00000004;
constexpr size_t CC_SHOWHELP = 0x00000008;
constexpr size_t CC_ENABLEHOOK = 0x00000010;
constexpr size_t CC_ENABLETEMPLATE = 0x00000020;
constexpr size_t CC_ENABLETEMPLATEHANDLE = 0x00000040;
constexpr size_t CC_SOLIDCOLOR = 0x00000080;
constexpr size_t CC_ANYCOLOR = 0x00000100;
#endif
constexpr size_t CC_ALPHACOLOR = 0x00000200;
