/// @file
/// @brief Contains xtd::forms::radio_buttons factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "radio_button.h"
#include "texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of radio_button objects for use by a Windows Forms application.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of radio_button control facttory.
    /// @include radio_buttons.cpp
    class forms_export_ radio_buttons final static_ {
    public:
      /// @brief Create a system-defined radio_button that represent abort radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> abort(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent abort radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> abort(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent about radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> about(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent about radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> about(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent actual size radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> actual_size(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent actual size radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> actual_size(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent add radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> add(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent add radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> add(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent alignment radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> alignment(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent alignment radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> alignment(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent align left radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> align_left(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent align left radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> align_left(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent align right radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> align_right(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent align right radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> align_right(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent apply radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> apply(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent apply radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> apply(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent ascending radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> ascending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent ascending radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> ascending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent back radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> back(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent back radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> back(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent bold radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> bold(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent bold radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> bold(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent bottom radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> bottom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent bottom radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> bottom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent cancel radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> cancel(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent cancel radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> cancel(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent CD-Rom radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> cdrom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent CD-Rom radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> cdrom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent centered radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> centered(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent centered radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> centered(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent clear radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> clear(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent clear radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> clear(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent close radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> close(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent close radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> close(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent color radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> color(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent color radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> color(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent contents radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> contents(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent contents radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> contents(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent convert radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> convert(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent convert radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> convert(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent copy radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> copy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent copy radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> copy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent customize radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> customize(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent customize radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> customize(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent cut radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> cut(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent cut radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> cut(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent delete radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> del(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent delete radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> del(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent decending radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> descending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent decending radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> descending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent down radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> down(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent down radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> down(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent edit radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> edit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent edit radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> edit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent execute radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> execute(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent execute radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> execute(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent file radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> file(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent file radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> file(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent find radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> find(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent find radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> find(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent first radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> first(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent first radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> first(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent floppy radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> floppy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent floppy radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> floppy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent font radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> font(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent font radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> font(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent forward radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> forward(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent forward radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> forward(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent harddisk radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> harddisk(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent harddisk radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> harddisk(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent help radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> help(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent help radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> help(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent home radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> home(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent home radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> home(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent ignore radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> ignore(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent ignore radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> ignore(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent indent radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> indent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent indent radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> indent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent index radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> index(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent index radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> index(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent info radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> info(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent info radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> info(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent italic radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> italic(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent italic radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> italic(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent justified radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> justified(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent justified radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> justified(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent jump_to radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> jump_to(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent jump to radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> jump_to(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent last radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> last(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent last radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> last(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent network radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> network(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent network radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> network(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent new radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> new_(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent new radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> new_(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent no radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> no(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent no radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> no(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent ok radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> ok(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent ok radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> ok(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent open radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> open(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent open radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> open(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent options radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> options(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent options radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> options(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent paste radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> paste(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent paste radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> paste(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent preferences radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> preferences(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent preferences radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> preferences(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent print radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> print(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent print radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> print(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent print preview radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> print_preview(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent print preview radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> print_preview(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent properties radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> properties(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent properties radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> properties(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent quit radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> quit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent quit radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> quit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent redo radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> redo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent redo radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> redo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent refresh radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> refresh(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent refresh radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> refresh(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent remove radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> remove(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent remove radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> remove(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent replace radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> replace(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent replace radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> replace(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent retry radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> retry(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent retry radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> retry(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent revert to saved radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> revert_to_saved(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent revert to saved radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> revert_to_saved(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent save radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> save(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent save radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> save(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent save as radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> save_as(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent save as radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> save_as(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent seach radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> search(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent search radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> search(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent select all radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> select_all(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent select all radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> select_all(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent spell check radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> spell_check(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent spell check radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> spell_check(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent stop radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> stop(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent stop radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> stop(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent strikeout radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> strikeout(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent strikeout radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> strikeout(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent tools radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> tools(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent tools radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> tools(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent top radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> top(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent top radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> top(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent undelete radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> undelete(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent undelete radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> undelete(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent underline radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> underline(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent underline radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> underline(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent undo radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> undo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent undo radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> undo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent uindent radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> unindent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent unindent radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> unindent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent up radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> up(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent up radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> up(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent view radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> view(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent view radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> view(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent yes radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> yes(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent yes radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> yes(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent zoom in radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> zoom_in(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent zoom in radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> zoom_in(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent zoom out radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> zoom_out(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent zoom out radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> zoom_out(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent zoom to fit radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> zoom_to_fit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(texts::zoom_to_fit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined radio_button that represent zoom to fit radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param back_color The radio_button background color.
      /// @param fore_core The radio_button foreground color.
      /// @return The created radio_button.
      static std::unique_ptr<radio_button> zoom_to_fit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<radio_button>(parent, texts::zoom_to_fit(), location, size, back_color, fore_color);}
    };
  }
}
