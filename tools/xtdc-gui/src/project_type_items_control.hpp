/// @file
/// @brief Contains project_type_item_control class.
#pragma once
#include <limits>
#include <xtd/as>
#include <xtd/size_object>
#include <xtd/drawing/bitmap>
#include <xtd/forms/application>
#include "project_type_item_control.hpp"
#include "../resources/catch2.xpm"
#include "../resources/cocoa.xpm"
#include "../resources/console.xpm"
#include "../resources/fltk.xpm"
#include "../resources/gtest.xpm"
#include "../resources/gtk.xpm"
#include "../resources/qt.xpm"
#include "../resources/sharedlib.xpm"
#include "../resources/solution.xpm"
#include "../resources/staticlib.xpm"
#include "../resources/win32.xpm"
#include "../resources/winforms.xpm"
#include "../resources/wpf.xpm"
#include "../resources/wxwidgets.xpm"
#include "../resources/xtd_console.xpm"
#include "../resources/xtd_gui.xpm"
#include "../resources/xtd_sharedlib.xpm"
#include "../resources/xtd_staticlib.xpm"
#include "../resources/xtd_solution.xpm"
#include "../resources/xtd_tunit.xpm"

namespace xtdc_gui {
  /// @brief Represents the project_type_items_control control
  class project_type_items_control : public xtd::forms::user_control {
  public:
    /// @brief Initializes a new instance of the project_type_item_control class.
    project_type_items_control() {
      auto project_type_items = xtd::array<project_type_item> {
        {xtd::drawing::bitmap::from_xpm_data(solution_icon), "Solution File", "A project for creating an empty solution file.", project_language::all & ~project_language::xtd & ~project_language::xtd_c, project_sdk::none, project_platform::all, project_type::solution_file},
        {xtd::drawing::bitmap::from_xpm_data(xtd_solution_icon), "xtd Solution File", "A project for creating an empty xtd solution file.", project_language::xtd, project_sdk::none, project_platform::all, project_type::solution_file},
        {xtd::drawing::bitmap::from_xpm_data(xtd_solution_icon), "xtd_c Solution File", "A project for creating an empty xtd_c solution file.", project_language::xtd_c, project_sdk::none, project_platform::all, project_type::solution_file},
        {xtd::drawing::bitmap::from_xpm_data(catch2_icon), "catch2 Unit Test project (c++)", "A project for creating a catch2 unit tests application.", project_language::cpp, project_sdk::catch2, project_platform::all, project_type::unit_tests_project},
        {xtd::drawing::bitmap::from_xpm_data(gtest_icon), "gtest Unit Test project (c++)", "A project for creating a gtest unit tests application.", project_language::cpp, project_sdk::gtest, project_platform::all, project_type::unit_tests_project},
        {xtd::drawing::bitmap::from_xpm_data(xtd_tunit_icon), "xtd Unit Test project (c++)", "A project for creating a xtd unit tests application.", project_language::xtd, project_sdk::none, project_platform::all, project_type::unit_tests_project},
        {xtd::drawing::bitmap::from_xpm_data(xtd_tunit_icon), "xtd_c Unit Test project (c)", "A project for creating a xtd unit tests application.", project_language::xtd_c, project_sdk::none, project_platform::all, project_type::unit_tests_project},
        {xtd::drawing::bitmap::from_xpm_data(staticlib_icon), "Static library (objective-c)", "A project for creating a objective-c static class library.", project_language::objectivec, project_sdk::none, project_platform::macos, project_type::static_library},
        {xtd::drawing::bitmap::from_xpm_data(staticlib_icon), "Static library (c#)", "A project for creating a c# static class library.", project_language::csharp, project_sdk::none, project_platform::windows, project_type::static_library},
        {xtd::drawing::bitmap::from_xpm_data(staticlib_icon), "Static library (c)", "A project for creating a c static library.", project_language::c, project_sdk::none, project_platform::all, project_type::static_library},
        {xtd::drawing::bitmap::from_xpm_data(staticlib_icon), "Static library (c++)", "A project for creating a c++ static class library.", project_language::cpp, project_sdk::none, project_platform::all, project_type::static_library},
        {xtd::drawing::bitmap::from_xpm_data(xtd_staticlib_icon), "xtd Static library (c++)", "A project for creating a xtd static class library.", project_language::xtd, project_sdk::none, project_platform::all, project_type::static_library},
        {xtd::drawing::bitmap::from_xpm_data(xtd_staticlib_icon), "xtd_c Static library (c)", "A project for creating a xtd_c static class library.", project_language::xtd_c, project_sdk::none, project_platform::all, project_type::static_library},
        {xtd::drawing::bitmap::from_xpm_data(sharedlib_icon), "Shared library (objective-c)", "A project for creating a objective-c shared class library.", project_language::objectivec, project_sdk::none, project_platform::macos, project_type::shared_library},
        {xtd::drawing::bitmap::from_xpm_data(sharedlib_icon), "Shared library (c#)", "A project for creating a c# shared class library.", project_language::csharp, project_sdk::none, project_platform::windows, project_type::shared_library},
        {xtd::drawing::bitmap::from_xpm_data(sharedlib_icon), "Shared library (c)", "A project for creating a c shared library.", project_language::c, project_sdk::none, project_platform::all, project_type::shared_library},
        {xtd::drawing::bitmap::from_xpm_data(sharedlib_icon), "Shared library (c++)", "A project for creating a c++ shared class library.", project_language::cpp, project_sdk::none, project_platform::all, project_type::shared_library},
        {xtd::drawing::bitmap::from_xpm_data(xtd_sharedlib_icon), "xtd Shared library (c++)", "A project for creating a xtd shared class library.", project_language::xtd, project_sdk::none, project_platform::all, project_type::shared_library},
        {xtd::drawing::bitmap::from_xpm_data(xtd_sharedlib_icon), "xtd_c Shared library (c)", "A project for creating a xtd_c shared class library.", project_language::xtd_c, project_sdk::none, project_platform::all, project_type::shared_library},
        {xtd::drawing::bitmap::from_xpm_data(console_icon), "Console Application (objective-c)", "A project for creating an objective-c command-line application.", project_language::objectivec, project_sdk::none, project_platform::macos, project_type::console},
        {xtd::drawing::bitmap::from_xpm_data(console_icon), "Console Application (c#)", "A project for creating a c# command-line application.", project_language::csharp, project_sdk::none, project_platform::windows, project_type::console},
        {xtd::drawing::bitmap::from_xpm_data(console_icon), "Console Application (c)", "A project for creating a c command-line application.", project_language::c, project_sdk::none, project_platform::all, project_type::console},
        {xtd::drawing::bitmap::from_xpm_data(console_icon), "Console Application (c++)", "A project for creating a c++ command-line application.", project_language::cpp, project_sdk::none, project_platform::all, project_type::console},
        {xtd::drawing::bitmap::from_xpm_data(xtd_console_icon), "xtd Console Application (c++)", "A project for creating a xtd command-line application.", project_language::xtd, project_sdk::none, project_platform::all, project_type::console},
        {xtd::drawing::bitmap::from_xpm_data(xtd_console_icon), "xtd_c Console Application (c)", "A project for creating a xtd_c command-line application.", project_language::xtd_c, project_sdk::none, project_platform::all, project_type::console},
        {xtd::drawing::bitmap::from_xpm_data(cocoa_icon), "Cocoa UI Application (objective-c)", "A project for creating a cocoa application with a graphic user\ninterface.", project_language::objectivec, project_sdk::cocoa, project_platform::macos, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(gtk_icon), "Gtkmm GUI Application (c++)", "A project for creating a gtkmm application with a graphic user\ninterface.", project_language::cpp, project_sdk::gtkmm, project_platform::linux, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(gtk_icon), "Gtk+4 GUI Application (c)", "A project for creating a gtk+4 application with a graphic user\ninterface.", project_language::c, project_sdk::gtk4, project_platform::linux, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(gtk_icon), "Gtk+3 GUI Application (c)", "A project for creating a gtk+3 application with a graphic user\ninterface.", project_language::c, project_sdk::gtk3, project_platform::linux, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(gtk_icon), "Gtk+2 GUI Application (c)", "A project for creating a gtk+2 application with a graphic user\ninterface.", project_language::c, project_sdk::gtk2, project_platform::linux, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(wpf_icon), "WPF GUI Application (c#)", "A project for creating a WPF application with a graphic user\ninterface.", project_language::csharp, project_sdk::wpf, project_platform::windows, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(winforms_icon), "Winforms GUI Application (c#)", "A project for creating a Winforms application with a graphic user\ninterface.", project_language::csharp, project_sdk::winforms, project_platform::windows, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(win32_icon), "Win32 GUI Application (c)", "A project for creating a Win32 application with a graphic user\ninterface.", project_language::c, project_sdk::win32, project_platform::windows, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(fltk_icon), "fltk GUI Application (c++)", "A project for creating a fltk application with a graphic user\ninterface.", project_language::cpp, project_sdk::fltk, project_platform::all, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(qt_icon), "Qt6 GUI Application (c++)", "A project for creating a Qt6 application with a graphic user interface.", project_language::cpp, project_sdk::qt6, project_platform::all, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(qt_icon), "Qt5 GUI Application (c++)", "A project for creating a Qt5 application with a graphic user interface.", project_language::cpp, project_sdk::qt5, project_platform::all, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(wxwidgets_icon), "wxWidgets GUI Application (c++)", "A project for creating a wxWidgets application with a graphic user\ninterface.", project_language::cpp, project_sdk::wxwidgets, project_platform::all, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(xtd_gui_icon), "xtd GUI Application (c++)", "A project for creating a xtd application with a graphic user interface.", project_language::xtd, project_sdk::none, project_platform::all, project_type::gui},
        {xtd::drawing::bitmap::from_xpm_data(xtd_gui_icon), "xtd_c GUI Application (c)", "A project for creating a xtd_c application with a graphic user interface.", project_language::xtd_c, project_sdk::none, project_platform::all, project_type::gui},
      };
      
      for (auto item : project_type_items) {
        auto item_control = xtd::new_sptr<project_type_item_control>(item);
        item_control->parent(*this);
        item_control->dock(xtd::forms::dock_style::top);
        item_control->tag(project_type_item_controls_.count());
        project_type_item_controls_.add(item_control);
        item_control->click += [&](object & sender, const xtd::event_args & e) {
          selected_index(project_type_item_controls_.count() - 1 - xtd::as<size_t>(xtd::as<control>(sender).tag()));
        };
      }
      
      auto_scroll(true);
      padding(4);
      back_color(xtd::forms::application::style_sheet().system_colors().window());
      border_style(xtd::forms::border_style::fixed_single);
    }
    
