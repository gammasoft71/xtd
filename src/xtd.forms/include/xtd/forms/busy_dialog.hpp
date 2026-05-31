/// @file
/// @brief Contains xtd::forms::busy_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "dialog_appearance.hpp"
#include "iwin32_window.hpp"
#include <xtd/drawing/color>
#include <xtd/drawing/icon>
#include <xtd/forms/control>
#include <xtd/optional>
#include <xtd/delegate>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays busy dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/busy_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_busy_dialog_w.png   |  @image html dialog_busy_dialog_m.png   |  @image html dialog_busy_dialog_g.png   |
    /// | Dark  |  @image html dialog_busy_dialog_wd.png  |  @image html dialog_busy_dialog_md.png  |  @image html dialog_busy_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of busy_dialog dialog.
    /// @include busy_dialog.cpp
    class forms_export_ busy_dialog  final : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the busy_dialog class.
      busy_dialog();
      /// @}
      /// @cond
      ~busy_dialog();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the background color for the dialog.
      /// @return A xtd::drawing::color that represents the background color of the dialog.
      [[nodiscard]] auto back_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the background color for the dialog.
      /// @param color A xtd::drawing::color that represents the background color of the dialog.
      /// @return Current busy_dialog instance.
      auto back_color(const xtd::drawing::color& color) -> busy_dialog&;
      
      /// @brief Gets the dialog appearance color for the dialog.
      /// @return A xtd::forms::dialog_appearance that represents the dialog appearance of the dialog.
      [[nodiscard]] auto dialog_appearance() const noexcept -> xtd::forms::dialog_appearance;
      /// @brief Sets the dialog appearance color for the dialog.
      /// @param dialog_appearance A xtd::forms::dialog_appearance that represents the dialog appearance of the dialog.
      /// @return Current busy_dialog instance.
      auto dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) -> busy_dialog&;
      
      /// @brief Gets the product description.
      /// @return The product description.
      [[nodiscard]] auto description() const noexcept -> const xtd::string&;
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current busy_dialog instance.
      auto description(const xtd::string& description) -> busy_dialog&;
      
      /// @brief Gets the foreground color for the dialog.
      /// @return A xtd::drawing::color that represents the foreground color of the dialog.
      [[nodiscard]] auto fore_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the foreground color for the dialog.
      /// @param color A xtd::drawing::color that represents the foreground color of the dialog.
      /// @return Current busy_dialog instance.
      auto fore_color(const xtd::drawing::color& color) -> busy_dialog&;
      
      /// @brief Gets the product icon.
      /// @return The product icon.
      [[nodiscard]] auto icon() const noexcept -> xtd::drawing::icon;
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current busy_dialog instance.
      auto icon(const xtd::drawing::icon& icon) -> busy_dialog&;
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current busy_dialog instance.
      auto icon(const xtd::drawing::image& image) -> busy_dialog&;
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current busy_dialog instance.
      auto icon(const xtd::drawing::bitmap& bitmap) -> busy_dialog&;
      
      /// @brief Gets the dialog opacity.
      /// @return The dialog opacity.
      /// @remarks 0 full opacity; 1.0 no opacity. The lower the value, the more transparent.
      [[nodiscard]] auto opacity() const noexcept -> double;
      /// @brief Gets the dialog opacity.
      /// @param opacity The dialog opacity.
      /// @return Current busy_dialog instance.
      /// @remarks 0 full opacity; 1.0 no opacity. The lower the value, the more transparent.
      auto opacity(double opacity) -> busy_dialog&;
      
      /// @brief Gets the dialog title.
      /// @return The dialog title.
      [[nodiscard]] auto text() const noexcept -> const xtd::string&;
      /// @brief Sets the dialog title.
      /// @param text The dialog title.
      /// @return Current busy_dialog instance.
      auto text(const xtd::string& text) -> busy_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Hides busy dialog box.
      auto hide() -> void;
      
      /// @brief Resets all properties to empty string.
      auto reset() -> void;
      
      /// @brief Runs busy dialog box.
      auto show() -> void;
      /// @brief Runs busy dialog box.
      auto show(const xtd::forms::iwin32_window& owner) -> void;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
