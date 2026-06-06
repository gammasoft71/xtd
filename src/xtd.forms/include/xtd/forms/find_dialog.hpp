/// @file
/// @brief Contains xtd::forms::find_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "dialog_closed_event_handler.hpp"
#include "dialog_appearance.hpp"
#include "find_event_handler.hpp"
#include "search_direction.hpp"
#include "iwin32_window.hpp"
#include "layout/arranged_element_collection.hpp"
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
    /// #include <xtd/forms/find_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_find_dialog_w.png   |  @image html dialog_find_dialog_m.png   |  @image html dialog_find_dialog_g.png   |
    /// | Dark  |  @image html dialog_find_dialog_wd.png  |  @image html dialog_find_dialog_md.png  |  @image html dialog_find_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of find_dialog dialog.
    /// @include find_dialog.cpp
    class forms_export_ find_dialog final : public xtd::forms::component {
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
      [[nodiscard]] auto find_string() const noexcept -> const xtd::string&;
      /// @brief Sets the string to find.
      /// @param value The string to find.
      /// @return Current find_dialog instance.
      auto find_string(const xtd::string& value) -> find_dialog&;
      
      /// @brief Gets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @return The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      [[nodiscard]] auto location() const noexcept -> xtd::drawing::point;
      /// @brief Sets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @param value The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      /// @return Current find_dialog instance.
      auto location(const xtd::drawing::point& value) -> find_dialog&;
      
      /// @brief Gets the match case value.
      /// @return `true` if match case option selected; otherwise `false`. The default is `false`.
      [[nodiscard]] auto match_case() const noexcept -> bool;
      /// @brief Sets the match case value.
      /// @param value `true` if match case option selected; otherwise `false`. The default is `false`.
      /// @return Current find_dialog instance.
      auto match_case(bool value) -> find_dialog&;
      
      /// @brief Gets the search direction value.
      /// @return One of xtd::forms::search_direction values. The default is xtd::forms::search_direction::down.
      [[nodiscard]] auto search_direction() const noexcept -> xtd::forms::search_direction;
      /// @brief Gets the search direction value.
      /// @param value One of xtd::forms::search_direction values. The default is xtd::forms::search_direction::down.
      /// @return Current find_dialog instance.
      auto search_direction(xtd::forms::search_direction value) -> find_dialog&;
      
      /// @brief Gets a value that indicates whether match case option is shown.
      /// @return `true` if match case option is shown; otherwise `false`. The default is `true`.
      [[nodiscard]] auto show_match_case() const noexcept -> bool;
      /// @brief Sets a value that indicates whether match case option is shown.
      /// @param value `true` if match case option is shown; otherwise `false`. The default is `true`.
      /// @return Current find_dialog instance.
      auto show_match_case(bool value) -> find_dialog&;
      
      /// @brief Gets a value that indicates whether up down option is shown.
      /// @return `true` if up down option is shown; otherwise `false`. The default is `true`.
      [[nodiscard]] auto show_up_down() const noexcept -> bool;
      /// @brief Sets a value that indicates whether up down option is shown.
      /// @param value `true` if up down option is shown; otherwise `false`. The default is `true`.
      /// @return Current find_dialog instance.
      auto show_up_down(bool value) -> find_dialog&;
      
      /// @brief Gets a value that indicates whether whole word option is shown.
      /// @return `true` if whole word option is shown; otherwise `false`. The default is `true`.
      [[nodiscard]] auto show_whole_word() const noexcept -> bool;
      /// @brief Sets a value that indicates whether whole word option is shown.
      /// @param value `true` if whole word option is shown; otherwise `false`. The default is `true`.
      /// @return Current find_dialog instance.
      auto show_whole_word(bool value) -> find_dialog&;
      
      /// @brief Gets the find dialog title.
      /// @return The find dialog title.
      [[nodiscard]] auto title() const noexcept -> const xtd::string&;
      /// @brief Sets the find dialog title.
      /// @param value The find dialog title.
      /// @return Current find_dialog instance.
      auto title(const xtd::string& value) -> find_dialog&;
      
      /// @brief Gets the whole word value.
      /// @return `true` if whole word option selected; otherwise `false`. The default is `false`.
      [[nodiscard]] auto whole_word() const noexcept -> bool;
      /// @brief Sets the whole word value.
      /// @param value `true` if whole word option selected; otherwise `false`. The default is `false`.
      /// @return Current find_dialog instance.
      auto whole_word(bool value) -> find_dialog&;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user click the find button.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<find_dialog, xtd::forms::find_event_handler> find_next;
      
      /// @brief Occurs when the user close the find dialog box with dialog close button or cancel button.
      /// @remarks The xtd::forms::dialog_closed_event_args::dialog_result is always set to xtd::forms::dialog_result::cancel
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<find_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the find dialog box.
      /// @remarks If the find dialog box is already closed, this method does nothing.
      auto close() -> void;
      
      /// @brief Resets all properties to default values.
      /// @remarks When you reset the xtd::forms::find::dialog, the following read/write properties are set to initial values.
      /// | Property         | Value                              |
      /// | ---------------- | ---------------------------------- |
      /// | title            | ""                                 |
      /// | find_string      | ""                                 |
      /// | show_up_down     | `true`                             |
      /// | show_whole_word  | `true`                             |
      /// | show_match_case  | `true`                             |
      /// | search_direction | xtd::forms::search_direction::down |
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
      auto on_dialog_closed() -> void;
      auto on_dialog_find(const xtd::drawing::point& location, const xtd::string& find_string, bool downwards, bool whole_word, bool match_case) -> void;
      auto recreate_handle() -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
