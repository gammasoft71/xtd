#include <xtd/forms/native/control.h>
#include <xtd/forms/native/panel.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/panel.h"

using namespace xtd;
using namespace xtd::forms;

panel::panel() {
  this->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->can_focus_ = false;
  this->size_ = this->default_size();
}

panel& panel::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

panel& panel::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params panel::create_params() const {
  forms::create_params create_params = this->scrollable_control::create_params();
  
  create_params.class_name("panel");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

drawing::size panel::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void panel::on_layout(const event_args& e) {
  this->scrollable_control::on_layout(e);
  if (auto_scroll_) native::panel::virtual_size(this->handle(), display_rectangle().size());
}
