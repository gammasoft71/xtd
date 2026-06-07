/// @file
/// @brief Contains xtd::forms::lcd_label control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "dot_matrix_display.hpp"
#include "lcd_style.hpp"
#include "nine_segment_display.hpp"
#include "seven_segment_display.hpp"
#include "fourteen_segment_display.hpp"
#include "sixteen_segment_display.hpp"
#include <xtd/argument_out_of_range_exception>
#include <xtd/convert_string>
#include <xtd/as>
#include <xtd/interface>

namespace xtd {
  namespace forms {
    /// @brief Represents a lcd label.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/lcd_label>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                | macOS                                  | Gnome                                  |
    /// | ----- | -------------------------------------- | -------------------------------------- | -------------------------------------- |
    /// | Light |  @image html control_lcd_label_w.png   |  @image html control_lcd_label_m.png   |  @image html control_lcd_label_g.png   |
    /// | Dark  |  @image html control_lcd_label_wd.png  |  @image html control_lcd_label_md.png  |  @image html control_lcd_label_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of lcd_label control.
    /// @include lcd_label.cpp
    /// @par Examples
    /// The following code example demonstrates the use of lcd_label control.
    /// @include lcd_label2.cpp
    class lcd_label : public control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialise a new lcd_label class.
      lcd_label();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets background digit color.
      /// @return A xtd::drawing color that represent the background digit color.
      /// @remarks Do not confuse back_digit_color and back_color. Background digit color is the color when digit is off.
      [[nodiscard]] auto back_digit_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets background digit color.
      /// @param value A xtd::drawing color that represent the background digit color.
      /// @return Current lcd_label.
      /// @remarks Do not confuse back_digit_color and back_color. Background digit color is the color when digit is off.
      auto back_digit_color(const xtd::drawing::color& value) -> lcd_label&;
      
      /// @brief Gets the background digit opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background digit opacity.
      [[nodiscard]] auto back_digit_opacity() const noexcept -> double;
      /// @brief Sets the background digit opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background digit opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current lcd_label.
      auto back_digit_opacity(double value) -> lcd_label&;
      
      /// @brief Gets a value indicate if background digits are shown.
      /// @return `true` if background digits are shown; otherwise `false`
      [[nodiscard]] auto show_back_digit() const noexcept -> bool;
      /// @brief Sets a value indicate if background digits are shown.
      /// @param value `true` if background digits are shown; otherwise `false`
      /// @return Current lcd_label.
      auto show_back_digit(bool value) -> lcd_label&;
      
      /// @brief Gets the digit spacing.
      /// @return A int32 represent the digit spacing.
      [[nodiscard]] auto digit_spacing() const noexcept -> xtd::int32;
      /// @brief Sets the digit spacing.
      /// @param value A int32 represent the digit spacing.
      /// @return Current lcd_label.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.
      auto digit_spacing(xtd::int32 value) -> lcd_label&;
      
      /// @brief Gets lcd style.
      /// @return One of xtd::forms::lcd_style values. The default is xtd::forms::lcd_style::seven_segment_display.
      [[nodiscard]] auto lcd_style() const noexcept -> xtd::forms::lcd_style;
      /// @brief Sets lcd style.
      /// @param value One of xtd::forms::lcd_style values. The default is xtd::forms::lcd_style::seven_segment_display.
      /// @return Current lcd_label.
      auto lcd_style(xtd::forms::lcd_style value) -> lcd_label&;
      
      /// @brief Gets segment style.
      /// @return One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      [[nodiscard]] auto segment_style() const noexcept -> xtd::forms::segment_style;
      /// @brief Sets segment style.
      /// @param value One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      /// @return Current lcd_label.
      auto segment_style(xtd::forms::segment_style value) -> lcd_label&;
      
      /// @brief Gets dot matrix style.
      /// @return One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      [[nodiscard]] auto dot_matrix_style() const noexcept -> xtd::forms::dot_matrix_style;
      /// @brief Sets dot matrix style.
      /// @param value One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      /// @return Current lcd_label.
      auto dot_matrix_style(xtd::forms::dot_matrix_style value) -> lcd_label&;
      
