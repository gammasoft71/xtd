#include "../../../include/xtd/forms/font_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/font_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct font_dialog::data {
  drawing::color color = application::style_sheet().system_colors().control_text();
  drawing::font font = drawing::system_fonts::default_font();
  size_t max_size = 0;
  size_t min_size = 0;
  size_t options = CF_TTONLY;
  bool show_color = false;
};

font_dialog::font_dialog() : data_(std::make_shared<data>()) {
}

bool font_dialog::allow_script_change() const noexcept {
  return !get_option(CF_SELECTSCRIPT);
}

font_dialog& font_dialog::allow_script_change(bool allow_script_change) {
  set_option(CF_SELECTSCRIPT, !allow_script_change);
  return *this;
}

bool font_dialog::allow_simulation() const noexcept {
  return !get_option(CF_NOSIMULATIONS);
}

font_dialog& font_dialog::allow_simulation(bool allow_simulation) {
  set_option(CF_NOSIMULATIONS, !allow_simulation);
  return *this;
}

bool font_dialog::allow_vector_fonts() const noexcept {
  return !get_option(CF_NOVECTORFONTS);
}

font_dialog& font_dialog::allow_vector_fonts(bool allow_vector_fonts) {
  set_option(CF_NOVECTORFONTS, !allow_vector_fonts);
  return *this;
}

bool font_dialog::allow_vertical_fonts() const noexcept {
  return !get_option(CF_NOVERTFONTS);
}

font_dialog& font_dialog::allow_vertical_fonts(bool allow_vertical_fonts) {
  set_option(CF_NOVERTFONTS, !allow_vertical_fonts);
  return *this;
}

drawing::color font_dialog::color() const noexcept {
  return data_->color;
}

font_dialog& font_dialog::color(const drawing::color& color) {
  data_->color = color;
  return *this;
}

bool font_dialog::fixed_pitch_only() const noexcept {
  return get_option(CF_FIXEDPITCHONLY);
}

font_dialog& font_dialog::fixed_pitch_only(bool fixed_pitch_only) {
  set_option(CF_FIXEDPITCHONLY, fixed_pitch_only);
  return *this;
}

drawing::font font_dialog::font() const noexcept {
  return data_->font;
}

font_dialog& font_dialog::font(const drawing::font& font) {
  data_->font = font;
  return *this;
}

bool font_dialog::font_must_exist() const noexcept {
  return get_option(CF_FORCEFONTEXIST);
}

font_dialog& font_dialog::font_must_exist(bool font_must_exist) {
  set_option(CF_FORCEFONTEXIST, font_must_exist);
  return *this;
}

size_t font_dialog::max_size() const noexcept {
  return data_->max_size;
}

font_dialog& font_dialog::max_size(size_t max_size) {
  data_->max_size = max_size;
  return *this;
}

size_t font_dialog::min_size() const noexcept {
  return data_->min_size;
}

font_dialog& font_dialog::min_size(size_t min_size) {
  data_->min_size = min_size;
  return *this;
}

size_t font_dialog::options() const noexcept {
  return data_->options;
}

bool font_dialog::script_only() const noexcept {
  return get_option(CF_SCRIPTSONLY);
}

font_dialog& font_dialog::script_only(bool script_only) {
  set_option(CF_SCRIPTSONLY, script_only);
  return *this;
}

bool font_dialog::show_apply() const noexcept {
  return get_option(CF_APPLY);
}

font_dialog& font_dialog::show_apply(bool show_apply) {
  set_option(CF_APPLY, show_apply);
  return *this;
}

bool font_dialog::show_color() const noexcept {
  return data_->show_color;
}

font_dialog& font_dialog::show_color(bool show_color) {
  data_->show_color = show_color;
  return *this;
}

bool font_dialog::show_effect() const noexcept {
  return get_option(CF_EFFECTS);
}

font_dialog& font_dialog::show_effect(bool show_effect) {
  set_option(CF_EFFECTS, show_effect);
  return *this;
}

bool font_dialog::show_help() const noexcept {
  return get_option(CF_SHOWHELP);
}

font_dialog& font_dialog::show_help(bool show_help) {
  set_option(CF_SHOWHELP, show_help);
  return *this;
}

void font_dialog::reset() noexcept {
  set_dialog_result(xtd::forms::dialog_result::none);
  data_->color = application::style_sheet().system_colors().control_text();
  data_->font = drawing::system_fonts::default_font();
  data_->max_size = 0;
  data_->min_size = 0;
  data_->options = CF_TTONLY;
  data_->show_color = false;
}

void font_dialog::on_apply(const event_args& e) {
  apply(*this, e);
}

bool font_dialog::run_dialog(intptr owner) {
  return native::font_dialog::run_dialog(owner, data_->font, data_->color, data_->options, data_->min_size, data_->max_size, data_->show_color);
}

void font_dialog::run_sheet(intptr owner) {
  if (!owner) run_dialog(owner);
  else native::font_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->font, data_->color, data_->options, data_->min_size, data_->max_size, data_->show_color);
}

bool font_dialog::get_option(size_t flag) const noexcept {
  return (data_->options & flag) == flag;
}

void font_dialog::set_option(size_t flag, bool value) {
  data_->options = value ? data_->options | flag : data_->options & ~flag;
}
