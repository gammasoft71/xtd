/// @file
/// @brief Contains xtd::drawing::texts factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
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
      [[nodiscard]] static auto abort() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&About". This field is constant.
      [[nodiscard]] static auto about() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Actual Size". This field is constant.
      [[nodiscard]] static auto actual_size() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Add". This field is constant.
      [[nodiscard]] static auto add() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Alignment". This field is constant.
      [[nodiscard]] static auto alignment() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Align Left". This field is constant.
      [[nodiscard]] static auto align_left() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Align Right". This field is constant.
      [[nodiscard]] static auto align_right() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Apply". This field is constant.
      [[nodiscard]] static auto apply() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Ascending". This field is constant.
      [[nodiscard]] static auto ascending() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Back". This field is constant.
      [[nodiscard]] static auto back() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Bold". This field is constant.
      [[nodiscard]] static auto bold() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Bottom". This field is constant.
      [[nodiscard]] static auto bottom() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Cancel". This field is constant.
      [[nodiscard]] static auto cancel() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&CD-Rom". This field is constant.
      [[nodiscard]] static auto cdrom() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Centered". This field is constant.
      [[nodiscard]] static auto centered() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Clear". This field is constant.
      [[nodiscard]] static auto clear() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Close". This field is constant.
      [[nodiscard]] static auto close() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Color". This field is constant.
      [[nodiscard]] static auto color() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Contents". This field is constant.
      [[nodiscard]] static auto contents() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Convert". This field is constant.
      [[nodiscard]] static auto convert() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Copy". This field is constant.
      [[nodiscard]] static auto copy() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Customize". This field is constant.
      [[nodiscard]] static auto customize() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Cu&t". This field is constant.
      [[nodiscard]] static auto cut() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Delete". This field is constant.
      [[nodiscard]] static auto del() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Descending". This field is constant.
      [[nodiscard]] static auto descending() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Down". This field is constant.
      [[nodiscard]] static auto down() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Edit". This field is constant.
      [[nodiscard]] static auto edit() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Execute". This field is constant.
      [[nodiscard]] static auto execute() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "E&xit". This field is constant.
      [[nodiscard]] static auto exit() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&File". This field is constant.
      [[nodiscard]] static auto file() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Find...". This field is constant.
      [[nodiscard]] static auto find() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&First". This field is constant.
      [[nodiscard]] static auto first() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Floppy". This field is constant.
      [[nodiscard]] static auto floppy() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Font". This field is constant.
      [[nodiscard]] static auto font() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Forward". This field is constant.
      [[nodiscard]] static auto forward() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Harddisk". This field is constant.
      [[nodiscard]] static auto harddisk() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Help". This field is constant.
      [[nodiscard]] static auto help() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Home". This field is constant.
      [[nodiscard]] static auto home() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Ignore". This field is constant.
      [[nodiscard]] static auto ignore() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Indent". This field is constant.
      [[nodiscard]] static auto indent() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Index". This field is constant.
      [[nodiscard]] static auto index() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Info". This field is constant.
      [[nodiscard]] static auto info() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Italic". This field is constant.
      [[nodiscard]] static auto italic() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Justified". This field is constant.
      [[nodiscard]] static auto justified() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Jump to". This field is constant.
      [[nodiscard]] static auto jump_to() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Last". This field is constant.
      [[nodiscard]] static auto last() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Network". This field is constant.
      [[nodiscard]] static auto network() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&New". This field is constant.
      [[nodiscard]] static auto new_() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Next". This field is constant.
      [[nodiscard]] static auto next() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&No". This field is constant.
      [[nodiscard]] static auto no() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&OK". This field is constant.
      [[nodiscard]] static auto ok() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Open...". This field is constant.
      [[nodiscard]] static auto open() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Options". This field is constant.
      [[nodiscard]] static auto options() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Paste". This field is constant.
      [[nodiscard]] static auto paste() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Preference". This field is constant.
      [[nodiscard]] static auto preferences() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Previous". This field is constant.
      [[nodiscard]] static auto previous() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Print...". This field is constant.
      [[nodiscard]] static auto print() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Print Re&view". This field is constant.
      [[nodiscard]] static auto print_preview() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Properties". This field is constant.
      [[nodiscard]] static auto properties() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Quit". This field is constant.
      [[nodiscard]] static auto quit() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Redo". This field is constant.
      [[nodiscard]] static auto redo() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Refresh". This field is constant.
      [[nodiscard]] static auto refresh() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Remove". This field is constant.
      [[nodiscard]] static auto remove() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Rep&lace". This field is constant.
      [[nodiscard]] static auto replace() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Retry". This field is constant.
      [[nodiscard]] static auto retry() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Revert to Saved". This field is constant.
      [[nodiscard]] static auto revert_to_saved() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Save". This field is constant.
      [[nodiscard]] static auto save() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Save &As...". This field is constant.
      [[nodiscard]] static auto save_as() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Search". This field is constant.
      [[nodiscard]] static auto search() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Select &All". This field is constant.
      [[nodiscard]] static auto select_all() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "-". This field is constant.
      [[nodiscard]] static auto separator() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Settings...". This field is constant.
      [[nodiscard]] static auto settings() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Spell Check". This field is constant.
      [[nodiscard]] static auto spell_check() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Stop". This field is constant.
      [[nodiscard]] static auto stop() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Strikeout". This field is constant.
      [[nodiscard]] static auto strikeout() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Tools". This field is constant.
      [[nodiscard]] static auto tools() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Top". This field is constant.
      [[nodiscard]] static auto top() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Undelete". This field is constant.
      [[nodiscard]] static auto undelete() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Underline". This field is constant.
      [[nodiscard]] static auto underline() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Undo". This field is constant.
      [[nodiscard]] static auto undo() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Unindent". This field is constant.
      [[nodiscard]] static auto unindent() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Up". This field is constant.
      [[nodiscard]] static auto up() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&View". This field is constant.
      [[nodiscard]] static auto view() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Window". This field is constant.
      [[nodiscard]] static auto window() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "&Yes". This field is constant.
      [[nodiscard]] static auto yes() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Zoom &In". This field is constant.
      [[nodiscard]] static auto zoom_in() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Zoom &Out". This field is constant.
      [[nodiscard]] static auto zoom_out() -> xtd::string;
      /// @brief Gets a system-defined text that has a string value of "Zoom to &Fit". This field is constant.
      [[nodiscard]] static auto zoom_to_fit() -> xtd::string;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of texts.
      [[nodiscard]] static auto get_texts() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
  
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of string objects for use by a Windows Forms application.
    /// @deprecated Replaced by xtd::drawing::texts - Will be removed in version 1.2.0.
    using system_texts [[deprecated("Replaced by xtd::drawing::texts - Will be removed in version 1.2.0.")]] = xtd::drawing::texts;
  }
}
