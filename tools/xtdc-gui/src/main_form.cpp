#include "main_form.h"
#include "../properties/settings.h"
#include "../resources/xtd_console.xpm"
#include "../resources/xtd_gui.xpm"
#include "../resources/xtd_tunit.xpm"
#include "../resources/xtd_open_examples.xpm"
#include "../resources/xtd_open.xpm"
#include "../resources/xtd_new.xpm"
#include "../resources/xtd_run.xpm"
#include <list>
#include <filesystem>
#include <xtd/environment.h>
#include <xtd/system_exception.h>
#include <xtd/diagnostics/process.h>
#include <xtd/drawing/system_icons.h>
#include <xtd/forms/application.h>
#include <xtd/forms/folder_browser_dialog.h>
#include <xtd/forms/message_box.h>
#include <xtd/forms/theme_images.h>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtdc_gui;

main_form::main_form() {
  busy_box::show("Initializing...", "xtdc-gui");
  client_size({1000, 710});
  icon(system_icons::from_name("xtd"));
  minimize_box(false);
  if (environment::os_version().is_macos_platform())
    environment::set_environment_variable("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin");
  start_position(form_start_position::center_screen);
  visible_changed += [&] {
    if (visible()) busy_box::hide();
  };
  
  startup_panel_.auto_scroll(true);
  startup_panel_.parent(*this);
  startup_panel_.size(client_size() - xtd::drawing::size {0, 100});
  startup_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  
  startup_title_label_.parent(startup_panel_);
  startup_title_label_.location({50, 50});
  startup_title_label_.auto_size(true);
  startup_title_label_.text("xtdc-gui");
  startup_title_label_.font({startup_title_label_.font(), 24.0});
  
  startup_open_recent_project_title_label_.parent(startup_panel_);
  startup_open_recent_project_title_label_.location({50, 115});
  startup_open_recent_project_title_label_.auto_size(true);
  startup_open_recent_project_title_label_.text("Open recent");
  startup_open_recent_project_title_label_.font({startup_open_recent_project_title_label_.font(), 16.0});
  
  startup_open_recent_projects_list_box_.parent(startup_panel_);
  startup_open_recent_projects_list_box_.location({50, 175});
  startup_open_recent_projects_list_box_.size({500, startup_panel_.size().height() - 175});
  startup_open_recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  startup_open_recent_projects_list_box_.key_down += [&](control& sender, key_event_args& e) {
    if (e.key_code() == keys::del && startup_open_recent_projects_list_box_.selected_index() != startup_open_recent_projects_list_box_.npos)
      delete_from_open_recent_projects(xtd::strings::split(properties::settings::default_settings().open_recent_propjects(), {';'})[startup_open_recent_projects_list_box_.selected_index()]);
  };

  startup_open_recent_projects_list_box_.double_click += [&] {
    if (startup_open_recent_projects_list_box_.selected_index() != startup_open_recent_projects_list_box_.npos) {
      if (!std::filesystem::exists(xtd::strings::split(properties::settings::default_settings().open_recent_propjects(), {';'})[startup_open_recent_projects_list_box_.selected_index()])) message_box::show(*this, xtd::strings::format("Project \"{}\" does not exists!", properties::settings::default_settings().open_recent_propjects()[startup_open_recent_projects_list_box_.selected_index()]), "Open project", message_box_buttons::ok, message_box_icon::error);
      else open_project(xtd::strings::split(properties::settings::default_settings().open_recent_propjects(), {';'})[startup_open_recent_projects_list_box_.selected_index()]);
    }
  };
  
  startup_get_started_title_label_.parent(startup_panel_);
  startup_get_started_title_label_.location({startup_panel_.size().width() - 400, 115});
  startup_get_started_title_label_.auto_size(true);
  startup_get_started_title_label_.text("Get started");
  startup_get_started_title_label_.font({startup_get_started_title_label_.font(), 16.0});
  startup_get_started_title_label_.anchor(anchor_styles::top|anchor_styles::right);

  startup_open_project_button_.parent(startup_panel_);
  startup_open_project_button_.image(xtd::forms::theme_images::current_theme().from_name("document-open", drawing::size {48, 48}));
  startup_open_project_button_.image(xtd::drawing::bitmap(xtd_open_icon));
  startup_open_project_button_.image_align(content_alignment::middle_left);
  startup_open_project_button_.text("Open a project or solution");
  startup_open_project_button_.location({startup_panel_.size().width() - 400, 175});
  startup_open_project_button_.size({350, 100});
  startup_open_project_button_.font({startup_open_project_button_.font(), 14.0});
  startup_open_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_open_project_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().open_propject_folder());
    if (dialog.show_sheet_dialog(*this) == dialog_result::ok) open_project(dialog.selected_path());
  };

  startup_run_project_button_.parent(startup_panel_);
  startup_run_project_button_.image(xtd::forms::theme_images::current_theme().from_name("system-run", drawing::size {48, 48}));
  startup_run_project_button_.image(xtd::drawing::bitmap(xtd_run_icon));
  startup_run_project_button_.image_align(content_alignment::middle_left);
  startup_run_project_button_.text("Run a project");
  startup_run_project_button_.location({startup_panel_.size().width() - 400, 285});
  startup_run_project_button_.size({350, 100});
  startup_run_project_button_.font({startup_run_project_button_.font(), 14.0});
  startup_run_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_run_project_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().open_propject_folder());
    if (dialog.show_sheet_dialog(*this) == dialog_result::ok) run_project(dialog.selected_path());
  };

  startup_new_project_button_.parent(startup_panel_);
  startup_new_project_button_.image(xtd::forms::theme_images::current_theme().from_name("document-new", drawing::size {48, 48}));
  startup_new_project_button_.image(xtd::drawing::bitmap(xtd_new_icon));
  startup_new_project_button_.image_align(content_alignment::middle_left);
  startup_new_project_button_.text("Create a new project");
  startup_new_project_button_.location({startup_panel_.size().width() - 400, 395});
  startup_new_project_button_.size({350, 100});
  startup_new_project_button_.font({startup_new_project_button_.font(), 14.0});
  startup_new_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_new_project_button_.click += [&] {
    startup_panel_.visible(false);
    create_panel_.visible(true);
    previous_button_.visible(true);
    next_button_.text("&Next");
    next_button_.visible(true);
  };

  startup_open_xtd_examples_button_.parent(startup_panel_);
  startup_open_xtd_examples_button_.image(xtd::forms::theme_images::current_theme().from_name("xtd", drawing::size {48, 48}));
  startup_open_xtd_examples_button_.image(xtd::drawing::bitmap(xtd_open_examples_icon));
  startup_open_xtd_examples_button_.image_align(content_alignment::middle_left);
  startup_open_xtd_examples_button_.text("Open xtd examples");
  startup_open_xtd_examples_button_.location({startup_panel_.size().width() - 400, 505});
  startup_open_xtd_examples_button_.size({350, 100});
  startup_open_xtd_examples_button_.font({startup_new_project_button_.font(), 14.0});
  startup_open_xtd_examples_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_open_xtd_examples_button_.click += [&] {
    startup_panel_.visible(false);
    open_xtd_examples_panel_.visible(true);
    previous_button_.visible(true);
    next_button_.text("&Open");
    next_button_.visible(true);
    next_button_.enabled(true);
  };

  open_xtd_examples_panel_.parent(*this);
  open_xtd_examples_panel_.size(client_size() - xtd::drawing::size {0, 100});
  open_xtd_examples_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  open_xtd_examples_panel_.visible(false);

  open_xtd_examples_title_label_.parent(open_xtd_examples_panel_);
  open_xtd_examples_title_label_.location({50, 50});
  open_xtd_examples_title_label_.auto_size(true);
  open_xtd_examples_title_label_.text("Open xtd examples");
  open_xtd_examples_title_label_.font({open_xtd_examples_title_label_.font(), 24.0});

  open_xtd_example_tab_control_.parent(open_xtd_examples_panel_);
  open_xtd_example_tab_control_.location({50, 115});
  open_xtd_example_tab_control_.size({450, open_xtd_examples_panel_.size().height() - 115});
  open_xtd_example_tab_control_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  open_xtd_example_tab_control_.selected_index_changed += [&] {
    if (open_xtd_example_tab_control_.selected_index() == 0) {
      open_xtd_example_console_list_box_.selected_index(current_open_xtd_example_console_list_box_index_);
      open_xtd_example_forms_list_box_.selected_index(open_xtd_example_forms_list_box_.npos);
      open_xtd_example_tunit_list_box_.selected_index(open_xtd_example_tunit_list_box_.npos);
    } else if (open_xtd_example_tab_control_.selected_index() == 1) {
      open_xtd_example_console_list_box_.selected_index(open_xtd_example_console_list_box_.npos);
      open_xtd_example_forms_list_box_.selected_index(current_open_xtd_example_forms_list_box_index_);
      open_xtd_example_tunit_list_box_.selected_index(open_xtd_example_tunit_list_box_.npos);
    } else if (open_xtd_example_tab_control_.selected_index() == 2) {
      open_xtd_example_console_list_box_.selected_index(open_xtd_example_console_list_box_.npos);
      open_xtd_example_forms_list_box_.selected_index(open_xtd_example_forms_list_box_.npos);
      open_xtd_example_tunit_list_box_.selected_index(current_open_xtd_example_tunit_list_box_index_);
    }
  };

  open_xtd_examples_information_text_box_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_text_box_.location({550, 50});
  open_xtd_examples_information_text_box_.size({400, open_xtd_examples_panel_.size().height() - 350});
  open_xtd_examples_information_text_box_.anchor(anchor_styles::top|anchor_styles::bottom|anchor_styles::right);
  open_xtd_examples_information_text_box_.multiline(true);
  open_xtd_examples_information_text_box_.read_only(true);
  open_xtd_examples_information_text_box_.word_wrap(false);

  open_xtd_examples_information_picture_box_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_picture_box_.location({550, open_xtd_examples_panel_.size().height() - 260});
  open_xtd_examples_information_picture_box_.size({400, 250});
  open_xtd_examples_information_picture_box_.size_mode(picture_box_size_mode::zoom);
  open_xtd_examples_information_picture_box_.anchor(anchor_styles::bottom|anchor_styles::right);

  open_xtd_example_console_tab_page_.text("xtd.core");
  open_xtd_example_console_tab_page_.parent(open_xtd_example_tab_control_);

  open_xtd_example_forms_tab_page_.text("xtd.forms");
  open_xtd_example_forms_tab_page_.parent(open_xtd_example_tab_control_);

  open_xtd_example_tunit_tab_page_.text("xtd.tunit");
  open_xtd_example_tunit_tab_page_.parent(open_xtd_example_tab_control_);
  
  open_xtd_example_console_picture_box_.parent(open_xtd_example_console_tab_page_);
  open_xtd_example_console_picture_box_.location({30, 30});
  open_xtd_example_console_picture_box_.size({40, 40});
  open_xtd_example_console_picture_box_.image(drawing::bitmap(xtd_console_icon));
  
  open_xtd_example_forms_picture_box_.parent(open_xtd_example_forms_tab_page_);
  open_xtd_example_forms_picture_box_.location({30, 30});
  open_xtd_example_forms_picture_box_.size({40, 40});
  open_xtd_example_forms_picture_box_.image(drawing::bitmap(xtd_gui_icon));
  
  open_xtd_example_tunit_picture_box_.parent(open_xtd_example_tunit_tab_page_);
  open_xtd_example_tunit_picture_box_.location({30, 30});
  open_xtd_example_tunit_picture_box_.size({40, 40});
  open_xtd_example_tunit_picture_box_.image(drawing::bitmap(xtd_tunit_icon));

  open_xtd_example_console_title_label_.parent(open_xtd_example_console_tab_page_);
  open_xtd_example_console_title_label_.text("xtd Console Application (c++)");
  open_xtd_example_console_title_label_.font({open_xtd_example_console_title_label_.font(), 16.0});
  open_xtd_example_console_title_label_.location({80, 35});
  open_xtd_example_console_title_label_.auto_size(true);

  open_xtd_example_forms_title_label_.parent(open_xtd_example_forms_tab_page_);
  open_xtd_example_forms_title_label_.text("xtd Gui Application (c++)");
  open_xtd_example_forms_title_label_.font({open_xtd_example_forms_title_label_.font(), 16.0});
  open_xtd_example_forms_title_label_.location({80, 35});
  open_xtd_example_forms_title_label_.auto_size(true);

  open_xtd_example_tunit_title_label_.parent(open_xtd_example_tunit_tab_page_);
  open_xtd_example_tunit_title_label_.text("xtd Unit Test Project (c++)");
  open_xtd_example_tunit_title_label_.font({open_xtd_example_tunit_title_label_.font(), 16.0});
  open_xtd_example_tunit_title_label_.location({80, 35});
  open_xtd_example_tunit_title_label_.auto_size(true);

  open_xtd_example_console_list_box_.parent(open_xtd_example_console_tab_page_);
  open_xtd_example_console_list_box_.location({30, 110});
  open_xtd_example_console_list_box_.size(open_xtd_example_console_tab_page_.size() - xtd::drawing::size {60, 140});
  //open_xtd_example_console_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  for (auto item : xtd_console_examples_)
    open_xtd_example_console_list_box_.items().push_back({item.name(), item});
  open_xtd_example_console_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_console_list_box_.selected_index() != open_xtd_example_console_list_box_.npos) {
      current_open_xtd_example_console_list_box_index_ = open_xtd_example_console_list_box_.selected_index();
      open_xtd_examples_information_text_box_.text(std::any_cast<xtd_example_item>(open_xtd_example_console_list_box_.selected_item().tag()).description());
      open_xtd_examples_information_picture_box_.image(std::any_cast<xtd_example_item>(open_xtd_example_console_list_box_.selected_item().tag()).picture());
    }
  };
  
  open_xtd_example_forms_list_box_.parent(open_xtd_example_forms_tab_page_);
  open_xtd_example_forms_list_box_.location({30, 110});
  open_xtd_example_forms_list_box_.size(open_xtd_example_forms_tab_page_.size() - xtd::drawing::size {60, 140});
  //open_xtd_example_forms_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  for (auto item : xtd_forms_examples_)
    open_xtd_example_forms_list_box_.items().push_back({item.name(), item});
  open_xtd_example_forms_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_forms_list_box_.selected_index() != open_xtd_example_forms_list_box_.npos) {
      current_open_xtd_example_forms_list_box_index_ = open_xtd_example_forms_list_box_.selected_index();
      open_xtd_examples_information_text_box_.text(std::any_cast<xtd_example_item>(open_xtd_example_forms_list_box_.selected_item().tag()).description());
      open_xtd_examples_information_picture_box_.image(std::any_cast<xtd_example_item>(open_xtd_example_forms_list_box_.selected_item().tag()).picture());
    }
  };

  open_xtd_example_tunit_list_box_.parent(open_xtd_example_tunit_tab_page_);
  open_xtd_example_tunit_list_box_.location({30, 110});
  open_xtd_example_tunit_list_box_.size(open_xtd_example_tunit_tab_page_.size() - xtd::drawing::size {60, 140});
  //open_xtd_example_tunit_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  for (auto item : xtd_tunit_examples_)
    open_xtd_example_tunit_list_box_.items().push_back({item.name(), item});
  open_xtd_example_tunit_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_tunit_list_box_.selected_index() != open_xtd_example_tunit_list_box_.npos) {
      current_open_xtd_example_tunit_list_box_index_ = open_xtd_example_tunit_list_box_.selected_index();
      open_xtd_examples_information_text_box_.text(std::any_cast<xtd_example_item>(open_xtd_example_tunit_list_box_.selected_item().tag()).description());
      open_xtd_examples_information_picture_box_.image(std::any_cast<xtd_example_item>(open_xtd_example_tunit_list_box_.selected_item().tag()).picture());
    }
  };

  create_panel_.parent(*this);
  create_panel_.size(client_size() - xtd::drawing::size {0, 100});
  create_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
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
  
  create_create_recent_projects_list_box_.parent(create_panel_);
  create_create_recent_projects_list_box_.location({50, 175});
  create_create_recent_projects_list_box_.size({400, create_panel_.size().height() - 175});
  create_create_recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  create_create_recent_projects_list_box_.selected_index_changed += [&] {
    if (create_create_recent_projects_list_box_.selected_index() == create_create_recent_projects_list_box_.npos)
      next_button_.enabled(false);
    else {
      create_project_type_items_control_.selected_index(create_project_type_items_control_.npos);
      current_project_type_index_ = xtd::parse<size_t>(xtd::strings::split(properties::settings::default_settings().create_recent_propjects(), {';'})[create_create_recent_projects_list_box_.selected_index()]);
      next_button_.enabled(true);
    }
  };
  create_create_recent_projects_list_box_.double_click += [&] {
    if (create_panel_.visible()) next_button_.perform_click();
  };
  create_create_recent_projects_list_box_.key_down += [&](control& sender, key_event_args& e) {
    if (e.key_code() == keys::del && create_create_recent_projects_list_box_.selected_index() != create_create_recent_projects_list_box_.npos)
      delete_from_create_recent_projects(xtd::parse<size_t>(xtd::strings::split(properties::settings::default_settings().create_recent_propjects(), {';'})[startup_open_recent_projects_list_box_.selected_index()]));
  };

  create_language_choice_.parent(create_panel_);
  create_language_choice_.width(140);
  create_language_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 400, 50});
  create_language_choice_.anchor(anchor_styles::top|anchor_styles::right);
  create_language_choice_.items().push_back_range({{"All languages", project_language::all}, {"xtd (c++)", project_language::xtd}, {"c++", project_language::cpp}, {"c", project_language::c}, {"c#", project_language::csharp}, {"objective-c", project_language::objectivec}});
  create_language_choice_.selected_value_changed += [&] {
    properties::settings::default_settings().language_index(create_language_choice_.selected_index());
    properties::settings::default_settings().save();
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_language_choice_.selected_index(properties::settings::default_settings().language_index());

  create_platform_choice_.parent(create_panel_);
  create_platform_choice_.width(140);
  create_platform_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 230, 50});
  create_platform_choice_.anchor(anchor_styles::top|anchor_styles::right);
  create_platform_choice_.items().push_back_range({{"All platforms", project_platform::all}, {"Windows", project_platform::windows}, {"Linux", project_platform::linux}, {"macOS", project_platform::macos}});
  create_platform_choice_.selected_value_changed += [&] {
    properties::settings::default_settings().platform_index(create_platform_choice_.selected_index());
    properties::settings::default_settings().save();
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_platform_choice_.selected_index(properties::settings::default_settings().platform_index());
  
  create_type_choice_.parent(create_panel_);
  create_type_choice_.width(140);
  create_type_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 50, 50});
  create_type_choice_.anchor(anchor_styles::top|anchor_styles::right);
  create_type_choice_.items().push_back_range({{"All project types", project_type::all}, {"Gui", project_type::gui}, {"Console", project_type::console}, {"Shared library", project_type::shared_library}, {"Static library", project_type::static_library}, {"UnitTest Project", project_type::unit_tests_project}, {"Solution File", project_type::solution_file}});
  create_type_choice_.selected_value_changed += [&] {
    properties::settings::default_settings().type_index(create_type_choice_.selected_index());
    properties::settings::default_settings().save();
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_type_choice_.selected_index(properties::settings::default_settings().type_index());

  create_project_type_items_control_.parent(create_panel_);
  create_project_type_items_control_.location({create_panel_.size().width() - 475 - 50, 100});
  create_project_type_items_control_.size({475, create_panel_.size().height() - 100});
  create_project_type_items_control_.anchor(anchor_styles::top|anchor_styles::bottom|anchor_styles::right);
  create_project_type_items_control_.selected_index_changed += [&] {
    if (create_project_type_items_control_.selected_index() == create_project_type_items_control_.npos)
      next_button_.enabled(false);
    else {
      create_create_recent_projects_list_box_.selected_index(create_create_recent_projects_list_box_.npos);
      current_project_type_index_ = create_project_type_items_control_.selected_index();
      next_button_.enabled(true);
    }
  };
  create_project_type_items_control_.double_click += [&] {
    if (create_panel_.visible()) next_button_.perform_click();
  };

  configure_panel_.auto_scroll(true);
  configure_panel_.parent(*this);
  configure_panel_.size(client_size() - xtd::drawing::size {0, 100});
  configure_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  configure_panel_.visible(false);

  configure_title_label_.parent(configure_panel_);
  configure_title_label_.location({50, 50});
  configure_title_label_.auto_size(true);
  configure_title_label_.text("Configure your new project");
  configure_title_label_.font({create_title_label_.font(), 24.0});
  
  configure_project_type_title_label_.parent(configure_panel_);
  configure_project_type_title_label_.location({50, 115});
  configure_project_type_title_label_.auto_size(true);
  configure_project_type_title_label_.text("Project type information");
  configure_project_type_title_label_.font({create_title_label_.font(), 16.0});

  configure_project_name_label_.parent(configure_panel_);
  configure_project_name_label_.location({50, 180});
  configure_project_name_label_.auto_size(true);
  configure_project_name_label_.text("Project name");
  
  configure_project_name_text_box_.parent(configure_panel_);
  configure_project_name_text_box_.location({50, 210});
  configure_project_name_text_box_.width(550);

  configure_project_location_label_.parent(configure_panel_);
  configure_project_location_label_.location({50, 270});
  configure_project_location_label_.auto_size(true);
  configure_project_location_label_.text("Project location");
  
  configure_project_location_text_box_.parent(configure_panel_);
  configure_project_location_text_box_.location({50, 300});
  configure_project_location_text_box_.width(550);
  configure_project_location_text_box_.text(properties::settings::default_settings().create_propject_folder());
  
  configure_project_location_button_.parent(configure_panel_);
  configure_project_location_button_.location({620, 300});
  configure_project_location_button_.width(37);
  configure_project_location_button_.text("...");
  configure_project_location_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().create_propject_folder());
    if (dialog.show_sheet_dialog(*this) == dialog_result::ok) {
      properties::settings::default_settings().create_propject_folder(dialog.selected_path());
      properties::settings::default_settings().save();
      configure_project_location_text_box_.text(properties::settings::default_settings().create_propject_folder());
    }
  };

  auto_close_check_box_.parent(*this);
  auto_close_check_box_.text("&Auto close");
  auto_close_check_box_.checked(properties::settings::default_settings().auto_close());
  auto_close_check_box_.location({50, client_size().height() - 75});
  auto_close_check_box_.anchor(anchor_styles::left|anchor_styles::bottom);
  auto_close_check_box_.checked_changed += [&] {
    properties::settings::default_settings().auto_close(auto_close_check_box_.checked());
    properties::settings::default_settings().save();
  };
  
  previous_button_.parent(*this);
  previous_button_.text("&Back");
  previous_button_.visible(false);
  previous_button_.location(client_size() - xtd::drawing::size {215, 75});
  previous_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  previous_button_.click += [&] {
    if (open_xtd_examples_panel_.visible()) {
      startup_panel_.visible(true);
      open_xtd_examples_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.visible(false);
    } else if (create_panel_.visible()) {
      startup_panel_.visible(true);
      create_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.visible(false);
    } else if (configure_panel_.visible()) {
      next_button_.text("&Next");
      create_panel_.visible(true);
      configure_panel_.visible(false);
      previous_button_.visible(true);
      next_button_.visible(true);
    } else if (open_xtd_examples_panel_.visible()) {
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
    if (create_panel_.visible()) {
      configure_project_type_title_label_.text(create_project_type_items_control_.project_type_items()[current_project_type_index_].name());
      auto project_name = std::map<project_type, std::string> {{project_type::gui, "gui_app"}, {project_type::console, "console_app"}, {project_type::shared_library, "class_library"}, {project_type::static_library, "class_library"}, {project_type::unit_tests_project, "unit_test_project"}, {project_type::solution_file, "solution_file"}}[create_project_type_items_control_.project_type_items()[current_project_type_index_].project_type()];
      auto index = 1;
      while (std::filesystem::exists(std::filesystem::path {configure_project_location_text_box_.text()}/xtd::strings::format("{}{}", project_name, index))) index++;
      configure_project_name_text_box_.text(xtd::strings::format("{}{}", project_name, index));
      previous_button_.text("&Back");
      next_button_.text("&Create");
      create_panel_.visible(false);
      configure_panel_.visible(true);
    } else if (configure_panel_.visible()) {
      auto project_path = std::filesystem::path {std::filesystem::path {configure_project_location_text_box_.text()}/configure_project_name_text_box_.text()}.string();
      if (std::filesystem::exists(project_path)) message_box::show(*this, xtd::strings::format("Project \"{}\" already exists!", project_path), "Create project", message_box_buttons::ok, message_box_icon::error);
      else {
        new_project(project_path, current_project_type_index_);
        startup_panel_.visible(true);
        configure_panel_.visible(false);
        previous_button_.visible(false);
        next_button_.text("&Next");
        next_button_.visible(false);
      }
    } else if (open_xtd_examples_panel_.visible()) {
      auto xtd_example = xtd_example_item();
      std::string exemple_subproject_path;
      if (open_xtd_example_tab_control_.selected_index() == 0) {
        xtd_example = std::any_cast<xtd_example_item>(open_xtd_example_console_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd_console";
      } else if (open_xtd_example_tab_control_.selected_index() == 1) {
        xtd_example = std::any_cast<xtd_example_item>(open_xtd_example_forms_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd_forms";
      } else if (open_xtd_example_tab_control_.selected_index() == 2) {
        xtd_example = std::any_cast<xtd_example_item>(open_xtd_example_tunit_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd_tunit";
      }
      
      auto target_path = std::filesystem::temp_directory_path()/"xtd_examples"/exemple_subproject_path/xtd_example.path().stem();
      if (std::filesystem::exists(target_path)) std::filesystem::remove_all(target_path);
      std::filesystem::create_directories(target_path);
      for (auto file : std::filesystem::directory_iterator(xtd_example.path()))
        std::filesystem::copy(file, target_path/file.path().filename());
      //message_box::show(*this, strings::format("Open example \"{}\" in {}.", xtd_example.name(), target_path.string()));
      background_worker_ = std::make_unique<background_worker>();
      background_worker_->do_work += [&](component& sender, do_work_event_args& e) {
        begin_invoke([&] {
          progress_dialog_ = std::make_unique<progress_dialog>();
          progress_dialog_->text(strings::format("Opening {} example", std::any_cast<std::filesystem::path>(e.argument()).filename()));
          progress_dialog_->message("Please wait...");
          progress_dialog_->marquee(true);
          progress_dialog_->show_sheet_dialog(*this);
        });
        process::start(process_start_info().file_name("xtdc").arguments(strings::format("open {}", std::any_cast<std::filesystem::path>(e.argument()))).use_shell_execute(false).create_no_window(true)).wait_for_exit();
      };
      background_worker_->run_worker_completed += [&] {
        begin_invoke([&] {
          progress_dialog_->hide();
          progress_dialog_.reset();
          if (properties::settings::default_settings().auto_close()) close();
        });
        background_worker_.reset();
      };
      background_worker_->run_worker_async(target_path);
    }
  };
  
  init();
}

void main_form::delete_from_create_recent_projects(size_t create_project_items_index) {
  auto create_recent_projects = xtd::strings::split(properties::settings::default_settings().create_recent_propjects(), {';'});
  create_recent_projects.erase(std::find(create_recent_projects.begin(), create_recent_projects.end(), std::to_string(create_project_items_index)));
  properties::settings::default_settings().create_recent_propjects(xtd::strings::join(";", create_recent_projects));
  properties::settings::default_settings().save();
  init_create_create_recent_projects_list_box();
}

void main_form::delete_from_open_recent_projects(const std::string& project_path) {
  auto open_recent_projects = xtd::strings::split(properties::settings::default_settings().open_recent_propjects(), {';'});
  open_recent_projects.erase(std::find(open_recent_projects.begin(), open_recent_projects.end(), project_path));
  properties::settings::default_settings().open_recent_propjects(xtd::strings::join(";", open_recent_projects));
  properties::settings::default_settings().save();
  init_startup_open_recent_projects_list_box();
}

void main_form::init() {
  init_create_create_recent_projects_list_box();
  init_startup_open_recent_projects_list_box();
  open_xtd_example_console_list_box_.selected_index(0);
}

void main_form::init_create_create_recent_projects_list_box() {
  auto project_type_items = create_project_type_items_control_.project_type_items();
  create_create_recent_projects_list_box_.items().clear();
  for (auto item : xtd::strings::split(properties::settings::default_settings().create_recent_propjects(), {';'}))
    create_create_recent_projects_list_box_.items().push_back(project_type_items[xtd::parse<size_t>(item)].name());
  create_create_recent_projects_list_box_.selected_index(create_create_recent_projects_list_box_.items().size() == 0 ? -1 : 0);
}

void main_form::init_startup_open_recent_projects_list_box() {
  startup_open_recent_projects_list_box_.items().clear();
  for (auto item : xtd::strings::split(properties::settings::default_settings().open_recent_propjects(), {';'}))
    startup_open_recent_projects_list_box_.items().push_back(xtd::strings::format("{} ({})", std::filesystem::path(item).stem().string(), item));
  startup_open_recent_projects_list_box_.selected_index(startup_open_recent_projects_list_box_.items().size() == 0 ? -1 : 0);
}

void main_form::add_to_create_recent_projects(size_t create_project_items_index) {
  auto create_recent_projects_from_settings = xtd::strings::split(properties::settings::default_settings().create_recent_propjects(), {';'});
  std::list<std::string> create_recent_projects {create_recent_projects_from_settings.begin(), create_recent_projects_from_settings.end()};
  if (std::find(create_recent_projects.begin(), create_recent_projects.end(), std::to_string(create_project_items_index)) != create_recent_projects.end())
    create_recent_projects.erase(std::find(create_recent_projects.begin(), create_recent_projects.end(), std::to_string(create_project_items_index)));
  
  create_recent_projects.push_front(std::to_string(create_project_items_index));
  properties::settings::default_settings().create_recent_propjects(xtd::strings::join(";", std::vector<std::string> {create_recent_projects.begin(), create_recent_projects.end()}));
  properties::settings::default_settings().save();
  
  init_create_create_recent_projects_list_box();
}

void main_form::add_to_open_recent_projects(const std::string& project_path) {
  auto open_recent_projects_from_settings = xtd::strings::split(properties::settings::default_settings().open_recent_propjects(), {';'});
  std::list<std::string> open_recent_projects {open_recent_projects_from_settings.begin(), open_recent_projects_from_settings.end()};
  if (std::find(open_recent_projects.begin(), open_recent_projects.end(), project_path) != open_recent_projects.end())
    open_recent_projects.erase(std::find(open_recent_projects.begin(), open_recent_projects.end(), project_path));

  open_recent_projects.push_front(project_path);
  properties::settings::default_settings().open_recent_propjects(xtd::strings::join(";", std::vector<std::string> {open_recent_projects.begin(), open_recent_projects.end()}));
  properties::settings::default_settings().open_propject_folder(project_path);
  properties::settings::default_settings().save();

  init_startup_open_recent_projects_list_box();
}

void main_form::new_project(const std::string& project_path, size_t project_type_items_index) {
  auto current_project_type = create_project_type_items_control_.project_type_items()[current_project_type_index_];
  add_to_create_recent_projects(project_type_items_index);
  new_project(project_path, current_project_type.project_type(), current_project_type.project_language(), current_project_type.project_sdk());
}

void main_form::new_project(const std::string& project_path, project_type type, project_language language, project_sdk sdk) {
  add_to_open_recent_projects(project_path);
  background_worker_ = std::make_unique<background_worker>();
  background_worker_->do_work += [&](component& sender, do_work_event_args& e) {
    std::tuple<std::string, std::string, std::filesystem::path> new_project = std::any_cast<std::tuple<std::string, std::string, std::filesystem::path>>(e.argument());
    begin_invoke([&] {
      progress_dialog_ = std::make_unique<progress_dialog>();
      progress_dialog_->text(strings::format("Creating {} project", std::get<2>(new_project).filename()));
      progress_dialog_->message("Please wait...");
      progress_dialog_->marquee(true);
      progress_dialog_->show_sheet_dialog(*this);
    });
    process::start(process_start_info().file_name("xtdc").arguments(strings::format("new {} -s {} {}", std::get<0>(new_project), std::get<1>(new_project), std::get<2>(new_project)).c_str()).use_shell_execute(false).create_no_window(true)).wait_for_exit();
    process::start(process_start_info().file_name("xtdc").arguments(strings::format("open {}", std::get<2>(new_project)).c_str()).use_shell_execute(false).create_no_window(true)).wait_for_exit();
  };;
  background_worker_->run_worker_completed += [&] {
    begin_invoke([&] {
      progress_dialog_->hide();
      progress_dialog_.reset();
      if (properties::settings::default_settings().auto_close()) close();
    });
    background_worker_.reset();
  };
  background_worker_->run_worker_async(std::make_tuple(std::map<project_type, std::string> {{project_type::gui, "gui"}, {project_type::console, "console"}, {project_type::shared_library, "sharedlib"}, {project_type::static_library, "staticlib"}, {project_type::unit_tests_project, "test"}, {project_type::solution_file, "sln"}}[type], (sdk == project_sdk::none ? std::map<project_language, std::string> {{project_language::xtd, "xtd"}, {project_language::cpp, "c++"}, {project_language::c, "c"}, {project_language::csharp, "c#"}, {project_language::objectivec, "objective-c"}}[language] : std::map<project_sdk, std::string> {{project_sdk::cocoa, "cocoa"}, {project_sdk::fltk, "fltk"}, {project_sdk::gtk2, "gtk+2"}, {project_sdk::gtk3, "gtk+3"}, {project_sdk::gtkmm, "gtkmm"}, {project_sdk::wxwidgets, "wxwidgets"}, {project_sdk::qt5, "qt5"}, {project_sdk::win32, "win32"}, {project_sdk::winforms, "winforms"}, {project_sdk::wpf, "wpf"}, {project_sdk::gtest, "gtest"}, {project_sdk::catch2, "catch2"}}[sdk]), std::filesystem::path(project_path)));
}

void main_form::open_project(const std::string& project_path) {
  add_to_open_recent_projects(project_path);
  background_worker_ = std::make_unique<background_worker>();
  background_worker_->do_work += [&](component& sender, do_work_event_args& e) {
    begin_invoke([&] {
      progress_dialog_ = std::make_unique<progress_dialog>();
      progress_dialog_->text(strings::format("Opening {} project", std::any_cast<std::filesystem::path>(e.argument()).filename()));
      progress_dialog_->message("Please wait...");
      progress_dialog_->marquee(true);
      progress_dialog_->show_sheet_dialog(*this);
    });
    process::start(process_start_info().file_name("xtdc").arguments(strings::format("open {}", std::any_cast<std::filesystem::path>(e.argument()))).use_shell_execute(false).create_no_window(true)).wait_for_exit();
  };
  background_worker_->run_worker_completed += [&] {
    begin_invoke([&] {
      progress_dialog_->hide();
      progress_dialog_.reset();
      if (properties::settings::default_settings().auto_close()) close();
    });
    background_worker_.reset();
  };
  background_worker_->run_worker_async(std::filesystem::path(project_path));
}

void main_form::run_project(const std::string& project_path) {
  add_to_open_recent_projects(project_path);
  background_worker_ = std::make_unique<background_worker>();
  background_worker_->do_work += [&](component& sender, do_work_event_args& e) {
    begin_invoke([&] {
      progress_dialog_ = std::make_unique<progress_dialog>();
      progress_dialog_->text(strings::format("Running {} project", std::any_cast<std::filesystem::path>(e.argument()).filename()));
      progress_dialog_->message("Please wait...");
      progress_dialog_->marquee(true);
      progress_dialog_->show_sheet_dialog(*this);
    });
    process::start(process_start_info().file_name("xtdc").arguments(strings::format("run {}", std::any_cast<std::filesystem::path>(e.argument()))).use_shell_execute(false).create_no_window(true)).wait_for_exit();
  };
  background_worker_->run_worker_completed += [&] {
    begin_invoke([&] {
      progress_dialog_->hide();
      progress_dialog_.reset();
      if (properties::settings::default_settings().auto_close()) close();
    });
    background_worker_.reset();
  };
  background_worker_->run_worker_async(std::filesystem::path(project_path));
}

void main_form::main() {
  application::run(main_form());
}
