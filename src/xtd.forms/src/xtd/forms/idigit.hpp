#pragma once
#include <xtd/drawing/color>
#include <xtd/interface>
#include <xtd/char32>
#include <xtd/int32>
#include <xtd/u32string>
#include "../../../include/xtd/forms/dot_matrix_style.hpp"
#include "../../../include/xtd/forms/segment_style.hpp"

class idigit interface_ {
public:
  virtual void back_digit_color(const xtd::drawing::color& value) = 0;
  virtual void back_digit_opacity(double value) = 0;
  virtual xtd::char32 character() const noexcept = 0;
  virtual void character(xtd::char32 value) = 0;
  virtual void dot_matrix_style_digit(xtd::forms::dot_matrix_style value) = 0;
  virtual void segment_style_digit(xtd::forms::segment_style value) = 0;
  virtual void show_back_digit(bool value) = 0;
  virtual xtd::int32 thickness_digit() const noexcept = 0;
  virtual void thickness_digit(xtd::int32 value) = 0;
  virtual xtd::array<xtd::char32> valid_characters() const noexcept = 0;
};
