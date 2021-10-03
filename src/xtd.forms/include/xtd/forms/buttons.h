/// @file
/// @brief Contains xtd::forms::buttons factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "button.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of button objects for use by a Windows Forms application.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of buttons control factory.
    /// @include buttons.cpp
    class buttons final static_ {
    public:
      /// @brief Create a system-defined button that represent abort button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> abort(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent abort button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> abort(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent about button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> about(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent about button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> about(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent actual size button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> actual_size(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent actual size button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> actual_size(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent add button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> add(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent add button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> add(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent alignment button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> alignment(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent alignment button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> alignment(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent align left button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> align_left(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent align left button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> align_left(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent align right button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> align_right(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent align right button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> align_right(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent apply button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> apply(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent apply button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> apply(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent ascending button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> ascending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent ascending button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> ascending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent back button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> back(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent back button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> back(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent bold button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> bold(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent bold button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> bold(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent bottom button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> bottom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent bottom button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> bottom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent cancel button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> cancel(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent cancel button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> cancel(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent CD-Rom button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> cdrom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent CD-Rom button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> cdrom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent centered button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> centered(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent centered button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> centered(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent clear button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> clear(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent clear button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> clear(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent close button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> close(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent close button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> close(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent color button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> color(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent color button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> color(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent contents button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> contents(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent contents button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> contents(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent convert button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> convert(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent convert button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> convert(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent copy button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> copy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent copy button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> copy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent customize button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> customize(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent customize button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> customize(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent cut button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> cut(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent cut button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> cut(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent delete button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> del(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent delete button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> del(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent descending button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> descending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent descending button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> descending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent down button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> down(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent down button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> down(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent edit button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> edit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent edit button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> edit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent execute button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> execute(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent execute button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> execute(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent file button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> file(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent file button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> file(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent find button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> find(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent find button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> find(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent first button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> first(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent first button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> first(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent floppy button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> floppy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent floppy button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> floppy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent font button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> font(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent font button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> font(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent forward button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> forward(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent forward button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> forward(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent hard disk button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> harddisk(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent hard disk button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> harddisk(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent help button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> help(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent help button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> help(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent home button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> home(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent home button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> home(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent ignore button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> ignore(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent ignore button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> ignore(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent indent button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> indent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent indent button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> indent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent index button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> index(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent index button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> index(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent info button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> info(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent info button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> info(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent italic button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> italic(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent italic button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> italic(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent justified button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> justified(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent justified button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> justified(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent jump_to button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> jump_to(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent jump to button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> jump_to(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent last button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> last(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent last button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> last(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent network button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> network(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent network button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> network(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent new button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> new_(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent new button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> new_(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent no button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> no(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent no button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> no(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent ok button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> ok(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent ok button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> ok(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent open button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> open(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent open button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> open(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent options button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> options(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent options button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> options(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent paste button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> paste(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent paste button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> paste(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent preferences button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> preferences(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent preferences button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> preferences(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent print button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> print(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent print button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> print(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent print preview button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> print_preview(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent print preview button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> print_preview(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent properties button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> properties(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent properties button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> properties(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent quit button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> quit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent quit button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> quit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent redo button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> redo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent redo button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> redo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent refresh button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> refresh(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent refresh button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> refresh(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent remove button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> remove(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent remove button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> remove(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent replace button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> replace(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent replace button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> replace(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent retry button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> retry(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent retry button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> retry(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent revert to saved button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> revert_to_saved(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent revert to saved button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> revert_to_saved(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent save button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> save(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent save button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> save(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent save as button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> save_as(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent save as button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> save_as(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent search button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> search(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent search button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> search(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent select all button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> select_all(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent select all button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> select_all(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent spell check button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> spell_check(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent spell check button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> spell_check(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent stop button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> stop(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent stop button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> stop(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent strikeout button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> strikeout(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent strikeout button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> strikeout(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent tools button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> tools(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent tools button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> tools(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent top button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> top(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent top button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> top(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent undelete button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> undelete(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent undelete button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> undelete(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent underline button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> underline(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent underline button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> underline(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent undo button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> undo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent undo button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> undo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represents an unindented button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> unindent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represents an unindented button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> unindent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent up button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> up(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent up button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> up(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent view button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> view(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent view button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> view(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent yes button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> yes(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent yes button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> yes(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent zoom in button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> zoom_in(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent zoom in button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> zoom_in(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent zoom out button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> zoom_out(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent zoom out button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> zoom_out(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent zoom to fit button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> zoom_to_fit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(system_texts::zoom_to_fit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined button that represent zoom to fit button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param back_color The button background color.
      /// @param fore_core The button foreground color.
      /// @return The created button.
      static std::unique_ptr<button> zoom_to_fit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<button>(parent, system_texts::zoom_to_fit(), location, size, back_color, fore_color);}
    };
  }
}
