#include "main_form.h"
#include <xtd/forms/application.h>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtdc_gui;

main_form::main_form() {
  text("xtdc-gui");
  client_size({1024, 700});
  minimize_box(false);
  maximize_box(false);
  //form_border_style(xtd::forms::form_border_style::fixed_dialog);
  
  create_panel_.parent(*this);
  create_panel_.size(client_size() - xtd::drawing::size {0, 100});
  create_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  //create_panel_.back_color(color::red);

  create_title_label_.parent(create_panel_);
  create_title_label_.location({50, 50});
  create_title_label_.auto_size(true);
  create_title_label_.text("Create a new project");
  create_title_label_.font({create_title_label_.font(), 24.0});
  
  recent_project_title_label_.parent(create_panel_);
  recent_project_title_label_.location({50, 115});
  recent_project_title_label_.auto_size(true);
  recent_project_title_label_.text("Recent project templates");
  recent_project_title_label_.font({create_title_label_.font(), 16.0});
  
  recent_projects_list_box_.parent(create_panel_);
  recent_projects_list_box_.location({50, 175});
  recent_projects_list_box_.size({400, create_panel_.size().height() - 175});
  recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  recent_projects_list_box_.items().push_back_range({"gui_app1 (GUI Application - xtd)", "console_app1 (Console Application - xtd)"});
  recent_projects_list_box_.selected_index(0);
  
  language_choice_.parent(create_panel_);
  language_choice_.width(140);
  language_choice_.location({create_panel_.size().width() - template_choice_.width() - 400, 50});
  language_choice_.anchor(anchor_styles::top|anchor_styles::right);
  language_choice_.items().push_back_range({"All", "xtd", "c++", "c", "c#", "objective-c"});
  language_choice_.selected_index(0);

  platform_choice_.parent(create_panel_);
  platform_choice_.width(140);
  platform_choice_.location({create_panel_.size().width() - template_choice_.width() - 230, 50});
  platform_choice_.anchor(anchor_styles::top|anchor_styles::right);
  platform_choice_.items().push_back_range({"All", "Windows", "macOS", "Linux"});
  platform_choice_.selected_index(0);
  
  template_choice_.parent(create_panel_);
  template_choice_.width(140);
  template_choice_.location({create_panel_.size().width() - template_choice_.width() - 50, 50});
  template_choice_.anchor(anchor_styles::top|anchor_styles::right);
  template_choice_.items().push_back_range({"All", "Gui", "Console", "Shared library", "Static library", "UnitTest Project", "Solution File"});
  template_choice_.selected_index(0);
  
  items_panel_.parent(create_panel_);
  items_panel_.location({create_panel_.size().width() - 475 - 50, 100});
  items_panel_.size({475, create_panel_.size().height() - 100});
  items_panel_.back_color(system_colors::window());
  items_panel_.border_style(xtd::forms::border_style::fixed_3d);
  items_panel_.anchor(anchor_styles::top|anchor_styles::bottom|anchor_styles::right);
  
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

  cancel_button_.parent(*this);
  cancel_button_.text("&Cancel");
  cancel_button_.location(client_size() - xtd::drawing::size {215, 75});
  cancel_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  cancel_button_.click += [&] {
    if (create_panel_.visible()) {
      close();
    } else {
      cancel_button_.text("&Cancel");
      create_panel_.visible(true);
      configure_panel_.visible(false);
    }
  };

  create_button_.parent(*this);
  create_button_.text("&Next");
  create_button_.location(client_size() - xtd::drawing::size {125, 75});
  create_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  create_button_.click += [&] {
    if (!create_panel_.visible()) {
      hide();
      close();
      application::do_events();
      system("xtdc new gui /Users/yves/Projects/gui_app1");
      system("xtdc open /Users/yves/Projects/gui_app1");
    } else {
      cancel_button_.text("&Back");
      create_button_.text("&Create");
      create_panel_.visible(false);
      configure_panel_.visible(true);
    }
  };
}

void main_form::main() {
  application::enable_visual_styles();
  application::run(main_form());
}
