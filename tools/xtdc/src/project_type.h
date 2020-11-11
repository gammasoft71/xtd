#pragma once

namespace xtdc_command {
  enum class project_type {
    unknown,
    blank_solution,
    console,
    gui,
    shared_library,
    static_library,
    unit_test_application
  };
}
