/// @file
/// @brief Contains xtd::forms::busy_dialog dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "component"
#include "dialog_appearance"
#include "iwin32_window"
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
    /// @code #include <xtd/forms/busy_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_busy_dialog_w.png   |  @image html dialog_busy_dialog_m.png   |  @image html dialog_busy_dialog_g.png   |
    /// | Dark  |  @image html dialog_busy_dialog_wd.png  |  @image html dialog_busy_dialog_md.png  |  @image html dialog_busy_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of busy_dialog dialog.
    /// @include busy_dialog.cpp
    class forms_export_ busy_dialog  final : public component {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the busy_dialog class.
      busy_dialog();
      /// @}
      /// @cond
      ~busy_dialog();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the background color for the dialog.
      /// @return A xtd::drawing::color that represents the background color of the dialog.
      xtd::drawing::color back_color() const noexcept;
      /// @brief Sets the background color for the dialog.
      /// @param color A xtd::drawing::color that represents the background color of the dialog.
      /// @return Current busy_dialog instance.
      busy_dialog& back_color(const xtd::drawing::color& color);
      
      /// @brief Gets the dialog appearance color for the dialog.
      /// @return A xtd::forms::dialog_appearance that represents the dialog appearance of the dialog.
      xtd::forms::dialog_appearance dialog_appearance() const noexcept;
      /// @brief Sets the dialog appearance color for the dialog.
      /// @param dialog_appearance A xtd::forms::dialog_appearance that represents the dialog appearance of the dialog.
      /// @return Current busy_dialog instance.
      busy_dialog& dialog_appearance(xtd::forms::dialog_appearance dialog_appearance);
      
      /// @brief Gets the product description.
      /// @return The product description.
      const xtd::ustring& description() const noexcept;
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current busy_dialog instance.
      busy_dialog& description(const xtd::ustring& description);
      
      /// @brief Gets the foreground color for the dialog.
      /// @return A xtd::drawing::color that represents the foreground color of the dialog.
      xtd::drawing::color fore_color() const noexcept;
      /// @brief Sets the foreground color for the dialog.
      /// @param color A xtd::drawing::color that represents the foreground color of the dialog.
      /// @return Current busy_dialog instance.
      busy_dialog& fore_color(const xtd::drawing::color& color);
      
      /// @brief Gets the product icon.
      /// @return The product icon.
      xtd::drawing::icon icon() const noexcept;
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current busy_dialog instance.
      busy_dialog& icon(const xtd::drawing::icon& icon);
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current busy_dialog instance.
      busy_dialog& icon(const xtd::drawing::image& image);
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current busy_dialog instance.
      busy_dialog& icon(const xtd::drawing::bitmap& bitmap);
      
      /// @brief Gets the dialog opacity.
      /// @return The dialog opacity.
      /// @remarks 0 full opacity; 1.0 no opacity. The lower the value, the more transparent.
      double opacity() const noexcept;
      /// @brief Gets the dialog opacity.
      /// @param opacity The dialog opacity.
      /// @return Current busy_dialog instance.
      /// @remarks 0 full opacity; 1.0 no opacity. The lower the value, the more transparent.
      busy_dialog& opacity(double opacity);
      
      /// @brief Gets the dialog title.
      /// @return The dialog title.
      const xtd::ustring& text() const noexcept;
      /// @brief Sets the dialog title.
      /// @param text The dialog title.
      /// @return Current busy_dialog instance.
      busy_dialog& text(const xtd::ustring& text);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Hides busy dialog box.
      void hide();
      
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs busy dialog box.
      void show();
      /// @brief Runs busy dialog box.
      void show(const iwin32_window& owner);
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
