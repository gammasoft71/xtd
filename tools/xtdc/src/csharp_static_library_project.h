#pragma once
#include "csharp_shared_library_project.h"

namespace xtdc_command {
  // There is no static library in csharp.
  using csharp_static_library_project = csharp_shared_library_project;
}
