#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/find_dialog.h"
#include <xtd/diagnostics/process>
#include <xtd/drawing/system_icons>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/find_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/chrono>
#include <xtd/literals>
#include <memory>
#include <vector>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct find_dialog::data {
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::standard;
  xtd::ustring find_string;
  intptr handle = 0;
  std::optional<xtd::drawing::point> location;
  bool match_case = false;
  const iwin32_window* owner;
  bool show_match_case = true;
  bool show_up_down = true;
  bool show_whole_word = true;
  xtd::forms::search_direction search_direction = xtd::forms::search_direction::down;
  xtd::ustring title;
  bool visible = false;
  bool whole_word = false;
};

find_dialog::find_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

find_dialog::~find_dialog() {
  destroy_handle();
}

const xtd::ustring& find_dialog::find_string() const noexcept {
  return data_->find_string;
}

find_dialog& find_dialog::find_string(const xtd::ustring& value) {
  if (value == data_->find_string) return *this;
  data_->find_string = value;
  recreate_handle();
  return *this;
}

xtd::drawing::point find_dialog::location() const noexcept {
  return data_->location.value_or(point(0, 0));
}

find_dialog& find_dialog::location(const xtd::drawing::point& value) {
  if (value == data_->location) return *this;
  data_->location = value;
  recreate_handle();
  return *this;
}

bool find_dialog::match_case() const noexcept {
  return data_->match_case;
}

find_dialog& find_dialog::match_case(bool value) {
  if (value == data_->match_case) return *this;
  data_->match_case = value;
  recreate_handle();
  return *this;
}

xtd::forms::search_direction find_dialog::search_direction() const noexcept {
  return data_->search_direction;
}

find_dialog& find_dialog::search_direction(xtd::forms::search_direction value) {
  if (value == data_->search_direction) return *this;
  data_->search_direction = value;
  recreate_handle();
  return *this;
}

bool find_dialog::show_match_case() const noexcept {
  return data_->show_match_case;
}

find_dialog& find_dialog::show_match_case(bool value) {
  if (value == data_->show_match_case) return *this;
  data_->show_match_case = value;
  recreate_handle();
  return *this;
}

bool find_dialog::show_up_down() const noexcept {
  return data_->show_up_down;
}

find_dialog& find_dialog::show_up_down(bool value) {
  if (value == data_->show_up_down) return *this;
  data_->show_up_down = value;
  recreate_handle();
  return *this;
}

bool find_dialog::show_whole_word() const noexcept {
  return data_->show_whole_word;
}

find_dialog& find_dialog::show_whole_word(bool value) {
  if (value == data_->show_whole_word) return *this;
  data_->show_whole_word = value;
  recreate_handle();
  return *this;
}

const xtd::ustring& find_dialog::title() const noexcept {
  return data_->title;
}

find_dialog& find_dialog::title(const xtd::ustring& value) {
  if (value == data_->title) return *this;
  data_->title = value;
  recreate_handle();
  return *this;
}

bool find_dialog::whole_word() const noexcept {
  return data_->whole_word;
}

find_dialog& find_dialog::whole_word(bool value) {
  if (value == data_->whole_word) return *this;
  data_->whole_word = value;
  recreate_handle();
  return *this;
}

void find_dialog::close() {
  if (!data_->visible) return;
  native::find_dialog::close(data_->handle);
  data_->visible = false;
}

void find_dialog::reset() noexcept {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->location.reset();
  data_->title = "";
  data_->find_string = "";
  data_->show_up_down = true;
  data_->show_match_case = true;
  data_->show_whole_word = true;
  data_->search_direction = xtd::forms::search_direction::down;
  data_->match_case = false;
  data_->whole_word = false;
  recreate_handle();
}

void find_dialog::show(const iwin32_window& owner) {
  if (data_->visible) return;
  if (data_->owner != &owner) {
    data_->owner = &owner;
    destroy_handle();
  }
  create_handle();
  native::find_dialog::show(data_->handle);
  data_->visible = true;
}

void find_dialog::create_handle() {
  if (data_->handle) return;
  data_->handle = native::find_dialog::create(data_->owner->handle(), data_->location, data_->title, data_->find_string, data_->show_up_down, data_->show_whole_word, data_->show_match_case, data_->search_direction == xtd::forms::search_direction::down, data_->whole_word, data_->match_case, {*this, &find_dialog::on_dialog_find}, {*this, &find_dialog::on_dialog_closed});
}

void find_dialog::destroy_handle() {
  if (!data_->handle) return;
  native::find_dialog::destroy(data_->handle);
  data_->handle = 0;
}

void find_dialog::on_dialog_closed() {
  data_->visible = false;
  dialog_closed(*this, dialog_closed_event_args(forms::dialog_result::cancel));
}

void find_dialog::on_dialog_find(const xtd::drawing::point& location, const ustring& find_string, bool downwards, bool whole_word, bool match_case) {
  data_->location = location;
  data_->find_string = find_string;
  data_->search_direction = downwards ? xtd::forms::search_direction::down : xtd::forms::search_direction::up;
  data_->whole_word = whole_word;
  data_->match_case = match_case;
  find_next(*this, find_event_args(data_->find_string, data_->match_case, data_->search_direction, data_->whole_word));
}

void find_dialog::recreate_handle() {
  if (!data_->handle) return;
  destroy_handle();
  create_handle();
  if (data_->visible) native::find_dialog::show(data_->handle);
}
