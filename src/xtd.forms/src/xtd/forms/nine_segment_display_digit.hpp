#pragma once
#include "idigit.hpp"
#include "../../../include/xtd/forms/nine_segment_display.hpp"
#include <xtd/collections/generic/dictionary>
#include <xtd/helpers/throw_helper>
#include <xtd/globalization/translator>

class nine_segment_display_digit : public xtd::forms::nine_segment_display, public idigit {
public:
  nine_segment_display_digit() = default;
  
  void back_digit_color(const xtd::drawing::color& value) override {xtd::forms::nine_segment_display::back_segment_color(value);}
  void back_digit_opacity(double value) override {xtd::forms::nine_segment_display::back_segment_opacity(value);}
  xtd::char32 character() const noexcept override {return character_;}
  void character(xtd::char32 value) override {
    if (character_ == value) return;
    if (!characters_.contains_key(value)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, xtd::string::format(xtd::globalization::translator::translate("Only characters : \"{}\" are valid"), valid_characters()).chars().c_str());
    character_ = value;
    nine_segment_display_digit::value(characters_[value]);
  }
  void dot_matrix_style_digit(xtd::forms::dot_matrix_style value) override {}
  void segment_style_digit(xtd::forms::segment_style value) override {xtd::forms::nine_segment_display::segment_style(value);}
  void show_back_digit(bool value) override {xtd::forms::nine_segment_display::show_back_segment(value);}
  xtd::int32 thickness_digit() const noexcept override {return xtd::forms::nine_segment_display::thickness();}
  void thickness_digit(xtd::int32 value) override {xtd::forms::nine_segment_display::thickness(value);}
  xtd::array<xtd::char32> valid_characters() const noexcept override {
    static auto vc = xtd::collections::generic::list<xtd::char32> {};
    if (vc.count()) return xtd::array<xtd::char32>(vc);
    vc = characters_.keys();
    vc.sort();
    return xtd::array<xtd::char32>(vc);
  }
  
private:
  xtd::char32 character_ = U' ';
  inline static xtd::collections::generic::dictionary<xtd::char32, xtd::forms::segments> characters_ {
    {U'0', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'1', xtd::forms::segments::b | xtd::forms::segments::c},
    {U'2', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::d | xtd::forms::segments::i},
    {U'3', xtd::forms::segments::a | xtd::forms::segments::g | xtd::forms::segments::h | xtd::forms::segments::i},
    {U'4', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'5', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'6', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g | xtd::forms::segments::h},
    {U'7', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::h},
    {U'8', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'9', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::f | xtd::forms::segments::g | xtd::forms::segments::i},
    {U'A', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'a', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g},
    {U'B', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'b', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'C', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'c', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g},
    {U'D', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g},
    {U'd', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g},
    {U'E', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'e', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'F', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'f', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'G', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'g', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'H', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'h', xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'I', xtd::forms::segments::b | xtd::forms::segments::c},
    {U'i', xtd::forms::segments::c},
    {U'J', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e},
    {U'j', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e},
    {U'L', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'l', xtd::forms::segments::d | xtd::forms::segments::e},
    {U'N', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'n', xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::g},
    {U'O', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'o', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g},
    {U'P', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'p', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'Q', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'q', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'R', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'r', xtd::forms::segments::e | xtd::forms::segments::g},
    {U'S', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g},
    {U's', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'T', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U't', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'U', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'u', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e},
    {U'Y', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'y', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'=', xtd::forms::segments::d | xtd::forms::segments::g}, {'-', xtd::forms::segments::g},
    {U'_', xtd::forms::segments::d},
    {U'°', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::f | xtd::forms::segments::g},
    {U'"', xtd::forms::segments::b | xtd::forms::segments::f},
    {U'\'', xtd::forms::segments::f},
    {U'[', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U']', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d},
    {U'|', xtd::forms::segments::b | xtd::forms::segments::c},
    {U' ', xtd::forms::segments::none},
    {U'.', xtd::forms::segments::dp},
    {U',', xtd::forms::segments::dp},
    {U':', xtd::forms::segments::pc}
  };
};
