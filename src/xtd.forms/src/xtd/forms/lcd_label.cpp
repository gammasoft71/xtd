#include "../../../include/xtd/forms/lcd_label.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

wchar_t lcd_label::dot_matrix_display_digit::get_character() const {
  return character_;
}

xtd::ustring lcd_label::dot_matrix_display_digit::get_valid_characters() const {
  return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=+-*/%\\_°\"'[](){}<>| .,:;!?&$€";
}

int32_t lcd_label::dot_matrix_display_digit::get_thickness() const {
  return thickness();
}

void lcd_label::dot_matrix_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_dot_color(value);
}

void lcd_label::dot_matrix_display_digit::set_back_digit_opacity(double value) {
  back_dot_opacity(value);
}

void lcd_label::dot_matrix_display_digit::set_character(wchar_t value) {
  static std::map<wchar_t, points_collection> characters {
    {'0', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {4, 2}, {5, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {2, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'1', {{3, 0}, {2, 1}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {'2', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {5, 2}, {4, 3}, {3, 4}, {2, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'3', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'4', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {5, 4}, {5, 5}, {5, 6}}},
    {'5', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {'6', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'7', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {5, 1}, {5, 2}, {4, 3}, {4, 4}, {3, 5}, {3, 6}}},
    {'8', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'9', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'A', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'B', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {'C', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 6}, {5, 5}, {4, 6}}},
    {'D', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {'E', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'F', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {1, 5}, {1, 6}}},
    {'G', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {1, 2}, {1, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'H', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'I', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {'J', {{5, 0}, {5, 1}, {5, 2}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'K', {{1, 0}, {5, 0}, {1, 1}, {4, 1}, {1, 2}, {3, 2}, {1, 3}, {2, 3}, {1, 4}, {3, 4}, {1, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {'L', {{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'M', {{1, 0}, {5, 0}, {1, 1}, {2, 1}, {4, 1}, {5, 1}, {1, 2}, {3, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'N', {{1, 0}, {5, 0}, {1, 1}, {2, 1}, {5, 1}, {1, 2}, {3, 2}, {5, 2}, {1, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'O', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'P', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {1, 5}, {1, 6}}},
    {'Q', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {4, 5}, {2, 6}, {3, 6}, {5, 6}}},
    {'R', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {3, 4}, {1, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {'S', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'T', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {'U', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'V', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {2, 3}, {4, 3}, {2, 4}, {4, 4}, {3, 5}, {3, 6}}},
    {'W', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {3, 2}, {5, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {3, 4}, {5, 4}, {1, 5}, {2, 5}, {4, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'X', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {2, 2}, {4, 2}, {3, 3}, {2, 4}, {4, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'Y', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {2, 2}, {4, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {'Z', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'a', {{2, 2}, {3, 2}, {4, 2}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'b', {{1, 0}, {1, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {'c', {{2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'d', {{5, 0}, {5, 1}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'e', {{2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {1, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'f', {{3, 0}, {4, 0}, {2, 1}, {2, 2}, {3, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}}},
    {'g', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'h', {{1, 0}, {1, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'i', {{3, 0}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {'j', {{4, 0}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {2, 6}, {3, 6}}},
    {'k', {{1, 0}, {1, 1}, {1, 2}, {5, 2}, {1, 3}, {4, 3}, {1, 4}, {2, 4}, {3, 4}, {1, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {'l', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 6}}},
    {'m', {{2, 2}, {4, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {3, 4}, {5, 4}, {1, 5}, {3, 5}, {5, 5}, {1, 6}, {3, 6}, {5, 6}}},
    {'n', {{2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {'o', {{2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'p', {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {1, 5}, {1, 6}}},
    {'q', {{2, 1}, {3, 1}, {4, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {5, 5}, {5, 6}}},
    {'r', {{2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}}},
    {'s', {{2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {'t', {{3, 0}, {3, 1}, {2, 2}, {3, 2}, {4, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 6}, {5, 6}}},
    {'u', {{1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'v', {{1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {4, 4}, {2, 5}, {4, 5}, {3, 6}}},
    {'w', {{1, 2}, {3, 2}, {5, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {3, 4}, {5, 4}, {1, 5}, {3, 5}, {5, 5}, {2, 6}, {4, 6}}},
    {'x', {{1, 2}, {5, 2}, {2, 3}, {4, 3}, {3, 4}, {2, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {'y', {{1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {'z', {{1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {4, 3}, {3, 4}, {2, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {'=', {{1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}}},
    {'+', {{3, 1}, {3, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {3, 4}, {3, 5}}},
    {'-', {{1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}}},
    {'*', {{3, 0}, {1, 1}, {3, 1}, {5, 1}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {1, 5}, {3, 5}, {5, 5}, {3, 6}}},
    {'/', {{5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}}},
    {'%', {{1, 0}, {2, 0}, {1, 1}, {2, 1}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}, {4, 5}, {5, 5}, {4, 6}, {5, 6}}},
    {'\\', {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}},
    {'_', {{1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {L'\u00B0', {{2, 0}, {3, 0}, {1, 1}, {4, 1}, {1, 2}, {4, 2}, {2, 3}, {3, 3}}},
    {'"', {{2, 0}, {5, 0}, {2, 1}, {5, 1}, {1, 2}, {4, 2}}},
    {'\'', {{3, 0}, {3, 1}, {2, 2}}},
    {'[', {{3, 0}, {4, 0}, {5, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {4, 6}, {5, 6}}},
    {']', {{1, 0}, {2, 0}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {1, 6}, {2, 6}, {3, 6}}},
    {'(', {{4, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 6}}},
    {')', {{2, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {2, 6}}},
    {'{', {{4, 0}, {5, 0}, {3, 1}, {3, 2}, {2, 3}, {3, 4}, {3, 5}, {4, 6}, {5, 6}}},
    {'}', {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}, {3, 4}, {3, 5}, {1, 6}, {2, 6}}},
    {'<', {{4, 1}, {3, 2}, {2, 3}, {3, 4}, {4, 5}}},
    {'>', {{2, 1}, {3, 2}, {4, 3}, {3, 4}, {2, 5}}},
    {'|', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {' ', {}},
    {'.', {{3, 6}}},
    {',', {{3, 5}, {2, 6}}},
    {':', {{3, 1}, {3, 5}}},
    {';', {{3, 2}, {3, 5}, {2, 6}}},
    {'!', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 6}}},
    {'?', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {5, 2}, {4, 3}, {3, 4}, {3, 6}}},
    {'&', {{2, 0}, {3, 0}, {1, 1}, {4, 1}, {1, 2}, {4, 2}, {2, 3}, {3, 3}, {5, 3}, {1, 4}, {4, 4}, {1, 5}, {4, 5}, {2, 6}, {3, 6}, {5, 6}}},
    {'$', {{3, 0}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {1, 2}, {3, 2}, {2, 3}, {3, 3}, {4, 3}, {3, 4}, {5, 4}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {3, 6}}},
    {L'\u20AC', {{3, 0}, {4, 0}, {5, 0}, {2, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {2, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {2, 5}, {3, 6}, {4, 6}, {5, 6}}},
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    set_dots(it->second);
  }
}

void lcd_label::dot_matrix_display_digit::set_segment_style(forms::segment_style value) {
}

void lcd_label::dot_matrix_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
  dot_matrix_style(value);
}

void lcd_label::dot_matrix_display_digit::set_show_back_digit(bool value) {
  show_back_dot(value);
}

void lcd_label::dot_matrix_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

wchar_t lcd_label::fourteen_segment_display_digit::get_character() const {
  return character_;
}

xtd::ustring lcd_label::fourteen_segment_display_digit::get_valid_characters() const {
  return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=+-*/\\_°\"'[]()| .,:";
}

int32_t lcd_label::fourteen_segment_display_digit::get_thickness() const {
  return thickness();
}

void lcd_label::fourteen_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_segment_color(value);
}

void lcd_label::fourteen_segment_display_digit::set_back_digit_opacity(double value) {
  back_segment_opacity(value);
}

void lcd_label::fourteen_segment_display_digit::set_character(wchar_t value) {
  static std::map<wchar_t, forms::segments> characters {
    {'0', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'1', forms::segments::b|forms::segments::c|forms::segments::j},
    {'2', forms::segments::a|forms::segments::b|forms::segments::d|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'3', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::g2},
    {'4', forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'5', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'6', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::e| forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'7', forms::segments::a|forms::segments::l|forms::segments::j},
    {'8', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g1|segments::g2},
    {'9', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'A', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'B', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d |forms::segments::g2|forms::segments::i|forms::segments::l},
    {'C', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f},
    {'D', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d |forms::segments::i|forms::segments::l},
    {'E', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'F', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'G', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g2},
    {'H', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'I', forms::segments::a|forms::segments::d|forms::segments::i|forms::segments::l},
    {'J', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e},
    {'K', forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::j|forms::segments::m},
    {'L', forms::segments::d|forms::segments::e|forms::segments::f},
    {'M', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::h|forms::segments::j},
    {'N', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::h|forms::segments::m},
    {'O', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'P', forms::segments::a|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'Q', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::m},
    {'R', forms::segments::a|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2|forms::segments::m},
    {'S', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::g2|forms::segments::h},
    {'T', forms::segments::a|forms::segments::i|forms::segments::l},
    {'U', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'V', forms::segments::e|forms::segments::f|forms::segments::j|forms::segments::k},
    {'W', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::k|forms::segments::m},
    {'X', forms::segments::h|forms::segments::j|forms::segments::k|forms::segments::m},
    {'Y', forms::segments::h|forms::segments::j|forms::segments::l},
    {'Z', forms::segments::a|forms::segments::d|forms::segments::j|forms::segments::k},
    {'a', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'b', forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::m},
    {'c', forms::segments::d|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'d', forms::segments::b|forms::segments::c|forms::segments::d|segments::g2|segments::k},
    {'e', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g1},
    {'f', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g1},
    {'g', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::h|forms::segments::g2},
    {'h', forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'i', forms::segments::l},
    {'j', forms::segments::b|forms::segments::c|forms::segments::d},
    {'k', forms::segments::i|forms::segments::l|forms::segments::j|forms::segments::m},
    {'l', forms::segments::i|forms::segments::l},
    {'m', forms::segments::c|forms::segments::e|forms::segments::g1|forms::segments::g2|forms::segments::l},
    {'n', forms::segments::e|forms::segments::g1|forms::segments::m},
    {'o', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'p', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::j},
    {'q', forms::segments::a|forms::segments::b|forms::segments::f|forms::segments::g1|forms::segments::g2|forms::segments::m},
    {'r', forms::segments::e|forms::segments::g},
    {'s', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::g2|forms::segments::h},
    {'t', forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g1},
    {'u', forms::segments::c|forms::segments::d|forms::segments::e},
    {'v', forms::segments::e|forms::segments::k},
    {'w', forms::segments::c|forms::segments::e|forms::segments::k|forms::segments::m},
    {'x', forms::segments::h|forms::segments::j|forms::segments::k|forms::segments::m},
    {'y', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::g2|forms::segments::i},
    {'z', forms::segments::a|forms::segments::d|forms::segments::j|forms::segments::k},
    {'=', forms::segments::d|forms::segments::g1|forms::segments::g2},
    {'+', forms::segments::g1|forms::segments::g2|forms::segments::i|forms::segments::l},
    {'-', forms::segments::g1|forms::segments::g2},
    {'*', forms::segments::g1|forms::segments::g2|forms::segments::h|forms::segments::i|forms::segments::j|forms::segments::k|forms::segments::l|forms::segments::m},
    {'/', forms::segments::j|forms::segments::k},
    {'\\', forms::segments::h|forms::segments::m},
    {'_', forms::segments::d},
    {L'\u00B0', forms::segments::a|forms::segments::b|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'"', forms::segments::b|forms::segments::f},
    {'\'', forms::segments::f},
    {'[', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f},
    {']', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d},
    {'(', forms::segments::j|forms::segments::m},
    {')', forms::segments::h|forms::segments::k},
    {'|', forms::segments::i|forms::segments::l},
    {' ', forms::segments::none},
    {'.', forms::segments::dp},
    {',', forms::segments::k},
    {':', forms::segments::pc}
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    fourteen_segment_display_digit::value(it->second);
  }
}

void lcd_label::fourteen_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::fourteen_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::fourteen_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::fourteen_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

wchar_t lcd_label::nine_segment_display_digit::get_character() const {
  return character_;
}

xtd::ustring lcd_label::nine_segment_display_digit::get_valid_characters() const {
  return "0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy=-_°\"'[]| .,:";
}

int32_t lcd_label::nine_segment_display_digit::get_thickness() const {
  return thickness();
}

void lcd_label::nine_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_segment_color(value);
}

void lcd_label::nine_segment_display_digit::set_back_digit_opacity(double value) {
  back_segment_opacity(value);
}

void lcd_label::nine_segment_display_digit::set_character(wchar_t value) {
  static std::map<wchar_t, forms::segments> characters {
    {'0', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'1', forms::segments::b|forms::segments::c},
    {'2', forms::segments::a|forms::segments::b|forms::segments::d|forms::segments::i},
    {'3', forms::segments::a|forms::segments::g|forms::segments::h|forms::segments::i},
    {'4', forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g},
    {'5', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'6', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g|forms::segments::h},
    {'7', forms::segments::a|forms::segments::e|forms::segments::h},
    {'8', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'9', forms::segments::a|forms::segments::b|forms::segments::f|forms::segments::g|forms::segments::i},
    {'A', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g},
    {'a', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'B', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'b', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'C', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f},
    {'c', forms::segments::d|forms::segments::e|forms::segments::g},
    {'D', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'d', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'E', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'e', forms::segments::a|forms::segments::b|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'F', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g},
    {'f', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g},
    {'G', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'g', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'H', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g},
    {'h', forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g},
    {'I', forms::segments::b|forms::segments::c},
    {'i', forms::segments::c},
    {'J', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e},
    {'j', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e},
    {'L', forms::segments::d|forms::segments::e|forms::segments::f},
    {'l', forms::segments::d|forms::segments::e},
    {'N', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f},
    {'n', forms::segments::c|forms::segments::e|forms::segments::g},
    {'O', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'o', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'P', forms::segments::a|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g},
    {'p', forms::segments::a|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g},
    {'Q', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g},
    {'q', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g},
    {'R', forms::segments::a|forms::segments::e|forms::segments::f},
    {'r', forms::segments::e|forms::segments::g},
    {'S', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'s', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'T', forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'t', forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'U', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'u', forms::segments::c|forms::segments::d|forms::segments::e},
    {'Y', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'y', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'=', forms::segments::d|forms::segments::g}, {'-', forms::segments::g},
    {'_', forms::segments::d},
    {L'\u00B0', forms::segments::a|forms::segments::b|forms::segments::f|forms::segments::g},
    {'"', forms::segments::b|forms::segments::f},
    {'\'', forms::segments::f},
    {'[', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f},
    {']', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d},
    {'|', forms::segments::b|forms::segments::c}, {' ', forms::segments::none},
    {'.', forms::segments::dp},
    {',', forms::segments::dp},
    {':', forms::segments::pc}
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    nine_segment_display_digit::value(it->second);
  }
}

void lcd_label::nine_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::nine_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::nine_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::nine_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

wchar_t lcd_label::seven_segment_display_digit::get_character() const {
  return character_;
}

xtd::ustring lcd_label::seven_segment_display_digit::get_valid_characters() const {
  return "0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy=-_°\"'[]| .,:";
}

int32_t lcd_label::seven_segment_display_digit::get_thickness() const {
  return thickness();
}

void lcd_label::seven_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_segment_color(value);
}

void lcd_label::seven_segment_display_digit::set_back_digit_opacity(double value) {
  back_segment_opacity(value);
}

void lcd_label::seven_segment_display_digit::set_character(wchar_t value) {
  static std::map<wchar_t, forms::segments> characters {
    {'0', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'1', forms::segments::b|forms::segments::c},
    {'2', forms::segments::a|forms::segments::b|forms::segments::d|forms::segments::e|forms::segments::g},
    {'3', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::g},
    {'4', forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g},
    {'5', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'6', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'7', forms::segments::a|forms::segments::b|forms::segments::c},
    {'8', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'9', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'A', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g},
    {'a', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'B', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'b', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'C', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f},
    {'c', forms::segments::d|forms::segments::e|forms::segments::g},
    {'D', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'d', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'E', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'e', forms::segments::a|forms::segments::b|forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'F', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g},
    {'f', forms::segments::a|forms::segments::e|forms::segments::f|forms::segments::g},
    {'G', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'g', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'H', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g},
    {'h', forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g},
    {'I', forms::segments::b|forms::segments::c},
    {'i', forms::segments::c},
    {'J', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e},
    {'j', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e},
    {'L', forms::segments::d|forms::segments::e|forms::segments::f},
    {'l', forms::segments::d|forms::segments::e},
    {'N', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f},
    {'n', forms::segments::c|forms::segments::e|forms::segments::g},
    {'O', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'o', forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::g},
    {'P', forms::segments::a|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g},
    {'p', forms::segments::a|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g},
    {'Q', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g},
    {'q', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g},
    {'R', forms::segments::a|forms::segments::e|forms::segments::f},
    {'r', forms::segments::e|forms::segments::g},
    {'S', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'s', forms::segments::a|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'T', forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'t', forms::segments::d|forms::segments::e|forms::segments::f|forms::segments::g},
    {'U', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::e|forms::segments::f},
    {'u', forms::segments::c|forms::segments::d|forms::segments::e},
    {'Y', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'y', forms::segments::b|forms::segments::c|forms::segments::d|forms::segments::f|forms::segments::g},
    {'=', forms::segments::d|forms::segments::g},
    {'-', forms::segments::g},
    {'_', forms::segments::d},
    {L'\u00B0', forms::segments::a|forms::segments::b|forms::segments::f|forms::segments::g},
    {'"', forms::segments::b|forms::segments::f},
    {'\'', forms::segments::f},
    {'[', forms::segments::a|forms::segments::d|forms::segments::e|forms::segments::f},
    {']', forms::segments::a|forms::segments::b|forms::segments::c|forms::segments::d},
    {'|', forms::segments::b|forms::segments::c}, {' ', forms::segments::none},
    {'.', forms::segments::dp},
    {',', forms::segments::dp},
    {':', forms::segments::pc}};
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    seven_segment_display::value(it->second);
  }
}

void lcd_label::seven_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::seven_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::seven_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::seven_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

wchar_t lcd_label::sixteen_segment_display_digit::get_character() const {
  return character_;
}

xtd::ustring lcd_label::sixteen_segment_display_digit::get_valid_characters() const {
  return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=+-*/\\_°\"'[]()| .,:";
}

int32_t lcd_label::sixteen_segment_display_digit::get_thickness() const {
  return sixteen_segment_display::thickness();
}

void lcd_label::sixteen_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {sixteen_segment_display::back_segment_color(value);}
void lcd_label::sixteen_segment_display_digit::set_back_digit_opacity(double value) {sixteen_segment_display::back_segment_opacity(value);}
void lcd_label::sixteen_segment_display_digit::set_character(wchar_t value) {
  static std::map<wchar_t, forms::segments> characters {
    {'0', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f},
    {'1', forms::segments::b|forms::segments::c|forms::segments::j},
    {'2', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'3', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::g2},
    {'4', forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'5', forms::segments::a1|forms::segments::a2|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'6', forms::segments::a1|forms::segments::a2|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'7', forms::segments::a1|forms::segments::a2|forms::segments::l|forms::segments::j},
    {'8', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g1|segments::g2},
    {'9', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'A', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'B', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::g2|forms::segments::i|forms::segments::l},
    {'C', forms::segments::a1|forms::segments::a2|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f},
    {'D', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::i|forms::segments::l},
    {'E', forms::segments::a1|forms::segments::a2|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'F', forms::segments::a1|forms::segments::a2|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'G', forms::segments::a1|forms::segments::a2|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g2},
    {'H', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'I', forms::segments::a1|forms::segments::a2|forms::segments::d1|forms::segments::d2|forms::segments::i|forms::segments::l},
    {'J', forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e},
    {'K', forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::j|forms::segments::m},
    {'L', forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f},
    {'M', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::h|forms::segments::j},
    {'N', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::h|forms::segments::m},
    {'O', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f},
    {'P', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'Q', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::m},
    {'q', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::f|forms::segments::g1|forms::segments::g2|forms::segments::m},
    {'R', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2|forms::segments::m},
    {'S', forms::segments::a1|forms::segments::a2|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::g2|forms::segments::h},
    {'T', forms::segments::a1|forms::segments::a2|forms::segments::i|forms::segments::l},
    {'U', forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f},
    {'V', forms::segments::e|forms::segments::f|forms::segments::j|forms::segments::k},
    {'W', forms::segments::b|forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::k|forms::segments::m},
    {'X', forms::segments::h|forms::segments::j|forms::segments::k|forms::segments::m},
    {'Y', forms::segments::h|forms::segments::j|forms::segments::l},
    {'Z', forms::segments::a1|forms::segments::a2|forms::segments::d1|forms::segments::d2|forms::segments::j|forms::segments::k},
    {'a', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'b', forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::m},
    {'c', forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'d', forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|segments::g2|segments::k},
    {'e', forms::segments::a1|forms::segments::a2|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g1},
    {'f', forms::segments::a1|forms::segments::a2|forms::segments::e|forms::segments::f|forms::segments::g1},
    {'g', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::h|forms::segments::g2},
    {'h', forms::segments::c|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'i', forms::segments::l},
    {'j', forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2},
    {'k', forms::segments::i|forms::segments::l|forms::segments::j|forms::segments::m},
    {'l', forms::segments::i|forms::segments::l},
    {'m', forms::segments::c|forms::segments::e|forms::segments::g1|forms::segments::g2|forms::segments::l},
    {'n', forms::segments::e|forms::segments::g1|forms::segments::m},
    {'o', forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::g1|forms::segments::g2},
    {'p', forms::segments::a1|forms::segments::a2|forms::segments::e|forms::segments::f|forms::segments::g1|forms::segments::j},
    {'r', forms::segments::e|forms::segments::g},
    {'s', forms::segments::a1|forms::segments::a2|forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::g2|forms::segments::h},
    {'t', forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f|forms::segments::g1},
    {'u', forms::segments::c|forms::segments::d1|forms::segments::d2|forms::segments::e},
    {'v', forms::segments::e|forms::segments::k},
    {'w', forms::segments::c|forms::segments::e|forms::segments::k|forms::segments::m},
    {'x', forms::segments::h|forms::segments::j|forms::segments::k|forms::segments::m},
    {'y', forms::segments::b|forms::segments::c|forms::segments::d2|forms::segments::g2|forms::segments::i},
    {'z', forms::segments::g1|forms::segments::d1|forms::segments::k},
    {'=', forms::segments::d1|forms::segments::d2|forms::segments::g1|forms::segments::g2},
    {'+', forms::segments::g1|forms::segments::g2|forms::segments::i|forms::segments::l},
    {'-', forms::segments::g1|forms::segments::g2},
    {'*', forms::segments::g1|forms::segments::g2|forms::segments::h|forms::segments::i|forms::segments::j|forms::segments::k|forms::segments::l|forms::segments::m},
    {'/', forms::segments::j|forms::segments::k},
    {'\\', forms::segments::h|forms::segments::m},
    {'_', forms::segments::d1|forms::segments::d2},
    {L'\u00B0', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::f|forms::segments::g1|forms::segments::g2},
    {'"', forms::segments::b|forms::segments::f},
    {'\'', forms::segments::f},
    {'[', forms::segments::a1|forms::segments::a2|forms::segments::d1|forms::segments::d2|forms::segments::e|forms::segments::f},
    {']', forms::segments::a1|forms::segments::a2|forms::segments::b|forms::segments::c|forms::segments::d1|forms::segments::d2},
    {'(', forms::segments::j|forms::segments::m},
    {')', forms::segments::h|forms::segments::k},
    {'|', forms::segments::i|forms::segments::l},
    {' ', forms::segments::none},
    {'.', forms::segments::dp},
    {',', forms::segments::k},
    {':', forms::segments::pc}
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    sixteen_segment_display::value(it->second);
  }
}

void lcd_label::sixteen_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::sixteen_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::sixteen_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::sixteen_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

lcd_label::lcd_label() {
  auto_size_mode_ = forms::auto_size_mode::grow_and_shrink;
  size_ = default_size();
}

xtd::drawing::color lcd_label::back_digit_color() const {
  return back_digit_color_.value_or(fore_color());
}

lcd_label& lcd_label::back_digit_color(const xtd::drawing::color& value) {
  if (!back_digit_color_.has_value() || back_digit_color_.value() != value) {
    back_digit_color_ = value;
    set_digits_params();
  }
  return *this;
}

double lcd_label::back_digit_opacity() const {
  return back_digit_opacity_;
}

lcd_label& lcd_label::back_digit_opacity(double value) {
  if (value < 0.0 || value > 1.0) throw argument_out_of_range_exception("value must be between 0.0 and 1.0."_t, current_stack_frame_);
  if (back_digit_opacity_ != value) {
    back_digit_opacity_ = value;
    set_digits_params();
  }
  return *this;
}

bool lcd_label::show_back_digit() const {
  return show_back_digit_;
}

lcd_label& lcd_label::show_back_digit(bool value) {
  if (show_back_digit_ != value) {
    show_back_digit_ = value;
    set_digits_params();
  }
  return *this;
}

int32_t lcd_label::digit_spacing() const {
  return digit_spacing_.value_or(lcd_style_ == lcd_style::dot_matrix_display ? 0 : thickness());
}

lcd_label& lcd_label::digit_spacing(int32_t value) {
  if (value < 0) throw argument_out_of_range_exception("value must be positive"_t, current_stack_frame_);
  if (digit_spacing_ != value) {
    digit_spacing_ = value;
    set_digits_params();
  }
  return *this;
}

forms::lcd_style lcd_label::lcd_style() const {
  return lcd_style_;
}

lcd_label& lcd_label::lcd_style(forms::lcd_style value) {
  if (lcd_style_ != value) {
    lcd_style_ = value;
    xtd::ustring current_text = text();
    text("");
    text(current_text);
  }
  return *this;
}

forms::segment_style lcd_label::segment_style() const {
  return segment_style_;
}

lcd_label& lcd_label::segment_style(forms::segment_style value) {
  if (segment_style_ != value) {
    segment_style_ = value;
    for (auto& digit : digits_)
      digit->set_segment_style(value);
  }
  return *this;
}

forms::dot_matrix_style lcd_label::dot_matrix_style() const {
  return dot_matrix_style_;
}

lcd_label& lcd_label::dot_matrix_style(forms::dot_matrix_style value) {
  if (dot_matrix_style_ != value) {
    dot_matrix_style_ = value;
    for (auto& digit : digits_)
      digit->set_dot_matrix_style(value);
  }
  return *this;
}

int32_t lcd_label::thickness() const {
  return thickness_.value_or(digits_.size() ? digits_[0]->get_thickness() : 1);
}

lcd_label& lcd_label::thickness(int32_t value) {
  if (thickness_ != value) {
    thickness_ = value;
    set_digits_params();
  }
  return *this;
}

control& lcd_label::text(const xtd::ustring& value) {
  if (text_ != value) {
    suspend_layout();
    std::wstring str = convert_string::to_wstring(value);
    if (str.size() < digits_.size()) {
      for (size_t index = digits_.size(); index < str.size(); index++) {
        dynamic_cast<control*>(digits_[index].get())->mouse_down -= {*this, &lcd_label::on_digit_mouse_down};
        dynamic_cast<control*>(digits_[index].get())->mouse_move -= {*this, &lcd_label::on_digit_mouse_move};
        dynamic_cast<control*>(digits_[index].get())->mouse_up -= {*this, &lcd_label::on_digit_mouse_up};
      }
      digits_.erase(digits_.begin() + str.size(), digits_.end());
    }
    if (str.size() > digits_.size())
      for (size_t index = digits_.size(); index < str.size(); index++) {
        switch (lcd_style_) {
          case lcd_style::seven_segment_display: digits_.push_back(std::make_shared<seven_segment_display_digit>()); break;
          case lcd_style::nine_segment_display: digits_.push_back(std::make_shared<nine_segment_display_digit>()); break;
          case lcd_style::fourteen_segment_display: digits_.push_back(std::make_shared<fourteen_segment_display_digit>()); break;
          case lcd_style::sixteen_segment_display: digits_.push_back(std::make_shared<sixteen_segment_display_digit>()); break;
          case lcd_style::dot_matrix_display: digits_.push_back(std::make_shared<dot_matrix_display_digit>()); break;
          default: throw argument_exception("lcd_style invalid", current_stack_frame_);
        }
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->parent(*this);
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->click += {*this, &lcd_label::on_digit_click};
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_down += {*this, &lcd_label::on_digit_mouse_down};
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_move += {*this, &lcd_label::on_digit_mouse_move};
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_up += {*this, &lcd_label::on_digit_mouse_up};
      }
    for (size_t index = 0; index < str.size(); index++)
      digits_[index]->set_character(str[index]);
    set_digits_params();
    control::text(value);
    resume_layout();
  }
  return *this;
}

xtd::ustring lcd_label::valid_characters() {
  switch (lcd_style_) {
    case lcd_style::seven_segment_display: return std::make_shared<seven_segment_display_digit>()->get_valid_characters();
    case lcd_style::nine_segment_display: return std::make_shared<nine_segment_display_digit>()->get_valid_characters();
    case lcd_style::fourteen_segment_display: return std::make_shared<fourteen_segment_display_digit>()->get_valid_characters();
    case lcd_style::sixteen_segment_display: return std::make_shared<sixteen_segment_display_digit>()->get_valid_characters();
    case lcd_style::dot_matrix_display: return std::make_shared<dot_matrix_display_digit>()->get_valid_characters();
    default: throw argument_exception("lcd_style invalid", current_stack_frame_);
  }
}

drawing::size lcd_label::default_size() const {
  return {100, 25};
}

void lcd_label::on_back_color_changed(const event_args& e) {
  control::on_back_color_changed(e);
  invalidate();
}

void lcd_label::on_fore_color_changed(const event_args& e) {
  control::on_fore_color_changed(e);
  invalidate();
}

void lcd_label::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  set_digits_params();
}

void lcd_label::on_size_changed(const event_args& e) {
  set_digits_params();
  control::on_size_changed(e);
}

void lcd_label::on_resize(const event_args& e) {
  set_digits_params();
  control::on_resize(e);
}

drawing::size lcd_label::measure_control() const {
  if (digits_.size() == 0) return {0, size_.height()};
  return drawing::size((dynamic_cast<control*>(digits_[0].get())->width() - 2 + digit_spacing()) * static_cast<int32_t>(digits_.size()) - digit_spacing() + 2, size_.height());
}

void lcd_label::on_digit_click(object& sender, const event_args& e) {
  on_click(e);
}

void lcd_label::on_digit_mouse_down(object& sender, const mouse_event_args& e) {
  on_mouse_down(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::on_digit_mouse_move(object& sender, const mouse_event_args& e) {
  on_mouse_move(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::on_digit_mouse_up(object& sender, const mouse_event_args& e) {
  on_mouse_up(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::set_digits_params() {
  int32_t offset_left = 0;
  for (auto& digit : digits_) {
    dynamic_cast<control*>(digit.get())->height(size_.height());
    dynamic_cast<control*>(digit.get())->left(offset_left);
    digit->set_back_digit_color(back_digit_color());
    digit->set_back_digit_opacity(back_digit_opacity_);
    digit->set_show_back_digit(show_back_digit_);
    digit->set_segment_style(segment_style_);
    digit->set_dot_matrix_style(dot_matrix_style_);
    if (thickness_.has_value()) digit->set_thickness(thickness());
    offset_left += dynamic_cast<control*>(digit.get())->width() - 2 + digit_spacing();
  }
}
