#include "main_form.h"
#include <ctype.h>
#include <list>
#include <xtd/char_object>
#include <xtd/environment>
#include <xtd/system_exception>
#include <xtd/diagnostics/debug>
#include <xtd/diagnostics/process>
#include <xtd/drawing/system_icons>
#include <xtd/forms/application>
#include <xtd/forms/folder_browser_dialog>
#include <xtd/forms/images>
#include <xtd/forms/message_box>
#include <xtd/io/directory>
#include <xtd/io/path>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::io;
using namespace xtdc_gui;

namespace {
  static void copy_directory(const ustring& source_dir, const ustring& destination_dir, bool recursive) {
    auto dir = directory_info(source_dir);
    if (!dir.exists()) throw directory_not_found_exception(ustring::format("Source directory not found: {}", dir.full_name()), csf_);
    
    directory::create_directory(destination_dir);
    
    for (const file_info& file : dir.get_files()) {
      ustring target_file_path = path::combine(destination_dir, file.name());
      file.copy_to(target_file_path);
    }
    
    if (recursive) {
      vector<directory_info> dirs = dir.get_directories();
      for (const directory_info& sub_dir : dirs) {
        ustring new_destination_dir = path::combine(destination_dir, sub_dir.name());
        copy_directory(sub_dir.full_name(), new_destination_dir, true);
      }
    }
  }
}

