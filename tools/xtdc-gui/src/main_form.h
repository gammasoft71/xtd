/// @file
/// @brief Contains main_form class.
#pragma once
#include "project_type_item_control.h"
#include "project_type_items_control.h"
#include "xtd_example_item.h"
#include <memory>
#include <vector>
#include <xtd/forms/button.h>
#include <xtd/forms/check_box.h>
#include <xtd/forms/choice.h>
#include <xtd/forms/form.h>
#include <xtd/forms/label.h>
#include <xtd/forms/list_box.h>
#include <xtd/forms/panel.h>
#include <xtd/forms/picture_box.h>
#include <xtd/forms/tab_control.h>
#include <xtd/forms/tab_page.h>
#include <xtd/forms/text_box.h>

namespace xtdc_gui {
  /// @brief Represents the main form
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();

    // The main entry point for the application.
    static void main();
    
  private:
    void add_to_create_recent_projects(size_t create_project_items_index);
    void add_to_open_recent_projects(const std::string& project_path);
    void delete_from_create_recent_projects(size_t create_project_items_index);
    void delete_from_open_recent_projects(const std::string& project_path);
    void init();
    void init_create_create_recent_projects_list_box();
    void init_startup_open_recent_projects_list_box();
    void new_project(const std::string& project_path, size_t project_type_items_index);
    void new_project(const std::string& project_path, project_type type, project_language language, project_sdk sdk);
    void open_project(const std::string& project_path);
    void run_project(const std::string& project_path);

    xtd::forms::panel startup_panel_;
    xtd::forms::label startup_title_label_;
    xtd::forms::label startup_open_recent_project_title_label_;
    xtd::forms::list_box startup_open_recent_projects_list_box_;
    xtd::forms::label startup_get_started_title_label_;
    xtd::forms::button startup_open_project_button_;
    xtd::forms::button startup_run_project_button_;
    xtd::forms::button startup_new_project_button_;
    xtd::forms::button startup_open_xtd_examples_button_;

    xtd::forms::panel open_xtd_examples_panel_;
    xtd::forms::label open_xtd_examples_title_label_;
    xtd::forms::tab_control open_xtd_example_tab_control_;
    xtd::forms::tab_page open_xtd_example_console_tab_page_;
    xtd::forms::tab_page open_xtd_example_forms_tab_page_;
    xtd::forms::tab_page open_xtd_example_tunit_tab_page_;
    xtd::forms::picture_box open_xtd_example_console_picture_box_;
    xtd::forms::picture_box open_xtd_example_forms_picture_box_;
    xtd::forms::picture_box open_xtd_example_tunit_picture_box_;
    xtd::forms::label open_xtd_example_console_title_label_;
    xtd::forms::label open_xtd_example_forms_title_label_;
    xtd::forms::label open_xtd_example_tunit_title_label_;
    xtd::forms::list_box open_xtd_example_console_list_box_;
    xtd::forms::list_box open_xtd_example_forms_list_box_;
    xtd::forms::list_box open_xtd_example_tunit_list_box_;
    xtd::forms::text_box open_xtd_examples_information_text_box_;
    xtd::forms::picture_box open_xtd_examples_information_picture_box_;

    xtd::forms::panel create_panel_;
    xtd::forms::label create_title_label_;
    xtd::forms::label create_recent_project_title_label_;
    xtd::forms::list_box create_create_recent_projects_list_box_;
    xtd::forms::choice create_language_choice_;
    xtd::forms::choice create_platform_choice_;
    xtd::forms::choice create_type_choice_;
    project_type_items_control create_project_type_items_control_;

    xtd::forms::panel configure_panel_;
    xtd::forms::label configure_title_label_;
    xtd::forms::label configure_project_type_title_label_;
    xtd::forms::label configure_project_name_label_;
    xtd::forms::text_box configure_project_name_text_box_;
    xtd::forms::label configure_project_location_label_;
    xtd::forms::text_box configure_project_location_text_box_;
    xtd::forms::button configure_project_location_button_;

    xtd::forms::check_box auto_close_check_box_;
    xtd::forms::button previous_button_;
    xtd::forms::button next_button_;
    
