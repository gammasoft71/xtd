/// @file
/// @brief Contains #async_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "threading/tasks/task.hpp"

#define async_ \
  -> xtd::threading::tasks::task<>
