/// @file
/// @brief Contains system_report class
#pragma once
#include <string>
#include "export.h"

namespace xtd {
  class export_ system_report {
  public:
    system_report() = default;
    
    std::string to_string() const;
  };
}
