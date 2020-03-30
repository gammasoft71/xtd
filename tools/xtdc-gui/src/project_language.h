#pragma once

namespace xtdc_gui {
  enum class project_language {
    xtd = 0b1,
    cpp = 0b01,
    c = 0b001,
    csharp = 0b0001,
    objectivec = 0b00001,
    all = xtd|cpp|c|csharp|objectivec,
  };
}
