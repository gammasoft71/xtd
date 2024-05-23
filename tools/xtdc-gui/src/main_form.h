/// @file
/// @brief Contains main_form class.
#pragma once
#include "settings_form.h"
#include "../properties/settings.h"
#include "../resources/xtd_open_examples.xpm"
#include "../resources/xtd_open.xpm"
#include "../resources/xtd_new.xpm"
#include "../resources/xtd_run.xpm"
#include "project_type_item_control.h"
#include "project_type_items_control.h"
#include "xtd_example_item.h"
#include <memory>
#include <vector>
#include <xtd/forms/background_worker>
#include <xtd/forms/button>
#include <xtd/forms/check_box>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/link_label>
#include <xtd/forms/list_box>
#include <xtd/forms/main_menu>
#include <xtd/forms/menu_images>
#include <xtd/forms/menu_item>
#include <xtd/forms/panel>
#include <xtd/forms/picture_box>
#include <xtd/forms/progress_dialog>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/forms/text_box>
#include <xtd/drawing/texts>
#include <xtd/environment>
#include <xtd/size_object>

namespace xtdc_gui {
  /// @brief Represents the main form
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();
    
    /// @brief The main entry point for the application.
    static auto main() -> void;
    
  private:
    void add_to_create_recent_projects(size_t create_project_items_index);
    void add_to_open_recent_projects(const xtd::ustring& project_path);
    void delete_from_create_recent_projects(size_t create_project_items_index);
    void delete_from_open_recent_projects(const xtd::ustring& project_path);
    void init();
    void init_create_create_recent_projects_list_box();
    void init_startup_open_recent_projects_list_box();
    void new_project();
    void new_project(const xtd::ustring& project_path, size_t project_type_items_index);
    void new_project(const xtd::ustring& project_path, project_type type, project_language language, project_sdk sdk);
    void open_project();
    void open_project(const xtd::ustring& project_path);
    void open_xtd_examples();
    void run_project();
    void run_project(const xtd::ustring& project_path);
    void settings();
    void show_about_dialog();
    void update_open_xtd_examples(const xtd_example_item& item, const xtd::ustring& context);
    void update_open_xtd_examples_description(const xtd::ustring& description);
    void update_open_xtd_examples_picture(const xtd::drawing::image& picture);
    void update_open_xtd_examples_output(const xtd::ustring& output);
    
    std::unique_ptr<xtd::forms::background_worker> background_worker_;
    std::unique_ptr<xtd::forms::progress_dialog> progress_dialog_;
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
    xtd::forms::tab_page open_xtd_example_core_tab_page_;
    xtd::forms::tab_page open_xtd_example_drawing_tab_page_;
    xtd::forms::tab_page open_xtd_example_forms_tab_page_;
    xtd::forms::tab_page open_xtd_example_tunit_tab_page_;
    xtd::forms::tab_page open_xtd_example_cmake_tab_page_;
    xtd::forms::picture_box open_xtd_example_core_picture_box_;
    xtd::forms::picture_box open_xtd_example_drawing_picture_box_;
    xtd::forms::picture_box open_xtd_example_forms_picture_box_;
    xtd::forms::picture_box open_xtd_example_tunit_picture_box_;
    xtd::forms::picture_box open_xtd_example_cmake_picture_box_;
    xtd::forms::label open_xtd_example_cmake_title_label_;
    xtd::forms::label open_xtd_example_core_title_label_;
    xtd::forms::label open_xtd_example_drawing_title_label_;
    xtd::forms::label open_xtd_example_forms_title_label_;
    xtd::forms::label open_xtd_example_tunit_title_label_;
    xtd::forms::list_box open_xtd_example_cmake_list_box_;
    xtd::forms::list_box open_xtd_example_core_list_box_;
    xtd::forms::list_box open_xtd_example_drawing_list_box_;
    xtd::forms::list_box open_xtd_example_forms_list_box_;
    xtd::forms::list_box open_xtd_example_tunit_list_box_;
    xtd::forms::label open_xtd_examples_information_label_;
    xtd::forms::link_label open_xtd_examples_information_link_label_;
    xtd::forms::label open_xtd_examples_information_picture_label_;
    xtd::forms::text_box open_xtd_examples_information_output_text_box_;
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
    
    xtd::forms::button previous_button_;
    xtd::forms::button next_button_;
    
    settings_form settings_form_;

    xtd::forms::menu_item file_open_project_menu_item_ {"Open a project or solution", {*this, overload_<>(&main_form::open_project)}, xtd::drawing::bitmap(xtd::drawing::bitmap(xtd_open_examples_icon), xtd::forms::menu_images::size()), xtd::forms::shortcut::cmd_o};
    xtd::forms::menu_item file_run_project_menu_item_ {"Run a project", {*this, overload_<>(&main_form::run_project)}, xtd::drawing::bitmap(xtd::drawing::bitmap(xtd_run_icon), xtd::forms::menu_images::size()), xtd::forms::shortcut::cmd_r};
    xtd::forms::menu_item file_create_new_project_menu_item_ {"Create new project", {*this, overload_<>(&main_form::new_project)}, xtd::drawing::bitmap(xtd::drawing::bitmap(xtd_new_icon), xtd::forms::menu_images::size()), xtd::forms::shortcut::cmd_n};
    xtd::forms::menu_item file_open_xtd_examples_menu_item_ {"Open xtd examples", {*this, &main_form::open_xtd_examples}, xtd::drawing::bitmap(xtd::drawing::bitmap(xtd_open_icon), xtd::forms::menu_images::size()), xtd::forms::shortcut::cmd_e};
    xtd::forms::menu_item file_separator1_menu_item_ {"-"};
    xtd::forms::menu_item file_settings_menu_item_ {xtd::drawing::texts::settings(), {*this, &main_form::settings}, xtd::forms::shortcut::f2};
    xtd::forms::menu_item file_separator2_menu_item_ {"-"};
    xtd::forms::menu_item file_exit_menu_item_ {xtd::drawing::texts::exit(), overload_<>(&xtd::forms::application::exit), xtd::forms::menu_images::file_exit(), xtd::environment::os_version().is_windows() ? xtd::forms::shortcut::alt_f4 : xtd::forms::shortcut::cmd_q};
    xtd::forms::menu_item file_menu_item_ {xtd::drawing::texts::file(), {file_open_project_menu_item_, file_run_project_menu_item_, file_create_new_project_menu_item_, file_open_xtd_examples_menu_item_, file_separator1_menu_item_, file_settings_menu_item_, file_separator2_menu_item_, file_exit_menu_item_}};
    xtd::forms::menu_item help_about_menu_item_ {xtd::drawing::texts::about(), {*this, &main_form::show_about_dialog}, xtd::forms::menu_images::help_about()};
    xtd::forms::menu_item help_menu_item_ {xtd::drawing::texts::help(), {help_about_menu_item_}};
    xtd::forms::main_menu main_menu_ {file_menu_item_, help_menu_item_};
    
    size_t current_project_type_index_ = xtd::size_object::max_value;
    size_t current_open_xtd_example_core_list_box_index_ = 0;
    size_t current_open_xtd_example_drawing_list_box_index_ = 0;
    size_t current_open_xtd_example_forms_list_box_index_ = 0;
    size_t current_open_xtd_example_tunit_list_box_index_ = 0;
    size_t current_open_xtd_example_cmake_list_box_index_ = 0;
  };
}
