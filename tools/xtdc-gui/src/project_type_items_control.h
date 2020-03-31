/// @file
/// @brief Contains project_type_item_control class.
#pragma once
#include "project_type_item_control.h"

namespace xtdc_gui {
  /// @brief Represents the project_type_items_control control
  class project_type_items_control : public xtd::forms::user_control {
  public:
    /// @brief Initializes a new instance of the project_type_item_control class.
    project_type_items_control() {
      std::vector<project_type_item> project_type_items {
        {"Solution File", "A project for creating an empty solution file.", project_language::all&~project_language::xtd, project_platform::all, project_type::solution_file},
        {"xtd Solution File", "A project for creating an empty xtd solution file.", project_language::xtd, project_platform::all, project_type::solution_file},
        {"catch2 Unit Test project (c++)", "A project for creating a catch2 unit tests application.", project_language::cpp, project_platform::all, project_type::unit_tests_project},
        {"gtest Unit Test project (c++)", "A project for creating a gtest unit tests application.", project_language::cpp, project_platform::all, project_type::unit_tests_project},
        {"xtd Unit Test project (c++)", "A project for creating a xtd unit tests application.", project_language::xtd, project_platform::all, project_type::unit_tests_project},
        {"Static library (objective-c)", "A project for creating a objective-c static class library.", project_language::objectivec, project_platform::macos, project_type::static_library},
        {"Static library (c#)", "A project for creating a c# static class library.", project_language::csharp, project_platform::windows, project_type::static_library},
        {"Static library (c)", "A project for creating a c static library.", project_language::c, project_platform::all, project_type::static_library},
        {"Static library (c++)", "A project for creating a c++ static class library.", project_language::cpp, project_platform::all, project_type::static_library},
        {"xtd Static library (c++)", "A project for creating a xtd static class library.", project_language::xtd, project_platform::all, project_type::static_library},
        {"Shared library (objective-c)", "A project for creating a objective-c shared class library.", project_language::objectivec, project_platform::macos, project_type::shared_library},
        {"Shared library (c#)", "A project for creating a c# shared class library.", project_language::csharp, project_platform::windows, project_type::shared_library},
        {"Shared library (c)", "A project for creating a c shared library.", project_language::c, project_platform::all, project_type::shared_library},
        {"Shared library (c++)", "A project for creating a c++ shared class library.", project_language::cpp, project_platform::all, project_type::shared_library},
        {"xtd Shared library (c++)", "A project for creating a xtd shared class library.", project_language::xtd, project_platform::all, project_type::shared_library},
        {"Console Application (objective-c)", "A project for creating an objective-c command-line application.", project_language::objectivec, project_platform::macos, project_type::console},
        {"Console Application (c#)", "A project for creating a c# command-line application.", project_language::csharp, project_platform::windows, project_type::console},
        {"Console Application (c)", "A project for creating a c command-line application.", project_language::c, project_platform::all, project_type::console},
        {"Console Application (c++)", "A project for creating a c++ command-line application.", project_language::cpp, project_platform::all, project_type::console},
        {"xtd Console Application (c++)", "A project for creating a xtd command-line application.", project_language::xtd, project_platform::all, project_type::console},
        {"Cocoa UI Application (objective-c)", "A project for creating a cocoa application with a graphic user\ninterface.", project_language::objectivec, project_platform::macos, project_type::gui},
        {"Gtkmm GUI Application (c++)", "A project for creating a gtkmm application with a graphic user\ninterface.", project_language::cpp, project_platform::linux, project_type::gui},
        {"Gtk+3 GUI Application (c)", "A project for creating a gtk+3 application with a graphic user\ninterface.", project_language::c, project_platform::linux, project_type::gui},
        {"Gtk+2 GUI Application (c)", "A project for creating a gtk+2 application with a graphic user\ninterface.", project_language::c, project_platform::linux, project_type::gui},
        {"WPF GUI Application (c#)", "A project for creating a WPF application with a graphic user\ninterface.", project_language::csharp, project_platform::windows, project_type::gui},
        {"Winforms GUI Application (c#)", "A project for creating a Winforms application with a graphic user\ninterface.", project_language::csharp, project_platform::windows, project_type::gui},
        {"Win32 GUI Application (c)", "A project for creating a Win32 application with a graphic user\ninterface.", project_language::c, project_platform::windows, project_type::gui},
        {"fltk GUI Application (c++)", "A project for creating a fltk application with a graphic user\ninterface.", project_language::cpp, project_platform::all, project_type::gui},
        {"Qt GUI Application (c++)", "A project for creating a Qt application with a graphic user interface.", project_language::cpp, project_platform::all, project_type::gui},
        {"wxWidgets GUI Application (c++)", "A project for creating a wxWidgets application with a graphic user\ninterface.", project_language::cpp, project_platform::all, project_type::gui},
        {"xtd GUI Application (c++)", "A project for creating a xtd application with a graphic user interface.", project_language::xtd, project_platform::all, project_type::gui},
      };
      
      for (auto item : project_type_items) {
        auto item_control = std::make_shared<project_type_item_control>(item);
        item_control->parent(*this);
        item_control->dock(xtd::forms::dock_style::top);
        item_control->tag(project_type_item_controls_.size());
        project_type_item_controls_.push_back(item_control);
        item_control->click += [&](control& sender, const xtd::event_args& e) {
          selected_index(project_type_item_controls_.size() - 1 - std::any_cast<size_t>(sender.tag()));
        };
      }
      
      auto_scroll(true);
      back_color(xtd::drawing::system_colors::window());
      border_style(xtd::forms::border_style::fixed_3d);
    }

