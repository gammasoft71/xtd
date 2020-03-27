/// @file
/// @brief Contains main_form class.
#pragma once
#include <xtd/forms/form.h>

namespace xtdc_gui {
  /// @brief Represents the main form
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();

    // The main entry point for the application.
    static void main();
  };
}
