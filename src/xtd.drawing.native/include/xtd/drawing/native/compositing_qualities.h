#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Invalid quality.
static const int32_t CQ_INVALID = -1;
/// @brief Default quality.
static const int32_t CQ_DEFAULT_VALUE = 0;
/// @brief High speed, low quality.
static const int32_t CQ_HIGH_SPEED = 1;
/// @brief High quality, low speed compositing.
static const int32_t CQ_HIGH_QUALITY = 2;
/// @brief Gamma correction is used.
static const int32_t CQ_GAMMA_CORRECTED = 3;
/// @brief Assume linear values.
static const int32_t CQ_ASSUME_LINEAR = 4;
