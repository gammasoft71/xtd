#pragma once

namespace xtdc_gui {
  enum class project_type {
    gui = 0b1,
    console = 0b01,
    shared_library = 0b001,
    static_library = 0b0001,
    unit_tests_project = 0b00001,
    solution_file = 0b000001,
    all = gui|console|shared_library|static_library|unit_tests_project|solution_file,
  };
}