    size_t current_project_type_index_ = -1;
    size_t current_open_xtd_example_console_list_box_index_ = 0;
    size_t current_open_xtd_example_forms_list_box_index_ = 0;
    size_t current_open_xtd_example_tunit_list_box_index_ = 0;
    std::vector<xtd_example_item> xtd_console_examples_ {
      {"Console color", "Show how to set background and foreground color.", {"xtd_console/console_color"}},
      {"Hello world (console)", "The classic first \"Hello, World!\" console application.", {"xtd_console/hello_world_console"}},
    };
    std::vector<xtd_example_item> xtd_forms_examples_ {
      {"Application - Application", "shows how to create an application with xtd::forms::application class.", {"xtd_forms/application/application"}},
      {"Application - Application_context", "shows how to create an application with xtd::forms::application class with xtd::forms::application_context class.", {"xtd_forms/application/application_context"}},
      {"Common controls - button", "represents a Windows xtd::forms::button control.", {"xtd_forms/common_controls/button"}},
      {"Common controls - check_box", "represents a Windows xtd::forms::check_box control.", {"xtd_forms/common_controls/check_box"}},
      {"Common controls - checked_list_box", "represents a Windows control to display a list of check box.", {"xtd_forms/common_controls/checked_list_box"}},
      {"Common controls - choice", "represents a Windows xtd::forms::choice control.", {"xtd_forms/common_controls/choice"}},
      {"Common controls - combo_box", "represents a Windows xtd::forms::combo_box control.", {"xtd_forms/common_controls/combo_box"}},
      {"Common controls - control", "defines the base class for controls, which are components with visual representation.", {"xtd_forms/common_controls/control"}},
      {"Common controls - domain_up_down", "represents a Windows spin box (also known as an up-down control) that displays string values.", {"xtd_forms/common_controls/domain_up_down"}},
      {"Common controls - label", " represents a standard Windows xtd::forms::label.", {"xtd_forms/common_controls/label"}},
      {"Common controls - list_box", "represents a Windows control to display a list of items.", {"xtd_forms/common_controls/list_box"}},
      {"Common controls - nunmeric_up_down", "represents a Windows spin box (also known as an up-down control) that displays numeric values.", {"xtd_forms/common_controls/numeric_up_down"}},
      {"Common controls - picture_box", "represents a Windows picture box control for displaying an image.", {"xtd_forms/common_controls/picture_box"}},
      {"Common controls - progress_bar", "represents a Windows xtd::forms::progress_bar control.", {"xtd_forms/common_controls/progress_bar"}},
      {"Common controls - radio_button", "enables the user to select a single option from a group of choices when paired with other xtd::forms::radio_button controls.", {"xtd_forms/common_controls/radio_button"}},
      {"Common controls - text_box", "represents a Windows xtd::forms::text_box control.", {"xtd_forms/common_controls/text_box"}},
      {"Common controls - track_bar", "represents a standard Windows xtd::forms::track_bar.", {"xtd_forms/common_controls/track_bar"}},
      {"Common controls - up_down_button", "represents a Windows spin button.", {"xtd_forms/common_controls/up_down_button"}},
      {"Common controls - user_control", "defines the base class for user controls.", {"xtd_forms/common_controls/user_control"}},
      {"Hello world - Hello world (emoticons)", "The classic first \"Hello, World!\" with xtd::forms::emoticons component.", {"xtd_forms/hello_world_examples/hello_world_emoticons"}},
      {"Hello world - Hello world (label)", "The classic first \"Hello, World!\" with xtd::forms::label control.", {"xtd_forms/hello_world_examples/hello_world_form"}},
      {"Hello world - Hello world (message_box)", "The classic first \"Hello, World!\" with xtd::forms::message_box dialog.", {"xtd_forms/hello_world_examples/hello_world_message_box"}},
      {"Hello world - Hello world (paint)", "The classic first \"Hello, World!\" with GDI+ drawing objects.", {"xtd_forms/hello_world_examples/hello_world_paint"}},
    };
    std::vector<xtd_example_item> xtd_tunit_examples_ {
      {"Hello world", "The classic first \"Hello, World!\" unit tests application.", "xtd_tunit/hello_world_tunit"},
    };
  };
}
