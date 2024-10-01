/// @file
/// @brief Contains xtd::drawing::texts factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include <xtd/static>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Provides a collection of string objects for use by a Windows Forms application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/texts>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_drawing texts
    /// @par Examples
    /// The following code example demonstrates the use of texts class.
    /// @include texts.cpp
    class drawing_export_ texts final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a system-defined text that has a string value of "&Abort". This field is constant.
      static xtd::string abort();
      /// @brief Gets a system-defined text that has a string value of "&About". This field is constant.
      static xtd::string about();
      /// @brief Gets a system-defined text that has a string value of "&Actual Size". This field is constant.
      static xtd::string actual_size();
      /// @brief Gets a system-defined text that has a string value of "Add". This field is constant.
      static xtd::string add();
      /// @brief Gets a system-defined text that has a string value of "Alignment". This field is constant.
      static xtd::string alignment();
      /// @brief Gets a system-defined text that has a string value of "Align Left". This field is constant.
      static xtd::string align_left();
      /// @brief Gets a system-defined text that has a string value of "Align Right". This field is constant.
      static xtd::string align_right();
      /// @brief Gets a system-defined text that has a string value of "&Apply". This field is constant.
      static xtd::string apply();
      /// @brief Gets a system-defined text that has a string value of "&Ascending". This field is constant.
      static xtd::string ascending();
      /// @brief Gets a system-defined text that has a string value of "&Back". This field is constant.
      static xtd::string back();
      /// @brief Gets a system-defined text that has a string value of "&Bold". This field is constant.
      static xtd::string bold();
      /// @brief Gets a system-defined text that has a string value of "&Bottom". This field is constant.
      static xtd::string bottom();
      /// @brief Gets a system-defined text that has a string value of "&Cancel". This field is constant.
      static xtd::string cancel();
      /// @brief Gets a system-defined text that has a string value of "&CD-Rom". This field is constant.
      static xtd::string cdrom();
      /// @brief Gets a system-defined text that has a string value of "Centered". This field is constant.
      static xtd::string centered();
      /// @brief Gets a system-defined text that has a string value of "&Clear". This field is constant.
      static xtd::string clear();
      /// @brief Gets a system-defined text that has a string value of "&Close". This field is constant.
      static xtd::string close();
      /// @brief Gets a system-defined text that has a string value of "&Color". This field is constant.
      static xtd::string color();
      /// @brief Gets a system-defined text that has a string value of "&Contents". This field is constant.
      static xtd::string contents();
      /// @brief Gets a system-defined text that has a string value of "&Convert". This field is constant.
      static xtd::string convert();
      /// @brief Gets a system-defined text that has a string value of "&Copy". This field is constant.
      static xtd::string copy();
      /// @brief Gets a system-defined text that has a string value of "&Customize". This field is constant.
      static xtd::string customize();
      /// @brief Gets a system-defined text that has a string value of "Cu&t". This field is constant.
      static xtd::string cut();
      /// @brief Gets a system-defined text that has a string value of "&Delete". This field is constant.
      static xtd::string del();
      /// @brief Gets a system-defined text that has a string value of "&Descending". This field is constant.
      static xtd::string descending();
      /// @brief Gets a system-defined text that has a string value of "&Down". This field is constant.
      static xtd::string down();
      /// @brief Gets a system-defined text that has a string value of "&Edit". This field is constant.
      static xtd::string edit();
      /// @brief Gets a system-defined text that has a string value of "&Execute". This field is constant.
      static xtd::string execute();
      /// @brief Gets a system-defined text that has a string value of "E&xit". This field is constant.
      static xtd::string exit();
      /// @brief Gets a system-defined text that has a string value of "&File". This field is constant.
      static xtd::string file();
      /// @brief Gets a system-defined text that has a string value of "&Find...". This field is constant.
      static xtd::string find();
      /// @brief Gets a system-defined text that has a string value of "&First". This field is constant.
      static xtd::string first();
      /// @brief Gets a system-defined text that has a string value of "&Floppy". This field is constant.
      static xtd::string floppy();
      /// @brief Gets a system-defined text that has a string value of "&Font". This field is constant.
      static xtd::string font();
      /// @brief Gets a system-defined text that has a string value of "&Forward". This field is constant.
      static xtd::string forward();
      /// @brief Gets a system-defined text that has a string value of "&Harddisk". This field is constant.
      static xtd::string harddisk();
      /// @brief Gets a system-defined text that has a string value of "&Help". This field is constant.
      static xtd::string help();
      /// @brief Gets a system-defined text that has a string value of "&Home". This field is constant.
      static xtd::string home();
      /// @brief Gets a system-defined text that has a string value of "&Ignore". This field is constant.
      static xtd::string ignore();
      /// @brief Gets a system-defined text that has a string value of "Indent". This field is constant.
      static xtd::string indent();
      /// @brief Gets a system-defined text that has a string value of "&Index". This field is constant.
      static xtd::string index();
      /// @brief Gets a system-defined text that has a string value of "&Info". This field is constant.
      static xtd::string info();
      /// @brief Gets a system-defined text that has a string value of "&Italic". This field is constant.
      static xtd::string italic();
      /// @brief Gets a system-defined text that has a string value of "Justified". This field is constant.
      static xtd::string justified();
      /// @brief Gets a system-defined text that has a string value of "&Jump to". This field is constant.
      static xtd::string jump_to();
      /// @brief Gets a system-defined text that has a string value of "&Last". This field is constant.
      static xtd::string last();
      /// @brief Gets a system-defined text that has a string value of "&Network". This field is constant.
      static xtd::string network();
      /// @brief Gets a system-defined text that has a string value of "&New". This field is constant.
      static xtd::string new_();
      /// @brief Gets a system-defined text that has a string value of "&Next". This field is constant.
      static xtd::string next();
      /// @brief Gets a system-defined text that has a string value of "&No". This field is constant.
      static xtd::string no();
      /// @brief Gets a system-defined text that has a string value of "&OK". This field is constant.
      static xtd::string ok();
      /// @brief Gets a system-defined text that has a string value of "&Open...". This field is constant.
      static xtd::string open();
      /// @brief Gets a system-defined text that has a string value of "&Options". This field is constant.
      static xtd::string options();
      /// @brief Gets a system-defined text that has a string value of "&Paste". This field is constant.
      static xtd::string paste();
      /// @brief Gets a system-defined text that has a string value of "&Preference". This field is constant.
      static xtd::string preferences();
      /// @brief Gets a system-defined text that has a string value of "&Previous". This field is constant.
      static xtd::string previous();
      /// @brief Gets a system-defined text that has a string value of "&Print...". This field is constant.
      static xtd::string print();
      /// @brief Gets a system-defined text that has a string value of "Print Re&view". This field is constant.
      static xtd::string print_preview();
      /// @brief Gets a system-defined text that has a string value of "&Properties". This field is constant.
      static xtd::string properties();
      /// @brief Gets a system-defined text that has a string value of "&Quit". This field is constant.
      static xtd::string quit();
      /// @brief Gets a system-defined text that has a string value of "&Redo". This field is constant.
      static xtd::string redo();
      /// @brief Gets a system-defined text that has a string value of "Refresh". This field is constant.
      static xtd::string refresh();
      /// @brief Gets a system-defined text that has a string value of "Remove". This field is constant.
      static xtd::string remove();
      /// @brief Gets a system-defined text that has a string value of "Rep&lace". This field is constant.
      static xtd::string replace();
      /// @brief Gets a system-defined text that has a string value of "&Retry". This field is constant.
      static xtd::string retry();
      /// @brief Gets a system-defined text that has a string value of "Revert to Saved". This field is constant.
      static xtd::string revert_to_saved();
      /// @brief Gets a system-defined text that has a string value of "&Save". This field is constant.
      static xtd::string save();
      /// @brief Gets a system-defined text that has a string value of "Save &As...". This field is constant.
      static xtd::string save_as();
      /// @brief Gets a system-defined text that has a string value of "&Search". This field is constant.
      static xtd::string search();
      /// @brief Gets a system-defined text that has a string value of "Select &All". This field is constant.
      static xtd::string select_all();
      /// @brief Gets a system-defined text that has a string value of "&Settings...". This field is constant.
      static xtd::string settings();
      /// @brief Gets a system-defined text that has a string value of "&Spell Check". This field is constant.
      static xtd::string spell_check();
      /// @brief Gets a system-defined text that has a string value of "&Stop". This field is constant.
      static xtd::string stop();
      /// @brief Gets a system-defined text that has a string value of "&Strikeout". This field is constant.
      static xtd::string strikeout();
      /// @brief Gets a system-defined text that has a string value of "&Tools". This field is constant.
      static xtd::string tools();
      /// @brief Gets a system-defined text that has a string value of "&Top". This field is constant.
      static xtd::string top();
      /// @brief Gets a system-defined text that has a string value of "Undelete". This field is constant.
      static xtd::string undelete();
      /// @brief Gets a system-defined text that has a string value of "&Underline". This field is constant.
      static xtd::string underline();
      /// @brief Gets a system-defined text that has a string value of "&Undo". This field is constant.
      static xtd::string undo();
      /// @brief Gets a system-defined text that has a string value of "Unindent". This field is constant.
      static xtd::string unindent();
      /// @brief Gets a system-defined text that has a string value of "&Up". This field is constant.
      static xtd::string up();
      /// @brief Gets a system-defined text that has a string value of "&View". This field is constant.
      static xtd::string view();
      /// @brief Gets a system-defined text that has a string value of "&Window". This field is constant.
      static xtd::string window();
      /// @brief Gets a system-defined text that has a string value of "&Yes". This field is constant.
      static xtd::string yes();
      /// @brief Gets a system-defined text that has a string value of "Zoom &In". This field is constant.
      static xtd::string zoom_in();
      /// @brief Gets a system-defined text that has a string value of "Zoom &Out". This field is constant.
      static xtd::string zoom_out();
      /// @brief Gets a system-defined text that has a string value of "Zoom to &Fit". This field is constant.
      static xtd::string zoom_to_fit();
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of texts.
      static const std::vector<xtd::string>& get_texts() noexcept;
      /// @}
    };
  }

  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of string objects for use by a Windows Forms application.
    /// @deprecated Replaced by xtd::drawing::texts - Will be removed in version 0.4.0.
    using system_texts [[deprecated("Replaced by xtd::drawing::texts - Will be removed in version 0.4.0.")]] = xtd::drawing::texts;
  }
}
