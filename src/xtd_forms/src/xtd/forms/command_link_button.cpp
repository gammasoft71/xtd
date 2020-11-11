#include "../../../include/xtd/forms/command_link_button.h"
#include "../../../include/xtd/forms/form.h"
#include <xtd/forms/native/button.h>
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/window_messages.h>

using namespace xtd;
using namespace xtd::forms;

command_link_button::command_link_button() {
  this->size_ = this->default_size();
  text_align(content_alignment::middle_left);
}

command_link_button& command_link_button::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

forms::create_params command_link_button::create_params() const {
  forms::create_params create_params = this->button_base::create_params();
  
  create_params.class_name("commandlinkbutton");
  
  create_params.style(create_params.style() | BS_COMMANDLINK);
  
  return create_params;
}

void command_link_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (image_ != drawing::image::empty || (image_list_.images().size() && image_index_ > -1)) {
    native::button::image(handle(), image_ != drawing::image::empty ? image_ : image_list_.images()[image_index_]);
    native::button::image_align(handle(), static_cast<uint32_t>(image_align_));
    if (image_align_ != content_alignment::middle_center) native::control::text(handle(), text_);
    native::control::location(handle(), location_);
    native::control::size(handle(), size_);
  }
}

/*
void button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_click(message); break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP: this->wm_mouse_up(message); break;
    default: this->control::wnd_proc(message);
  }
}

void button::wm_click(message& message) {
  this->def_wnd_proc(message);
  this->on_click(event_args::empty);
}

void button::wm_mouse_up(message& message) {
  this->def_wnd_proc(message);
  mouse_event_args e = mouse_event_args::create(message);
  this->on_mouse_click(e);
  this->on_mouse_up(e);
}
 */

drawing::size command_link_button::measure_control() const {
  drawing::size size = button_base::measure_control();
  if (size.height() < default_size().height()) size.height(default_size().height());
  return size;
}