    size_t selected_index() const {return selected_index_;}
    void selected_index(size_t value) {
      if (selected_index_ != value) {
        selected_index_ = value;
        on_selected_index_changed(xtd::event_args::empty);
      }
    }
    
    const project_type_item& selected_project_type_item() const {return selected_project_type_item_;}
    void selected_project_type_item(const project_type_item& value) {
      if (selected_project_type_item_ != value) {
        selected_project_type_item_ = value;
        on_selected_project_type_item_changed(xtd::event_args::empty);
      }
    }
    
    void filter_items(project_language language, project_platform platform, project_type type) {
      for (auto item : project_type_item_controls_)
        item->visible((language == project_language::all || (item->project_type_item().project_language() & language) == language) && (platform == project_platform::all || (item->project_type_item().project_platform() & platform) == platform) && (type == project_type::all || (item->project_type_item().project_type() & type) == type));
      perform_layout();
      selected_index(npos);
    }
    
    xtd::event<project_type_items_control, xtd::event_handler> selected_index_changed;
    xtd::event<project_type_items_control, xtd::event_handler> selected_project_type_item_changed;
    
    void perform_double_click() {on_double_click(xtd::event_args::empty);}
    
    xtd::array<project_type_item> project_type_items() const {
      xtd::collections::generic::list<project_type_item> items;
      for (auto it = project_type_item_controls_.items().rbegin(); it != project_type_item_controls_.items().rend(); ++it)
        items.add((*it)->project_type_item());
      return items.to_array();
    }
    
