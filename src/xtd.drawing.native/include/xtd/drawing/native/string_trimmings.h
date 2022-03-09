#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies no trimming.
static const int32_t ST_NONE = 0;
/// @brief Specifies that the text is trimmed to the nearest character.
static const int32_t ST_CHARACTER = 1;
/// @brief Specifies that text is trimmed to the nearest word.
static const int32_t ST_WORD = 2;
/// @brief Specifies that the text is trimmed to the nearest character, and an ellipsis is inserted at the end of a trimmed line.
static const int32_t ST_ELLIPSIS_CHARACTER = 3;
/// @brief Specifies that text is trimmed to the nearest word, and an ellipsis is inserted at the end of a trimmed line.
static const int32_t ST_ELLIPSIS_WORD = 4;
/// @brief The center is removed from trimmed lines and replaced by an ellipsis. The algorithm keeps as much of the last slash-delimited segment of the line as possible.
static const int32_t ST_ELLIPSIS_PATH = 5;
