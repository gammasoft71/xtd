/// @file
/// @brief Contains xtd::forms::replace_dialog dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection"
#include "component"
#include "dialog_closed_event_handler"
#include "dialog_appearance"
#include "find_event_handler"
#include "replace_event_handler"
#include "iwin32_window"
#include <xtd/drawing/point>
#include <xtd/event>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays find dialog.
    /// @par Header
    /// @code #include <xtd/forms/replace_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                    | macOS                                      | Gnome                                      |
    /// | ----- | ------------------------------------------ | ------------------------------------------ | ------------------------------------------ |
    /// | Light |  @image html dialog_replace_dialog_w.png   |  @image html dialog_replace_dialog_m.png   |  @image html dialog_replace_dialog_g.png   |
    /// | Dark  |  @image html dialog_replace_dialog_wd.png  |  @image html dialog_replace_dialog_md.png  |  @image html dialog_replace_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of replace_dialog dialog.
    /// @include replace_dialog.cpp
    class forms_export_ replace_dialog final : public component {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the replace_dialog class.
      replace_dialog();
      /// @}
      
      /// @cond
      ~replace_dialog();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const noexcept;
      /// @brief Sets the string to find.
      /// @param value The string to find.
      /// @return Current replace_dialog instance.
      replace_dialog& find_string(const xtd::ustring& value);
      
      /// @brief Gets the replaced string.
      /// @return The replaced string.
      const xtd::ustring& replace_string() const noexcept;
      /// @brief Sets the replaced string.
      /// @param value The replaced string.
      /// @return Current replace_dialog instance.
      replace_dialog& replace_string(const xtd::ustring& value);
      
      /// @brief Gets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @return The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      xtd::drawing::point location() const noexcept;
      /// @brief Sets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @param value The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      /// @return Current replace_dialog instance.
      replace_dialog& location(const xtd::drawing::point& value);
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const noexcept;
      /// @brief Sets the match case value.
      /// @param value true if match case option selected; otherwise false. The default is false.
      /// @return Current replace_dialog instance.
      replace_dialog& match_case(bool value);
      
      /// @brief Gets a value that indicates whether match case option is shown.
      /// @return true if match case option is shown; otherwise false. The default is true.
      bool show_match_case() const noexcept;
      /// @brief Sets a value that indicates whether match case option is shown.
      /// @param value true if match case option is shown; otherwise false. The default is true.
      /// @return Current replace_dialog instance.
      replace_dialog& show_match_case(bool value);
      
      /// @brief Gets a value that indicates whether whole word option is shown.
      /// @return true if whole word option is shown; otherwise false. The default is true.
      bool show_whole_word() const noexcept;
      /// @brief Sets a value that indicates whether whole word option is shown.
      /// @param value true if whole word option is shown; otherwise false. The default is true.
      /// @return Current replace_dialog instance.
      replace_dialog& show_whole_word(bool value);
      
      /// @brief Gets the find dialog title.
      /// @return The find dialog title.
      const xtd::ustring& title() const noexcept;
      /// @brief Sets the find dialog title.
      /// @param value The find dialog title.
      /// @return Current replace_dialog instance.
      replace_dialog& title(const xtd::ustring& value);
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const noexcept;
      /// @brief Sets the whole word value.
      /// @param value true if whole word option selected; otherwise false. The default is false.
      /// @return Current replace_dialog instance.
      replace_dialog& whole_word(bool value);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the user click the find button.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<replace_dialog, xtd::forms::find_event_handler> find_next;
      
      /// @brief Occurs when the user click the replace button.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<replace_dialog, xtd::forms::replace_event_handler> replace;
      
      /// @brief Occurs when the user click the replace all button.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<replace_dialog, xtd::forms::replace_event_handler> replace_all;
      
      /// @brief Occurs when the user close the replace dialog box with dialog close button or cancel button.
      /// @remarks The xtd::forms::dialog_closed_event_args::dialog_result is always set to xtd::forms::dialog_result::cancel
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<replace_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Closes the find dialog box.
      /// @remarks If the find dialog box is already closed, this method does nothing.
      void close();
      
      /// @brief Resets all properties to default values.
      /// @remarks When you reset the xtd::forms::replace::dialog, the following read/write properties are set to initial values.
      /// | Property         | Value                              |
      /// | ---------------- | ---------------------------------- |
      /// | title            | ""                                 |
      /// | find_string      | ""                                 |
      /// | replace_string   | ""                                 |
      /// | show_whole_word  | true                               |
      /// | show_match_case  | true                               |
      /// | whole_word       | false                              |
      /// | match_case       | false                              |
      void reset() noexcept;
      
      /// @brief Runs find dialog box.
      /// @remarks If the find dialog box is already displayed, this method does nothing.
      void show(const iwin32_window& owner);
      /// @}
      
    private:
      void create_handle();
      void destroy_handle();
      void recreate_handle();
      void on_dialog_closed();
      void on_dialog_find(const xtd::drawing::point& location, const ustring& find_string, const ustring& replace_string, bool whole_word, bool match_case);
      void on_dialog_replace(const xtd::drawing::point& location, const ustring& find_string, const ustring& replace_string, bool replace_all, bool whole_word, bool match_case);
      
      std::shared_ptr<data> data_;
    };
  }
}