    /// @brief Represents a value that is not a valid position in a collection.
    /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::size.
    inline static constexpr xtd::size npos = xtd::collections::generic::list<xtd::sptr<project_type_item_control>>::npos;
    
    /// @brief Represents the index of the first valid element in a collection.
    /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
    static inline constexpr xtd::size bpos = xtd::collections::generic::list<xtd::sptr<project_type_item_control>>::bpos;
    
    /// @brief Represents the index of the last valid element in a collection.
    /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
    /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
    /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
    static inline constexpr xtd::size epos = xtd::collections::generic::list<xtd::sptr<project_type_item_control>>::epos;
    
  protected:
    xtd::uptr<xtd::object> clone() const override {
      auto result = xtd::new_uptr<project_type_items_control>(*this);
      if (typeof_(*result) != typeof_(*this)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
      return result;
    }
    
  private:
    void on_selected_index_changed(const xtd::event_args& e) {
      if (previous_selected_index_ != npos) {
        project_type_item_controls_[project_type_item_controls_.count() - 1 - previous_selected_index_]->back_color(back_color());
        project_type_item_controls_[project_type_item_controls_.count() - 1 - previous_selected_index_]->fore_color(fore_color());
      }
      if (selected_index_ != npos) {
        project_type_item_controls_[project_type_item_controls_.count() - 1 - selected_index_]->back_color(xtd::forms::application::style_sheet().system_colors().accent());
        project_type_item_controls_[project_type_item_controls_.count() - 1 - selected_index_]->fore_color(xtd::forms::application::style_sheet().system_colors().accent_text());
        selected_project_type_item(project_type_item_controls_[project_type_item_controls_.count() - 1 - selected_index_]->project_type_item());
      }
      previous_selected_index_ = selected_index_;
      selected_index_changed(*this, e);
    }
    
    void on_selected_project_type_item_changed(const xtd::event_args& e) {
      for (auto item : project_type_item_controls_)
        if (item->project_type_item() == selected_project_type_item_) {
          selected_index(project_type_item_controls_.count() - 1 - xtd::as<size_t>(item->tag()));
          break;
        }
      selected_project_type_item_changed(*this, e);
    }
    
    xtd::collections::generic::list<xtd::sptr<project_type_item_control>> project_type_item_controls_;
    size_t previous_selected_index_ = npos;
    size_t selected_index_ = npos;
    project_type_item selected_project_type_item_;
  };
}