      /// @brief Gets thickness of lcd.
      /// @return A int32 that represent the lcd thickness.
      [[nodiscard]] auto thickness() const noexcept -> xtd::int32;
      /// @brief Sets thickness of lcd.
      /// @param value A int32 that represent the lcd thickness.
      /// @return Current lcd_label.
      auto thickness(xtd::int32 value) -> lcd_label&;
      
      using xtd::forms::control::text;
      /// @brief Sets the text associated with this control.
      /// @param value The text associated with this control.
      /// @return Current control.
      auto text(const xtd::string& value) -> xtd::forms::control& override;
      
      /// @brief Gets valid characters.
      /// @return A xtd::array<char32> that represent valid characters.
      /// @remarks The valid characters are different according to lcd_style. See table below :
      /// @remarks
      /// | xtd::forms::lcd_label::lcd_style                 | ` ` | `!` | `"` | `$` | `%` | `&` |  '  | `(` | `)` | `*` | `+` | `,` | `-` | `.` | `/` | `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8` | `9` | `:` | `;` | `<` | `=` | `>` | `?` | `A` | `B` | `C` | `D` | `E` | `F` | `G` | `H` | `I` | `J` | `K` | `L` | `M` | `N` | `O` | `P` | `Q` | `R` | `S` | `T` | `U` | `V` | `W` | `X` | `Y` | `Z` | `[` | \\  | `]` | `_` | `a` | `b` | `c` | `d` | `e` | `f` | `g` | `h` | `i` | `j` | `k` | `l` | `m` | `n` | `o` | `p` | `q` | `r` | `s` | `t` | `u` | `v` | `w` | `x` | `y` | `z` | `{` | \|  | `}` | `°` | `€` |
      /// |--------------------------------------------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
      /// | xtd::forms::lcd_style::seven_segment_display     |  ✔️  |  ❌  |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ✔️  |  ❌  |  ✔️  |  ❌  |
      /// | xtd::forms::lcd_style::nine_segment_display      |  ✔️  |  ❌  |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ✔️  |  ❌  |  ✔️  |  ❌  |
      /// | xtd::forms::lcd_style::fourteen_segment_display  |  ✔️  |  ❌  |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️  |  ❌  |
      /// | xtd::forms::lcd_style::sixteen_segment_display   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ❌  |  ✔️  |  ❌  |  ❌  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ❌  |  ✔️  |  ❌  |  ✔️  |  ❌  |
      /// | xtd::forms::lcd_style::dot_matrix_display        |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |  ✔️   |  ✔️  |
      [[nodiscard]] auto valid_characters() -> xtd::array<xtd::char32>;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create() -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @param name The name of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified text.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::string& text) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @param name The name of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent,.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, location.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @param name The name of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> lcd_label;
      /// @brief A factory to create an xtd::forms::lcd_label with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::lcd_label.
      /// @param text A string that represent text of the xtd::forms::lcd_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::lcd_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::lcd_label.
      /// @param name The name of the xtd::forms::lcd_label.
      /// @return New xtd::forms::lcd_label created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> lcd_label;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}

      /// @name Protected Methods
      
      /// @{

      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;

      auto on_back_color_changed(const xtd::event_args& e)  -> void override;
      auto on_fore_color_changed(const xtd::event_args& e) -> void override;
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto on_size_changed(const xtd::event_args& e) -> void override;
      auto on_resize(const xtd::event_args& e) -> void override;
      /// @}
      
    private:
      auto on_digit_click(xtd::object& sender, const xtd::event_args& e) -> void;
      auto on_digit_mouse_down(xtd::object& sender, const xtd::forms::mouse_event_args& e) -> void;
      auto on_digit_mouse_move(xtd::object& sender, const xtd::forms::mouse_event_args& e) -> void;
      auto on_digit_mouse_up(xtd::object& sender, const xtd::forms::mouse_event_args& e) -> void;
      auto set_digits_params() -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
