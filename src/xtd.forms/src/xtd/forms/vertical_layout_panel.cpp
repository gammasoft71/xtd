#include "../../../include/xtd/forms/vertical_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

void vertical_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (controls().size() == 0) return;
  int32_t top = padding().top();
  int32_t left = padding().left();
  int32_t width = client_size().width() - padding().left() - padding().right();
  int32_t height = client_size().height() / controls().size()) - padding().top() - padding().bottom();
  for (size_t index = 0; index < controls().size(); ++index) {
    controls()[index].get().set_bounds(left, top, width, height);
    top += height + padding().bottom() + padding().top();
  }
}
