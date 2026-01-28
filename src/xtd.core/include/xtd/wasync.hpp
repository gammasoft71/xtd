/// @file
/// @brief Contains wasync_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "threading/tasks/wtask.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
}

#define wasync_ -> xtd::threading::tasks::wtask<>
