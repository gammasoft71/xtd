#pragma once
#include "idigit.hpp"
#include "../../../include/xtd/forms/fourteen_segment_display.hpp"
#include <xtd/collections/generic/dictionary>
#include <xtd/helpers/throw_helper>
#include <xtd/globalization/translator>

class fourteen_segment_display_digit : public xtd::forms::fourteen_segment_display, public idigit {
public:
  fourteen_segment_display_digit() = default;
  
  void back_digit_color(const xtd::drawing::color& value) override {xtd::forms::fourteen_segment_display::back_segment_color(value);}
  void back_digit_opacity(double value) override {xtd::forms::fourteen_segment_display::back_segment_opacity(value);}
  xtd::char32 character() const noexcept override {return character_;}
  void character(xtd::char32 value) override {
    if (character_ == value) return;
    if (!characters_.contains_key(value)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, xtd::string::format(xtd::globalization::translator::translate("Only characters : \"{}\" are valid"), valid_characters()).chars().c_str());
    character_ = value;
    fourteen_segment_display_digit::value(characters_[value]);
  }
  void dot_matrix_style_digit(xtd::forms::dot_matrix_style value) override {}
  void segment_style_digit(xtd::forms::segment_style value) override {xtd::forms::fourteen_segment_display::segment_style(value);}
  void show_back_digit(bool value) override {xtd::forms::fourteen_segment_display::show_back_segment(value);}
  xtd::int32 thickness_digit() const noexcept override {return xtd::forms::fourteen_segment_display::thickness();}
  void thickness_digit(xtd::int32 value) override {xtd::forms::fourteen_segment_display::thickness(value);}
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
    {U'1', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::j},
    {U'2', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'3', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::g2},
    {U'4', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'5', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'6', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'7', xtd::forms::segments::a | xtd::forms::segments::l | xtd::forms::segments::j},
    {U'8', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'9', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'A', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'B', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::g2 | xtd::forms::segments::i | xtd::forms::segments::l},
    {U'C', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'D', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::i | xtd::forms::segments::l},
    {U'E', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'F', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'G', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g2},
    {U'H', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'I', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::i | xtd::forms::segments::l},
    {U'J', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e},
    {U'K', xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::j | xtd::forms::segments::m},
    {U'L', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'M', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::h | xtd::forms::segments::j},
    {U'N', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::h | xtd::forms::segments::m},
    {U'O', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'P', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'Q', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::m},
    {U'R', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2 | xtd::forms::segments::m},
    {U'S', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::g2 | xtd::forms::segments::h},
    {U'T', xtd::forms::segments::a | xtd::forms::segments::i | xtd::forms::segments::l},
    {U'U', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U'V', xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::j | xtd::forms::segments::k},
    {U'W', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::k | xtd::forms::segments::m},
    {U'X', xtd::forms::segments::h | xtd::forms::segments::j | xtd::forms::segments::k | xtd::forms::segments::m},
    {U'Y', xtd::forms::segments::h | xtd::forms::segments::j | xtd::forms::segments::l},
    {U'Z', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::j | xtd::forms::segments::k},
    {U'a', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'b', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::m},
    {U'c', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'd', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::g2 | xtd::forms::segments::k},
    {U'e', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1},
    {U'f', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1},
    {U'g', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::h | xtd::forms::segments::g2},
    {U'h', xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'i', xtd::forms::segments::l},
    {U'j', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d},
    {U'k', xtd::forms::segments::i | xtd::forms::segments::l | xtd::forms::segments::j | xtd::forms::segments::m},
    {U'l', xtd::forms::segments::i | xtd::forms::segments::l},
    {U'm', xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::g1 | xtd::forms::segments::g2 | xtd::forms::segments::l},
    {U'n', xtd::forms::segments::e | xtd::forms::segments::g1 | xtd::forms::segments::m},
    {U'o', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'p', xtd::forms::segments::a | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::j},
    {U'q', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2 | xtd::forms::segments::m},
    {U'r', xtd::forms::segments::e | xtd::forms::segments::g},
    {U's', xtd::forms::segments::a | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::g2 | xtd::forms::segments::h},
    {U't', xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f | xtd::forms::segments::g1},
    {U'u', xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::e},
    {U'v', xtd::forms::segments::e | xtd::forms::segments::k},
    {U'w', xtd::forms::segments::c | xtd::forms::segments::e | xtd::forms::segments::k | xtd::forms::segments::m},
    {U'x', xtd::forms::segments::h | xtd::forms::segments::j | xtd::forms::segments::k | xtd::forms::segments::m},
    {U'y', xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d | xtd::forms::segments::g2 | xtd::forms::segments::i},
    {U'z', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::j | xtd::forms::segments::k},
    {U'=', xtd::forms::segments::d | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'+', xtd::forms::segments::g1 | xtd::forms::segments::g2 | xtd::forms::segments::i | xtd::forms::segments::l},
    {U'-', xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'*', xtd::forms::segments::g1 | xtd::forms::segments::g2 | xtd::forms::segments::h | xtd::forms::segments::i | xtd::forms::segments::j | xtd::forms::segments::k | xtd::forms::segments::l | xtd::forms::segments::m},
    {U'/', xtd::forms::segments::j | xtd::forms::segments::k},
    {U'\\', xtd::forms::segments::h | xtd::forms::segments::m},
    {U'_', xtd::forms::segments::d},
    {U'°', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::f | xtd::forms::segments::g1 | xtd::forms::segments::g2},
    {U'"', xtd::forms::segments::b | xtd::forms::segments::f},
    {U'\'', xtd::forms::segments::f},
    {U'[', xtd::forms::segments::a | xtd::forms::segments::d | xtd::forms::segments::e | xtd::forms::segments::f},
    {U']', xtd::forms::segments::a | xtd::forms::segments::b | xtd::forms::segments::c | xtd::forms::segments::d},
    {U'(', xtd::forms::segments::j | xtd::forms::segments::m},
    {U')', xtd::forms::segments::h | xtd::forms::segments::k},
    {U'|', xtd::forms::segments::i | xtd::forms::segments::l},
    {U' ', xtd::forms::segments::none},
    {U'.', xtd::forms::segments::dp},
    {U',', xtd::forms::segments::k},
    {U':', xtd::forms::segments::pc}
  };
};