main_form::main_form() {
  if (properties::settings::default_settings().menu_visible())
    menu(main_menu_);
    
  client_size({1000, 710});
  minimum_client_size(client_size());
  accept_button(next_button_);
  icon(system_icons::from_name("xtd"));
  minimize_box(false);
  start_position(form_start_position::center_screen);
  text("xtdc-gui");
  
  busy_box::show("Initializing...", "xtdc-gui");
  
  startup_panel_.auto_scroll(true);
  startup_panel_.parent(*this);
  startup_panel_.size(client_size() - drawing::size {0, 100});
  startup_panel_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  
  startup_title_label_.parent(startup_panel_);
  startup_title_label_.location({50, 50});
  startup_title_label_.auto_size(true);
  startup_title_label_.text("Start");
  startup_title_label_.font({startup_title_label_.font(), 24.0});
  
  startup_open_recent_project_title_label_.parent(startup_panel_);
  startup_open_recent_project_title_label_.location({50, 115});
  startup_open_recent_project_title_label_.auto_size(true);
  startup_open_recent_project_title_label_.text("Open recent");
  startup_open_recent_project_title_label_.font({startup_open_recent_project_title_label_.font(), 16.0});
  
  startup_open_recent_projects_list_box_.parent(startup_panel_);
  startup_open_recent_projects_list_box_.location({50, 175});
  startup_open_recent_projects_list_box_.size({500, startup_panel_.size().height() - 175});
  startup_open_recent_projects_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  startup_open_recent_projects_list_box_.key_down += [&](object & sender, key_event_args & e) {
    if (e.key_code() == keys::del && startup_open_recent_projects_list_box_.selected_index() != startup_open_recent_projects_list_box_.npos)
      delete_from_open_recent_projects(properties::settings::default_settings().open_recent_propjects().split({';'})[startup_open_recent_projects_list_box_.selected_index()]);
  };
  
  startup_open_recent_projects_list_box_.double_click += [&] {
    if (startup_open_recent_projects_list_box_.selected_index() != startup_open_recent_projects_list_box_.npos) {
      if (!directory::exists(properties::settings::default_settings().open_recent_propjects().split({';'})[startup_open_recent_projects_list_box_.selected_index()].c_str())) message_box::show(*this, ustring::format("Project \"{}\" does not exists!", properties::settings::default_settings().open_recent_propjects()[startup_open_recent_projects_list_box_.selected_index()]), "Open project", message_box_buttons::ok, message_box_icon::error);
      else open_project(properties::settings::default_settings().open_recent_propjects().split({';'})[startup_open_recent_projects_list_box_.selected_index()]);
    }
  };
  
  startup_get_started_title_label_.parent(startup_panel_);
  startup_get_started_title_label_.location({startup_panel_.size().width() - 400, 115});
  startup_get_started_title_label_.auto_size(true);
  startup_get_started_title_label_.text("Get started");
  startup_get_started_title_label_.font({startup_get_started_title_label_.font(), 16.0});
  startup_get_started_title_label_.anchor(anchor_styles::top | anchor_styles::right);
  
  startup_open_project_button_.parent(startup_panel_);
  startup_open_project_button_.image(images::from_name("document-open", drawing::size {48, 48}));
  startup_open_project_button_.image(bitmap(xtd_open_icon));
  startup_open_project_button_.image_align(content_alignment::middle_left);
  startup_open_project_button_.text("Open a project or solution");
  startup_open_project_button_.location({startup_panel_.size().width() - 400, 175});
  startup_open_project_button_.size({350, 100});
  startup_open_project_button_.font({startup_open_project_button_.font(), 14.0});
  startup_open_project_button_.anchor(anchor_styles::top | anchor_styles::right);
  startup_open_project_button_.click += {*this, overload_<>(&main_form::open_project)};
  
  startup_run_project_button_.parent(startup_panel_);
  startup_run_project_button_.image(images::from_name("system-run", drawing::size {48, 48}));
  startup_run_project_button_.image(bitmap(xtd_run_icon));
  startup_run_project_button_.image_align(content_alignment::middle_left);
  startup_run_project_button_.text("Run a project");
  startup_run_project_button_.location({startup_panel_.size().width() - 400, 285});
  startup_run_project_button_.size({350, 100});
  startup_run_project_button_.font({startup_run_project_button_.font(), 14.0});
  startup_run_project_button_.anchor(anchor_styles::top | anchor_styles::right);
  startup_run_project_button_.click += {*this, overload_<>(&main_form::run_project)};
  
  startup_new_project_button_.parent(startup_panel_);
  startup_new_project_button_.image(images::from_name("document-new", drawing::size {48, 48}));
  startup_new_project_button_.image(bitmap(xtd_new_icon));
  startup_new_project_button_.image_align(content_alignment::middle_left);
  startup_new_project_button_.text("Create a new project");
  startup_new_project_button_.location({startup_panel_.size().width() - 400, 395});
  startup_new_project_button_.size({350, 100});
  startup_new_project_button_.font({startup_new_project_button_.font(), 14.0});
  startup_new_project_button_.anchor(anchor_styles::top | anchor_styles::right);
  startup_new_project_button_.click += {*this, overload_<>(&main_form::new_project)};
  
  startup_open_xtd_examples_button_.parent(startup_panel_);
  startup_open_xtd_examples_button_.image(images::from_name("xtd", drawing::size {48, 48}));
  startup_open_xtd_examples_button_.image(bitmap(xtd_open_examples_icon));
  startup_open_xtd_examples_button_.image_align(content_alignment::middle_left);
  startup_open_xtd_examples_button_.text("Open xtd examples");
  startup_open_xtd_examples_button_.location({startup_panel_.size().width() - 400, 505});
  startup_open_xtd_examples_button_.size({350, 100});
  startup_open_xtd_examples_button_.font({startup_new_project_button_.font(), 14.0});
  startup_open_xtd_examples_button_.anchor(anchor_styles::top | anchor_styles::right);
  startup_open_xtd_examples_button_.click += {*this, &main_form::open_xtd_examples};
  
  open_xtd_examples_panel_.parent(*this);
  open_xtd_examples_panel_.size(client_size() - drawing::size {0, 100});
  open_xtd_examples_panel_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  open_xtd_examples_panel_.visible(false);
  
  open_xtd_examples_title_label_.parent(open_xtd_examples_panel_);
  open_xtd_examples_title_label_.location({50, 50});
  open_xtd_examples_title_label_.auto_size(true);
  open_xtd_examples_title_label_.text("Open xtd examples");
  open_xtd_examples_title_label_.font({open_xtd_examples_title_label_.font(), 24.0});
  
  open_xtd_example_tab_control_.parent(open_xtd_examples_panel_);
  open_xtd_example_tab_control_.location({50, 115});
  open_xtd_example_tab_control_.size({450, open_xtd_examples_panel_.size().height() - 115});
  open_xtd_example_tab_control_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  open_xtd_example_tab_control_.selected_index_changed += [&] {
    if (open_xtd_example_tab_control_.selected_index() == 0) {
      open_xtd_example_core_list_box_.selected_index(current_open_xtd_example_core_list_box_index_);
      open_xtd_example_drawing_list_box_.selected_index(open_xtd_example_drawing_list_box_.npos);
      open_xtd_example_forms_list_box_.selected_index(open_xtd_example_forms_list_box_.npos);
      open_xtd_example_tunit_list_box_.selected_index(open_xtd_example_tunit_list_box_.npos);
      open_xtd_example_cmake_list_box_.selected_index(open_xtd_example_cmake_list_box_.npos);
    } else if (open_xtd_example_tab_control_.selected_index() == 1) {
      open_xtd_example_core_list_box_.selected_index(open_xtd_example_core_list_box_.npos);
      open_xtd_example_drawing_list_box_.selected_index(current_open_xtd_example_drawing_list_box_index_);
      open_xtd_example_forms_list_box_.selected_index(open_xtd_example_forms_list_box_.npos);
      open_xtd_example_tunit_list_box_.selected_index(open_xtd_example_tunit_list_box_.npos);
      open_xtd_example_cmake_list_box_.selected_index(open_xtd_example_cmake_list_box_.npos);
    } else if (open_xtd_example_tab_control_.selected_index() == 2) {
      open_xtd_example_core_list_box_.selected_index(open_xtd_example_core_list_box_.npos);
      open_xtd_example_drawing_list_box_.selected_index(open_xtd_example_drawing_list_box_.npos);
      open_xtd_example_forms_list_box_.selected_index(current_open_xtd_example_forms_list_box_index_);
      open_xtd_example_tunit_list_box_.selected_index(open_xtd_example_tunit_list_box_.npos);
      open_xtd_example_cmake_list_box_.selected_index(open_xtd_example_cmake_list_box_.npos);
    } else if (open_xtd_example_tab_control_.selected_index() == 3) {
      open_xtd_example_core_list_box_.selected_index(open_xtd_example_core_list_box_.npos);
      open_xtd_example_drawing_list_box_.selected_index(open_xtd_example_drawing_list_box_.npos);
      open_xtd_example_forms_list_box_.selected_index(open_xtd_example_forms_list_box_.npos);
      open_xtd_example_tunit_list_box_.selected_index(current_open_xtd_example_tunit_list_box_index_);
      open_xtd_example_cmake_list_box_.selected_index(open_xtd_example_cmake_list_box_.npos);
    } else if (open_xtd_example_tab_control_.selected_index() == 4) {
      open_xtd_example_core_list_box_.selected_index(open_xtd_example_core_list_box_.npos);
      open_xtd_example_drawing_list_box_.selected_index(open_xtd_example_drawing_list_box_.npos);
      open_xtd_example_forms_list_box_.selected_index(open_xtd_example_forms_list_box_.npos);
      open_xtd_example_tunit_list_box_.selected_index(open_xtd_example_tunit_list_box_.npos);
      open_xtd_example_cmake_list_box_.selected_index(current_open_xtd_example_cmake_list_box_index_);
    }
  };
  
  open_xtd_examples_information_label_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_label_.location({550, 60});
  open_xtd_examples_information_label_.auto_size(true);
  open_xtd_examples_information_label_.font({open_xtd_examples_information_label_.font(), 16.0});
  open_xtd_examples_information_label_.text("Description");
  open_xtd_examples_information_label_.anchor(anchor_styles::top | anchor_styles::right);
  
  open_xtd_examples_information_link_label_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_link_label_.back_color(xtd::forms::application::style_sheet().system_colors().window());
  open_xtd_examples_information_link_label_.border_style(xtd::forms::border_style::solid);
  open_xtd_examples_information_link_label_.location({550, 100});
  open_xtd_examples_information_link_label_.size({400, open_xtd_examples_panel_.size().height() - 390});
  open_xtd_examples_information_link_label_.font({open_xtd_examples_information_link_label_.font(), 12.0f});
  open_xtd_examples_information_link_label_.anchor(anchor_styles::top | anchor_styles::bottom | anchor_styles::right);
  open_xtd_examples_information_link_label_.text_align(content_alignment::top_left);
  open_xtd_examples_information_link_label_.padding(xtd::forms::padding(5));
  open_xtd_examples_information_link_label_.link_clicked += [](object & sender, link_label_clicked_event_args & e) {
    process::start(as<ustring>(e.link().link_data()));
  };
  
  open_xtd_examples_information_picture_label_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_picture_label_.location({550, open_xtd_examples_panel_.size().height() - 270});
  open_xtd_examples_information_picture_label_.auto_size(true);
  open_xtd_examples_information_picture_label_.font({open_xtd_examples_information_picture_label_.font(), 16.0});
  open_xtd_examples_information_picture_label_.text("Output");
  open_xtd_examples_information_picture_label_.anchor(anchor_styles::bottom | anchor_styles::right);
  
  open_xtd_examples_information_picture_box_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_picture_box_.back_color(xtd::forms::application::style_sheet().system_colors().window());
  open_xtd_examples_information_picture_box_.border_style(xtd::forms::border_style::solid);
  open_xtd_examples_information_picture_box_.location({550, open_xtd_examples_panel_.size().height() - 230});
  open_xtd_examples_information_picture_box_.size({400, 230});
  open_xtd_examples_information_picture_box_.size_mode(picture_box_size_mode::zoom);
  open_xtd_examples_information_picture_box_.anchor(anchor_styles::bottom | anchor_styles::right);
  
  open_xtd_examples_information_output_text_box_.parent(open_xtd_examples_panel_);
  open_xtd_examples_information_output_text_box_.back_color(xtd::forms::application::style_sheet().system_colors().window());
  open_xtd_examples_information_output_text_box_.border_style(xtd::forms::border_style::solid);
  open_xtd_examples_information_output_text_box_.location({ 550, open_xtd_examples_panel_.size().height() - 230 });
  open_xtd_examples_information_output_text_box_.size({ 400, 230 });
  open_xtd_examples_information_output_text_box_.anchor(anchor_styles::bottom | anchor_styles::right);
  open_xtd_examples_information_output_text_box_.word_wrap(false);
  open_xtd_examples_information_output_text_box_.multiline(true);
  open_xtd_examples_information_output_text_box_.read_only(true);
  open_xtd_examples_information_output_text_box_.font({ drawing::font_family::generic_monospace(), open_xtd_examples_information_output_text_box_.font().size()});
  
  open_xtd_example_core_tab_page_.text("xtd.core");
  open_xtd_example_core_tab_page_.parent(open_xtd_example_tab_control_);
  
  open_xtd_example_drawing_tab_page_.text("xtd.drawing");
  open_xtd_example_drawing_tab_page_.parent(open_xtd_example_tab_control_);
  
  open_xtd_example_forms_tab_page_.text("xtd.forms");
  open_xtd_example_forms_tab_page_.parent(open_xtd_example_tab_control_);
  
  open_xtd_example_tunit_tab_page_.text("xtd.tunit");
  open_xtd_example_tunit_tab_page_.parent(open_xtd_example_tab_control_);
  
  open_xtd_example_cmake_tab_page_.text("xtd.cmake");
  open_xtd_example_cmake_tab_page_.parent(open_xtd_example_tab_control_);
  
  open_xtd_example_core_picture_box_.parent(open_xtd_example_core_tab_page_);
  open_xtd_example_core_picture_box_.image(images::from_name("xtd-console"));
  open_xtd_example_core_picture_box_.location({30, 30});
  open_xtd_example_core_picture_box_.size({40, 40});
  open_xtd_example_core_picture_box_.size_mode(picture_box_size_mode::zoom);
  
  open_xtd_example_drawing_picture_box_.parent(open_xtd_example_drawing_tab_page_);
  open_xtd_example_drawing_picture_box_.image(images::from_name("xtd-drawing"));
  open_xtd_example_drawing_picture_box_.location({30, 30});
  open_xtd_example_drawing_picture_box_.size({40, 40});
  open_xtd_example_drawing_picture_box_.size_mode(picture_box_size_mode::zoom);
  
  open_xtd_example_forms_picture_box_.parent(open_xtd_example_forms_tab_page_);
  open_xtd_example_forms_picture_box_.image(images::from_name("xtd-forms"));
  open_xtd_example_forms_picture_box_.location({30, 30});
  open_xtd_example_forms_picture_box_.size({40, 40});
  open_xtd_example_forms_picture_box_.size_mode(picture_box_size_mode::zoom);
  
  open_xtd_example_tunit_picture_box_.parent(open_xtd_example_tunit_tab_page_);
  open_xtd_example_tunit_picture_box_.size_mode(picture_box_size_mode::zoom);
  open_xtd_example_tunit_picture_box_.location({30, 30});
  open_xtd_example_tunit_picture_box_.size({40, 40});
  open_xtd_example_tunit_picture_box_.image(images::from_name("xtd-tunit"));
  
  open_xtd_example_cmake_picture_box_.parent(open_xtd_example_cmake_tab_page_);
  open_xtd_example_cmake_picture_box_.image(images::from_name("xtd-cmake"));
  open_xtd_example_cmake_picture_box_.location({30, 30});
  open_xtd_example_cmake_picture_box_.size({40, 40});
  open_xtd_example_cmake_picture_box_.size_mode(picture_box_size_mode::zoom);
  
  open_xtd_example_core_title_label_.parent(open_xtd_example_core_tab_page_);
  open_xtd_example_core_title_label_.text("xtd Console Application (c++)");
  open_xtd_example_core_title_label_.font({open_xtd_example_core_title_label_.font(), 16.0});
  open_xtd_example_core_title_label_.location({80, 35});
  open_xtd_example_core_title_label_.auto_size(true);
  
  open_xtd_example_drawing_title_label_.parent(open_xtd_example_drawing_tab_page_);
  open_xtd_example_drawing_title_label_.text("xtd Drawing Project (c++)");
  open_xtd_example_drawing_title_label_.font({open_xtd_example_drawing_title_label_.font(), 16.0});
  open_xtd_example_drawing_title_label_.location({80, 35});
  open_xtd_example_drawing_title_label_.auto_size(true);
  
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
  
  open_xtd_example_cmake_title_label_.parent(open_xtd_example_cmake_tab_page_);
  open_xtd_example_cmake_title_label_.text("xtd CMake Project (c++)");
  open_xtd_example_cmake_title_label_.font({open_xtd_example_core_title_label_.font(), 16.0});
  open_xtd_example_cmake_title_label_.location({80, 35});
  open_xtd_example_cmake_title_label_.auto_size(true);
  
  open_xtd_example_core_list_box_.parent(open_xtd_example_core_tab_page_);
  open_xtd_example_core_list_box_.location({30, 110});
  open_xtd_example_core_list_box_.size(open_xtd_example_core_tab_page_.size() - drawing::size {60, 140});
  open_xtd_example_core_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  for (auto item : xtd_example_item::get_core_examples())
    open_xtd_example_core_list_box_.items().push_back({item.name(), item});
  open_xtd_example_core_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_core_list_box_.selected_index() != open_xtd_example_core_list_box_.npos) {
      current_open_xtd_example_core_list_box_index_ = open_xtd_example_core_list_box_.selected_index();
      update_open_xtd_examples(any_cast<xtd_example_item>(open_xtd_example_core_list_box_.selected_item().tag()), "xtd-console");
    }
  };
  open_xtd_example_core_list_box_.double_click += [&] {
    next_button_.perform_click();
  };
  
  open_xtd_example_drawing_list_box_.parent(open_xtd_example_drawing_tab_page_);
  open_xtd_example_drawing_list_box_.location({30, 110});
  open_xtd_example_drawing_list_box_.size(open_xtd_example_forms_tab_page_.size() - drawing::size {60, 140});
  open_xtd_example_drawing_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  for (auto item : xtd_example_item::get_drawing_examples())
    open_xtd_example_drawing_list_box_.items().push_back({item.name(), item});
  open_xtd_example_drawing_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_drawing_list_box_.selected_index() != open_xtd_example_drawing_list_box_.npos) {
      current_open_xtd_example_drawing_list_box_index_ = open_xtd_example_drawing_list_box_.selected_index();
      update_open_xtd_examples(any_cast<xtd_example_item>(open_xtd_example_drawing_list_box_.selected_item().tag()), "xtd-drawing");
    }
  };
  open_xtd_example_drawing_list_box_.double_click += [&] {
    next_button_.perform_click();
  };
  
  open_xtd_example_forms_list_box_.parent(open_xtd_example_forms_tab_page_);
  open_xtd_example_forms_list_box_.location({30, 110});
  open_xtd_example_forms_list_box_.size(open_xtd_example_forms_tab_page_.size() - drawing::size {60, 140});
  open_xtd_example_forms_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  for (auto item : xtd_example_item::get_forms_examples())
    open_xtd_example_forms_list_box_.items().push_back({item.name(), item});
  open_xtd_example_forms_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_forms_list_box_.selected_index() != open_xtd_example_forms_list_box_.npos) {
      current_open_xtd_example_forms_list_box_index_ = open_xtd_example_forms_list_box_.selected_index();
      update_open_xtd_examples(any_cast<xtd_example_item>(open_xtd_example_forms_list_box_.selected_item().tag()), "xtd-forms");
    }
  };
  open_xtd_example_forms_list_box_.double_click += [&] {
    next_button_.perform_click();
  };
  
  open_xtd_example_tunit_list_box_.parent(open_xtd_example_tunit_tab_page_);
  open_xtd_example_tunit_list_box_.location({30, 110});
  open_xtd_example_tunit_list_box_.size(open_xtd_example_tunit_tab_page_.size() - drawing::size {60, 140});
  open_xtd_example_tunit_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  for (auto item : xtd_example_item::get_tunit_examples())
    open_xtd_example_tunit_list_box_.items().push_back({item.name(), item});
  open_xtd_example_tunit_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_tunit_list_box_.selected_index() != open_xtd_example_tunit_list_box_.npos) {
      current_open_xtd_example_tunit_list_box_index_ = open_xtd_example_tunit_list_box_.selected_index();
      update_open_xtd_examples(any_cast<xtd_example_item>(open_xtd_example_tunit_list_box_.selected_item().tag()), "xtd-tunit");
    }
  };
  open_xtd_example_tunit_list_box_.double_click += [&] {
    next_button_.perform_click();
  };
  
  open_xtd_example_cmake_list_box_.parent(open_xtd_example_cmake_tab_page_);
  open_xtd_example_cmake_list_box_.location({30, 110});
  open_xtd_example_cmake_list_box_.size(open_xtd_example_core_tab_page_.size() - drawing::size {60, 140});
  open_xtd_example_cmake_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  for (auto item : xtd_example_item::get_cmake_examples())
    open_xtd_example_cmake_list_box_.items().push_back({item.name(), item});
  open_xtd_example_cmake_list_box_.selected_value_changed += [&] {
    if (open_xtd_example_cmake_list_box_.selected_index() != open_xtd_example_cmake_list_box_.npos) {
      current_open_xtd_example_cmake_list_box_index_ = open_xtd_example_cmake_list_box_.selected_index();
      update_open_xtd_examples(any_cast<xtd_example_item>(open_xtd_example_cmake_list_box_.selected_item().tag()), "xtd-cmake");
    }
  };
  open_xtd_example_cmake_list_box_.double_click += [&] {
    next_button_.perform_click();
  };
  
  create_panel_.parent(*this);
  create_panel_.size(client_size() - drawing::size {0, 100});
  create_panel_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
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
  create_create_recent_projects_list_box_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  create_create_recent_projects_list_box_.selected_index_changed += [&] {
    if (create_create_recent_projects_list_box_.selected_index() == create_create_recent_projects_list_box_.npos)
      next_button_.enabled(false);
    else {
      create_project_type_items_control_.selected_index(create_project_type_items_control_.npos);
      current_project_type_index_ = parse<size_t>(properties::settings::default_settings().create_recent_propjects().split({';'})[create_create_recent_projects_list_box_.selected_index()]);
      next_button_.enabled(true);
    }
  };
  create_create_recent_projects_list_box_.double_click += [&] {
    if (create_panel_.visible()) next_button_.perform_click();
  };
  create_create_recent_projects_list_box_.key_down += [&](object & sender, key_event_args & e) {
    if (e.key_code() == keys::del && create_create_recent_projects_list_box_.selected_index() != create_create_recent_projects_list_box_.npos)
      delete_from_create_recent_projects(parse<size_t>(properties::settings::default_settings().create_recent_propjects().split({';'})[create_create_recent_projects_list_box_.selected_index()]));
  };
  
  create_language_choice_.parent(create_panel_);
  create_language_choice_.width(140);
  create_language_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 400, 50});
  create_language_choice_.anchor(anchor_styles::top | anchor_styles::right);
  create_language_choice_.items().push_back_range({{"All languages", project_language::all}, {"xtd (c++)", project_language::xtd}, {"xtd_c (c)", project_language::xtd_c}, {"c++", project_language::cpp}, {"c", project_language::c}, {"c#", project_language::csharp}, {"objective-c", project_language::objectivec}});
  create_language_choice_.selected_value_changed += [&] {
    properties::settings::default_settings().language_index(create_language_choice_.selected_index()).save();
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_language_choice_.selected_index(properties::settings::default_settings().language_index());
  
  create_platform_choice_.parent(create_panel_);
  create_platform_choice_.width(140);
  create_platform_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 230, 50});
  create_platform_choice_.anchor(anchor_styles::top | anchor_styles::right);
  create_platform_choice_.items().push_back_range({{"All platforms", project_platform::all}, {"Windows", project_platform::windows}, {"Linux", project_platform::linux}, {"macOS", project_platform::macos}});
  create_platform_choice_.selected_value_changed += [&] {
    properties::settings::default_settings().platform_index(create_platform_choice_.selected_index()).save();
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_platform_choice_.selected_index(properties::settings::default_settings().platform_index());
  
  create_type_choice_.parent(create_panel_);
  create_type_choice_.width(140);
  create_type_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 50, 50});
  create_type_choice_.anchor(anchor_styles::top | anchor_styles::right);
  create_type_choice_.items().push_back_range({{"All project types", project_type::all}, {"Gui", project_type::gui}, {"Console", project_type::console}, {"Shared library", project_type::shared_library}, {"Static library", project_type::static_library}, {"UnitTest Project", project_type::unit_tests_project}, {"Solution File", project_type::solution_file}});
  create_type_choice_.selected_value_changed += [&] {
    properties::settings::default_settings().type_index(create_type_choice_.selected_index()).save();
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_type_choice_.selected_index(properties::settings::default_settings().type_index());
  
  create_project_type_items_control_.parent(create_panel_);
  create_project_type_items_control_.location({create_panel_.size().width() - 475 - 50, 100});
  create_project_type_items_control_.size({475, create_panel_.size().height() - 100});
  create_project_type_items_control_.anchor(anchor_styles::top | anchor_styles::bottom | anchor_styles::right);
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
    next_button_.perform_click();
  };
  
  configure_panel_.auto_scroll(true);
  configure_panel_.parent(*this);
  configure_panel_.size(client_size() - drawing::size {0, 100});
  configure_panel_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
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
  configure_project_name_text_box_.key_press += [&](object & sender, key_press_event_args & e) {
    e.handled(configure_project_name_text_box_.text().size() >= 128 || !(char_object::is_letter_or_digit(e.key_char()) || e.key_char() == U'_' || e.key_char() == U'-'));
  };
  configure_project_name_text_box_.key_up += [&](object & sender, key_event_args & e) {
    next_button_.enabled(configure_project_name_text_box_.text().size() != 0 && configure_project_location_text_box_.text().size() != 0);
  };
  
  configure_project_location_label_.parent(configure_panel_);
  configure_project_location_label_.location({50, 270});
  configure_project_location_label_.auto_size(true);
  configure_project_location_label_.text("Project location");
  
  configure_project_location_text_box_.parent(configure_panel_);
  configure_project_location_text_box_.location({50, 300});
  configure_project_location_text_box_.width(550);
  configure_project_location_text_box_.text(properties::settings::default_settings().create_propject_folder());
  configure_project_location_text_box_.key_up += [&](object & sender, key_event_args & e) {
    next_button_.enabled(configure_project_name_text_box_.text().size() != 0 && configure_project_location_text_box_.text().size() != 0);
  };
  
  configure_project_location_button_.parent(configure_panel_);
  configure_project_location_button_.location({620, 300});
  configure_project_location_button_.width(37);
  configure_project_location_button_.text("...");
  configure_project_location_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().create_propject_folder());
    if (dialog.show_sheet_dialog(*this) == dialog_result::ok) {
      properties::settings::default_settings().create_propject_folder(dialog.selected_path()).save();
      configure_project_location_text_box_.text(properties::settings::default_settings().create_propject_folder());
      next_button_.enabled(configure_project_name_text_box_.text().size() != 0 && configure_project_location_text_box_.text().size() != 0);
    }
  };
  
  previous_button_.parent(*this);
  previous_button_.text("&Back");
  previous_button_.visible(false);
  previous_button_.location(point(client_size() - drawing::size {215, 75}));
  previous_button_.anchor(anchor_styles::bottom | anchor_styles::right);
  previous_button_.click += [&] {
    if (open_xtd_examples_panel_.visible()) {
      if (menu().has_value()) {
        file_open_project_menu_item_.enabled(true);
        file_run_project_menu_item_.enabled(true);
      }
      startup_panel_.visible(true);
      open_xtd_examples_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.visible(false);
    } else if (create_panel_.visible()) {
      if (menu().has_value()) {
        file_open_project_menu_item_.enabled(true);
        file_run_project_menu_item_.enabled(true);
      }
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
    } else if (!open_xtd_examples_panel_.visible()) {
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
  next_button_.location(point(client_size() - drawing::size {125, 75}));
  next_button_.anchor(anchor_styles::bottom | anchor_styles::right);
  next_button_.click += [&] {
    if (create_panel_.visible()) {
      configure_project_type_title_label_.text(create_project_type_items_control_.project_type_items()[current_project_type_index_].name());
      auto project_name = map<project_type, ustring> {{project_type::gui, "gui_app"}, {project_type::console, "console_app"}, {project_type::shared_library, "class_library"}, {project_type::static_library, "class_library"}, {project_type::unit_tests_project, "unit_test_project"}, {project_type::solution_file, "solution_file"}} [create_project_type_items_control_.project_type_items()[current_project_type_index_].project_type()];
      auto index = 1;
      while (directory::exists(path::combine(configure_project_location_text_box_.text(), ustring::format("{}{}", project_name, index)))) index++;
      configure_project_name_text_box_.text(ustring::format("{}{}", project_name, index));
      previous_button_.text("&Back");
      next_button_.text("&Create");
      create_panel_.visible(false);
      configure_panel_.visible(true);
    } else if (configure_panel_.visible()) {
      auto project_path = path::combine(configure_project_location_text_box_.text(), configure_project_name_text_box_.text());
      if (directory::exists(project_path)) message_box::show(*this, ustring::format("Project \"{}\" already exists!", project_path), "Create project", message_box_buttons::ok, message_box_icon::error);
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
      ustring exemple_subproject_path;
      if (open_xtd_example_tab_control_.selected_index() == 0) {
        xtd_example = any_cast<xtd_example_item>(open_xtd_example_core_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd.core.examples";
      } else if (open_xtd_example_tab_control_.selected_index() == 1) {
        xtd_example = any_cast<xtd_example_item>(open_xtd_example_drawing_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd.drawing.examples";
      } else if (open_xtd_example_tab_control_.selected_index() == 2) {
        xtd_example = any_cast<xtd_example_item>(open_xtd_example_forms_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd.forms.examples";
      } else if (open_xtd_example_tab_control_.selected_index() == 3) {
        xtd_example = any_cast<xtd_example_item>(open_xtd_example_tunit_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd.tunit.examples";
      } else if (open_xtd_example_tab_control_.selected_index() == 4) {
        xtd_example = any_cast<xtd_example_item>(open_xtd_example_cmake_list_box_.selected_item().tag());
        exemple_subproject_path = "xtd.cmake.examples";
      }
      
      auto target_path = path::combine(path::get_temp_path(), exemple_subproject_path, path::get_file_name(xtd_example.path()));
      if (directory::exists(target_path)) directory::remove(target_path, true);
      directory::create_directory(target_path);
      copy_directory(xtd_example.path(), target_path, true);
      //message_box::show(*this, ustring::format("Open example \"{}\" in {}.", xtd_example.name(), target_path.string()));
      background_worker_ = make_unique<background_worker>();
      background_worker_->do_work += [&](object & sender, do_work_event_args & e) {
        begin_invoke([&] {
          progress_dialog_ = make_unique<progress_dialog>();
          progress_dialog_->text(ustring::format("Opening {} example", path::get_file_name(any_cast<ustring>(e.argument()))));
          progress_dialog_->message("Please wait...");
          progress_dialog_->marquee(true);
          progress_dialog_->show_sheet_dialog(*this);
        });
        process::start(process_start_info().file_name("xtdc").arguments(ustring::format("open {}", any_cast<ustring>(e.argument()))).use_shell_execute(false).create_no_window(true)).wait_for_exit();
      };
      background_worker_->run_worker_completed += [&] {
        begin_invoke([&] {
          progress_dialog_->hide();
          progress_dialog_.reset();
          background_worker_.reset();
          if (properties::settings::default_settings().auto_close()) close();
        });
      };
      background_worker_->run_worker_async(target_path);
    }
  };
  
  init();
  
  busy_box::hide();
}

void main_form::delete_from_create_recent_projects(size_t create_project_items_index) {
  auto create_recent_projects = properties::settings::default_settings().create_recent_propjects().split({';'});
  create_recent_projects.erase(find(create_recent_projects.begin(), create_recent_projects.end(), std::to_string(create_project_items_index)));
  properties::settings::default_settings().create_recent_propjects(ustring::join(";", create_recent_projects)).save();
  init_create_create_recent_projects_list_box();
}

void main_form::delete_from_open_recent_projects(const ustring& project_path) {
  auto open_recent_projects = properties::settings::default_settings().open_recent_propjects().split({';'});
  open_recent_projects.erase(find(open_recent_projects.begin(), open_recent_projects.end(), project_path));
  properties::settings::default_settings().open_recent_propjects(ustring::join(";", open_recent_projects)).save();
  init_startup_open_recent_projects_list_box();
}

void main_form::init() {
  init_create_create_recent_projects_list_box();
  init_startup_open_recent_projects_list_box();
  open_xtd_example_core_list_box_.selected_index(0);
}

void main_form::init_create_create_recent_projects_list_box() {
  auto project_type_items = create_project_type_items_control_.project_type_items();
  create_create_recent_projects_list_box_.items().clear();
  for (auto item : properties::settings::default_settings().create_recent_propjects().split({';'}))
    create_create_recent_projects_list_box_.items().push_back(project_type_items[parse<size_t>(item)].name());
  create_create_recent_projects_list_box_.selected_index(create_create_recent_projects_list_box_.items().size() == 0 ? -1 : 0);
}

void main_form::init_startup_open_recent_projects_list_box() {
  startup_open_recent_projects_list_box_.items().clear();
  for (auto item : properties::settings::default_settings().open_recent_propjects().split({';'}))
    startup_open_recent_projects_list_box_.items().push_back(ustring::format("{} ({})", path::get_file_name(item), item));
  startup_open_recent_projects_list_box_.selected_index(startup_open_recent_projects_list_box_.items().size() == 0 ? -1 : 0);
}

void main_form::add_to_create_recent_projects(size_t create_project_items_index) {
  auto create_recent_projects_from_settings = properties::settings::default_settings().create_recent_propjects().split({';'});
  list<ustring> create_recent_projects {create_recent_projects_from_settings.begin(), create_recent_projects_from_settings.end()};
  if (find(create_recent_projects.begin(), create_recent_projects.end(), std::to_string(create_project_items_index)) != create_recent_projects.end())
    create_recent_projects.erase(find(create_recent_projects.begin(), create_recent_projects.end(), std::to_string(create_project_items_index)));
    
  create_recent_projects.push_front(std::to_string(create_project_items_index));
  properties::settings::default_settings().create_recent_propjects(ustring::join(";", vector<ustring> {create_recent_projects.begin(), create_recent_projects.end()})).save();
  
  init_create_create_recent_projects_list_box();
}

void main_form::add_to_open_recent_projects(const ustring& project_path) {
  auto open_recent_projects_from_settings = properties::settings::default_settings().open_recent_propjects().split({';'});
  list<ustring> open_recent_projects {open_recent_projects_from_settings.begin(), open_recent_projects_from_settings.end()};
  if (find(open_recent_projects.begin(), open_recent_projects.end(), project_path) != open_recent_projects.end())
    open_recent_projects.erase(find(open_recent_projects.begin(), open_recent_projects.end(), project_path));
    
  open_recent_projects.push_front(project_path);
  properties::settings::default_settings().open_recent_propjects(ustring::join(";", vector<ustring> {open_recent_projects.begin(), open_recent_projects.end()})).open_propject_folder(project_path).save();
  
  init_startup_open_recent_projects_list_box();
}

void main_form::new_project() {
  if (menu().has_value()) {
    file_open_project_menu_item_.enabled(false);
    file_run_project_menu_item_.enabled(false);
  }
  startup_panel_.visible(false);
  create_panel_.visible(true);
  open_xtd_examples_panel_.visible(false);
  previous_button_.visible(true);
  next_button_.text("&Next");
  next_button_.visible(true);
}

void main_form::new_project(const ustring& project_path, size_t project_type_items_index) {
  auto current_project_type = create_project_type_items_control_.project_type_items()[current_project_type_index_];
  add_to_create_recent_projects(project_type_items_index);
  new_project(project_path, current_project_type.project_type(), current_project_type.project_language(), current_project_type.project_sdk());
}

void main_form::new_project(const ustring& project_path, project_type type, project_language language, project_sdk sdk) {
  add_to_open_recent_projects(project_path);
  background_worker_ = make_unique<background_worker>();
  background_worker_->do_work += [&](object & sender, do_work_event_args & e) {
    tuple<ustring, ustring, ustring> new_project = any_cast<tuple<ustring, ustring, ustring>>(e.argument());
    begin_invoke([&] {
      progress_dialog_ = make_unique<progress_dialog>();
      progress_dialog_->text(ustring::format("Creating {} project", path::get_file_name(get<2>(new_project))));
      progress_dialog_->message("Please wait...");
      progress_dialog_->marquee(true);
      progress_dialog_->show_sheet_dialog(*this);
    });
    process::start(process_start_info().file_name("xtdc").arguments(ustring::format("new {} -s {} {}", get<0>(new_project), get<1>(new_project), get<2>(new_project)).c_str()).use_shell_execute(false).create_no_window(true)).wait_for_exit();
    process::start(process_start_info().file_name("xtdc").arguments(ustring::format("open {}", get<2>(new_project)).c_str()).use_shell_execute(false).create_no_window(true)).wait_for_exit();
  };
  background_worker_->run_worker_completed += [&] {
    begin_invoke([&] {
      progress_dialog_->hide();
      progress_dialog_.reset();
      background_worker_.reset();
      if (properties::settings::default_settings().auto_close()) close();
    });
  };
  background_worker_->run_worker_async(make_tuple(map<project_type, ustring> {{project_type::gui, "gui"}, {project_type::console, "console"}, {project_type::shared_library, "sharedlib"}, {project_type::static_library, "staticlib"}, {project_type::unit_tests_project, "test"}, {project_type::solution_file, "sln"}} [type], (sdk == project_sdk::none ? map<project_language, ustring> {{project_language::xtd, "xtd"}, {project_language::xtd_c, "xtd_c"}, {project_language::cpp, "c++"}, {project_language::c, "c"}, {project_language::csharp, "c#"}, {project_language::objectivec, "objective-c"}} [language] : map<project_sdk, ustring> {{project_sdk::cocoa, "cocoa"}, {project_sdk::fltk, "fltk"}, {project_sdk::gtk2, "gtk+2"}, {project_sdk::gtk3, "gtk+3"}, {project_sdk::gtk4, "gtk+4"}, {project_sdk::gtkmm, "gtkmm"}, {project_sdk::wxwidgets, "wxwidgets"}, {project_sdk::qt5, "qt5"}, {project_sdk::qt6, "qt6"}, {project_sdk::win32, "win32"}, {project_sdk::winforms, "winforms"}, {project_sdk::wpf, "wpf"}, {project_sdk::gtest, "gtest"}, {project_sdk::catch2, "catch2"}} [sdk]), project_path));
}

void main_form::open_project() {
  folder_browser_dialog dialog;
  dialog.selected_path(properties::settings::default_settings().open_propject_folder());
  if (dialog.show_sheet_dialog(*this) == dialog_result::ok) open_project(dialog.selected_path());
}

void main_form::open_project(const ustring& project_path) {
  add_to_open_recent_projects(project_path);
  background_worker_ = make_unique<background_worker>();
  background_worker_->do_work += [&](object & sender, do_work_event_args & e) {
    begin_invoke([&] {
      progress_dialog_ = make_unique<progress_dialog>();
      progress_dialog_->text(ustring::format("Opening {} project", path::get_file_name(any_cast<ustring>(e.argument()))));
      progress_dialog_->message("Please wait...");
      progress_dialog_->marquee(true);
      progress_dialog_->show_sheet_dialog(*this);
    });
    process::start(process_start_info().file_name("xtdc").arguments(ustring::format("open {}", any_cast<ustring>(e.argument()))).use_shell_execute(false).create_no_window(true)).wait_for_exit();
  };
  background_worker_->run_worker_completed += [&] {
    begin_invoke([&] {
      progress_dialog_->hide();
      progress_dialog_.reset();
      background_worker_.reset();
      if (properties::settings::default_settings().auto_close()) close();
    });
  };
  background_worker_->run_worker_async(project_path);
}

void main_form::open_xtd_examples() {
  if (menu().has_value()) {
    file_open_project_menu_item_.enabled(false);
    file_run_project_menu_item_.enabled(false);
  }
  startup_panel_.visible(false);
  open_xtd_examples_panel_.visible(true);
  create_panel_.visible(false);
  previous_button_.visible(true);
  next_button_.text("&Open");
  next_button_.visible(true);
  next_button_.enabled(true);
}

void main_form::run_project() {
  folder_browser_dialog dialog;
  dialog.selected_path(properties::settings::default_settings().open_propject_folder());
  if (dialog.show_sheet_dialog(*this) == dialog_result::ok) run_project(dialog.selected_path());
}

void main_form::run_project(const ustring& project_path) {
  add_to_open_recent_projects(project_path);
  background_worker_ = make_unique<background_worker>();
  background_worker_->do_work += [&](object & sender, do_work_event_args & e) {
    begin_invoke([&] {
      progress_dialog_ = make_unique<progress_dialog>();
      progress_dialog_->text(ustring::format("Running {} project", path::get_file_name(any_cast<ustring>(e.argument()))));
      progress_dialog_->message("Please wait...");
      progress_dialog_->marquee(true);
      progress_dialog_->show_sheet_dialog(*this);
    });
    process::start(process_start_info().file_name("xtdc").arguments(ustring::format("run {}", any_cast<ustring>(e.argument()))).use_shell_execute(false).create_no_window(true)).wait_for_exit();
  };
  background_worker_->run_worker_completed += [&] {
    begin_invoke([&] {
      progress_dialog_->hide();
      progress_dialog_.reset();
      background_worker_.reset();
      if (properties::settings::default_settings().auto_close()) close();
    });
  };
  background_worker_->run_worker_async(project_path);
}

void main_form::settings() {
  settings_form_.show();
}

void main_form::show_about_dialog() {
  static about_dialog dialog;
  dialog.icon(system_icons::xtd_logo());
  dialog.name("xtdc-gui");
  dialog.version(environment::version().to_string(2));
  dialog.long_version(environment::version().to_string(3));
  dialog.description("Project management.");
  dialog.copyright("Copyright (c) 2024 Gammasoft.\nAll rights reserved.");
  dialog.website("https://gammasoft71.wixsite.com/gammasoft");
  dialog.website_label("gammasoft website");
  dialog.authors({"Gammasoft", "Bader", "Contributors"});
  dialog.translators({"Gammasoft", "Contributors"});
  dialog.artists({"Gammasoft"});
  dialog.license("MIT License\n"
    "\n"
    "Copyright (c) 2024 Gammasoft.\n"
    "\n"
    "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n"
    "\n"
    "The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n"
    "\n"
    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n");
  dialog.show();
}

void main_form::update_open_xtd_examples(const xtd_example_item& item, const xtd::ustring& context) {
  // Description
  update_open_xtd_examples_description(item.description().empty() ? "Coming soon..."_s : item.description());
  // Picture or Output
  if (item.picture() != xtd::drawing::image::empty)
    update_open_xtd_examples_picture(item.picture());
  else if (!item.output().empty())
    update_open_xtd_examples_output(item.output());
  else
    update_open_xtd_examples_picture(images::from_name(context, drawing::size{ 1024, 1024 }));
}

void main_form::update_open_xtd_examples_description(const xtd::ustring& description) {
  open_xtd_examples_information_link_label_.text("");
  open_xtd_examples_information_link_label_.links().clear();
  if (description.empty()) return;
  static const std::regex rgx_md_link(R"(\[(.*?)\]\((.*?)\))", std::regex::optimize);
  xtd::ustring text = description;
  std::sregex_iterator iterator(description.begin(), description.end(), rgx_md_link), end{};
  for (auto it = iterator; it != end; ++it) {
    if (it->size() == 3) { // 3 matches: whole []() + sub [] + sub ()
      const xtd::ustring whole = it->str(0); // []()
      const xtd::ustring title = it->str(1); // [] contents
      xtd::ustring link = it->str(2);        // () contents
      // Todo: if it's not a link, maybe a file e.g ../../CMakeLists.txt
      // open a google search in xtd documentation for now...
      if (!link.starts_with("http"))
        link = xtd::ustring::format("https://www.google.com/search?q={}+site:https://gammasoft71.github.io/xtd/reference_guides/latest", title);
      // Replace all markdown links [title](url) with title
      text = text.replace(whole, title);
      open_xtd_examples_information_link_label_.links().push_back(xtd::forms::link(it->position(), title.length(), link));
    }
  }
  
  open_xtd_examples_information_link_label_.text(text);
  if (iterator == end) open_xtd_examples_information_link_label_.links().clear();
}

void main_form::update_open_xtd_examples_picture(const xtd::drawing::image& picture) {
  open_xtd_examples_information_output_text_box_.visible(false);
  open_xtd_examples_information_picture_box_.visible(true);
  open_xtd_examples_information_picture_box_.image(picture);
}

void main_form::update_open_xtd_examples_output(const xtd::ustring& output) {
  open_xtd_examples_information_output_text_box_.visible(true);
  open_xtd_examples_information_picture_box_.visible(false);
  open_xtd_examples_information_output_text_box_.text(output);
}

void main_form::main() {
  application::run(main_form());
}
