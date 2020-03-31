/// @file
/// @brief Contains main_form class.
#pragma once
#include "project_type_item_control.h"
#include "project_type_items_control.h"
#include <memory>
#include <vector>
#include <xtd/forms/button.h>
#include <xtd/forms/choice.h>
#include <xtd/forms/form.h>
#include <xtd/forms/label.h>
#include <xtd/forms/list_box.h>
#include <xtd/forms/panel.h>

namespace xtdc_gui {
  /// @brief Represents the main form
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();

    // The main entry point for the application.
    static void main();
    
  private:
    xtd::forms::panel startup_panel_;
    xtd::forms::label startup_title_label_;
    xtd::forms::label open_recent_project_title_label_;
    xtd::forms::list_box open_recent_projects_list_box_;
    xtd::forms::label get_started_title_label_;
    xtd::forms::button open_project_button_;
    xtd::forms::button run_project_button_;
    xtd::forms::button new_project_button_;

    xtd::forms::panel create_panel_;
    xtd::forms::label create_title_label_;
    xtd::forms::label create_recent_project_title_label_;
    xtd::forms::list_box create_recent_projects_list_box_;
    xtd::forms::choice language_choice_;
    xtd::forms::choice platform_choice_;
    xtd::forms::choice type_choice_;
    project_type_items_control project_type_items_control_;

    xtd::forms::panel configure_panel_;
    xtd::forms::label configure_title_label_;
    xtd::forms::label project_type_title_label_;

    xtd::forms::button previous_button_;
    xtd::forms::button next_button_;
    bool auto_close_ = false;
  };
}
