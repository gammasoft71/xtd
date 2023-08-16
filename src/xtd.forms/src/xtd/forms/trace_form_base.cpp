#include "../../../include/xtd/forms/trace_form_base.h"

using namespace xtd;
using namespace xtd::forms;

struct trace_form_base::data {
  bool need_header = true;
  bool show_date = true;
  bool show_time = true;
  xtd::ustring format = "{0}";
  xtd::ustring header_separator = "|";
  xtd::forms::text_box text;
};

xtd::forms::control& trace_form_base::dock(xtd::forms::dock_style dock) {
  if (dock == xtd::forms::dock_style::left) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width() / 4, xtd::forms::screen::get_working_area(handle()).height()});
  else if (dock == xtd::forms::dock_style::top) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width(), xtd::forms::screen::get_working_area(handle()).height() / 4});
  else if (dock == xtd::forms::dock_style::right) bounds({xtd::forms::screen::get_working_area(handle()).left() + xtd::forms::screen::get_working_area(handle()).width() - xtd::forms::screen::get_working_area(handle()).width() / 4, xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width() / 4, xtd::forms::screen::get_working_area(handle()).height()});
  else if (dock == xtd::forms::dock_style::bottom) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top() + xtd::forms::screen::get_working_area(handle()).height() - xtd::forms::screen::get_working_area(handle()).height() / 4, xtd::forms::screen::get_working_area(handle()).width(), xtd::forms::screen::get_working_area(handle()).height() / 4});
  else if (dock == xtd::forms::dock_style::fill) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width(), xtd::forms::screen::get_working_area(handle()).height()});
  return xtd::forms::control::dock(dock);
}

const xtd::ustring& trace_form_base::header_separator() const noexcept {
  return data_->header_separator;
}

trace_form_base& trace_form_base::header_separator(const xtd::ustring& header_separator) {
  if (header_separator != data_->header_separator) {
    data_->header_separator = header_separator;
    update_format();
  }
  return *this;
}

const xtd::ustring& trace_form_base::name() const noexcept {
  return form::name();
}

bool trace_form_base::show_date() const noexcept {
  return data_->show_date;
}

trace_form_base& trace_form_base::show_date(bool value) {
  if (data_->show_date != value) {
    data_->show_date = value;
    update_format();
  }
  return *this;
}

bool trace_form_base::show_time() const noexcept {
  return data_->show_time;
}

trace_form_base& trace_form_base::show_time(bool value) {
  if (data_->show_time != value) {
    data_->show_time = value;
    update_format();
  }
  return *this;
}

trace_form_base::trace_form_base(const xtd::ustring& text) : data_(std::make_shared<data>()) {
  close_box(false);
  minimize_box(false);
  name("9f5767d6-7a21-4ebe-adfe-2427b2024a55");
  show_in_taskbar(false);
  data_->text.name("d014d407-851c-49c1-a343-3380496a639a");
  
  dock(xtd::forms::dock_style::bottom);
  start_position(xtd::forms::form_start_position::manual);
  font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), font().size()));
  this->text(text);
  
  data_->text.dock(xtd::forms::dock_style::fill);
  data_->text.multiline(true);
  data_->text.parent(*this);
  data_->text.read_only(true);
  data_->text.word_wrap(false);
  update_format();
}

void trace_form_base::on_back_color_changed(const xtd::event_args& e) {
  data_->text.back_color(back_color());
}

void trace_form_base::on_fore_color_changed(const xtd::event_args& e) {
  data_->text.fore_color(fore_color());
}

void trace_form_base::write(const xtd::ustring& trace) {
  if (need_header()) write_header();
  data_->text.append_text(trace);
}

void trace_form_base::write_line(const xtd::ustring& trace) {
  write(trace);
  write(environment::new_line());
  need_header(true);
}

void trace_form_base::write_header() {
  auto now =  xtd::date_time::now();
  data_->text.append_text(xtd::ustring::format(data_->format, now, (now.ticks() / 10 % 1000000), data_->header_separator));
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
