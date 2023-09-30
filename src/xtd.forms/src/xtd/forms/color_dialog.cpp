#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/color_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/color_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

struct color_dialog::data {
  drawing::color color = drawing::color::black;
  colors custom_colors {16, xtd::drawing::color::white};
  size_t options = CC_ALPHACOLOR | CC_PREVENTFULLOPEN;
  xtd::ustring title;
};

color_dialog::color_dialog() : data_(std::make_shared<data>()) {
}

bool color_dialog::alpha_color() const noexcept {
  return get_option(CC_ALPHACOLOR);
}

color_dialog& color_dialog::alpha_color(bool alpha_color) {
  set_option(CC_ALPHACOLOR, alpha_color);
  return *this;
}

bool color_dialog::allow_full_open() const noexcept {
  return get_option(CC_PREVENTFULLOPEN);
}

color_dialog& color_dialog::allow_full_open(bool allow_full_open) {
  set_option(CC_PREVENTFULLOPEN, allow_full_open);
  return *this;
}

bool color_dialog::any_color() const noexcept {
  return get_option(CC_ANYCOLOR);
}

color_dialog& color_dialog::any_color(bool any_color) {
  set_option(CC_ANYCOLOR, any_color);
  return *this;
}

drawing::color color_dialog::color() const noexcept {
  return data_->color;
}

color_dialog& color_dialog::color(const drawing::color& color) {
  data_->color = color;
  return *this;
}

const color_dialog::colors& color_dialog::custom_colors() const noexcept {
  return data_->custom_colors;
}

color_dialog& color_dialog::custom_colors(const colors& custom_colors)  {
  for (auto index = 0_sz; index < custom_colors.size(); ++index)
    data_->custom_colors[index] = custom_colors[index];
  for (auto index = custom_colors.size(); index < data_->custom_colors.size(); ++index)
    data_->custom_colors[index] = xtd::drawing::color::white;
  return *this;
}

bool color_dialog::full_open() const noexcept {
  return get_option(CC_FULLOPEN);
}

color_dialog& color_dialog::full_open(bool full_open) {
  set_option(CC_FULLOPEN, full_open);
  return *this;
}

size_t color_dialog::options() const noexcept {
  return data_->options;
}

bool color_dialog::show_help() const noexcept {
  return get_option(CC_SHOWHELP);
}

color_dialog& color_dialog::show_help(bool show_help) {
  set_option(CC_SHOWHELP, show_help);
  return *this;
}

bool color_dialog::solid_color_only() const noexcept {
  return get_option(CC_SOLIDCOLOR);
}

color_dialog& color_dialog::solid_color_only(bool solid_color_only) {
  set_option(CC_SOLIDCOLOR, solid_color_only);
  return *this;
}

const xtd::ustring& color_dialog::title() const noexcept {
  return data_->title;
}

color_dialog& color_dialog::title(const xtd::ustring& value) {
  data_->title = value;
  return *this;
}

void color_dialog::reset() noexcept {
  set_dialog_result(xtd::forms::dialog_result::none);
  data_->color = drawing::color::black;
  data_->custom_colors = std::vector<xtd::drawing::color>(16, xtd::drawing::color::white);
  data_->options = CC_ALPHACOLOR | CC_PREVENTFULLOPEN;
}

bool color_dialog::run_dialog(intptr owner) {
  return native::color_dialog::run_dialog(owner, data_->title, data_->color, data_->custom_colors, data_->options);
}

void color_dialog::run_sheet(intptr owner) {
  if (!owner) run_dialog(owner);
  else native::color_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->title, data_->color, data_->custom_colors, data_->options);
}

bool color_dialog::get_option(size_t flag) const noexcept {
  return (data_->options & flag) == flag;
}

void color_dialog::set_option(size_t flag, bool value) {
  data_->options = value ? data_->options | flag : data_->options & ~flag;
}
