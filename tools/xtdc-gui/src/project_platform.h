#pragma once

namespace xtdc_gui {
  enum class project_platform {
    windows = 0b1,
    linux = 0b01,
    macos = 0b001,
    all = windows|linux|macos,
  };
}
