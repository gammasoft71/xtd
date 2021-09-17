#include "../../../include/xtd/forms/link_label_clicked_event_args.h"

using namespace xtd;
using namespace xtd::forms;

link_label_clicked_event_args::link_label_clicked_event_args(const xtd::forms::link& link, xtd::forms::mouse_buttons button) : link_(link), button_(button) {
}

const xtd::forms::link& link_label_clicked_event_args::link() const {
  return link_;
}

xtd::forms::mouse_buttons link_label_clicked_event_args::button() const {
  return button_;
}

bool link_label_clicked_event_args::visited() const {
  return visited_;
}
void link_label_clicked_event_args::visited(bool value) {
  visited_ = value;
}
