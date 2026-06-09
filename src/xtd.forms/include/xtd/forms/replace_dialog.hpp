/// @file
/// @brief Contains xtd::forms::replace_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.hpp"
#include "component.hpp"
#include "dialog_closed_event_handler.hpp"
#include "dialog_appearance.hpp"
#include "find_event_handler.hpp"
#include "replace_event_handler.hpp"
#include "iwin32_window.hpp"
#include <xtd/drawing/point>
#include <xtd/event>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays find dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/replace_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                    | macOS                                      | Gnome                                      |
    /// | ----- | ------------------------------------------ | ------------------------------------------ | ------------------------------------------ |
    /// | Light |  @image html dialog_replace_dialog_w.png   |  @image html dialog_replace_dialog_m.png   |  @image html dialog_replace_dialog_g.png   |
    /// | Dark  |  @image html dialog_replace_dialog_wd.png  |  @image html dialog_replace_dialog_md.png  |  @image html dialog_replace_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of replace_dialog dialog.
    /// @include replace_dialog.cpp
    class forms_export_ replace_dialog final : public xtd::forms::component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the replace_dialog class.
      replace_dialog();
      /// @}
      
      /// @cond
      ~replace_dialog();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      [[nodiscard]] auto find_string() const noexcept -> const xtd::string&;
      /// @brief Sets the string to find.
      /// @param value The string to find.
      /// @return Current replace_dialog instance.
      auto find_string(const xtd::string& value) -> replace_dialog&;
      
      /// @brief Gets the replaced string.
      /// @return The replaced string.
      [[nodiscard]] auto replace_string() const noexcept -> const xtd::string&;
      /// @brief Sets the replaced string.
      /// @param value The replaced string.
      /// @return Current replace_dialog instance.
      auto replace_string(const xtd::string& value) -> replace_dialog&;
      
      /// @brief Gets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @return The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      [[nodiscard]] auto location() const noexcept -> xtd::drawing::point;
      /// @brief Sets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @param value The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      /// @return Current replace_dialog instance.
      auto location(const xtd::drawing::point& value) -> replace_dialog&;
      
      /// @brief Gets the match case value.
      /// @return `true` if match case option selected; otherwise `false`. The default is `false`.
      [[nodiscard]] auto match_case() const noexcept -> bool;
      /// @brief Sets the match case value.
      /// @param value `true` if match case option selected; otherwise `false`. The default is `false`.
      /// @return Current replace_dialog instance.
      auto match_case(bool value) -> replace_dialog&;
      
      /// @brief Gets a value that indicates whether match case option is shown.
      /// @return `true` if match case option is shown; otherwise `false`. The default is `true`.
      [[nodiscard]] auto show_match_case() const noexcept -> bool;
      /// @brief Sets a value that indicates whether match case option is shown.
      /// @param value `true` if match case option is shown; otherwise `false`. The default is `true`.
      /// @return Current replace_dialog instance.
      auto show_match_case(bool value) -> replace_dialog&;
      
      /// @brief Gets a value that indicates whether whole word option is shown.
      /// @return `true` if whole word option is shown; otherwise `false`. The default is `true`.
      [[nodiscard]] auto show_whole_word() const noexcept -> bool;
      /// @brief Sets a value that indicates whether whole word option is shown.
      /// @param value `true` if whole word option is shown; otherwise `false`. The default is `true`.
      /// @return Current replace_dialog instance.
      auto show_whole_word(bool value) -> replace_dialog&;
      
      /// @brief Gets the find dialog title.
      /// @return The find dialog title.
      [[nodiscard]] auto title() const noexcept -> const xtd::string&;
      /// @brief Sets the find dialog title.
      /// @param value The find dialog title.
      /// @return Current replace_dialog instance.
      auto title(const xtd::string& value) -> replace_dialog&;
      
      /// @brief Gets the whole word value.
      /// @return `true` if whole word option selected; otherwise `false`. The default is `false`.
      [[nodiscard]] auto whole_word() const noexcept -> bool;
      /// @brief Sets the whole word value.
      /// @param value `true` if whole word option selected; otherwise `false`. The default is `false`.
      /// @return Current replace_dialog instance.
      auto whole_word(bool value) -> replace_dialog&;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user click the find button.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<replace_dialog, xtd::forms::find_event_handler> find_next;
      
      /// @brief Occurs when the user click the replace button.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<replace_dialog, xtd::forms::replace_event_handler> replace;
      
      /// @brief Occurs when the user click the replace all button.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<replace_dialog, xtd::forms::replace_event_handler> replace_all;
      
      /// @brief Occurs when the user close the replace dialog box with dialog close button or cancel button.
      /// @remarks The xtd::forms::dialog_closed_event_args::dialog_result is always set to xtd::forms::dialog_result::cancel
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<replace_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the find dialog box.
      /// @remarks If the find dialog box is already closed, this method does nothing.
      auto close() -> void;
      
      /// @brief Resets all properties to default values.
      /// @remarks When you reset the xtd::forms::replace::dialog, the following read/write properties are set to initial values.
      /// | Property         | Value                              |
      /// | ---------------- | ---------------------------------- |
      /// | title            | ""                                 |
      /// | find_string      | ""                                 |
      /// | replace_string   | ""                                 |
      /// | show_whole_word  | `true`                             |
      /// | show_match_case  | `true`                             |
      /// | whole_word       | `false`                            |
      /// | match_case       | `false`                            |
      auto reset() noexcept -> void;
      
      /// @brief Runs find dialog box.
      /// @remarks If the find dialog box is already displayed, this method does nothing.
      auto show(const iwin32_window& owner) -> void;
      /// @}
      
    private:
      auto create_handle() -> void;
      auto destroy_handle() -> void;
      auto recreate_handle() -> void;
      auto on_dialog_closed() -> void;
      auto on_dialog_find(const xtd::drawing::point& location, const xtd::string& find_string, const xtd::string& replace_string, bool whole_word, bool match_case) -> void;
      auto on_dialog_replace(const xtd::drawing::point& location, const xtd::string& find_string, const xtd::string& replace_string, bool replace_all, bool whole_word, bool match_case) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
