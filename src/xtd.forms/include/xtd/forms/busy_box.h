#pragma once
#include "busy_dialog.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ busy_box final static_ {
    public:
      static void hide() {
        delete dialog_;
        dialog_ = nullptr;
      }
      
      static void show(const iwin32_window& owner) {show_busy_dialog(&owner);}
      static void show(const iwin32_window& owner, const std::string& text) {show_busy_dialog(&owner, text);}
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption) {show_busy_dialog(&owner, text, caption);}
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon) {show_busy_dialog(&owner, text, caption, icon);}
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color) {show_busy_dialog(&owner, text, caption, icon, back_color);}
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {show_busy_dialog(&owner, text, caption, icon, back_color, fore_color);}
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float transparency) {show_busy_dialog(&owner, text, caption, icon, back_color, fore_color, transparency);}

      static void show() {show_busy_dialog(nullptr);}
      static void show(const std::string& text) {show_busy_dialog(nullptr, text);}
      static void show(const std::string& text, const std::string& caption) {show_busy_dialog(nullptr, text, caption);}
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon) {show_busy_dialog(nullptr, text, caption, icon);}
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color) {show_busy_dialog(nullptr, text, caption, icon, back_color);}
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {show_busy_dialog(nullptr, text, caption, icon, back_color, fore_color);}
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float transparency) {show_busy_dialog(nullptr, text, caption, icon, back_color, fore_color, transparency);}
      
    private:
      static busy_dialog* dialog_;
      static void show_busy_dialog(const iwin32_window* owner, const std::string& text = "Pleasee wait...", const std::string& caption = "", const xtd::drawing::icon& icon = xtd::drawing::icon::empty, const xtd::drawing::color& back_color = xtd::forms::theme_colors::current_theme().control(), const xtd::drawing::color& fore_color = xtd::forms::theme_colors::current_theme().control_text(), float transparency = 1.0) {
        if (dialog_) return;
        dialog_ = new busy_dialog();
        dialog_->description(text);
        dialog_->text(caption);
        dialog_->icon(icon);
        dialog_->back_color(back_color);
        dialog_->fore_color(fore_color);
        dialog_->transparency(transparency);
        owner ? dialog_->show(*owner) : dialog_->show();
      }
    };
  }
}
