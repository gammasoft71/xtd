#include <memory>
#include <vector>
#include <xtd/chrono>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/replace_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/process.h>
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/replace_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct replace_dialog::data {
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::standard;
  xtd::ustring find_string;
  xtd::ustring replace_string;
  intptr handle = 0;
  std::optional<xtd::drawing::point> location;
  bool match_case = false;
  const iwin32_window* owner;
  bool show_match_case = true;
  bool show_whole_word = true;
  xtd::ustring title;
  bool visible = false;
  bool whole_word = false;
};

replace_dialog::replace_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

replace_dialog::~replace_dialog() {
  destroy_handle();
}

const xtd::ustring& replace_dialog::find_string() const noexcept {
  return data_->find_string;
}

replace_dialog& replace_dialog::find_string(const xtd::ustring& value) {
  if (value == data_->find_string) return *this;
  data_->find_string = value;
  recreate_handle();
  return *this;
}

const xtd::ustring& replace_dialog::replace_string() const noexcept {
  return data_->replace_string;
}

replace_dialog& replace_dialog::replace_string(const xtd::ustring& value) {
  if (value == data_->replace_string) return *this;
  data_->replace_string = value;
  recreate_handle();
  return *this;
}

xtd::drawing::point replace_dialog::location() const noexcept {
  return data_->location.value_or(point(0, 0));
}

replace_dialog& replace_dialog::location(const xtd::drawing::point& value) {
  if (value == data_->location) return *this;
  data_->location = value;
  recreate_handle();
  return *this;
}

bool replace_dialog::match_case() const noexcept {
  return data_->match_case;
}

replace_dialog& replace_dialog::match_case(bool value) {
  if (value == data_->match_case) return *this;
  data_->match_case = value;
  recreate_handle();
  return *this;
}

bool replace_dialog::show_match_case() const noexcept {
  return data_->show_match_case;
}

replace_dialog& replace_dialog::show_match_case(bool value) {
  if (value == data_->show_match_case) return *this;
  data_->show_match_case = value;
  recreate_handle();
  return *this;
}

bool replace_dialog::show_whole_word() const noexcept {
  return data_->show_whole_word;
}

replace_dialog& replace_dialog::show_whole_word(bool value) {
  if (value == data_->show_whole_word) return *this;
  data_->show_whole_word = value;
  recreate_handle();
  return *this;
}

const xtd::ustring& replace_dialog::title() const noexcept {
  return data_->title;
}

replace_dialog& replace_dialog::title(const xtd::ustring& value) {
  if (value == data_->title) return *this;
  data_->title = value;
  recreate_handle();
  return *this;
}

bool replace_dialog::whole_word() const noexcept {
  return data_->whole_word;
}

replace_dialog& replace_dialog::whole_word(bool value) {
  if (value == data_->whole_word) return *this;
  data_->whole_word = value;
  recreate_handle();
  return *this;
}

void replace_dialog::close() {
  if (!data_->visible) return;
  native::replace_dialog::close(data_->handle);
  data_->visible = false;
}

void replace_dialog::reset() noexcept {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->location.reset();
  data_->title = "";
  data_->find_string = "";
  data_->replace_string = "";
  data_->show_match_case = true;
  data_->show_whole_word = true;
  data_->match_case = false;
  data_->whole_word = false;
  recreate_handle();
}

void replace_dialog::show(const iwin32_window& owner) {
  if (data_->visible) return;
  if (data_->owner != &owner) {
    data_->owner = &owner;
    destroy_handle();
  }
  create_handle();
  native::replace_dialog::show(data_->handle);
  data_->visible = true;
}

void replace_dialog::on_dialog_closed() {
  data_->visible = false;
  dialog_closed(*this, dialog_closed_event_args(forms::dialog_result::cancel));
}

void replace_dialog::on_dialog_find(const xtd::drawing::point& location, const ustring& find_string, const ustring& replace_string, bool whole_word, bool match_case) {
  data_->location = location;
  data_->find_string = find_string;
  data_->replace_string = replace_string;
  data_->whole_word = whole_word;
  data_->match_case = match_case;
  find_next(*this, find_event_args(data_->find_string, data_->match_case, search_direction::down, data_->whole_word));
}

void replace_dialog::on_dialog_replace(const xtd::drawing::point& location, const ustring& find_string, const ustring& replace_string, bool replace_all, bool whole_word, bool match_case) {
  data_->location = location;
  data_->find_string = find_string;
  data_->replace_string = replace_string;
  data_->whole_word = whole_word;
  data_->match_case = match_case;
  if (replace_all) this->replace_all(*this, replace_event_args(data_->find_string, data_->replace_string, data_->match_case, data_->whole_word));
  else replace(*this, replace_event_args(data_->find_string, data_->replace_string, data_->match_case, data_->whole_word));
}

void replace_dialog::create_handle() {
  if (data_->handle) return;
  data_->handle = native::replace_dialog::create(data_->owner->handle(), data_->location, data_->title, data_->find_string, data_->replace_string, data_->show_whole_word, data_->show_match_case, data_->whole_word, data_->match_case, {*this, &replace_dialog::on_dialog_find}, {*this, &replace_dialog::on_dialog_replace}, {*this, &replace_dialog::on_dialog_closed});
}

void replace_dialog::destroy_handle() {
  if (!data_->handle) return;
  native::replace_dialog::destroy(data_->handle);
  data_->handle = 0;
}

void replace_dialog::recreate_handle() {
  if (!data_->handle) return;
  destroy_handle();
  create_handle();
  if (data_->visible) native::replace_dialog::show(data_->handle);
}