    size_t selected_index() const {return selected_index_;}
    void selected_index(size_t value) {
      if (selected_index_ != value) {
        selected_index_ = value;
        on_selected_index_changed(xtd::event_args::empty);
      }
    }

    const project_type_item& selected_project_type_item() const {return this->selected_project_type_item_;}
    void selected_project_type_item(const project_type_item& value) {
      if (selected_project_type_item_ != value) {
        selected_project_type_item_ = value;
        on_selected_project_type_item_changed(xtd::event_args::empty);
      }
    }

    void filter_items(project_language language, project_platform platform, project_type type) {
      for (auto& item : project_type_item_controls_)
        item->visible((language == project_language::all || (item->project_type_item().project_language() & language) == language) && (platform == project_platform::all || (item->project_type_item().project_platform() & platform) == platform) && (type == project_type::all || (item->project_type_item().project_type() & type) == type));
      if (selected_index_ != -1 && !project_type_item_controls_[selected_index_]->visible()) selected_index(-1);
      perform_layout();
    }
    
    xtd::event<project_type_items_control, xtd::event_handler<xtd::forms::control&>> selected_index_changed;
    xtd::event<project_type_items_control, xtd::event_handler<xtd::forms::control&>> selected_project_type_item_changed;
    
  private:
    void on_selected_index_changed(const xtd::event_args& e) {
      if (previous_selected_index_ != -1) project_type_item_controls_[project_type_item_controls_.size() - 1 - previous_selected_index_]->back_color(back_color());
      if (selected_index_ != -1) {
        project_type_item_controls_[project_type_item_controls_.size() - 1 - selected_index_]->back_color(xtd::drawing::system_colors::menu_highlight());
        selected_project_type_item(project_type_item_controls_[project_type_item_controls_.size() - 1 - selected_index_]->project_type_item());
      }
      previous_selected_index_ = selected_index_;
      selected_index_changed(*this, e);
    }
    
    void on_selected_project_type_item_changed(const xtd::event_args& e) {
      for (auto item : project_type_item_controls_)
        if (item->project_type_item() == selected_project_type_item_) {
          selected_index(project_type_item_controls_.size() - 1 - std::any_cast<size_t>(item->tag()));
          break;
        }
      selected_project_type_item_changed(*this, e);
    }

    std::vector<std::shared_ptr<project_type_item_control>> project_type_item_controls_;
    size_t previous_selected_index_ = -1;
    size_t selected_index_ = -1;
    project_type_item selected_project_type_item_;
  };
}
