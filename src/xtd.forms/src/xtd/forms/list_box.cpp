#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/list_box.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/list_box_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/list_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

list_box::list_box() {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint | control_styles::standard_click | control_styles::use_text_for_accessibility, false);
  data_->items.item_added += [this](size_t index, const item & item) {
    if (is_handle_created()) native::list_box::insert_item(handle(), index, item.value());
    list_box::item selected_item;
    if (selected_index() != npos && selected_index() < data_->items.size()) selected_item = data_->items[selected_index()];
    this->selected_item(selected_item);
  };
  
  data_->items.item_removed += [this](size_t index, const item & item) {
    if (is_handle_created()) native::list_box::delete_item(handle(), index);
    list_box::item selected_item;
    if (selected_index() != npos && selected_index() < data_->items.size()) selected_item = data_->items[selected_index()];
    this->selected_item(selected_item);
    
    if (this->items().size() == 1) // not 0! --> the item_remove occure before erase!
      this->selected_index(npos);
  };
  
  data_->items.item_updated += [this](size_t index, const item & item) {
    if (is_handle_created()) native::list_box::update_item(handle(), index, item.value());
    list_box::item selected_item;
    if (selected_index() != npos && selected_index() < data_->items.size()) selected_item = data_->items[selected_index()];
    this->selected_item(selected_item);
  };
}

list_box& list_box::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides != border_sides) {
    data_->border_sides = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

list_box& list_box::border_style(forms::border_style border_style) {
  if (data_->border_style != border_style) {
    data_->border_style = border_style;
    post_recreate_handle();
  }
  return *this;
}

list_control& list_box::selected_index(size_t selected_index) {
  if (selected_index != npos && selected_index >= data_->items.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, current_stack_frame_);
  if (this->selected_index() != selected_index) {
    set_selected_index(selected_index);
    if (is_handle_created()) native::list_box::selected_index(handle(), this->selected_index());
    
    item selected_item;
    if (this->selected_index() != npos) selected_item = data_->items[this->selected_index()];
    //this->selected_item(selected_item);
    data_->selected_item = selected_item;
    on_selected_value_changed(event_args::empty);
    
    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> list_box::selected_indices() const {
  return is_handle_created() ? native::list_box::selected_indices(handle()) : vector<size_t> {};
}

list_box& list_box::selected_item(const item& selected_item) {
  if (data_->selected_item != selected_item) {
    auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
    if (it == data_->items.end()) {
      if (selected_index() == npos || items().size() == 0) data_->selected_item = "";
      else {
        if (selected_index() >= items().size()) data_->selected_item = items()[items().size() - 1];
        else data_->selected_item = items()[selected_index()];
      }
    } else {
      size_t index = it - data_->items.begin();
      selected_index(index);
      data_->selected_item = *it;
      on_selected_value_changed(event_args::empty);
    }
  }
  return *this;
}

vector<list_box::item> list_box::selected_items() const {
  vector<item> items;
  for (size_t index : selected_indices())
    items.push_back(data_->items[index]);
  return items;
}

list_box& list_box::selection_mode(forms::selection_mode selection_mode) {
  if (data_->selection_mode != selection_mode) {
    data_->selection_mode = selection_mode;
    post_recreate_handle();
  }
  return *this;
}

list_box& list_box::sorted(bool sorted) {
  if (data_->sorted != sorted) {
    data_->sorted = sorted;
    data_->items.sorted(data_->sorted);
  }
  return *this;
}

void list_box::begin_update() {
  if (is_handle_created()) native::list_box::begin_update(handle());
}

void list_box::end_update() {
  if (is_handle_created()) native::list_box::end_update(handle());
}

drawing::color list_box::default_back_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color list_box::default_fore_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

forms::create_params list_box::create_params() const {
  forms::create_params create_params = list_control::create_params();
  
  create_params.class_name("listbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);
  
  switch (data_->selection_mode) {
    case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
    case selection_mode::one:  break;
    case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
    case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
    default: break;
  }
  
  // Do not use native control sort
  //if (data_->sorted) create_params.style(create_params.style() | LBS_SORT);
  
  if (data_->border_style == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (data_->border_style != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

void list_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  data_->items.sorted(data_->sorted);
  for (size_t index = 0; index < data_->items.size(); ++index)
    native::list_box::insert_item(handle(), index, data_->items[index].value());
  if (data_->selection_mode == forms::selection_mode::none) selected_index(npos);
  native::list_box::selected_index(handle(), selected_index());
  if (selected_index() != npos) data_->selected_item = data_->items[selected_index()];
}

void list_box::on_selected_value_changed(const event_args& e) {
  list_control::text(data_->selected_item.value());
  list_control::on_selected_value_changed(e);
}


void list_box::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: list_control::wnd_proc(message);
  }
}

void list_box::wm_mouse_double_click(message& message) {
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_mouse_up(message& message) {
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_command_control(message& message) {
  def_wnd_proc(message);
  if (HIWORD(message.wparam()) == LBN_SELCHANGE) {
    selected_index(native::list_box::selected_index(handle()));
    if (selected_index() != npos) selected_item(data_->items[selected_index()]);
    on_click(event_args::empty);
  }
}
