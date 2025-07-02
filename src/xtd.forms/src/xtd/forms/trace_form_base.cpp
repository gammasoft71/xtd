#include "../../../include/xtd/forms/trace_form_base.hpp"
#include <xtd/lock>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

string& __xtd_forms_trace_form_base_default_form_name__() noexcept {
  static auto value = string {"9f5767d6-7a21-4ebe-adfe-2427b2024a55"};
  return value;
}

string& __xtd_forms_trace_form_base_default_text_box_name__() noexcept {
  static auto value = string {"d014d407-851c-49c1-a343-3380496a639a"};
  return value;
}

struct trace_form_base::data {
  bool need_header = true;
  bool show_date = true;
  bool show_time = true;
  string format = "{0}";
  string header_separator = "|";
  forms::text_box text;
};

control& trace_form_base::dock(dock_style dock) {
  if (dock == dock_style::left) bounds({screen::get_working_area(handle()).left(), screen::get_working_area(handle()).top(), screen::get_working_area(handle()).width / 4, screen::get_working_area(handle()).height});
  else if (dock == dock_style::top) bounds({screen::get_working_area(handle()).left(), screen::get_working_area(handle()).top(), screen::get_working_area(handle()).width, screen::get_working_area(handle()).height / 4});
  else if (dock == dock_style::right) bounds({screen::get_working_area(handle()).left() + screen::get_working_area(handle()).width - screen::get_working_area(handle()).width / 4, screen::get_working_area(handle()).top(), screen::get_working_area(handle()).width / 4, screen::get_working_area(handle()).height});
  else if (dock == dock_style::bottom) bounds({screen::get_working_area(handle()).left(), screen::get_working_area(handle()).top() + screen::get_working_area(handle()).height - screen::get_working_area(handle()).height / 4, screen::get_working_area(handle()).width, screen::get_working_area(handle()).height / 4});
  else if (dock == dock_style::fill) bounds({screen::get_working_area(handle()).left(), screen::get_working_area(handle()).top(), screen::get_working_area(handle()).width, screen::get_working_area(handle()).height});
  return control::dock(dock);
}

const string& trace_form_base::header_separator() const noexcept {
  return data_->header_separator;
}

trace_form_base& trace_form_base::header_separator(const string& header_separator) {
  if (header_separator == data_->header_separator) return *this;
  data_->header_separator = header_separator;
  update_format();
  return *this;
}

const string& trace_form_base::name() const noexcept {
  return form::name();
}

bool trace_form_base::show_date() const noexcept {
  return data_->show_date;
}

trace_form_base& trace_form_base::show_date(bool value) {
  if (data_->show_date == value) return *this;
  data_->show_date = value;
  update_format();
  return *this;
}

bool trace_form_base::show_time() const noexcept {
  return data_->show_time;
}

trace_form_base& trace_form_base::show_time(bool value) {
  if (data_->show_time == value) return *this;
  data_->show_time = value;
  update_format();
  return *this;
}

trace_form_base::trace_form_base(const string& text) : data_(xtd::new_sptr<data>()) {
  close_box(false);
  minimize_box(false);
  name(__xtd_forms_trace_form_base_default_form_name__());
  show_in_taskbar(false);
  data_->text.name(__xtd_forms_trace_form_base_default_text_box_name__());
  
  dock(dock_style::bottom);
  start_position(form_start_position::manual);
  font(drawing::font(font_family::generic_monospace(), font().size()));
  this->text(text);
  
  data_->text.dock(dock_style::fill);
  data_->text.multiline(true);
  data_->text.parent(*this);
  data_->text.read_only(true);
  data_->text.word_wrap(false);
  update_format();
}

void trace_form_base::on_back_color_changed(const event_args& e) {
  data_->text.back_color(back_color());
}

void trace_form_base::on_fore_color_changed(const event_args& e) {
  data_->text.fore_color(fore_color());
}

void trace_form_base::write(const string& trace) {
  auto writer = [self = this, trace = trace] {
    auto lck = lock {*self};
    if (self->need_header()) self->write_header();
    self->data_->text.append_text(trace);
  };
  if (invoke_required()) begin_invoke(writer);
  else writer();
}

void trace_form_base::write_line(const string& trace) {
  auto lck = lock {*this};
  write(trace);
  write(environment::new_line());
  need_header(true);
}

void trace_form_base::write_header() {
  auto now = date_time::now();
  data_->text.append_text(string::format(data_->format, now, (now.ticks() / 10 % 1000000), data_->header_separator));
  data_->need_header = false;
}

bool trace_form_base::need_header() const {
  return data_->need_header;
}

trace_form_base& trace_form_base::need_header(bool value) {
  data_->need_header = value;
  return *this;
}

void trace_form_base::update_format() {
  data_->format = "";
  if (data_->show_date && data_->show_time) data_->format = "{0:u}.{1:D6}{2}" + data_->format;
  else if (data_->show_date) data_->format = "{0:L}-{0:k}-{0:i}{2}" + data_->format;
  else if (data_->show_time) data_->format = "{0:t}.{1:D6}{2}" + data_->format;
}
