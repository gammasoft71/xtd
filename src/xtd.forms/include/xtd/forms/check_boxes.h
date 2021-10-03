/// @file
/// @brief Contains xtd::forms::check_boxes factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "check_box.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of check_box objects for use by a Windows Forms application.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of check_boxes control factory.
    /// @include check_boxes.cpp
    class check_boxes final static_ {
    public:
      /// @brief Create a system-defined check_box that represent abort check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> abort(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent abort check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> abort(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent about check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> about(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent about check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> about(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent actual size check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> actual_size(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent actual size check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> actual_size(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent add check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> add(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent add check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> add(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent alignment check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> alignment(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent alignment check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> alignment(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent align left check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> align_left(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent align left check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> align_left(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent align right check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> align_right(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent align right check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> align_right(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent apply check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> apply(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent apply check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> apply(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent ascending check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> ascending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent ascending check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> ascending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent back check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> back(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent back check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> back(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent bold check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> bold(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent bold check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> bold(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent bottom check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> bottom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent bottom check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> bottom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent cancel check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> cancel(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent cancel check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> cancel(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent CD-Rom check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> cdrom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent CD-Rom check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> cdrom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent centered check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> centered(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent centered check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> centered(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent clear check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> clear(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent clear check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> clear(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent close check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> close(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent close check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> close(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent color check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> color(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent color check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> color(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent contents check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> contents(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent contents check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> contents(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent convert check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> convert(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent convert check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> convert(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent copy check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> copy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent copy check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> copy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent customize check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> customize(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent customize check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> customize(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent cut check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> cut(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent cut check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> cut(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent delete check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> del(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent delete check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> del(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent descending check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> descending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent descending check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> descending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent down check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> down(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent down check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> down(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent edit check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> edit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent edit check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> edit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent execute check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> execute(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent execute check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> execute(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent file check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> file(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent file check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> file(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent find check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> find(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent find check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> find(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent first check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> first(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent first check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> first(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent floppy check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> floppy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent floppy check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> floppy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent font check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> font(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent font check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> font(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent forward check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> forward(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent forward check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> forward(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent hard disk check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> harddisk(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent hard disk check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> harddisk(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent help check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> help(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent help check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> help(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent home check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> home(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent home check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> home(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent ignore check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> ignore(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent ignore check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> ignore(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent indent check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> indent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent indent check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> indent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent index check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> index(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent index check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> index(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent info check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> info(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent info check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> info(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent italic check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> italic(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent italic check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> italic(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent justified check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> justified(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent justified check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> justified(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent jump_to check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> jump_to(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent jump to check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> jump_to(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent last check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> last(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent last check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> last(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent network check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> network(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent network check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> network(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent new check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> new_(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent new check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> new_(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent no check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> no(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent no check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> no(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent ok check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> ok(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent ok check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> ok(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent open check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> open(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent open check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> open(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent options check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> options(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent options check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> options(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent paste check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> paste(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent paste check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> paste(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent preferences check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> preferences(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent preferences check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> preferences(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent print check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> print(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent print check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> print(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent print preview check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> print_preview(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent print preview check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> print_preview(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent properties check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> properties(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent properties check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> properties(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent quit check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> quit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent quit check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> quit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent redo check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> redo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent redo check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> redo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent refresh check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> refresh(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent refresh check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> refresh(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent remove check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> remove(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent remove check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> remove(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent replace check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> replace(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent replace check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> replace(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent retry check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> retry(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent retry check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> retry(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent revert to saved check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> revert_to_saved(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent revert to saved check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> revert_to_saved(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent save check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> save(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent save check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> save(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent save as check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> save_as(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent save as check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> save_as(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent search check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> search(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent search check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> search(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent select all check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> select_all(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent select all check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> select_all(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent spell check check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> spell_check(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent spell check check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> spell_check(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent stop check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> stop(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent stop check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> stop(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent strikeout check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> strikeout(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent strikeout check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> strikeout(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent tools check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> tools(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent tools check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> tools(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent top check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> top(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent top check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> top(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent undelete check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> undelete(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent undelete check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> undelete(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent underline check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> underline(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent underline check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> underline(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent undo check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> undo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent undo check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> undo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represents an unindented check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> unindent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represents an unindented check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> unindent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent up check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> up(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent up check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> up(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent view check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> view(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent view check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> view(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent yes check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> yes(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent yes check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> yes(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent zoom in check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> zoom_in(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent zoom in check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> zoom_in(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent zoom out check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> zoom_out(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent zoom out check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> zoom_out(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent zoom to fit check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> zoom_to_fit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(system_texts::zoom_to_fit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined check_box that represent zoom to fit check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static std::unique_ptr<check_box> zoom_to_fit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<check_box>(parent, system_texts::zoom_to_fit(), location, size, back_color, fore_color);}
    };
  }
}
