#include "../../../include/xtd/forms/text_box_base.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/edit_styles>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <optional>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct text_box_base::data {
  bool accepts_tab = false;
  forms::border_sides border_sides = xtd::forms::border_sides::all;
  optional<forms::border_style> border_style;
  bool multiline = false;
  bool read_only = false;
  bool word_wrap = true;
  mutable size_t selection_start = 0;
  mutable size_t selection_length = 0;
};

bool text_box_base::accepts_tab() const noexcept {
  return data_->accepts_tab;
}

text_box_base& text_box_base::accepts_tab(bool value) {
  if (data_->accepts_tab == value) return *this;
  data_->accepts_tab = value;
  post_recreate_handle();
  on_accepts_tab_changed(event_args::empty);
  return *this;
}

forms::border_sides text_box_base::border_sides() const noexcept {
  return data_->border_sides;
}

text_box_base& text_box_base::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

forms::border_style text_box_base::border_style() const noexcept {
  return data_->border_style.value_or(forms::border_style::fixed_single);
}

text_box_base& text_box_base::border_style(forms::border_style border_style) {
  if (this->border_style() == border_style) return *this;
  data_->border_style = border_style;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  on_border_style_changed(event_args::empty);
  return *this;
}

text_box_base& text_box_base::border_style(std::nullptr_t) {
  if (!data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

std::vector<xtd::ustring> text_box_base::lines() const noexcept {
  return text().split({'\n'});
}

text_box_base& text_box_base::lines(const std::vector<xtd::ustring>& lines) {
  text(xtd::ustring::join("\n", lines));
  return *this;
}

bool text_box_base::multiline() const noexcept {
  return data_->multiline;
}

text_box_base& text_box_base::multiline(bool value) {
  if (data_->multiline == value) return *this;
  data_->multiline = value;
  post_recreate_handle();
  on_multiline_changed(event_args::empty);
  return *this;
}

bool text_box_base::read_only() const noexcept {
  return data_->read_only;
}

text_box_base& text_box_base::read_only(bool value) {
  if (data_->read_only == value) return *this;
  data_->read_only = value;
  post_recreate_handle();
  on_read_only_changed(event_args::empty);
  return *this;
}

size_t text_box_base::selection_length() const noexcept {
  return data_->selection_length;
}

text_box_base& text_box_base::selection_length(size_t value) {
  select(data_->selection_start, value);
  return *this;
}

size_t text_box_base::selection_start() const noexcept {
  return data_->selection_start;
}

text_box_base& text_box_base::selection_start(size_t value) {
  select(value, data_->selection_length);
  return *this;
}

bool text_box_base::word_wrap() const noexcept {
  return data_->word_wrap;
}

text_box_base& text_box_base::word_wrap(bool value) {
  if (data_->word_wrap == value) return *this;
  data_->word_wrap = value;
  post_recreate_handle();
  return *this;
}

void text_box_base::append_text(const xtd::ustring& value) {
  suspend_layout();
  text(text() + value);
  select(text().size(), 0);
  resume_layout();
}

void text_box_base::clear() {
  text("");
}

void text_box_base::select(size_t start, size_t length) {
  if (data_->selection_start != start || length != data_->selection_length) {
    if (start > text().size()) throw argument_out_of_range_exception("start greater than text size"_t, csf_);
    if (start + length > text().size()) throw argument_out_of_range_exception("start + length greater than text size"_t, csf_);
    data_->selection_start = start;
    data_->selection_length = length;
  }
}

void text_box_base::select_all() {
  select(0, text().size());
}

text_box_base::text_box_base() : data_(std::make_shared<data>()) {
  set_style(control_styles::fixed_height, auto_size());
  set_style(control_styles::standard_click | control_styles::standard_double_click | control_styles::use_text_for_accessibility | control_styles::user_paint, false);
}

forms::create_params text_box_base::create_params() const noexcept {
  auto create_params = control::create_params();
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  if (accepts_tab()) create_params.style(create_params.style() | ES_WANTTAB);
  if (multiline()) create_params.style(create_params.style() | ES_MULTILINE);
  if (read_only()) create_params.style(create_params.style() | ES_READONLY);
  if (!word_wrap()) create_params.style(create_params.style() | ES_AUTOHSCROLL);
  
  return create_params;
}

forms::cursor text_box_base::default_cursor() const noexcept {
  return forms::cursors::ibeam();
}

void text_box_base::on_accepts_tab_changed(const event_args& e) {
  if (can_raise_events()) accepts_tab_changed(*this, e);
}

void text_box_base::on_border_style_changed(const event_args& e) {
  if (can_raise_events()) border_style_changed(*this, e);
}

void text_box_base::on_multiline_changed(const event_args& e) {
  if (can_raise_events()) multiline_changed(*this, e);
}

void text_box_base::on_read_only_changed(const event_args& e) {
  if (can_raise_events()) read_only_changed(*this, e);
}
