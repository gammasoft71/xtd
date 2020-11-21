#pragma once
#include <optional>
#include <string>
#include <xtd/delegate.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/icon.h>
#include <xtd/forms/control.h>
#include "dialog_style.h"
#include "iwin32_window.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays busy box.
    /// @par Example
    /// The following code example demonstrate the use of busy_dialog dialog.
    /// @include busy_dialog.cpp
    class busy_dialog  final {
    public:
      /// @brief Initializes a new instance of the busy_dialog class.
      busy_dialog() = default;
      ~busy_dialog() {hide();}
      
      xtd::drawing::color back_color() const {return back_color_;}
      busy_dialog& back_color(const xtd::drawing::color& color) {
        back_color_ = color;
        return *this;
      }
      
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      busy_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        dialog_style_ = dialog_style;
        return *this;
      }
      
      xtd::drawing::color fore_color() const {return fore_color_;}
      busy_dialog& fore_color(const xtd::drawing::color& color) {
        fore_color_ = color;
        return *this;
      }
      

      /// @brief Gets the dialog title.
      /// @return The dialog title.
      const std::string& text() const {return text_;}
      /// @brief Sets the dialog title.
      /// @param copyright The dialog title.
      /// @return Current busy_dialog instance.
      busy_dialog& text(const std::string& text) {
        text_ = text;
        return *this;
      }
      
      /// @brief Gets the product description.
      /// @return The product description.
      const std::string& description() const {return description_;}
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current busy_dialog instance.
      busy_dialog& description(const std::string& description) {
        description_ = description;
        return *this;
      }
      
      /// @brief Gets the product icon.
      /// @return The product icon.
      xtd::drawing::icon icon() const {return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_));}
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current busy_dialog instance.
      busy_dialog& icon(const xtd::drawing::icon& icon) {
        icon_ = icon.to_bitmap();
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current busy_dialog instance.
      busy_dialog& icon(const xtd::drawing::image& image) {
        icon_ = image;
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current busy_dialog instance.
      busy_dialog& icon(const xtd::drawing::bitmap& bitmap) {
        icon_ = bitmap;
        return *this;
      }

      double transparency() const {return transparency_;}
      busy_dialog& transparency(double transparency) {
        transparency_ = transparency;
        return *this;
      }

      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs busy dialog box.
      void show();
      /// @brief Runs busy dialog box.
      void show(const iwin32_window& owner);

      void hide();

    private:
      xtd::drawing::color back_color_ = xtd::forms::theme_colors::current_theme().control();
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::system;
      xtd::drawing::color fore_color_ = xtd::forms::theme_colors::current_theme().control_text();
      xtd::drawing::image icon_;
      std::string text_;
      std::string description_;
      double transparency_;
      bool native_ = false;
      intptr_t handle_ = 0;
    };
  }
}
