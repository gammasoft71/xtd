#include "../../../include/xtd/forms/scrollable_control.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct scrollable_control::data {
  bool auto_scroll = false;
  bool h_scroll = false;
  bool v_scroll = false;
  drawing::rectangle display_rectangle;
  drawing::size auto_scroll_margin;
};

bool scrollable_control::auto_scroll() const noexcept {
  return data_->auto_scroll;
}

scrollable_control& scrollable_control::auto_scroll(bool auto_scroll) {
  if (data_->auto_scroll == auto_scroll) return *this;
  data_->auto_scroll = auto_scroll;
  post_recreate_handle();
  return *this;
}

drawing::size scrollable_control::auto_scroll_margin() const noexcept {
  return data_->auto_scroll_margin;
}

scrollable_control& scrollable_control::auto_scroll_margin(const drawing::size& value) {
  if (data_->auto_scroll_margin == value) return *this;
  data_->auto_scroll_margin = value;
  perform_layout();
  return *this;
}

drawing::rectangle scrollable_control::display_rectangle() const noexcept {
  return data_->display_rectangle;
}

bool scrollable_control::h_scroll() const noexcept {
  return data_->h_scroll;
}

scrollable_control& scrollable_control::h_scroll(bool h_scroll) {
  if (data_->h_scroll == h_scroll) return *this;
  data_->h_scroll = h_scroll;
  post_recreate_handle();
  return *this;
}

bool scrollable_control::v_scroll() const noexcept {
  return data_->v_scroll;
}

scrollable_control& scrollable_control::v_scroll(bool v_scroll) {
  if (data_->v_scroll == v_scroll) return *this;
  data_->v_scroll = v_scroll;
  post_recreate_handle();
  return *this;
}

scrollable_control::scrollable_control() : data_(std::make_shared<data>()) {
  set_state(state::tab_stop, false);
  set_style(control_styles::container_control, true);
  set_style(control_styles::all_painting_in_wm_paint, false);
}

forms::create_params scrollable_control::create_params() const noexcept {
  auto create_params = control::create_params();
  
  if (data_->auto_scroll) {
    create_params.style(create_params.style() | WS_HSCROLL | WS_VSCROLL);
    create_params.ex_style(create_params.ex_style() | WS_EX_AUTOSCROLL);
  } else {
    if (data_->h_scroll) create_params.style(create_params.style() | WS_HSCROLL);
    if (data_->v_scroll) create_params.style(create_params.style() | WS_VSCROLL);
  }
  
  return create_params;
}

void scrollable_control::on_layout(const event_args& e) {
  control::on_layout(e);
  if (data_->auto_scroll) {
    data_->display_rectangle = control::client_rectangle();
    data_->display_rectangle.height(data_->display_rectangle.height() - system_information::horizontal_scroll_bar_height());
    data_->display_rectangle.width(data_->display_rectangle.width() - system_information::vertical_scroll_bar_width());
    for (auto item : controls()) {
      if (item.get().visible())
        data_->display_rectangle = drawing::rectangle::make_union(data_->display_rectangle, item.get().bounds());
    }
    data_->display_rectangle.width(data_->display_rectangle.width() + data_->auto_scroll_margin.width());
    data_->display_rectangle.height(data_->display_rectangle.height() + data_->auto_scroll_margin.height());
  }
}
