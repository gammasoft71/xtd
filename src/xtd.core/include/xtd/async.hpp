/// @file
/// @brief Contains async_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "threading/tasks/task.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
}

#define async_ -> xtd::threading::tasks::task<>
