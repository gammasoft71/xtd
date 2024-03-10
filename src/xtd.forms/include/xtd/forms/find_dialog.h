/// @file
/// @brief Contains xtd::forms::find_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include "dialog_closed_event_handler.h"
#include "dialog_appearance.h"
#include "find_event_handler.h"
#include "search_direction.h"
#include "iwin32_window.h"
#include "layout/arranged_element_collection.h"
#include <xtd/drawing/point>
#include <xtd/event>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays find dialog.
    /// @par Header
    /// @code #include <xtd/forms/find_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_find_dialog_w.png   |  @image html dialog_find_dialog_m.png   |  @image html dialog_find_dialog_g.png   |
    /// | Dark  |  @image html dialog_find_dialog_wd.png  |  @image html dialog_find_dialog_md.png  |  @image html dialog_find_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of find_dialog dialog.
    /// @include find_dialog.cpp
    class forms_export_ find_dialog final : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the find_dialog class.
      find_dialog();
      /// @}
      
      /// @cond
      ~find_dialog();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const noexcept;
      /// @brief Sets the string to find.
      /// @param value The string to find.
      /// @return Current find_dialog instance.
      find_dialog& find_string(const xtd::ustring& value);
      
      /// @brief Gets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @return The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      xtd::drawing::point location() const noexcept;
      /// @brief Sets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @param value The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      /// @return Current find_dialog instance.
      find_dialog& location(const xtd::drawing::point& value);
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const noexcept;
      /// @brief Sets the match case value.
      /// @param value true if match case option selected; otherwise false. The default is false.
      /// @return Current find_dialog instance.
      find_dialog& match_case(bool value);
      
      /// @brief Gets the search direction value.
      /// @return One of xtd::forms::search_direction values. The default is xtd::forms::search_direction::down.
      xtd::forms::search_direction search_direction() const noexcept;
      /// @brief Gets the search direction value.
      /// @param value One of xtd::forms::search_direction values. The default is xtd::forms::search_direction::down.
      /// @return Current find_dialog instance.
      find_dialog& search_direction(xtd::forms::search_direction value);
      
      /// @brief Gets a value that indicates whether match case option is shown.
      /// @return true if match case option is shown; otherwise false. The default is true.
      bool show_match_case() const noexcept;
      /// @brief Sets a value that indicates whether match case option is shown.
      /// @param value true if match case option is shown; otherwise false. The default is true.
      /// @return Current find_dialog instance.
      find_dialog& show_match_case(bool value);
      
      /// @brief Gets a value that indicates whether up down option is shown.
      /// @return true if up down option is shown; otherwise false. The default is true.
      bool show_up_down() const noexcept;
      /// @brief Sets a value that indicates whether up down option is shown.
      /// @param value true if up down option is shown; otherwise false. The default is true.
      /// @return Current find_dialog instance.
      find_dialog& show_up_down(bool value);
      
      /// @brief Gets a value that indicates whether whole word option is shown.
      /// @return true if whole word option is shown; otherwise false. The default is true.
      bool show_whole_word() const noexcept;
      /// @brief Sets a value that indicates whether whole word option is shown.
      /// @param value true if whole word option is shown; otherwise false. The default is true.
      /// @return Current find_dialog instance.
      find_dialog& show_whole_word(bool value);
      
      /// @brief Gets the find dialog title.
      /// @return The find dialog title.
      const xtd::ustring& title() const noexcept;
      /// @brief Sets the find dialog title.
      /// @param value The find dialog title.
      /// @return Current find_dialog instance.
      find_dialog& title(const xtd::ustring& value);
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const noexcept;
      /// @brief Sets the whole word value.
      /// @param value true if whole word option selected; otherwise false. The default is false.
      /// @return Current find_dialog instance.
      find_dialog& whole_word(bool value);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user click the find button.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      xtd::event<find_dialog, xtd::forms::find_event_handler> find_next;
      
      /// @brief Occurs when the user close the find dialog box with dialog close button or cancel button.
      /// @remarks The xtd::forms::dialog_closed_event_args::dialog_result is always set to xtd::forms::dialog_result::cancel
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      xtd::event<find_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the find dialog box.
      /// @remarks If the find dialog box is already closed, this method does nothing.
      void close();
      
      /// @brief Resets all properties to default values.
      /// @remarks When you reset the xtd::forms::find::dialog, the following read/write properties are set to initial values.
      /// | Property         | Value                              |
      /// | ---------------- | ---------------------------------- |
      /// | title            | ""                                 |
      /// | find_string      | ""                                 |
      /// | show_up_down     | true                               |
      /// | show_whole_word  | true                               |
      /// | show_match_case  | true                               |
      /// | search_direction | xtd::forms::search_direction::down |
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
      void on_dialog_closed();
      void on_dialog_find(const xtd::drawing::point& location, const ustring& find_string, bool downwards, bool whole_word, bool match_case);
      void recreate_handle();
      
      std::shared_ptr<data> data_;
    };
  }
}
