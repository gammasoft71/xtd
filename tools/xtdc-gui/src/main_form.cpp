#include "main_form.h"
#include "../properties/settings.h"
#include <xtd/environment.h>
#include <xtd/forms/application.h>
#include <xtd/forms/folder_browser_dialog.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtdc_gui;

main_form::main_form() {
  //text("xtdc-gui");
  client_size({1024, 700});
  minimize_box(false);
  maximize_box(false);
  start_position(form_start_position::center_screen);
  
  startup_panel_.parent(*this);
  startup_panel_.size(client_size() - xtd::drawing::size {0, 100});
  startup_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  
  startup_title_label_.parent(startup_panel_);
  startup_title_label_.location({50, 50});
  startup_title_label_.auto_size(true);
  startup_title_label_.text("xtdc-gui");
  startup_title_label_.font({startup_title_label_.font(), 24.0});
  
  open_recent_project_title_label_.parent(startup_panel_);
  open_recent_project_title_label_.location({50, 115});
  open_recent_project_title_label_.auto_size(true);
  open_recent_project_title_label_.text("Open recent");
  open_recent_project_title_label_.font({open_recent_project_title_label_.font(), 16.0});
  
  open_recent_projects_list_box_.parent(startup_panel_);
  open_recent_projects_list_box_.location({50, 175});
  open_recent_projects_list_box_.size({500, startup_panel_.size().height() - 175});
  open_recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  open_recent_projects_list_box_.items().push_back_range({"gui_app1 (~/Projects/gui_app1)", "console_app1 (~/Projects/console_app1)"});
  open_recent_projects_list_box_.selected_index(0);
  
  get_started_title_label_.parent(startup_panel_);
  get_started_title_label_.location({startup_panel_.size().width() - 400, 115});
  get_started_title_label_.auto_size(true);
  get_started_title_label_.text("Get started");
  get_started_title_label_.font({get_started_title_label_.font(), 16.0});
  get_started_title_label_.anchor(anchor_styles::top|anchor_styles::right);

  open_project_button_.parent(startup_panel_);
  open_project_button_.text("Open a project or solution");
  open_project_button_.location({startup_panel_.size().width() - 400, 175});
  open_project_button_.size({350, 120});
  open_project_button_.font({open_project_button_.font(), 16.0});
  open_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  open_project_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().open_propject_folder());
    if (dialog.show_dialog() == dialog_result::ok) {
      properties::settings::default_settings().open_propject_folder(dialog.selected_path());
      properties::settings::default_settings().save();
      system(strings::format("xtdc open {}", dialog.selected_path()).c_str());
      if (properties::settings::default_settings().auto_close()) close();
    }
  };

  run_project_button_.parent(startup_panel_);
  run_project_button_.text("Run a project");
  run_project_button_.location({startup_panel_.size().width() - 400, 310});
  run_project_button_.size({350, 120});
  run_project_button_.font({run_project_button_.font(), 16.0});
  run_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  run_project_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().open_propject_folder());
    if (dialog.show_dialog() == dialog_result::ok) {
      properties::settings::default_settings().open_propject_folder(dialog.selected_path());
      properties::settings::default_settings().save();
      system(strings::format("xtdc run {}", dialog.selected_path()).c_str());
      if (properties::settings::default_settings().auto_close()) close();
    }
  };

  new_project_button_.parent(startup_panel_);
  new_project_button_.text("Create a new project");
  new_project_button_.location({startup_panel_.size().width() - 400, 445});
  new_project_button_.size({350, 120});
  new_project_button_.font({new_project_button_.font(), 16.0});
  new_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  new_project_button_.click += [&] {
    startup_panel_.visible(false);
    create_panel_.visible(true);
    previous_button_.visible(true);
    next_button_.visible(true);
  };

  create_panel_.parent(*this);
  create_panel_.size(client_size() - xtd::drawing::size {0, 100});
  create_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  //create_panel_.back_color(color::red);
  create_panel_.visible(false);

  create_title_label_.parent(create_panel_);
  create_title_label_.location({50, 50});
  create_title_label_.auto_size(true);
  create_title_label_.text("Create a new project");
  create_title_label_.font({create_title_label_.font(), 24.0});
  
  create_recent_project_title_label_.parent(create_panel_);
  create_recent_project_title_label_.location({50, 115});
  create_recent_project_title_label_.auto_size(true);
  create_recent_project_title_label_.text("Recent project templates");
  create_recent_project_title_label_.font({create_title_label_.font(), 16.0});
  
  create_recent_projects_list_box_.parent(create_panel_);
  create_recent_projects_list_box_.location({50, 175});
  create_recent_projects_list_box_.size({400, create_panel_.size().height() - 175});
  create_recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  create_recent_projects_list_box_.items().push_back_range({"xtd GUI Application (c++)", "xtd Console Application (c++)"});
  create_recent_projects_list_box_.selected_index(0);
  
  language_choice_.parent(create_panel_);
  language_choice_.width(140);
  language_choice_.location({create_panel_.size().width() - type_choice_.width() - 400, 50});
  language_choice_.anchor(anchor_styles::top|anchor_styles::right);
  language_choice_.items().push_back_range({{"All languages", project_language::all}, {"xtd (c++)", project_language::xtd}, {"c++", project_language::cpp}, {"c", project_language::c}, {"c#", project_language::csharp}, {"objective-c", project_language::objectivec}});
  language_choice_.selected_value_changed += [&] {
    project_type_items_control_.filter_items(language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(language_choice_.selected_item().tag()) : project_language::all, platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(platform_choice_.selected_item().tag()) : project_platform::all, type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(type_choice_.selected_item().tag()) : project_type::all);
  };
  language_choice_.selected_index(1);

  platform_choice_.parent(create_panel_);
  platform_choice_.width(140);
  platform_choice_.location({create_panel_.size().width() - type_choice_.width() - 230, 50});
  platform_choice_.anchor(anchor_styles::top|anchor_styles::right);
  platform_choice_.items().push_back_range({{"All platforms", project_platform::all}, {"Windows", project_platform::windows}, {"Linux", project_platform::linux}, {"macOS", project_platform::macos}});
  platform_choice_.selected_value_changed += [&] {
    project_type_items_control_.filter_items(language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(language_choice_.selected_item().tag()) : project_language::all, platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(platform_choice_.selected_item().tag()) : project_platform::all, type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(type_choice_.selected_item().tag()) : project_type::all);
  };
  platform_choice_.selected_index(environment::os_version().is_windows_platform() ? 1 : environment::os_version().is_linux_platform() ? 2 : 3);
  
  type_choice_.parent(create_panel_);
  type_choice_.width(140);
  type_choice_.location({create_panel_.size().width() - type_choice_.width() - 50, 50});
  type_choice_.anchor(anchor_styles::top|anchor_styles::right);
  type_choice_.items().push_back_range({{"All project types", project_type::all}, {"Gui", project_type::gui}, {"Console", project_type::console}, {"Shared library", project_type::shared_library}, {"Static library", project_type::static_library}, {"UnitTest Project", project_type::unit_tests_project}, {"Solution File", project_type::solution_file}});
  type_choice_.selected_value_changed += [&] {
    project_type_items_control_.filter_items(language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(language_choice_.selected_item().tag()) : project_language::all, platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(platform_choice_.selected_item().tag()) : project_platform::all, type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(type_choice_.selected_item().tag()) : project_type::all);
  };
  type_choice_.selected_index(0);

  project_type_items_control_.parent(create_panel_);
  project_type_items_control_.location({create_panel_.size().width() - 475 - 50, 100});
  project_type_items_control_.size({475, create_panel_.size().height() - 100});
  project_type_items_control_.anchor(anchor_styles::top|anchor_styles::bottom|anchor_styles::right);

  configure_panel_.parent(*this);
  configure_panel_.size(client_size() - xtd::drawing::size {0, 100});
  configure_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  //configure_panel_.back_color(color::red);
  configure_panel_.visible(false);

  configure_title_label_.parent(configure_panel_);
  configure_title_label_.location({50, 50});
  configure_title_label_.auto_size(true);
  configure_title_label_.text("Configure your new project");
  configure_title_label_.font({create_title_label_.font(), 24.0});
  
  project_type_title_label_.parent(configure_panel_);
  project_type_title_label_.location({50, 115});
  project_type_title_label_.auto_size(true);
  project_type_title_label_.text("Project type information");
  project_type_title_label_.font({create_title_label_.font(), 16.0});

  previous_button_.parent(*this);
  previous_button_.text("&Back");
  previous_button_.visible(false);
  previous_button_.location(client_size() - xtd::drawing::size {215, 75});
  previous_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  previous_button_.click += [&] {
    if (create_panel_.visible()) {
      startup_panel_.visible(true);
      create_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.visible(false);
    } else {
      previous_button_.text("&Back");
      next_button_.text("&Next");
      create_panel_.visible(true);
      configure_panel_.visible(false);
    }
  };

  next_button_.parent(*this);
  next_button_.text("&Next");
  next_button_.visible(false);
  next_button_.enabled(false);
  next_button_.location(client_size() - xtd::drawing::size {125, 75});
  next_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  next_button_.click += [&] {
    if (!create_panel_.visible()) {
      system("xtdc new gui /Users/yves/Projects/gui_app1");
      system("xtdc open /Users/yves/Projects/gui_app1");
      if (properties::settings::default_settings().auto_close()) close();
    } else {
      previous_button_.text("&Back");
      next_button_.text("&Create");
      create_panel_.visible(false);
      configure_panel_.visible(true);
    }
  };
}

void main_form::main() {
  application::enable_visual_styles();
  application::run(main_form());
}
